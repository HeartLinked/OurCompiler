#include "IRGen.hpp"
#include "koopa.h"
#include "utils.hpp"

using namespace std;

const char* inst_op[] = 
{
    "", "", "sgt", "slt", "", "",
    "add", "sub", "mul", "div",
    "rem", "and", "or", "xor",
    "sll", "srl", "sra"
};

//配栈上局部变量的地址
class LocalAllocate
{
public:
    unordered_map<koopa_raw_value_t, size_t> var_address; //记录value的偏移量
    
    //R: 函数中有call则为4，用于保存ra寄存器
    //A: 该函数调用的函数中，参数最多的那个，需要额外分配的第9,10……个参数的空间
    //S: 为这个函数的局部变量分配的栈空间
    //delta: 16字节对齐后的栈帧长度
    size_t R, A, S, delta;

    //初始化
    LocalAllocate(): R(0), A(0), S(0) {;}

    //清空所有参数
    void clear()
    {
        var_address.clear(); //清空value偏移量的记录
        R = A = S = delta = 0;
    }

    //为value分配空间
    void alloc(koopa_raw_value_t value, size_t type_size = 4)
    {
        var_address.insert(make_pair(value, S));
        S += type_size;
    }

    //设置R=4，函数中有call则R=4，用于保存ra寄存器
    void setR()
    {
        R = 4;
    }

    //该函数调用的函数中，参数最多的那个，需要额外分配的第9,10……个参数的空间
    void setA(size_t a)
    {
        if(A > a)
            A = A;
        else
            A = a;
    }

    bool exists(koopa_raw_value_t value)
    {
        return var_address.find(value) != var_address.end();
    }
    
    size_t getOffset(koopa_raw_value_t value)
    {
        //大小为A的位置存函数参数
        return var_address[value] + A;
    }

    //得到16字节对齐后的栈帧长度
    void getDelta()
    {
        int d = S + R + A;
        delta = d%16 ? d + 16 - d %16: d;
    }
};

//函数控制器，用于确定当前函数的参数是第几个
class FunctionControl{
private:
    koopa_raw_function_t func;  //当前访问的函数

public:
    FunctionControl() = default;
    //赋值函数
    void setFunc(koopa_raw_function_t function)
    {
        func = function;
    }
    //得到raw value在func序列中的下标
    int getParamNum(koopa_raw_value_t v)
    {
        int i = 0;
        for(i = 0 ; i < func->params.len; ++i){
            if(func->params.buffer[i] == (void *)v)
                break;
        }
        return i;
    }
};

//全局变量定义
LocalAllocate la;
FunctionControl fc;
RiscvGen rg;
TempLabel tb;
//局部变量分配栈地址
void AllocateLocalAddress(const koopa_raw_function_t &func)
{
    for(size_t i = 0; i < func->bbs.len; i++)
    {
        auto bb = reinterpret_cast<koopa_raw_basic_block_t>(func->bbs.buffer[i]);
        for(size_t j = 0; j < bb->insts.len; j++)
        {
          auto value = reinterpret_cast<koopa_raw_value_t>(bb->insts.buffer[j]);

          //接下来对指令进行处理
          //alloc类型
          if(value->kind.tag == KOOPA_RVT_ALLOC)
          {
              size_t type_size = getTypeSize(value->ty->data.pointer.base);
              la.alloc(value, type_size);
              continue;
          }
          //call类型
          if(value->kind.tag == KOOPA_RVT_CALL)
          {
              koopa_raw_call_t c = value->kind.data.call;
              la.setR();
              la.setA((size_t)max(0, ((int)c.args.len - 8) * 4)); //超过8个参数
          }
          //其他情况
          size_t type_size = getTypeSize(value->ty);
          if(type_size != 0)
              la.alloc(value, type_size);
        }
    }
}

// 计算类型koopa_raw_type_t的大小
size_t getTypeSize(koopa_raw_type_t ty)
{
    size_t size = 0;

    switch(ty->tag)
    {
        case KOOPA_RTT_INT32:
            size = 4;
            break;
        case KOOPA_RTT_POINTER:
            size = 4;
            break;
        case KOOPA_RTT_FUNCTION:
            size = 0;
            break;
        case KOOPA_RTT_UNIT:
            size = 0;
            break;
        case KOOPA_RTT_ARRAY:
            size = ty->data.array.len * getTypeSize(ty->data.array.base);
            break;
        default:
            //暂时没添加其他情况
            assert(false);
    }

    return size;
}

//输入char*类型buf和读取文件路径，将文件内容转换成char*类型输出到buf里
void TransferIR(char * buf , const char* file_name)
{
    ifstream in(file_name);
    string line;

    if(in) // 有该文件
    {
        while (getline (in, line)) // line中不包括每行的换行符
        {
            strcpy(buf+strlen(buf),line.c_str());
            buf[strlen(buf)]='\n';
        }
    }
    else // 没有该文件
      cout <<"no such file" << endl;

    return ;
}

//输入IR的文本形式，将其转换成raw program之后进行处理，输出RISCV内容
void IRGenerate(const char* str)
{
    //解析字符串 str, 得到 Koopa IR 程序
    koopa_program_t program;
    koopa_error_code_t ret = koopa_parse_from_string(str, &program);
    assert(ret == KOOPA_EC_SUCCESS); //确保解析时没有出错

    //创建raw program builder构建raw program
    koopa_raw_program_builder_t builder = koopa_new_raw_program_builder();
    //将koopa IR 程序转换成raw program
    koopa_raw_program_t raw = koopa_build_raw_program(builder, program);
    //释放koopa IR程序占用的内存
    koopa_delete_program(program);

    //处理raw program
    Visit(raw);
    cout << rg.c_str();

    //处理完成, 释放 raw program builder 占用的内存
    koopa_delete_raw_program_builder(builder);
}

//访问raw program
void Visit(const koopa_raw_program_t &program)
{
    //执行一些必要操作
    cerr << "Raw Program Visit" << endl;


    //访问所有全局变量
    Visit(program.values);
    //访问所有函数
    Visit(program.funcs);
}

//访问raw slice
void Visit(const koopa_raw_slice_t &slice) 
{
    cerr << "Raw Slice Visit" << endl;
    for (size_t i = 0; i < slice.len; i++) 
    {
        auto ptr = slice.buffer[i];
        //根据slice的kind决定将ptr视作何种元素
        switch(slice.kind) 
        {
            case KOOPA_RSIK_FUNCTION:
                //访问函数
                Visit(reinterpret_cast<koopa_raw_function_t>(ptr));
                break;
            case KOOPA_RSIK_BASIC_BLOCK:
                //访问基本块
                Visit(reinterpret_cast<koopa_raw_basic_block_t>(ptr));
                break;
            case KOOPA_RSIK_VALUE:
                //访问指令
                Visit(reinterpret_cast<koopa_raw_value_t>(ptr));
                break;
            default:
                //没有其他情况
                assert(false);
        }
    }
}

//访问函数
void Visit(const koopa_raw_function_t &func) 
{
    cerr << "Function Visit" << endl;
    if(func->bbs.len == 0) return; //如果函数bbs空，直接返回
    fc.setFunc(func);
    
    //将func->name的第一位字符@去掉
    string func_name(func->name);
    string::iterator p = func_name.begin();
    func_name.erase(p);
    //添加输出
    rg.append("\t.text\n");
    rg.append("\t.globl " + func_name + "\n");
    rg.append(func_name + ":\n");

    //清空配栈局部变量地址
    la.clear();
    //先完成局部变量分配
    AllocateLocalAddress(func);
    la.getDelta();

    //函数的开头部分riscv输出
    if(la.delta != 0)
        rg.sp(-(int)la.delta);
    if(la.R != 0)
        rg.store("ra", "sp", (int)la.delta - 4);

    // 找到entry block
    size_t e = 0;
    for(e; e < func->bbs.len; e++)
    {
        auto eb = reinterpret_cast<koopa_raw_basic_block_t>(func->bbs.buffer[e]);
        if(eb->name != nullptr && !strcmp(eb->name, "%entry"))
            break;
    }
    ////////合并成Visit(eb)
    //访问entry block
    Visit(reinterpret_cast<koopa_raw_basic_block_t>(func->bbs.buffer[e]));

    for(size_t i = 0; i < func->bbs.len; i++)
    {
        if(i == e) 
            continue;
        Visit(reinterpret_cast<koopa_raw_basic_block_t>(func->bbs.buffer[i]));
    }

    //函数的epilogue在ret指令完成
    rg.append("\n\n");
}

//访问基本块
void Visit(const koopa_raw_basic_block_t &bb) 
{
    // 执行一些其他的必要操作
    cerr << "Basic Block Visit" << endl;
    //判断是否为entry block
    if(bb->name != nullptr && strcmp(bb->name, "%entry"))
        rg.label(string(bb->name + 1));

    //遍历所有basic block
    for(size_t i = 0; i < bb->insts.len; i++)
        Visit(reinterpret_cast<koopa_raw_value_t>(bb->insts.buffer[i]));
}

//访问指令
void Visit(const koopa_raw_value_t &value) 
{
    //根据指令类型判断后续需要如何访问
    const auto &kind = value->kind;

    switch (kind.tag) 
    {
        case KOOPA_RVT_RETURN:
            //访问 return 指令
            Visit(kind.data.ret);
            break;
        case KOOPA_RVT_INTEGER:
            //访问 integer 指令
            Visit(kind.data.integer);
            break;
        case KOOPA_RVT_BINARY:
            //访问 binary 二元运算指令
            Visit(kind.data.binary);
            rg.store("t0", "sp", la.getOffset(value));
            break;
        case KOOPA_RVT_ALLOC:
            //本地内存分配指令，什么也不用做
            cerr << "not define alloc now" << endl;
            break;
        case KOOPA_RVT_LOAD:
            //加载指令
            // cerr << "not define load now" << endl;
            Visit(kind.data.load);
            rg.store("t0", "sp", la.getOffset(value));
            break;
        case KOOPA_RVT_STORE:
            //存储指令
            cerr << "not define store now" << endl;
            Visit(kind.data.store);
            break;
        case KOOPA_RVT_GET_ELEM_PTR:
            //得到元素指针指令
            cerr << "not define element ptr now" << endl;
            break;
        case KOOPA_RVT_CALL:
          //函数调用指令
          cerr << "not define call now" << endl;
          Visit(kind.data.call);
          if(kind.data.call.callee->ty->data.function.ret->tag == KOOPA_RTT_INT32){
              rg.store("a0", "sp", la.getOffset(value));
          }
          break;
        case KOOPA_RVT_BRANCH:
          //分支指令
          cerr << "not define branch now" << endl;
          Visit(kind.data.branch);
          break;
        case KOOPA_RVT_JUMP:
          //跳转指令
        //   cerr << "not define jump now" << endl;
          Visit(kind.data.jump);
          break;
        case KOOPA_RVT_GET_PTR:
          //得到指针指令
          cerr << "not define ptr now" << endl;
          break;
        case KOOPA_RVT_UNDEF:
          //未定义指令
          cerr << "not define undef now" << endl;
          break;
        case KOOPA_RVT_AGGREGATE:
          //聚集常数指令
          cerr << "not define aggregate now" << endl;
          break;
        case KOOPA_RVT_FUNC_ARG_REF:
          //函数参数指令
          cerr << "not define func arg now" << endl;
          break;
        case KOOPA_RVT_BLOCK_ARG_REF:
          //基本块参数指令
          cerr << "not define block arg now" << endl;
          break;
        case KOOPA_RVT_GLOBAL_ALLOC:
          //全局内存分配指令
          VisitGlobalVar(value);
          cerr << "not define global alloc now" << endl;
          break;
        case KOOPA_RVT_ZERO_INIT:
          //零初始值设定项指令
          cerr << "not define zero init now" << endl;
          break;
        default:
          //其他类型暂时遇不到
          cerr << "You meet an error!!" << endl;
          assert(false);
    }
}

//访问return类型指令
void Visit(const koopa_raw_return_t &ret)
{
    cerr << "Return Raw Visit" << endl;
    if(ret.value != nullptr)
    {
        koopa_raw_value_t ret_value = ret.value;
        //return为整数情况
        if(ret_value->kind.tag == KOOPA_RVT_INTEGER)
        {
            int ret_int = Visit(ret_value->kind.data.integer);
            rg.li("a0", ret_int);
        } 
        else
        {
            int i = la.getOffset(ret_value);
            rg.load("a0", "sp", i);
        }
    }
    if(la.R)
        rg.load("ra", "sp", la.delta - 4);
    if(la.delta)
        rg.sp(la.delta);
    rg.ret();
}

//访问integer类型指令
int Visit(const koopa_raw_integer_t &integer)
{
  cerr << "Integer Raw Visit" << endl;
  return integer.value;
}

//访问binary二元运算类型指令
void Visit(const koopa_raw_binary_t &binary)
{
    cerr << "Binary Raw Visit" << endl;

    //首先把左右操作数分别加载到寄存器t0,t1
    if(binary.lhs->kind.tag == KOOPA_RVT_INTEGER)
        rg.li("t0", Visit(binary.lhs->kind.data.integer));
    else
        rg.load("t0", "sp", la.getOffset(binary.lhs));
    if(binary.rhs->kind.tag == KOOPA_RVT_INTEGER)
        rg.li("t1", Visit(binary.rhs->kind.data.integer));
    else
        rg.load("t1", "sp", la.getOffset(binary.rhs));

    string op;
    //判断二元运算类型
    switch (binary.op)
    {
        case KOOPA_RBO_NOT_EQ:
            //ne
            rg.binary("xor", "t0" ,"t0", "t1");
            rg.two("snez", "t0", "t0");
            break;
        case KOOPA_RBO_EQ:
            //eq
            rg.binary("xor", "t0" ,"t0", "t1");
            rg.two("seqz", "t0", "t0");
            break;
        case KOOPA_RBO_GE:
            //ge
            rg.binary("slt", "t0", "t0", "t1");
            rg.two("seqz", "t0", "t0");
            break;
        case KOOPA_RBO_LE:
            //le
            rg.binary("sgt", "t0", "t0", "t1");
            rg.two("seqz", "t0", "t0");
            break;
        default:
            //其他二元运算指令
            op = inst_op[(int)binary.op];
            rg.binary(op, "t0", "t0", "t1");
            break;
    }
}

//访问load指令
void Visit(const koopa_raw_load_t &load)
{
    koopa_raw_value_t src = load.src;
    //如果是全局变量
    if(src->kind.tag == KOOPA_RVT_GLOBAL_ALLOC)
    {
        rg.la("t0", string(src->name + 1));
        rg.load("t0", "t0", 0);
    }
    //如果非全局变量则栈分配
    else if(src->kind.tag == KOOPA_RVT_ALLOC)
        rg.load("t0", "sp", la.getOffset(src));
    //其他情况
    else
    {
        rg.load("t0", "sp", la.getOffset(src));
        rg.load("t0", "t0", 0);
    }
}

//访问store指令
void Visit(const koopa_raw_store_t &store)
{
    int i, j;
    if(store.value->kind.tag == KOOPA_RVT_FUNC_ARG_REF)
    {
        i = fc.getParamNum(store.value);
        if(i < 8)
        {
            string regt = "a" + to_string(i);
            if(store.dest->kind.tag == KOOPA_RVT_GLOBAL_ALLOC)
            {
                rg.la("t0", string(store.dest->name + 1));
                rg.store(regt, "t0", 0);
            }
            else if(store.dest->kind.tag == KOOPA_RVT_ALLOC)
                rg.store(regt, "sp", la.getOffset(store.dest));
            //间接引用
            else
            {
                rg.load("t0", "sp", la.getOffset(store.dest));
                rg.store(regt, "t0", 0);
            }
            return ;
        }
        else
        {
            i = (i - 8) * 4;
            rg.load("t0", "sp", i + la.delta); //caller帧栈中
        }
    }
    else if(store.value->kind.tag == KOOPA_RVT_INTEGER)
        rg.li("t0", Visit(store.value->kind.data.integer));
    else
        rg.load("t0", "sp", la.getOffset(store.value));

    if(store.dest->kind.tag == KOOPA_RVT_GLOBAL_ALLOC)
    {
        rg.la("t1", string(store.dest->name + 1));
        rg.store("t0", "t1", 0);
    }
    else if(store.dest->kind.tag == KOOPA_RVT_ALLOC)
        rg.store("t0", "sp", la.getOffset(store.dest));
    else
    {
        rg.load("t1", "sp", la.getOffset(store.dest));
        rg.store("t0", "t1", 0);
    }

    return ;
}

// 访问jump指令
void Visit(const koopa_raw_jump_t &jump){
    auto name = string(jump.target->name + 1);
    rg.jump(name);
    return;
}

// 访问branch指令
void Visit(const koopa_raw_branch_t &branch){
    auto true_bb = branch.true_bb;
    auto false_bb = branch.false_bb;
    koopa_raw_value_t v = branch.cond;
    if(v->kind.tag == KOOPA_RVT_INTEGER){
        rg.li("t0", Visit(v->kind.data.integer));
    }else{
        rg.load("t0", "sp", la.getOffset(v));
    }
    // 这里，用条件跳转指令跳转范围只有4KB，过不了long_func测试用例
    // 1MB。
    // 因此只用bnez实现分支，然后用jump调到目的地。
    string tmp_label = tb.StickTable();
    rg.bnez("t0", tmp_label);
    rg.jump(string(false_bb->name + 1));
    rg.label(tmp_label);
    rg.jump(string(true_bb->name + 1));
    return;
}

// 访问 call 指令
void Visit(const koopa_raw_call_t &call){
    for(int i = 0; i < call.args.len; ++i){
        koopa_raw_value_t v = (koopa_raw_value_t)call.args.buffer[i];
        if(v->kind.tag == KOOPA_RVT_INTEGER){
            int j = Visit(v->kind.data.integer);
            if(i < 8){
                rg.li("a" + to_string(i), j);
            } else {
                rg.li("t0", j);
                rg.store("t0", "sp", (i - 8) * 4);
            }
        } else{
            int off = la.getOffset(v);
            if(i < 8){
                rg.load("a" + to_string(i), "sp", off);
            } else {
                rg.load("t0", "sp", off);
                rg.store("t0", "sp", (i - 8) * 4);
            }
        }
    }
    rg.call(string(call.callee->name + 1));
    // if(call.callee->ty->data.function.ret->tag ==KOOPA_RTT_INT32)
    return;
}


// 访问全局变量
void VisitGlobalVar(koopa_raw_value_t value){
    rg.append("  .data\n");
    rg.append("  .globl " + string(value->name + 1) + "\n");
    rg.append(string(value->name + 1) + ":\n");
    koopa_raw_value_t init = value->kind.data.global_alloc.init;
    auto ty = value->ty->data.pointer.base;
    if(ty->tag == KOOPA_RTT_INT32){
        if(init->kind.tag == KOOPA_RVT_ZERO_INIT){
            rg.zeroInitInt();
        } else {
            int i = Visit(init->kind.data.integer);
            rg.word(i);
        }
    } else{
        // see aggragate
        assert (init->kind.tag == KOOPA_RVT_AGGREGATE) ;
        initGlobalArray(init);
    }
    rg.append("\n");
    return ;
}

void initGlobalArray(koopa_raw_value_t init){
    if(init->kind.tag == KOOPA_RVT_INTEGER){
        int v = Visit(init->kind.data.integer);
        rg.word(v);
    } else {
        // KOOPA_RVT_AGGREGATE
        auto elems = init->kind.data.aggregate.elems;
        for(int i = 0; i < elems.len; ++i){
            initGlobalArray(reinterpret_cast<koopa_raw_value_t>(elems.buffer[i]));
        }
    }
}

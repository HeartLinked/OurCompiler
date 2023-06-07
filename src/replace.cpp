#include <iostream>
#include <fstream>
#include <string>
#include <regex>

void replaceInFile(const std::string& filePath) {
    std::ifstream fileIn(filePath);
    std::string fileContent;
    if(fileIn.is_open()) {
        std::string line;
        while(std::getline(fileIn, line)) {
            fileContent += line + "\n";
        }
        fileIn.close();
    }
    else {
        std::cerr << "Unable to open the file\n";
        return;
    }

    // 正则表达式匹配 2 到 6 个连续的 %、英文字母、数字和下划线的组合
    std::regex pattern1("([%a-zA-Z0-9_]{2,6} = call @putint)");
    std::string newContent1 = std::regex_replace(fileContent, pattern1, "call @putint");
    std::regex pattern2("([%a-zA-Z0-9_]{2,6} = call @putch)");
    std::string newContent2 = std::regex_replace(newContent1, pattern2, "call @putch");
    
    std::ofstream fileOut(filePath);
    if(fileOut.is_open()) {
        fileOut << newContent2;
        fileOut.close();
    }
    else {
        std::cerr << "Unable to open the file\n";
    }
}

// int main() {
//     replaceInFile("hello.S");
//     return 0;
// }

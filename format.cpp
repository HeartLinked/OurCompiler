#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

void FormatFile(const std::string &filename) {
    std::ifstream inFile(filename);

    if (!inFile) {
        std::cerr << "Error opening file.\n";
        return;
    }

    std::string content((std::istreambuf_iterator<char>(inFile)),
                        std::istreambuf_iterator<char>());

    inFile.close();

    int indentLevel = 0;
    std::string formatted = "";
    std::stack<char> brackets;
    bool isNewLine = false;

    for (char c : content) {
        if (c == '{') {
            indentLevel++;
            formatted += "{\n" + std::string(indentLevel * 4, ' ');
            brackets.push(c);
            isNewLine = true;
        } else if (c == '}') {
            if (!brackets.empty()) {
                brackets.pop();
                indentLevel--;
            }
            if (!isNewLine) {
                formatted += "\n" + std::string(indentLevel * 4, ' ');
            }
            formatted += "}\n" + std::string(indentLevel * 4, ' ');
            isNewLine = true;
        } else if (c == ',') {
            formatted += ", ";
            isNewLine = false;
        } else {
            formatted += c;
            isNewLine = false;
        }
    }

    // Write the formatted content back to the file
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening file for write.\n";
        return;
    }
    outFile << formatted;
    outFile.close();
}

void formatFile(const std::string &filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }

    std::ostringstream formatted;
    std::string line;
    while (std::getline(inFile, line)) {
        bool isBlank = true;
        for (char ch : line) {
            if (!std::isspace(ch)) {
                isBlank = false;
                break;
            }
        }
        if (!isBlank) {
            formatted << line << '\n';
        }
    }
    inFile.close();

    // Re-open the file in output mode to overwrite it
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Unable to open file for writing: " << filename
                  << std::endl;
        return;
    }

    // Write the formatted content to the file
    outFile << formatted.str();
    outFile.close();
}

void Format(const std::string &filename) {
    FormatFile(filename); // replace with your file name
    formatFile(filename); // replace with your file name
}

int main() {
    Format("test1.koopa");
    return 0;
}

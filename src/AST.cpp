#include "AST.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <random>
#include <unordered_map>
#include <vector>
#include <set>

int cnt = 0, cnt2 = 'A', cnt3 = 'A', cnt4 = 'A', cnt5 = 'a', cnt6 = '0', cnt7 = '0';

int gen() { return cnt++; }

char gen2() {return cnt2++;}

char ifGen3() {return cnt3++;}

char whileGen4() {return cnt4++;}

char breakGen5() {return cnt5++;}

char entrygen() {return cnt6++; }

char labelgen() {return cnt7++; }

std::string generateRandomString() {
    std::string validChars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, validChars.length() - 1);

    std::string randomString;
    for (int i = 0; i < 3; ++i) {
        char randomChar = validChars[distribution(generator)];
        randomString += randomChar;
    }

    return randomString;
}

string genLabel(string s) {
    return s + "_" + labelgen() + "_" + generateRandomString();
}


bool hasDuplicateElements(const std::vector<string>& vec) {
    std::set<string> uniqueElements;

    for (const auto& element : vec) {
        if (uniqueElements.find(element) != uniqueElements.end()) {
            return true;  // 发现重复元素，返回 true
        }
        uniqueElements.insert(element);
    }

    return false;  // 未发现重复元素，返回 false
}
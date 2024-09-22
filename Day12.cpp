
#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> bracketMap = {
        {')', '('},
        {'}', '{'},
        {']', '['}
    };

    for (char ch : s)
    {
        if (bracketMap.count(ch)) 
        {
            if (stack.empty() || stack.top() != bracketMap[ch]) 
            {
                return false;  
            }
            stack.pop(); 
        } else 
        {
            stack.push(ch);
        }
    }

    return stack.empty();
}

int main() {
    std::string s = "{[()]}";
    if (isValid(s)) {
        std::cout << "True (string is valid)" << std::endl;
    } else {
        std::cout << "The string is not valid." << std::endl;
    }
    return 0;
}
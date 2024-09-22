#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(const std::vector<std::string>& strs)
 {
    if (strs.empty()) return "";

    std::string prefix = strs[0];

    for (size_t i = 1; i < strs.size(); ++i) {
        const std::string& str = strs[i];
        size_t j = 0;
        
        while (j < prefix.length() && j < str.length() && prefix[j] == str[j]) 
        {
            j++;
        }
        
        prefix = prefix.substr(0, j);
        
        if (prefix.empty()) return "";
    }

    return prefix;
}

int main()
 {
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = longestCommonPrefix(strs);
    std::cout << "Longest common prefix: " << result << std::endl;
    return 0;
}
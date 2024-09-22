
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

void backtrack(std::string& s, std::vector<bool>& visited, std::string& current, std::vector<std::string>& result) {
    if (current.length() == s.length()) {
        result.push_back(current);
        return;
    }

    for (size_t i = 0; i < s.length(); ++i) {
        if (visited[i]) continue;
        if (i > 0 && s[i] == s[i - 1] && !visited[i - 1]) continue;

        visited[i] = true; 
        current.push_back(s[i]); 

        backtrack(s, visited, current, result); 
        visited[i] = false; 
        current.pop_back(); 
    }
}

std::vector<std::string> permuteUnique(std::string s) {
    std::vector<std::string> result;
    std::string current;
    std::vector<bool> visited(s.length(), false);

    std::sort(s.begin(), s.end());

    backtrack(s, visited, current, result);
    return result;
}

int main()
 {
    std::string s = "abc";
    std::vector<std::string> permutations = permuteUnique(s);
    for (const auto& perm : permutations) {
        std::cout << perm << std::endl;
    }
    return 0;
}
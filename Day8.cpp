#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

std::string reverseWords(const std::string& s) 
{
    std::istringstream stream(s);
    std::vector<std::string> words;
    std::string word;
    while (stream >> word) 
    {
        words.push_back(word);
    }
    std::reverse(words.begin(), words.end());
    std::ostringstream result;
    for (size_t i = 0; i < words.size(); ++i)
    {
        if (i != 0) 
        {
            result << " ";  
        }
        result << words[i];
    }
        return result.str();
}
int main() 
{
    std::string input = "the sky is blue";
    std::string output = reverseWords(input);
    
    std::cout << output << std::endl;  
    
    return 0;
}
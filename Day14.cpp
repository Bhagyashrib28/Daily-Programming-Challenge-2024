#include <iostream>
#include <string>
#include <unordered_map>

int atMostKDistinct(const std::string& s, int k) 
{
    if (k == 0) return 0; 
    std::unordered_map<char, int> charCount;
    int left = 0, count = 0;
    for (int right = 0; right < s.size(); ++right)
    {
        charCount[s[right]]++;
        while (charCount.size() > k) 
        {
            charCount[s[left]]--;
            if (charCount[s[left]] == 0) 
            {
                charCount.erase(s[left]);
            }
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int countSubstringsWithKDistinct(const std::string& s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    std::string s = "aabacbebebe";
    int k = 3;
    int result = countSubstringsWithKDistinct(s, k);
    std::cout << "Number of substrings with exactly " << k << " distinct characters: " << result << std::endl;
    return 0;
}
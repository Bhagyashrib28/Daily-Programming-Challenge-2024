#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<std::pair<int, int>> findZeroSumSubarrays(const std::vector<int>& arr) {
    std::vector<std::pair<int, int>> result;
    std::unordered_map<int, int> prefixSumMap;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); ++i) {
        prefixSum += arr[i];


        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        
        if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
            result.push_back({prefixSumMap[prefixSum] + 1, i});
        }


        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
            prefixSumMap[prefixSum] = i;
        }
    }

    return result;
}

int main() {
    std::vector<int> arr = {1, 2, -3, 3, -1, 2};
    std::vector<std::pair<int, int>> zeroSumSubarrays = findZeroSumSubarrays(arr);

    std::cout << "Subarrays with sum zero:\n";
    for (const auto& p : zeroSumSubarrays) {
        std::cout << "(" << p.first << ", " << p.second << ")\n";
    }

    return 0;
}
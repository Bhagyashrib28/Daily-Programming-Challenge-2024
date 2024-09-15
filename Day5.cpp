#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

std::vector<int> findLeaders(const std::vector<int>& arr) {
    std::vector<int> leaders;
    if (arr.empty()) return leaders;

    int n = arr.size();
    int max_from_right = arr[n - 1];
    leaders.push_back(max_from_right);

    // Traverse the array from right to left
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > max_from_right) {
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }

    // Reverse the leaders vector to maintain the original order
    std::reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main() {
    std::vector<int> arr = {16, 17, 4, 3, 5, 2};
    std::vector<int> leaders = findLeaders(arr);

    std::cout << "Leaders: [";
    for (size_t i = 0; i < leaders.size(); ++i) {
        std::cout << leaders[i];
        if (i < leaders.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
#include <iostream>
#include <vector>

void mergeInPlace(std::vector<int>& arr1, int m, std::vector<int>& arr2, int n) {
    
    int i = m - 1;  
    int j = n - 1;  
    int k = m + n - 1;  

    
    while (i >= 0 && j >= 0) {
        if (arr1[i] > arr2[j]) {
            arr1[k--] = arr1[i--];
        } else {
            arr1[k--] = arr2[j--];
        }
    }


    while (j >= 0) {
        arr1[k--] = arr2[j--];
    }

    for (int l = 0; l < n; l++) {
        arr2[l] = arr1[m + l];
    }


    arr1.resize(m);  
}

int main() {
    std::vector<int> arr1 = {1, 3, 5, 7, 0, 0, 0, 0};  
    std::vector<int> arr2 = {2, 4, 6, 8};

    int m = 4;  
    int n = 4;  

    mergeInPlace(arr1, m, arr2, n);

    std::cout << "arr1: ";
    for (int num : arr1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "arr2: ";
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
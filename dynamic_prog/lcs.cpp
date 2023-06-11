#include <iostream>
#include <vector>

std::vector<int> lcs(const std::vector<int>& arr) {
    int n = arr.size();
    std::vector<int> lis(n, 1);
    std::vector<int> prevIndex(n, -1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prevIndex[i] = j;
            }
        }
    }

    int maxLen = 0;
    int maxLenIndex = 0;
    for (int i = 0; i < n; i++) {
        if (lis[i] > maxLen) {
            maxLen = lis[i];
            maxLenIndex = i;
        }
    }

    std::vector<int> subsequence;
    while (maxLenIndex != -1) {
        subsequence.push_back(arr[maxLenIndex]);
        maxLenIndex = prevIndex[maxLenIndex];
    }

    std::cout << "Length of the Longest Increasing Subsequence: " << maxLen << std::endl;
    std::cout << "Subsequence: ";
    for (int i = subsequence.size() - 1; i >= 0; i--) {
        std::cout << subsequence[i] << " ";
    }
    std::cout << std::endl;

    return subsequence;
}

int main() {
    std::vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};

    std::vector<int> resultingSubsequence = lcs(arr);

    return 0;
}

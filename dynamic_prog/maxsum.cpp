#include <iostream>
#include <vector>

int maxSubarraySum(const std::vector<int>& arr) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        currentSum += arr[i];

        if (currentSum < 0) {
            currentSum = 0;
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    std::vector<int> arr = {1, -2, 3, 7 , -4, -5};
    int maxSum = maxSubarraySum(arr);

    std::cout << "Maximum sum of a contiguous subarray: " << maxSum << std::endl;

    return 0;
}

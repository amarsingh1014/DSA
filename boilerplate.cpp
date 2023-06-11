#include <iostream>
#include <vector>

bool subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base case: It is always possible to obtain a sum of zero using no elements.
    dp[0][0] = true;

    // Fill the dp array
    for (int i = 1; i <= n; i++) {
        int num = nums[i - 1];
        for (int j = 0; j <= target; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= num) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - num];
            }
        }
    }

    return dp[n][target];
}

int main() {
    std::vector<int> nums = {3, 7, 2, 9, 1};
    int target = 12;

    bool hasSubset = subsetSum(nums, target);

    if (hasSubset) {
        std::cout << "There exists a subset that adds up to the target sum." << std::endl;
    } else {
        std::cout << "No subset exists that adds up to the target sum." << std::endl;
    }

    return 0;
}


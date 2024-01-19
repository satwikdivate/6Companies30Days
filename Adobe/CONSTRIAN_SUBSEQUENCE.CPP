// class Solution {
// public:
//     int constrainedSubsetSum(vector<int>& nums, int k) {
//          int n = nums.size();
//         std::vector<int> dp(n, 0);

//         dp[n - 1] = nums[n - 1];
//         int maximum = dp[n - 1];
//         int currentMaxIndex = n - 1;
//         int limit;

//         for (int i = n - 2; i >= 0; i--) {
//             if (currentMaxIndex - i > k) {
//                 limit = std::min(i + k + 1, n);
//                 currentMaxIndex = i + 1;

//                 for (int j = i + 2; j < limit; j++) {
//                     if (dp[currentMaxIndex] < dp[j]) {
//                         currentMaxIndex = j;
//                     }
//                 }
//             }

//             dp[i] = std::max(nums[i], nums[i] + dp[currentMaxIndex]);

//             if (dp[i] >= dp[currentMaxIndex]) {
//                 currentMaxIndex = i;
//             }

//             maximum = std::max(maximum, dp[i]);
//         }

//         return maximum;
//     }
// };
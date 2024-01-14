  #include<bits/stdc++.h>
using namespace std;
 vector<int> largestDivisibleSubset(vector<int>&nums) {
        // sort the array
     sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<int> dp(n, 1), parent(n, -1);
    int maxIndex = 0, maxSize = 1;

    // Dynamic programming to find the maximum size of divisible subset
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if (dp[i] > maxSize) {
                    maxSize = dp[i];
                    maxIndex = i;
                }
            }
        }
    }

    // Reconstructing the subset
    vector<int> ans;
    for (int i = maxIndex; i != -1; i = parent[i]) {
        ans.push_back(nums[i]);
    }

    return ans;
    }
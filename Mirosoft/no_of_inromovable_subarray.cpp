#include<bits/stdc++.h>
using namespace std;

int incremovableSubarrayCount(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i >= 2 && nums[i - 1] <= nums[i - 2]) return ans;
            int j = nums.size();
            while(j > i && (j == nums.size() || nums[j] > nums[j - 1]) && (i == 0 || nums[j - 1] > nums[i - 1])) j--;
            ans += (nums.size() + 1 - max(j, i + 1));
        }
        return ans;
    }
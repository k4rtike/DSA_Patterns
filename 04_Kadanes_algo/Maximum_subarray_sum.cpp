/*
Leetcoed:53
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
*/

#include<bits/stdc++.h>
using namespace std;
int maxSubArray(vector<int>& nums) {

    int ans=nums[0];
    int best = nums[0];

    for(int i=1; i<nums.size(); i++){
        int prev=best+nums[i];
        int curr = nums[i];
        best=max(prev, curr);
        ans = max(best, ans);
    }
    return ans;
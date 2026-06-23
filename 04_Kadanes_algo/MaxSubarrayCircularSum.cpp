/*
https://leetcode.com/problems/maximum-sum-circular-subarray/description/
918. Maximum Sum Circular Subarray
Medium
Topics
premium lock icon
Companies
Hint
Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.

A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].

A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

 

Example 1:

Input: nums = [1,-2,3,-2]
Output: 3
Explanation: Subarray [3] has maximum sum 3.
Example 2:

Input: nums = [5,-3,5]
Output: 10
Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10.

*/

//Think of a doughnut , and try to find out the sweetest part, in one bite.

#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumCircular(vector<int>& nums) {

        int bestmax = nums[0];
        int bestmin = nums[0];
        int ans = nums[0];
        int minArr = nums[0];
        int ans2=0;

        int sum=nums[0];

        for(int i=1; i<nums.size(); i++){
            sum = sum+nums[i];
            int prevSum = bestmax + nums[i];
            int curr1=nums[i];
            bestmax = max(curr1, prevSum);
            ans = max(bestmax, ans);

            int prevMin = bestmin + nums[i];
            int curr2 = nums[i];
            bestmin = min(curr2, prevMin);
            minArr = min(bestmin, minArr);
        }
        
        int circular = sum-minArr;
        if(ans<0){
            return ans;
        }
        return max(ans, circular);
    }
/*

You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).

Return the maximum absolute sum of any (possibly empty) subarray of nums.

Note that abs(x) is defined as follows:

If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 

Example 1:

Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

*/
#include<bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int minSum=INT_MAX;
    int maxSum=INT_MIN;
    int minEnd=0;
    int maxEnd=0;

    for(int i=0; i<nums.size(); i++){
        minEnd=min(nums[i], minEnd+nums[i]);
        minSum=min(minEnd, minSum);

        maxEnd=max(nums[i], maxEnd+nums[i]);
        maxSum= max(maxEnd, maxSum);
    }

    return max(abs(maxSum), abs(minSum));
}
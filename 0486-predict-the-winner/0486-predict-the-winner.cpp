class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
          int n = nums.size();
        
        // Base case: Subarrays of length 1 (dp[i] initially represents dp[i][i])
        vector<int> dp(nums.begin(), nums.end());
        
        // Iterate through all possible subarray lengths
        for (int length = 1; length < n; ++length) {
            for (int i = 0; i < n - length; ++i) {
                int j = i + length;
                // dp[i+1] represents the old dp[i+1][j]
                // dp[i] represents the old dp[i][j-1]
                dp[i] = std::max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            }
        }
        
        // If Player 1's relative score difference is non-negative, 
    //they  win
        return dp[0] >= 0;
        
    }
};
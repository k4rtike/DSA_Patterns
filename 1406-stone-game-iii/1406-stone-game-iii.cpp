class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        // dp[i] stores the max relative score a player can get starting from index i
        // Size is n + 1 to handle the base case out of bounds safely (dp[n] = 0)
        vector<int> dp(n + 1, 0);
        
        // Traverse backwards from the last stone to the first
        for (int i = n - 1; i >= 0; --i) {
            int takeOne = INT_MIN;
            int takeTwo = INT_MIN;
            int takeThree = INT_MIN;
            
            // Option 1: Take 1 stone
            takeOne = stoneValue[i] - dp[i + 1];
            
            // Option 2: Take 2 stones (if available)
            if (i + 1 < n) {
                takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[i + 2];
            }
            
            // Option 3: Take 3 stones (if available)
            if (i + 2 < n) {
                takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3];
            }
            
            // Current player chooses the optimal strategy
            dp[i] = max({takeOne, takeTwo, takeThree});
        }
        
        // dp[0] holds Alice's relative score margin over Bob for the full game
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};
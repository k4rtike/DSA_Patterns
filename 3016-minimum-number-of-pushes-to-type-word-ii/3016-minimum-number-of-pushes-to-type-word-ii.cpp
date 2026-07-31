class Solution {
public:
    int minimumPushes(string word) {
         // Step 1: Count character frequencies using a fixed-size array
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        
        // Step 2: Sort frequencies in descending order
        sort(freq.rbegin(), freq.rend());
        
        // Step 3: Accumulate total pushes needed
        int totalPushes = 0;
        for (int i = 0; i < 26 && freq[i] > 0; i++) {
            int pushesPerLetter = (i / 8) + 1;
            totalPushes += freq[i] * pushesPerLetter;
        }
        
        return totalPushes;
    }
};
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.length();
        
        // Extract and sort the first half
        string left_half = s.substr(0, n / 2);
        sort(left_half.begin(), left_half.end());
        
        // Get the middle element for odd lengths
        string mid = (n % 2 != 0) ? string(1, s[n / 2]) : "";
        
        // Construct the right half by reversing the sorted left half
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());
        
        return left_half + mid + right_half;
    }
};
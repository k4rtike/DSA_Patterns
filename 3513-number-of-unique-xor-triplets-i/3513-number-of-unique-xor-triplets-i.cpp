class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        return 1 << (static_cast<int>(std::log2(n)) + 1);
    }
};
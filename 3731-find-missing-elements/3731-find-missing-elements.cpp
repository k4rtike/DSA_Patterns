class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto [min_it, max_it] = minmax_element(nums.begin(), nums.end());
        int mn = *min_it;
        int mx = *max_it;
        
        unordered_set<int> num_set(nums.begin(), nums.end());
        vector<int> result;
        
        for (int i = mn; i <= mx; ++i) {
            if (num_set.find(i) == num_set.end()) {
                result.push_back(i);
            }
        }
        return result;
    }
};
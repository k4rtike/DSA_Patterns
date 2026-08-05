class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        bitset<2048> single, pair, triplet;
        for(int x : nums) single.set(x);

        for(int i=0; i<2048; ++i){
            if(!single[i]) continue;
            for(int j=i; j<2048; ++j){
                if(single[j]) pair.set(i ^ j);
            }
        }
        for(int p=0; p<2048; ++p){
            if(!pair[p]) continue;
            for(int x = 0; x<2048; ++x){
                if(single[x]) triplet.set(p ^ x);
            }
        }
        return triplet.count();
        
    }
};
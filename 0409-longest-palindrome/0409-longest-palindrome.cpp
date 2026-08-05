class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> h;
        for(int i=0; i<s.size(); i++){
            h[s[i]]++;
        }
        bool odd = false;
        int res=0;

        for(auto i : h){
            int val = i.second;
            if(val%2==0){
                res+=val;
            }
            else{
                odd = true;
            }
        }

        if(odd==false){
            return res;
        }
        for(auto i:h){
            int val=i.second;

            if(val%2==1){
                res+= (val-1);
            }
        }
        return res+1;
    }
};
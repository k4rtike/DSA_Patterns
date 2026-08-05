class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> f;
        int n=s.size();

        for(int i=0; i<n; i++){
            f[s[i]]++; //agar i index vala char hoga to increse ho jayegi otherwise entry create hoke frequency upgrade ho jayegi.
        }

        for(int i=0; i<n;i++){
            if(f[s[i]]==1){
                //first unique mil gya 1 return kar do
                return i;
            }
        }
        return -1;
        
    }
};
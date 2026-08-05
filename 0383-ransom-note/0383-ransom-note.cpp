class Solution {
public:
    bool answer(unordered_map<char,int> have, unordered_map<char,int> need){
        for(auto i : need){
            char c=i.first;
            int fneed = i.second;
            int fhave = have[c];

            if(fhave<fneed){
                return false;
            }
        }
        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> need;
        unordered_map<char,int> have;
        int ran=ransomNote.size();
        int mag=magazine.size();
        for(int i=0; i<ran; i++){
            need[ransomNote[i]]++;
        }
        for(int i=0; i<mag; i++){
            have[magazine[i]]++;
        }

        return answer(have, need);
    }
};
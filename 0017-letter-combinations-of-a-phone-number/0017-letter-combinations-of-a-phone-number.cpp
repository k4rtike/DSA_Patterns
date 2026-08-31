class Solution {
private: void kit(string & digits, int n, int indx, string &notes, vector<string> & res, unordered_map<char, string> &hm){

    if(indx == n){
        res.push_back(notes);
        return;
    }
    string  choice = hm[digits[indx]];

    for(int j=0; j<choice.length();j++){
        notes.push_back(choice[j]);
        kit(digits, n, indx+1,notes,res, hm);

        notes.pop_back();
    }
}
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        int indx = 0;
        string notes="";
        unordered_map<char, string> hm;
        hm['2'] = "abc";
        hm['3'] = "def";
        hm['4'] = "ghi";
        hm['5'] = "jkl";
        hm['6'] = "mno";
        hm['7'] = "pqrs";
        hm['8'] = "tuv";
        hm['9'] = "wxyz";

        vector<string> res;

        kit(digits, n, indx, notes, res, hm);
        return res;
    }
};
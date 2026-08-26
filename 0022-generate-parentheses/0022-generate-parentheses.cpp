class Solution {
private: 
    void kit(int open, int close, int n, string & temp, vector<string>& res){
        if(open == n && close == n){
            res.push_back(temp);
            return;
        }

        if(open<n){
            temp.push_back('(');
            kit(open+1, close, n, temp, res);

            temp.pop_back();
        }

        if(close<open){
            temp.push_back(')');
            kit(open, close+1, n, temp, res);
            temp.pop_back();
        }

        return;
    }


public:
    vector<string> generateParenthesis(int n) {

        int open=0;
        int close=0;
        vector<string> res;
        string temp;

        kit(open, close, n, temp, res);
        return res;
        
    }
};
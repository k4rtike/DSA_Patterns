class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st;
        vector<int> res;

        int n=temperatures.size();
        res.push_back(0);
        st.push(n-1);

        for(int i=n-2; i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(st.empty()){
                res.push_back(0);
            }
            else {
                res.push_back(st.top()-i);
            }
            st.push(i);
        }
        reverse(res.begin(), res.end());
        return res;

    }
};
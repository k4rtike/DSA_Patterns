class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
    int n = word1.length(), m = word2.length();
    vector<int> last(m, -1);
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--)
        if (word1[i] == word2[j]) last[j--] = i;
    
    vector<int> ans;
    bool canSkip = true;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (word1[i] == word2[j]) ans.push_back(i), j++;
        else if (canSkip && (j == m - 1 || i < last[j + 1])) {
            canSkip = false;
            ans.push_back(i);
            j++;
        }
    }
    return ans.size() == m ? ans : vector<int>();
    }
};
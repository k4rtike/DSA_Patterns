/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<vector<int>> levelO(TreeNode* root){
        vector<vector<int>> res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool level=0;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize--){
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left!=NULL){
                    q.push(node->left);
                }
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            if(level){
                vector<int> rev;
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            level = 1-level;
        }
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        return levelO(root);
    }
};
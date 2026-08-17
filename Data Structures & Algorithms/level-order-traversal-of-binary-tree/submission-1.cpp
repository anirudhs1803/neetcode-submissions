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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> answer;

        while(!q.empty()){
            int size = q.size();
            vector<int> levels;
            for(int i =0; i< size ;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                levels.push_back(node->val);
            }
            answer.push_back(levels);
        }
        return answer;
    }
    
};

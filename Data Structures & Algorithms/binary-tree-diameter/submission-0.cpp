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
    int best =0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;
    }
    int height(TreeNode* node){
        if(node == nullptr){
            return 0;
        }
        int leftheight = height(node->left);
        int rightheight = height(node->right);

        best = max(leftheight+ rightheight, best);
        return max(leftheight, rightheight) +1;
    }
};

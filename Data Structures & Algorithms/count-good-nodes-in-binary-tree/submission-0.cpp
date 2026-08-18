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
    int countgood(TreeNode* node, int maxsofar){
        if(node == nullptr){
            return 0;
        }
        int count =0;
        if(node->val >= maxsofar){
            count = 1;
        }
        int newmax = max(maxsofar,node->val);

        count+= countgood(node->left, newmax);
        count+= countgood(node->right, newmax);

        return count;
    }
    int goodNodes(TreeNode* root) {
        return countgood(root, INT_MIN);
    }
};

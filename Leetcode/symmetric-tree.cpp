// Problem: https://leetcode.com/problems/symmetric-tree/

// Recursive

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
    bool isSymmetricRecursive(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        
        if(left == nullptr || right == nullptr){
            return false;
        }
        
        bool isEqual = (left->val == right->val);
        
        return isEqual && isSymmetricRecursive(left->left, right->right) && isSymmetricRecursive(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetricRecursive(root->left, root->right);
    }
};

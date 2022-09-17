// Problem: https://leetcode.com/problems/path-sum/

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
    bool hasPathSumRecursive(TreeNode* root, int targetSum){
        if(root->left == nullptr && root->right == nullptr){
            return targetSum == root->val;
        }
        
        bool resLeft = false;
        bool resRight = false;
        
        if(root->left != nullptr){
            resLeft = hasPathSumRecursive(root->left, targetSum-root->val);
        } 
        
        if(root->right != nullptr){
            resRight = hasPathSumRecursive(root->right, targetSum-root->val);
        }
        
        return resLeft || resRight;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr){
            return false;
        }
        
        return hasPathSumRecursive(root, targetSum);
    }
};

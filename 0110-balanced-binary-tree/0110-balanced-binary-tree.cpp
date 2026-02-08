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
    int findHeight(TreeNode* root, int h, bool&ans){
        if(root==NULL)return h;
        int leftH=findHeight(root->left,h+1,ans);
        int rightH=findHeight(root->right,h+1,ans);
        if(abs(leftH-rightH)>1)ans=false;
        return max(leftH,rightH);  
    }
    bool isBalanced(TreeNode* root) {
        bool ans=true;
        findHeight(root,0,ans);
        return ans;
    }
};
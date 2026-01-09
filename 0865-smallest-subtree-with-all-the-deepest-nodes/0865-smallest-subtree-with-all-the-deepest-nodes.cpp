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
    pair<TreeNode*,int> maxDepth(TreeNode* node, int depth){
        if(node==NULL)return {NULL,depth};
        if(node!=NULL){
            pair<TreeNode*,int>nodeLeft=maxDepth(node->left,depth+1);
            pair<TreeNode*,int>nodeRight=maxDepth(node->right,depth+1);
            if(nodeLeft.second==nodeRight.second){
                return{node,nodeLeft.second};
            }
            if(nodeLeft.second>nodeRight.second)return {nodeLeft.first,nodeLeft.second};
            else if(nodeRight.second>nodeLeft.second)return {nodeRight.first,nodeRight.second};
        }
        return {NULL,depth};
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        pair<TreeNode*,int> ans=maxDepth(root,0);
        return ans.first;
    }
};
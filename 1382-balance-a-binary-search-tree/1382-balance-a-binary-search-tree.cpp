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
    TreeNode* ConstructBST(vector<int>&InorderVect,int low,int high){
        if(low>high)return NULL;
        int mid = low+(high-low)/2;
        TreeNode *curr= new TreeNode(InorderVect[mid]);
        curr->left= ConstructBST(InorderVect,low,mid-1);
        curr->right= ConstructBST(InorderVect,mid+1,high);
        return curr;
    }
    void GetInorderVect(TreeNode* root,vector<int>&InorderVect){
        if(root==NULL)return;
        GetInorderVect(root->left,InorderVect);
        InorderVect.push_back(root->val);
        GetInorderVect(root->right,InorderVect);
        return;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>InorderVect;
        GetInorderVect(root,InorderVect);
        return ConstructBST(InorderVect,0,InorderVect.size()-1);
    }
};
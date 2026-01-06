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

 /*
    1. ->lvl:1

7.      8.  ->lvl:2

7 8.     ->lvl:3

         ->lvl:4
 */
class Solution {
public:
    unordered_map<int,int>levels;
    void recursion(int l,TreeNode* node){
        if(node==NULL)return;
        recursion(l+1,node->left);
        recursion(l+1,node->right);
        // int sum=left_val+right_val;
        // if(levels.count(l)!=levels.end()){
            levels[l]+=node->val;   
        // }
        // else{
        //     levels[l]=node->val;
        // }
 
    }
    int maxLevelSum(TreeNode* root) {
        recursion(1,root);
        int max_level_sum=INT_MIN;
        int max_level=0;
        for(auto itr=levels.begin();itr!=levels.end();itr++){
            if(itr->second>max_level_sum){
                max_level_sum=itr->second;
                max_level=itr->first;
            }
            // max_level_sum=max(max_level_sum,(itr->second));
        }
        return max_level;
    }
};
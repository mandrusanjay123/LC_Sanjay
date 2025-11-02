/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        ListNode* curr=head;
        ListNode* prev=new ListNode();
        ListNode* ans=prev;
        while(curr!=NULL){
            if(mp.find(curr->val)!=mp.end()){
                prev->next=curr->next;
                curr=curr->next;
            }
            else{
                prev->next=curr;
                curr=curr->next;
                prev=prev->next;
            }

        }
        return ans->next;
    }
};
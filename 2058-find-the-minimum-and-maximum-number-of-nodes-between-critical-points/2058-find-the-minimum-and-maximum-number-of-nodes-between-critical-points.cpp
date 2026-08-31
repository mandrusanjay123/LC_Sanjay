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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>places;
        ListNode*prev=head;
        vector<int>nullcase={-1,-1};
        if(prev==NULL)return nullcase;
        ListNode*curr=head->next;
        if(curr==NULL)return nullcase;
        ListNode*next=head->next->next;
        if(next==NULL)return nullcase;
        int id=1;
        while(next!=NULL){
            if(curr->val>prev->val&&curr->val>next->val)places.push_back(id);
            else if(curr->val<prev->val&&curr->val<next->val)places.push_back(id);
            prev=curr;
            curr=next;
            next=next->next;
            id++;
        }
        if(places.size()<2)return nullcase;
        int maxima=places[places.size()-1]-places[0];
        int minima=INT_MAX;
        for(int i=1;i<places.size();i++){
            minima=min(minima,places[i]-places[i-1]);
        }
        return {minima,maxima};
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_map>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        unordered_map<int,int> dp;
        ListNode* temp=head;
        vector<ListNode*> save;
        while(temp!=NULL){
            dp[temp->val]++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            if(dp[temp->val]==1) save.push_back(temp);
            temp=temp->next;
        }
        if(save.size()==0) return NULL;
        for(int i=0;i<save.size()-1;i++) save[i]->next=save[i+1];
        save[save.size()-1]->next=NULL;
        return save[0];
    }
};

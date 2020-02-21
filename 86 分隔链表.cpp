/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head) return NULL;
        vector<ListNode*> small,big;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val<x) small.push_back(temp);
            else big.push_back(temp);
            temp=temp->next;
        }
        small.insert(small.end(),big.begin(),big.end());
        for(int i=0;i<small.size()-1;i++) small[i]->next=small[i+1];
        small[small.size()-1]->next=NULL;
        return small[0];
    }
};

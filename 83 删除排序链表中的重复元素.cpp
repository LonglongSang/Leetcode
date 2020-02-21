/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        vector<ListNode*> ret;
        unordered_set<int> dp;
        ListNode* temp=head;
        while(temp!=NULL){
            if(dp.find(temp->val)==dp.end()){
                ret.push_back(temp);
                dp.insert(temp->val);
            }
            temp=temp->next;
        }
        
        for(int i=0;i<ret.size()-1;i++) ret[i]->next=ret[i+1];
        ret[ret.size()-1]->next=NULL;
        return ret[0];
        
    }
};

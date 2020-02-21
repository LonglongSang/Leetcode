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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return NULL;
        vector<ListNode*> dp;
        ListNode* temp=head;
        while(temp!=NULL){
            dp.push_back(temp);
            temp=temp->next;
        }
        for(int i=0;i<dp.size();i+=2){
            if(i+1==dp.size()) break;
            temp=dp[i];
            dp[i]=dp[i+1];
            dp[i+1]=temp;
        }
        for(int i=0;i<dp.size()-1;i++) dp[i]->next=dp[i+1];
        dp[dp.size()-1]->next=NULL;
        return dp[0];
    }
};

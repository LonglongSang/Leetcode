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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> dp;
        ListNode* temp=head;
        while(temp!=NULL){
            dp.push_back(temp);
            temp=temp->next;
        }
        if(n==1 && dp.size()==1){
            return NULL;
        }else if(n==dp.size()){
            return dp[1];
        }else{
            dp[dp.size()-n-1]->next=dp[dp.size()-n]->next;
            return dp[0];
        }
        return NULL;
    }
};

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
    ListNode* rotateRight(ListNode* head, int k) {
        vector<ListNode*> dp;
        ListNode* temp=head;
        while(temp!=NULL){
            dp.push_back(temp);
            temp=temp->next;
        }
        if(k==0 || dp.size()==0 || k%dp.size()==0) return head;
        k=k%dp.size();
        reverse(dp.end()-k,dp.end());
        reverse(dp.begin(),dp.end()-k);
        reverse(dp.begin(),dp.end());
        for(int i=0;i<dp.size()-1;i++) dp[i]->next=dp[i+1];
        dp[dp.size()-1]->next=NULL;
        return dp[0];
    }
};

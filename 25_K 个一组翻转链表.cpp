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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return NULL;
        if(k==1) return head;
        vector<ListNode*> dp;
        ListNode* temp=head;
        while(temp!=NULL){
            dp.push_back(temp);
            temp=temp->next;
        }
        int count=dp.size()/k;
        cout<<count<<endl;
        for(int i=0;i<count;i++){
            reverse(dp.begin()+i*k,dp.begin()+k*(i+1));
        }
        for(int i=0;i<dp.size()-1;i++) dp[i]->next=dp[i+1];
        dp[dp.size()-1]->next=NULL;
        return dp[0];
    }
};

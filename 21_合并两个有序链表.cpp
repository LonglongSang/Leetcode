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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        vector<ListNode*> dp;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL && l2!=NULL){
                if(l1->val<l2->val){
                    dp.push_back(l1);
                    l1=l1->next;                    
                }else{
                    dp.push_back(l2);
                    l2=l2->next;                     
                }
            }else if(l1!=NULL){
                dp.push_back(l1);
                l1=l1->next;
            }else if(l2!=NULL){
                dp.push_back(l2);
                l2=l2->next;
            }
        }
        if(dp.size()==0) return NULL;
        for(int i=0;i<dp.size()-1;i++) dp[i]->next=dp[i+1];
        dp[dp.size()-1]->next=NULL;
        return dp[0];
    }
};

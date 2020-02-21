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
    static bool cmp(ListNode* &a,ListNode* &b){
        return a->val<b->val;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> dp(20000);
        int count=0;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=NULL;
            if(lists[i]!=NULL) temp=lists[i];
            while(temp!=NULL){
                dp[count++]=temp;
                temp=temp->next;
            }
        }
        if(count==0) return NULL;
        sort(dp.begin(),dp.begin()+count,cmp);
        for(int i=0;i<count-1;i++) dp[i]->next=dp[i+1];
        dp[count-1]->next=NULL;
        return dp[0];
        
    }
};

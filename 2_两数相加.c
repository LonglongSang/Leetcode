/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* add;
    struct ListNode* temp=NULL;
    if(l1==NULL && l2==NULL)
        return temp;
    temp=(struct ListNode*)malloc(sizeof(struct ListNode));
    temp->next=NULL;
    add=temp;
    int count=0;
    struct ListNode* pre1=l1;
    struct ListNode* pre2=l2;
    while(pre1 != NULL || pre2 !=NULL || count==1){
        int a=0;
        int b=0;
        if(pre1 != NULL)
            a=pre1->val;
        if(pre2 !=NULL)
            b=pre2->val;
        int now_add=a+b;
        temp->next=(struct ListNode*)malloc(sizeof(struct ListNode));
        temp=temp->next;
        if(count+now_add-10>=0){  
            temp->val=count+now_add-10;
            count=1;
            printf("%d",temp->val);
        }else{
            temp->val=now_add+count;
            count=0;
            printf("%d",temp->val);
        }
        if(pre1 !=NULL)
            pre1=pre1->next;
        else
            pre1=NULL;
        if(pre2!=NULL)
            pre2=pre2->next;
        else
            pre2=NULL;
    } 
    temp->next=NULL;
    add=add->next;
    return add;
}

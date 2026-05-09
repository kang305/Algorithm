#include<bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    struct ListNode *next;
};
ListNode* trainingPlan(ListNode* head, int cnt)
{
    ListNode* fast=head;
    ListNode* slow=head;
    int tmp=1;//计数
    while (fast!=NULL&&tmp<=cnt) {//让fast指针先走cnt步
        fast=fast->next;
        tmp++;
    }
    while(fast!=NULL) {//当fast指向NULL时,slow指向倒数第cnt个
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}
int main()
{
    int n,x,cnt;
    scanf("%d %d",&n,&cnt);
    ListNode* l=NULL;
    ListNode* r=NULL;
    for(int i=1;i<=n;i++)
    {//尾插法建立一个不带头结点的单链表
        cin>>x;
        ListNode* s=(ListNode*)malloc(sizeof(ListNode));
        s->val=x;
        s->next=NULL;
        if(i==1)
        {
            l=s;
            r=s;
            continue;
        }
        //尾插
        r->next=s;
        r=s;
    }
    ListNode* ans=trainingPlan(l,cnt);
    cout<<ans->val<<endl;
    return 0;
}
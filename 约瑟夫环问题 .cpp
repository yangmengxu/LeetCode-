class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int state[n];
        int cnt,cur=0;
        fill(state,state+n,0);
        for(int i=0;i<n-1;++i)
        {
            cnt=1;
            while(cnt<=m)
            {
                if(!(i==0&&cnt==1))
                {
                    while(state[(cur+1)%n]!=0)
                    cur=(cur+1)%n;
                   cur=(cur+1)%n;
                }
                ++cnt;
            }
            state[cur]=1;
        }
        for(int i=0;i<n;++i)
            if(state[i]!=1) return i;
        return -1;
    }
};


//貌似标准解法是循环链表
class Solution {
public:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int v):val(v),next(NULL){};
    };
    int EndChild(ListNode *Head,int out)
    {
        int cnt;
        ListNode *p=Head,*q=Head;
        while(p->next!=p){
            for(int i=0;i<out-1;++i){
                q=p;
                p=p->next;
            }
            q->next=p->next;
            delete p;
            p=q->next;
        }
        return p->val;
    }
    int LastRemaining_Solution(int n, int m)
    {
        if(!n||!m) return -1;
        ListNode *head=new ListNode(0);
        ListNode *p=head;
        for(int i=1;i<n;++i)
        {
            ListNode *q=new ListNode(i);
            p->next=q;
            p=q;
        }
        p->next=head;
        return EndChild(head,m);
    }
};

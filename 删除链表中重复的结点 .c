//Solution 1 递归方法
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead||!pHead->next) return pHead;
          ListNode *p=new ListNode(-1);
           p->next=pHead;
        if(pHead->val!=pHead->next->val){
            pHead->next=deleteDuplication(pHead->next);
            delete p;
            return pHead;
        }
        else{
            int value=pHead->val;
            ListNode *q=pHead;
            while(q!=NULL&&q->val==value){
                p->next=q->next;
                delete q;
                q=p->next;
            }
            if(!q) return p->next;
            else{
                p->next=deleteDuplication(p->next);
                return p->next;
            }
        }
    }
};


//非递归方法
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
         if(pHead==nullptr) return nullptr;
        if(pHead!=nullptr&&pHead->next==nullptr) return pHead;
        ListNode *pre=new ListNode(pHead->val);
        bool isComm=false;
        pre->next=pHead;
        ListNode *p,*q,*pfront;
        pfront=pre;
        p=pfront->next;
        while(p!=nullptr&&p->next!=nullptr)
        {
            q=p->next;
            while(q!=nullptr&&p->val==q->val)
            {
                isComm=true;
                p->next=q->next;
                delete q;
                q=p->next;
            }
            if(isComm)
            {
                pfront->next=p->next;
                delete p;
                p=q;
                isComm=false;
            }
            else
            {
                pfront=pfront->next;
                p=p->next;
            }
        }
        return pre->next;
    }
};

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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
          if(pHead==NULL||pHead->next==NULL) return NULL;
        ListNode *p,*q;
        p=q=pHead;
        while(p!=NULL&&p->next!=NULL){
            p=p->next;
            q=q->next->next;
            if(p==q)
                break;
        }
        if(p==NULL) return NULL;
        q=pHead;
        while(q!=p){
            q=q->next;
            p=p->next;
        }
        return p;
    }
};

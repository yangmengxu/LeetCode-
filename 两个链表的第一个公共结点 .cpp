//做这一题要记住，链表有公共节点，就说明从公共节点之后两个链表重叠

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
//Solution 1
/*
        假定 List1长度: a+n  List2 长度:b+n, 且 a<b
        那么 p1 会先到链表尾部, 这时p2 走到 a+n位置,将p1换成List2头部
        接着p2 再走b+n-(n+a) =b-a 步到链表尾部,这时p1也走到List2的b-a位置，还差a步就到可能的第一个公共节点。
        将p2 换成 List1头部，p2走a步也到可能的第一个公共节点。如果恰好p1==p2,那么p1就是第一个公共节点。  或者p1和p2一起走n步到达列表尾部，二者没有公共节点，退出循环。 同理a>=b.
        时间复杂度O(n+a+b)
         
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1||!pHead2) return NULL;
        ListNode *p,*q;
        p=pHead1,q=pHead2;
        while(p!=q)
        {
            if(p!=NULL) p=p->next;
            if(q!=NULL) q=q->next;
            if(p!=q){
                if(!p) p=pHead2;
                if(!q) q=pHead1;
            }
        }
        return p;
    }
};


//Solution 2
/*
这种方法利用红黑树来存储链表每个节点的地址值
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(!pHead1||!pHead2) return NULL;
        map<ListNode*,int>mp;
        ListNode *p=pHead1;
        ListNode *q=pHead2;
        while(p!=NULL){
            mp[p]=1;
            p=p->next;
        }
        while(q!=NULL){
            if(mp[q]) return q;
            q=q->next;
        }
        return NULL;
    }
};

//Solution 3
/*
这种方法利用链表之间的长度差，然后将长度长的链表移动到和短的链表一样的长度，再同步移动
*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr||pHead2==nullptr)
            return nullptr;
        int pcnt1=getLengthOfList(pHead1);
        int pcnt2=getLengthOfList(pHead2);
        ListNode *newpHead1,*newpHead2;
        if(pcnt1>=pcnt2)
        {
            int diff=pcnt1-pcnt2;
            newpHead1=WalkList(pHead1,diff);
            newpHead2=pHead2;
        }
        else{
            int diff=pcnt2-pcnt1;
            newpHead2=WalkList(pHead2,diff);
            newpHead1=pHead1;
        }
        while(newpHead1!=nullptr)
        {
            if(newpHead1==newpHead2) return newpHead1;
            newpHead1=newpHead1->next;
            newpHead2=newpHead2->next;
        }
        return nullptr;
    }
private:
    int getLengthOfList(ListNode *obj)
    {
        if(obj==nullptr)
            return 0;
        int cnt=1;
        while(obj->next!=nullptr)
        {
            ++cnt;
            obj=obj->next;
        }
        return cnt;
    }
    ListNode* WalkList(ListNode* p1,int n)
    {
        if(n<=0)
            return p1;
        while(n)
        {
            p1=p1->next;
            --n;
        }
        return p1;
    }
};

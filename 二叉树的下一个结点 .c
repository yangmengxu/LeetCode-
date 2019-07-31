//递归方法
class Solution {
public:
    void inorder(TreeLinkNode *root,TreeLinkNode *obj,vector<TreeLinkNode *>&ans,bool &flag){
        if(root!=NULL){
            inorder(root->left,obj,ans,flag);
            if(flag) {
                ans.push_back(root);
                return ;
            }
            if(root==obj) flag=true;
            inorder(root->right,obj,ans,flag);
        }
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL) return NULL;
        TreeLinkNode *pp=pNode;
        while(pp->next!=NULL) pp=pp->next;
        vector<TreeLinkNode *>res;
        bool flag=false;
        inorder(pp,pNode,res,flag);
        return res.size()>0?res[0]:NULL;
    }
};


//非递归方法
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
         
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr) return nullptr;
        if(pNode->right!=nullptr)
        {
            TreeLinkNode *temp=pNode->right;
            while(temp->left!=nullptr)
                temp=temp->left;
            return temp;
        }
        while(pNode->next!=nullptr)
        {
            TreeLinkNode *temp=pNode->next;
            if(temp->left==pNode)
                return temp;
            pNode=pNode->next;
        }
        return nullptr;
    }
};

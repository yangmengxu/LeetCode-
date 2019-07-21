class Solution {
public:
    int Depth(TreeNode *ptr)
    {
        if(ptr==NULL) return 0;
        int l=Depth(ptr->left);
        int r=Depth(ptr->right);
        if(l==-1||r==-1||abs(l-r)>1)
            return -1;
        return max(l,r)+1;
    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return Depth(pRoot)!=-1;
    }
};

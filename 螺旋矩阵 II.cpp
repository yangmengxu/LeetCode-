class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n));
        if(n<=0) return ans;
        int up=0,down=n-1,left=0,right=n-1;
        int value=1;
        while(up<=down&&left<=right)
        {
            for(int i=left;i<=right;++i)
                ans[up][i]=(value++);
            for(int i=up+1;i<=down;++i)
                ans[i][right]=(value++);
            if(up!=down)
                for(int i=right-1;i>=left;--i)
                    ans[down][i]=(value++);
            if(left!=right)
                for(int i=down-1;i>=up+1;--i)
                    ans[i][left]=(value++);
            ++up,--down,++left,--right;
        }
        return ans;
    }
};

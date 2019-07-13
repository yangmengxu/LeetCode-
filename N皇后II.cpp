class Solution {
public:
    void IsOk(int row,int col,vector<vector<int> >&flag,int &n)
    {
        for(int i=0;i<n;++i)
        {
            if(flag[row][i]!=1) flag[row][i]=1;
            if(flag[i][col]!=1) flag[i][col]=1;
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(j==i-row+col||j==-i+row+col)
                    flag[i][j]=1;
    }
   void dfs(vector<vector<int> >flag,int &cnt,int depth,int &n)
    {
        if(depth==n){
            ++cnt;
            return ;
        } 
        for(int i=0;i<n;++i)
        {
            if(flag[depth][i]) continue;
            vector<vector<int> >temp=flag;
            IsOk(depth,i,flag,n);
            dfs(flag,cnt,depth+1,n);
            flag=temp;
        }
        return ;
    }
    int totalNQueens(int n) {
        if(n<=0) return 0;
        int res=0;
        vector<vector<int> >state(n,vector<int>(n));
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                state[i][j]=0;
        dfs(state,res,0,n);
        return res;
    }
};

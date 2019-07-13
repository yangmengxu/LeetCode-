#include <iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string> >res;
    void IsOk(int &row,int &col,int n,vector<vector<int> >&loca)
    {
        for(int i=0;i<n;++i){
            if(!loca[row][i]) loca[row][i]=1;
            if(!loca[i][col]) loca[i][col]=1;
        }
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(j==i-row+col||j==-i+row+col)
                    loca[i][j]=1;
    }
    void dfs(vector<string>ans,int depth,vector<vector<int> >flag)
    {
        if(depth==ans.size()) {
            res.push_back(ans);
            return ;
        }
        for(int i=0;i<ans.size();++i)
        {
            if(flag[depth][i]) continue;
            vector<vector<int> >temp=flag;
            ans[depth][i]='Q';
            IsOk(depth,i,ans.size(),flag);
            dfs(ans,depth+1,flag);
            flag=temp;
            ans[depth][i]='.';
        }
        return ;
    }
    void solveNQueens(int n) {
        if(n<=0) return ;
        vector<string>ans(n);
        vector<vector<int> >location(n,vector<int>(n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                ans[i]+='.';
                location[i][j]=0;
            }
        }
        dfs(ans,0,location);
        return ;
    }

int main()
{
    int n;
    cin>>n;
    solveNQueens(n);
    for(int i=0;i<res.size();++i){
            cout<<"第"<<i<<"种解法：\n";
        for(int j=0;j<res[i].size();++j)
        cout<<res[i][j]<<endl;
        cout<<endl;
    }
    return 0;
}

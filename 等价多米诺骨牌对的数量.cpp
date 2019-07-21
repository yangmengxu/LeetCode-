class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int row=dominoes.size();
        int dp[10][10]={0};
        for(int i=0;i<row;++i){
            if(dominoes[i][0]>dominoes[i][1])
                ++dp[dominoes[i][1]][dominoes[i][0]];
            else
                ++dp[dominoes[i][0]][dominoes[i][1]];
        }
        int res=0;
        for(int i=0;i<10;++i)
            for(int j=i;j<10;++j)
            {
                if(dp[i][j]>1)
                    res+=(dp[i][j]*(dp[i][j]-1))/2;
            }
        return res;
    }
};

#include <iostream>
#include<vector>
#include<string>
#include<utility>
#include<queue>
using namespace std;
int offset[4][2]={1,0,0,1,-1,0,0,-1};
int visited[502][502]={0};
int MinStep=0x0fffff;
void bfs(vector<string>&str,int x,int y){
    visited[x][y]=1;
    MinStep=0;
    queue<pair<int,int> >q;
    q.push(pair<int,int>(x,y));
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;++i){
            pair<int,int>f=q.front();
            q.pop();
            for(int j=0;j<4;++j){
                int dx=f.first+offset[j][0];
                int dy=f.second+offset[j][1];
                if(dx>=str.size()||dx<0||dy>=str[0].size()||dy<0||
                   visited[dx][dy]||str[dx][dy]=='#')
                    continue;
                if(str[dx][dy]=='E'){
                    ++MinStep;
                    return ;
                }
                else{
                    visited[dx][dy]=1;
                    q.push(pair<int,int>(dx,dy));
                }
            }
        }
        ++MinStep;
    }
    MinStep=-1;
    return ;
}
int main()
{
    int n;
    cin>>n;
    vector<string>arr(n);
    for(int i=0;i<n;++i)
        cin>>arr[i];
    int ix,iy;
    for(int i=0;i<n;++i)
    for(int j=0;j<arr[0].size();++j){
        if(arr[i][j]=='S'){
            ix=i;
            iy=j;
            break;
        }
    }
    bfs(arr,ix,iy);
    cout<<MinStep<<endl;
    return 0;
}

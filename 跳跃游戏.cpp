//解题思路就是先求出flag[nums.size()-2]处能不能跳跃到终点，然后再求cur=nums.size()-3,...,0处能不能跳跃成功
//最终返回flag[0],其中用容器保存每一步的值，优化时间
class Solution {
public:
    void PartJudge(vector<int>&nums,int cur,vector<int>&flag)
    {
        if(flag[cur]!=-1) return ;
        if(nums[cur]==0) {flag[cur]=0;return ;}
        for(int i=1;i<=nums[cur];++i)
            if(flag[cur+i]) {flag[cur]=1;return ;}
        flag[cur]=0;
        return ;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size()<=0) return false;
        vector<int>IsOk(nums.size());
        fill(IsOk.begin(),IsOk.end(),-1);
        IsOk[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;--i)
           PartJudge(nums,i,IsOk);
        return (bool)IsOk[0];
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Size=nums.size();
        if(Size<=0) return 0;
        int res=INT_MIN;
        int cur=0;
        for(int i=0;i<Size;++i)
        {
            if(cur<0)
                cur=nums[i];
            else{
                cur+=nums[i];
            }
            res=max(res,cur);
        }
        return res;
    }
};

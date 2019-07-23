//a + b + c = 0 -> 固定 nums[i] = fix，找 nums[i] + nums[r] = -fix
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >res;
        sort(nums.begin(),nums.end());
        if(nums.size()<3||nums.front()>0||nums.back()<0) return res;
        for(int i=0;i<nums.size();++i){
            int fix=nums[i];
            if(fix>0) break;
            if(i>0&&nums[i]==nums[i-1]) continue;
            //对撞指针
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==-fix){
                    if(l==i+1||r==nums.size()-1){
                        vector<int>temp(3);
                        temp[0]=nums[i];
                        temp[1]=nums[l];
                        temp[2]=nums[r];
                        res.push_back(temp);
                        ++l,--r;
                    }
                    else if(nums[l]==nums[l-1])
                        ++l;
                    else if(nums[r]==nums[r+1])
                        --r;
                    else{
                        res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                        ++l,--r;
                    }
                }
                else if(nums[l]+nums[r]>-fix)
                    --r;
                else if(nums[l]+nums[r]<-fix)
                    ++l;
            }
        }
        return res;
    }
};

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
         if(index<7) return index;
         vector<int>res(index);
         res[0]=1;
         int cnt2=0,cnt3=0,cnt5=0;
         for(int i=1;i<index;++i)
         {
             res[i]=min(res[cnt2]*2,min(res[cnt3]*3,res[cnt5]*5));
             if(res[i]==res[cnt2]*2) ++cnt2;
             if(res[i]==res[cnt3]*3) ++cnt3;
             if(res[i]==res[cnt5]*5) ++cnt5;
         }
         return res[index-1];
    }
};

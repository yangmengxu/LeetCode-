/*
找到的第一组（相差最大的）就是乘积最小的。可以这样证明：考虑x+y=C（C是常数），x*y的大小。不妨设y>=x，y-x=d>=0，
即y=x+d, 2x+d=C, x=(C-d)/2, x*y=x(x+d)=(C-d)(C+d)/4=(C^2-d^2)/4，也就是x*y是一个关于变量d的二次函数，
对称轴是y轴，开口向下。d是>=0的，d越大, x*y也就越小。
*/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>res;
        int i=0,j=array.size()-1;
        while(i<j)
        {
            if(array[i]+array[j]==sum)
            {
                res.push_back(array[i]);
                res.push_back(array[j]);
                return res;
            }
            while(i<j&&array[i]+array[j]>sum) --j;
            while(i<j&&array[i]+array[j]<sum) ++i;
        }
        return res;
    }
};

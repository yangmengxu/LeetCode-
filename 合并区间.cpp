class Solution {
public:
    static bool cmp(const vector<int>&v1,const vector<int>&v2)
    {
        return v1[0]<v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          vector<vector<int>>res;
          if(intervals.size()<=0) return res;
        sort(intervals.begin(),intervals.end(),cmp);
          vector<int>SubInt;
        int Max=INT_MIN;
        for(int i=0;i<intervals.size();++i)
        {
            SubInt.push_back(intervals[i][0]);
            if(i<intervals.size()-1&&intervals[i][1]>=intervals[i+1][0])
            {
                Max=intervals[i][1];
                while(i<intervals.size()-1&&Max>=intervals[i+1][0])
                {Max=max(Max,intervals[i+1][1]);++i;}
                SubInt.push_back(Max);
                res.push_back(SubInt);
                SubInt.clear();
            }
            else
            {
                SubInt.push_back(intervals[i][1]);
                res.push_back(SubInt);
                SubInt.clear();
            }
        }
        return res;
    }
};

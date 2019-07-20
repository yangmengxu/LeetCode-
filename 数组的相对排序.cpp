class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>res;
        vector<int>front,back;
        map<int,int>mp;
        for(int i=0;i<arr2.size();++i)
            mp[arr2[i]]=i;
        bool flag=false;
        for(int i=0;i<arr1.size();++i){
            for(int j=0;j<arr2.size();++j)
            {
                if(arr1[i]==arr2[j]){
                    front.push_back(arr1[i]);
                    flag=true;
                    break;
                }
            }
            if(!flag) back.push_back(arr1[i]);
            else flag=false;
        }
        sort(back.begin(),back.end());
        for(int i=1;i<front.size();++i){
            int Cur=front[i];
            int j=i-1;
            while(j>=0&&mp[Cur]<mp[front[j]]){
                front[j+1]=front[j];
                --j;
            }
            front[j+1]=Cur;
        }
        for(int k=0;k<arr1.size();++k)
        {
            if(k<front.size()) res.push_back(front[k]);
            else res.push_back(back[k-front.size()]);
        }
        return res;
    }
};

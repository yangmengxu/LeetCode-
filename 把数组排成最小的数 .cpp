class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(),numbers.end(),cmp);
        string res="";
        for(int i=0;i<numbers.size();++i)
            res+=to_string(numbers[i]);
        return res;
    }
private:
    static bool cmp(const int &a,const int &b)
    {
        string strA=to_string(a)+to_string(b);
        string strB=to_string(b)+to_string(a);
        return strA<strB;
    }
};

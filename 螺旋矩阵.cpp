class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if(matrix.size()<=0||matrix[0].size()<=0) return ans;
        int up=0,down=matrix.size()-1,left=0,right=matrix[0].size()-1;
        while(up<=down&&left<=right)
        {
               for(int i=left;i<=right;++i)
                        ans.push_back(matrix[up][i]);
               for(int i=up+1;i<=down;++i)
                        ans.push_back(matrix[i][right]);
               if(up!=down)//防止同一行上面来回遍历
               for(int i=right-1;i>=left;--i)
                        ans.push_back(matrix[down][i]);
               if(left!=right)//防止同一列上来回遍历
               for(int i=down-1;i>=up+1;--i)
                        ans.push_back(matrix[i][left]);
               ++left,++up,--down,--right;
        }
        return ans;
    }
};


//超时版本
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int up=0,down=matrix.size()-1,left=0,right=matrix[0].size()-1;
        int flag=0;//0代表最上面，1代表最右面，2代表最下面，3代表最左面
        while(!(up==down&&left==right))
        {
            if(flag==0){
                for(int i=left;i<=right;++i)
                        ans.push_back(matrix[up][i]);
                    ++up;
            }
            if(flag==1){
                    for(int i=up;i<=down;++i)
                        ans.push_back(matrix[i][right]);
                    --right;
            }
            if(flag==2){
                    for(int i=right;i>=left;--i)
                        ans.push_back(matrix[down][i]);
                    --down;
            }
            if(flag==3){
                    for(int i=down;i>=up;--i)
                        ans.push_back(matrix[i][left]);
                    ++left;
            }
            flag=(flag+1)%4;
        }
        ans.push_back(matrix[up][left]);
        return ans;
    }
};

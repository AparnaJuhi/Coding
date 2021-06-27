class Solution {
public:
    int candy(vector<int>& r) {
        //intialise all candies to 0
        int sum=0;
        vector<int>v;
        for(int i=0;i<r.size();i++)
        {
            v.push_back(1);
        }
        for(int i=1;i<r.size();i++)
        {
            if(r[i]>r[i-1])
            {
                v[i]=v[i-1]+1;
            }
        }
         for(int i=r.size()-2;i>=0;i--)
        {
            if(r[i]>r[i+1] && v[i]<=v[i+1])
            {
                 v[i]=v[i+1]+1;
            }
        }
        for(int i=0;i<r.size();i++)
            sum+=v[i];
        return sum;
        
    }
};

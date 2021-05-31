class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
         vector<vector<string>> ans;
        string key="";
        sort(products.begin(),products.end());
        int m=products.size();
        int n=searchWord.size();
        for(int i=0;i<n;i++)
        {
            key+=searchWord[i];
             //now search key in provided vector
            int count=0;
            vector<string>temp;
            for(int j=0;j<m;j++)
            {
                string r = products[j].substr(0,i+1);
                if(r==key)
                {
                    count++;
                    temp.push_back(products[j]);
                }
                if(count==3)
                    break;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

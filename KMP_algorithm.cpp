vector <int> search(string pat, string txt)
        {
            //constructing lps array
            int lps[pat.size()];
            int i=1;
            int len=0;
            lps[0]=0;//lps[0] is always 0
            while(i<pat.size())
            {
                if(pat[len]==pat[i])
                {
                    len++;
                    lps[i]=len;i++;
                }
                else
                {
                    //if dont match but nth to compare
                    if(len==0)
                    {
                        lps[i]=0;
                        i++;
                        
                    }
                    
                    else
                    {
                        len=lps[len-1];
                    }
                }
            }
            
            vector<int>ans;
            //now lps array is made, start pattern matching
            
            //iterating on the string
            i=0;
            int j=0;
            while(i<txt.size())
            {
                if(txt[i]==pat[j])
                {
                    i++;j++;
                }
                else
                {
                    
                    if(j==0)
                    i++;
                    else
                    j=lps[j-1];
                    
                
                }
                if(j==pat.size())
                {
                    ans.push_back((i-j)+1);
                    j=lps[j-1];
                }
                
                
            }
            if(ans.size()==0)
            {
                ans.push_back(-1);return ans;
            }
            return ans;
            
        }

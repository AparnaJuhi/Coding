int findNext (int N) 
    {
        int flag=0;
        string s=to_string(N);
        int len=s.size();
        int a[len];
        for(int i=0;i<len;i++)
        {
            a[i]=(s[i]-'0');
        }
        int i;
        for(i=len-2;i>=0;i--)
        {
            if(a[i]<a[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        return -1;
        //if possible, find just greater element after i
        
        int mini_greater=a[i+1];
        int idx=i+1;
        for(int j=i+2;j<len;j++)
        {
            if(a[j] > a[i] && a[j]<mini_greater)
            {mini_greater=a[j];idx=j;}
        }
        swap(a[idx],a[i]);
        //now sort the array after i to last
        sort(a+i+1, a+len);
        int ans=0;
        for(i=0;i<len;i++)
        {
            ans=ans*10+a[i];
        }
        return ans;
        
        
    }  

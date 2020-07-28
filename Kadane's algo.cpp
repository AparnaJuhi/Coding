#include <iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int a[n];
        int countofNegative=0;
        int leastNegative=-9999999;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]<0)
            {countofNegative++;
            if(a[i]>leastNegative)
            leastNegative=a[i];}
            
        }
        if(countofNegative==n)
        {
            cout<<leastNegative<<"\n";
        }
        else
        {
            int max_so_far=0,max_end_here=0;
            for(int i=0;i<n;i++)
            {
                max_end_here=max_end_here+a[i];
                if(max_so_far<max_end_here)
                max_so_far=max_end_here;
                if(max_end_here<0)
                max_end_here=0;
            }
            cout<<max_so_far<<"\n";
        }
    }
}

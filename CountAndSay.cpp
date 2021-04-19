#include <bits/stdc++.h>
using namespace std;
string countAndSay(int n) {
        string finalString="";
        finalString+="1";
        if(n==1)
            return finalString;
        else
        {
            int characterPtr=0;
            int countPtr=0;
            string progress="";
            while(n>1)
            {
                 n--;
                while(countPtr<finalString.size())
                {
                    while(finalString[countPtr]==finalString[characterPtr])
                        countPtr++;
                    //now adding the sum
                progress+=std::to_string(countPtr-characterPtr);
                progress+=finalString[characterPtr];
                    characterPtr=countPtr;
                }
                finalString=progress;
               
                characterPtr=0;
                countPtr=0;
                finalString=progress;
                progress="";
            }
            return finalString;
        }
    }

int main()
{
	int n;
	cin>>n;
	cout<<countAndSay(n);
}

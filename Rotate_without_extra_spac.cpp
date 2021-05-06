#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>& nums, int k) {
    int n=nums.size();
   k=k%n;
    //reverse the whole array
 
    reverse(nums.begin(),nums.end());
       // and then again reverse the elements from start to k. 
    reverse(nums.begin(),nums.begin()+k);
    // and then again reverse the elements from k to n. (from k to end of the array)
    reverse(nums.begin()+k,nums.end());
    
}

int main()
{
	int n,input;
	cin>>n;
	vector<int>nums;
	for(int i=0;i<n;i++)
	{
		cin>>input;
		nums.push_back(input);
	}
	int k;
	cin>>k;
	rotate(nums,k);
	for(int i=0;i<n;i++)
	cout<<nums[i]<<" ";
}

public:
int minDifference(int arr[], int n)  { 
int sum=0,p;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
       p=sum;
        sum=sum/2;
        int mat[sum+1][n+1];
        //make a matrix of sumxn
        for(int i=1;i<=sum;i++)
        {
            mat[i][0]=0;
        }
        for(int j=0;j<=n;j++)
        mat[0][j]=1;
        for(int i=1;i<=sum;i++)
        {
            for(int j=1;j<=n;j++)
            {
                mat[i][j]=mat[i][j-1];
                if(i>=arr[j-1])
                {
                    //if sum greater than number
                      mat[i][j]=(mat[i][j] || mat[i-arr[j-1]][j-1]);
                    
                }
            }
        }
        while(mat[sum][n]!=1)
        {
            sum--;
        }
        return abs(sum-(p-sum));
	} 
};

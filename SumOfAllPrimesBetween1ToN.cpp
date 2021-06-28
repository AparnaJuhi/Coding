long long int prime_Sum(int n){
   	    long long int sum=0;
   	    bool prime[n+1];
   	    for(int i=0;i<=n;i++)
   	    prime[i]=true;
   	     //check prime
   	    for(int i=2;i*i<=n;i++)
   	    {
   	       
   	        if(prime[i])
   	        for(int j=2*i;j<=n;j+=i)
   	        {
   	            prime[j]=false;
   	        }
   	    }
   	    for(int i=2;i<=n;i++)
   	    {
   	        if(prime[i]==true)
   	        {
   	            sum+=i;
   	        }
   	    }
   	    return sum;
   	    
   	}    

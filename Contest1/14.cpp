#include<iostream>
using namespace std;

long long tk(long long a[],long long b[],long long k)
{
	long long count = 0,j=0;
	for(long long i = 0 ; i < k ; i++)
	{
		for(j = 0 ; j < k ; j++)
			if(a[i] == b[j]) break;	
		if(j == k) count++;
	}
	return count;
}

main()
{
	long long T,n,k;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		long long a[k],b[k],i;
		for(i = 0 ; i < k ; i++)
		{
			cin>>a[i];
			b[i] = a[i];
		}
		for(i = k-1 ; i >= 0 ; i--)
			if(b[i] != n-k+i+1)
			{
				b[i] += 1;
				break;	
			}	
		if(i < 0) cout<<k<<endl;
		else
		{
			for(long long j = i+1 ; j < k ; j++)
				b[j] = b[i] + j-i;
			
			cout<<tk(a,b,k)<<endl;			
		}	
	}
}

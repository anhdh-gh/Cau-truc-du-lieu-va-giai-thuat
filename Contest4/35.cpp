#include<bits/stdc++.h>
using namespace std;
main()
{
	long long T,n,max,sum;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		max = -1e9;
		for(long long i = 0 ; i < n ; i++)
		{
			sum = 0;
			for(long long j = i ; j < n ; j++)
			{
				sum += a[j];
				if(max < sum) max = sum;				
			}
		}
		cout<<max<<endl;
	}
}

// Cach lam chia va tri

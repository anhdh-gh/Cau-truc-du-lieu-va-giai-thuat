#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n],min = 1e7;
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
//		sort(a,a+n);
//		if(a[0] >= 0) // Mang toan so >= 0
//			min = a[0]+a[1];
//		else if(a[n-1] <= 0) // Mang toan so <= 0
//			min = a[n-1]+a[n-2];
//		else // Mang gom cac so <= 0 va >= 0
//		{
			for(long long i = 0 ; i < n ; i++)
				for(long long j = 0 ; j < n ; j++)
					if(i != j && abs(min) > abs(a[i]+a[j])) 
						min = a[i]+a[j];				
//		}
		cout<<min<<endl;
	}
}

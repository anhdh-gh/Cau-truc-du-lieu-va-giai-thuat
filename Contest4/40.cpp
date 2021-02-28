#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n],dem = 0;
		for(long long i = 0 ; i < n ; i++)
		{
			cin>>a[i];
			if(a[i]==0) dem++;
		}
		cout<<dem<<endl;
	}
}

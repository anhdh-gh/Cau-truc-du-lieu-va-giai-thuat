#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n,x;
	cin>>T;
	while(T--)
	{
		cin>>n>>x;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		long long dem = 0;
		for(long long i = 0 ; i < n ; i++)
		{
			if(a[i]==x) dem++;
			else if(dem != 0) break;			
		}
		if(dem == 0) cout<<-1;
		else cout<<dem;
		cout<<endl;
	}
}

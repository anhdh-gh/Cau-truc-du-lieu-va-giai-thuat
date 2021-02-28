#include<bits/stdc++.h>
using namespace std;
long long a[1005],n;

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		for(long long i = n-1 ; i >= n/2 ; i--)
			if(i == n-1-i) cout<<a[i]<<" ";
			else cout<<a[i]<<" "<<a[n-1-i]<<" ";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
main()
{
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		if(n%2==0) cout<<a[n/2-1];
		else cout<<a[n/2];
		cout<<endl;
	}
}

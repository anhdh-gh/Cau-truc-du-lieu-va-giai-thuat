#include<bits/stdc++.h>
using namespace std;
long long a[1005],f[1005],n,k,m=1e9+7;
long long tinh()
{
	memset(f,0,sizeof(f));
	long long i,j;
	f[0] = 1;
	for(i = 1 ; i <= k ; i++)
		for(j = 1 ; j <= n ; j++)
			if(a[j]<=i)
				f[i] = (f[i]+f[i-a[j]])%m;
	return f[k];
}

main()
{
	long long T,i;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(i = 1 ; i <= n ; i++)
			cin>>a[i];
		cout<<tinh()<<endl;
	}
}


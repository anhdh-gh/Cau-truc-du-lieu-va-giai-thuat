#include<bits/stdc++.h>
using namespace std;
long long T,n,k,a[100000],vt;
long long tim(long long l,long long h)
{
	if(l > h) return 0;
	long long m = (l+h)/2;
	if(k == a[m]) return m;
	if(k < a[m]) return tim(l,m-1);
	return tim(m+1,h);
}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(long long i = 1 ; i <= n ; i++)
			cin>>a[i];
		vt = tim(1,n);
		if(vt!=0) cout<<vt<<endl;
		else cout<<"NO"<<endl;
	}
}

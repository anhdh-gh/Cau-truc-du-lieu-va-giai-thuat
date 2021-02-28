#include<bits/stdc++.h>
using namespace std;
long long n,a[1000],L[40005],s;
// Xem lai cong thuc trong slide. Hoc thuoc cong thuc
long long qhd()
{
	memset(L,0,sizeof(L));	// Dat lai mang L toan 0 
	L[0] = 1;
	for(long long i = 1 ; i <= n ; i++)
		for(long long j = s ; j >= a[i] ; j--)
			if(L[j]==0 && L[j-a[i]]==1)
				L[j] = 1;
	return L[s];
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n>>s;
		for(long long i = 1 ; i <= n ; i++)
			cin>>a[i];
		if(qhd()==1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

#include<bits/stdc++.h>
using namespace std;
vector<long long>a;
long long n;
long long kt()
{
	vector<long long>b(a);
	sort(b.begin(),b.end());
	for(long long i = 0 ; i < n ; i++)
		if(b[i]!=a[i] && b[i]!=a[n-1-i]) // 1 so chi co 2 vi tri neu sap xep duoc i && n-i-1
			return 0;
	return 1;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		a.resize(n);  // dat lai size
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		if(kt()==1) cout<<"Yes";
		else cout<<"No";
		cout<<endl;
	}
}

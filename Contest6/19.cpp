#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		long long a[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>a[i];
		sort(a,a+n);
		vector<long long>b;
		b.insert(b.begin(),a,a+n);
		for(long long i = 0 ; i < b.size()-1 ; i++)
			if(b[i]==b[i+1])
				b.erase(b.begin()+i--);
		cout<<(b[b.size()-1]-b[0]+1)-b.size()<<endl;
	}
}

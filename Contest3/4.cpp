#include<bits/stdc++.h>
using namespace std;

long long covert(string s)
{
	long long n = 0,coso = 1;
	for(long long i = s.size()-1 ; i >= 0 ; i--)
	{
		n += (s[i]-'0')*coso;
		coso *= 10;
	}
	return n;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n;
		long long A[n];
		for(long long i = 0 ; i < n ; i++)
			cin>>A[i];
		sort(A,A+n);
		string a,b;
		for(long long i = 0 ; i < n ; i+=2)
			a.push_back(A[i]+'0');
		for(long long i = 1 ; i < n ; i+=2)	
			b.push_back(A[i]+'0');
		long long x = covert(a);
		long long y = covert(b);
		cout<<x+y<<endl;
	}
}

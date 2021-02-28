#include<bits/stdc++.h>
using namespace std;
long long k;
long long ck10(string a)
{
	long long sum = 0,coso = 1;
	for(long long i = a.size()-1 ; i >= 0 ; i--)
	{
		sum += (a[i]-'0')*coso;
		coso *= k;
	}
	return sum;
}

void sum(long long n)
{
	stack<long long>s;
	if(n==0){cout<<0;return;}
	while(n!=0)
	{
		s.push(n%k);
		n /= k;
	}
	while(!s.empty())
	{
		long long t = s.top();
		s.pop();
		cout<<t;
	}
}

main()
{
	string a,b;
	cin>>k>>a>>b;
	sum(ck10(a)+ck10(b));
}

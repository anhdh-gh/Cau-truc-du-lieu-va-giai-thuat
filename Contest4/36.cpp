#include<bits/stdc++.h>
using namespace std;

long long c210(string a)
{
	long long sum = 0,coso = 1;
	for(long long i = a.size()-1 ; i >= 0 ; i--)
	{
		sum += (a[i]-'0')*coso;
		coso *= 2;
	}
	return sum;
}

void nhan(long long n)
{
	stack<long long>s;
	if(n==0){cout<<0;return;}
	while(n!=0)
	{
		s.push(n%2);
		n /= 2;
	}
	while(!s.empty())
	{
		long long t = s.top();
		s.pop();
		cout<<t;
	}
	cout<<endl;
}

main()
{
	long long T;
	cin>>T;
	string a,b;
	while(T--)
	{
		cin>>a>>b;
		cout<<c210(a)*c210(b)<<endl;
	}
}

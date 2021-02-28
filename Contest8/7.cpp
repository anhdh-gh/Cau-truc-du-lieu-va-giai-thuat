#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

long long process(long long n)
{
	long long temp,dem = 0;
	queue<long long>p;
	p.push(1);
	while(1)
	{
		temp = p.front();
		p.pop();
		if(temp > n) return dem;
		dem++;
		p.push(temp*10);
		p.push(temp*10+1);
	}
}

main()
{
 	faster()
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<process(n)<<endl;
	}
}

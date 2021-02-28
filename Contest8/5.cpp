#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void process(long long n)
{
	long long temp;
	queue<long long>p;
	p.push(1);
	while(n--)
	{
		temp = p.front();
		p.pop();
		cout<<temp<<" ";
		p.push(temp*10);
		p.push(temp*10+1);
	}
	cout<<endl;
}

main()
{
 	faster()
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		process(n);
	}
}

#include<bits/stdc++.h>
using namespace std;

long long cost(long long a[],long long n)
{
	priority_queue<long long,vector<long long>,greater<long long> >pq(a,a+n);
	//priority_queue<kieu du lieu,kieu thung chua,kieu so sanh> >pq;
	long long c = 0,x,y;
	while(pq.size() > 1)
	{
		x = pq.top();    // lay ten dau
		pq.pop();		 // xao tren dau
		y = pq.top();
		pq.pop();
		c += x+y;
		pq.push(x+y);
	}
	return c;
}

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
		cout<<cost(a,n)<<endl;
	}
}

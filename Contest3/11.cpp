#include<bits/stdc++.h>
using namespace std;
unsigned long long m = 1e9+7;
unsigned long long n;
unsigned long long cost(unsigned long long a[],unsigned long long n)
{
	priority_queue<unsigned long long,vector<unsigned long long>,greater<unsigned long long> >pq(a,a+n);
	//priority_queue<kieu du lieu,kieu thung chua,kieu so sanh> >pq;
	unsigned long long c = 0,x,y;
	while(pq.size() > 1)
	{
		x = pq.top();    // lay ten dau
		pq.pop();		 // xoa tren dau
		y = pq.top();
		pq.pop();
		c += (x+y)%m;
		pq.push((x+y)%m);
	}
	return c;
}

main()
{  
	cin>>n;
	unsigned long long a[n];
	for(unsigned long long i = 0 ; i < n ; i++)
		cin>>a[i];
	cout<<cost(a,n)%m<<endl;
}

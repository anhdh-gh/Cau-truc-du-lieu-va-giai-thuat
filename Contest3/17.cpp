#include<bits/stdc++.h>
using namespace std;
string a;
long long k;

long long xuly()
{
	int frequency[26] = {0}; 
	if(k > a.size()) return 0;
	priority_queue<long long>pq;
	sort(a.begin(),a.end());
	long long dem = 1;
	a += "|";
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i]==a[i+1]) dem++;
		else {pq.push(dem);dem=1;}
	while(k--)
	{
		long long temp = pq.top();
		pq.pop();
		temp -= 1;
		pq.push(temp);
	}
	long long kq = 0;
	while(!pq.empty())
	{
		long long temp = pq.top();
		kq += temp*temp;
		pq.pop();
	}
	return kq;
}

main()
{
	long long T;
	cin>>T;
	while(T--)
	{
		cin>>k>>a;
		cout<<xuly()<<endl;
	}
}

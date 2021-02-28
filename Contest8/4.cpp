#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void process(long long k,string a)
{
	priority_queue<long long>pq;
	sort(a.begin(),a.end());
	a += "|";
	long long dem = 1;
	for(long long i = 0 ; i < a.size()-1 ; i++)
		if(a[i] == a[i+1]) dem++;
		else{pq.push(dem);dem = 1;}
	long long temp;
	while(k--)
	{
		temp = pq.top();
		pq.pop();
		temp--;
		pq.push(temp);	
	}
	temp = 0;
	while(!pq.empty())
	{
		temp += pq.top()*pq.top();
		pq.pop();
	}
	cout<<temp<<endl;
}

main()
{
 	faster()
	long long T,k;
	string a;
	cin>>T;
	while(T--)
	{
		cin>>k>>a;
		process(k,a);
	}
}

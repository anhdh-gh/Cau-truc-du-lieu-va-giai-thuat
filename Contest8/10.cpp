#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Neu nho hon 10^6 nen su dung int thay vi long long vi no se nhanh hon
int process(int n)
{
	pair<int,int>temp,x;
	temp.first = n;
	temp.second = 0;	
	set<int>daxet;
	daxet.insert(n);
	//          value,step
	queue<pair<int,int> >q;
	q.push(temp);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		if(temp.first == 1) return temp.second;
		if(temp.first-1 == 1) return temp.second+1;
		if(daxet.find(temp.first-1)==daxet.end() && temp.first-1 > 0)
		{
			daxet.insert(temp.first-1);
			x.first = temp.first-1;
			x.second = temp.second+1;
			q.push(x);
		}
		for(int i = 2 ; i*i <= temp.first ; i++)
		{
			if(temp.first%i==0 && daxet.find(temp.first/i)==daxet.end())
			{
				daxet.insert(temp.first/i);
				x.first = temp.first/i;
				x.second = temp.second+1;
				q.push(x);				
			}
		}
	}
}

main()
{
 	faster()
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<process(n)<<endl;
	}
}

#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

struct node{
	long long value;
	long long level;
};

long long process(long long s,long long t)
{
	set<long long>visit; // Loai bo cac phan tu trung nhau
	visit.insert(s);
	queue<node>q;
	node x={s,0},temp;
	q.push(x);
	while(!q.empty())
	{
		x = q.front();
		q.pop();
		if(x.value == t) 
			return x.level;
		if(x.value*2 == t || x.value-1 == t) 
			return x.level+1;
		if(visit.find(x.value*2)==visit.end() && x.value < t)
		{
			temp.value = x.value*2;
			temp.level = x.level+1;
			q.push(temp);
			visit.insert(x.value*2);
		}
		if(visit.find(x.value-1) ==visit.end() && x.value-1 > 0)
		{
			temp.value = x.value-1;
			temp.level = x.level+1;
			q.push(temp);
			visit.insert(x.value-1);
		}
	}
}

main()
{
 	faster()
	long long T,s,t;
	cin>>T;
	while(T--)
	{
		cin>>s>>t;
		cout<<process(s,t)<<endl;
	}
}
//https://www.geeksforgeeks.org/minimum-number-operation-required-convert-number-x-y/

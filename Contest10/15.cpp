#include<bits/stdc++.h>
#define iii pair<int,pair<int,int>>
using namespace std;
int T,v,e,x,y,w,d[1005],u;
vector<iii>edge;

int check(int s)
{
	for(int i = 1 ; i <= v ; i++)
		d[i] = INT_MAX;
	d[s] = 0;
	for(int i = 2 ; i <= v ; i++)
		for(int j = 0 ; j < edge.size() ; j++)
		{
			x = edge[j].second.first;
			y = edge[j].second.second;
			w = edge[j].first;
			if(d[x]!=INT_MAX && d[y]>d[x]+w)
				d[y] = d[x]+w;
		}
	for(int i = 0 ; i < edge.size() ; i++)
	{
		x = edge[i].second.first;
		y = edge[i].second.second;
		w = edge[i].first;		
		if(d[x]!=INT_MAX&&d[y]>d[x]+w) return 1;
	}
	return 0;
}

void process(int s)
{
	if(check(s)==1)
	{
		cout<<-1<<endl;
		return;
	}
	for(int i = 1 ; i <= v ; i++)
		if(d[i]==INT_MAX) cout<<"INFI ";
		else cout<<d[i]<<" ";
	cout<<endl;
}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>v>>e>>u;
		edge.clear();
		while(e--)
		{
			cin>>x>>y>>w;
			edge.push_back({w,{x,y}});
		}
		process(u);
	}
}

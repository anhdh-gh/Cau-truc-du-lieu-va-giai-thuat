#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,v,e,x,y,w,truoc[1005],Min_w;
			//dau,cuoi,trong so
vector<pair<int,pair<int,int>>>edge;

int goc(int i)
{
	while(truoc[i]!=0) 
		i = truoc[i];
	return i;
}

void add(int a,int b)
{
	truoc[goc(a)] = b;
}

int Kruskal()
{
	// Sap xep theo trong so
	sort(edge.begin(),edge.end());
	Min_w = 0;
	for(int i = 0 ; i < edge.size() ; i++)
		if(goc(edge[i].second.first) != goc(edge[i].second.second))
		{
			add(edge[i].second.first,edge[i].second.second);
			Min_w += edge[i].first;
		}
	return Min_w;	
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		edge.clear();
		memset(truoc,0,sizeof(truoc));
		while(e--)
		{
			cin>>x>>y>>w;
			edge.push_back({w,{x,y}});
		}
		cout<<Kruskal()<<endl;
	}
}
//https://sites.google.com/site/kc97ble/algorithm-graph/kruskal-cpp

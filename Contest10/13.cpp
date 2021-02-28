#include<bits/stdc++.h>
#define iii pair<int,pair<int,int>>
using namespace std;
int T,v,e,x,y,w;
vector<iii>edge;

int check_chu_trinh_am(int s)
{
	int d[1005];
	for(int i = 1 ; i <= v ; i++)
		d[i] = INT_MAX;
	d[s] = 0;
	// Sau V-1 lan lap => Tat ca cac dinh d[i] da duoc cap nhap la co duong di nho nhat
	// Neu van con duong di nho hon => Co chu trinh am
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

int check()
{
	// Duyet cac thanh phan lien thong
	for(int i = 1 ; i <= v ; i++)
		if(check_chu_trinh_am(i)==1) return 1;
	return 0;
}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		edge.clear();
		while(e--)
		{
			cin>>x>>y>>w;
			edge.push_back({w,{x,y}});
		}
		cout<<check()<<endl;
	}
}
// Do thi co huong
//https://www.geeksforgeeks.org/detect-negative-cycle-graph-bellman-ford/

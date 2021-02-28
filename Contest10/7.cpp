#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,V,E,x,y,daxet[100005];
vector<vector<int> >ke;
vector<int>DFS;
// Cach 1: 
//string check()
//{
//	for(int i = 1 ; i <= V ; i++)
//	{
//		for(int j = 0 ; j < ke[i].size() ; j++)
//		{
//			x = ke[i][j];
//			for(int k = 0 ; k < ke[i].size() ; k++)
//				if(k != j)
//				{
//					y = ke[i][k];
//					if(find(ke[x].begin(),ke[x].end(),y)==ke[x].end()||find(ke[y].begin(),ke[y].end(),x)==ke[y].end()) 
//						return "NO";
//				}
//		}
//	}
//	return "YES";
//}

// Cach 2: 
// 1 do thi n dinh => co nhieu nhat n(n-1) canh (tinh ca canh lap)
int dfs(int s)
{
	daxet[s] = 1;
	DFS.push_back(s);
	for(int i = 0 ; i < ke[s].size() ; i++)
		if(daxet[ke[s][i]]==0)
			dfs(ke[s][i]);
}

string check()
{
	memset(daxet,0,sizeof(daxet));
	// Duyet cac thanh phan lien thong
	for(int i = 1 ; i <= V ; i++)
		if(daxet[i]==0)
		{
			DFS.clear();
			dfs(i);
			int n = DFS.size();
			int tong = 0; // so canh
			for(int j = 0 ; j < n ; j++)
				tong += ke[DFS[j]].size();
			if(tong != n*(n-1)) return "NO";
		}
	return "YES";
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>V>>E;
		ke.clear();
		ke.resize(100005);
		while(E--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout<<check()<<endl;
	}
}

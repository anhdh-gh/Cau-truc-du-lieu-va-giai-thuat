#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,v,e,u,x,y,daxet[1005];
vector<vector<int> >ke;
vector<pair<int,int> >res;

void Tree_bfs(int s)
{
	queue<int>q;
	q.push(s);
	daxet[s] = 1;
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		for(int i = 0 ; i < ke[s].size() ; i++)
			if(daxet[ke[s][i]]==0)
			{
				daxet[ke[s][i]] = 1;
				q.push(ke[s][i]);
				res.push_back({s,ke[s][i]});
			}
	}
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		ke.clear();
		ke.resize(1005);
		cin>>v>>e>>u;
		while(e--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		memset(daxet,0,sizeof(daxet));
		res.clear();
		Tree_bfs(u);
		if(res.size()==v-1)
		{
			for(int i = 0 ; i < res.size() ; i++)
				cout<<res[i].first<<" "<<res[i].second<<endl;
		}
		else cout<<-1<<endl;
	}
}

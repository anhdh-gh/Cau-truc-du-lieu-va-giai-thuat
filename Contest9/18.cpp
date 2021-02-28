#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int T,v,e,x,y,daxet[10000],s;

int bfs(vector<vector<int> >res)
{	
	for(int i = 1 ; i <= v ; i++)
	{
		memset(daxet,0,sizeof(daxet));
		vector<int>BFS;
		daxet[i] = 1;
		queue<int>q;
		q.push(i);
		BFS.push_back(i);
		while(!q.empty())
		{
			s = q.front();
			q.pop();
			for(int j = 0 ; j < res[s-1].size() ; j++)
				if(daxet[res[s-1][j]] == 0)
					{
						daxet[res[s-1][j]] = 1;
						q.push(res[s-1][j]);
						BFS.push_back(res[s-1][j]);
					}
		}
		if(BFS.size() != v) return 0;				
	}
	return 1;
}

main()
{
 	faster()
	
	cin>>T;
	while(T--)
	{
		// Input
		vector<vector<int> >res(1005);
		cin>>v>>e;
		while(e--)
		{
			cin>>x>>y;
			res[x-1].push_back(y);
		}
		// output
		//Idea: Duyet tai 1 dinh s bat ki deu co duong di toi dinh t
		// Use DFS
		if(bfs(res)==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

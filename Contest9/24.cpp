#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// Idea: Giong bai 23
int T,v,e,x,y,daxet[1005],truoc[1005];
vector<vector<int> >ke;

int bfs(int s)
{
	daxet[s] = 1;
	truoc[s] = 0;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		for(int i = 0 ; i < ke[s].size() ; i++)
		{
			x = ke[s][i];
			if(daxet[x]==0)
			{
				q.push(x);
				daxet[x] = 1;
				truoc[x] = s;
			}
			else if(truoc[s]!=x) return 1;
		}
	}
	return 0;
}

int tim_chu_trinh()
{

	for(int i = 1 ; i <= v ; i++)
	{
		memset(daxet,0,sizeof(daxet));
		memset(truoc,0,sizeof(truoc));	
		if(bfs(i)==1) return 1;			
	}
	return 0;
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		ke.clear();
		ke.resize(1005);
		while(e--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);	
		}
		if(tim_chu_trinh()==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

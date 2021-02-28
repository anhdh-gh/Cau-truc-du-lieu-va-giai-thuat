#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int T,V,E,x,y,daxet[100005];
vector<vector<int> >ke;
// Tim tren moi thanh phan lien thong ben nao nhieu dinh hon
int bfs(int s)
{
	int dem = 1;
	daxet[s] = 1;
	queue<int>q;
	q.push(s);
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		for(int i = 0 ; i < ke[s].size() ; i++)
			if(daxet[ke[s][i]]==0)
			{
				daxet[ke[s][i]] = 1;
				q.push(ke[s][i]);
				dem++;
			}
	}
	return dem;
}

int Max()
{
	int dem = 0;
	memset(daxet,0,sizeof(daxet));
	for(int i = 1 ; i <= V ; i++)
		if(daxet[i]==0)
			dem = max(dem,bfs(i));
	return dem;
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
		cout<<Max()<<endl;
	}
}

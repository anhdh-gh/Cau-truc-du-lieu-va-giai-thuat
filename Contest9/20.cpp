#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int T,v,e,x,y,daxet[1005],k;
vector<vector<int> >dsk;

void init()
{
	for(int i = 1 ; i <= v ; i++)
		daxet[i] = 0;
}

void bfs(int s)
{
	queue<int>q;
	q.push(s);
	daxet[s] = 1;
	while(!q.empty())
	{
		s = q.front();
		q.pop();
		for(int i = 0 ; i < dsk[s].size() ; i++)
			if(daxet[dsk[s].at(i)]==0)
			{
				daxet[dsk[s].at(i)] = 1;
				q.push(dsk[s].at(i));	
			} 
	}
}

int dem_stplt()
{
	int dem  = 0;
	for(int j = 1 ; j <= v ; j++)
	if(daxet[j]==0)
	{
		bfs(j);
		dem++;
	}	
	return dem;
}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		dsk.clear();
		dsk.resize(v+1);
		while(e--)
		{
			cin>>x>>y;
			dsk[x].push_back(y);
			dsk[y].push_back(x);
		}
		// Bo tung dinh roi dem so tplt
		init();
		k = dem_stplt(); // so tplt ban dau
		for(int i = 1 ; i <= v ; i++)
		{
			init();
			daxet[i] = 1;
			if(dem_stplt() > k) cout<<i<<" ";
		}
		cout<<endl;
	}
}

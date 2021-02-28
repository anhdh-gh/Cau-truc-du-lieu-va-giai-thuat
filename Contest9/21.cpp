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

void dfs(int s)
{
	daxet[s] = 1;
	for(int i = 0 ; i < dsk[s].size() ; i++)
		if(daxet[dsk[s][i]]==0 && (s != x || dsk[s][i] != y) && (s != y || dsk[s][i] != x))
			dfs(dsk[s][i]);
}

int dem_stplt()
{
	int dem  = 0;
	for(int j = 1 ; j <= v ; j++)
	if(daxet[j]==0)
	{
		dfs(j);
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
		// Bo tung canh roi dem so tplt
		x = 0;y = 0;
		init();
		k = dem_stplt(); // so tplt ban dau
		for(int i = 1 ; i <= v ; i++)
		{
			for(int j = 0 ; j < dsk[i].size() ; j++)
			{
				if(i < dsk[i][j])
				{
					init();
					x = i;
					y = dsk[i][j];
					if(dem_stplt() > k) cout<<x<<" "<<y<<" ";
				}
			}
		}
		cout<<endl;
	}
}

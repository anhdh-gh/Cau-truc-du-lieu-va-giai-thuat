#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int m,n,x,y,a[505][505],daxet[505][505],res,u,v;
int ti[]={0,0,-1,1};
int tj[]={1,-1,0,0};

void input()
{
	cin>>m>>n;
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)
			cin>>a[i][j];	
}

int process()
{
	res = -1;
	queue<pair<int,int> >q;
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)
			if(a[i][j] == 2) 
			{
				q.push({i,j});
				daxet[i][j] = 0;
			}
			else daxet[i][j];
	while(!q.empty())
	{
		x = q.front().first;
		y = q.front().second;
		q.pop();
		// lan sang 4 phia 1 o
		for(int i = 0 ; i < 4 ; i++)
		{
			u = x + ti[i],v = y + tj[i];
			if(a[u][v] == 1 && u >= 0 && v >= 0 && u < m && v < n)
			{
				a[u][v] = 2;
				daxet[u][v] = daxet[x][y] + 1;
				res = max(daxet[u][v],res);
				q.push({u,v});
			}
		}
	}
	for(int i = 0 ; i < m ; i++)
		for(int j = 0 ; j < n ; j++)	
			if(a[i][j]==1) return -1;
	return res;
}

main()
{
	faster()
	input();
	cout<<process();
}

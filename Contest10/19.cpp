#include<bits/stdc++.h>
#define iii pair<int,pair<int,int>>
using namespace std;
int T,n,m,daxet[1005][1005];
int a[1005][1005];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int is_safe(int i,int j)
{
	if(i<1||i>n||j<1||j>m||daxet[i][j]==1) return 0;
	return 1;
}

int process()
{
	priority_queue<iii,vector<iii>,greater<iii>>pq;
	pq.push({a[1][1],{1,1}});
	daxet[1][1] = 1;
	while(!pq.empty())
	{
		int w = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		for(int i = 0 ; i < 4 ; i++)
		{
			int u = x + dx[i];
			int v = y + dy[i];
			if(is_safe(u,v)==1)
			{
				// Vi cai pq luon lay cai nho nhat => Neu ma di duoc toi (i,j) thi do cx la doan duong ngan nhat tu (1,1)->(i,j)
				//=> danh dau luon (i,j) daxet
				daxet[u][v] = 1;
				if(u==n&&v==m) return w+a[u][v];
				pq.push({w+a[u][v],{u,v}});
			}
		}
	}
}

main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
			{
				cin>>a[i][j];
				daxet[i][j] = 0;
			}
		cout<<process()<<endl;
	}
}

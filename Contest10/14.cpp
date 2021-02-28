#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

// Cach nay khong biet sai o dau
//int t,v,e,u,x,y,w;
//long long a[1005][1005]; // Ma tran ke
//long long d[1005];// Do dai duong di tam thoi 
//vector<int>T; // Tap dinh co nhan tam thoi
// 
//void Dijkstra(int s)
//{
//	// Su dung s gan cho cac dinh con lai
//	for(int i = 1 ; i <= v ; i++)
//		d[i] = a[s][i];
//	d[s] = 0; // Duong di ngan nhat tu s den chinh no la: 0
//	T.erase(find(T.begin(),T.end(),s)); // Co dinh dinh s
//	while(!T.empty())
//	{
//		int Min = INT_MAX,m;
//		for(int i = 0 ; i < T.size() ; i++)
//		{
//			if(Min >= d[T[i]])
//			{
//				Min = d[T[i]];
//				m = T[i];
//			}					
//		}
//		T.erase(find(T.begin(),T.end(),m)); // Co dinh dinh m
//		// Su dung dinh m gan lai cho cac dinh
//		for(int i = 0 ; i < T.size() ; i++)
//			if(d[T[i]] > d[m] + a[m][T[i]])
//				d[T[i]] = d[m] + a[m][T[i]];
//	}
//	// In ket qua
//	for(int i = 1 ; i <= v ; i++)
//		cout<<d[i]<<" ";
//	cout<<endl;
//}
// 
//main()
//{
//	cin>>t;
//	while(t--)
//	{
//		cin>>v>>e>>u;
//		T.clear();
//		// Khoi tao
//		for(int i = 1 ; i <= v ; i++)
//			T.push_back(i);
//		for(int i = 1 ; i <= v ; i++)
//			for(int j = 1 ; j <= v ; j++)
//				a[i][j] = INT_MAX;
//		while(e--)
//		{
//			cin>>x>>y>>w;
//			a[x][y] = w;
//			a[y][x] = w;
//		}
//		Dijkstra(u);
//	}
//}

// Cach khac
#define ii pair<int,int>

vector<ii>a[1005];
int V,d[1005];

void Dijkstra(int s)
{
	// Sort theo trong so nho nhat luon o dau tien
	priority_queue<ii,vector<ii>,greater<ii>>T;
	for(int i = 1 ; i <= V ; i++)
		d[i] = INT_MAX;
	d[s] = 0;
	T.push({0,s});
	while(!T.empty())
	{
		int u = T.top().second;
		T.pop();
		for(int i = 0 ; i < a[u].size() ; i++)
		{
			int v = a[u][i].second;
			int uv = a[u][i].first;
			if(d[v] > d[u] + uv)
			{
				d[v] = d[u] + uv;
				T.push({d[v],v});
			}
		}
	}
}

main()
{
	faster()
	int t,e,s,x,y,w;
	cin>>t;
	while(t--)
	{
		cin>>V>>e>>s;
		for(int i = 1 ; i <= V ; i++)
			a[i].clear();
		while(e--)
		{
			cin>>x>>y>>w;
			a[x].push_back({w,y});
			a[y].push_back({w,x});
		}
		Dijkstra(s);
		for(int i = 1 ; i <= V ; i++)
			cout<<d[i]<<" ";
		cout<<endl;
	}
}

#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
//https://www.geeksforgeeks.org/union-find/
//int T,x,y,parent[1005];
//
//struct canh{
//	int dau;
//	int cuoi;
//};
//
//struct graph{
//	int V; // So dinh
//	int E; // So canh
//	vector<canh>e;
//};
//
//// Tim goc cua dinh s
//int find(int s)
//{
//	if(parent[s] == 0) return s;
//	while(parent[s] != 0)
//		s = parent[s];
//	return s;
//}
//
//// Noi hai goc cua dinh s va t
//void Union(int s,int t)
//{
//	/*s = find(s);
//	t = find(t);
//	if(s != t)*/ parent[s] = t;
//}
//
//
//int tim_chu_trinh(graph a)
//{
//	memset(parent,0,sizeof(parent));
//	for(int i = 0 ; i < a.e.size() ; i++)
//	{
//		x = find(a.e[i].dau);
//		y = find(a.e[i].cuoi);
//		if(x == y) return 1;
//		Union(x,y);
//	}
//	return 0;
//}
//
//main()
//{
// 	faster()
//	cin>>T;
//	while(T--)
//	{
//		graph a;
//		cin>>a.V>>a.E;
//		for(int i = 1 ; i <= a.E ; i++)
//		{
//			cin>>x>>y;
//			a.e.push_back({x,y});
//		}
//		if(tim_chu_trinh(a)==1) cout<<"YES";
//		else cout<<"NO";
//		cout<<endl;
//	}
//}

//https://www.geeksforgeeks.org/union-find-algorithm-set-2-union-by-rank/
int T,x,y;

struct canh{
	int dau;
	int cuoi;
};

struct graph{
	int V; // So dinh
	int E; // So canh
	vector<canh>e;
};

struct subset{
	int parent;
	int rank;
}; 

// Tim goc cua dinh s
int find(vector<subset>b,int s)
{
	while(b[s].parent != s)
		s = b[s].parent;
	return b[s].parent;
}

// Noi hai goc cua dinh s va t
// Cai goc nao co rank > hon thi  noi cai goc con lai vao
// Truong hop 2 goc deu co rank = nhau. => Noi cai nao vao nhau cx dc. Tang rank cai con lai len 1
void Union(vector<subset>&b,int s,int t)
{
	s = find(b,s);
	t = find(b,t);
	if(b[s].rank < b[t].rank)
		b[s].parent = t;
	else if(b[s].rank > b[t].rank)
		b[t].parent = s;
	else //= nhau thi noi cai nao vao cai nao cung duoc
	{
		b[t].parent = s;
		b[s].rank++;
	}
}

int tim_chu_trinh(graph a)
{
	vector<subset>b;
	for(int i = 0 ; i <= a.V+1 ; i++)
		b.push_back({i,0});
	for(int i = 0 ; i < a.e.size() ; i++)
	{
		x = find(b,a.e[i].dau);
		y = find(b,a.e[i].cuoi);
		if(x == y) return 1;
		Union(b,x,y);
	}
	return 0;
}

main()
{
 	faster()
	cin>>T;
	while(T--)
	{
		graph a;
		cin>>a.V>>a.E;
		for(int i = 1 ; i <= a.E ; i++)
		{
			cin>>x>>y;
			a.e.push_back({x,y});
		}
		if(tim_chu_trinh(a)==1) cout<<"YES";
		else cout<<"NO";
		cout<<endl;
	}
}

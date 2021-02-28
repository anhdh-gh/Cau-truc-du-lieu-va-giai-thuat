#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int t,v,e,x,y,w,Min_w;
vector<int>V; // Tap dinh ban dau
vector<int>VH; // Tap dinh cua cay
vector<pair<int,int> >T; // Tap canh cau cay khung
int a[1005][1005]; // Ma tran trong so

int Prim(int s)
{
	Min_w = 0;
	VH.push_back(s); // Add dinh s
	V.erase(find(V.begin(),V.end(),s)); // Loai bo dinh s khoi V
	while(T.size() < v-1)
	{
		// Tim canh i j co w_min sao cho i thuoc VH,j thuoc V
		w = INT_MAX;
		for(int i = 0 ; i < VH.size() ; i++)
		{
			for(int j = 0 ; j < V.size() ; j++)
			{
				if(w > a[VH[i]][V[j]])
				{
					w = a[VH[i]][V[j]];
					x = VH[i];
					y = V[j];
				}
			}
		}
		Min_w += w; // Update trong so min
		a[x][y] = INT_MAX;
		a[y][x] = INT_MAX;
		T.push_back({x,y}); // add canh
		V.erase(find(V.begin(),V.end(),y));
		VH.push_back(y);
	}
	return Min_w;
}

main()
{
 	faster()
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		V.clear();
		VH.clear();
		T.clear();
		for(int i = 1 ; i <= v ; i++)
			for(int j = 1 ; j <= v ; j++)
				a[i][j] = INT_MAX;	
		// Khoi tao tap dinh ban dau
		for(int i = 1 ; i <= v ; i++) V.push_back(i);
		while(e--)
		{
			cin>>x>>y>>w;
			a[x][y] = w;
			a[y][x] = w;
		}
		cout<<Prim(1)<<endl;
	}
}
//1
//13 26
//1 2 2
//1 3 1
//1 4 3
//2 3 2
//2 6 5
//2 7 5
//3 4 4
//3 6 5
//4 5 5
//4 6 5
//5 6 6
//5 10 6
//6 7 6
//6 8 6
//6 9 6
//6 10 6
//7 8 6
//8 9 7
//8 12 7
//8 13 7
//9 10 7
//9 11 7
//10 11 7
//10 12 7
//11 12 8
//12 13 8
//Output = 60

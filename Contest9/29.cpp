#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// 1. Dieu kien do thi vo huong la do thi euler
//   - Do thi vo huong lien thong: use DFS hoac BFS  = {...} == v => Do thi vo huong lien thong
//	 - Do thi moi dinh deu co bac chan.

// 2. Dieu kien do thi vo huong la do thi nua euler (co duong di euler)
// 	  - Do thi vo huong lien thong.
//	  - Co 0 hoac 2 dinh bac le.
//		+ 0 dinh bac le. =>. Do thi euler
//      + 2 dinh bac le => Ra o dinh le nay, vao o dinh le con lai
int T,v,e,x,y,daxet[1005],dfs,dem_le;
vector<vector<int> >ke;

// Kiem tra lien thong cua do thi vo huong
void DFS(int s)
{
	daxet[s] = 1;
	dfs++;
	for(int i = 0 ; i < ke[s].size() ; i++)
		if(daxet[ke[s][i]]==0) DFS(ke[s][i]);
}

// Dem bac cua dinh, return resolt
int process()
{
	dfs = 0;
	DFS(1);
	if(dfs != v) return 0; // do thi khong lien thong
	dem_le = 0;
	for(int i = 1 ; i <= v ; i++)
		if(ke[i].size()%2!=0) dem_le++;	
	if(dem_le == 0) return 2;
	if(dem_le == 2) return 1;
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
		memset(daxet,0,sizeof(daxet));
		while(e--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
			ke[y].push_back(x);
		}
		cout<<process()<<endl;
	}
}

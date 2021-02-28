#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
// 1. Dieu kien do thi co huong la do thi euler
//   - Do thi co huong lien thong yeu: Ton tai DFS(u) hoac BFS(u)  = {...} == v => Do thi co huong lien thong yeu
//	 - Do thi co ban deg+(u) = deg-(u). Moi u thuoc v

// 2. Dieu kien do thi co huong la do thi nua euler (co duong di euler)
// 	  - Do thi co huong lien thong yeu.
//	  - Ton tai hai dinh u,v sao cho: deg+(u) - deg-(u) = deg-(u) - deg+(u) = 1
// 	  - Cac dinh con lai deg+ = deg-
//    => Duong di se ra tu dinh u ka ket thuc vao dinh v
int T,v,e,x,y,daxet[1005],dfs,deg_ra,deg_vao,ok;
vector<vector<int> >ke;

// Kiem tra lien thong yeu cua do thi co huong
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
	ok = 0;
	for(int i = 1 ; i <= v ; i++)
	{
		dfs = 0;
		DFS(i);
		if(dfs == v) {ok = 1;break;} 	
	}
	if(ok == 1)
	{
		for(int i = 1 ; i <= v ; i++)
		{
			deg_ra = ke[i].size();
			deg_vao = 0;
			for(int j = 1 ; j <= v ; j++)
				if(find(ke[j].begin(),ke[j].end(),i) != ke[j].end()) deg_vao++;
			if(deg_ra != deg_vao) return 0;
		}		
		return 1;
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
		memset(daxet,0,sizeof(daxet));
		while(e--)
		{
			cin>>x>>y;
			ke[x].push_back(y);
		}
		cout<<process()<<endl;
	}
}

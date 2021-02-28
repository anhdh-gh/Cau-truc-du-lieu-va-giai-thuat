#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int T,v,e,i,j,daxet[10000],s;
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		// Chuyen ve danh sach ke
		vector<vector<int> >res(1005);
		while(e--)
		{
			cin>>i>>j;
			res[i-1].push_back(j);
			res[j-1].push_back(i);
		}
		// BFS
		memset(daxet,0,sizeof(daxet));
		vector<vector<int> >tplt;
		for(j = 1 ; j <= v ; j++)
			if(daxet[j] == 0)
			{
				s = j;
				daxet[s] = 1;
				vector<int>luu;
				queue<int>q;
				q.push(s);
				luu.push_back(s);
				while(!q.empty())
				{
					s = q.front();
					q.pop();
					for(i = 0 ; i < res[s-1].size() ; i++)
						if(daxet[res[s-1][i]]==0)
						{
							daxet[res[s-1][i]] = 1;
							q.push(res[s-1][i]);
							luu.push_back(res[s-1][i]);
						}			
				}
				tplt.push_back(luu);						
			}
		// In
		cout<<tplt.size()<<endl;
	}
}

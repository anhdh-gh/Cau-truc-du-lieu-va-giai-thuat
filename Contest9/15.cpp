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
		// DFS
		memset(daxet,0,sizeof(daxet));
		vector<vector<int> >tplt;
		for(j = 1 ; j <= v ; j++)
			if(daxet[j] == 0)
			{
				s = j;
				daxet[s] = 1;
				vector<int>luu;
				stack<int>st;
				st.push(s);
				luu.push_back(s);
				while(!st.empty())
				{
					s = st.top();
					st.pop();
					for(i = 0 ; i < res[s-1].size() ; i++)
						if(daxet[res[s-1][i]]==0)
						{
							daxet[res[s-1][i]] = 1;
							st.push(s);
							st.push(res[s-1][i]);
							luu.push_back(res[s-1][i]);
							break;
						}			
				}
				tplt.push_back(luu);						
			}
		// In
		cout<<tplt.size()<<endl;
	}
}

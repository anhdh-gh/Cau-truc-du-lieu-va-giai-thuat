#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int T,v,e,i,j,s,t;
	cin>>T;
	while(T--)
	{
		cin>>v>>e>>s>>t;
		// Convert from dsc to dsk
		vector<vector<int> >res(v);
		while(e--)
		{
			cin>>i>>j;
			res[i-1].push_back(j);
			res[j-1].push_back(i);
		}
		// sort lai cac dinh trong dsk
		// Phai co them ham sort moi dung, Nhung bo di moi yes
//		for(i = 0 ; i < res.size() ; i++)
//			sort(res[i].begin(),res[i].end());
		// DFS;
		int daxet[v+1],truoc[v+1];
		memset(daxet,0,sizeof(daxet));
		memset(truoc,0,sizeof(truoc));
		daxet[s] = 1;
		stack<int>st;
		st.push(s);
		truoc[s] = 0;
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
					truoc[res[s-1][i]] = s;
					break;
				}			
		}
		// output
		list<int>luu;
		if(truoc[t] == 0) cout<<-1;
		else
		{
			while(truoc[t] != 0)
			{
				luu.push_front(t);
				t = truoc[t];
			}	
			luu.push_front(t);
			// In duong di
			for(auto it = luu.begin() ; it != luu.end() ; it++)
				cout<<*it<<" ";					
		}
		cout<<endl;	
	}
}

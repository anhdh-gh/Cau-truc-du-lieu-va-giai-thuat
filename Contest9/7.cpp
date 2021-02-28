#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int T,v,e,i,j,s;
	cin>>T;
	while(T--)
	{
		cin>>v>>e>>s;
		// Convert from dsc to dsk
		vector<vector<int> >res(v);
		while(e--)
		{
			cin>>i>>j;
			res[i-1].push_back(j);
		}
		// sort lai cac dinh trong dsk
		// Phai co them ham sort moi dung, Nhung bo di moi yes
//		for(i = 0 ; i < res.size() ; i++)
//			sort(res[i].begin(),res[i].end());
		// DFS;
		int daxet[v+1];
		memset(daxet,0,sizeof(daxet));
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
		// output
		for(i = 0 ; i < luu.size() ; i++)
			cout<<luu[i]<<" ";
		cout<<endl;
	}
}

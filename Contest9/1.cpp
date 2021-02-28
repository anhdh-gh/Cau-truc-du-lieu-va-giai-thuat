#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

main()
{
 	faster()
	int T,v,e,i,j;
	cin>>T;
	while(T--)
	{
		cin>>v>>e;
		vector<vector<int> >res(v);
		while(e--)
		{
			cin>>i>>j;
			res[i-1].push_back(j);
			res[j-1].push_back(i);
		}
		for(i = 0 ; i < res.size() ; i++)
		{
			sort(res[i].begin(),res[i].end());
			cout<<i+1<<": ";
			for(j = 0 ; j < res[i].size() ; j++)
				cout<<res[i][j]<<" ";
			cout<<endl;
		}
	}
}

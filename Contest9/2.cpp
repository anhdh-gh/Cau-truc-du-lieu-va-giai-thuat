#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pair pair<int,int>
using namespace std;

void cut_string(int i,vector<pair>&res,string temp)
{
	temp += " ";
	int so = 0;
	for(int j = 0 ; j < temp.size() ; j++)
		if(temp[j] >= '0' && temp[j] <= '9')
			so = so*10+(temp[j]-'0');
		else 
		{
			if(so > i) res.push_back({i,so});
			so = 0;
		}
}

main()
{
 	faster()
	int n;
	cin>>n;
	cin.ignore();
	vector<pair>res;
	string temp;
	for(int i = 1 ; i <= n ; i++)
	{
		getline(cin,temp);
		cut_string(i,res,temp);
	}
	for(int i = 0 ; i < res.size() ; i++)
		cout<<res[i].first<<" "<<res[i].second<<endl;
}

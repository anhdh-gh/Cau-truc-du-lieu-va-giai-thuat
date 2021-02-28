#include<bits/stdc++.h>
using namespace std;

main()
{
	long long T;
	cin>>T;
	cin.ignore();
	string s;
	while(T--)
	{
		getline(cin,s);
		s += " ";
		vector<string>res;
		string temp;
		for(long long i = 0 ; i < s.size() ; i++)
		{
			if(s[i]==' '&&temp.size()!=0)
			{
				res.push_back(temp); 
				temp.clear();
			}
			else temp.push_back(s[i]);
		}
		for(long long i = 0 ; i < res.size() ; i++)
		{
			reverse(res[i].begin(),res[i].end());
			cout<<res[i]<<" ";
		}
		cout<<endl;
	}
}

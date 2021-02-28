#include<bits/stdc++.h>
using namespace std;

void In(vector<long long>S)
{
	if(S.empty()==1) cout<<"empty";
	else
		for(long long i = 0 ; i < S.size() ; i++)
			cout<<S[i]<<" ";
	cout<<endl;
}

main()
{
	string command;
	long long value;
	vector<long long>S;
	while(cin>>command)
	{
		if(command=="push")
		{
			cin>>value;
			S.push_back(value);
		}
		else if(command=="show") In(S);
		else S.pop_back();
	}
}

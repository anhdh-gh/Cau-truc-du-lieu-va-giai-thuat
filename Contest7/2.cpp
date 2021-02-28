#include<bits/stdc++.h>
using namespace std;

						
main()
{
	long long T,value;
	string command;
	cin>>T;
	stack<long long>S;
	while(T--)
	{
		cin>>command;
		if(command=="PUSH")
		{
			cin>>value;
			S.push(value);
		}
		else if(command=="PRINT")
		{
			if(S.empty()==1) cout<<"NONE";
			else cout<<S.top();
			cout<<endl;
		}
		else if(S.empty()!=1) S.pop();
	}
}


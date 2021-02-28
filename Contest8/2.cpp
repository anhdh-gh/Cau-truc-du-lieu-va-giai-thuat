#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


main()
{
 	faster()
	long long stv,x;
	string tv;
	queue<long long>q;
	cin>>stv;
	while(stv--)
	{
		cin>>tv;
		if(tv == "PUSH") 
		{
			cin>>x;
			q.push(x);
		}
		else if(tv == "PRINTFRONT")
			if(q.empty() != 1) cout<<q.front()<<endl;
		 	else cout<<"NONE"<<endl;
		else if(tv == "POP" && q.empty() != 1) q.pop();
	}
}


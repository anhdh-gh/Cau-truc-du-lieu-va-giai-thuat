#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


main()
{
 	faster()
	long long stv,x;
	string tv;
	deque<long long>q;
	cin>>stv;
	while(stv--)
	{
		cin>>tv;
		if(tv == "PUSHBACK") 
		{
			cin>>x;
			q.push_back(x);
		}
		else if(tv == "PUSHFRONT") 
		{
			cin>>x;
			q.push_front(x);
		}
		else if(tv == "PRINTFRONT")
			if(q.empty() != 1) cout<<q.front()<<endl;
			else cout<<"NONE"<<endl;
		else if(tv == "POPFRONT" && q.empty() != 1) q.pop_front();
		else if(tv == "PRINTBACK")
			if(q.empty() != 1) cout<<q.back()<<endl;
			else cout<<"NONE"<<endl;
		else if(tv == "POPBACK" && q.empty() != 1) q.pop_back();
	}
}


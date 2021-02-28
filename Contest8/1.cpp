#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;


main()
{
 	faster()
	long long T,n,tv,tv3;
	cin>>T;
	while(T--)
	{
		queue<long long>q;
		cin>>n;
		while(n--)
		{
			cin>>tv;
			if(tv == 3) 
			{
				cin>>tv3;
				q.push(tv3);
			}
			else if(tv == 1) cout<<q.size()<<endl;
			else if(tv == 2) 
			{
				if(q.empty()==1) cout<<"YES"<<endl;
				else cout<<"NO"<<endl;
			}
			else if(tv == 4 && q.empty() != 1) q.pop();
			else if(tv == 5)
			{
				if(q.empty() != 1) cout<<q.front()<<endl;
				else cout<<-1<<endl; 
			}
			else if(tv  == 6)
			{
				if(q.empty() != 1) cout<<q.back()<<endl;
				else cout<<-1<<endl; 				
			}
		}
	}
}


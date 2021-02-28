#include<bits/stdc++.h>
using namespace std;

//idea: 
// Duyet tu dau den cuoi.
// Neu a[i] = 'D' => stack.push(i+1) 
// Neu a[i] = 'I' or i == a.size() 
// => in ra (i+1) va in tat ca gia tri trong stack

void process(string a)
{
	stack<long long>st;
	for(long long i = 0 ; i <= a.size() ; i++)
		if(a[i] == 'I' || i == a.size())
		{
			cout<<i+1;
			while(!st.empty())
			{
				cout<<st.top();
				st.pop();	
			}	
		} 
		else if(a[i] == 'D') st.push(i+1);
	cout<<endl;
}

main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		process(a);
	}
}

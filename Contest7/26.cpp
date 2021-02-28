#include<bits/stdc++.h>
using namespace std;

main()
{
	// faster
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // input
	long long n;
	cin>>n;
	long long a[n],res[n];
	for(long long i = 0 ; i < n ; i++)
		cin>>a[i];
	// process
	stack<long long>st;// Luu vi tri
	res[0] = 1;
	st.push(0);
	for(long long i = 1 ; i < n ; i++)
	{
		while(!st.empty() && a[st.top()] <= a[i]) st.pop();
		if(st.empty()==1) res[i] = i+1; // if stack empty =>a[i] >= all element on left
		else res[i] = i - st.top();
		st.push(i);
	}
	// In resolt
	for(long long i = 0 ; i < n ; i++)
		cout<<res[i]<<" ";
}
// Neu 1 so a[i] >= a[j] , a[j] >= a[k]... => a[i] >= a[k]...

#include<bits/stdc++.h>
using namespace std;

// covert string a -> long long
long long s_l(string a)
{
	stringstream convert(a);
	long long x;
	convert>>x;
	return x;
}

void process(string a)
{
	vector<char>st;
	for(long long i = 0 ; i < a.size() ; i++)
	{
		if(a[i]!=']') st.push_back(a[i]);
		else
		{
			string temp;
			while(st.empty()!=1 && st.back()!='[') // Lay tat ca cac ki tu trong [ .. ] 
			{
				temp.push_back(st.back());
				st.pop_back();
			}
			st.pop_back(); // pop not dau [
			// Lay so truoc [
			string so;
			while(st.empty()!=1 && st.back() >= '0' && st.back() <= '9')
			{
				so.push_back(st.back());
				st.pop_back();
			}
			// Lap so lan
			reverse(so.begin(),so.end()); // dao nguoc so
			long long T = s_l(so);
			while(T--)
			{
				for(long long j = temp.size()-1 ; j >= 0 ; j--)
					st.push_back(temp[j]);
			}
		}
	}
	for(long long i = 0 ; i < st.size() ; i++)
		cout<<st[i];
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

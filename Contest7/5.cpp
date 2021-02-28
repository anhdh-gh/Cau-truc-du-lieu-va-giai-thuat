#include<bits/stdc++.h>
using namespace std;

// Khong the lam theo cach liet ke cac chuoi con roi kiem tra
////Kiem tra xem day con co tao thanh day dung khong.
//bool check(string a)
//{
//	stack<char>s;
//	for(long long i = 0 ; i < a.size() ; i++)
//		if(a[i]=='(')
//			s.push(a[i]);
//		else if(s.empty()!=1)
//		{
//			if('(' != s.top()) return false;
//			else s.pop();
//		} 
//		else return false;
//	if(s.empty()==1) return true;
//	return false;
//}
//
//// Lay k ki tu tu vi tri n
//string cat(string s,long long n,long long k)
//{
//	string temp;
//	for(long long i = n ; i < s.size() ; i++)
//	{
//		temp.push_back(s[i]);
//		k--;
//		if(k==0) break;
//	}
//	if(k==0) return temp;
//}
//
//long long process(string a)
//{
//	// Liet ke tat ca cac day con
//	for(long long i = a.size() ; i >= 1 ; i--) // Lay i ki tu
//		for(long long j = 0 ; j < a.size() ; j++) // Tu vi tri j
//		{
//			if(a.size()-j >= i)
//			{
//				string temp = cat(a,j,i);
//				if(check(temp)==true) return temp.size();
//			}			
//		}
//	return 0;
//}

long long process(string a)
{
	long long Max = 0;
	vector<long long>st;
	st.push_back(-1);
	for(long long i = 0 ; i < a.size() ; i++)
	{
		if(a[i]=='(') st.push_back(i); //push vi tri
		else 
		{
			st.pop_back();
			if(st.empty()!=1) Max = max(Max,i-st.back());
			else st.push_back(i);
		}
	}
	return Max;
}


main()
{
	long long T;
	cin>>T;
	string a;
	while(T--)
	{
		cin>>a;
		cout<<process(a)<<endl;
	}
}
//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/

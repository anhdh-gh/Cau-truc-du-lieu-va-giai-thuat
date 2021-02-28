#include<bits/stdc++.h>
using namespace std;

//1 so la so ugly la:
// n = 2^a * 3^b * 5^c
vector<long long>ugly;
void loc()
{
	priority_queue<long long,vector<long long>,greater<long long> >luu;
	luu.push(1);
	long long truoc=0;
	ugly.push_back(0);
	while(ugly.size() <= 1e4)
	{
		long long s = luu.top();
		luu.pop();
		if(ugly.back()!=s)
		{
			luu.push(s*2);
			luu.push(s*3);
			luu.push(s*5);	
			ugly.push_back(s);		
		}
	}
//	for(long long i = 0 ; i < ugly.size() ; i++)
//		cout<<i<<"-"<<ugly[i]<<endl;
}
// Ung voi moi 1 so i bat ki ta se sinh ra duoc 3 so khac la: 2*i , 3*i , 5*i roi them vao hang doi uu tien
// Case: Trung nhau => khong xet den pop ra luon

main()
{
	loc();
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cout<<ugly[n]<<endl;
	}
}
//https://www.geeksforgeeks.org/ugly-numbers/

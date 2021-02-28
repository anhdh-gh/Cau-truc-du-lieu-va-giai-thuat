#include<bits/stdc++.h>
using namespace std;
int F[105];	//F[i] la khoang thoi gian de in ra i ki tu
int n, X, Y, Z;
int dp()
{
	//tai moi vi tri i co 2 cach de dien
		//1,  i-1 ki tu insert them 1 ki tu dc i ki tu
		//2,  i/2 ki tu gap doi len duoc i ki tu
				//2.1, i chan khong co j de noi
				//2.2, i le 
						//2.2.1, ta lay [i/2]*2 thi can insert them 1 phan tu
						//2.2.2  ta lay [(i+1)/2]*2 thi can delete di 1 phan tu
	//th co so
	//khong in ra ki tu
	F[0]=0;
	//ki tu dau tien bat buoc insert
	F[1]=X;
	
	//
	for(int i=2;i<=n;i++)
	{
		if(i%2==0){
			F[i]=min(F[i-1] + X, F[i/2] + Z);
		}
		else{
			F[i]=min(F[i-1] + X, min(F[i/2] + Z + X, F[(i+1)/2] + Z + Y));
		}
	}
	return F[n];
}
int main()
{
	int t; cin>>t;
	while(t--)
	{
		//insert_time==X | delete_time==Y | copy_time==Z
		cin>>n>>X>>Y>>Z;
		cout<<dp()<<endl;
	}
}

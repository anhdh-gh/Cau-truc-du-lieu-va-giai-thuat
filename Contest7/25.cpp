#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

//// Danh sach lien ket vong
//struct node{
//	int so;
//	node *next;
//};
//
//// Submit tren geeksforgeeks => yes
////https://practice.geeksforgeeks.org/problems/game-of-death-in-a-circle/0
//int process(int n,int m)
//{
//	if(m == 1) return n;
//	//B1: Tao vong tron
//	node *circle = new node,*dau;
//	circle->so = 1; // Gia tri dau tien
//	dau = circle;// Luu cai dau tien
//	for(int i = 2 ; i <= n ; i++)
//	{
//		circle->next = new node;
//		circle = circle->next;
//		circle->so = i;
//	}
//	circle->next = dau; // Noi thanh vong
//
//	//B2: Xoay vong
//	circle = dau; // Dua ve node dau tien
//	while(dau != circle->next)
//	{
//		//Tim vi tri nguoi can lay ra
//		for(int i = 1 ; i < m /*(m-1)*/ ; i++)
//			circle = circle->next;
//		// Xoa	
//		dau = circle->next->next;
//		circle->next = dau;
//		circle = circle->next;					
//	}
//	return circle->so;
//}

// Code tren geeksforgeeks
long long process(long long n, long long m)
{
  if (n == 1)
    return 1;
  else
    return (process(n-1,m) + m)%n +1;
}

main()
{
	faster()
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		cout<<process(n,m)<<endl;
	}
}

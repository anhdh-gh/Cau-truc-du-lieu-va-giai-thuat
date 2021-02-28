#include<iostream>
#include<vector>
using namespace std;

main()
{
	long long T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		vector<string>a;
		a.push_back("0");
		a.push_back("1");
		for(long long i = 2 ; i <= n ; i++)
		{
			for(long long j = a.size()-1 ; j >= 0 ; j--)
				a.push_back(a[j]);
			for(long long j = 0; j < a.size()/2 ; j++)
				a[j] = "0" + a[j];
			for(long long j = a.size()/2 ; j < a.size(); j++)
				a[j] = "1" + a[j];
		}
		for(long long i = 0 ; i < a.size() ; i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
}
// cach chuyen binary -> gray
//consider a 6 bit binary code 110110
//
//- first bit form left side of gray code will be the first bit from left side of
//   binary code i.e 1.
//- for second bit of gray code, find XOR operation on first and second bit of 
//  binary code i.e. 1 XOR 1 = 0
//- For third bit of gray code, find XOR operation on second and third bit of 
//  binary code i.e. 1 XOR 0 = 1
//- For forth bit of gray code, find XOR operation on third and forth bit of 
//  binary code i.e. 0 XOR 1 = 1
//- For fifth bit of gray code, find XOR operation on forth and fifth bit of 
//  binary code i.e. 1 XOR 1 = 0
//- For sixth bit of gray code, find XOR operation on fifth and sizth bit of 
//  binary code i.e. 1 XOR 0 = 1
//
//Therefore, the gray code of given binary code is 101101

// cach khac 
//n-bit Gray Codes can be generated from list of (n-1)-bit Gray codes using following steps.
//1) Let the list of (n-1)-bit Gray codes be L1. Create another list L2 which is reverse of L1.
//2) Modify the list L1 by prefixing a ‘0’ in all codes of L1.
//3) Modify the list L2 by prefixing a ‘1’ in all codes of L2.
//4) Concatenate L1 and L2. The concatenated list is required list of n-bit Gray codes.
//
//For example, following are steps for generating the 3-bit Gray code list from the list of 2-bit Gray code list.
//L1 = {00, 01, 11, 10} (List of 2-bit Gray Codes)
//L2 = {10, 11, 01, 00} (Reverse of L1)
//Prefix all entries of L1 with ‘0’, L1 becomes {000, 001, 011, 010}
//Prefix all entries of L2 with ‘1’, L2 becomes {110, 111, 101, 100}
//Concatenate L1 and L2, we get {000, 001, 011, 010, 110, 111, 101, 100}
//
//To generate n-bit Gray codes, we start from list of 1 bit Gray codes. 
//The list of 1 bit Gray code is {0, 1}.
// We repeat above steps to generate 2 bit Gray codes from 1 bit Gray codes, 
// then 3-bit Gray codes from 2-bit Gray codes till the number of bits becomes equal to n. 
// Following is the implementation of this approach.

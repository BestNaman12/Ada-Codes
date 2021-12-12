#include <bits/stdc++.h>
using namespace std;
void Min_Exchange(int V , int n , int deno[])
{
	sort(deno, deno + n);
	vector<int> ans;
	for (int i = n - 1; i >= 0; i--) {
		while (V >= deno[i]) {
			V -= deno[i];
			ans.push_back(deno[i]);
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
}
int main()
{
	int amount;
	int opt;
	int size;
	int denominations[] = { 1, 2, 5, 10, 20,50, 100, 500, 1000 };
	int user_deno[10];
	cout<<"\n Enter the amount whose exchange is required : ";
	cin>>amount;
	cout<<"\n Do you wish to enter your particular denominations ? : ";
	cout<<"\n 1.Yes \n 2. No ";
	cout<<"\n Enter your choice : ";
	cin>>opt;
	if(opt == 1)
	{
		int n;
		cout<<"\n How many types of denominations you want to enter ? : ";
		cin>>n;
		cout<<"\n Enter denominations : ";
		for(int i=0;i<n;i++)
		{
			cin>>user_deno[i];
		}
		size = n;
		cout<<"The minimum exchange calculated is : ";
		Min_Exchange(amount,size,user_deno);
	}
	else	
	{
		size = sizeof(denominations) / sizeof(denominations[0]);
		cout<<"The minimum exchange calculated is : ";
		Min_Exchange(amount,size,denominations);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int Min_Exchange(int coins[], int m, int V)
{
	int table[V+1];
	table[0] = 0;

	for (int i=1; i<=V; i++)
	{
		table[i] = INT_MAX;
	}
	for (int i=1; i<=V; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (coins[j] <= i)
			{
				int sub_res = table[i-coins[j]];
				if (sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
		}
	}
	if(table[V]==INT_MAX)
		return -1;
	return table[V];
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
		cout<<"The minimum exchange calculated is : "<<Min_Exchange(user_deno , size , amount);
	}
	else	
	{
		size = sizeof(denominations) / sizeof(denominations[0]);
		cout<<"The minimum exchange calculated is : "<<Min_Exchange(denominations , size , amount);
	}
	return 0;
}

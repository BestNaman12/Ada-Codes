#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int opt1;
	do{
	int opt;
	int temp,j,i,minimum_index;
	cout<<"\n 1. Bubble Sort";
	cout<<"\n 2. Selection Sort";
	cout<<"\n Enter your choice : ";
	cin>>opt;
	int a[1000];
	int n;
	switch(opt)
	{
		case 1 : 
				cout<<"\n Enter the size of array : ";
				cin>>n;
				cout<<"\n Enter the array elements : ";
				for(int i=0;i<n;i++)
				{
					cin>>a[i];
				}
				for(i=0;i<n-1;i++)
				{
					for(j=0;j<n-i-1;j++)
					{
						if(a[j]>a[j+1])
							swap(a[j],a[j+1]);
					}
				}
				cout<<"\n The Sorted Array is : ";
				for(i=0;i<n;i++)
					cout<<a[i]<<" ";
				break;
		case 2 : 
				cout<<"\n Enter the size of array : ";
				cin>>n;
				cout<<"\n Enter the array elements : ";
				for(int i=0;i<n;i++)
				{
					cin>>a[i];
				}
			    for (i = 0; i < n-1; i++)
			    {
			        minimum_index = i;
			        for (j = i+1; j < n; j++)
			        if (a[j] < a[minimum_index])
			            minimum_index = j;
			        swap(a[minimum_index], a[i]);
			    }
			    cout<<"\n The Sorted Array is : ";
				for(i=0;i<n;i++)
					cout<<a[i]<<" ";
				break;
		default : cout<<"\n Wrong Option ";
	}
	cout<<"\n Continue ? 1= YES , 0= No : ";
	cin>>opt1;
}while(opt1!=0);
	return 0;
}
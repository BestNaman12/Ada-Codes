// selection_sort
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[1000];
	int n;
	cout<<"\n Enter the size of array : ";
	cin>>n;
	cout<<"\n Enter the array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int i, j, minimum_index;
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
	return 0;
}
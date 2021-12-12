// binary_recursive
#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int A[], int low, int high, int x)
{
    if (low > high) 
    {
        return -1;
    }
 
    int mid = (low + high)/2;   

    if (x == A[mid]) 
    {
        return mid;
    }

    else if (x < A[mid]) {
        return binarySearch(A, low, mid - 1, x);
    }
 
    else {
        return binarySearch(A, mid + 1, high, x);
    }
}
 
int main(void)
{
    int n;
	int a[1000];
	int key;

	cout<<"\n Enter the value of n : ";
	cin>>n;

	cout<<"\n Enter the array elements : ";
	for(int i=0;i<n;i++)
		cin>>a[i];

	cout<<"\n Enter the element to be searched : ";
	cin>>key;
 
 	sort(a,a+n);

    int low = 0, high = n - 1;
    int index = binarySearch(a, low, high, key);
 
    if (index != -1) 
    {
        cout<<"\n Element found at index "<<index+1;
    }

    else 
    {
        cout<<"\n Element not found in the array";
    }
 
    return 0;
}
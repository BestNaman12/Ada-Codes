#include <iostream>
using namespace std;
void merge(int arr[], int p, int q, int r) 
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[p + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[q + 1 + j];
	int i, j, k;
	i = 0;
	j = 0;
	k = p;
	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) 
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) 
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int p, int r) {
	if (p < r) {

		int q = p + (r - p) / 2;
		mergeSort(arr, p, q);
		mergeSort(arr, q + 1, r);
		merge(arr, p, q, r);
	}
}


void printArray(int arr[], int size) 
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() 
{
	int arr[1000];
	int n;	
	cout<<"\n Enter the size of array : ";
	cin>>n;
	cout<<"\n Enter the array elements : ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	mergeSort(arr, 0, size - 1);
	cout << "Sorted array: \n";
	printArray(arr, size);
	return 0;
}

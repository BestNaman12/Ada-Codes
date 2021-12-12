#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int temp,j,i,minimum_index;
	cout<<"\n 3. Insertion Sort";
	int a[1000];
	int n;
		
				cout<<"\n Enter the size of array : ";
				cin>>n;
				cout<<"\n Enter the array elements : ";
				for(int i=0;i<n;i++)
				{
					cin>>a[i];
				}
				for(int k=1; k<n; k++)   
			    {  
			        temp = a[k];  
			        j= k-1;  
			        while(j>=0 && temp <= a[j])  
			        {  
			            a[j+1] = a[j];   
			            j = j-1;  
			        }  
			        a[j+1] = temp;  
			    }  
			    cout<<"\n Sorted Array : ";
			    for(int i=0;i<n;i++)
			    {
			    	cout<<a[i]<<" ";
			    } 
			    
	return 0;
}
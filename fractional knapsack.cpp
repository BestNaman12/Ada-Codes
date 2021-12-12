// fractional knapsack using greedy
#include<iostream>
#include<algorithm>
using namespace std;
struct bag 
{
    double value, weight;
};
bool cmp(struct bag a, struct bag b)
{
    double r1 = a.value / a.weight;
    double r2 = b.value / b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, struct bag arr[], int n)
{
    sort(arr, arr + n, cmp);
    int current_weight = 0; 
    double answer = 0.0; 
    for (int i = 0; i < n; i++) {
        if (current_weight + arr[i].weight <= W) 
        {
            current_weight += arr[i].weight;
            answer += arr[i].value;
        }
        else {
            double remaining_weight = W - current_weight;
            answer += arr[i].value * ((remaining_weight / arr[i].weight));
            break;
        }
    }
    return answer;
}
int main()
{
    double W;
    cout<<"\n Enter the weight of knapsack : ";
    cin>>W;
    double n;
    bag a[100];
    cout<<"\n Enter n : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    	cout<<"\n Enter profit and weight of item "<<i+1<<" : ";
    	cin>>a[i].value>>a[i].weight;
    }
    cout << "Maximum value we can obtain "<< fractionalKnapsack(W, a, n);
    return 0;
}
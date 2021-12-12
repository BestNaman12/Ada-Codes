#include<bits/stdc++.h>
using namespace std;

int KnapSack(int W, int wt[],int P[], int n){
    int w,i;
    vector<vector<int>> MaxProfit(n+1,vector<int>(W+1));
    vector<vector<int>> keep(n+1,vector<int>(W+1));
    
    for(i=0;i<=n;i++){
        for(w=0;w<=W;w++){
        if(i==0 || w==0){
            MaxProfit[i][w]=0;
        }
        else if(wt[i-1]<=w){
               MaxProfit[i][w]=max(P[i-1]+MaxProfit[i-1][w-wt[i-1]],MaxProfit[i-1][w]);
               keep[i][w]=1;
            }
        else{
                MaxProfit[i][w]=MaxProfit[i-1][w];
                keep[i][w]=0;
            }
        }     
    }
    int k=W;
        for(i=n;i>0;i--){
            
            if(keep[i][k]==1){
                cout<<wt[i]<<endl;
                k=k-wt[i];
            }
        }
    return MaxProfit[n][W];
    }

int main()
{
    int wt[]={5,4,6,3};
    int profit[]={10,40,30,50};
    int W=10;
    int n=sizeof(wt)/sizeof(wt[0]);

    cout<<KnapSack(W,wt,profit,n)<<endl;
}

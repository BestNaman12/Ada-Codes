#include<iostream>
using namespace std;
int a[10][10],visited[10],n,cost=0;
int least(int c){
    int nc=999;
    int min=999,kmin;
    for(int i=0;i<n;i++){
        if((a[c][i]!=0)&&(visited[i]==0)){
            if(a[c][i]<min){
                min=a[i][0]+a[c][i];
                kmin=a[c][i];
                nc=i;
            }
        }
    }
        if(min!=999)
            cost+=kmin;
            return nc;
}
void min_cost(int city){
    int ncity;
    visited[city]=1;
    cout<<city+1<<"->";
    ncity=least(city);
    if(ncity==999){
        ncity=0;
        cout<<(ncity+1);
        cost+=a[city][ncity];
        return;
    }
    min_cost(ncity);
}
void print(){cout<<"\nMinimum Cost: "<<cost<<endl;}
int main(){
    cout<<"Enter the number of cities: ";
    cin>>n;
    cout<<"\nEnter the Cost Matrix: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            visited[i]=0;
        }
    }
    min_cost(0);
    print();
}


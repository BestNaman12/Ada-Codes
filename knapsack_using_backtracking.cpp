#include<iostream>
using namespace std;
#define max 10
int w[max],i,j,p[max];
int n,m;
float unit[max];
int y[max],x[max],fp=-1,fw;
void get()
{
	cout<<"\n Enter total number of items: ";
	cin>>n;
	cout<<"\n Enter the Maximum capacity of the Sack: ";
	cin>>m;
	for(i=0;i<n;i++)
	{
		cout<<"\n Enter the weight of the item "<<i+1<<" : ",i+1;
		cin>>w[i];
		cout<<"\n Enter the profit of the item "<<i+1<<" : ", i+1;
		cin>>p[i];
	}
}
void show()
{
	float s=0.0;
	cout<<"\n\tItem\tWeight\tCost\tUnit Profit\tSelected ";
	for(i=0;i<n;i++)
		cout<<"\n\t"<<i+1<<"\t"<<w[i]<<"\t"<<p[i]<<"\t"<<unit[i]<<"\t\t    "<<x[i];
	cout<<"\n\n The Sack now holds following items : ";
	for(i=0;i<n;i++)
		if(x[i]==1)
		{
			cout<<"\t"<<i+1;
			s += (float) p[i] * (float) x[i];
		}
		cout<<"\n Maximum Profit:  "<<s;
	}

	void sort()
	{
		int t,t1;
		float t2;
		for(i=0;i<n;i++)
			unit[i] = (float) p[i] / (float) w[i];
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(unit[i]  < unit[j])
				{
					t2 = unit[i];
					unit[i] = unit[j];
					unit[j] = t2;
					t = p[i];
					p[i] = p[j];
					p[j] = t;
					t1 = w[i];
					w[i] = w[j];
					w[j] =t1;
				}
			}
		}
	}
	float bound(float cp,float cw,int k)
	{
		float b = cp;
		float c = cw;
		for(i=k;i<=n;i++)
		{
			c = c+w[i];
			if( c < m)
				b = b +p[i];
			else
				return (b+(1-(c-m)/ (float)w[i])*p[i]);
		}
		return b;
	}
	void knapsack(int k,float cp,float cw) //cp is current profit and cw is current weight
	{
		if(cw+w[k] <= m)
		{
			y[k] = 1;
			if(k <= n)
				knapsack(k+1,cp+p[k],cw+w[k]);
			if(((cp+p[k]) > fp) && ( k == n))
			{
				fp = cp+p[k];
				fw = cw+w[k];
				for(j=0;j<=k;j++)
					x[j] = y[j];
			}
		}
		if(bound(cp,cw,k) >= fp)
		{
			y[k] = 0;
			if( k <= n)
				knapsack(k+1,cp,cw);
			if((cp > fp) && (k == n))
			{
				fp = cp;
				fw = cw;
				for(j=0;j<=k;j++)
					x[j] = y[j];
			}
		}
	}
	int main()
	{
		get();
		cout<<"\n The KnapSack is arranged in the order\n";
		sort();
		knapsack(0,0.0,0.0);
		show();
		return 0;
	}
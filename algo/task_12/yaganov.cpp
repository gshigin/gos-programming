#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    long long int N,lev=1000000000000,l=0,X1,Y1,X2,Y2,xo,yo,niz=10000000000000000;
    long double A=0,L=0;
	
    cin >> N;
	
    if (N==1) 
	{
		cout << 0 << endl << 0; 
		system("Pause");
		return 0;
	}
	
    vector <long long int> x(N);
    vector <long long int> y(N);
    vector <long long int> sp(N);
	
    for (long long int i=0; i<N; ++i) 
	{
		cin >> x[i] >> y[i];
		if (x[i]<lev) 
		{
			lev=x[i]; 
			niz=y[i]; 
			l=i;
		}
	
		if ((x[i]==lev)&&(y[i]<=niz)) 
		{
			lev=x[i]; 
			niz=y[i]; 
			l=i;
		};
	}
	
    xo=x[l]; 
	yo=y[l];
	
    for (long long int i=0; i < N; ++i) 
	{
		x[i]=x[i]-xo; 
		y[i]=y[i]-yo;
	}
	
    swap(x[0],x[l]); 
	swap(y[0],y[l]);
	
    for (long long int i = 1; i < N; ++i)
	{
        for(long long j = i+1; j < N; ++j)
        {
            if (x[i]*y[j]-x[j]*y[i]<0) 
			{
				swap(x[i],x[j]); 
				swap(y[i],y[j]);
			}
            if ((x[i]*y[j]-x[j]*y[i]==0)&&(x[j]*x[j]+y[j]*y[j]<x[i]*x[i]+y[i]*y[i]))
            {
				swap(x[i],x[j]); swap(y[i],y[j]);
			}
        };
	}
	
    sp[0]=0; 
	sp[1]=1;
    long long int k = 1;
	
    for (long long int i = 2; i <N ; ++i)
    {
        X1 = x[sp[k]]-x[sp[k-1]]; Y1=y[sp[k]]-y[sp[k-1]];
        X2 = x[i]-x[sp[k]]; Y2=y[i]-y[sp[k]];
		
        while ((X1*Y2-X2*Y1<=0)&&(k>1)) 
		{
			k--;
            X1=x[sp[k]]-x[sp[k-1]]; 
			Y1=y[sp[k]]-y[sp[k-1]];
            X2=x[i]-x[sp[k]]; 
			Y2=y[i]-y[sp[k]];
		}

        k++;
        sp[k]=i;
    }
    for (int i = 0; i < k; ++i)
    {
        A=A+0.5*(x[sp[i]]*y[sp[i+1]]-x[sp[i+1]]*y[sp[i]]);
        L=L+sqrt((x[sp[i]]-x[sp[i+1]])*(x[sp[i]]-x[sp[i+1]])+(y[sp[i]]-y[sp[i+1]])*(y[sp[i]]-y[sp[i+1]]));
    }
	
    A=A+0.5*(x[sp[k]]*y[sp[0]]-x[sp[0]]*y[sp[k]]);
    L=L+sqrt((x[sp[k]]-x[sp[0]])*(x[sp[k]]-x[sp[0]])+(y[sp[k]]-y[sp[0]])*(y[sp[k]]-y[sp[0]]));
    cout.precision(20);
    cout << L << endl << abs(A) << endl;
	
	system("Pause");
    return 0;
}
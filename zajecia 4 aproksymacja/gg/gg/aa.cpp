#include <iostream>
#include <cstdlib>

using namespace std;



//***W DANYCH PUNKCIE, BLAD**********
int main()

{
    int n;
    cout<<"podaj liczbe punktow"<<endl;
    cin>> n;
    double *x=new double[n];
    double *y=new double[n];
   double a0,a1;
    for(int i=0;i<n;i++)
    {
      cout<<"podaj x i y dla punktu nr "<<i<<": "<<endl;
      cin>>x[i]>>y[i];
    }
    int d;
    cout<<"wybierz stopien aproksymacji"<<endl;
    cin>> d;
    int m=d+1;
   
   
	double**g=new double*[m];
    for(int i=0;i<m;i++)
    {
    	g[i]=new double [m];
	}
	
    double*p=new double[m];
   for(int i=0;i<m;i++)
   {
	   p[i]=0;
   }
   for(int i=0;i<m;i++)
   {
   	for(int j=0;j<m;j++)
   	{
	   
       g[i][j]=0;
   }
   }
  
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<m;j++)
    	{
    		int w=i+j;
    	
    		for(int k=0;k<n;k++)
    		{
    			
    			double c=1;
    			if(w==0)
    			{
				g[i][j]=n;
			}
    			else
    			{
    				for(int t=w;t>0;t--)
    				{
    					c*=x[k];
    					
					}
		
					g[i][j]+=c;
				}
    			
			}
		
		}
	}
	
	for(int i=0;i<n;i++)
	{
		p[0]+=y[i];
	}
	for(int i=1;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int a=i;
			double wynik=y[j];
			for(;a>0;a--)
			{
				wynik*=x[j];
			}
			p[i]+=wynik;
		
		}
	}
	

	cout<<"Macierz g"<<endl;

	for(int i=0;i<m;i++)
	{
	for(int j=0;j<m;j++)
	{
		cout<<g[i][j]<<" ";
		
	}
	cout<<endl;
	}

	cout<<endl;
	cout<<"Macierz p"<<endl;

	for(int i=0;i<m;i++)
	{
		cout<<p[i]<<" ";
		
	cout<<endl;
	}


	
system("pause");
return 0;
}
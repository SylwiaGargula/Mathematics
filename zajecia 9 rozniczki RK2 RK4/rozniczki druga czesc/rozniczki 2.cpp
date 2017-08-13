#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x, double y)
{
	return -1*x*x +y;

}
double O(double x,double y,double h)
{
	double k1=f(x,y);
	double k2=f(x+h,y+h*k1);
	return 0.5*(k1+k2);
}

double O1(double x,double y,double h)
{
	double k1=f(x,y);
	
	double k2=f(x+0.5*h,y+0.5*h*k1);
	
	double k3=f(x+0.5*h,y+0.5*h*k2);
	
	double k4=f(x+h,y+h*k3);
	
	double d=((1.0/6.0)*(k1+2*k2+2*k3+k4));
	
	return d;
}

int main()
{


	
	cout<<"****************"<<endl;
	double a=0;
	cout<<"Metoda RK4"<<endl;
	cout<<"Podaj poczatek przedzialu a"<<endl;
	cin>>a;



	double b;
	cout<<"Podaj warunek poczatkowy(wartosc dla a)"<<endl;
	cin>>b;

	
	int n=0;
	cout<<"Podaj ilosc krokow"<<endl;
	cin>>n;

	
	double x=0, y=0;
	cout<<"Podaj punkt-koniec przedzialu"<<endl;
	cin>>x;

	double h=(x-a)/n;



	for(int i=1; i<=n;i++)
	{
		 b= b + h*O1(a,b,h);
         a+= h;
		 cout <<a<<' '<< b<<endl;
	}

	
	
		double a1=0;
	cout<<"****************"<<endl;
	cout<<"Metoda RK2"<<endl;
	cout<<"Podaj poczatek przedzialu a"<<endl;
	cin>>a1;


	double b1;
	cout<<"Podaj warunek poczatkowy(wartosc dla a)"<<endl;
	cin>>b1;

	
	int n1=0;
	cout<<"Podaj ilosc krokow"<<endl;
	cin>>n1;

	
	double x1=0, y1=0;
	cout<<"Podaj punkt-koniec przedzialu"<<endl;
	cin>>x1;

	double h1=(x1-a1)/n1;
	
	
	
	for(int i=1; i<=n1;i++)
	{
		 b1= b1 + h1*O(a1,b1,h1);
        a1+= h1;
		 cout <<a1<<' '<< b1<<endl;
	}

	





	system("pause");

}

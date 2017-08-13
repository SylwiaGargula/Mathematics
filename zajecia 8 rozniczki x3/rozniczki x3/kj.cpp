#include <iostream>
#include <cstdlib>

using namespace std;

double f(double x, double y)
{
	return x*x +y;

}

int main()
{
	double a=0;
	cout<<"****************"<<endl;
	cout<<"Metoda Eulera"<<endl;
	cout<<"Podaj poczatek przedzialu a"<<endl;
	cin>>a;


	double warunek;
	cout<<"Podaj warunek poczatkowy(wartosc dla a)"<<endl;
	cin>>warunek;

	double h=0;
	cout<<"Podaj ilosc krokow"<<endl;
	cin>>h;

	
	double x=0, y=0;
	cout<<"Podaj punkt w ktorym chcesz obliczyc wartosc(koniec przedzialu)"<<endl;
	cin>>x;
	
	double n=(x-a)/(h-1);


	for(int i=1; i<h;i++)
	{
		 warunek = warunek + n*f(a,warunek);
        a += n;
		 cout <<a<<' '<< warunek<<endl;
	}
	a=0;
	warunek=0;
	
	cout<<"*************"<<endl;
	cout<<"Metoda Heuna"<<endl;

	cout<<"Podaj poczatek przedzialu a"<<endl;
	cin>>a;

cout<<"Podaj warunek poczatkowy(wartosc dla a)"<<endl;
	cin>>warunek;

	
	
	for(int i=1; i<h;i++)
	{
		 warunek = warunek + 0.5*n*(f(a,warunek)+f(a+n,warunek+n*f(a,warunek)));
        a += n;
		 cout <<a<<' '<< warunek<<endl;
	}
	
	a=0;
	warunek=0;
	
	cout<<"*************"<<endl;
	cout<<"Zmodyfikowana metoda Eulera"<<endl;

	cout<<"Podaj poczatek przedzialu a"<<endl;
	cin>>a;

cout<<"Podaj warunek poczatkowy(wartosc dla a)"<<endl;
	cin>>warunek;

	
	
	for(int i=1; i<h;i++)
	{
		 warunek=warunek+ n*f(a+0.5*n,warunek+0.5*n*f(a,warunek));
        a += n;
		 cout <<a<<' '<< warunek<<endl;
	}
	



system("PAUSE");
return 0;
}
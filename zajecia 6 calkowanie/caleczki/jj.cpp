#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{
	cout<<"Calkowanie numeryczne"<<endl;

	cout<<"Calkowana funkcja to cosinus"<<endl;
	

	double a=0, b=0;
	cout<<"Podaj przedzial a i b"<<endl;
	cin>>a;
	cin>>b;

	double pomoc=0;
	pomoc=(a+b)/2;

	double kwadrat=0;
	kwadrat=(b-a)*(cos(pomoc));

	cout<<"Calkowanie metoda prostokatow"<<endl;
	cout<<"Pole powierzchni pod cosinusoida na przedziale "<<a<<" "<<b<<" wynosi "<<kwadrat<<endl;

	cout<<"****************************"<<endl;
	
	cout<<"Calkowanie metoda trapezow"<<endl;

	double poczatek=0;
	poczatek=cos(a);

	double koniec=0;
	koniec=cos(b);

	double trapez=0;
	trapez=(b-a)* ((poczatek+koniec)/2);

	
	cout<<"Pole powierzchni pod cosinusoida na przedziale "<<a<<" "<<b<<" wynosi "<<trapez<<endl;

	cout<<"****************************"<<endl;
	cout<<"Calkowanie metoda Simpsona"<<endl;

	double simpson=0;
	double ulamek=0;
	ulamek=cos((a+b)/2);


	simpson=((b-a)/6)*(poczatek+koniec+(4*ulamek));


	
	cout<<"Pole powierzchni pod cosinusoida na przedziale "<<a<<" "<<b<<" wynosi "<<simpson<<endl;



	cout<<"****************************"<<endl;
	



system("pause");
}
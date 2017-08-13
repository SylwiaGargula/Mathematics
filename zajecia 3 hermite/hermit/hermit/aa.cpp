#include <iostream>
#include <cstdlib>

using namespace std;





int main()
{

	int ilosc_wezlow; //przechowuje iloscc punktow bez ich krotnosci

	cout<<"Interpolacja hermite'a"<<endl;
	cout<<"Podaj ilosc wezlow"<<endl;
	cin>>ilosc_wezlow;



	int krotnosc;
	double * tablica=new double[ilosc_wezlow]; //przechowuje jaka ma krotnosc kazdy punkt

	for(int i=0; i<ilosc_wezlow; i++)
	{
	cout<<"Podaj krotnosc punktu nr "<<i<<endl;
	cin>>krotnosc;
	tablica[i]=krotnosc;

	}
	//tablica 2wymiarowa
	double **punkty = new double *[ilosc_wezlow];
	for(int i=0; i<ilosc_wezlow; i++)
	 *punkty= new double[tablica[i]];

	for(int i=0; i<ilosc_wezlow; i++)
	{
	cout<<"Podaj wartosci X punktu "<<i<<endl;
	cin>>punkty[0][i];
	}

	for(int i=0; i<ilosc_wezlow;i++)
	{
		for(int j=1; j<tablica[i];j++)
		{
		cout<<"Podaj wartosci Y i pochodne punktu "<<i<<endl;
		cin>>punkty[j][i];
		}
	}
	
	system("PAUSE");
	return 0;
}
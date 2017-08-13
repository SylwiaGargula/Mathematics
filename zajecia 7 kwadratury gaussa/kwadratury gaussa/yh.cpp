#include <iostream>
#include <cstdlib>

using namespace std;


int main()
{

	cout<<"Kwadratura gaussa \nFunkcja 1/x"<<endl;
	
	double a=0;
	double b=0;
	cout<<"Podaj przedzial calkowania"<<endl;
	cin>>a;
	cin>>b;

	cout<<"Kwadratura dwuwezlowa"<<endl;

	double x0=0.577350;
	double x1=-0.577350;

	double t0=0;
	double t1=0;

	t0=((a+b)/2) + (((b-a)/2)*x0);
	cout<<t0<<endl;

	t1=((a+b)/2) + (((b-a)/2)*x1);
	cout<<t1<<endl;

	double f0=0;
	double f1=0;

	f0=1/t0;
	f1=1/t1;
	cout<<f0<<endl;
	cout<<f1<<endl;
	//A=0
	double q=((b-a)/2)*(f0+f1);
	cout<<"Q wynosi "<<q<<endl;
	cout<<"*************"<<endl;

	cout<<"Kwadratura czterowezlowa"<<endl;

	double x[4];
	x[0]=-0.861136;
	x[1]=-0.339981;
	x[2]=0.339981;
	x[3]=0.861136;

	double t[4];
	cout<<"t"<<endl;
	for(int i=0; i<4; i++)
	{
		t[i]=((a+b)/2)+(((b-a)/2)*x[i]);
		cout<<t[i]<<endl;
	}

	double A[4];
	A[0]=0.347855;
	A[1]=0.652145;
	A[2]=0.652145;
	A[3]=0.347855;

	double f[4];
	cout<<"f"<<endl;
	for(int i=0; i<4; i++)
	{
	f[i]=1/t[i];
	cout<<f[i]<<endl;
	}


	double q1[4];
	for(int i=0; i<4; i++)
	{
		q1[i]=A[i]*f[i];
	}

	double Q=0;
	Q=((b-a)/2)*(q1[0]+q1[1]+q1[2]+q1[3]);
	cout<<"Q wynosi "<<Q<<endl;

system("pause");
return 0;
}
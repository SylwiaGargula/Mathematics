#include<iostream>


using namespace std;


void interpolacjalagrange();
void interpolacja_hermita();


int main()
{

	interpolacjalagrange();
	//interpolacja_hermita();

	return 0;
}


//******************WYBRANE PUNKTY*****************
void interpolacjalagrange()
{
	int n;
	cout << "podaj ile wezlow interpolacji ";
	cin >> n;
	double* x = new double[n];
	double *y = new double[n];

	for (int i = 0; i<n; i++)
	{
		cout << "wprowadz x i y";
		cin >> x[i] >> y[i];
	}
	//obliczanie w danym punkcie
	double a;
	double wartosc2 = 0;
	cout << "wprowadz punkt w ktorym chcesz obliczyc wartosc ";
	cin >> a;
	for (int i = 0; i<n; i++)
	{
		double wartosc1 = 1;
		for (int j = 0; j<n; j++)
		{
			if (i != j)
			{
				wartosc1 *= ((a - x[j]) / (x[i] - x[j]));

			}


		}
		wartosc2 += wartosc1*y[i];
	}
	cout << "wartosc w tym punkcie wynosi " << wartosc2;
	system("pause");



	//wspolczynniki bk
	double *b = new double[n - 1];

	b[0] = y[0];

	for (int k = 1; k<n; k++)
	{
		double d = 0;
		for (int j = 0; j <= k; j++)
		{
			double c = 1;
			for (int i = 0; i <= k; i++)
			{
				if (j != i)
				{
					c *= x[j] - x[i];
				}

			}
			d += y[j] / (c);

		}

		b[k] = d;

	}
	cout << "wspolczynniki wielomianow:";
	for (int i = 0; i<n; i++)
		cout << b[i] << endl;

	// wartosc na podstawie wspolczynnikow
	double p = b[0];

	for (int i = 1; i < n; i++)
	{
		double m = 1;
		for (int j = 0; j < i; j++)
		{
			m *= a - x[j];
		}
		p += b[i] * m;

	}
	cout << "ze wspolczynnikow wychodzi dla tego samego punktu ";
	cout << p;

	//blad SSE

	double sse = 0;
	double *wartosci = new double[n];
	for (int i = 0; i < n; i++)
	{
		wartosci[i] = b[0];
	}
	for (int g = 0; g< n; g++)
	{
		for (int i = 1; i < n; i++)
		{
			double m = 1;
			for (int j = 0; j < i; j++)
			{
				m *= x[g] - x[j];
			}
			wartosci[g] += b[i] * m;

		}

	}

	for (int i = 0; i < n; i++)
	{
		sse = sse + (y[i] - wartosci[i])*(y[i] - wartosci[i]);

	}
	sse = sse / n;

	cout << endl << "blad wynosi 0";


	system("pause");
}


void interpolacja_hermita()
{
	cout << "podaj liczbe wez³ów";
	int n;
	cin >> n;
	double** tab = new double*[n];

	int *a = new int[n];
	for (int i = 0; i<n; i++)
	{
		cout << "podaj ile pochodnych znamy dla wezla +2 (wartosc x oraz y)" << i << ": ";
		cin >> a[i];
		tab[i] = new double[a[i]];
	}
	for (int i = 0; i<n; i++)
	{

		for (int j = 0; j<a[i]; j++)
		{
			cout << "podaj wartoœæ" << j << "pochodnej w" << i << "punkcie:(jezeli pochodna =0 podajemy wartosc x jezeli =1 podaje wartosc wezla ";
			cin >> tab[i][j];
		}

	}


	int b = 0;
	for (int i = 0; i < n; i++)
	{
		b += a[i] - 1;

	}

	int c = b;
	double **tablica = new double*[b];

	tablica[0] = new double[b];
	tablica[1] = new double[b];
	for (int i = 2; i <= c; i++)
	{
		b--;

		tablica[i] = new double[b];

	}
	int i = 0;
	for (int k = 0; k < n; k++)
	{
		for (int j = 0; j < a[k] - 1; j++)
		{

			tablica[i][0] = tab[k][0];
			tablica[i][1] = tab[k][1];
			i++;

		}
	}


	int d = c - 1;
	int q = 0;
	int y = a[0];
	int skok = 1;
	for (int j = 2; j <= c; j++)
	{

		for (int i = 0; i < d; i++)
		{
			if (i >= y - 1)
			{
				q++;
				y += a[q];
			}

			if (tablica[i][0] == tablica[i + skok][0])
			{
				int g = 1;
				for (int k = skok; k > 0; k--)
					g *= k;

				tablica[i][j] = tab[q][j] / g;
			}
			else
			{


				tablica[i][j] = ((tablica[i + 1][j - 1] - tablica[i][j - 1]) / (tablica[i + skok][0] - tablica[i][0]));
			}


		}
		skok++;
		d--;
	}



	double *wspolczynniki = new double[c];
	int j = 0;
	for (int i = 0; i < c; i++)
	{

		wspolczynniki[i] = tablica[0][i + 1];


		cout << "wspolczynnik b" << i << "=" << wspolczynniki[i] << endl;


	}
	double x;
	cout << "podaj punkt w ktorym chcesz obliczyc wartosc ";
	cin >> x;


	double calosc = wspolczynniki[0];


	for (int j = 0; j < c - 2; j++)
	{
		double pojedynczy = 1;
		for (int i = 0; i <= j; i++)
		{
			pojedynczy *= (x - tablica[i][0]);
		}

		pojedynczy *= wspolczynniki[j + 1];
		calosc += pojedynczy;


	}


	cout << "wartosc dla podanego punktu wynosi" << calosc;





	system("pause");
}
// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>
#include <windows.h>
#include <ctime>

using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
double GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}










int main()
{  
	StartCounter();
	fstream fout;
	
	fout.open("D:\\my projects 2\\fizfac progi\\intagrals\\data.txt");
	
	fout.precision(16);
	
	cout.precision(16);
	int n;
	double pi = 3.1415926535, h, x = 0, sum = 0, sum2 = 0, sum3=0, sum4=0, rs = 0,simpson=0;
	cout << "vvedite n \n";
	cout << "aaaaa" << GetCounter() << "\n";
	cin >> n;
	StartCounter();
	for (int k = 10; k <= 1000; k = k +1 ) {
		n = k+1;

		/*h = pi / n;
		n = n + 1;
		x = 0, sum = 0, sum2 = 0, sum3 = 0, sum4 = 0, rs = 0, simpson = 0;
		vector < vector<double>> data(n, vector<double>(2));

		for (int i = 0; i < n; i++)
		{
			data[i][0] = x;
			data[i][1] = sin(x);
			x = x + h;

		}
		//cout << x << "\n";
		for (int i = 0; i < n - 1; i++) {

			sum = sum + data[i + 1][1] * h;

		}
		for (int i = 0; i < n - 2; i++)
		{
			sum2 = sum2 + data[i + 1][1];

		}

		rs = h * sum2 + h * (data[0][1] + data[n - 1][1]) * (h / 2);
		*/

		x = 0, sum = 0, sum2 = 0, sum3 = 0, sum4 = 0, rs = 0, simpson = 0;
		n = n - 1;
		if (n % 2)
		{
			n = n + 1;
		}
		h = pi / n;

		x = 0;

		vector < vector<double>> data1((n + 1), vector<double>(2));
		for (int i = 0; i <= n; i++)
		{
			data1[i][0] = x;
			data1[i][1] = sin(x);
			x = x + h;
		}
		//cout << "\n";

		/*for (int i = 0; i <= n; i++)
		{
			cout << data1[i][1] << "\n";
		}
		*/


		for (int i = 1; i <= n / 2; i++) {
			sum3 = sum3 + data1[2 * i - 1][1];
		}

		for (int i = 1; i <= n / 2; i++) {
			sum4 = sum4 + data1[2 * i][1];
		}
		simpson = h / 3 * (data1[0][1] + 4 * sum3 + 2 * sum4 + data1[n][1]);

		//cout << "\n";
		fout << (2 - simpson) << "\n";
		

	}

/*
	for (int i = 0; i < n - 1; i++) {
		(data[i][1] + 4 * sin((data[i][0] + data[i][0]) / 2) + data[i + 1][1]);

	}*/
	//(data[i + 1][0] - data[i][0]) / 6

		

	cout << "aaaaa" << GetCounter() << "\n";
		cout << sum << "\n" << rs << "\n" << simpson << "\n";
		
	return(0);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

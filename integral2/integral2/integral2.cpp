// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
#include <vector>
#include<iomanip>
using namespace std;
int main()
{
	cout.precision(16);
	int n;
	double pi = 3.1415926535, h, x = 0, sum = 0, sum2 = 0, sum3 = 0, sum4 = 0, rs = 0, simpson = 0;
	cout << "vvedite n \n";
	cin >> n;

	h = pi / n;
	n = n + 1;
	vector < vector<double>> data(n, vector<double>(2));

	for (int i = 0; i < n; i++)
	{
		data[i][0] = x;
		data[i][1] = sin(x);
		x = x + h;

	}
	cout << x << "\n";
	for (int i = 0; i < n - 1; i++) {

		sum = sum + data[i + 1][1] * h;

	}
	//прямоугольники
	
	for (int i = 0; i < n - 2; i++)
	{
		sum2 = sum2 + data[i + 1][1];

	}
	
	rs = h * sum2 + h * (data[0][1] + data[n - 1][1]) * (h / 2);
	//трапеции
	double sum5 = 0;
	for (int i = 0; i < n-1 ; i++) {
		sum5=sum5+(data[i][1] + data[i + 1][1])* h / 2;

	}
	//неоптимизированые трапеции




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
	cout << "\n";

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

	cout << "\n";
	//метод симпсона



	/*
		for (int i = 0; i < n - 1; i++) {
			(data[i][1] + 4 * sin((data[i][0] + data[i][0]) / 2) + data[i + 1][1]);

		}*/
		//(data[i + 1][0] - data[i][0]) / 6




	    cout << setw(20) << "priamokutnik" << setw(30) << sum << setw(30) << 2 - sum;
		cout << "\n" << setw(20) << "trapezia" << setw(30) << sum5 << setw(30) << 2 - sum5;
		cout << "\n" << setw(20) << "optim trapezia" << setw(30) << rs << setw(30) << 2 - rs;
		cout << "\n" << setw(20) << "simpson" << setw(30) << simpson << setw(30) << 2 - simpson;

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

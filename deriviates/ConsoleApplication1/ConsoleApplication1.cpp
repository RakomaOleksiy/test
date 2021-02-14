// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
//#include <math.h>
#include <vector>
#include<fstream>
using namespace std;

double dsin(double h, double x)
{
	double d;

	d = (sin(x + h) - sin(x)) / h;

	return(d);
}



int main()
{

	ofstream fout;
	fout.open("data.txt");

	const float pi = 3.14159;
	int n = 0, i = 0;
	double h, x = 0, temproary_var = 0, temproary_var1;
 
	cout << "vedite n" << endl;
	cin >> n;

	

	vector<vector<double>> data(n+1, vector<double>(7));
	vector<vector<double>> data2(n+1, vector<double>(2));


	  
	h = pi / n;
	fout.precision(8);
	
	for (i = 0; i < n+1; i++) 
	

	{
		
		temproary_var=dsin(h, x);
		
		data[i][1] = temproary_var;
		data[i][0] = x;
		x = (x + h); 

		
	}
	
	x = 0;
	for (i = 0; i < n+1; i++) {
		temproary_var = cos(x);
			x = (x + h);
			data[i][2] = temproary_var;
	}
	for (i = 0; i < n+1; i++) {

		temproary_var= data[i][2] - data[i][1];
		data[i][3] = temproary_var;
	}
    for (i = 0; i < n-1+1; i++) 
	{
		temproary_var = (data[i + 1][1] - data[i][1]) / h;
		data[i][4] = temproary_var;
    }
	x = 0;
	for (i = 0; i < n+1; i++) 
	{
		temproary_var = ((-1) * sin(x));
		x = x + h;
		data[i][5] = temproary_var;
	}
    for (i = 0; i < n+1; i++)
	{
		data[i][6] = data[i][5] - data[i][4];
	}
   // cout << "x    " << "f(x)' p " << "f(x)'  a" << "f(x)'a-f(x)'p" << "f(x)2 p " << "f(x2  a" << "f(x)2a-f(x)2p" << endl;
	/*for (i = 0; i < n; i++)
	{
		for (int k = 0; k < 7; k++) 
		{
			cout << data[i][k] << "  ";
		}
		
		cout << endl;
	}*/
	
	for (i = 0; i < n+1; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			fout << data[i][k] << "  ";
		}

		fout << endl;
	}
	//////////////////////////////////////////////
	for (i = 0; i < n+1-1; i++) {
		data2[i][0] = data[i][3] / data[i][2];
		data2[i][1] = data[i][6] / data[i][5];
	}
	
	/*
	temproary_var = 0;
	temproary_var1 = 0;
	*/
	/*for (i = 1; i < n - 1; i++)
		{
			if (data[i][0] > temproary_var) { temproary_var = data[i][0]; }
			else {};
			if (data[i][1] > temproary_var1) { temproary_var1 = data[i][1]; }
			else {};

		}
		cout << temproary_var << endl << temproary_var1;*/
    /*for (i = 0; i < n ; i++) {
			for (int k = 0; k < 2; k++) {
				cout << data2[i][k] << "  ";
			}   cout << endl;
		}*/
	fout.close();

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

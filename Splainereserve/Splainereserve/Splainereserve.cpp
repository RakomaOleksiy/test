
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
int main()
{

	ifstream fout;
	ofstream fin;
	fout.open("D:\\my projects 2\\fizfac progi\\matrix\\data10.txt");

	if (!fout.is_open()) {

		cout << "Error";
	}
	else {
		double n = 0, a = 0, b = 0;

		int k = 0;

		vector<double> data(0);

		while (!fout.eof()) {
			fout >> n;
			data.push_back(n);
			n = 0;
		}

		n = data.size();
		k = n / 2;

		vector<vector<double>> data1(k, vector<double>(2));

		int c = 0;
		vector<vector<double>> data5(k, vector<double>(2));


		for (int i = 0; i < n; i = i + 2) {
			data1[c][0] = data[i];
			data1[c][1] = data[i + 1];
			c++;
		}
		data5 = data1;

		//////////////////////////////////////////
		////    INTERPOLATION SPLIN     /////////
		//////////////////////////////////////////

		//summary...

		n = data.size();
		k = n / 2;
		vector<double>h(k);
		vector<double>d(k);
		vector<double>u(k);
		vector<double>v(k);
		vector<double>z(k);
		vector<double>B(k);
		//part #1 serching for z coeficiennts....
		cout << k << "\n";
		for (int i = 0; i < k - 1; i++) {

			h[i] = data5[i + 1][1] - data5[i][1];
			cout << "h:" << h[i] << "\n";
			d[i] = 1 / h[i] * (data5[i + 1][0] - data5[i][0]);
			cout << "d:" << d[i] << "\n";
		};

		// Set...

		u[1] = 2 * (h[0] + h[1]);

		v[1] = 6 * (d[1] - d[0]);
		cout << "v:" << v[1] << "\n";
		// continue...

		for (int i = 2; i < k - 1; i++) {
			u[i] = 2 * (h[i] + h[i - 1]) - h[i - 1] * h[i - 1] / u[i - 1];

			v[i] = 6 * (d[i] - d[i - 1]) - h[i - 1] * v[i - 1] / u[i - 1];

		};

		// Set...

		z[0] = 0;
		z[k - 1] = 0;

		// continue...

		for (int i = k - 2; i > 0; i--) {
			z[i] = (v[i] - h[i] * z[i + 1]) / u[i];

		};

		// ok, now we have z coeficients...


		// Calculating B...

		for (int i = 0; i < k - 1; i++) {
			B[i] = -h[i] / 6 * z[i + 1] - h[i] / 3 * z[i] + 1 / h[i] * (data5[i + 1][0] - data5[i][0]);

		};


		// output of result...



		fout.close();
		fin.open("D:\\my projects 2\\fizfac progi\\matrix\\outSpline.txt");

		if (!fin.is_open()) {

			cout << "Error2";
		}
		


		for (int i = 0; i < k - 1; i++) {
			fin << data5[i][0] << "+(x-" << data5[i][1] << ")*(" <<
				B[i] << "+(x-" << data5[i][1] << ")*(" << z[i] / 2 << "+" << h[i] * 1/6 <<
				"*(x-" << data5[i][1] << ")*(" << z[i + 1] - z[i] << "))" << "\n";
		};

	}







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

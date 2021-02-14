// Method_Runge_Kute.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


double f(double x, double y,double z) {
	double p = 0;
	//p = 0.6 * y + 0.5 * z + 6 * cos(x) + 4 * sin(x);
	p =	z;
	
	return (p);
};
double g(double x, double y, double z) {
	double p = 0;
	//p = 4 * y + 0.5 * z + 3 * cos(x) + 5 * sin(x);
	p = pow(z, 2);
	
	return (p);
};



int main()
{
	ofstream fin;

	//start conditions..
	double y = 1;
	double x = 0;
	double x1 = x;
	double z = 2;
	double y1 = y;
	double z1 = z;
	double a = 0;
	double b = 0.5;
	double h = 0.01;
	double h1 = h;
	double hb;
	double de = 0.001;
	double buf = x;
	double buf2 = 0;
	double buf3 = 0;
	//calculations...

	int N = 10*(b - a) / h;

	double K1 = 0;
	double K2 = 0;
	double K3 = 0;
	double K4 = 0;

	double M1 = 0;
	double M2 = 0;
	double M3 = 0;
	double M4 = 0;





	//sikle...
	vector<vector<double>> X(N + 1, vector<double>(5));
	
	
	cout.precision(16);
	
	

	X[0][0] = y;
	X[0][1] = x;
    X[0][2] = y1;
	X[0][3] = z;
	X[0][4] = z1;
	double bx;

	
	for (int i = 0; i < N; i++) {
		//prosedure1...
		y = X[i][0];
	    z = X[i][3];
		x = X[i][1];
		cout << "x_is:  " << x <<"  i_is:"<<i<<"\n";


		K1 = h * f(x, y, z);
		M1 = h * g(x, y, z);
		K2 = h * f(x + 0.5 * h, y + 0.5 * K1, z + 0.5 * M1);
		M2 = h * g(x + 0.5 * h, y + 0.5 * K1, z + 0.5 * M1);
		K3 = h * f(x + 0.5 * h, y + 0.5 * K2, z + 0.5 * M2);
		M3 = h * g(x + 0.5 * h, y + 0.5 * K2, z + 0.5 * M2);
		K4 = h * f(x + h, y + K3, z + K3);
		M4 = h * g(x + h, y + K3, z + K3);
		






		/*
				cout << "K1 " << K1<<"\n";
				cout << "K2 " << K2 << "\n";
				cout << "K3 " << K3 << "\n";
				cout << "K4 " << K4 << "\n";
				cout <<"\n";
				*/
		buf2 = 0.16667 * (K1 + 2 * K2 + 2 * K3 + K4);
		buf3 = 0.16667 * (M1 + 2 * M2 + 2 * M3 + M4);
		y = y + buf2;
		z = z + buf3;
		

		X[i + 1][0] = y;
		X[i + 1][3] = z;
		

		if (i % 2 != 0) {
			
			y1 = X[i - 1][0];
			z1 = X[i - 1][3];
			bx = X[i - 1][1];

			hb = h * 2;



			K1 = hb * f(bx, y1,z1);
			M1 = hb * g(bx, y1,z1);
		   
			K2 = hb * f(bx+ 0.5 * hb, y1 + 0.5 * K1, z1 + 0.5 * M1);
			M2 = hb * g(bx + 0.5 * hb, y1 + 0.5 * K1, z1 + 0.5 * M1);
			
			K3 = hb * f(bx + 0.5 * hb, y1 + 0.5 * K2, z1 + 0.5 * M2);
			M3 = hb * g(bx + 0.5 * hb, y1 + 0.5 * K2, z1 + 0.5 * M2);

			K4 = hb * f(bx + hb, y1 + K3, z1 + M3);
			M4 = hb * g(bx + hb, y1 + K3, z1 + M3);

			y1 = y1 + 0.16667 * (K1 + 2 * K2 + 2 * K3 + K4);
			z1 = z1 + 0.16667 * (M1 + 2 * M2 + 2 * M3 + M4);
		 //cout << "de_is: " << abs(y - y1) << "\n";

			//cout << "ai_is:  " <<i<< "\n";
			//cout << "h_is:  " << h << "\n";
			//cout << "y_is:  " << y << "\n";
			//cout << "y1_is:  " << y1 << "\n";
			
			X[i + 1][2] = y1;
			X[i + 1][4] = z1;

			if (abs(y - y1) > de|| abs(z - z1) > de) { h = h * 0.5; i = i - 2;  }
			
			else { X[i + 1][1] = x + h; };
			
		}
		//cout << x << "\n";
		

		
		




		
		if (i % 2 == 0) {
			X[i + 1][1] = x + h;
			//cout << "aaaaaaaaaaaa" << "\n";
		}
		
	//X[i + 1][1] = x + h;
    }
	
	/*
	* 
	for (int i = 0; i < N; i++) {
	
		cout << X[i][0] << "	" << X[i][1] << "	" << X[i][2] << "	" << "\n";
	}
	*/



	fin.open("D:\\my projects 2\\fizfac progi\\matrix\\Kutaout.txt");
	fin << "ListPlot [{";
	for (int j = 0; j < N; j++) {

		fin << "{"<<X[j][1]<<"," <<X[j][0]<<"},"<< "\n";
	}
	fin << "}]";

	fin.close();
	fin.open("D:\\my projects 2\\fizfac progi\\matrix\\Kutaout2.txt");
	
	fin << "ListPlot [{";
	for (int j = 0; j < N; j++) {

		fin << "{" << X[j][1] << "," << X[j][3] << "}," << "\n";
	}
	fin << "}]";
	
	fin.close();
	int i = 0;
	//adams method...
	while (X[i+1][0]-X[i][0]<de)
	{

	
		i++;
		X[i + 4][0] = X[i + 3][0] + (h * 0.042) * (55 * f(X[i + 3][1], X[i + 3][0], X[i + 3][3]) - 59 * f(X[i + 2][1], X[i + 2][0], X[i + 2][3]) + 37 * f(X[i + 1][1], X[i + 1][0], X[i + 1][3]) - 9 * f(X[i][1], X[i][0], X[i][3]));
		X[i + 4][3] = X[i + 3][3] + (h * 0.042) * (55 * g(X[i + 3][1], X[i + 3][0], X[i + 3][3]) - 59 * g(X[i + 2][1], X[i + 2][0], X[i + 2][3]) + 37 * g(X[i + 1][1], X[i + 1][0], X[i + 1][3]) - 9 * g(X[i][1], X[i][0], X[i][3]));
		X[i + 4][1] = X[i + 3][1] + h1;

	}


	fin.open("D:\\my projects 2\\fizfac progi\\matrix\\Admsout1.txt");
	fin << "ListPlot [{";
	for (int j = 0; j < N; j++) {

		fin << "{" << X[j][1] << "," << X[j][0] << "}," << "\n";
	}
	fin << "}]";

	fin.close();
	fin.open("D:\\my projects 2\\fizfac progi\\matrix\\Admsout2.txt");

	fin << "ListPlot [{";
	for (int j = 0; j < N; j++) {

		fin << "{" << X[j][1] << "," << X[j][3] << "}," << "\n";
	}
	fin << "}]";








	
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

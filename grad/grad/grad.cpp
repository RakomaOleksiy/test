// grad.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
using namespace std;

double fxy(double x, double y) {
    double z;

    z = sin(x) + cos(y);
    return(z);

}
double dfx(double x, double y) {
    double h = 0.000000000001;
    double z = 0;
    z = (fxy(x + h, y) - fxy(x, y)) / h;
    return(z);


}
double dfy(double x, double y) {
    double h = 0.000000000001;
    double z = 0;
    z = (fxy(x, y+h) - fxy(x, y)) / h;
    return(z);
}

int main()
{
    ofstream fin;
    fin.open("D:\\my projects 2\\fizfac progi\\matrix\\GRAD.txt");


    double x = 0;
    double y = 0;
    double y1 = 0;
    double x1 = 0;
    double a = 0;
    double e = 1;
    
    srand(time(0));
    
    a =1+ rand() % 5;
    x =1+ rand() % 5;
    y = 1 + rand() % 5;
    
    a = 1;
    x = 1;
    y = 1;

    double d1=1, d2,n = 0;
   
    fin << "ListPointPlot3D[{";
    
    while (abs(d1) > 0.0001) {
        bool triger = 1;
        cout << d1 << "\n";
        d1 = dfx(x, y);
        d2 = dfy(x, y);

        n = pow((pow(d1, 2) + pow(d2, 2)), 0.5);
        double z;

        while (triger) {


            x1 = x - a * d1;

            y1 = y - a * d2;

            if ((fxy(x1, y1) - fxy(x, y)) <= e * a * n) { triger = 0; }
            else { a = a * 0.5; };
            cout << "a_is: " << a << "\n";
        }
        triger = 1;

        x = x - a * d1;
        y = y - a * d2;
        z = fxy(x, y);
            fin << "{" << x << "," << y << "," << z << "},";
    
    
    }
    fin << "}]";
    cout << "x_is: " << x<<"\n";
    cout << "Y_is: " << y <<"\n";
    cout << d1 << "\n";
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

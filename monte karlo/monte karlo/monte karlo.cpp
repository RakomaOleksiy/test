// monte karlo.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double Rx(double a, double b) 
    
    {

        return (double)(rand()) / RAND_MAX * (b - a) + a;
    }
double Ry(double a, double b)

{
    return (double)(rand()) / RAND_MAX * (b - a) + a;
}
  
double f(double x, double y) {
    return x*y;
}
double fx(double x) {
    return x;
}

   


int main()
{
    double z = 0;
    double sumx = 0;
    int N;
    double a = 0, b = 10;
    double c = 4, d = 8;

    cin >> N;

    for (int i = 0; i < N; i++) {
       sumx=sumx+f(Rx(a, b),Ry(c,d));
    }
   
    cout << (b-a)*(d-c)/N*sumx<< "\n";


    /*double c = 4, d = 8;
    double x;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        
      
        sumx = sumx+f(Rx(a,b),Ry(c,d));
       
    }
    
    cout << (sumx)/N;
    */





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

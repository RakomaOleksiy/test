#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;



/*int M(int i, int j, vector<vector<int>> data3, int k, int b;)
{
	int a=0;
	if (b = 1) { return data3[i][j] }
	else {
		
		for (i < k; i++)
		{

			a=a+pow(-1, (i + j))* data3[i][j] * M(i + 1, j + 1, data3);
			
		}
	}
}*/




/*int M(vector<vector<int>> data3,int k, int b,int i) {
	vector<double> buf(k);
	for (int j = 0; j < k; j++) {
	  
	
		if(data3[i][j]=0){
			for (int c = j+1; c < k; c++){
				if (data3[c][j] != 0)
				{
					for (int i = 0; i < k; i++) {
						data3[c][i] = buf[i];


					}
				}

					*/
					

    int main()
	{

 
	
	  
	
	  ifstream fin;
	
	  fin.open("D:\\my projects 2\\fizfac progi\\matrix\\data.txt");
	
	  if (!fin.is_open()) 
	   
	  {
		
		  cout << "Error";
	  }
	
	  
	  else

	  {



		  int k = 0, n = 0, b = 0, number = 0, nx = 0;
		  bool np = 1;

		  cout << "ura!! fail otkrilsa";

		  vector<double> data(0);
		  while (!fin.eof()) {
			  fin >> n;
			  data.push_back(n);
		  }
		  n = data.size();
		  k = sqrt(n);
		  vector<vector<double>> data2(k, vector<double>(k * 2));
		  vector<vector<double>> data3(k, vector<double>(k));
		  vector<vector<double>> data5(k, vector<double>(k));
		  vector<vector<double>> data6(k, vector<double>(k));
		  vector<double>buf(k * k);
		  //опрдлние матриц
		  int m = 0;
		  double d = 0;

		  for (int i = 0; i < k; i++)
		  {

			  for (int j = 0; j < k; j++)
			  {
				  data2[i][j] = data[b];
				  data5[i][j] = data[b];
				  b = b + 1;
			  }
		  }
		  cout << "\n";
		  /*for (int i = 0; i < k; i++)
		   {

			   for (int j = 0; j < k; j++)
			   {
				   cout << data2[i][j] << " ";
			   }
			   cout << "\n";
		   }*/
		   //запихивам цифры в матрицы
		  for (int i = 0; i < k; i++)
		  {
			  for (int j = k; j < k * 2; j++) {
				  if (i == (j - k)) { m = 1; }
				  else { m = 0; }
				  data2[i][j] = m;
			  }
		  }
		  //добавляем диничеую матрицу


		  /* for (int i = 0; i < k; i++)
		   {

			   for (int j = 0; j < k; j++)
			   {
				   data3[i][j] = 0;  data3[i][i] = 1;
			   }

		   }

		   for (int j = 0; j < k; j++)
			   for (int i = 0; i < k; i++)
			   {

				   if (data2[i][j] < 0.0001 || data2[i][j] > -0.0001) {
					   data2[i] = buf;
				   }


			   }

			*/
			/* for (int n = 0; n < k - 1; n++)

						if (data2[n][n] < 0.0001|| data2[n][n] > -0.0001)
						{

						 copy(0, (k - 1), back_inserter(buf));

						}*/

		  for (int n = 0; n < k; n++) {
			  for (int i = n; i < k; i++)
			  {

				  if (data2[i][n] == 0)
				  {

					  for (int c = n + 1; c < k; c++)
					  {
						  if (data2[c][n] != 0)
							  for (int j = 0; j < k * 2; j++)
							  {
								  data2[i][n] = data2[i][n] + data2[c][n];
								  //cout << "1" << "\n";
								  //cout << data2[i][n] << "\n";
							  }

					  }
				  }
			  }

			  // код сверху, чтоб избежать деления на ноль
			  for (int i = n + 1; i < k; i++) {

				  d = data2[i][n] / data2[n][n];
				  //cout << d << "\n";
				  for (int v = n; v < k * 2; v++) {

					  data2[i][v] = data2[i][v] - data2[n][v] * d;
					  //cout << "proverka" << "\n";

					  /*for (int i = 0; i < k; i++) {
						  for (int j = 0; j < k; j++)
						  {
							 // cout << setw(10) << data2[i][j];
						  }
						  //cout << "\n";
					  }
					  */
					  /*for (int i = 0; i < k; i++) {
						  for (int j = 0; j < k * 2; j++)
						  {
							  cout << setw(10) << data2[i][j];
						  }
						  cout << "\n";
					  }*/
				  }

				  for (int l = 0; l < k; l++) { if (data2[i][l] == 0) { nx = nx + 1; } }

				  if (nx == k) { np = 0; }
				  nx = 0;
			  }


		  }
		  //приводим к диагональному виду сверху вниз
		  for (int n = k - 1; n >= 0; n--) {
			  for (int i = n; i >= 0; i--)
			  {

				  if (data2[i][n]<0.000001 && data2[i][n] > -0.000001)
				  {

					  for (int c = n; c >= k; c--)
					  {
						  if (data2[c][n] > 0.000001 || data2[c][n] < -0.000001)

							  for (int j = 0; j < k * 2; j++)
							  {
								  data2[i][n] = data2[i][n] + data2[c][n];

							  }
					  }
				  }
			  }
			  for (int i = n - 1; i >= 0; i--) {

				  d = data2[i][n] / data2[n][n];
				  for (int v = n - 1; v < k * 2; v++) {

					  data2[i][v] = data2[i][v] - data2[n][v] * d;

				  }

			  }

		  }

		  // опять избегаем деления на бесконечно малые

		  /* for (int n = 0; n < k-1; n++) {
						  /for (int i = n + 1; i < k; i++) {*/
						  /* if (data2[n][n] < 0.0001 || data2[n][n] > -0.0001) {*/

		  cout.precision(2);

		  /*d= (data2[n][n] / data2[n][n]);
						  cout << d << "\n";




						  for (int j = 0; j < k; j++)
						   {
							  data2[n][j]=data2[n][j] - data2[n][j] * d;
							  for (int z = 0; z < k; z++)
							  {

								  for (int o = 0; o < k; o++)
								  {
									  cout << data2[z][o] << " ";
								  }
								  cout << "\n";
							  }
							  cout << "\n";
						  }
					   }
				   }*/
		  cout << "\n";
		  /*for (int n = 0; n < k - 1; n++) {

			  for (int i = 0; i < k - 1; i++) {

				  for (int j = 0; j < k; j++)
				  {
					  data2[n][j] - data2[i][j] / (data2[i + 1][i]);

				  }
			  }



		 // попытка гауса



	  }


		//cout << n;
		//buf[0];
		/*getline(fin, str);

		while (str[k] != '\0')

		{

			if (str[k] == ' ') { n = n + 1; }
			k = k + 1;
		}
		k = n + 1;

		vector<vector<int>> data(k, vector<int>(k));

		while (str[k] != '\0')

		{
			buf[i] = str[k];
			i = i + 1;
			 //if (str[k] != ' ') { b = b + 1;    }
			if (str[k] == ' ') { for(int u=0; u < i;u++){

			 data[x][number]

				 =(str[k-u]-0)*10


			}
			k = k + 1;

		}







	}
	*/
	/* for (int i = 0; i < k; i++) {
   for (int j = 0; j < k * 2; j++)
   {
	   cout << setw (10)<<data2[i][j];
   }
   cout << "\n";
}*/

		  if (!np) { cout << "det =0, or incorect matrix"; }
		  else {
			  double det = 1;
			  for (int i = 0; i < k; i++) {
				  det = det * data2[i][i];
			  }
			  cout << "\n";
			  cout << "determinant:" << det << "\n";
			  cout << "\n";

			  //считаем дтерминант, можно было провести эту процедуру раньше
			  //тогда бы погрешность была меньше



			  for (int i = 0; i < k; i++) {
				  d = 1 / data2[i][i];
				  for (int j = 0; j < k * 2; j++)
				  {
					  data2[i][j] = data2[i][j] * d;
				  }

			  }
			  //приводим к единичному виду правую матрицу
			  for (int i = 0; i < k; i++) {
				  for (int j = 0; j < k; j++)
				  {
					  data3[i][j] = data2[i][j + k];
				  }

			  }
			  // выделяем обратную матрицу из обшей
			  double q = 0;
			  for (int n = 0; n < k; n++)
			  {
				  for (int i = 0; i < k; i++) {

					  for (int j = 0; j < k; j++)
					  {
						  q = q + data3[i][j] * data5[j][n];

					  }
					  data6[i][n] = q; q = 0;

				  }
			  }
			  //проверяем перемножением




			  cout << "matrix" << "\n";
			  for (int i = 0; i < k; i++) {
				  for (int j = 0; j < k; j++)
				  {
					  cout << setw(10) << data5[i][j];
				  }
				  cout << "\n";

				  // вывод данных
			  }
			  cout << "ob matrix" << "\n";
			  for (int i = 0; i < k; i++) {
				  for (int j = 0; j < k; j++)
				  {
					  cout << setw(10) << data3[i][j];
				  }
				  cout << "\n";

				  // вывод данных
			  }
			  cout << "proverka" << "\n";
			  for (int i = 0; i < k; i++) {
				  for (int j = 0; j < k; j++)
				  {
					  cout << setw(10) << data6[i][j];
				  }
				  cout << "\n";

				  //  вывод данных
			  }
		  }
	  }
	  return(0);
    }


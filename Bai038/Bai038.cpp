#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

string getInputFileName(int);
string getOutputFileName(int);
void Nhap(int[][500], int&, int&, string);
void Xuat(int[][500], int, int, string);
void Xuat(int[][500], int, int);
int Tong5m(int[][500], int, int);
bool Kt5m(int);

int main()
{
	int m, n;
	int a[500][500];
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(a, m, n, FileName);

		cout << "\n" << FileName << endl;
		Xuat(a, m, n);

		int kq = Tong5m(a, m, n);

		cout << "\n" << "Tong cac so nguyen dang 5^m la: ";
		cout << setw(8) << kq;

		FileName = getOutputFileName(i);
		Xuat(a, m, n, FileName);
	}

	return 0;
}


string getInputFileName(int n)
{
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

string getOutputFileName(int n)
{
	string fileName = string("intmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
}

void Nhap(int a[][500], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(int a[][500], int m, int n, string filename)
{
	ofstream fo(filename);
	fo << setw(8) << m;
	fo << setw(8) << n;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << a[i][j];
		fo << "\n";
	}
}

void Xuat(int a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(8) << a[i][j];
		cout << endl;
	}
}

bool Kt5m(int n)
{
	bool flag = true;
	if (n < 0)
		return false;
	while (n > 1)
	{
		int du = n % 5;
		if (du != 0)
			flag = false;
		n = n / 5;
	}
	return flag;
}

int Tong5m(int a[][500], int m, int n)
{
	int s = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (Kt5m(a[i][j]) == true)
				s = s + a[i][j];
	return s;
}

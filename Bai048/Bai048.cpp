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
int TongBien(int[][500], int, int);
bool ktChinhPhuong(int);

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

		cout << "Tong cac gia tri nam tren bien: " << TongBien(a, m, n);

		FileName = getOutputFileName(i);
		Xuat(a, m, n, FileName);
	}
	return 0;;
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

bool ktChinhPhuong(int k)
{
	bool flag = false;
	for (int i = 0; i <= k; i++)
		if (i * i == k)
			flag = true;
	return flag;
}

int TongBien(int a[][500], int m, int n)
{
	int s = 0;
	for (int j = 0; j < n - 1; j++)
		if (ktChinhPhuong(a[0][j]) == true)
			s = s + a[0][j];
	for (int i = 0; i < m - 1; i++)
		if (ktChinhPhuong(a[i][n - 1]) == true)
			s = s + a[i][n - 1];
	for (int j = n - 1; j > 0; j--)
		if (ktChinhPhuong(a[m - 1][j]) == true)
			s = s + a[m - 1][j];
	for (int i = m - 1; i > 0; i--)
		if (ktChinhPhuong(a[i][n - 1]) == true)
			s = s + a[i][n - 1];
	return s;
}
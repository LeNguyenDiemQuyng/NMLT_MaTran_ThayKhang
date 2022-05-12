#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

string getInputFileName(int);
string getOutputFileName(int);
void Nhap(float[][500], int&, int&, string);
void Xuat(float[][500], int, int, string);
void Xuat(float[][500], int, int);
float TongDuong(float[][500], int, int, int);

int main()
{

	float a[500][500];
	int m;
	int n;
	int d;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(a, m, n, FileName);

		cout << "\n" << FileName << endl;
		Xuat(a, m, n);

		cout << "\nNhap dong muon tinh tong: ";
		cin >> d;

		float kq = TongDuong(a, m, n, d);
		cout << setw(8) << setprecision(5);
		cout << "\n" << "Tong cac so duong tren dong " << d << " la: " << kq << endl;

		FileName = getOutputFileName(i);
		Xuat(a, m, n, FileName);
	}
	return 1;
}

string getInputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".inp";
	else
		fileName += to_string(n) + ".inp";
	return fileName;
}

string getOutputFileName(int n)
{
	string fileName = string("floatmatrandata");
	if (n < 10)
		fileName += "0" + to_string(n) + ".out";
	else
		fileName += to_string(n) + ".out";
	return fileName;
}

void Nhap(float a[][500], int& m, int& n, string filename)
{
	ifstream fi(filename);
	fi >> m;
	fi >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fi >> a[i][j];
}

void Xuat(float a[][500], int m, int n, string filename)
{
	ofstream fo(filename);
	fo << setw(8) << m;
	fo << setw(8) << n;
	fo << "\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			fo << setw(8) << setprecision(5) << a[i][j];
		fo << "\n";
	}
}

void Xuat(float a[][500], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(8);
			cout << setprecision(3);
			cout << a[i][j];
		}
		cout << "\n";
	}
}

float TongDuong(float a[][500], int m, int n, int d)
{
	int s = 0;
	for (int j = 0; j < n; ++j)
		if (a[d][j] > 0)
			s = s + a[d][j];
	return s;
}
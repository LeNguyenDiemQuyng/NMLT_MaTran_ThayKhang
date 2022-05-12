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
bool ktCucTieu(float[][500], int, int, int, int);
float TongCucTieu(float[][500], int, int);


int main()
{
	float a[500][500];
	int m, n, d;
	for (int i = 1; i <= 1; i++)
	{
		string FileName = getInputFileName(i);
		Nhap(a, m, n, FileName);

		cout << "\n" << FileName << endl;
		Xuat(a, m, n);

		cout << "\nTong cac phan tu cuc tieu la: " << TongCucTieu(a, m, n);

		FileName = getOutputFileName(i);
		Xuat(a, m, n, FileName);
	}

	return 0;
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

bool ktCucTieu(float a[][500], int n, int m, int d, int c)
{
	if (d != 0)
	{
		if (c != 0)
			if (a[d - 1][c - 1] < a[d][c])
				return 0;
		if (a[d - 1][c] < a[d][c])
			return 0;
		if (c != m - 1)
			if (a[d - 1][c + 1] < a[d][c])
				return 0;
	}
	if (c != 0)
		if (a[d][c - 1] < a[d][c])
			return 0;
	if (c != m - 1)
		if (a[d][c + 1] < a[d][c])
			return 0;
	if (d != m - 1)
	{
		if (c != 0)
			if (a[d + 1][c - 1] < a[d][c])
				return 0;
		if (a[d + 1][c] < a[d][c])
			return 0;
		if (c != m - 1)
			if (a[d + 1][c + 1] < a[d][c])
				return 0;
	}
	return 1;
}
float TongCucTieu(float a[][500], int n, int m)
{
	float s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (ktCucTieu(a, n, m, i, j))
				s += a[i][j];
	return s;
}
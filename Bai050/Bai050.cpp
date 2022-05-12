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
float TongCucDai(float[][500], int, int);
bool ktCucDai(float[][500], int, int, int, int);

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

		cout << "\nTong cac phan tu cuc dai la: " << TongCucDai(a, m, n);

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

float TongCucDai(float a[][500], int m, int n)
{
	float sum = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (ktCucDai(a, m, n, i, j))
				sum += a[i][j];
	return sum;
}

bool ktCucDai(float a[][500], int m, int n, int x, int y)
{
	float check = a[x][y];
	for (int i = x - 1; i <= x + 1; i++)
	{
		if (i < 0 || i > m - 1)
			continue;
		for (int j = y - 1; j <= y + 1; j++)
		{
			if (j < 0 || j > n - 1 || (i == x && j == y))
				continue;
			if (check <= a[i][j])
				return 0;
		}
	}
	return 1;
}
#include<iostream>

using namespace std;

void line(int kol, char c)
{
	for (int i = 0;i < kol;i++) cout << c;
	cout << '\n';
}

void fline(FILE* f, int kol, char c)
{
	for (int i = 0;i < kol;i++) fprintf_s(f, "%1c", c);
	fprintf_s(f, "\n");
}
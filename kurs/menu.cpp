#include<iostream>
#include<iomanip>

using namespace std;

short menu2();
short write();
short add();
short unadd();
short raschet();
void line(int, char);

short Vibor;

int main()
{
	setlocale(LC_CTYPE, "");
	system("chcp 1251");
	system("cls");
	system("color f0");
	while (1)
	{
		line(23, '=');
		cout << "|1* :    �����������  |\n";
		cout << "|2* :     ���������   |\n";
		cout << "|3  : ��������� ������|\n";
		line(23, '=');
		cout << "\n  �������� ��������: ";
		cin >> Vibor;
		switch (Vibor)
		{
		case 1:Vibor = 10, menu2(); break;
		case 2:Vibor = 7, menu2(); break;
		case 3:system("cls");return 0; break;
		default:cout << "  ����� �������� ���\n"; break;
		}
	}
	return 0;
}

short menu2()
{
	short vibormenu2;
	system("cls");
	while (1)
	{
		line(24, '=');
		cout << "|1  :   ����� ������   |\n";
		cout << "|2  : ���������� ������|\n";
		cout << "|3  :  �������� ������ |\n";
		cout << "|4* : ����� �����������|\n";
		cout << "|5  :       �����      |\n";
		line(24, '=');
		cout << "\n  �������� ��������: ";
		cin >> vibormenu2;
		switch (vibormenu2)
		{
		case 1:write(); break;
		case 2:add(); break;
		case 3:unadd(); break;
		case 4:raschet(); break;
		case 5:system("cls");return 0; break;
		default:cout << "  ����� �������� ���\n"; break;
		}
	}
}
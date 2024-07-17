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
		cout << "|1* :    Десятиборье  |\n";
		cout << "|2* :     Семиборье   |\n";
		cout << "|3  : Закончить работу|\n";
		line(23, '=');
		cout << "\n  Выберите операцию: ";
		cin >> Vibor;
		switch (Vibor)
		{
		case 1:Vibor = 10, menu2(); break;
		case 2:Vibor = 7, menu2(); break;
		case 3:system("cls");return 0; break;
		default:cout << "  Таких операций нет\n"; break;
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
		cout << "|1  :   Новый список   |\n";
		cout << "|2  : Дополнение списка|\n";
		cout << "|3  :  Удаление записи |\n";
		cout << "|4* : Вывод победителей|\n";
		cout << "|5  :       Назад      |\n";
		line(24, '=');
		cout << "\n  Выберите операцию: ";
		cin >> vibormenu2;
		switch (vibormenu2)
		{
		case 1:write(); break;
		case 2:add(); break;
		case 3:unadd(); break;
		case 4:raschet(); break;
		case 5:system("cls");return 0; break;
		default:cout << "  Таких операций нет\n"; break;
		}
	}
}
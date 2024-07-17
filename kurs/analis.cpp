#include<iostream>
#include<iomanip>
#include "struct.h"

using namespace std;

short sort(short,int,int);
short sortnomer(int, int);
void nomer(int, int);
short pois();
short vopros();
void line(int, char);

extern FILE* fail_nach;
FILE* fail_itog;
extern short Vibor;

extern sem sport;
sem sport1;
extern perem znach[3];
extern perem a;

short raschet()
{
	system("cls");
	FILE* fail_rashet;
	float itog, peremen, itogitog, f, b, c;
	short vibormenu;
	int nomervstav=-1, nomerstr, kolstr=-1, kolj=0;
	fopen_s(&fail_rashet, "Значения для расчета.txt", "r");
	fopen_s(&fail_itog, "Предворительная таблица.txt", "w");
	if (Vibor == 7)
	{
		fopen_s(&fail_nach, "Информация по спортсменам семиборья.txt", "r");

	}
	else fopen_s(&fail_nach, "Информация по спортсменам десятиборья.txt", "r");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла\n";
		return 1;
	}
	if (fail_rashet == NULL)
	{
		cout << "Ошибка открытия  файла: Значения для расчета.txt.txt\n";
		return 1;
	}
	if (fail_itog == NULL)
	{
		cout << "Ошибка открытия  файла: Предворительная таблица.txt\n";
		return 1;
	}


	while (!feof(fail_nach))
	{
		kolstr++;
		if (Vibor == 7) fseek(fail_rashet, 242, 0);
		else fseek(fail_rashet, 0, 0);
		sport.Itog=0;
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
		if (sport.Pol == 'Ж' || sport.Pol == 'ж')kolj++;
		while ((!feof(fail_rashet)) && (!(ftell(fail_rashet) == 244)))
		{
			fscanf_s(fail_nach, " %7f", &peremen);
			fscanf_s(fail_rashet, "%9f %6f %5f\n", &f, &b, &c);
			itog = f * pow(fabs(peremen - b), c);
			itog = round(itog * pow(10, 2)) / pow(10, 2);
			fprintf_s(fail_itog, " %7.2f (%7.2f)", peremen, itog);
			sport.Itog += itog;
		}
		sport.Itog = round(sport.Itog * pow(10, 2)) / pow(10, 2);
		fprintf_s(fail_itog, " %8.2f\n", sport.Itog);
		fscanf_s(fail_nach, "\n");
	}
	fclose(fail_rashet);
	fclose(fail_nach);
	fclose(fail_itog);

	if (Vibor == 7)
	{
		fopen_s(&fail_itog, "Предворительная таблица.txt", "r+");
		while (!feof(fail_itog))
		{
			fseek(fail_itog, (nomervstav + 1) * 201, 0);
			do {
				nomervstav++;
				fscanf_s(fail_itog, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
				fscanf_s(fail_itog, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
				fscanf_s(fail_itog, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &znach[0].Beg_Malo, &sport.a.Beg_Bar, &znach[0].Beg_Bar);
				fscanf_s(fail_itog, " %7f (%7f) %7f", &sport.a.Beg_Mnogo, &znach[0].Beg_Mnogo, &sport.a.Prij_D);
				fscanf_s(fail_itog, " (%7f) %7f (%7f) %7f", &znach[0].Prij_D, &sport.a.Prij_V, &znach[0].Prij_V, &sport.a.Met_Ia);
				fscanf_s(fail_itog, " (%7f) %7f (%7f)", &znach[0].Met_Ia, &sport.a.Shest_Kopio, &znach[0].Shest_Kopio);
				if (Vibor == 10) {
					fscanf_s(fail_itog, " %7f (%7f) %7f", &sport.a.Beg_Sred, &znach[0].Beg_Sred, &sport.a.Kopio_M);
					fscanf_s(fail_itog, " (%7f) %7f (%7f)", &znach[0].Kopio_M, &sport.a.Met_D, &znach[0].Met_D);
				}
				fscanf_s(fail_itog, " %8f\n", &sport.Itog);
			} while ((!feof(fail_itog)) && !((sport.Pol == 'М') || (sport.Pol == 'м')));
			nomerstr = nomervstav;
			do {
				nomerstr++;
				fscanf_s(fail_itog, "%4i %s %s", &sport1.Nomer, sport1.Surname, sizeof(sport.Surname), sport1.Name, sizeof(sport.Name));
				fscanf_s(fail_itog, " %s %c", sport1.Patronymic, sizeof(sport.Patronymic), &sport1.Pol, 1);
				fscanf_s(fail_itog, " %7f (%7f) %7f (%7f)", &sport1.a.Beg_Malo, &znach[1].Beg_Malo, &sport1.a.Beg_Bar, &znach[1].Beg_Bar);
				fscanf_s(fail_itog, " %7f (%7f) %7f", &sport1.a.Beg_Mnogo, &znach[1].Beg_Mnogo, &sport1.a.Prij_D);
				fscanf_s(fail_itog, " (%7f) %7f (%7f) %7f", &znach[1].Prij_D, &sport1.a.Prij_V, &znach[1].Prij_V, &sport1.a.Met_Ia);
				fscanf_s(fail_itog, " (%7f) %7f (%7f)", &znach[1].Met_Ia, &sport1.a.Shest_Kopio, &znach[1].Shest_Kopio);
				if (Vibor == 10) {
					fscanf_s(fail_itog, " %7f (%7f) %7f", &sport1.a.Beg_Sred, &znach[1].Beg_Sred, &sport1.a.Kopio_M);
					fscanf_s(fail_itog, " (%7f) %7f (%7f)", &znach[1].Kopio_M, &sport1.a.Met_D, &znach[1].Met_D);
				}
				fscanf_s(fail_itog, " %8f\n", &sport1.Itog);
				if (sport1.Pol == 'Ж' || sport1.Pol == 'ж')
				{
					fseek(fail_itog, nomerstr * 201, 0);
					fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
					fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f (%7.2f)", sport.a.Beg_Malo, znach[0].Beg_Malo, sport.a.Beg_Bar, znach[0].Beg_Bar);
					fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", sport.a.Beg_Mnogo, znach[0].Beg_Mnogo, sport.a.Prij_D);
					fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[0].Prij_D, sport.a.Prij_V, znach[0].Prij_V, sport.a.Met_Ia);
					fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[0].Met_Ia, sport.a.Shest_Kopio, znach[0].Shest_Kopio);
					if (Vibor == 10) {
						fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", sport.a.Beg_Sred, znach[0].Beg_Sred, sport.a.Kopio_M);
						fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[0].Kopio_M, sport.a.Met_D, znach[0].Met_D);
					}
					fprintf_s(fail_itog, " %8.2f\n", sport.Itog);

					fseek(fail_itog, nomervstav * 201, 0);
					fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", sport1.Nomer, sport1.Surname, sport1.Name, sport1.Patronymic, sport1.Pol);
					fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f (%7.2f)", sport1.a.Beg_Malo, znach[1].Beg_Malo, sport1.a.Beg_Bar, znach[1].Beg_Bar);
					fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", sport1.a.Beg_Mnogo, znach[1].Beg_Mnogo, sport1.a.Prij_D);
					fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[1].Prij_D, sport1.a.Prij_V, znach[1].Prij_V, sport1.a.Met_Ia);
					fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[1].Met_Ia, sport1.a.Shest_Kopio, znach[1].Shest_Kopio);
					if (Vibor == 10) {
						fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", sport1.a.Beg_Sred, znach[1].Beg_Sred, sport1.a.Kopio_M);
						fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[1].Kopio_M, sport1.a.Met_D, znach[1].Met_D);
					}
					fprintf_s(fail_itog, " %8.2f\n", sport1.Itog);
				}
			} while ((!feof(fail_itog)) && !((sport1.Pol == 'Ж') || (sport1.Pol == 'ж')));
		}
		fclose(fail_itog);
	}

	if (Vibor == 7)
	{
		sortnomer(0, kolj - 1);
		sortnomer(kolj, kolstr);
		fopen_s(&fail_nach, "Предворительная таблица.txt", "r");
		fopen_s(&fail_itog, "Замена.txt", "w");
		nomer(0, kolj);
		nomer(kolj , kolstr+1);
		fclose(fail_itog);
		fclose(fail_nach);
		remove("Предворительная таблица.txt");
		rename("Замена.txt", "Предворительная таблица.txt");
	}
	else
	{
		sortnomer(0, kolstr);
		fopen_s(&fail_nach, "Предворительная таблица.txt", "r");
		fopen_s(&fail_itog, "Замена.txt", "w");
		nomer(0, kolstr+1);
		fclose(fail_itog);
		fclose(fail_nach);
		remove("Предворительная таблица.txt");
		rename("Замена.txt", "Предворительная таблица.txt");
	}

	fopen_s(&fail_nach, "Предворительная таблица.txt", "r");
	if (Vibor == 7)
	{
		printf_s( "_________________________________________________________________________________ЧЕМПИОНЫ__________________________________________________________________________________\n");
		printf_s( "|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Прыжок Ш.(м)/Мет. Коп.(ж)|  Итог  |\n");
		vibormenu = 171;
	}
	else
	{
		printf_s("__________________________________________________________________________________________ЧЕМПИОНЫ_______________________________________________________________________________________\n");
		printf_s("|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Сред.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Мет. Коп|Мет. Диска|Прыжок Ш.|  Итог  |\n");
		vibormenu = 185;
	}
	do
	{
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &a.Beg_Malo, &sport.a.Beg_Bar, &a.Beg_Bar);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Mnogo, &a.Beg_Mnogo, &sport.a.Prij_D, &a.Prij_D);
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Prij_V, &a.Prij_V, &sport.a.Met_Ia);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Met_Ia, &sport.a.Shest_Kopio, &a.Shest_Kopio);
		if (Vibor == 10) {
			fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &a.Beg_Sred, &sport.a.Kopio_M);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Kopio_M, &sport.a.Met_D, &a.Met_D);
		}
		fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);
		if (sport.Pobed < 4)
		{
			line(vibormenu, '-');
			if (Vibor == 10)
			{
				printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
				printf_s("| %7.2f  | %7.2f  | %7.2f  ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Sred);
				printf_s("| %7.2f | %7.2f | %7.2f", sport.a.Beg_Mnogo, sport.a.Prij_D, sport.a.Prij_V);
				printf_s("| %7.2f |%7.2f | %7.2f  ", sport.a.Met_Ia, sport.a.Kopio_M, sport.a.Met_D);
				printf_s("|%7.2f  |%8.2f|\n", sport.a.Shest_Kopio, sport.Itog);
				printf_s("|     |    |                    |               |                    |   ");
				printf_s("| %7.2f  | %7.2f  | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Sred);
				printf_s("| %7.2f | %7.2f | %7.2f ", a.Beg_Mnogo, a.Prij_D, a.Prij_V);
				printf_s("| %7.2f |%7.2f | %7.2f  |%7.2f  |        |\n", a.Met_Ia, a.Kopio_M, a.Met_D, a.Shest_Kopio);
			}
			else
			{
				printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
				printf_s("| %7.2f  | %7.2f  | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo);
				printf_s("| %7.2f | %7.2f ", sport.a.Prij_D, sport.a.Prij_V);
				printf_s("| %7.2f |        %7.2f          |%8.2f|\n", sport.a.Met_Ia, sport.a.Shest_Kopio, sport.Itog);
				printf_s("|     |    |                    |               |                    |   |");
				printf_s(" %7.2f  | %7.2f  | %7.2f | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Mnogo, a.Prij_D);
				printf_s("| %7.2f | %7.2f |        %7.2f          |        |\n", a.Prij_V, a.Met_Ia, a.Shest_Kopio);
			}
		}
	} while (!feof(fail_nach));
	line(vibormenu, '=');
	fclose(fail_nach);

	while (1)
	{
		line(23,'=');
		cout << "|1  :       Поиск     |\n";
		cout << "|2  :   Сортировка \\/ |\n";
		cout << "|3  :   Сортировка /\\ |\n";
		cout << "|4  :  Сортировка а-я |\n";
		cout << "|5  :  Сортировка я-а |\n";
		cout << "|6  :       Назад     |\n";
		line(23, '=');
		cout << "\n Выберите операцию: ";
		cin >> vibormenu;
		switch (vibormenu)
		{
		case 1:pois(); break;
		case 2:if (Vibor == 10)sort(1, 0, kolstr);
			  else { sort(1, 0, kolj - 1);sort(1, kolj, kolstr); } vopros(); break;
		case 3:if(Vibor==10)sort(0,0,kolstr);
			  else { sort(0, 0, kolj - 1);sort(0, kolj, kolstr);} vopros(); break;
		case 4:if (Vibor == 10)sort(3, 0, kolstr);
			  else { sort(3, 0, kolj - 1);sort(3, kolj, kolstr); } vopros(); break;
		case 5:if (Vibor == 10)sort(2, 0, kolstr);
			  else { sort(2, 0, kolj - 1);sort(2, kolj, kolstr); } vopros(); break;
		case 6:system("cls");return 0; break;
		default:cout << "  Таких операций нет\n"; break;
		}
	}
}
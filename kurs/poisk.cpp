#include<iostream>
#include<iomanip>
#include<string>
#include "struct.h"

using namespace std;

void line(int, char);

extern FILE* fail_nach;

extern short Vibor;
extern sem sport;
perem a;

short pois()
{
	char fam[20];
	int nom, Otstup;
	fopen_s(&fail_nach, "Предворительная таблица.txt", "r");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла: Предворительная таблица.txt\n";
		return 1;
	}
	cout << "Введите фамилию спортсмена или его номер" << "\n\t";
	cin.ignore();
	cin.getline(fam, 20, '\n');
	if (Vibor == 10)
	{
		printf_s("_______________________________________________________________________________________ПОИСК____________________________________________________________________________________\n");
		printf_s("|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Сред.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Мет. Коп|Мет. Диска|Прыжок Ш.|  Итог  |\n");
		Otstup = 185;
	}
	else
	{
		printf_s( "__________________________________________________________________________________ПОИСК____________________________________________________________________________________\n");
		printf_s( "|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Прыжок Ш.(м)/Мет. Коп.(ж)|  Итог  |\n");
		Otstup = 171;
	}
	if (isdigit(fam[0])) {
		nom = atoi(fam);
		while (!feof(fail_nach))
		{
			fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &a.Beg_Malo, &sport.a.Beg_Bar, &a.Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Mnogo, &a.Beg_Mnogo, &sport.a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &a.Prij_D, &sport.a.Prij_V, &a.Prij_V, &sport.a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Met_Ia, &sport.a.Shest_Kopio, &a.Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &a.Beg_Sred, &sport.a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Kopio_M, &sport.a.Met_D, &a.Met_D);
			}
			fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);
			if (sport.Nomer == nom)
			{
				line(Otstup, '-');
				if (Vibor == 10)
				{
					printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
					printf_s("| %7.2f  | %7.2f  | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Sred);
					printf_s("| %7.2f | %7.2f | %7.2f ", sport.a.Beg_Mnogo, sport.a.Prij_D, sport.a.Prij_V);
					printf_s("| %7.2f |%7.2f | %7.2f  |%7.2f  |%8.2f|\n", sport.a.Met_Ia, sport.a.Kopio_M, sport.a.Met_D, sport.a.Shest_Kopio, sport.Itog);
					printf_s("|     |    |                    |               |                    |   | ");
					printf_s("%7.2f  | %7.2f  | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Sred);
					printf_s("| %7.2f | %7.2f | %7.2f ", a.Beg_Mnogo, a.Prij_D, a.Prij_V);
					printf_s("| %7.2f |%7.2f ", a.Met_Ia, a.Kopio_M);
					printf_s("| %7.2f  |%7.2f  |        |\n", a.Met_D, a.Shest_Kopio);
				}
				else
				{
					printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
					printf_s("| %7.2f  | %7.2f  | %7.2f | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
					printf_s("| %7.2f | %7.2f |        %7.2f          |%8.2f|\n", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio, sport.Itog);
					printf_s("|     |    |                    |               |                    |   |");
					printf_s(" %7.2f  | %7.2f  | %7.2f | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Mnogo, a.Prij_D);
					printf_s("| %7.2f | %7.2f |         %7.2f         |        |\n", a.Prij_V, a.Met_Ia, a.Shest_Kopio);
				}
				break;
			}
		}
	}
	else
	{
		while (!feof(fail_nach))
		{
			fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol,1 ); 
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &a.Beg_Malo, &sport.a.Beg_Bar, &a.Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Mnogo, &a.Beg_Mnogo, &sport.a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &a.Prij_D, &sport.a.Prij_V, &a.Prij_V, &sport.a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Met_Ia, &sport.a.Shest_Kopio, &a.Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &a.Beg_Sred, &sport.a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Kopio_M, &sport.a.Met_D, &a.Met_D);
			}	
			fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);
			if (strcmp(fam, sport.Surname)==0)
			{
				line(Otstup, '-');
				if (Vibor == 10)
				{
					printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
					printf_s("| %7.2f  | %7.2f  | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Sred);
					printf_s("| %7.2f | %7.2f | %7.2f ", sport.a.Beg_Mnogo, sport.a.Prij_D, sport.a.Prij_V);
					printf_s("| %7.2f |%7.2f | %7.2f  ", sport.a.Met_Ia, sport.a.Kopio_M, sport.a.Met_D);
					printf_s("|%7.2f  |%8.2f|\n", sport.a.Shest_Kopio, sport.Itog);
					printf_s("|     |    |                    |               |                    |   | ");
					printf_s("%7.2f  | %7.2f  | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Sred);
					printf_s("| %7.2f | %7.2f | %7.2f ", a.Beg_Mnogo, a.Prij_D, a.Prij_V);
					printf_s("| %7.2f |%7.2f | %7.2f  |%7.2f  |        |\n", a.Met_Ia, a.Kopio_M, a.Met_D, a.Shest_Kopio);
				}
				else
				{
					printf_s("|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
					printf_s("| %7.2f  | %7.2f  | %7.2f | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
					printf_s("| %7.2f | %7.2f |        %7.2f          |%8.2f|\n", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio, sport.Itog);
					printf_s("|     |    |                    |               |                    |   |");
					printf_s(" %7.2f  | %7.2f  | %7.2f | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Mnogo, a.Prij_D);
					printf_s("| %7.2f | %7.2f |        %7.2f          |        |\n", a.Prij_V, a.Met_Ia, a.Shest_Kopio);
				}
			}
		}
	}
	line(Otstup, '=');
	fclose(fail_nach);
}
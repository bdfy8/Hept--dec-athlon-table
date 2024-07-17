#include<iostream>
#include<iomanip>
#include "struct.h"

using namespace std;

void fline(FILE*, int, char);
void zapis7();
void zapis10();

extern FILE* fail_nach;
extern FILE* fail_itog;
extern short Vibor;

extern sem sport;
extern perem a;

short vopros()
{
	system("cls");
	char otvet, s[25];
	cout << "Хотите записать эти данные?" << '\n';
	cout << "     д-да/н-нет" << "\n\t";
	cin >> otvet;
	if (otvet == 'д')
	{
		cout << "Введите имя файла с расширением" << '\n';
		cin.ignore();
		cout << '\t';
		cin.getline(s, 25, '\n');
		fopen_s(&fail_nach, "Предворительная таблица.txt", "r");
		if (fail_nach == NULL)
		{
			cout << "Ошибка открытия  файла: Предворительная таблица.txt\n";
			return 1;
		}
		fopen_s(&fail_itog, s, "w");
		if (fail_itog == NULL)
		{
			cout << "Ошибка открытия  файла: " << s << '\n';
			return 1;
		}
		if (Vibor == 7)zapis7();
		else zapis10();
	}
	system("cls");
	fclose(fail_itog);
	fclose(fail_nach);
}

void zapis7()
{

	fprintf_s(fail_itog, "_____________________________________________________________________________ИТОГОВАЯ_ТАБЛИЦА______________________________________________________________________________\n");
	fprintf_s(fail_itog, "|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Прыжок Ш.(м)/Мет. Коп.(ж)|  Итог  |\n");
	while (!feof(fail_nach))
	{
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &a.Beg_Malo, &sport.a.Beg_Bar, &a.Beg_Bar);
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Mnogo, &a.Beg_Mnogo, &sport.a.Prij_D);
		fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &a.Prij_D, &sport.a.Prij_V, &a.Prij_V, &sport.a.Met_Ia);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Met_Ia, &sport.a.Shest_Kopio, &a.Shest_Kopio);
		fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);

		fline(fail_itog, 171, '-');
		fprintf_s(fail_itog, "|%4i |%4i|%20s|%15s|%20s| %1c ", sport.Pobed, sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
		fprintf_s(fail_itog, "| %7.2f  | %7.2f  | %7.2f | %7.2f ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
		fprintf_s(fail_itog, "| %7.2f | %7.2f |         %7.2f         |%8.2f|\n", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio, sport.Itog);
		fprintf_s(fail_itog, "|     |    |                    |               |                    |   ");
		fprintf_s(fail_itog, "| %7.2f  | %7.2f  | %7.2f | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Mnogo, a.Prij_D);
		fprintf_s(fail_itog, "| %7.2f | %7.2f |         %7.2f         |        |\n", a.Prij_V, a.Met_Ia, a.Shest_Kopio);
	}
	fline(fail_itog, 171, '=');
}

void zapis10()
{
	fprintf_s(fail_itog, "______________________________________________________________________________________ИТОГОВАЯ_ТАБЛИЦА___________________________________________________________________________________\n");
	fprintf_s(fail_itog, "|Место|  № |      Фамилия       |      Имя      |      Отчество      |Пол|Бег Корот.|Бег с Бар.|Бег Сред.|Бег Длин.|Прыжок Д.|Прыжок В.|Мет. Ядра|Мет. Коп|Мет. Диска|Прыжок Ш.|  Итог  |\n");
	while (!feof(fail_nach))
	{
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &a.Beg_Malo, &sport.a.Beg_Bar, &a.Beg_Bar);
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Mnogo, &a.Beg_Mnogo, &sport.a.Prij_D);
		fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &a.Prij_D, &sport.a.Prij_V, &a.Prij_V, &sport.a.Met_Ia);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Met_Ia, &sport.a.Shest_Kopio, &a.Shest_Kopio);
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &a.Beg_Sred, &sport.a.Kopio_M);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &a.Kopio_M, &sport.a.Met_D, &a.Met_D);
		fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);

		fline(fail_itog, 185, '-');
		fprintf_s(fail_itog, "|%4i |%4i|%20s ", sport.Pobed, sport.Nomer, sport.Surname);
		fprintf_s(fail_itog, "|%15s|%20s| %1c", sport.Name, sport.Patronymic, sport.Pol);
		fprintf_s(fail_itog, "| %7.2f  | %7.2f  | %7.2f  ", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Sred);
		fprintf_s(fail_itog, "| %7.2f | %7.2f | %7.2f", sport.a.Beg_Mnogo, sport.a.Prij_D, sport.a.Prij_V);
		fprintf_s(fail_itog, "| %7.2f |%7.2f | %7.2f  ", sport.a.Met_Ia, sport.a.Kopio_M, sport.a.Met_D);
		fprintf_s(fail_itog, "|%7.2f  |%8.2f|\n", sport.a.Shest_Kopio, sport.Itog);
		fprintf_s(fail_itog, "|     |    |                    |               |                    |   ");
		fprintf_s(fail_itog, "| %7.2f  | %7.2f  | %7.2f ", a.Beg_Malo, a.Beg_Bar, a.Beg_Sred);
		fprintf_s(fail_itog, "| %7.2f | %7.2f | %7.2f ", a.Beg_Mnogo, a.Prij_D, a.Prij_V);
		fprintf_s(fail_itog, "| %7.2f |%7.2f ", a.Met_Ia, a.Kopio_M);
		fprintf_s(fail_itog, "| %7.2f  |%7.2f  |        |\n", a.Met_D, a.Shest_Kopio);
	}
	fline(fail_itog, 185, '=');
}
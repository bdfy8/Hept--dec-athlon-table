#include<iostream>
#include<iomanip>
#include "struct.h"

using namespace std;

extern FILE* fail_nach;
extern FILE* fail_itog;
extern short Vibor;

extern sem sport;
sem per[2];
perem znach[3];

short sort(short ai,int low, int high)
{
	bool virajen;
	int i = low, j = high;
	fopen_s(&fail_nach, "Предворительная таблица.txt", "r+");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла: Предворительная таблица.txt\n";
		return 1;
	}
	int pivot = (i + j) / 2;
	if (Vibor == 7) fseek(fail_nach, pivot * 206, 0);
	else fseek(fail_nach, pivot * 260, 0);
	fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
	fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
	fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &znach[0].Beg_Malo, &sport.a.Beg_Bar, &znach[0].Beg_Bar);
	fscanf_s(fail_nach, " %7f (%7f) %7f ", &sport.a.Beg_Mnogo, &znach[0].Beg_Mnogo, &sport.a.Prij_D);
	fscanf_s(fail_nach, "(%7f) %7f (%7f) %7f", &znach[0].Prij_D, &sport.a.Prij_V, &znach[0].Prij_V, &sport.a.Met_Ia);
	fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[0].Met_Ia, &sport.a.Shest_Kopio, &znach[0].Shest_Kopio);
	if (Vibor == 10) {
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &znach[0].Beg_Sred, &sport.a.Kopio_M);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[0].Kopio_M, &sport.a.Met_D, &znach[0].Met_D);
	}
	fscanf_s(fail_nach, " %8f %4i\n", &sport.Itog, &sport.Pobed);
	while (i <= j)
	{
		do {
			if (Vibor == 7) fseek(fail_nach, i * 206, 0);
			else fseek(fail_nach, i * 260, 0);
			i++;
			fscanf_s(fail_nach, "%4i %s %s", &per[0].Nomer, per[0].Surname, sizeof(sport.Surname), per[0].Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", per[0].Patronymic, sizeof(sport.Patronymic), &per[0].Pol, 1);
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &per[0].a.Beg_Malo, &znach[1].Beg_Malo, &per[0].a.Beg_Bar, &znach[1].Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Mnogo, &znach[1].Beg_Mnogo, &per[0].a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &znach[1].Prij_D, &per[0].a.Prij_V, &znach[1].Prij_V, &per[0].a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Met_Ia, &per[0].a.Shest_Kopio, &znach[1].Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Sred, &znach[1].Beg_Sred, &per[0].a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Kopio_M, &per[0].a.Met_D, &znach[1].Met_D);
			}
			fscanf_s(fail_nach, " %8f %4i\n", &per[0].Itog, &per[0].Pobed);

			if (ai == 0) virajen = (sport.Itog > per[0].Itog);
			if (ai == 1) virajen = (sport.Itog < per[0].Itog);
			if (ai == 2) virajen = strcmp(sport.Surname, per[0].Surname)==1;
			if (ai == 3) virajen = strcmp(per[0].Surname, sport.Surname)==1;
		} while (virajen);
		do {
			if (Vibor == 7) fseek(fail_nach, j * 206, 0);
			else fseek(fail_nach, j * 260, 0);
			j--;
			fscanf_s(fail_nach, "%4i %s %s", &per[1].Nomer, per[1].Surname, sizeof(sport.Surname), per[1].Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", per[1].Patronymic, sizeof(sport.Patronymic), &per[1].Pol, 1);
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &per[1].a.Beg_Malo, &znach[2].Beg_Malo, &per[1].a.Beg_Bar, &znach[2].Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &per[1].a.Beg_Mnogo, &znach[2].Beg_Mnogo, &per[1].a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &znach[2].Prij_D, &per[1].a.Prij_V, &znach[2].Prij_V, &per[1].a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[2].Met_Ia, &per[1].a.Shest_Kopio, &znach[2].Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &per[1].a.Beg_Sred, &znach[2].Beg_Sred, &per[1].a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[2].Kopio_M, &per[1].a.Met_D, &znach[2].Met_D);
			}
			fscanf_s(fail_nach, " %8f %4i\n", &per[1].Itog, &per[1].Pobed);

			if (ai == 0) virajen = (sport.Itog < per[1].Itog);
			if (ai == 1) virajen = (sport.Itog > per[1].Itog);
			if (ai == 2) virajen = strcmp(per[1].Surname,sport.Surname)==1;
			if (ai == 3) virajen = strcmp(sport.Surname, per[1].Surname)==1;
		} while (virajen);
		if (--i <= ++j)
		{
			if (Vibor == 7) fseek(fail_nach, i * 206, 0);
			else fseek(fail_nach, i  * 260, 0);
			fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", per[1].Nomer, per[1].Surname, per[1].Name, per[1].Patronymic, per[1].Pol);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f)", per[1].a.Beg_Malo, znach[2].Beg_Malo, per[1].a.Beg_Bar, znach[2].Beg_Bar);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[1].a.Beg_Mnogo, znach[2].Beg_Mnogo, per[1].a.Prij_D);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[2].Prij_D, per[1].a.Prij_V, znach[2].Prij_V, per[1].a.Met_Ia);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[2].Met_Ia, per[1].a.Shest_Kopio, znach[2].Shest_Kopio);
			if (Vibor == 10) {
				fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[1].a.Beg_Sred, znach[2].Beg_Sred, per[1].a.Kopio_M);
				fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[2].Kopio_M, per[1].a.Met_D, znach[2].Met_D);
			}
			fprintf_s(fail_nach, " %8.2f %4i\n", per[1].Itog, per[1].Pobed);
			i++;

			if (Vibor == 7) fseek(fail_nach, j * 206, 0);
			else fseek(fail_nach, j * 260, 0);
			fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", per[0].Nomer, per[0].Surname, per[0].Name, per[0].Patronymic, per[0].Pol);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f)", per[0].a.Beg_Malo, znach[1].Beg_Malo, per[0].a.Beg_Bar, znach[1].Beg_Bar);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Mnogo, znach[1].Beg_Mnogo, per[0].a.Prij_D);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[1].Prij_D, per[0].a.Prij_V, znach[1].Prij_V, per[0].a.Met_Ia);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[1].Met_Ia, per[0].a.Shest_Kopio, znach[1].Shest_Kopio);
			if (Vibor == 10) {
				fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Sred, znach[1].Beg_Sred, per[0].a.Kopio_M);
				fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[1].Kopio_M, per[0].a.Met_D, znach[1].Met_D);
			}
			fprintf_s(fail_nach, " %8.2f %4i\n", per[0].Itog, per[0].Pobed);
			j--;
		}
	}
	fclose(fail_nach);
	if (j > low)
		sort(ai, low, j);
	if (i < high)
		sort(ai, i, high);
	
}

short sortnomer(int low, int high)
{
	int i = low, j = high;
	fopen_s(&fail_nach, "Предворительная таблица.txt", "r+");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла: Предворительная таблица.txt\n";
		return 1;
	}
	int pivot = (i + j ) / 2;
	if (Vibor == 7) fseek(fail_nach, pivot * 201, 0);
	else fseek(fail_nach, pivot * 255, 0);
	fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
	fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
	fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &znach[0].Beg_Malo, &sport.a.Beg_Bar, &znach[0].Beg_Bar);
	fscanf_s(fail_nach, " %7f (%7f) %7f ", &sport.a.Beg_Mnogo, &znach[0].Beg_Mnogo, &sport.a.Prij_D);
	fscanf_s(fail_nach, "(%7f) %7f (%7f) %7f", &znach[0].Prij_D, &sport.a.Prij_V, &znach[0].Prij_V, &sport.a.Met_Ia);
	fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[0].Met_Ia, &sport.a.Shest_Kopio, &znach[0].Shest_Kopio);
	if (Vibor == 10) {
		fscanf_s(fail_nach, " %7f (%7f) %7f", &sport.a.Beg_Sred, &znach[0].Beg_Sred, &sport.a.Kopio_M);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[0].Kopio_M, &sport.a.Met_D, &znach[0].Met_D);
	}
	fscanf_s(fail_nach, " %8f\n", &sport.Itog);
	while (i <= j)
	{
		do {
			if (Vibor == 7) fseek(fail_nach, i * 201, 0);
			else fseek(fail_nach, i * 255, 0);
			i++;
			fscanf_s(fail_nach, "%4i %s %s", &per[0].Nomer, per[0].Surname, sizeof(sport.Surname), per[0].Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", per[0].Patronymic, sizeof(sport.Patronymic), &per[0].Pol, 1);
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &per[0].a.Beg_Malo, &znach[1].Beg_Malo, &per[0].a.Beg_Bar, &znach[1].Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Mnogo, &znach[1].Beg_Mnogo, &per[0].a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &znach[1].Prij_D, &per[0].a.Prij_V, &znach[1].Prij_V, &per[0].a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Met_Ia, &per[0].a.Shest_Kopio, &znach[1].Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Sred, &znach[1].Beg_Sred, &per[0].a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Kopio_M, &per[0].a.Met_D, &znach[1].Met_D);
			}
			fscanf_s(fail_nach, " %8f\n", &per[0].Itog);
		} while (sport.Itog < per[0].Itog);
		do {
			if (Vibor == 7) fseek(fail_nach, j * 201, 0);
			else fseek(fail_nach, j * 255, 0);
			j--;
			fscanf_s(fail_nach, "%4i %s %s", &per[1].Nomer, per[1].Surname, sizeof(sport.Surname), per[1].Name, sizeof(sport.Name));
			fscanf_s(fail_nach, " %s %c", per[1].Patronymic, sizeof(sport.Patronymic), &per[1].Pol, 1);
			fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &per[1].a.Beg_Malo, &znach[2].Beg_Malo, &per[1].a.Beg_Bar, &znach[2].Beg_Bar);
			fscanf_s(fail_nach, " %7f (%7f) %7f", &per[1].a.Beg_Mnogo, &znach[2].Beg_Mnogo, &per[1].a.Prij_D);
			fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &znach[2].Prij_D, &per[1].a.Prij_V, &znach[2].Prij_V, &per[1].a.Met_Ia);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[2].Met_Ia, &per[1].a.Shest_Kopio, &znach[2].Shest_Kopio);
			if (Vibor == 10) {
				fscanf_s(fail_nach, " %7f (%7f) %7f", &per[1].a.Beg_Sred, &znach[2].Beg_Sred, &per[1].a.Kopio_M);
				fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[2].Kopio_M, &per[1].a.Met_D, &znach[2].Met_D);
			}
			fscanf_s(fail_nach, " %8f\n", &per[1].Itog);
		} while (sport.Itog > per[1].Itog);
		if (--i <= ++j)
		{
			if (Vibor == 7) fseek(fail_nach, i * 201, 0);
			else fseek(fail_nach, i  * 255, 0);
			fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", per[1].Nomer, per[1].Surname, per[1].Name, per[1].Patronymic, per[1].Pol);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f)", per[1].a.Beg_Malo, znach[2].Beg_Malo, per[1].a.Beg_Bar, znach[2].Beg_Bar);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[1].a.Beg_Mnogo, znach[2].Beg_Mnogo, per[1].a.Prij_D);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[2].Prij_D, per[1].a.Prij_V, znach[2].Prij_V, per[1].a.Met_Ia);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[2].Met_Ia, per[1].a.Shest_Kopio, znach[2].Shest_Kopio);
			if (Vibor == 10) {
				fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[1].a.Beg_Sred, znach[2].Beg_Sred, per[1].a.Kopio_M);
				fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[2].Kopio_M, per[1].a.Met_D, znach[2].Met_D);
			}
			fprintf_s(fail_nach, " %8.2f\n", per[1].Itog);
			i++;

			if (Vibor == 7) fseek(fail_nach, j  * 201, 0);
			else fseek(fail_nach, j  * 255, 0);
			fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", per[0].Nomer, per[0].Surname, per[0].Name, per[0].Patronymic, per[0].Pol);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f)", per[0].a.Beg_Malo, znach[1].Beg_Malo, per[0].a.Beg_Bar, znach[1].Beg_Bar);
			fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Mnogo, znach[1].Beg_Mnogo, per[0].a.Prij_D);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[1].Prij_D, per[0].a.Prij_V, znach[1].Prij_V, per[0].a.Met_Ia);
			fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[1].Met_Ia, per[0].a.Shest_Kopio, znach[1].Shest_Kopio);
			if (Vibor == 10) {
				fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Sred, znach[1].Beg_Sred, per[0].a.Kopio_M);
				fprintf_s(fail_nach, " (%7.2f) %7.2f (%7.2f)", znach[1].Kopio_M, per[0].a.Met_D, znach[1].Met_D);
			}
			fprintf_s(fail_nach, " %8.2f\n", per[0].Itog);
			j--;
		}
	}
	fclose(fail_nach);
	if (j > low)
		sortnomer( low, j);
	if (i < high)
		sortnomer(i, high);
}

void nomer(int low, int high)
{
	int N = 0;
	float itog=-1;
	for (int i = low;i < high; i++)
	{
		fscanf_s(fail_nach, "%4i %s %s", &per[0].Nomer, per[0].Surname, sizeof(sport.Surname), per[0].Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", per[0].Patronymic, sizeof(sport.Patronymic), &per[0].Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f)", &per[0].a.Beg_Malo, &znach[1].Beg_Malo, &per[0].a.Beg_Bar, &znach[1].Beg_Bar);
		fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Mnogo, &znach[1].Beg_Mnogo, &per[0].a.Prij_D);
		fscanf_s(fail_nach, " (%7f) %7f (%7f) %7f", &znach[1].Prij_D, &per[0].a.Prij_V, &znach[1].Prij_V, &per[0].a.Met_Ia);
		fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Met_Ia, &per[0].a.Shest_Kopio, &znach[1].Shest_Kopio);
		if (Vibor == 10) {
			fscanf_s(fail_nach, " %7f (%7f) %7f", &per[0].a.Beg_Sred, &znach[1].Beg_Sred, &per[0].a.Kopio_M);
			fscanf_s(fail_nach, " (%7f) %7f (%7f)", &znach[1].Kopio_M, &per[0].a.Met_D, &znach[1].Met_D);
		}
		fscanf_s(fail_nach, " %8f\n", &per[0].Itog);
		
		if (itog != per[0].Itog) N++;

		fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", per[0].Nomer, per[0].Surname, per[0].Name, per[0].Patronymic, per[0].Pol);
		fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f (%7.2f)", per[0].a.Beg_Malo, znach[1].Beg_Malo, per[0].a.Beg_Bar, znach[1].Beg_Bar);
		fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Mnogo, znach[1].Beg_Mnogo, per[0].a.Prij_D);
		fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f) %7.2f", znach[1].Prij_D, per[0].a.Prij_V, znach[1].Prij_V, per[0].a.Met_Ia);
		fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[1].Met_Ia, per[0].a.Shest_Kopio, znach[1].Shest_Kopio);
		if (Vibor == 10) {
			fprintf_s(fail_itog, " %7.2f (%7.2f) %7.2f", per[0].a.Beg_Sred, znach[1].Beg_Sred, per[0].a.Kopio_M);
			fprintf_s(fail_itog, " (%7.2f) %7.2f (%7.2f)", znach[1].Kopio_M, per[0].a.Met_D, znach[1].Met_D);
		}
		fprintf_s(fail_itog, " %8.2f %4i\n", per[0].Itog, N);

		itog = per[0].Itog;
	}
}
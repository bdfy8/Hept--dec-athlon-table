#include<iostream>
#include <iomanip>
#include "struct.h"

using namespace std;

FILE* fail_nach;
extern FILE* fail_itog;
extern short Vibor;

sem sport;

void vvod(int);

short write()
{
	if (Vibor == 7) fopen_s(&fail_nach, "Информация по спортсменам семиборья.txt", "w");
	else fopen_s(&fail_nach, "Информация по спортсменам десятиборья.txt", "w");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла\n";
		return 1;
	}
	vvod(0);
	fclose(fail_nach);
}

short add()
{
	int Otstup = 146;
	if (Vibor == 7)
	{
		fopen_s(&fail_nach, "Информация по спортсменам семиборья.txt", "r+");
		Otstup = 122;
	}
	else fopen_s(&fail_nach, "Информация по спортсменам десятиборья.txt", "r+");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла\n";
		return 1;
	}
	fseek(fail_nach, -Otstup, SEEK_END);
	fscanf_s(fail_nach, "%4d", &Otstup);
	fseek(fail_nach, 0, SEEK_END);
	vvod(Otstup);
	fclose(fail_nach);
}

short unadd()
{
	int N;
	if (Vibor == 7)
	{
		fopen_s(&fail_nach, "Информация по спортсменам семиборья.txt", "r");
	}
	else fopen_s(&fail_nach, "Информация по спортсменам десятиборья.txt", "r");
	fopen_s(&fail_itog, "Замена.txt", "w");
	if (fail_nach == NULL)
	{
		cout << "Ошибка открытия  файла\n";
		return 1;
	}
	if (fail_itog == NULL)
	{
		cout << "Ошибка открытия  файла: Замена.txt\n";
		return 1;
	}

	cout << "Введите номер спортсмена,которого хотите удалить :" << '\n';
	cin >> N;

	while(!feof(fail_nach))
	{
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f %7f %7f %7f", &sport.a.Beg_Malo, &sport.a.Beg_Bar, &sport.a.Beg_Mnogo, &sport.a.Prij_D);
		fscanf_s(fail_nach, " %7f %7f %7f", &sport.a.Prij_V, &sport.a.Met_Ia, &sport.a.Shest_Kopio);
		if (Vibor == 10)fscanf_s(fail_nach, " %7f %7f %7f", &sport.a.Beg_Sred, &sport.a.Kopio_M, &sport.a.Met_D);
		fscanf_s(fail_nach, "\n");
		if (sport.Nomer != N)
		{
			fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
			fprintf_s(fail_itog, " %7.2f %7.2f %7.2f %7.2f", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
			fprintf_s(fail_itog, " %7.2f %7.2f %7.2f", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio);
			if (Vibor == 10)
			{
				fprintf_s(fail_itog, " %7.2f %7.2f %7.2f", sport.a.Beg_Sred, sport.a.Kopio_M, sport.a.Met_D);
			}
			fprintf_s(fail_itog, "\n");
		}
		else break;
	}
	if (feof(fail_nach)) cout << "Спортсмена под таким номером нет" << '\n';
	else cout << "Информация удалена" << '\n';
	while (!feof(fail_nach))
	{
		fscanf_s(fail_nach, "%4i %s %s", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name));
		fscanf_s(fail_nach, " %s %c", sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f %7f %7f %7f", &sport.a.Beg_Malo, &sport.a.Beg_Bar, &sport.a.Beg_Mnogo, &sport.a.Prij_D);
		fscanf_s(fail_nach, " %7f %7f %7f", &sport.a.Prij_V, &sport.a.Met_Ia, &sport.a.Shest_Kopio);
		if (Vibor == 10)fscanf_s(fail_nach, " %7f %7f %7f", &sport.a.Beg_Sred, &sport.a.Kopio_M, &sport.a.Met_D);
		fscanf_s(fail_nach, "\n");

		fprintf_s(fail_itog, "%4i %20s %15s %20s %1c", sport.Nomer-1, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
		fprintf_s(fail_itog, " %7.2f %7.2f %7.2f %7.2f", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
		fprintf_s(fail_itog, " %7.2f %7.2f %7.2f", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio);
		if (Vibor == 10)
		{
			fprintf_s(fail_nach, " %7.2f %7.2f %7.2f", sport.a.Beg_Sred, sport.a.Kopio_M, sport.a.Met_D);
		}
		fprintf_s(fail_itog, "\n");
	}
	fclose(fail_itog);
	fclose(fail_nach);
	if (Vibor == 7) 
	{
		remove("Информация по спортсменам семиборья.txt");
		rename("Замена.txt", "Информация по спортсменам семиборья.txt");
	}
	else
	{
		remove("Информация по спортсменам десятиборья.txt");
		rename("Замена.txt", "Информация по спортсменам десятиборья.txt");
	}
}

void vvod(int N)
{
	char otvet = 'д';
	sport.Nomer = N + 1;
	while (otvet != 'н')
	{
		cin.ignore();
		cout << "Введите Фамилию" << '\n';
		cin.getline(sport.Surname, 20, '\n');
		cout << "Введите Имя" << '\n';
		cin.getline(sport.Name, 15, '\n');
		cout << "Введите Отчество" << '\n';
		cin.getline(sport.Patronymic, 20, '\n');
		if (Vibor == 7)
		{
			cout << "Введите пол(м/ж)" << '\n';
			cin >> sport.Pol;
		}
		else sport.Pol='м';
		cout << "Введите время бега на короткую дистанцую(с.мс)" << '\n';
		cin >> sport.a.Beg_Malo;
		cout << "Введите время бега с барьерами(с.мс)" << '\n';
		cin >> sport.a.Beg_Bar;
		cout << "Введите время бега на длинную дистанцию(с.мс)" << '\n';
		cin >> sport.a.Beg_Mnogo;
		cout << "Введите расстояние прыжка в длину(м.см)" << '\n';
		cin >> sport.a.Prij_D;
		cout << "Введите расстояние прыжка в высоту(м.см)" << '\n';
		cin >> sport.a.Prij_V;
		cout << "Введите рассоятние броска ядра(м.см)" << '\n';
		cin >> sport.a.Met_Ia;
		if (sport.Pol== 'м' ||sport.Pol== 'М') cout << "Введите высоту прыжка с шестом(м.см)" << '\n';
		else cout << "Введите рассстояние броска копья(м.см)" << '\n';
		cin >> sport.a.Shest_Kopio;
		fprintf_s(fail_nach, "%4i %20s %15s %20s %1c",sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
		fprintf_s(fail_nach, " %7.2f %7.2f %7.2f %7.2f", sport.a.Beg_Malo, sport.a.Beg_Bar, sport.a.Beg_Mnogo, sport.a.Prij_D);
		fprintf_s(fail_nach, " %7.2f %7.2f %7.2f", sport.a.Prij_V, sport.a.Met_Ia, sport.a.Shest_Kopio);
		if (Vibor == 10)
		{
			cout << "Введите время бега на среднюю дистанцию(с.мс)" << '\n';
			cin >> sport.a.Beg_Sred;
			cout << "Введите рассстояние броска копья(м.см)" << '\n';
			cin >> sport.a.Kopio_M;
			cout << "Введите рассстояние броска диска(м.см)" << '\n';
			cin >> sport.a.Met_D;
			fprintf_s(fail_nach, " %7.2f %7.2f %7.2f", sport.a.Beg_Sred, sport.a.Kopio_M, sport.a.Met_D);
		}
		fprintf_s(fail_nach, "\n");
		cout << "Хотите ввести еще (да - д / нет - н)" << '\n';
		cin >> otvet;
		sport.Nomer++;
	}
}
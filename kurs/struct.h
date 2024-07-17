#pragma once

using namespace std;

struct perem
{
	float Beg_Malo=0.00, Beg_Bar = 0.00, Beg_Mnogo = 0.00, Prij_D = 0.00, Prij_V = 0.00, Shest_Kopio = 0.00, Met_Ia = 0.00, Beg_Sred = 0.00, Met_D = 0.00, Kopio_M = 0.00;
};

struct sem
{
	float Itog;
	int Nomer,Pobed;
	char Name[15], Surname[20], Patronymic[20], Pol;
	perem a;
};
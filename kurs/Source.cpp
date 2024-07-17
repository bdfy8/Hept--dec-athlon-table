//fscanf_s(fail_nach, "%4d %20s %15s %20s %1c %5.2f %6.2f %7.2f %6.2f %6.2f %6.2f %6.2f ", &sport.Nomer, &sport.Surname, sizeof(sport.Surname), &sport.Name, sizeof(sport.Name), &sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, sizeof(sport.Pol), &sport.Beg_Malo, &sport.Beg_Bar, &sport.Beg_Mnogo, &sport.Prij_D, &sport.Prij_V, &sport.Met_Ia, &sport.Shest_Kopio);
//fprintf_s(fail_nach, "%4d %20s %15s %20s %1ñ %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol, sport.Beg_Malo, sport.Beg_Bar, sport.Beg_Mnogo, sport.Prij_D, sport.Prij_V, sport.Met_Ia, sport.Shest_Kopio);

//system("chcp 1251");
//fscanf_s(fail_nach, "%4d %20s %15s %20s %1c %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f\n", sport1.Nomer, sport1.Surname, sizeof(sport.Surname), &sport1.Name, sizeof(sport.Name), sport1.Patronymic, sizeof(sport.Patronymic), sport1.Pol, &sport1.Beg_Malo, &sport1.Beg_Bar, &sport1.Beg_Mnogo, &sport1.Prij_D, &sport1.Prij_V, &sport1.Met_Ia, &sport1.Shest_Kopio);


	/*if (Vibor == 7)
	{
		while (!feof(fail_nach))
		{
			fseek(fail_nach, (nomervstav+1)*122, 0);
			do{
				nomervstav++;
				fscanf_s(fail_nach, "%4i %s %s %s %c %7f %7f %7f %7f %7f %7f %7f\n", &sport1.Nomer, sport1.Surname, sizeof(sport.Surname), sport1.Name, sizeof(sport.Name), sport1.Patronymic, sizeof(sport.Patronymic), &sport1.Pol,1, &sport1.Beg_Malo, &sport1.Beg_Bar, &sport1.Beg_Mnogo, &sport1.Prij_D,&sport1.Prij_V, &sport1.Met_Ia, &sport1.Shest_Kopio);
				/*fscanf_s(fail_nach, ");
				fscanf_s(fail_nach, "");
				fscanf_s(fail_nach, "");
				fscanf_s(fail_nach, "");
				fscanf_s(fail_nach, " %7f ");
				fscanf_s(fail_nach, " %7f ");
				fscanf_s(fail_nach, " %7f ");
				fscanf_s(fail_nach, " %7f ");
				fscanf_s(fail_nach, " %7f ", );
				fscanf_s(fail_nach, " %7f ");
				fscanf_s(fail_nach, " %7f\n");
				printf_s( "%4i", sport1.Nomer);
				printf_s(" %20s", sport1.Surname);
				printf_s( " %15s", sport1.Name);
				printf_s( " %20s", sport1.Patronymic);
				printf_s( " %1c", sport1.Pol);
				printf_s(" %7.2f ", sport1.Beg_Malo);
				printf_s(" %7.2f ", sport1.Beg_Bar);
				printf_s( " %7.2f ", sport1.Beg_Mnogo);
				printf_s( " %7.2f ", sport1.Prij_D);
				printf_s( " %7.2f ", sport1.Prij_V);
				printf_s( " %7.2f ", sport1.Met_Ia);
				printf_s( " %7.2f\n", sport1.Shest_Kopio);
				//printf_s( "%4d %20s %15s %20s %ñ %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f\n", sport1.Nomer, sport1.Surname, sport1.Name, sport1.Patronymic, sport1.Pol, sport1.Beg_Malo, sport1.Beg_Bar, sport1.Beg_Mnogo, sport1.Prij_D, sport1.Prij_V, sport1.Met_Ia, sport1.Shest_Kopio);
			} while ((!feof(fail_nach)) && ((sport1.Pol != 'Ì') && (sport1.Pol != 'ì')));
			nomerstr = nomervstav;
			do{
				nomerstr++;
				fscanf_s(fail_nach, "%4i %s %s %s %c %7f %7f %7f %7f %7f %7f %7f\n", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name), sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1, &sport.Beg_Malo, &sport.Beg_Bar, &sport.Beg_Mnogo, &sport.Prij_D, &sport.Prij_V, &sport.Met_Ia, &sport.Shest_Kopio);
				if (sport.Pol == 'Æ' || sport.Pol == 'æ')
				{
					fseek(fail_nach, nomerstr*122, 0);
					fprintf_s(fail_nach, "%4i %20s %15s %20s %1c %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f\n", sport1.Nomer, sport1.Surname, sport1.Name, sport1.Patronymic, sport1.Pol, sport1.Beg_Malo, sport1.Beg_Bar, sport1.Beg_Mnogo, sport1.Prij_D, sport1.Prij_V, sport1.Met_Ia, sport1.Shest_Kopio);
					fseek(fail_nach, nomervstav*122, 0);
					fprintf_s(fail_nach, "%4i %20s %15s %20s %1c %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f %7.2f\n", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol, sport.Beg_Malo, sport.Beg_Bar, sport.Beg_Mnogo, sport.Prij_D, sport.Prij_V, sport.Met_Ia, sport.Shest_Kopio);
				}
			} while ((!feof(fail_nach)) && ((sport.Pol != 'Æ') && (sport.Pol != 'æ')));
		}
	}*/



/*fscanf_s(fail_nach, "%4i %s %s %s %c", &mina.Nomer, mina.Surname, sizeof(sport.Surname), mina.Name, sizeof(sport.Name), mina.Patronymic, sizeof(sport.Patronymic), &mina.Pol, 1);
fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f)", &mina.a.Beg_Malo, &minznach.Beg_Malo, &mina.a.Beg_Bar, &minznach.Beg_Bar, &mina.a.Beg_Mnogo, &minznach.Beg_Mnogo, &mina.a.Prij_D, &minznach.Prij_D, &mina.a.Prij_V, &minznach.Prij_V, &mina.a.Met_Ia, &minznach.Met_Ia, &mina.a.Shest_Kopio, &minznach.Shest_Kopio);
if (Vibor == 10)fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f)", &mina.a.Beg_Sred, &minznach.Beg_Sred, &mina.a.Kopio_M, &minznach.Kopio_M, &mina.a.Met_D, &minznach.Met_D);
fscanf_s(fail_nach, "  %8f\n", &itog[0]);
while (!feof(fail_nach))
{
	nomerstrvst = nomervst;
	while (!feof(fail_nach))
	{
		nomerstr++;
		fscanf_s(fail_nach, "%4i %s %s %s %c", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name), sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &znach.Beg_Malo, &sport.a.Beg_Bar, &znach.Beg_Bar, &sport.a.Beg_Mnogo, &znach.Beg_Mnogo, &sport.a.Prij_D, &znach.Prij_D, &sport.a.Prij_V, &znach.Prij_V, &sport.a.Met_Ia, &znach.Met_Ia, &sport.a.Shest_Kopio, &znach.Shest_Kopio);
		if (Vibor == 10) fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f)", &sport.a.Beg_Sred, &znach.Beg_Sred, &sport.a.Kopio_M, &znach.Kopio_M, &sport.a.Met_D, &znach.Met_D);
		fscanf_s(fail_nach, "  %8f\n", &itog[1]);
		if (ai == 0)
		{
			if (itog[0] >= itog[1])
			{
				per = sport;
				sport = mina;
				mina = per;
				itog[2] = itog[0];
				itog[0] = itog[1];
				itog[1] = itog[2];
				perznach = znach;
				znach = minznach;
				minznach = perznach;
				nomerstrvst = nomerstr;
			}
		}
		if (ai == 1)
		{
			if (itog[0] < itog[1])
			{
				mina = sport;
				itog[0] = itog[1];
				minznach = znach;
				nomerstrvst = nomerstr;
			}
		}
		if (ai == 2)
		{
			if (strcmp(mina.Surname, sport.Surname) != -1)
			{
				mina = sport;
				itog[0] = itog[1];
				minznach = znach;
				nomerstrvst = nomerstr;
			}
		}
		if (ai == 3)
		{
			if (strcmp(mina.Surname, sport.Surname) != 1)
			{
				mina = sport;
				itog[0] = itog[1];
				minznach = znach;
				nomerstrvst = nomerstr;
			}
		}
	}
	if (nomervst != nomerstrvst)
	{
		if (Vibor == 7) fseek(fail_nach, nomervst * 201, 0);
		else fseek(fail_nach, nomervst * 254, 0);
		fscanf_s(fail_nach, "%4i %s %s %s %c", &sport.Nomer, sport.Surname, sizeof(sport.Surname), sport.Name, sizeof(sport.Name), sport.Patronymic, sizeof(sport.Patronymic), &sport.Pol, 1);
		fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f)", &sport.a.Beg_Malo, &znach.Beg_Malo, &sport.a.Beg_Bar, &znach.Beg_Bar, &sport.a.Beg_Mnogo, &znach.Beg_Mnogo, &sport.a.Prij_D, &znach.Prij_D, &sport.a.Prij_V, &znach.Prij_V, &sport.a.Met_Ia, &znach.Met_Ia, &sport.a.Shest_Kopio, &znach.Shest_Kopio);
		if (Vibor == 10) fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f)", &sport.a.Beg_Sred, &znach.Beg_Sred, &sport.a.Kopio_M, &znach.Kopio_M, &sport.a.Met_D, &znach.Met_D);
		fscanf_s(fail_nach, "  %8f\n", &itog[1]);

		if (Vibor == 7) fseek(fail_nach, nomervst * 201, 0);
		else fseek(fail_nach, nomervst * 254, 0);
		fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", mina.Nomer, mina.Surname, mina.Name, mina.Patronymic, mina.Pol);
		fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f)", mina.a.Beg_Malo, minznach.Beg_Malo, mina.a.Beg_Bar, minznach.Beg_Bar, mina.a.Beg_Mnogo, minznach.Beg_Mnogo, mina.a.Prij_D, minznach.Prij_D, mina.a.Prij_V, minznach.Prij_V, mina.a.Met_Ia, minznach.Met_Ia, mina.a.Shest_Kopio, minznach.Shest_Kopio);
		if (Vibor == 10) fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f)", mina.a.Beg_Sred, minznach.Beg_Sred, mina.a.Kopio_M, minznach.Kopio_M, mina.a.Met_D, minznach.Met_D);
		fprintf_s(fail_nach, "  %8.2f\n", itog[0]);

		if (Vibor == 7) fseek(fail_nach, nomerstrvst * 201, 0);
		else fseek(fail_nach, nomerstrvst * 254, 0);
		fprintf_s(fail_nach, "%4i %20s %15s %20s %1c", sport.Nomer, sport.Surname, sport.Name, sport.Patronymic, sport.Pol);
		fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f)", sport.a.Beg_Malo, znach.Beg_Malo, sport.a.Beg_Bar, znach.Beg_Bar, sport.a.Beg_Mnogo, znach.Beg_Mnogo, sport.a.Prij_D, znach.Prij_D, sport.a.Prij_V, znach.Prij_V, sport.a.Met_Ia, znach.Met_Ia, sport.a.Shest_Kopio, znach.Shest_Kopio);
		if (Vibor == 10) fprintf_s(fail_nach, " %7.2f (%7.2f) %7.2f (%7.2f) %7.2f (%7.2f)", sport.a.Beg_Sred, znach.Beg_Sred, sport.a.Kopio_M, znach.Kopio_M, sport.a.Met_D, znach.Met_D);
		fprintf_s(fail_nach, "  %8.2f\n", itog[1]);
	}
	nomervst++;
	nomerstr = nomervst;

	if (Vibor == 7) fseek(fail_nach, nomervst * 201, 0);
	else fseek(fail_nach, nomervst * 254, 0);
	fscanf_s(fail_nach, "%4i %s %s %s %c", &mina.Nomer, mina.Surname, sizeof(sport.Surname), mina.Name, sizeof(sport.Name), mina.Patronymic, sizeof(sport.Patronymic), &mina.Pol, 1);
	fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f) %7f (%7f)", &mina.a.Beg_Malo, &minznach.Beg_Malo, &mina.a.Beg_Bar, &minznach.Beg_Bar, &mina.a.Beg_Mnogo, &minznach.Beg_Mnogo, &mina.a.Prij_D, &minznach.Prij_D, &mina.a.Prij_V, &minznach.Prij_V, &mina.a.Met_Ia, &minznach.Met_Ia, &mina.a.Shest_Kopio, &minznach.Shest_Kopio);
	if (Vibor == 10)fscanf_s(fail_nach, " %7f (%7f) %7f (%7f) %7f (%7f)", &mina.a.Beg_Sred, &minznach.Beg_Sred, &mina.a.Kopio_M, &minznach.Kopio_M, &mina.a.Met_D, &minznach.Met_D);
	fscanf_s(fail_nach, "  %8f\n", &itog[0]);
}
fclose(fail_nach);
*/
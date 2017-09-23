// DZ3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <math.h>
#include <algorithm>
#include <string>

void comb(int* Mods_tmp, int* mods_cnt, int* Prime_factors, int N, int K)
{
	std::string bitmask(++K, 1);
	bitmask.resize(N, 0);

	do
	{
		Mods_tmp[*mods_cnt] = 1;
		for (int i = 0; i < N; ++i)
			if (bitmask[i])
				Mods_tmp[*mods_cnt] = Mods_tmp[*mods_cnt] * Prime_factors[i];
		*mods_cnt += 1;
	}
	while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main()
{
	int i, j, cnt;
	int p(23), b(8), g(8);
	const int N(200);
	bool Prime_num_bool[N] = {false};
	int Prime_num[N] = { 0 }, Prime_factors[N] = { 0 }, Prime_factors_red[N] = { 0 }, Prime_factors_pow[N] = { 0 };
	int Mods_tmp[N] = { 0 }, Mods[N] = { 0 };
	int Subgroup[N] = { 0 };

	for (i = 2; i <= sqrt(N); i++)
		if (Prime_num_bool[i] == false)
			for (j = i * i; j < N; j += i) Prime_num_bool[j] = true;

	printf("\n \t %s %d %s \n", "Prime numbers for N =", N, ":");
	cnt = 0;
	for (i = 2; i < N; i++)
		if (Prime_num_bool[i] == false)
		{
			Prime_num[cnt++] = i;
			printf("\t %d", i);
		}

	int order = p - 1;
	int ord = order;

	cnt = 0;
	i = 0;
	while (Prime_num[i] <= sqrt(ord))
	{
		while (ord % Prime_num[i] == 0)
		{
			Prime_factors[cnt++] = Prime_num[i];
			ord /= Prime_num[i];
		}
		i++;
	}
	if (ord > 1) Prime_factors[cnt] = ord;

	i = 0;
	cnt = 0;
	int cnt_pow = 1;
	Prime_factors_red[cnt] = Prime_factors[i++];
	do
	{
		if (Prime_factors[i] == Prime_factors[i - 1]) cnt_pow++;
		else
		{
			Prime_factors_pow[cnt] = cnt_pow;
			cnt++;
			Prime_factors_red[cnt] = Prime_factors[i];
			cnt_pow = 1;
		}
	}
	while (Prime_factors[i++] != 0);

	printf("\n \t %s %d %s \n", "Factorization for order =", order, ":");
	i = 0;
	while (Prime_factors[i] != 0) printf("\t %d", Prime_factors[i++]);
	cnt = i;
	printf("\n \t %s %d %s \n", "Factorization with powers for order =", order, ":");
	i = 0;
	while (Prime_factors_red[i] != 0)
	{
		printf("\t %d", Prime_factors_red[i]);
		printf("\t %d \n", Prime_factors_pow[i]);
		i++;
	}
	
	int mods_cnt = 0;
	Mods_tmp[mods_cnt++] = 1;
	for (i = 0; i < cnt; i++)
		comb(Mods_tmp, &mods_cnt, Prime_factors, cnt, i);
	std::sort(std::begin(Mods_tmp), std::end(Mods_tmp) - N + mods_cnt);
	cnt = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (Mods[j] == Mods_tmp[i]) break;
			if (j == i)	Mods[cnt++] = Mods_tmp[i];
		}
	}

	printf("\n \t %s %d %s \n", "All divisors for order =", order, ":");
	i = 0;
	while (Mods[i] != 0) printf("\t %d", Mods[i++]);

	i = 0;
	Subgroup[i++] = static_cast<int>(pow(b, i)) % p;
	do Subgroup[i] = (Subgroup[i - 1] * b) % p;
	while (Subgroup[i++] != 1);

	printf("\n \t %s %d %s", "Subgroup for b [", b, "]:");
	i = 0;
	while (Subgroup[i] != 0)
	{
		printf("\n \t %s %d %s %d %s %d", "[", b, "^", i, "] = ", Subgroup[i]);
		i++;
	}

	_getch();
	return 0;
}

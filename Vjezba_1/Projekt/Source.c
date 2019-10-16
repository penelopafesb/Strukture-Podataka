#include<stdio.h>
#include<malloc.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include<string.h>
#define MAX 20

typedef struct {
	int bodovi;
	char ime[MAX];
	char prezime[MAX];
	float prosjek;

}student;

int broji_retke(char* ime_dat);
int citaj(char* ime_dat, student *s, int n);
int prosjek(char* ime_dat, student *s, int n, int max);
int ispis(char* ime_dat, student *s, int n);

int main()
{
	int n, i;
	student* s;
	int max = 0;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska u otvaranju datoteke!");

	n = broji_retke(fp);

	s = (student*)malloc(n * sizeof(student));

	max = citaj(fp, s, n);
	prosjek(fp, s, n, max);
	ispis(fp, s, n);

	return 0;
}

int broji_retke(char* ime_dat)
{
	int znak = 0;
	int br = 0;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska u otvaranju datoteke!");

	br++;
	while ((znak = fgetc(fp)) != EOF)
	{
		if (znak == '\n')
			br++;
	}

	return br;
}

int citaj(char* ime_dat, student *s, int n)
{
	int i, max;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska u otvaranju datoteke!");

	for (i = 0; i < n; i++) {

		fscanf(fp, "%d ", &s[i].bodovi);
		fscanf(fp, "%s ", s[i].ime);
		fscanf(fp, "%s ", s[i].prezime);
	}

	max = s[0].bodovi;

	for (i = 1; i < n; i++) {
		if (s[i].bodovi > max)
			max = s[i].bodovi;
	}

	return max;
}

int prosjek(char* ime_dat, student *s, int n, int max)
{
	int i;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska u otvaranju datoteke!");

	for (i = 0; i < n; i++)
		s[i].prosjek = (float)s[i].bodovi / max * 100;

	return 0;
}

int ispis(char* ime_dat, student *s, int n)
{
	int i;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska u otvaranju datoteke!");

	printf("\t\tIme\t\tPrezime\t\tBodovi\tProsjek\n\n");

	for (i = 0; i < n; i++) {
		printf("%15s\t\t%15s\t\t%2d\t%f\n", s[i].ime, s[i].prezime, s[i].bodovi, s[i].prosjek);
	}

	return 0;
}
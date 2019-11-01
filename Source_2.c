#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<ctype.h>
#define MAX 1024

typedef struct _student {
	char ime[MAX];
	char prezime[MAX];
	int godina;

	struct _student * next;
}student;

int Menu(student *);
int UnosPocetak(student *);
int Ispis(student *);
int UnosKraj(student *);
student* PronadiZadnji(student*);
student* PronadiPrezime(student*, char*);
student* PronadiPrethodni(student*, student*);
int Obrisi(student *, student *);
int DodajIzaElementa(student*, student*);
int DodajIspredElementa(student*, student*, student*);

int main()
{
	student* head;
	head = (student*)malloc(sizeof(student));
	head->next = NULL;
	int status = 0;

	do {
		status = Menu(head);
	} while (!status);
		
	return 0;
}

int Menu(student *head)
{
	int izbor = 0;
	
	char prezime[MAX];
	student* nadi_prezime = NULL;
	nadi_prezime = (student*)malloc(sizeof(student));

	char obrisi[MAX];
	student* obrisi_el = NULL;
	obrisi_el = (student*)malloc(sizeof(student));

	char iza[MAX];
	student* dodaj_iza = NULL;
	dodaj_iza = (student*)malloc(sizeof(student));

	char ispred[MAX];
	student* dodaj_ispred = NULL;
	dodaj_ispred = (student*)malloc(sizeof(student));
	student* prethodni = NULL;
	prethodni = (student*)malloc(sizeof(student));

	printf("*******************************************\n");
	printf("1 - Unos elementa na pocetak\n");
	printf("2 - Unos elementa na kraj\n");
	printf("3 - Ispis liste\n");
	printf("4 - Pronadi prezime\n");
	printf("5 - Izbrisi prezime\n");
	printf("6 - Dodaj element iza\n");
	printf("7 - Dodaj element ispred\n");
	printf("9 - Iskljuci program\n");
	printf("*******************************************\n");

	while (1) {

		printf("\nIzaberite zeljenu opciju unosom broja\nZa ponovni ispis izbornika pritisnite 0\n");
		scanf(" %d", &izbor);

		switch (izbor) {
		case (1): UnosPocetak(head);
			break;

		case (2): UnosKraj(head);
			break;

		case (3): Ispis(head);
			break;

		case(4): printf("\n\nKoje prezime zelite pronaci? ");
			scanf("%s", prezime);
			nadi_prezime = PronadiPrezime(head, prezime);
			printf("\nElement koji ste pretrazili:\nIme: %s\nPrezime: %s\nGodina rodenja: %d\n", nadi_prezime->ime, nadi_prezime->prezime, nadi_prezime->godina);
			break;

		case(5): printf("\n\nKoje prezime zelite obrisati? ");
			scanf("%s", obrisi);
			obrisi_el = PronadiPrezime(head, obrisi);
			Obrisi(head, obrisi_el);
			break;

		case (6): printf("\n\nIza kojeg prezimena zelite dodati element? ");
			scanf("%s", iza);
			dodaj_iza = PronadiPrezime(head, iza);
			DodajIzaElementa(head, dodaj_iza);
			break;

		case(7): printf("\n\nIspred kojeg elementa zelite dodati prezime? ");
			scanf("%s", ispred);
			dodaj_ispred = PronadiPrezime(head, ispred);
			prethodni = (head, dodaj_ispred);
			DodajIspredElementa(head, dodaj_ispred, prethodni);
			break;

		case(0): 
			return 0;

		case (9):
			return 1;

		default: printf("\n\nKrivi unos! Pokusajte ponovo.");
		}
	}

	return 0;
}

int UnosPocetak(student *head)
{
	student *s;
	s = (student*)malloc(sizeof(student));

	s->next = head->next;
	head->next = s;

	printf("Unesite ime: ");
	scanf("%s", s->ime);
	printf("Unesite prezime: ");
	scanf("%s", s->prezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &s->godina);
	printf("\n");

	return 0;
}

int Ispis(student *head)
{
	student *s = head->next;

	printf("\n***************VASA LISTA**************\n");
	while (s != NULL) {
		printf("\tIme: %s", s->ime);
		printf("\n\tPrezime: %s", s->prezime);
		printf("\n\tGodina rodenja: %d", s->godina);
		printf("\n\n");
		s = s->next;
	}
	printf("****************************************");

	return 0;
}

int UnosKraj(student *head)
{
	student *s;
	s = (student*)malloc(sizeof(student));
	student *p;
	p = (student*)malloc(sizeof(student));

	p = PronadiZadnji(head);

	s->next = NULL;
	p->next = s;

	printf("Unesite ime: ");
	scanf("%s", s->ime);
	printf("Unesite prezime: ");
	scanf("%s", s->prezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &s->godina);
	printf("\n");

	return 0;	
}

student* PronadiZadnji(student *head)
{
	student *p = head;

	while (p != NULL && p->next != NULL)
		p = p->next;

	return p;
}

student* PronadiPrezime(student *head, char *prezime)
{
	student *P = head->next;

	while (P != NULL && strcmp(P->prezime, prezime))
		P = P->next;

	return P;
}

student* PronadiPrethodni(student *head, student *element)
{
	student *P;
	P = (student*)malloc(sizeof(student));
	P = head;
		
	while (P != NULL && P->next != element)
		P = P->next;

	return P;
}

int Obrisi(student *head, student *element)
{
	student *P = NULL;
	student *q = NULL;
	P = (student*)malloc(sizeof(student));
	q = (student*)malloc(sizeof(student));
	q = element;

	P = PronadiPrethodni(head, element);
	P->next = q->next;
	
	free(q);

	return 0;
}

int DodajIzaElementa(student* head, student* element)
{
	student* novi;
	novi = (student*)malloc(sizeof(student));

	printf("Unesite ime: ");
	scanf("%s", novi->ime);
	printf("Unesite prezime: ");
	scanf("%s", novi->prezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &novi->godina);
	printf("\n");

	novi->next = element->next;
	element->next = novi;

	return 0;
}

int DodajIspredElementa(student* head, student* element, student* prethodni)
{
	student* novi;
	novi = (student*)malloc(sizeof(student));

	printf("Unesite ime: ");
	scanf("%s", novi->ime);
	printf("Unesite prezime: ");
	scanf("%s", novi->prezime);
	printf("Unesite godinu rodenja: ");
	scanf("%d", &novi->godina);
	printf("\n");

	novi->next = prethodni->next;
	prethodni->next = novi;

	return 0;
}
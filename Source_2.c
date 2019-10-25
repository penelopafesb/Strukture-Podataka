#define CRT_SECURE_NO_WARNINGS
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

int UnosPocetak(student *);
int Ispis(student *);
int UnosKraj(student *);
student* PronadiZadnji(student*);
student* PronadiPrezime(student*, char*);

int main()
{
	student *head = NULL;
	char prezime[MAX];
	student *el = NULL;

	head = (student*)malloc(sizeof(student));
	head->next = NULL;

	UnosPocetak(head);
	UnosKraj(head);
	UnosPocetak(head);
	printf("Koje prezime zelite pronaci? ");
	scanf("%s", prezime);
	el = PronadiPrezime(head, prezime);
	printf("Ime:%s\nPrezime:%s\nGodina rodenja:%d\n", el->ime, el->prezime, el->godina);
	Ispis(head);
	
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

	return 0;
}

int Ispis(student *head)
{
	student *s = head->next;

	while (s != NULL) {
		printf("Ime: %s", s->ime);
		printf("\nPrezime: %s", s->prezime);
		printf("\nGodina rodenja: %d", s->godina);
		printf("\n");
		s = s->next;
	}

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
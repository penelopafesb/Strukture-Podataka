#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 30

struct _cvor {
	int element;
	struct _cvor * next;
};

typedef struct _cvor Cvor;
typedef struct _cvor *Pozicija;

int RandomGen();
void Push(Pozicija);
void PushPrvi(Pozicija);
Pozicija PronadiZadnji(Pozicija);
int Pop(Pozicija);
void Ispis(head);
int PopRed(Pozicija);


int main()
{
	Pozicija head_stog;
	Pozicija head_red;
	head_stog = (Pozicija)malloc(sizeof(Cvor));
	head_red = (Pozicija)malloc(sizeof(Cvor));

	int i, br1, br2, br3, br4;
	
	PushPrvi(head_stog);
	for (i = 0; i < 13; i++)
		Push(head_stog);

	printf("Ovo je stog\n");
	Ispis(head_stog);

	br1 = Pop(head_stog);
	br2 = Pop(head_stog);

	printf("\n");
	Ispis(head_stog);
	printf("\n");
	
	PushPrvi(head_red);
	for (i = 0; i < 3; i++) 
		Push(head_red);

	printf("Ovo je red\n");
	Ispis(head_red);

	br3 = PopRed(head_red);
	br4 = PopRed(head_red);

	printf("\n");
	Ispis(head_red);

	return 0;
}

int RandomGen()
{
	int broj = 0;

	broj = (rand() % 90) + 10;

	return broj;
}

Pozicija PronadiZadnji(Pozicija head)
{
	Pozicija p;
	p = (Pozicija)malloc(sizeof(Cvor));
	p = head;

	while (p->next != NULL)
		p = p->next;

	return p;
}

void PushPrvi(Pozicija head)
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));

	q->element = RandomGen();

	q->next = NULL;
	head->next = q;

}

void Push(Pozicija head)
{
	Pozicija q;
	Pozicija zadnji;
	q = (Pozicija)malloc(sizeof(Cvor));
	zadnji = (Pozicija)malloc(sizeof(Cvor));

	zadnji = PronadiZadnji(head);

	q->element = RandomGen();

	q->next = zadnji->next;
	zadnji->next = q;

}

int Pop(Pozicija head)
{
	Pozicija q, zadnji;
	q = (Pozicija)malloc(sizeof(Cvor));
	zadnji = (Pozicija)malloc(sizeof(Cvor));
	int x;

	zadnji = PronadiZadnji(head);
	q = head;

	while (q->next->next != NULL)
		q = q->next;

	q->next = zadnji->next;
	x = zadnji->element;
	free(zadnji);

	return x;
}

void Ispis(Pozicija head)
{
	Pozicija q;
	q = (Pozicija)malloc(sizeof(Cvor));
	q = head->next;

	while (q != NULL) {
		printf(" %d ", q->element);
		q = q->next;
	}
}

int PopRed(Pozicija head)
{
	Pozicija temp;
	temp = (Pozicija)malloc(sizeof(Cvor));
	int x;

	temp = head->next;
	x = temp->element;
	head->next = temp->next;
	free(temp);

	return x;
}
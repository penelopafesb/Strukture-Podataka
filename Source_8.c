#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

/*
md - make directory
cd <dir ime> - open <dir ime>
cd.. - go back one directory
dir - list the files in current directory
izlaz
*/

typedef struct _stablo Stablo;
struct _stablo {
	char *ime;

	Stablo* child;
	Stablo* sibling;
};

typedef struct _stog Stog;
struct _stog{
	Stablo *directory;

	Stog* next;
};

Stablo* MakeDir();
int Menu(Stablo*, Stog*);
int Dir(Stablo*, Stog*);

int main()
{
	Stablo* root;
	root = (Stablo*)malloc(sizeof(Stablo));
	root->child = NULL;
	root->sibling = NULL;
	Stog* head;
	head = (Stog*)malloc(sizeof(Stog));
	head->next = NULL;
	int status = 0;
	root->ime = (char*)malloc(MAX * sizeof(char));
	root->ime = "C:";

	do {
		status = Menu(root, head);
	} while (!status);

	return 0;
}

int Menu(Stablo* root, Stog* head) {
	Stablo* CurrentFile = root;
	char command[MAX] = { 0 };

	printf("****************************\n");
	printf("md - Dodaj novi direktorij\n");
	printf("cd - Otvoti direktorij\n");
	printf("cd.. - Zatvoriti direktorij\n");
	printf("dir - Ispisi listu direktorija u trenutnome direktoriju\n");
	printf("exit - Izlaz\n");
	printf("****************************\n");

	while (1) {
		printf("\n%s>", CurrentFile->ime);
		scanf("%s", command);

		if (!strcmp(command, "md")) {
			CurrentFile->child = MakeDir();
		}

		else if (!strcmp(command, "cd")) {

		}

		else if (!strcmp(command, "dir")) {
			Dir(CurrentFile, head);
		}

		else if (!strcmp(command, "exit")) {
			return 1;
		}

		else
			printf("Naredba nije pronadena!\n");
	}

	return 0;
}

Stablo* MakeDir(){
	Stablo *directory;
	directory = (Stablo*)malloc(sizeof(Stablo));
	directory->ime = (char*)malloc(MAX*sizeof(char));

	if (!directory)
		printf("Memorija nije uspjesno alocirana");

	printf("Unesite ime direktorija: ");
	scanf(" %s", directory->ime);

	directory->sibling = NULL;
	directory->child = NULL;

 	return directory;
}

int Dir(Stablo* currentFile, Stog* head) {
	if (currentFile->child != NULL) {
		printf("DIRECTORIES: ");
		printf("\t- %s\n", currentFile->child->ime);
	}

	return 0;
}

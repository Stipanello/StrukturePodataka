#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 50

struct _person;
typedef struct _person* Position;
typedef struct _person
{
	char name[MAX_LENGTH];
	char lastName[MAX_LENGTH];
	int birthYear;

	Position next;
}Person;

Position CreatePerson();
Position FindLast(Position head);
Position FindPrev(Position head, Position current);
int InsertAfter(Position position, Position newPerson);

int AddToBegin(Position head);
int AddToEnd(Position head);
int AddAfter(Position head, const char* surname);
int AddBefore(Position head, const char* surname);
int DeletePerson(Position head, const char* surname);
Position FindBySurname(Position head, const char* surname);

int PrintList(Position head);

int main()
{
	Person head = { .name = "", .lastName = "", .birthYear = 0, .next = NULL };

	AddToBegin(&head);
	AddToBegin(&head);
	AddToEnd(&head);
	AddToEnd(&head);

	PrintList(&head);

	DeletePerson(&head, "d");

	printf("\n");
	PrintList(&head);
	printf("\n");

	AddAfter(&head, "c");
	AddBefore(&head, "c");

	printf("\n");
	PrintList(&head);
	printf("\n");

	return 0;
}

Position CreatePerson()
{
	Position newPerson = (Position)malloc(sizeof(Person));
	if (newPerson == NULL)
	{
		//ispis
		return NULL;
	}

	newPerson->next = NULL;
	newPerson->birthYear = 2000;
	strcpy(newPerson->name, "mate");
	scanf(" %s", newPerson->lastName);

	return newPerson;
}

Position FindLast(Position head)
{
	Position last = head;
	while (last->next != NULL)
	{
		last = last->next;
	}
	
	return last;
}

Position FindPrev(Position head, Position current)
{
	Position prev = head;
	while (prev != NULL && prev->next != current)
	{
		prev = prev->next;
	}

	return prev;
}
int InsertAfter(Position position, Position newPerson)
{
	newPerson->next = position->next;
	position->next = newPerson;
}

int AddToBegin(Position head)
{
	Position temp = head;
	Position newPerson = CreatePerson();
	if (newPerson == NULL)
	{
		return -1;
	}

	InsertAfter(temp, newPerson);

	return 0;
}

int AddToEnd(Position head)
{
	Position last = FindLast(head);

	Position newPerson = CreatePerson();
	if (newPerson == NULL)
	{
		return -1;
	}

	InsertAfter(last, newPerson);
	return 0;
}

int AddAfter(Position head, const char* surname)
{
	Position newPerson = CreatePerson();
	Position position = FindBySurname(head, surname);
	InsertAfter(position, newPerson);

	return 0;
}
int AddBefore(Position head, const char* surname)
{
	Position newPerson = CreatePerson();
	Position position = FindBySurname(head, surname);
	Position prev = FindPrev(head, position);

	InsertAfter(prev, newPerson);

	return 0;
}

Position FindBySurname(Position head, const char* surname)
{
	Position temp = head->next;

	while (temp != NULL && strcmp(temp->lastName, surname) != 0)
	{
		temp = temp->next;
	}

	return temp;
	
}

int DeletePerson(Position head, const char* surname)
{
	Position toDelete = FindBySurname(head, surname);
	Position prev = FindPrev(head, toDelete);

	prev->next = toDelete->next;
	free(toDelete);

	return 0;
}

int PrintList(Position head)
{
	Position temp = head->next;

	while (temp != NULL)
	{
		printf("Name: %s\n", temp->lastName);
		temp = temp->next;
	}
	
	return 0;
}


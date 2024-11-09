#define _CRT_SECURE_NO_WARNINGS
#define EXIT_SUCCESS 0
#define EXIT_FAILED -1
#define MAX_LENGTH 32
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _person* position;

typedef struct _person {
	//data
	char fname[MAX_LENGTH], lname[MAX_LENGTH];
	int birth_year;
	//link
	position next;
}person;

position create_person(position head, char* fname, char* lname, int birth_year, position* next);
int prepend_list(position head, char* fname, char* lname, int birth_year, position* next);
int append_list(position head, char* fname, char* lname, int birth_year, position* next);
position find_last(position head);
//int print_list(position first);
int print_list(position head);
int delete(position head, char* lname);
int insert_after(position head, char* fname, char* lname, int birth_year, position* next);

position create_person(position head, char* fname, char* lname, int birth_year, position* next) {
	position new_person = NULL;

	new_person = (position*)malloc(sizeof(person));
	if (!new_person) {
		printf("Malloc failed in funciton create_person()");
		return NULL;
	}

	strcpy(new_person->fname, fname);
	strcpy(new_person->lname, lname);
	new_person->birth_year = birth_year;
	new_person->next = NULL;

	return  new_person;
}

int main()
{
	person head = { .fname = "", .lname = "", .birth_year = 0,  .next = NULL };
	
	prepend_list(&head, "Mia", "Aleric", 2003, &head.next);
	prepend_list(&head, "Ana", "Anic", 1985, &head.next);
	prepend_list(&head, "Jure", "Juric", 1999, &head.next);
	append_list(&head, "Stipe", "Barac", 2004, &head.next);
	print_list(&head);

	printf("\n------------------------\n");

	delete(&head, "Juric");
	print_list(&head);

	printf("\n------------------------\n");
	
	delete(&head, "Aleric");
	print_list(&head);

	printf("\n------------------------\n");
	
	return 0;
}

int prepend_list(position head, char* fname, char* lname, int birth_year, position* next) 
{
	position new_person = NULL;

	new_person = create_person(head, fname, lname, birth_year, next);
	if (!new_person) {
		//printf("Memory allocation failed!\n");
		return EXIT_FAILED;
	}
	new_person->next= head->next;	//provjeriti
	head->next = new_person; 

	return EXIT_SUCCESS;
}

int append_list(position head, char* fname, char* lname, int birth_year, position* next)
{
	position new_person = NULL, last = NULL;
	
	new_person = create_person(head, fname, lname, birth_year, next);
	if (!new_person) {
		//printf("Memory allocation failed!\n");
		return EXIT_FAILED;
	}

	new_person->next = NULL;	//
	last = find_last(head);
	last->next = new_person;

	return EXIT_SUCCESS;
}

position find_last(position head)
{
	position temp = head;

	while (temp->next) {
		temp = temp->next;
	}
	return temp;
}
/*	funkcija sa vjezbi
int print_list(position first)
{
	position temp = first;

	while (temp != NULL) {
		printf("First name: %s\nLast name: %s\nBirth year: %d\n", temp->fname, temp->lname, temp->birth_year);
		temp = temp->next;
	}
	return EXIT_SUCCESS;
}
*/
int print_list(position head) {
	position temp = head->next;

	while (temp != NULL) {
		printf("First name: %s\nLast name: %s\nBirth year: %d\n\n", temp->fname, temp->lname, temp->birth_year);
		temp = temp->next;
	}
	return EXIT_SUCCESS;
}


position find_previous(position head, char* lname)
{
	position temp = head;

	while (temp->next && strcmp(temp->next->lname, lname) != 0)
		temp = temp->next;
	if (temp->next)
		return temp;
	else
		return NULL;
}

int delete(position head, char* lname)
{
	position previous = find_previous(head, lname);
	if (!previous)
	{
		printf("Person with last name %s not found.\n", lname);
		return EXIT_FAILED;
	}

	position to_delete = previous->next;
	previous->next = to_delete->next;
	free(to_delete);

	return EXIT_SUCCESS;
}
 //treci zadatak

 int insert_after(position head, char* fname, char* lname, int birth_year, position* next){
	position new_person = NULL;
	new_person = create_person(head, fname, lname, birth_year, next);

	printf("Unesite ime, prezime i godinu rođenja studenta: ");
	scanf("%s", "%s", "%d", &fname, &lname, &birth_year);

	char after_lname[MAX_LENGTH] = NULL;
	printf("Unesite prezime osobe iza koje želite dodati osobu: ");
	scanf("%s",after_lname);

	while (head->next != NULL && strcmp(after_lname, head->lname) != 0)
	{
			head = head->next;
	}
		if






 }

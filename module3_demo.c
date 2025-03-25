#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable : 4996) // needed in VS. Works like _CRT_SECURE_NO_WARNINGS.
// ctrl e,v to copy line down

#define MAX_CONTACTS 100
struct contact {
	char name[30];
	int phone;
	char email[30];
};

struct contact contactbook[MAX_CONTACTS];
int tail = 0; // next unused space

void branching(char c);
int insertion();
int search();
int delete();

int main()
{
	char input = ' ';
	while (input != 'q') {
		// display menu
		printf("Enter selection: \n");
		printf("   i: insert new entry   \n");
		printf("   d: delete an entry   \n");
		printf("   s: search an entry   \n");
		printf("   p: print all entries   \n");
		printf("   q: quit   \n");

		scanf(" %c", &input);
		input = tolower(input);

		branching(input);
	}
	return 0;
}

void branching(char c) {
	switch (c) {
	case 'i':
		insertion();
		break;
	case 'd':
		delete();
		break;
	case 's':
		search();
		break;
	case 'p':
		printf("print()\n");
		break;
	case 'q':
		// do nothing
		break;
	default:
		printf("invalid input\n");
	}
}

int insertion() {
	if (tail == MAX_CONTACTS) {
		printf("There are no more places for insert\n");
		return -1;
	}
	else {
		printf("Enter name, phone, email \n");
		scanf("%s", contactbook[tail].name);
		scanf("%d", &contactbook[tail].phone);
		scanf("%s", contactbook[tail].email);
		tail++;
		printf("The number of entries is %d\n", tail);
		return 0;
	}
}

int search() {
	char tname[30];
	printf("Please enter a name to search: \n");
	scanf("%s", tname);

	for (int i = 0; i < tail; i++) {
		if (_stricmp(tname, contactbook[i].name) == 0) {
			printf("phone: %d\n", contactbook[i].phone);
			printf("email: %s\n", contactbook[i].email);
			return i;
		}
	}

	printf("The name does not exist \n");
	return -1;
}

int delete() {
	int k;
	k = search();

	if (k == -1) {
		return -1;
	}
	else {
		for (int i = k; i < tail; i++) {
			strcpy(contactbook[i].name, contactbook[i + 1].name);
			strcpy(contactbook[i].email, contactbook[i + 1].email);
			contactbook[i].phone = contactbook[i + 1].phone;
		}
		printf("the index deleted was: %d\n", k);
		tail--;
		return k;
	}
}
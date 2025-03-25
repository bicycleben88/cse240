#include <stdio.h>
#include <ctype.h>
#define MAX_CONTACTS 100
#pragma warning(disable : 4996) // needed in VS. Works like _CRT_SECURE_NO_WARNINGS.
// ctrl e,v to copy line down

struct contact {
	char name[30];
	int phone;
	char email[30];
};

struct contact contactbook[MAX_CONTACTS];
int tail = 0; // next unused space

void branching(char c);
int insertion();

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
		printf("delete()\n");
		break;
	case 's':
		printf("search()\n");
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
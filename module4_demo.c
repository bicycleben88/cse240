#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#pragma warning(disable : 4996) // needed in VS. Works like _CRT_SECURE_NO_WARNINGS.
// ctrl e,v to copy line down

#define MAX_LENGTH 1024

struct ContactNode {
	char name[MAX_LENGTH];
	int phone;
	char email[MAX_LENGTH];

	struct ContactNode* next;
};


int main()
{
	struct ContactNode* n = malloc(sizeof(struct ContactNode));
	strcpy(n->name, "whhhat");
	n->phone = 666;

	printf("name is %s, phone is %d\n", n->name, n->phone);

	return 0;
}
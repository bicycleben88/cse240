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

struct ContactNode* addFront(struct ContactNode* node, struct ContactNode* front) {
	node->next = front;
	front = node;

	return front;
}

struct ContactNode* removeFront(struct ContactNode* front) {
	if (front != NULL) {
		struct ContactNode* temp = front;
		front = front->next;
		free(temp);
	}

	return front;
}

void display(struct ContactNode* front) {
	struct ContactNode* iter = front;

	while (iter) {
		printf("name: %s, number: %d\n", iter->name, iter->phone);
		iter = iter->next;
	}
}


int main()
{
	struct ContactNode* n1 = malloc(sizeof(struct ContactNode));
	strcpy(n1->name, "whhhat");
	n1->phone = 666;

	struct ContactNode* n2 = malloc(sizeof(struct ContactNode));
	strcpy(n2->name, "shat");
	n2->phone = 6660666;

	struct ContactNode* n3 = malloc(sizeof(struct ContactNode));
	strcpy(n3->name, "shat stick");
	n3->phone = 66606660;

	struct ContactNode* list = NULL;

	list = addFront(n1, list);
	list = addFront(n2, list);
	list = removeFront(list);
	list = addFront(n3, list);

	display(list);

	while (list != NULL) {
		list = removeFront(list);
	}

	return 0;
}


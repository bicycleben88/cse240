/*
* Description: Student Records with linked list
*
* Duration: 7
*
* Author: Ben Higginbotham
* Version: GCC
*/
// CSE240 
// Be sure to add the standard header above.
// Write the compiler used: Visual studio or gcc (SELECT ONE AND INDICATE)

// READ BEFORE YOU START:
// You are given a partially completed program that creates a linked list of patient records.
// Each record(struct) has this information: student's name, major, school year of student, ID number.
// The struct 'studentRecord' holds information of one student. School year is enum type.
// A linked list called 'list' is made to hold the list of students.
// To begin, you should trace through the given code and understand how it works.
// Please read the instructions above each required function and follow the directions carefully.
// You should not modify any of the given code, the return types, or the parameters, you risk getting compile error.
// You are not allowed to modify main ().
// You can use string library functions.
// ***** WRITE COMMENTS FOR IMPORANT STEPS OF YOUR CODE. *****
// ***** GIVE MEANINGFUL NAMES TO VARIABLES. *****


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996) // for Visual Studio Only

#define MAX_NAME_LENGTH 25

typedef enum { freshman = 0, sophomore, junior, senior } schoolYearType; // enum type 

struct studentRecord {
	char studentName[MAX_NAME_LENGTH];
	char major[MAX_NAME_LENGTH];
	schoolYearType schoolYear;
	unsigned int IDNumber;
	struct studentRecord* next;	// pointer to next node
} *list = NULL;					// Declare linked list 'list'

// forward declaration of functions (already implmented)
void flushStdIn();
void executeAction(char);

// functions that need implementation:
int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input); // 20 points
void displayList();						// 10 points
int countNodes();						// 5 points
int deleteNode(char* studentName_input);	// 10 points
void swapNodes(struct studentRecord* node1, struct studentRecord* node2);	// 5 points



int main()
{
	char selection = 'i';		// initialized to a dummy value
	printf("\nCSE240 HW5\n");
	do
	{
		printf("\nCurrently %d student(s) on the list.", countNodes());	// NOTE: countNodes() called here
		printf("\nEnter your selection:\n");
		printf("\t a: add a new student\n");
		printf("\t d: display student list\n");
		printf("\t r: remove a student from the list\n");
		printf("\t q: quit\n");
		selection = getchar();
		flushStdIn();
		executeAction(selection);
	} while (selection != 'q');

	return 0;
}

// flush out leftover '\n' characters
void flushStdIn()
{
	char c;
	do c = getchar();
	while (c != '\n' && c != EOF);
}

// Ask for details from user for the given selection and perform that action
// Read the code in the function, case by case
void executeAction(char c)
{
	char studentName_input[MAX_NAME_LENGTH], major_input[MAX_NAME_LENGTH];
	unsigned int IDNumber_input, result = 0;
	char schoolYear_input[20];
	switch (c)
	{
	case 'a':	// add student
		// input student details from user
		printf("\nEnter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Enter major: ");
		fgets(major_input, sizeof(major_input), stdin);
		major_input[strlen(major_input) - 1] = '\0';	// discard the trailing '\n' char

		printf("Enter whether student is 'freshman' or 'sophomore' or 'junior' or 'senior': ");
		fgets(schoolYear_input, sizeof(schoolYear_input), stdin);
		schoolYear_input[strlen(schoolYear_input) - 1] = '\0';	// discard the trailing '\n' char
		printf("Please enter ID number: ");
		scanf("%d", &IDNumber_input);
		flushStdIn();

		// add the student to the list
		result = addSort(studentName_input, major_input, schoolYear_input, IDNumber_input);
		if (result == 0)
			printf("\nStudent is already on the list! \n\n");
		else if (result == 1)
			printf("\nStudent successfully added to the list! \n\n");

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'r':		// remove a student
		printf("\nPlease enter student name: ");
		fgets(studentName_input, sizeof(studentName_input), stdin);
		studentName_input[strlen(studentName_input) - 1] = '\0';	// discard the trailing '\n' char

		// delete the node
		result = deleteNode(studentName_input);
		if (result == 0)
			printf("\nStudent does not exist! \n\n");
		else if (result == 1)
			printf("\nStudent successfully removed from the list. \n\n");
		else
			printf("\nList is empty! \n\n");
		break;

	case 'q':		// quit
		break;
	default: printf("%c is invalid input!\n", c);
	}
}

// Q1 : addSort 
// This function is used to insert a new student into the list. You can insert the new student to the end of the linked list.
// Do not allow the student to be added to the list if that student already exists in the list. You can do that by checking the names of the students already in the list.
// If the student already exists then return 0 without adding student to the list. If the student does not exist in the list then go on to add the student at the end of the list and return 1.
// NOTE: You must convert the string 'schoolYear_input' to an enum type and store it in the list because the struct has enum type for school year.
// Sorting should happen within the list. That is, you should not create a new linked list of students having sorted students.
// Hint: One of the string library function can be useful to implement this function because the sorting needs to happen by student name which is a string.
//       Use swapNodes() to swap the nodes in the sorting logic

int addSort(char* studentName_input, char* major_input, char* schoolYear_input, unsigned int IDNumber_input) // 20 points
{
	struct studentRecord* tempList = list;	// work on a copy of 'list'
	// enter code here
	struct studentRecord* newRecord = malloc(sizeof(struct studentRecord));

	// convert school year input string into enum
	schoolYearType Year;
	Year = 0;
	if (strcmp(schoolYear_input, "freshman") == 0) {
		Year = freshman;
	} else if (strcmp(schoolYear_input, "sophomore") == 0) {
		Year = sophomore;
	}
	else if (strcmp(schoolYear_input, "junior") == 0) {
		Year = junior;
	}
	else if (strcmp(schoolYear_input, "senior") == 0) {
		Year = senior;
	}
	else {
		printf("\ninvalid input, school year will default to freshman\n");
	}

	// check if list is empty
	if (list == NULL) {
		// add student to begining of list
		strcpy(newRecord->studentName, studentName_input);
		strcpy(newRecord->major, major_input);
		newRecord->schoolYear = Year;
		newRecord->IDNumber = IDNumber_input;
		newRecord->next = NULL;
		list = newRecord;
	} else {
		// traverse list to look for duplicate record
		while (tempList != NULL) {
			if (strcmp(tempList->studentName, studentName_input) == 0) {
				return 0;
			}
			else if (tempList->next != NULL) {
				tempList = tempList->next;
			}
			else {
				break;
			}
		}
		// add student to end of list
		strcpy(newRecord->studentName, studentName_input);
		strcpy(newRecord->major, major_input);
		newRecord->schoolYear = Year;
		newRecord->IDNumber = IDNumber_input;
		newRecord->next = NULL;
		tempList->next = newRecord;
	}

	if (countNodes() > 1) {
		tempList = list;
		while(tempList != NULL) {
			if (strcmp(tempList -> studentName, newRecord -> studentName) > 0) {
				swapNodes(tempList, newRecord);	
				break;
			}
			tempList = tempList -> next;
		}
	}
	return 1;	// edit this line as needed
}

// Q2 : displayList (10 points)
// This function displays the linked list of students, with all details (struct elements). 
// Parse through the linked list and print the student details one after the other. See expected output screenshots in homework question file.
// NOTE: School year is stored in the struct as enum type. You need to display a string for school year.
void displayList()
{
	struct studentRecord* tempList = list;				// work on a copy of 'list'
	// enter code here
	while (tempList) {
		// convert school year enum into string 
		char Year[10];
		switch (tempList->schoolYear) {
		case freshman:
			strcpy(Year, "freshman");
			break;
		case sophomore:
			strcpy(Year, "sophomore");
			break;
		case junior:
			strcpy(Year, "junior");
			break;
		default:
			strcpy(Year, "senior");
			break;
		}
		printf("\nStudent Name: %s\n", tempList->studentName);
		printf("Student Major: %s\n", tempList->major);
		printf("SchoolYear: %s\n", Year);
		printf("ID Number: %d\n", tempList->IDNumber);
		tempList = tempList->next;
	}

}

// Q3: countNodes (5 points)
// This function counts the number of students on the linked list and returns the number.
// You may use this function in other functions like deleteNode(), sortList(), addNode(), if needed. 
// It can helpful to call this function in other functions, but not necessary.
// This function is called in main() to display number of students along with the user menu.
int countNodes()
{
	struct studentRecord* tempList = list;                          // work on a copy of 'list'
	int count = 0;
	while (tempList) {
		count++;
		tempList = tempList->next;
	}
	return count;	// edit this line as needed
}

// Q4 : deleteNode (10 points)
// This function deletes the node specified by the student name.
// Parse through the linked list and remove the node containing this student name.
// NOTE: After you remove the node, make sure that your linked list is not broken.
// (Hint: Visualize the list as: list......-> node1 -> node_to_remove -> node2 -> ...end. 
//        After removing "node_to_remove", the list is broken into "list ....node1" and "node2.... end". Stitch these lists.)

int deleteNode(char* studentName_input)
{
	// return 0 if list is empty
	if (list == NULL) {
		return 0;
	}

	struct studentRecord* prev = list;
	struct studentRecord* tempList = list->next;
	
	// remove first node if it matches student name input
	if (strcmp(prev -> studentName, studentName_input) == 0) {
		if (prev -> next != NULL) {
			list = list -> next;
			free(prev);
		} else {
			list = NULL;
			free(list);
		}
		return 1;
	}
	
	while (tempList) {
		if (strcmp(tempList->studentName, studentName_input) == 0) {
			if (tempList -> next != NULL) {
				prev -> next = tempList -> next;
				free(tempList);
			} else {
				prev -> next = NULL;
				free(tempList);
			}
			return 1;
		}
		prev = tempList;
		tempList = tempList -> next;
	}

	return 0;			// edit this line as needed
}


// Q5 : swapNodes (5 points)
// This function swaps the elements of parameters 'node1' and 'node2' (Here node1 does NOT mean 1st node of the list. 'node1' is just the name of the node)
// This function should not alter the 'next' element of the nodes. Only then will the nodes be swapped.
// Hint: The swap logic is similar to swapping two simple integer/string variables.
// NOTE: This function can be used in the sorting logic in addSort()

void swapNodes(struct studentRecord* node1, struct studentRecord* node2)
{
	struct studentRecord* tempList = malloc(sizeof(struct studentRecord));
	
	strcpy(tempList -> studentName, node1 -> studentName);
	strcpy(tempList -> major, node1 -> major);
	tempList -> schoolYear = node1 -> schoolYear;
	tempList -> IDNumber = node1 -> IDNumber;

	strcpy(node1 -> studentName, node2 -> studentName);
        strcpy(node1 -> major, node2 -> major);
        node1 -> schoolYear = node2 -> schoolYear;
        node1 -> IDNumber = node2 -> IDNumber;

	strcpy(node2 -> studentName, tempList -> studentName);
        strcpy(node2 -> major, tempList -> major);
        node2 -> schoolYear = tempList -> schoolYear;
        node2 -> IDNumber = tempList -> IDNumber;
}



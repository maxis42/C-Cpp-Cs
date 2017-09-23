//
// Created by Maxim on 11.05.2017.
//
#include <iostream>
#include <algorithm>
#include <cstring>
#include "functions.h"
using namespace std;


void printMenu() {
	printf("\n\tMenu options:");
	printf("\n\t1 - Initialize database with max number of employees");
	printf("\n\t2 - Fill database with employees");
	printf("\n\t3 - Show database");
	printf("\n\t4 - Delete database");
	printf("\n\t5 - Sort database");
	printf("\n\t0 - Exit\n");
}

void show_db(employee *database, int *n) {
	for (int i = 0; i < *n; i++) {
		printf("\n\tEmployee #%d", i + 1);
		printf("\n\t\tName: %s", database[i].name);
		printf("\n\t\tSurname: %s", database[i].surname);
		printf("\n\t\tYear of birth: %d", database[i].yearOfBirth);
		printf("\n\t\tSalary: %d", database[i].salary);
		printf("\n");
	}
}

void fill_db(employee *database, int *n) {
	printf("\n\tMax number of employees: %d", *n);
	printf("\n\n");
	for (int i = 0; i < *n; i++) {
		printf("\tEmployee #%d\n", i + 1);

		printf("\t\tInput name: ");
		scanf("%s", &database[i].name);

		printf("\t\tInput surname: ");
		scanf("%s", &database[i].surname);

		printf("\t\tInput year of birth: ");
		scanf("%d", &database[i].yearOfBirth);

		printf("\t\tInput salary: ");
		scanf("%d", &database[i].salary);

		printf("\n");
	}
}

void delete_db(employee *database, int *n) {
	delete []database;
}

void sort_db(employee *database, int *n) {
	printf("\n\tPlease choose how to sort the database:");
	printf("\n\t\t- input '1' for sorting on names");
	printf("\n\t\t- input '2' for sorting on surnames");
	printf("\n\t\t- input '3' for sorting on years of birth");
	printf("\n\t\t- input '4' for sorting on salaries");
	printf("\n");
	printf("\n\tYour input >> ");
	int sortOption;
	scanf("%d", &sortOption);

	if (sortOption == 1) sort(database, database + *n, [](employee a, employee b){return strcmp(a.name, b.name);});
	else if (sortOption == 2) sort(database, database + *n, [](employee a, employee b){return strcmp(a.surname, b.surname);});
	else if (sortOption == 3) sort(database, database + *n, [](employee a, employee b){return a.yearOfBirth < b.yearOfBirth;});
	else if (sortOption == 4) sort(database, database + *n, [](employee a, employee b){return a.salary < b.salary;});
	else printf("\n\tIncorrect input!");
}

employee *create_db(int *n) {
	printf("\n\tPlease input max number of employees >> ");
	scanf("%d", n);

	employee *database = new employee[*n];

	return database;
}

int chooseMenu() {
	int menu_option(0);
	scanf("%d", &menu_option);
	return menu_option;
}

void printDatabaseNotInitialised() {
	printf("\n\tYou haven't initialised the employee database yet!\n\t");
}

void startProgram() {
	printf("\n\tTask: Create employee database program with menu.");
	printf("\n\n\tDatabase\n");

	int menuOption = -1; //menu option
	bool dbCreatedFlag = false; //flag if the array is created
	int n(0); //n - number of words, m - max word length
	employee *employeeDatabase;
	printMenu();
	while (menuOption) {

		printf("\n\tPlease make input (-1 for menu) >> ");
		menuOption = chooseMenu();

		switch (menuOption) {

			case -1: { //print menu
				printMenu();
				break;
			}

			case 0: { //exit
				printf("\n\tBye-bye!\n\t");
				break;
			}

			case 1: { //create database
				employeeDatabase = create_db(&n);
				dbCreatedFlag = true; //array is created
				break;
			}

			case 2: { //fill database
				if (dbCreatedFlag) fill_db(employeeDatabase, &n);
				else printDatabaseNotInitialised();
				break;
			}

			case 3: { //show database
				if (dbCreatedFlag) show_db(employeeDatabase, &n);
				else printDatabaseNotInitialised();
				break;
			}

			case 4: { //delete database
				if (dbCreatedFlag) delete_db(employeeDatabase, &n);
				else printDatabaseNotInitialised();
				break;
			}

			case 5: { //sorting database
				if (dbCreatedFlag) sort_db(employeeDatabase, &n);
				else printDatabaseNotInitialised();
				break;
			}

			default: printf("\n\tPlease make correct input!\n\t");
		}
	}
}
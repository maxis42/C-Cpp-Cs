//
// Created by Maxim on 11.05.2017.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct employee {
	char
			name[20],
			surname[20];
	int
			yearOfBirth,
			salary;
};

int chooseMenu();

employee *create_db(int *n);

void delete_db(employee *database, int *n);

void sort_db(employee *database, int *n);

void fill_db(employee *database, int *n);

void show_db(employee *database, int *n);

void startProgram();

void printMenu();

void printDatabaseNotInitialised();

#endif //FUNCTIONS_H

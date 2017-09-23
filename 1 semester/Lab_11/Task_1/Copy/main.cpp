#include <iostream>
#include "functions.h"

int choose_menu();

char **create_dict(size_t *n, size_t *m);

void delete_dict(char **dictionary, size_t *n);

void fill_dict(char **dictionary, size_t *n);

void show_dict(char **dictionary, size_t *n);

void start_menu();

void print_menu();





int main() {
	printf("\n\tTask: Create dictionary program with menu.");

	start_menu();

	system("pause");
	return 0;
}





void print_menu() {
	printf("\n\tMenu options:");
	printf("\n\t1 - Initialize dictionary (size & length)");
	printf("\n\t2 - Fill dictionary with words");
	printf("\n\t3 - Show dictionary");
	printf("\n\t4 - Delete dictionary");
	printf("\n\t0 - Exit\n");
}

void show_dict(char **dictionary, size_t *n) {
	for (size_t i = 0; i < *n; i++)
		printf("\n\tWord #%zd: %s", i + 1, dictionary[i]);
	printf("\n");
}

void fill_dict(char **dictionary, size_t *n) {
	printf("\n\n");
	for (size_t i = 0; i < *n; i++)
	{
		printf("\tInput word #%zd: ", i + 1);
		scanf("%s", dictionary[i]);
	}
}

void delete_dict(char **dictionary, size_t *n) {
	for (size_t i = 0; i < *n; i++)
		free ((void *)dictionary[i]);
	free ((void *)dictionary);
}

char **create_dict(size_t *n, size_t *m) {
	printf("\n\tPlease input number of words: ");
	scanf("%zd", n);
	printf("\n\tPlease input maximum word length: ");
	scanf("%zd", m);

	char **dict = (char **)calloc(*n, sizeof(char *));
	for (size_t i = 0; i < *n; i++)
		dict[i] = (char *)calloc(*m, sizeof(char));

	return dict;
}

int choose_menu() {
	int menu_option(0);
	scanf("%d", &menu_option);
	return menu_option;
}

void start_menu() {
	printf("\n\n\tDictionary\n");

	int menu_opt = -1; //menu option
	bool dict_flag = false; //flag if the array is created
	size_t n(0), m(0); //n - number of words, m - max word length
	char **dictionary(nullptr);
	print_menu();
	while (menu_opt)
	{
		printf("\n\tPlease make input (-1 for menu)>: ");
		menu_opt = choose_menu();
		switch (menu_opt)
		{
			case -1:
			{
				print_menu();
				break;
			}
			case 0:
			{
				printf("\n\tBye-bye!\n\t");
				break;
			}
			case 1:
			{
				dictionary = create_dict(&n, &m);
				dict_flag = true; //array is created
				break;
			}
			case 2:
			{
				if (dict_flag)
				{
					printf("\n\tMax words: %zd", n);
					printf("\n\tMax word length: %zd", m);
					fill_dict(dictionary, &n);
				}
				else printf("\n\tYou haven't initialised the dictionary yet!\n\t");
				break;
			}
			case 3:
			{
				if (dict_flag) show_dict(dictionary, &n);
				else printf("\n\tYou haven't initialised the dictionary yet!\n\t");
				break;
			}
			case 4:
			{
				if (dict_flag) delete_dict(dictionary, &n);
				else printf("\n\tYou haven't initialised the dictionary yet!\n\t");
				break;
			}
			default: printf("\n\tPlease make correct input!\n\t");
		}
	}
}
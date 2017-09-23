//
// Created by Maxim on 11.05.2017.
//

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

int choose_menu();

char **create_dict(size_t *n, size_t *m);

void delete_dict(char **dictionary, size_t *n);

void fill_dict(char **dictionary, size_t *n);

void show_dict(char **dictionary, size_t *n);

void start_menu();

void print_menu();

#endif //FUNCTIONS_H

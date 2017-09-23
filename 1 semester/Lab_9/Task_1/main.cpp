#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

int main() {

	printf("\n\tTask:");
	printf("\n\t1. Parse a string and pop words separated with spaces.");
	printf("\n\t2. Sort the array of pointers on words in alphabetical order.\n\t");

	//Input string from console
	const size_t N(1024);
	char str_input[N];
	printf("\n\tPlease input string: ");
	gets(str_input);
	printf("\n\tYour input: \"");
	fputs(str_input, stdout);
	printf("\"\n");
	//----------

	//Form new string from inputted one without any spaces
	// at the beginning and in the end of string
    printf("\n\tDeleting trailing, leading and duplicating spaces...\n");

    //1. Delete leading spaces
	if (str_input[0] == ' ')
	{
		size_t cnt_first_letter = 0;
	  while (!isalnum(str_input[cnt_first_letter])) cnt_first_letter++;
		for (size_t i = 0; i < strlen(str_input); i++)
		{
			str_input[i] = str_input[i + cnt_first_letter];
		}
	}

    //2. Delete trailing spaces
	if (str_input[strlen(str_input) - 1] == ' ')
	{
		size_t cnt_last_letter = strlen(str_input) - 1;
	  while (!isalnum(str_input[cnt_last_letter])) cnt_last_letter--;
			str_input[cnt_last_letter + 1] = '\0';
	}

	//3. Delete duplicating spaces
	for (size_t i = 0; i < strlen(str_input); i++)
	{
		if (str_input[i] == ' ')
		{
			size_t num_of_spaces = 0;
			size_t j = i;
			while (!isalnum(str_input[j++])) num_of_spaces++;
			if (num_of_spaces > 1)
			{
				for (size_t k = i + 1; k < strlen(str_input); k++)
				{
					str_input[k] = str_input[k + num_of_spaces - 1];
				}
			}
		}
	}

	printf("\n\tAdjusted string on spaces: \"");
	fputs(str_input, stdout);
	printf("\"\n");
	//----------

	//Number of words
	size_t words_num = 1;
	for (size_t i = 0; i < strlen(str_input); i++)
	{
		if (str_input[i] == ' ') words_num++;
	}
	printf("\n\tNumber of words: %zd", words_num);
	//----------

	//Array of pointers on words
	//Change spaces on '\0' in order to separate words
	char **p_words = (char **)calloc(words_num, sizeof(char *));
	size_t j = 0;
	p_words[j++] = &str_input[0];
	size_t str_input_len = strlen(str_input);
	for (size_t i = 0; i < str_input_len; i++)
	{
		if (str_input[i] == ' ')
		{
			p_words[j] = &str_input[i + 1];
			str_input[i] = '\0';
			j++;
		}
	}

	printf("\n\n\tPrinting words:");
	for (size_t i = 0; i < words_num; i++)
	{
		printf("\n\t%s", p_words[i]);
	}
	//----------

	//Sorting the array of pointers on words in alphabetical order
	for (size_t i = 0; i < words_num - 1; i++)
	{
		size_t cnt = 0;
		for (size_t j = 0; j < words_num - 1 - i; j++)
		{
			if (strcmp(p_words[j], p_words[j + 1]) > 0)
			{
				char *tmp = p_words[j];
				p_words[j] = p_words[j + 1];
				p_words[j + 1] = tmp;
				cnt++;
			}
		}
		if (!cnt) break;
	}

	printf("\n\n\tPrinting sorted:");
	for (size_t i = 0; i < words_num; i++)
	{
		printf("\n\t%s", p_words[i]);
	}
	//----------

	free ((void *)p_words[0]);
	free ((void *)p_words);

	system("pause");
	return 0;
}

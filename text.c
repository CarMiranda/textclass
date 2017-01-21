#include "text.h"
#include <stdio.h>
#include <stdlib.h>

char *newString(size_t strSize)
{
	char *str = (char *) malloc(sizeof(char) * (strSize + 1));
	memset(str, '\0', strSize + 1);
	return str;
}

void freeStr(char *str)
{
	free(str);
}

size_t strlen(char *str)
{
	size_t i = 0;
	while (str[i] != '\0') { ++i; }
	return i;
}

void printHelp()
{
	printf("Usage: text <command> [<options> [filename]]\n");
	printf("Commands:\n");

}

int main(int argc, char *argv[])
{
	if (argc > 1) {
		treatArgs(argc, argv);
		return 0;
	}

	printHelp();

	return 0;
}

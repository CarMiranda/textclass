#ifndef text_h
#define text_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct String_Struct *String;

struct String_Struct {
	
	// Properties
	size_t length; // Length of the string
	char *content; // The string content (text)
	
	// Methods
	void *(*init)(const void *self, size_t len); // Initializer
	void (*destroy)(const void *self); // Destructor
	size_t (*setLength)(const void *self, size_t newLength);
	size_t (*getLength)(const void *self); // Length getter
	void (*setContent)(const void *self, char *str); // Content setter
	char *(*getContent)(const void *self); // Content getter

	void *(*copy)(const void *self); // Copy string to a new string struct
	int (*compare)(const void *self, const void *otherStr); // Compares the string to another string
	void *(*toUpper)(const void *self); // Creates a copy of the string in upper case
	void *(*toLower)(const void *self); // Creates a copy of the string in lower case
	void *(*capitalize)(const void *self); // Creates a copy of the string capitalizing every word
	void *(*trim)(const void *self); // Creates a copy of the string without trailing blank spaces
	void *(*substring)(const void *self, int from, int to); // Creates a substring. Parameteres correspond to from and to indexes (included and excluded, respectively)
	char (*charAt)(const void *self, int i); // Returns the character of the string at the given index
	void *(*split)(const void *self, char s); // Splits the string into a String array based on a separator
	int *(*indexOf)(const void *self, char c); // Returns an array of integers corresponding to the indexes of appearances of the parameter

};

void *String_init(const void *self, size_t len);
void String_destroy(const void *self);
size_t String_setLength(const void *self, size_t newLength);
size_t String_getLength(const void *self);
void String_setContent(const void *self, char *str);
char *String_getContent(const void *self);
void *String_copy(const void *self);
int String_compare(const void *self, const void *otherStr);
void *String_toUpper(const void *self);
void *String_toLower(const void *self);
void *String_capitalize(const void *self);
void *String_trim(const void *self);
void *String_substring(const void *self, int from, int to);
char String_charAt(const void *self, int i);
void *String_split(const void *self, char s);
int *String_indexOf(const void *self, char c);

String String_new(size_t len);

#endif

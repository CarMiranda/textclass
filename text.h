#ifndef text_h
#define text_h

char *newString(size_t strSize);

void destroyString(char *str);

size_t strlen(char *str);

char *replaceChar(char *str, char chr);

char *replaceString(char *str1, char *str2);

#endif

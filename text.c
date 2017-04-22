#include "text.h"

#define MAXLEN 1024

void *String_init(const void *self, size_t len) {

	String str = (String) self;
	if (len < 0 || len > MAXLEN) {
		return NULL;
	}

	str->length = len;
	str->content = (char *) malloc(sizeof(char) * (len + 1));

	if (!str->content) {
		return NULL;
	}

	memset(str->content, '\0', len + 1);

	return str;

} 

void String_destroy(const void *self) {

	String str = (String) self;

	if (str) {
		if (str->content) { free(str->content); }
		free(str);
	}

}

size_t String_setLength(const void *self, size_t newLength) {
	
	size_t oldLength;
	String str = (String) self;
	char *strContent = NULL;

	if (newLength < 0 || newLength > MAXLEN) { return 1; }

	oldLength = str->length;
	if (newLength != oldLength) {
		strContent = (char *) malloc(sizeof(char) * (newLength + 1));
		if (!strContent) { return 2; }
		if (newLength < oldLength) {
			memcpy(strContent, str->content, newLength);
		} else {
			memcpy(strContent, str->content, oldLength);
			memset(strContent + newLength, '\0', newLength - oldLength);
	}
		free(str->content);
		str->content = strContent;
	}

	return newLength;

}

size_t String_getLength(const void *self) {

	String str = (String) self;

	if (!str) { return 0; }

	return str->length;

}

void String_setContent(const void *self, char *strContent) {

	String str = (String) self;

	size_t len = strlen(strContent);
	str->setLength(str, len);
	memcpy(str->content, strContent, len);

}

char *String_getContent(const void *self) {

	String str = (String) self;

	if (!str) { return '\0'; }
	return str->content;
}

void *String_copy(const void *self) {
	String str = (String) self;
	String copy = String_new(str->length);
	copy->setContent(copy, str->content);
	return copy;
}

int String_compare(const void *self, const void *otherStr) {
	String str1 = (String) self;
	String str2 = (String) otherStr;
	return strcmp(str1->content, str2->content);
}

void *String_toUpper(const void *self) {

	String str = (String) self;
	size_t i, len = str->length;
	for (i = 0; i < len; ++i) {
		str->content[i] = toupper(str->content[i]);
	}
	return str;

}

void *String_toLower(const void *self) {

	String str = (String) self;
	size_t i, len = str->length;
	for (i = 0; i < len; ++i) {
		str->content[i] = tolower(str->content[i]);
	}
	return str;

}

void *String_capitalize(const void *self) {

	String str = (String) self;
	size_t i, len = str->getLength(str);
	for (i = 1; i < len; ++i) {
		if (isspace(str->content[i - 1])) {
			str->content[i] = toupper(str->content[i]);
		}
	}
	return str;

}

void *String_trim(const void *self) {
	String str = (String) self;
	size_t i, j = 0, len = str->length;
	char *newStr = (char *) malloc(sizeof(char) * (len + 1));
	for (i = 0; i < len - 1; ++i) {
		if (isblank(str->content[i]) && isblank(str->content[i + 1])) {
			continue;
		}
		newStr[j] = str->content[i];
		j++;
	}
	newStr[j] = '\0';
	str->setContent(str, newStr);

	return str;
}

void *String_substring(const void *self, int from, int to) {
	String str = (String) self, substr;
	char *substrContent;
	size_t len = str->length;

	if (from < 0 || from > len || to < 0 || to > len) {
		return NULL;
	}

	if (from < to) {
		
	} else if {from > to} {

	} else {
		substr = String_new(1);
		substr->setContent(substr, str->content[from]);
	}

}

char String_charAt(const void *self, int i) {
	String str = (String) self;

	if (i < 0 || i > str->length) { return 1; }

	return str->content[i];
}

void *String_split(const void *self, char s) {
	
}

int *String_indexOf(const void *self, char c) {
	String str = (String) self;
	size_t i, j = 0, len = str->length;
	int indexes[];

	for (i = 0; i < len; ++i) {
		if (str->content[i] == c) {
			indexes[j] = i;
			j++;
		}
	}

	return indexes;
}

String String_new(size_t len) {

	String self = (String) malloc(sizeof(struct String_Struct));

	// Set up the default functions
	self->init = String_init;
	self->destroy = String_destroy;
	self->setLength = String_setLength;
	self->getLength = String_getLength;
	self->setContent = String_setContent;
	self->getContent = String_getContent;
	self->copy = String_copy;
	self->compare = String_compare;
	self->toUpper = String_toUpper;
	self->toLower = String_toLower;
	self->capitalize = String_capitalize;
	self->trim = String_trim;
	self->substring = String_substring;
	self->charAt = String_charAt;
	self->split = String_split;
	self->indexOf = String_indexOf;

	self->init(self, len);

	return self;

}

size_t strlen(const char *str) {
	size_t i;

	i = 0;
	while (str[i] != '\0') { ++i; }

	return i;
}

char charAt(char *str, int index) {
	if (strlen(str) < index) {
		return '\0';
	} else {
		return str[index];
	}
}

int strcmp(const char *str1, const char *str2) {
	int i;
	size_t slen1, slen2;
	
	i = 0;
	slen1 = strlen(str1);
	slen2 = strlen(str2);

	if (slen1 < slen2) {
		return -1;
	} else if (slen1 > slen2) {
		return 1;
	} else {
		while (i < slen1) {
		       if (str1[i] < str2[i]) {
		       		return -1;
		       } else if (str1[i] > str2[i]) {
	       			return 1;
		       }
		       i++;
		}
	}

	return 0;
}

char *strsrch(char *text, char *str) {
	size_t txtlen = strlen(text), strl;
}

char *replaceString(char *text, char *str1, char *str2) {
	size_t txtlen = strlen(text);
	int i, j;
	for (i = 0; i < txtlen; i++) {
		if (str1[i] == str2[i]) {
			j = i + 1;
			while ((str1[j] == str2[j]) && (j < txtlen + i)) {
				j++;
			}
		}
	}
}

void treatArgs(int argc, char *argv[]) {
	char *command = argv[1];

	if (!strcmp("compare", command)) {
		int res = strcmp(argv[2], argv[3]);
		if (res > 0) {
			printf("%s is greater than %s\n", argv[2], argv[3]);
		} else if (res < 0) {
			printf("%s is greater than %s\n", argv[3], argv[2]);
		} else {
			printf("Strings are equal: %s\n", argv[2]);
		}
	}
}

void printHelp() {
	printf("Usage: text <command> [<options> [filename]]\n");
	printf("Commands:\n");

}

int main(int argc, char *argv[]) {
	if (argc > 1) {
		treatArgs(argc, argv);
		return 0;
	}

	printHelp();

	return 0;
}

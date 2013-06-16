#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int getConfSectionValue(char *conf, char *section, char *keyName, char *keyVal, int *lineNum);

int setConfSectionValue(char *conf, char *section, char *keyName, char *keyVal);


char *l_trim(char * szOutput, const char *szInput);
char *r_trim(char *szOutput, const char *szInput);
char *a_trim(char * szOutput, const char * szInput);

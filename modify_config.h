#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
 * conf 为conf文件的路径 section 为 setcion  keyname 为key的名字
 * keyVal 返回查到的值  lineNum返回所在行
 * 返回0表示成功， -1 keyName不存在 -2 section不存在 -3为文件打开失败
 */
int getConfSectionValue(char *conf, char *section, char *keyName, char *keyVal, int *lineNum);

/*
 * type -1 keyName不存在 -2 section不存在
 * 返回0 成功， -3 文件打开失败
 */
int setConfSectionValue(char *conf, char *section, char *keyName, char *keyVal, int lineNum, int type);

/*
 *删除整个section 包括其子项
 *返回0表示成功
 */
int rmConfSection(char *conf, char *section);

char *l_trim(char * szOutput, const char *szInput);
char *r_trim(char *szOutput, const char *szInput);
char *a_trim(char * szOutput, const char * szInput);

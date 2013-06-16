#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
 
#include "modify_config.h"

#define KEYVALLEN 100

int setConfSectionValue(char *conf, char *section, char *keyName, char *keyVal)
{

}

int getConfSectionValue(char *conf, char *section, char *keyName, char *keyVal)
{
  char sectionname[32], keyname[32];
  FILE *fp;
  char *buf,*c;
  char buf_i[KEYVALLEN], buf_o[KEYVALLEN];
  int found = 0;
  if((fp = fopen(conf, "r")) == NULL)
  {
    printf("openfile [%s] error[%s] \n", conf, strerror(errno));
    return(-1);
  }
  fseek(fp, 0, SEEK_SET);
  memset(sectionname, 0, sizeof(sectionname));
  sprintf(sectionname, "[%s]", section);
  while( !feof(fp) && fgets( buf_i, KEYVALLEN, fp )!=NULL )
  {
    l_trim(buf_o, buf_i);
    if( strlen(buf_o) <= 0 )
      continue;
    buf = NULL;
    buf = buf_o;  

    if( found == 0 ){
      if( buf[0] != '[' ) {
        continue;
      } else if ( strncmp(buf, sectionname, strlen(sectionname))==0 ){
        found = 1;
        continue;
      }

    } else if(found == 1 ){
      if( buf[0] == ';' ){
        continue;
      } else if ( buf[0] == '[' ){
        break;
      } else{
        if( (c = (char*)strchr(buf, '=')) == NULL )
          continue;
        memset( keyname, 0, sizeof(keyname) ); 

	sscanf( buf, "%[^=|^ |^\t]", keyname );
	if( strcmp(keyname, keyName) == 0 ){
          sscanf( ++c, "%[^\n]", keyVal );
	  char *KeyVal_o = (char *)malloc(strlen(keyVal) + 1);
	  if(KeyVal_o != NULL){
	    memset(KeyVal_o, 0, sizeof(KeyVal_o));
	    a_trim(KeyVal_o, keyVal);
	    if(KeyVal_o && strlen(KeyVal_o) > 0)
	      strcpy(keyVal, KeyVal_o);
	    free(KeyVal_o);
	    KeyVal_o = NULL;
          }
          found = 2;
          break;
        }else{
          continue;
        }
      }

    }

  }
  fclose( fp );
  if( found == 2)
    return 0;
  else
    return -1;
}



/* private */
/* 删除左边的空格*/
char * l_trim(char * szOutput, const char *szInput)
{
 assert(szInput != NULL);
 assert(szOutput != NULL);
 assert(szOutput != szInput);
 for   (NULL; *szInput != '\0' && isspace(*szInput); ++szInput){
  ;
 }
 return strcpy(szOutput, szInput);
}

/*   删除右边的空格   */
char *r_trim(char *szOutput, const char *szInput)
{
 char *p = NULL;
 assert(szInput != NULL);
 assert(szOutput != NULL);
 assert(szOutput != szInput);
 strcpy(szOutput, szInput);
 for(p = szOutput + strlen(szOutput) - 1; p >= szOutput && isspace(*p); --p){
  ;
 }
 *(++p) = '\0';
 return szOutput;
}

/*   删除两边的空格   */
char * a_trim(char * szOutput, const char * szInput)
{
 char *p = NULL;
 assert(szInput != NULL);
 assert(szOutput != NULL);
 l_trim(szOutput, szInput);
 for   (p = szOutput + strlen(szOutput) - 1;p >= szOutput && isspace(*p); --p){
  ;
 }
 *(++p) = '\0';
 return szOutput;
}
/* test */
int main()
{
 char host[32];
 getConfSectionValue("./sample.ceph.conf", "osd.0", "host", host);
 printf("%s\n", host);
 return 0;
}




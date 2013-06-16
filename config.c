#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
 
#include "config.h"

#define KEYVALLEN 100



int getConfSectionValue(char *conf, char *section, char *keyName, char *keyVal)
{
  char sectionname[32], keyname[32];
  FILE *fp;
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

  }

}

int main()
{
 char ip[32];
 getConfSectionValue("./sample.ceph.conf", "osd.0", "hostname", ip);
 printf("%s\n",ip);
 return 0;
}




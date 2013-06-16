#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include "config.h"

int main()
{
 char ip[32];
 config::getConfSectionValue("./sample.ceph.conf", "osd.0", "hostname", ip);
 printf("%s\n",ip);
 return 0;
}

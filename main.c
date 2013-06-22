#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

#include "modify_config.h"

int main(){
  char host[32];
  int result;
  int lineNum; 
  result = getConfSectionValue("./sample.ceph.conf", "undefine", "undefine", host, &lineNum);
  printf("result is %d,  %s, %d\n", result, host, lineNum);
  result = getConfSectionValue("./sample.ceph.conf", "osd.0", "undefine", host, &lineNum);
  printf("result is %d,  %s, %d\n", result, host,lineNum);
  result = getConfSectionValue("./sample.ceph.conf", "undefine", "host", host, &lineNum);
  printf("result is %d,  %s, %d\n", result, host, lineNum);
  result = getConfSectionValue("./sample.ceph.conf", "osd.0", "host", host, &lineNum);
  printf("result is %d,  %s, %d\n", result, host, lineNum);
  result = getConfSectionValue("./sample.ceph.conf", "global", "pid\0file", host, &lineNum);
  printf("result is %d,  %s, %d\n", result, host, lineNum);
 
//  result = getConfSectionValue("./sample.ceph.conf", "osd.11", "host", "name", &lineNum);
//  result = setConfSectionValue("./sample.ceph.conf", "osd.11", "host", "name", lineNum, result);
//  result = getConfSectionValue("./sample.ceph.conf", "osd.11", "devs", "/dev/sdy", &lineNum);
//  result = setConfSectionValue("./sample.ceph.conf", "osd.11", "devs", "/dev/sdy", lineNum, result);
  
  return 0;
}

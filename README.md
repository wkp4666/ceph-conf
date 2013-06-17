ceph-conf
=========

read and write conf file for ceph
对ceph.conf文件进行修改（读写）

##提供对ceph.conf 文件的读取与修改.

ceph.conf 文件主要规则     
1. ； 为注释文字   
2. [section]  
3.  keyName=keyVal


##主要功能：

* 读ceph.onf 的值:
    *  getConfSectionValue(char *conf, char *section, char *keyName, char *keyVal, int *lineNum)

* 向ceph.conf插入值:(TODO)    
    *  setConfSectionValue(char *conf, char *section, char *keyName, char *keyVal, int *lineNum)




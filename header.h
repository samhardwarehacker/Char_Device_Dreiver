#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/cdev.h>
#include "operations.h"
#include<linux/moduleparam.h>

#ifndef DEBUG 
#define DEBUG
#endif

#ifndef DEVICE_NAME
#define DEVICE_NAME "SOM_DEVICE_DRIVER"
#endif

#ifndef MAJOR_NUM
#define MAJOR_NUM  0
#endif

#ifndef MINOR_NUM
#define MINOR_NUM  0
#endif

#ifndef NOD
#define NOD  1
#endif

#ifndef NOREG 
#define NOREG  8
#endif

#ifndef REGSIZE 
#define REGSIZE 8
#endif

#ifndef DEVSIZE 
#define DEVSIZE 1024
#endif

#ifndef DATASIZE 
#define DATASIZE 0
#endif

extern dev_t devid,devno;
extern int major_num,minor_num,nod,noreg,regsize,devsize,datasize;
void mymodule(void);

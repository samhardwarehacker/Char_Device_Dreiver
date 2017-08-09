#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include "operations.h"

#ifndef DEVICE_NAME
#define DEVICE_NAME "TEST_DRIVER"
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
extern dev_t devid;
extern int major_num,minor_num,nod;

//void mymodule(void);

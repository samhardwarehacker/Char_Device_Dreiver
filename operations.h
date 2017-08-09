 static struct file_operations  fops={};

typedef struct Qset
{
  struct Qset *next;
  void **data;
}Qset;

typedef struct Dev
{
  struct Qset *first;
  struct cdev c_dev;
  int noreg;
  int regsize;
  int devsize;
  int datasize;
}Dev;

extern Dev *dev;

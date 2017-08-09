// static struct file_operations  fops={};

typedef struct Qset
{
  struct Qset *next;
  void **data;
}Qset;

typedef struct Dev
{
  struct Qset *first;
}Dev;

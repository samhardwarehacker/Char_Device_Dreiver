#include "header.h"
#include "declaration.h"

static void __exit end_func(void)
{

   printk(KERN_INFO "Bye Bye\n");
   unregister_chrdev_region(devid,nod);
}

module_exit(end_func);

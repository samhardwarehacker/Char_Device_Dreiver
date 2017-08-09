#include "header.h"

static void __exit end_func(void)
{
  int i=0;
   #ifdef DEBUG
   printk(KERN_INFO "Bye Bye\n");
   #endif
   for(i=0;i<nod;i++)
   {
   cdev_del(&dev[i].c_dev);
   }
   kfree(dev);
   unregister_chrdev_region(devid,nod);
}

module_exit(end_func);

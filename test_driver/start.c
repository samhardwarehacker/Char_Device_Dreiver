#include "header.h"
#include "declaration.h"

// ------------------------------------------------------------------
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOMNATH");
//------------------------------------------------------------------
EXPORT_SYMBOL(mymodule);
int major_num = MAJOR_NUM;
int minor_num = MINOR_NUM;
int nod = NOD;
dev_t devid = 0;
static int __init start_func(void)
{
  printk(KERN_INFO "Hellow kernel\n");
  // ------------------------------Driver registration---------------------------------------------------
  if(!devid)
  {
  	if( alloc_chrdev_region(&devid,minor_num,nod,DEVICE_NAME)== -1)
    		{
    			printk(KERN_ERR "Device Reegistration Failed\n");
    			goto OUT;
    		}
  }
  else
  {
    if(register_chrdev_region(devid,minor_num,DEVICE_NAME)== -1)
    	{
	  	printk(KERN_ERR "Device Registration Failed");
		goto OUT;
	}
  }
  printk(KERN_INFO "Test Device Register Successfully with Major Num:-  %d \t %d\n",MAJOR(devid),MINOR(devid));
  //------------------------- END -------------------------------------------------------------------------
  
  //------------------------ GETTING MEMORY TO SCULL DEVICES ----------------------------------------------
  if(!kmalloc((sizeof(Dev)*nod),GFP_KERNEL))
  {
     printk(KERN_ERR "Kmalloc failed\n");
     goto OUT;

  }
  else
  {
   printk(KERN_INFO "Memory Allocated successfully for scull devices\n");
  }

  return 0;

OUT:
 	return -1;
}

//----------------------------------------------------------------------------
//void mymodule(void)
//{
//  printk(KERN_INFO "%s function start\n",__func__);
//  printk(KERN_INFO "%s function end\n",__func__);
//}
module_init(start_func);

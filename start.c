#include "header.h"
// ------------------------------------------------------------------
MODULE_LICENSE("GPL");
MODULE_AUTHOR("SOMNATH");
//------------------------------------------------------------------
Dev *dev;
int major_num = MAJOR_NUM;
int minor_num = MINOR_NUM;
int nod = 0;
// this function is use to take command line argument for insmod command 
// example insmod ./module/lkm_test.ko nod=100
// we are passing value 100 for variable nod
module_param(nod,int,S_IRUGO);
//-----------------------------------------------------------------------
dev_t devid = 0,devno = 0;
static int __init start_func(void)
{
int i = 0;
// before send the device information take a copy of that in your init function
int noreg = NOREG;
int regsize = REGSIZE;
int devsize = DEVSIZE;
int datasize = DATASIZE;
//-----------------------------------------------------------------------------
#ifdef DEBUG
  printk(KERN_INFO "Hellow kernel\n");
#endif  
  // ------------------------------Driver registration---------------------------------------------------
  if(!devid)
  {
  	if( alloc_chrdev_region(&devid,minor_num,nod,DEVICE_NAME)== -1)
    		{
		        #ifdef DEBUG
    			printk(KERN_ERR "Device Reegistration Failed\n");
			#endif
    			goto OUT;
    		}
  }
  else
  {
    if(register_chrdev_region(devid,minor_num,DEVICE_NAME)== -1)
    	{
	        #ifdef DEBUG
	  	printk(KERN_ERR "Device Registration Failed");
		#endif
		goto OUT;
	}
  }
  major_num = MAJOR(devid);
  minor_num = MINOR(devid);
  #ifdef DEBUG
  printk(KERN_INFO "Device Register Successfully with Major Num:-  %d\n",major_num);
  #endif
  //------------------------- END -------------------------------------------------------------------------
  
  //------------------------ GETTING MEMORY TO SCULL DEVICES ----------------------------------------------
  dev = (Dev *)kmalloc((sizeof(Dev)*nod),GFP_KERNEL);
 if(!dev)
 {
     #ifdef DEBUG
     printk(KERN_ERR "Kmalloc failed\n");
     #endif
     goto OUT;

  }
  else
  {
   #ifdef DEBUG
   printk(KERN_INFO "Memory Allocated successfully for scull devices\n");
   #endif
  }
   memset(dev,'\0',sizeof(Dev)*nod);
//  mymodule();
  for(i=0;i<nod;i++)
  {
          dev[i].noreg=noreg;
	  dev[i].regsize=regsize;
	  dev[i].devsize=devsize;
          dev[i].datasize=datasize;
 	  dev[i].c_dev.ops = &fops;
  	  cdev_init(&dev[i].c_dev,dev[i].c_dev.ops);
 	 devno = MKDEV(major_num,i);
	 if(cdev_add(&dev[i].c_dev,devno,i)== -1)
 		{
		 #ifdef DEBUG
       		  printk(KERN_ERR "cdev_add error");
		 #endif
		 goto OUT;
		}  
	else
	{
 	#ifdef DEBUG
	//  printk(KERN_INFO "Minor num - %d\n",MINOR(devno));
	   printk(KERN_INFO "Minor num - %d\n",MINOR(dev[i].c_dev.dev));
	 #endif 
	}  
 } 
  return 0;

OUT:
 	return -1;
}

module_init(start_func);

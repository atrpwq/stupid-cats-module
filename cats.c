#include<linux/module.h>
#include<linux/random.h>
#define __RANDNUM get_random_u8() //random number generator

MODULE_AUTHOR("unknown"); //author signature
MODULE_LICENSE("GPL-1.0"); //license

static int __init modinit(void){ //initialize function (kinda like main in normal c programming)
	printk(KERN_INFO "%d Cats: Loaded module\n",__RANDNUM); //prints a random number then cats
	return 0; //returns 0 exit code
}

static void __exit modexit(void){ //exit function
	printk(KERN_INFO "%d Cats: Unloaded module\n",__RANDNUM); //prints a random number then exits
}

module_init(modinit); //module init func
module_exit(modexit); //module exit func

#include <linux/kernel.h>
#include <linux/module.h> 

MODULE_LICENSE("GPL");

int rate_limit_init(void) 
{
	int i;

	for(i=0;i<20;i++) {
		printk_once(KERN_INFO"Printing %d\n", i);
	}
	printk_once(KERN_INFO"Printing %d\n", i);
	return 0;
}

void rate_limit_exit(void)
{
	printk(KERN_INFO "Done\n");
}
module_init(rate_limit_init);
module_exit(rate_limit_exit);

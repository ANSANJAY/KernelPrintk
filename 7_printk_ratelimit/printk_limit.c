#include <linux/kernel.h>
#include <linux/module.h> 
#include <linux/delay.h>

int rate_limit_init(void) 
{
	int i;

	for(i=0;i<20;i++) {
		if(printk_ratelimit()) {
			printk(KERN_INFO"Printing %d\n", i+1);
		}
		else {
			pr_info("Sleeping for 5 seconds\n");
			//msleep(5000);
			//i--;
		}
	}
	return 0;
}

void rate_limit_exit(void)
{
	printk(KERN_INFO "Done\n");
}
module_init(rate_limit_init);
module_exit(rate_limit_exit);

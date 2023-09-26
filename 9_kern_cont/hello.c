#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    printk(KERN_CONT"%s: Hello", __func__);
    printk(KERN_CONT"World\n");
    return 0;
}

static void test_hello_exit(void)
{
    printk(KERN_INFO"%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

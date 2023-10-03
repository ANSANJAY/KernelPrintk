#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    printk("\001""4""%s: In init\n", __func__); //warning
    return 0;
}

static void test_hello_exit(void)
{
    printk("\001""2""%s: In exit\n", __func__); //crit
}

module_init(test_hello_init);
module_exit(test_hello_exit);

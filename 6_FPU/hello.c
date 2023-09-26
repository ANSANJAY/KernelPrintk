#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    float f = 2.56;
    printk("%s: In init, value of f is %f\n", __func__, f);
    return 0;
}

static void test_hello_exit(void)
{
    printk("%s: In exit\n", __func__);
}

module_init(test_hello_init);
module_exit(test_hello_exit);

#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
static int test_hello_init(void)
{
    char buffer[] = "Hello World. Linux is the best OS";
    print_hex_dump_bytes("buf: ", DUMP_PREFIX_ADDRESS,
                 buffer, sizeof(buffer));
    return 0;
}

static void test_hello_exit(void)
{
}

module_init(test_hello_init);
module_exit(test_hello_exit);

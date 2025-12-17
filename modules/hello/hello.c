#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("nesww");
MODULE_DESCRIPTION("Module hello");

static int __init hello_init(void) {
    printk(KERN_INFO "Hello from Kernel Space!\n");
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye Kernel Space!\n");
}

module_init(hello_init);
module_exit(hello_exit);

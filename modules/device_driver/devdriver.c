#include <asm-generic/errno-base.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

#define MOD_NAME "devdriver"
#define INTERNAL_BUFFER_SIZE 256

static ssize_t nread(struct file *filp, char* buffer, size_t length, loff_t *offset) {
    put_user('X', buffer);
    return 1;
}

static ssize_t nwrite(
    struct file *filp,
    const char *buffer,
    size_t length,
    loff_t *offset) {
    if (length >= INTERNAL_BUFFER_SIZE) {
        return 0;
    }
    char *kbuffer = kmalloc(INTERNAL_BUFFER_SIZE, GFP_KERNEL);
    if (copy_from_user(kbuffer, buffer, length)) {
        kfree(kbuffer);
        return -EFAULT;
    };
    kbuffer[length] = '\0';
    printk(KERN_INFO "devdriver: Received message: %s", kbuffer);
    kfree(kbuffer);
    return length;
}

static struct file_operations fops = {
    .read = nread,
    .write = nwrite
};
static int major;

static int __init init(void) {
   major = register_chrdev(0, MOD_NAME, &fops);
   printk(KERN_INFO "devdriver: Module loaded, major: %d\n", major);
   return 0;
}

static void __exit exit(void) {
    unregister_chrdev(major, MOD_NAME);
    printk(KERN_INFO "devdriver: Module unloaded, major: %d\n", major);
}

module_init(init);
module_exit(exit);
MODULE_LICENSE("GPL");

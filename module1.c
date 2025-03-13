// MODULE 1- INTIALIZATION,MODULE DEINTIALIZATION INTO KERNEL:

#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h> // Headers

static int __init module1_init(void)
{
    printk(KERN_INFO "inserted sucessfully\n"); // intialization of module
    return 0;
}

static void __exit module1_exit(void) // Deintialization of module
{
    printk(KERN_INFO "removed sucessfully\n");
}

module_init(module1_init); // macros
module_exit(module1_exit);

MODULE_LICENSE("GPL"); // aditional macros
MODULE_AUTHOR("VINAY_KUMAR_RATHOR");
MODULE_DESCRIPTION("UNDERSTANDING OF MODULE BASICS");
MODULE_VERSION("2.0");

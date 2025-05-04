#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("2024E8021682118");
#define MODULE_NAME "2024E8021682118_task1"

static char *mem1 = NULL;
static char *mem2 = NULL;

static int __init task1_init(void)
{
    // 分配 1KB
    mem1 = kmalloc(1024, GFP_KERNEL);
    if (!mem1)
    {
        printk(KERN_ERR "%s: 1KB allocation failed!\n", MODULE_NAME);
        return -ENOMEM;
    }
    printk(KERN_INFO "%s: kmalloc(1KB) addr = %p\n", MODULE_NAME, mem1);

    // 分配 8KB
    mem2 = kmalloc(8192, GFP_KERNEL);
    if (!mem2)
    {
        printk(KERN_ERR "%s: 8KB allocation failed!\n", MODULE_NAME);
        kfree(mem1);
        return -ENOMEM;
    }
    printk(KERN_INFO "%s: kmalloc(8KB) addr = %p\n", MODULE_NAME, mem2);
    return 0;
}

static void __exit task1_exit(void)
{
    if (mem1)
        kfree(mem1);
    if (mem2)
        kfree(mem2);
    printk(KERN_INFO "%s: Memory freed\n", MODULE_NAME);
}

module_init(task1_init);
module_exit(task1_exit);
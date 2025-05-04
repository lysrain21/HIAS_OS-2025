#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("2024E8021682118");
#define MODULE_NAME "2024E8021682118_task2"

static char *mem8k = NULL;
static char *mem1m = NULL;
static char *mem64m = NULL;

static int __init task2_init(void)
{
    // 分配 8KB
    mem8k = vmalloc(8192);
    if (!mem8k)
    {
        printk(KERN_ERR "%s: 8KB vmalloc failed!\n", MODULE_NAME);
        return -ENOMEM;
    }
    printk(KERN_INFO "%s: vmalloc(8KB) addr = %px\n", MODULE_NAME, mem8k);

    // 分配 1MB
    mem1m = vmalloc(1024 * 1024);
    if (!mem1m)
    {
        printk(KERN_ERR "%s: 1MB vmalloc failed!\n", MODULE_NAME);
        vfree(mem8k);
        return -ENOMEM;
    }
    printk(KERN_INFO "%s: vmalloc(1MB) addr = %px\n", MODULE_NAME, mem1m);

    // 分配 64MB（可能失败）
    mem64m = vmalloc(64 * 1024 * 1024);
    if (!mem64m)
    {
        printk(KERN_ERR "%s: 64MB vmalloc failed!\n", MODULE_NAME);
        vfree(mem8k);
        vfree(mem1m);
        return -ENOMEM;
    }
    printk(KERN_INFO "%s: vmalloc(64MB) addr = %px\n", MODULE_NAME, mem64m);
    return 0;
}

static void __exit task2_exit(void)
{
    if (mem8k)
        vfree(mem8k);
    if (mem1m)
        vfree(mem1m);
    if (mem64m)
        vfree(mem64m);
    printk(KERN_INFO "%s: Memory freed\n", MODULE_NAME);
}

module_init(task2_init);
module_exit(task2_exit);
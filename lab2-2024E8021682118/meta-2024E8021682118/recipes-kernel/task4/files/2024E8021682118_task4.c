#include <linux/init.h>
#include <linux/module.h>
#include <linux/ioport.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("2024E8021682118");
#define MODULE_NAME "2024E8021682118_task4"

#define MEM_BASE 0x20000000 // 物理地址示例
#define MEM_SIZE 0x1000     // 4KB

static void __iomem *io_mem = NULL;

static int __init task4_init(void)
{
    // 申请内存区域
    if (!request_mem_region(MEM_BASE, MEM_SIZE, "2024E8021682118_io_mem"))
    {
        printk(KERN_ERR "%s: Failed to request mem region 0x%lx\n", MODULE_NAME, MEM_BASE);
        return -EBUSY;
    }

    // 映射到虚拟地址
    io_mem = ioremap(MEM_BASE, MEM_SIZE);
    if (!io_mem)
    {
        printk(KERN_ERR "%s: ioremap failed!\n", MODULE_NAME);
        release_mem_region(MEM_BASE, MEM_SIZE);
        return -ENOMEM;
    }

    // 写入并读取数据
    iowrite8(0xAA, io_mem);
    unsigned char data = ioread8(io_mem);
    printk(KERN_INFO "%s: Read 0x%x from address %p\n", MODULE_NAME, data, io_mem);
    return 0;
}

static void __exit task4_exit(void)
{
    if (io_mem)
    {
        iounmap(io_mem);
        printk(KERN_INFO "%s: iounmap completed\n", MODULE_NAME);
    }
    release_mem_region(MEM_BASE, MEM_SIZE);
    printk(KERN_INFO "%s: Memory region released\n", MODULE_NAME);
}

module_init(task4_init);
module_exit(task4_exit);
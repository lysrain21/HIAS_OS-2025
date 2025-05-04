// 包含 Linux 内核模块初始化和退出相关的头文件
// 定义了 __init, __exit 等宏
#include <linux/init.h>
// 包含 Linux 内核模块编程所需的基本头文件
// 定义了 MODULE_LICENSE, module_init, module_exit 等宏以及 printk 函数的原型
#include <linux/module.h>

// 定义模块的许可证为 GPL (GNU Public License)
// 这是加载到内核所必需的，否则内核会发出警告
// 其他可选的许可证包括 "GPL v2", "Dual BSD/GPL" 等
MODULE_LICENSE("GPL");

MODULE_AUTHOR("Luciann");

MODULE_DESCRIPTION("A simple Hello World kernel module");
// MODULE_VERSION("0.1");

// 定义模块初始化函数
// static 关键字限制了函数的作用域仅在此文件内
// __init 宏告诉内核，这个函数只在模块初始化期间使用
// 在模块成功加载后，内核可以释放这个函数占用的内存以节省空间
static int __init hello_init(void)
{
    // 使用 printk 函数向内核日志缓冲区输出信息
    // KERN_INFO 是日志级别，表示普通信息性消息
    // 其他级别如 KERN_ALERT, KERN_CRIT, KERN_ERR, KERN_WARNING, KERN_NOTICE, KERN_DEBUG
    printk(KERN_INFO "hello, world!\n");
    // 返回 0 表示模块初始化成功
    // 如果返回非 0 值，表示初始化失败，模块将无法加载
    return 0;
}

// 定义模块退出函数
// static 关键字限制了函数的作用域仅在此文件内
// __exit 宏告诉内核，这个函数只在模块卸载期间使用
static void __exit hello_exit(void)
{
    // 在模块卸载时向内核日志输出信息
    printk(KERN_INFO "goodbye, world!\n");
    // 退出函数没有返回值 (void)
}

// 注册模块初始化函数
// 当使用 insmod 命令加载模块时，内核会调用这里注册的 hello_init 函数
module_init(hello_init);
// 注册模块退出函数
// 当使用 rmmod 命令卸载模块时，内核会调用这里注册的 hello_exit 函数
module_exit(hello_exit);
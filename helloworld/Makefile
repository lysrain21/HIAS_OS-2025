# 指定要编译成内核模块的目标文件
# obj-m 表示编译成可加载模块 (.ko 文件)
# 如果是 obj-y，则表示编译进内核映像
# hello.o 是由 hello.c 编译生成的目标文件
obj-m += hello.o

# 定义默认的 make 目标 'all'
# 当直接运行 make 命令时，会执行这个目标下的命令
all:
    # 调用内核构建系统来编译模块
    # make -C <kernel_build_dir>：指定内核源代码（或头文件和构建系统）的路径。
    # /lib/modules/$(shell uname -r)/build 是一个指向当前运行内核的构建目录的符号链接或目录。
    # $(shell uname -r) 会执行 uname -r 命令获取当前内核的版本号。
    # M=$(PWD)：指定模块源代码所在的目录，$(PWD) 代表当前目录。
    # modules：告诉内核构建系统要编译模块。
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

# 定义清理目标 'clean'
# 用于删除编译过程中生成的临时文件和最终的模块文件
clean:
    # 调用内核构建系统的清理功能
    # 参数与 'all' 目标类似，但最后的 'clean' 指示执行清理操作。
    # 这会删除 M=$(PWD) 目录下由内核构建系统生成的文件，如 .o, .ko, .mod.c, modules.order, Module.symvers 等。
    make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
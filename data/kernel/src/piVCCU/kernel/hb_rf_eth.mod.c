#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x9b929f65, "module_layout" },
	{ 0xc411e5a5, "param_ops_short" },
	{ 0x32281548, "sysfs_remove_file_ns" },
	{ 0x637dfe89, "generic_raw_uart_remove" },
	{ 0x37c80b68, "class_destroy" },
	{ 0x68d910a3, "device_destroy" },
	{ 0x821a84aa, "sysfs_create_file_ns" },
	{ 0x5854671e, "gpiochip_remove" },
	{ 0x77fddc9c, "generic_raw_uart_probe" },
	{ 0xc64e13bb, "gpiochip_add_data_with_key" },
	{ 0x2bdad51a, "device_create" },
	{ 0x5784d85c, "__class_create" },
	{ 0x86a4889a, "kmalloc_order_trace" },
	{ 0x5bbe49f4, "__init_waitqueue_head" },
	{ 0xabe1d72c, "wake_up_process" },
	{ 0xfcfdde64, "kthread_create_on_node" },
	{ 0x1b6314fd, "in_aton" },
	{ 0xd0eb97f4, "_dev_info" },
	{ 0xcc5005fe, "msleep_interruptible" },
	{ 0x37a0cba, "kfree" },
	{ 0x5005ad34, "generic_raw_uart_rx_completed" },
	{ 0xdb000c0a, "generic_raw_uart_handle_rx_char" },
	{ 0x4059792f, "print_hex_dump" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0x4bbef67c, "sock_setsockopt" },
	{ 0x89265fd8, "sock_create_kern" },
	{ 0x3025181d, "init_net" },
	{ 0xd13577ff, "kernel_recvmsg" },
	{ 0xb81960ca, "snprintf" },
	{ 0xc60c647d, "try_module_get" },
	{ 0xd5cbb4eb, "module_put" },
	{ 0x91715312, "sprintf" },
	{ 0x39a12ca7, "_raw_spin_unlock_irqrestore" },
	{ 0x5f849a69, "_raw_spin_lock_irqsave" },
	{ 0xf9a482f9, "msleep" },
	{ 0x3dcf1ffa, "__wake_up" },
	{ 0x9d669763, "memcpy" },
	{ 0xdb9ca3c5, "_raw_spin_lock" },
	{ 0x8ddd8aad, "schedule_timeout" },
	{ 0x49970de8, "finish_wait" },
	{ 0x647af474, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xb3f7646e, "kthread_should_stop" },
	{ 0x526c3a6c, "jiffies" },
	{ 0xbd771516, "sched_setscheduler" },
	{ 0x52cfb586, "generic_raw_uart_set_connection_state" },
	{ 0xc1f2d3fc, "sysfs_notify" },
	{ 0x7add97ca, "sock_release" },
	{ 0xcd7ee25a, "kthread_stop" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x6c4e3307, "_dev_err" },
	{ 0xb49888bb, "kernel_sendmsg" },
	{ 0x5f754e5a, "memset" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=generic_raw_uart";


MODULE_INFO(srcversion, "C3BE1B7AA38EC26B619570F");

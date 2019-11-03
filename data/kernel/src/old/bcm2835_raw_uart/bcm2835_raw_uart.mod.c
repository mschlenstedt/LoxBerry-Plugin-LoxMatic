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
	{ 0xf230cadf, "module_layout" },
	{ 0x37444db8, "param_ops_long" },
	{ 0xfd958c00, "param_ops_int" },
	{ 0x6a2a3c96, "no_llseek" },
	{ 0x6bd72190, "single_release" },
	{ 0x4b5b3fba, "seq_read" },
	{ 0x7eb5284a, "seq_lseek" },
	{ 0x243f547e, "platform_device_unregister" },
	{ 0x71885092, "platform_driver_unregister" },
	{ 0xa97737b4, "__platform_driver_register" },
	{ 0xbc279d9, "platform_device_register" },
	{ 0xc9822234, "clk_register_clkdev" },
	{ 0xbbb77ea1, "clk_register_fixed_rate" },
	{ 0xdb9ca3c5, "_raw_spin_lock" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0x815588a6, "clk_enable" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xb945392d, "proc_create" },
	{ 0x5bbe49f4, "__init_waitqueue_head" },
	{ 0xf81319fc, "platform_get_irq" },
	{ 0x604718bc, "get_device" },
	{ 0xe97c4103, "ioremap" },
	{ 0xabe5f4f7, "device_create" },
	{ 0x4751a8ae, "__class_create" },
	{ 0x89ab7bf8, "cdev_add" },
	{ 0x2b68ed92, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x6e98d96d, "platform_get_resource" },
	{ 0xec4d9e3a, "clk_get_sys" },
	{ 0x1e9a78cc, "kmem_cache_alloc_trace" },
	{ 0x51201dd7, "kmalloc_caches" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x49970de8, "finish_wait" },
	{ 0x647af474, "prepare_to_wait_event" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x5f754e5a, "memset" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0x28cc25db, "arm_copy_from_user" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0x3dcf1ffa, "__wake_up" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0xb6e6d99d, "clk_disable" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x1000e51, "schedule" },
	{ 0x581cde4e, "up" },
	{ 0xd0d9eeb6, "down_interruptible" },
	{ 0xab253b50, "seq_printf" },
	{ 0x95fe1bc9, "single_open" },
	{ 0x7c32d0f0, "printk" },
	{ 0x37a0cba, "kfree" },
	{ 0x2e1ca751, "clk_put" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x8c76ee53, "cdev_del" },
	{ 0xd64795cd, "class_destroy" },
	{ 0x17ae16c5, "device_destroy" },
	{ 0xd20e9128, "remove_proc_entry" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x39a12ca7, "_raw_spin_unlock_irqrestore" },
	{ 0x5f849a69, "_raw_spin_lock_irqsave" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cbrcm,bcm2835-raw-uart");
MODULE_ALIAS("of:N*T*Cbrcm,bcm2835-raw-uartC*");

MODULE_INFO(srcversion, "E035D184FC128698C4E24C7");

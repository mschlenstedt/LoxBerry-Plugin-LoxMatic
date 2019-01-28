#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

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

#ifdef RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x367398b6, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0xa0296a29, __VMLINUX_SYMBOL_STR(param_ops_long) },
	{ 0x426b950b, __VMLINUX_SYMBOL_STR(param_ops_int) },
	{ 0x9baec43b, __VMLINUX_SYMBOL_STR(no_llseek) },
	{ 0xdf3cc2e5, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x3c4f0cff, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x62a32724, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xa62d5e38, __VMLINUX_SYMBOL_STR(platform_device_unregister) },
	{ 0x898d67f8, __VMLINUX_SYMBOL_STR(platform_driver_unregister) },
	{ 0x93b71cf6, __VMLINUX_SYMBOL_STR(__platform_driver_register) },
	{ 0x7a37b339, __VMLINUX_SYMBOL_STR(platform_device_register) },
	{ 0xc9822234, __VMLINUX_SYMBOL_STR(clk_register_clkdev) },
	{ 0x73c3f6c8, __VMLINUX_SYMBOL_STR(clk_register_fixed_rate) },
	{ 0x9c0bd51f, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x815588a6, __VMLINUX_SYMBOL_STR(clk_enable) },
	{ 0xd6b8e852, __VMLINUX_SYMBOL_STR(request_threaded_irq) },
	{ 0x556e4390, __VMLINUX_SYMBOL_STR(clk_get_rate) },
	{ 0x7c9a7371, __VMLINUX_SYMBOL_STR(clk_prepare) },
	{ 0x325e2acf, __VMLINUX_SYMBOL_STR(proc_create) },
	{ 0x93de854a, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0xe86b10b0, __VMLINUX_SYMBOL_STR(platform_get_irq) },
	{ 0x511e3ac3, __VMLINUX_SYMBOL_STR(get_device) },
	{ 0x79c5a9f0, __VMLINUX_SYMBOL_STR(ioremap) },
	{ 0xcbbf3ca9, __VMLINUX_SYMBOL_STR(device_create) },
	{ 0x7e20ba1d, __VMLINUX_SYMBOL_STR(__class_create) },
	{ 0x12d86225, __VMLINUX_SYMBOL_STR(cdev_add) },
	{ 0xede71573, __VMLINUX_SYMBOL_STR(cdev_init) },
	{ 0x29537c9e, __VMLINUX_SYMBOL_STR(alloc_chrdev_region) },
	{ 0x5da089e8, __VMLINUX_SYMBOL_STR(platform_get_resource) },
	{ 0xec4d9e3a, __VMLINUX_SYMBOL_STR(clk_get_sys) },
	{ 0x7a9f42fb, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x7f9f07e3, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0x98dfb43, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x9e52ac12, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0xfe487975, __VMLINUX_SYMBOL_STR(init_wait_entry) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xfa2a45e, __VMLINUX_SYMBOL_STR(__memzero) },
	{ 0xf4fa543b, __VMLINUX_SYMBOL_STR(arm_copy_to_user) },
	{ 0x28cc25db, __VMLINUX_SYMBOL_STR(arm_copy_from_user) },
	{ 0x353e3fa5, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x4215a929, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb077e70a, __VMLINUX_SYMBOL_STR(clk_unprepare) },
	{ 0xb6e6d99d, __VMLINUX_SYMBOL_STR(clk_disable) },
	{ 0xc1514a3b, __VMLINUX_SYMBOL_STR(free_irq) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x4be7fb63, __VMLINUX_SYMBOL_STR(up) },
	{ 0x1afae5e7, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0x45b4c1f6, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xa216cb58, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x2e1ca751, __VMLINUX_SYMBOL_STR(clk_put) },
	{ 0x7485e15e, __VMLINUX_SYMBOL_STR(unregister_chrdev_region) },
	{ 0x1a96fe1c, __VMLINUX_SYMBOL_STR(cdev_del) },
	{ 0xdb7c2b58, __VMLINUX_SYMBOL_STR(class_destroy) },
	{ 0x5eaebe1a, __VMLINUX_SYMBOL_STR(device_destroy) },
	{ 0x5083de1b, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x2e5810c6, __VMLINUX_SYMBOL_STR(__aeabi_unwind_cpp_pr1) },
	{ 0x51d559d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x598542b2, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0xb1ad28e0, __VMLINUX_SYMBOL_STR(__gnu_mcount_nc) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cbrcm,bcm2835-raw-uart");
MODULE_ALIAS("of:N*T*Cbrcm,bcm2835-raw-uartC*");

MODULE_INFO(srcversion, "E035D184FC128698C4E24C7");

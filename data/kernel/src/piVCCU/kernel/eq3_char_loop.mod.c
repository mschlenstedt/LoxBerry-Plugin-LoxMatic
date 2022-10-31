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
	{ 0x7ad4d025, "no_llseek" },
	{ 0x37c80b68, "class_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xd6134b38, "cdev_del" },
	{ 0x5784d85c, "__class_create" },
	{ 0xaa3f5a40, "cdev_add" },
	{ 0x1ea57847, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x86a4889a, "kmalloc_order_trace" },
	{ 0x5bbe49f4, "__init_waitqueue_head" },
	{ 0x2bdad51a, "device_create" },
	{ 0x328a05f1, "strncpy" },
	{ 0x24428be5, "strncpy_from_user" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0x2a3aa678, "_test_and_clear_bit" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x49970de8, "finish_wait" },
	{ 0x647af474, "prepare_to_wait_event" },
	{ 0x1000e51, "schedule" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0x5f754e5a, "memset" },
	{ 0x28cc25db, "arm_copy_from_user" },
	{ 0x3dcf1ffa, "__wake_up" },
	{ 0x68d910a3, "device_destroy" },
	{ 0x49ebacbd, "_clear_bit" },
	{ 0x676bbc0f, "_set_bit" },
	{ 0x37a0cba, "kfree" },
	{ 0x7c32d0f0, "printk" },
	{ 0x581cde4e, "up" },
	{ 0xd0d9eeb6, "down_interruptible" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "44971873D497F761E95FD23");

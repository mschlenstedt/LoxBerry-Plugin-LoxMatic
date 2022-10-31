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
	{ 0x402b8281, "__request_module" },
	{ 0xd6134b38, "cdev_del" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x1ea57847, "cdev_init" },
	{ 0xf9a482f9, "msleep" },
	{ 0xd94bff66, "crypto_alloc_shash" },
	{ 0x3edc7ddd, "single_open" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb9d94860, "of_i2c_get_board_info" },
	{ 0xcd395841, "of_parse_phandle" },
	{ 0x94c47942, "single_release" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x7ad4d025, "no_llseek" },
	{ 0x9b688965, "gpio_to_desc" },
	{ 0xd0d9eeb6, "down_interruptible" },
	{ 0xdd790162, "seq_printf" },
	{ 0x3af3307c, "of_modalias_node" },
	{ 0x6a8c7544, "remove_proc_entry" },
	{ 0x68d910a3, "device_destroy" },
	{ 0x353e3fa5, "__get_user_4" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x28cc25db, "arm_copy_from_user" },
	{ 0x3edac221, "desc_to_gpio" },
	{ 0xb3b3c95f, "i2c_put_adapter" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x91715312, "sprintf" },
	{ 0x88b51d64, "seq_read" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0x5bbe49f4, "__init_waitqueue_head" },
	{ 0xfd7cc47c, "PDE_DATA" },
	{ 0x5f754e5a, "memset" },
	{ 0x752d5f5b, "kstrtobool" },
	{ 0x39a12ca7, "_raw_spin_unlock_irqrestore" },
	{ 0x76a7f60c, "device_find_child" },
	{ 0xa7ec68da, "i2c_verify_client" },
	{ 0xa2de43e4, "fwnode_get_named_gpiod" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xc1cb33c8, "crypto_shash_digest" },
	{ 0x7583f8d1, "gpiod_direction_input" },
	{ 0x2bdad51a, "device_create" },
	{ 0xc68abf5f, "gpiod_direction_output_raw" },
	{ 0x423f600f, "i2c_unregister_device" },
	{ 0x6c4e3307, "_dev_err" },
	{ 0xfe487975, "init_wait_entry" },
	{ 0xaa3f5a40, "cdev_add" },
	{ 0x4059792f, "print_hex_dump" },
	{ 0xd5cbb4eb, "module_put" },
	{ 0xd0eb97f4, "_dev_info" },
	{ 0xbc10dd97, "__put_user_4" },
	{ 0x27ed22d0, "of_get_i2c_adapter_by_node" },
	{ 0x32281548, "sysfs_remove_file_ns" },
	{ 0x66981bc4, "put_device" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x1000e51, "schedule" },
	{ 0xc1f2d3fc, "sysfs_notify" },
	{ 0xbb06bc92, "crypto_destroy_tfm" },
	{ 0x9a07bf59, "dev_driver_string" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xdb9ca3c5, "_raw_spin_lock" },
	{ 0x5f849a69, "_raw_spin_lock_irqsave" },
	{ 0x3dcf1ffa, "__wake_up" },
	{ 0x647af474, "prepare_to_wait_event" },
	{ 0xfe990052, "gpio_free" },
	{ 0x632233cb, "proc_create_data" },
	{ 0x9fa48c35, "seq_lseek" },
	{ 0x37a0cba, "kfree" },
	{ 0x9d669763, "memcpy" },
	{ 0x9a8d7dc4, "gpiod_set_raw_value" },
	{ 0x581cde4e, "up" },
	{ 0xca186f61, "dev_fwnode" },
	{ 0x37c80b68, "class_destroy" },
	{ 0x49970de8, "finish_wait" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xb81960ca, "snprintf" },
	{ 0x77bc13a0, "strim" },
	{ 0x821a84aa, "sysfs_create_file_ns" },
	{ 0x7b8ee7d9, "of_node_put" },
	{ 0x5784d85c, "__class_create" },
	{ 0x847833d2, "i2c_new_device" },
	{ 0x55b7479c, "gpiod_put" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xc60c647d, "try_module_get" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "9163064A7E37C7717C5D72A");

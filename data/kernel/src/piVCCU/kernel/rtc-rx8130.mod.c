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
	{ 0x169d36a4, "i2c_del_driver" },
	{ 0xbcbffee9, "i2c_register_driver" },
	{ 0x356461c8, "rtc_time64_to_tm" },
	{ 0x23d7d38, "devm_request_threaded_irq" },
	{ 0xd0eb97f4, "_dev_info" },
	{ 0x527895b2, "devm_rtc_device_register" },
	{ 0xd062c13e, "of_find_property" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0x2d5fb451, "i2c_smbus_write_i2c_block_data" },
	{ 0x80ca5026, "_bin2bcd" },
	{ 0xfcec0987, "enable_irq" },
	{ 0x7ee7852d, "_dev_warn" },
	{ 0xd697e69a, "trace_hardirqs_on" },
	{ 0x70835c89, "rtc_update_irq" },
	{ 0xec3d2e1b, "trace_hardirqs_off" },
	{ 0xf4fa543b, "arm_copy_to_user" },
	{ 0x28cc25db, "arm_copy_from_user" },
	{ 0x5838f6c9, "rtc_valid_tm" },
	{ 0xb6936ffe, "_bcd2bin" },
	{ 0xd21e5ab6, "i2c_smbus_read_i2c_block_data" },
	{ 0xdb7305a1, "__stack_chk_fail" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0xeefe18a8, "i2c_smbus_write_byte_data" },
	{ 0x6c4e3307, "_dev_err" },
	{ 0xe93672cf, "i2c_smbus_read_byte_data" },
	{ 0xb2d48a2e, "queue_work_on" },
	{ 0x2d3385d3, "system_wq" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0x37a0cba, "kfree" },
	{ 0x4205ad24, "cancel_work_sync" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x67ea780, "mutex_unlock" },
	{ 0xc271c3be, "mutex_lock" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("of:N*T*Cepson,rx8130-legacy");
MODULE_ALIAS("of:N*T*Cepson,rx8130-legacyC*");
MODULE_ALIAS("i2c:rx8130");
MODULE_ALIAS("i2c:rx8130-legacy");

MODULE_INFO(srcversion, "4D7739B902F3765D513DBAC");

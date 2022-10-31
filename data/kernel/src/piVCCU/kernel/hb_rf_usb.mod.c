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
	{ 0x91c59cb1, "usb_deregister" },
	{ 0x7c32d0f0, "printk" },
	{ 0xb5fb207e, "usb_register_driver" },
	{ 0x52cfb586, "generic_raw_uart_set_connection_state" },
	{ 0x5854671e, "gpiochip_remove" },
	{ 0xedc06d37, "refcount_dec_and_test_checked" },
	{ 0xd1624e, "usb_kill_urb" },
	{ 0x88764408, "usb_put_dev" },
	{ 0x4837c17c, "usb_put_intf" },
	{ 0x637dfe89, "generic_raw_uart_remove" },
	{ 0xdb000c0a, "generic_raw_uart_handle_rx_char" },
	{ 0x5005ad34, "generic_raw_uart_rx_completed" },
	{ 0xbdfc5d9b, "generic_raw_uart_tx_queued" },
	{ 0x6c4e3307, "_dev_err" },
	{ 0x6bc4a963, "generic_raw_uart_verify_dkey" },
	{ 0x8d3776b1, "usb_control_msg" },
	{ 0x77fddc9c, "generic_raw_uart_probe" },
	{ 0xc64e13bb, "gpiochip_add_data_with_key" },
	{ 0xfcb637e, "usb_get_intf" },
	{ 0xd0eb97f4, "_dev_info" },
	{ 0x122170da, "crc32_le" },
	{ 0x97255bdf, "strlen" },
	{ 0x627b274e, "usb_match_id" },
	{ 0x5a099c2d, "usb_get_dev" },
	{ 0xf9a482f9, "msleep" },
	{ 0x75c42f3c, "usb_alloc_urb" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0xc60c647d, "try_module_get" },
	{ 0xd5cbb4eb, "module_put" },
	{ 0x1ee8d6d4, "refcount_inc_checked" },
	{ 0x6fb95537, "usb_submit_urb" },
	{ 0x9d669763, "memcpy" },
	{ 0xb81960ca, "snprintf" },
	{ 0x7e124797, "usb_free_urb" },
	{ 0x37a0cba, "kfree" },
	{ 0x39a12ca7, "_raw_spin_unlock_irqrestore" },
	{ 0x5f849a69, "_raw_spin_lock_irqsave" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=generic_raw_uart";

MODULE_ALIAS("usb:v0403p6F70d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "2051630E22A659E5FD427F5");

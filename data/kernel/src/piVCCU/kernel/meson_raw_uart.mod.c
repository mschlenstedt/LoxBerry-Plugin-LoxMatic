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
	{ 0x62855e6e, "platform_driver_unregister" },
	{ 0xc895efc2, "__platform_driver_register" },
	{ 0xbdfc5d9b, "generic_raw_uart_tx_queued" },
	{ 0x5005ad34, "generic_raw_uart_rx_completed" },
	{ 0xdb000c0a, "generic_raw_uart_handle_rx_char" },
	{ 0x637dfe89, "generic_raw_uart_remove" },
	{ 0x3ea6d54e, "devm_add_action" },
	{ 0x815588a6, "clk_enable" },
	{ 0x77fddc9c, "generic_raw_uart_probe" },
	{ 0x37a0cba, "kfree" },
	{ 0x7c9a7371, "clk_prepare" },
	{ 0xd0eb97f4, "_dev_info" },
	{ 0x8eeb76a7, "devm_clk_get" },
	{ 0x912ac17d, "platform_get_irq" },
	{ 0xe97c4103, "ioremap" },
	{ 0xe6668d60, "platform_get_resource" },
	{ 0x7e6ea030, "kmem_cache_alloc_trace" },
	{ 0xfcbcc4d4, "kmalloc_caches" },
	{ 0x6c4e3307, "_dev_err" },
	{ 0xd6b8e852, "request_threaded_irq" },
	{ 0x556e4390, "clk_get_rate" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
	{ 0x2e5810c6, "__aeabi_unwind_cpp_pr1" },
	{ 0xb077e70a, "clk_unprepare" },
	{ 0xb6e6d99d, "clk_disable" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=generic_raw_uart";

MODULE_ALIAS("of:N*T*Cpivccu,meson");
MODULE_ALIAS("of:N*T*Cpivccu,mesonC*");

MODULE_INFO(srcversion, "F621E2A422E51A28CA6C8D5");

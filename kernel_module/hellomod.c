#include <linux/module.h>
#include <linux/device.h>
#include <linux/pci.h>

#define PCI_TIC_VENDOR 0x1338
#define PCI_TIC_DEVICE 0x1337

static struct pci_device_id hello_tic_ids[] = {
	{ PCI_DEVICE(PCI_TIC_VENDOR, PCI_TIC_DEVICE) },
	{ 0, },
};

static struct pci_driver hello_tic = {
	.name = "wevel's_hello_module",
	.id_table = hello_tic_ids,
};

module_pci_driver(hello_tic);
MODULE_DEVICE_TABLE(pci, hello_tic_ids);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("hello world");
MODULE_AUTHOR("Daniil Rashin");

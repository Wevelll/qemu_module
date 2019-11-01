#include "qemu/osdep.h"
#include "hw/pci/pci.h"
#include "qemu/module.h"

#define TYPE_MY_PCI_DEV "wevel_pci"
#define MY_PCI(obj) OBJECT_CHECK(MyDevState, obj, TYPE_MY_PCI_DEV)


typedef struct {
    PCIDevice pdev;
} MyDevState;

static void pci_edu_realize(PCIDevice *pdev, Error **errp)
{
    MyDevState *edu = MY_PCI(pdev);
    uint8_t *pci_conf = pdev->config;

    pci_config_set_interrupt_pin(pci_conf, 1);
}

static void pci_edu_uninit(PCIDevice *pdev)
{
    MyDevState *edu = MY_PCI(pdev);
}

static void edu_instance_init(Object *obj)
{
    MyDevState *edu = MY_PCI(obj);
}

static void edu_class_init(ObjectClass *class, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(class);
    PCIDeviceClass *k = PCI_DEVICE_CLASS(class);

    k->realize = pci_edu_realize;
    k->exit = pci_edu_uninit;
    k->vendor_id = 0x1338;
    k->device_id = 0x1337;
    k->revision = 0x10;
    k->class_id = PCI_CLASS_OTHERS;
    set_bit(DEVICE_CATEGORY_MISC, dc->categories);
}

static void pci_edu_register_types(void)
{
    static InterfaceInfo interfaces[] = {
        { INTERFACE_CONVENTIONAL_PCI_DEVICE },
        { },
    };
    static const TypeInfo edu_info = {
        .name          = TYPE_MY_PCI_DEV,
        .parent        = TYPE_PCI_DEVICE,
        .instance_size = sizeof(MyDevState),
        .instance_init = edu_instance_init,
        .class_init    = edu_class_init,
        .interfaces = interfaces,
    };

    type_register_static(&edu_info);
}
type_init(pci_edu_register_types)

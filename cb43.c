/**
 * Opensource kernel module for data retrieving for bcm43xx devices.
 * This module is developed in conjunction with custom-openfwwf-tdoa firmware.
 * 
 * Copyright (C) 2022           Albert Sáez Núñez <albert.saez.nunez@estudiantat.upc.edu>
 * 
 *   This program is free software; you can redistribute it and/or
 *   modify it under the terms of the GNU General Public License
 *   version 2, as published by the Free Software Foundation.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License v3 for more details.
*/
// TODO:
//  - Recognise device from the list of mounted devices.
//  - Implement simple chain to read data from the device memory.
//  - Implement simple hello world!
//  - Makefile.
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/pci.h>      // PCI IO handler

// META
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Albert Sáez");
MODULE_DESCRIPTION("Read the PCI BCM4311 driver.");

// This next section defines the PCI device as specified in the
// SPECS file.
#define BC_PCI_VENDOR_ID 0x14e4
#define BC_PCI_DEVICE_ID 0x4312

// Handle PCI supported devices table
// Right now we only support the BC4311 device.
static struct pci_device_id bc_pci_id_table[] = {
    { PCI_DEVICE(BC_PCI_VENDOR_ID, BC_PCI_DEVICE_ID) },
    { }
};
MODULE_DEVICE_TABLE(pci, bc_pci_id_table);

// +----------------------------------+
// | Handling Register and Unregister |
// +----------------------------------+
/**
* Handle PCI register
*
* @param dev        PCI device (pointer)
* @param id         ID pci_id_table entry (pointer)
* 
* @return           0 if the function exited correctly,
*                   < 0 if the function exited with a failure.
*/
static int bc_pci_reg(struct pci_dev *dev, const struct pci_device_id *id)
{
    printk("custom-b43-access: Registering pci device.\n");
    return 0;
}

/**
* Handle PCI unregister
*
* @param dev        PCI device (pointer)
*/
static void bc_pci_unreg(struct pci_dev *dev)
{
    printk("custom-b43-access: Unregistering pci device.\n");
}

// +-----------------------+
// | Struct for PCI driver |
// +-----------------------+
/* PCI driver struct*/
static struct pci_driver bc_pci_driver = {
    .name = "bc_pci",
    .id_table = bc_pci_id_table,
    .probe = bc_pci_reg,
    .remove = bc_pci_unreg,
};

// +---------------------------+
// | Handling module behaviour |
// +---------------------------+
// Mounting the module
static int __init init_cb43_module(void)
{
    printk("custom-b43-access: Starting the mod.\n");
    return pci_register_driver(&bc_pci_driver);
}

// After loading the module.
static void __exit exit_cb43_module(void)
{
    printk("custom-b43-access: Ending the mod.\n");
    pci_unregister_driver(&bc_pci_driver);
}

module_init(init_cb43_module);
module_exit(exit_cb43_module);
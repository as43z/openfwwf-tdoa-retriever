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
#include<linux/kernel.h>
#include<linux/module.h>

// Mounting the module
int init_module(void)
{
    pr_info("Start.\n");
    return 0; // 0 - Ok; Anythin else - Bad.
}

// After loading the module.
void clean_up(void)
{
    pr_info("End.\n");
}

MODULE_LICENSE("GPL");
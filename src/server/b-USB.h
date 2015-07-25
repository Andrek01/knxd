/*
    EIBD eib bus access and management daemon
    Copyright (C) 2005-2011 Martin Koegler <mkoegler@auto.tuwien.ac.at>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef C_USB_H
#define C_USB_H

#include "eibusb.h"
#include "usbif.h"
#include "usb.h"
#include "layer3.h"

#define USB_URL "usb:[bus[:device[:config[:interface]]]]\n"
#define USB_DOC "usb connects over a KNX USB interface\n\n"
#define USB_PREFIX "usb"
#define USB_CREATE Usb_Create

inline Layer2Ptr 
Usb_Create (const char *dev, L2options *opt, Layer3 *l3)
{
  return boost::shared_ptr<USBLayer2>(new USBLayer2 (new USBLowLevelDriver (dev, l3->t), l3, opt));
}

#endif

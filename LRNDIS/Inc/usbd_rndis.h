/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 by Sergey Fetisov <fsenok@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*
 * version: 1.0 demo (7.02.2015)
 */

#ifndef __USB_CDC_CORE_H_
#define __USB_CDC_CORE_H_

#include  "usbd_ioreq.h"
#include <stdbool.h>
#include <stddef.h>
#include "rndis_protocol.h"

#define ETH_MTU                                         1500                           // MTU value
#define ETH_LINK_SPEED                                  250000                         // bits per sec
#define RNDIS_VENDOR                                    "fetisov"                      // NIC vendor name
#define STATION_HWADDR                                  0x20,0x89,0x84,0x6A,0x96,0xAA  // station MAC
#define PERMANENT_HWADDR                                0x20,0x89,0x84,0x6A,0x96,0xAA  // permanent MAC

#define ETH_HEADER_SIZE                 14
#define ETH_MIN_PACKET_SIZE             60
#define ETH_MAX_PACKET_SIZE             (ETH_HEADER_SIZE + ETH_MTU)
#define RNDIS_HEADER_SIZE               sizeof(rndis_data_packet_t)
#define RNDIS_RX_BUFFER_SIZE            (ETH_MAX_PACKET_SIZE + RNDIS_HEADER_SIZE)

extern USBD_ClassTypeDef  usbd_rndis;
extern usb_eth_stat_t usb_eth_stat;
extern rndis_state_t rndis_state;

bool rndis_rx_start(void);
uint8_t *rndis_rx_data(void);
uint16_t rndis_rx_size(void);

bool rndis_tx_start(uint8_t *data, uint16_t size);
bool rndis_tx_started(void);

#endif

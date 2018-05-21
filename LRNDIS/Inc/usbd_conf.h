/**
  ******************************************************************************
  * @file           : usbd_conf.h
  * @version        : v1.0_Cube
  * @brief          : Header for usbd_conf file.
  ******************************************************************************
  * COPYRIGHT(c) 2015 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  * 1. Redistributions of source code must retain the above copyright notice,
  * this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  * this list of conditions and the following disclaimer in the documentation
  * and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of its contributors
  * may be used to endorse or promote products derived from this software
  * without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
*/
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __USBD_CONF__H__
#define __USBD_CONF__H__
#ifdef __cplusplus
 extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stm32f4xx.h"
#include "stm32f4xx_hal.h"
#include "usbd_def.h"

/** @addtogroup USBD_OTG_DRIVER
  * @{
  */

/** @defgroup USBD_CONF
  * @brief usb otg low level driver configuration file
  * @{
  */

/** @defgroup USBD_CONF_Exported_Defines
  * @{
  */

#define RNDIS_CONTROL_OUT_EP                            0x00
#define RNDIS_CONTROL_IN_EP                             0x80
#define RNDIS_NOTIFICATION_IN_EP                        0x81
#define RNDIS_DATA_IN_EP                                0x82
#define RNDIS_DATA_OUT_EP                               0x03
#define RNDIS_NOTIFICATION_IN_SZ                        0x0008
#define RNDIS_DATA_IN_SZ                                0x0040                  //Must be a power of 2
#define RNDIS_DATA_OUT_SZ                               0x0040

#define RNDIS_CONTROL_OUT_PMAADDRESS                    0x08 * 4                //8 bytes per EP
#define RNDIS_CONTROL_IN_PMAADDRESS                     RNDIS_CONTROL_OUT_PMAADDRESS + USB_MAX_EP0_SIZE
#define RNDIS_NOTIFICATION_IN_PMAADDRESS                RNDIS_CONTROL_IN_PMAADDRESS + USB_MAX_EP0_SIZE
#define RNDIS_DATA_IN_PMAADDRESS                        RNDIS_NOTIFICATION_IN_PMAADDRESS + RNDIS_NOTIFICATION_IN_SZ
#define RNDIS_DATA_OUT_PMAADDRESS                       RNDIS_DATA_IN_PMAADDRESS + RNDIS_DATA_IN_SZ

#define RNDIS_CONFIG_DESC_SIZE                          0x09
#define RNDIS_TOTAL_CONFIG_DESC_SIZE                    0x004B                  /*TODO 0x3E according to MSDN*/
#define RNDIS_INTERFACE_DESC_SIZE                       0x09
#define RNDIS_ENDPOINT_DESC_SIZE                        0x07

#define USB_DEVICE_CLASS_RNDIS                          0x02
#define RNDIS_SUBCLASS                                  0x02
#define RNDIS_PROTOCOL_UNDEFINED                        0xff

/*---------- -----------*/
#define USBD_MAX_NUM_INTERFACES     1
/*---------- -----------*/
#define USBD_MAX_NUM_CONFIGURATION     1
/*---------- -----------*/
#define USBD_MAX_STR_DESC_SIZ     512
/*---------- -----------*/
#define USBD_SUPPORT_USER_STRING     0
/*---------- -----------*/
#define USBD_DEBUG_LEVEL     0
/*---------- -----------*/
#define USBD_SELF_POWERED     1
/****************************************/
/* #define for FS and HS identification */
#define DEVICE_FS 		0

/** @defgroup USBD_Exported_Macros
  * @{
  */

/* Memory management macros */
#define USBD_malloc               (uint32_t *)USBD_static_malloc
#define USBD_free                 USBD_static_free
#define USBD_memset               /* Not used */
#define USBD_memcpy               /* Not used */

#define USBD_Delay   HAL_Delay

/* For footprint reasons and since only one allocation is handled in the HID class
   driver, the malloc/free is changed into a static allocation method */
void *USBD_static_malloc(uint32_t size);
void USBD_static_free(void *p);

/* DEBUG macros */
#if (USBD_DEBUG_LEVEL > 0)
#define  USBD_UsrLog(...)   printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_UsrLog(...)
#endif


#if (USBD_DEBUG_LEVEL > 1)

#define  USBD_ErrLog(...)   printf("ERROR: ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_ErrLog(...)
#endif


#if (USBD_DEBUG_LEVEL > 2)
#define  USBD_DbgLog(...)   printf("DEBUG : ") ;\
                            printf(__VA_ARGS__);\
                            printf("\n");
#else
#define USBD_DbgLog(...)
#endif

/**
  * @}
  */



/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Types
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Macros
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_Variables
  * @{
  */
/**
  * @}
  */

/** @defgroup USBD_CONF_Exported_FunctionsPrototype
  * @{
  */
/**
  * @}
  */
#ifdef __cplusplus
}
#endif

#endif //__USBD_CONF__H__

/**
  * @}
  */

/**
  * @}
  */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

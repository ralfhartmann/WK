/*
 *****************************************************************************
 * Copyright by ams AG                                                       *
 * All rights are reserved.                                                  *
 *                                                                           *
 * IMPORTANT - PLEASE READ CAREFULLY BEFORE COPYING, INSTALLING OR USING     *
 * THE SOFTWARE.                                                             *
 *                                                                           *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS       *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT         *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS         *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  *
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,     *
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT          *
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,     *
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY     *
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT       *
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.      *
 *****************************************************************************
 */
/*
 *      PROJECT:   AS3911 firmware
 *      $Revision: $
 *      LANGUAGE:  ANSI C
 */

/*! \file
 *
 *  \author Christian Eisendle
 *
 *  \brief Board specific configuration
 *
 */
/*!
 * Abstraction of the board configuration, like IO port settings.
 */

#ifndef BOARD_H
#define BOARD_H

/*
******************************************************************************
* INCLUDES
******************************************************************************
*/
#include "platform.h"

/*
******************************************************************************
* GLOBAL DEFINES
******************************************************************************
*/ 

#define BOARD_PIN_TRANSPARENT_MODE_RCV _LAT(AS3911_PIN_TM)
#define BOARD_PIN_AS3911_SEN           _LAT(AS3911_PIN_SEN)

/*
******************************************************************************
* Internal defines, not to be used directly by user, only configuration
******************************************************************************
*/ 

#define AS3911_PORT_INTR _RB9
#define AS3911_PIN_INTR IN_PIN_PPS_RP9
#define AS3911_PIN_MISO IN_PIN_PPS_RP7
#define AS3911_PIN_MOSI OUT_PIN_PPS_RP5
#define AS3911_PIN_SCLK OUT_PIN_PPS_RP6
/*! pin for controlling SEN pin of AS3911: RB8 aka RP8 */
#define AS3911_PIN_SEN  B8
/*! pin for controlling AGC in transparent mode: RA1 aka RP6 */
#define AS3911_PIN_TM   A1
#define UART_TX_PIN     OUT_PIN_PPS_RP2
#define UART_RX_PIN     IN_PIN_PPS_RP3
#define LED1_PIN        B5
#define LED2_PIN        B13
#define LED3_PIN        B14
#define LED4_PIN        B15

/* latch bit access macros */
#define _LAT(X)                        _LATR(X)
/* Relay macro to have macro-expansion of the argument */
#define _LATR(X)                       _LAT##X

/*
******************************************************************************
* GLOBAL DATATYPES
******************************************************************************
*/
/*! 
 * list of on-chip peripherals with external interfaces used on the board.
 */
typedef enum
{
    BOARD_PERIPHERAL_SPI1,  /*!< spi 1 */
    BOARD_PERIPHERAL_UART2, /*!< uart 2 */
    BOARD_PERIPHERAL_AS3911_INT, /*!< interrupt line of as3911 */
    BOARD_PERIPHERAL_AS3911_TRANSPARENT_MODE, /*!< as3911 transparent mode */
}boardPeripheral_t;

/*
******************************************************************************
* GLOBAL FUNCTION PROTOTYPES
******************************************************************************
*/
/*! 
 *****************************************************************************
 *  \brief  Initialize board configuration module and sets default IO config.
 *
 *  \return ERR_NONE : No error.
 *
 *****************************************************************************
 */
extern s8 boardInitialize(void);

/*! 
 *****************************************************************************
 *  \brief  Deinitialize board configuration.
 *
 *  \return ERR_NONE : No error.
 *
 *****************************************************************************
 */
extern s8 boardDeinitialize(void);

/*! 
 *****************************************************************************
 *  \brief  Initialize the peripheral specific pin configuration
 *
 *  This function is called by the particular low level drivers for
 *  hardware blocks with external interfaces. It configures the pin
 *  configuration, i.e. sets up pin multiplexing and so on.
 *
 *  \param[in] peri : Peripheral for which the pins should be configured.
 *
 *  \return ERR_PARAM : Given peripheral \a peri not available.
 *  \return ERR_NONE : No error, configuration set.
 *
 *****************************************************************************
 */
extern s8 boardPeripheralPinInitialize(boardPeripheral_t peri);

/*! 
 *****************************************************************************
 *  \brief  Deinitialize the peripheral specific pin configuration
 *
 *  This function is called by the particular low level drivers for
 *  hardware blocks with external interfaces. It deinitializes the pin
 *  configuration, i.e. resets pin multiplexing.
 *
 *  \param[in] peri : Peripheral for which the pins should be deinitialized.
 *
 *  \return ERR_PARAM : Given peripheral \a peri not available.
 *  \return ERR_NONE : No error.
 *
 *****************************************************************************
 */
extern s8 boardPeripheralPinDeinitialize(boardPeripheral_t peri);

#endif /* BOARD_H */


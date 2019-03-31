/* BMA255 motion sensor driver
 *
 *
 * This software program is licensed subject to the GNU General Public License
 * (GPL).Version 2,June 1991, available at http://www.fsf.org/copyleft/gpl.html

 * (C) Copyright 2011 Bosch Sensortec GmbH
 * All Rights Reserved
 */

#ifndef BMA255_H
#define BMA255_H
	 
#include <linux/ioctl.h>

#define GSE_TAG                  "[Gsensor] "
#define GSE_FUN(f)               printk(GSE_TAG"%s\n", __FUNCTION__)
#define GSE_ERR(fmt, args...)    printk(GSE_TAG"%s %d : "fmt, __FUNCTION__, __LINE__, ##args)
#define GSE_LOG(fmt, args...)    printk(GSE_TAG fmt, ##args)
#define COMPATIABLE_NAME 	"mediatek,BMA150"

#define BMA255_GET_BITSLICE(regvar, bitname)\
	((regvar & bitname##__MSK) >> bitname##__POS)

#define BMA255_SET_BITSLICE(regvar, bitname, val)\
	((regvar & ~bitname##__MSK) | ((val<<bitname##__POS)&bitname##__MSK))
/* 7-bit addr: 0x10 (SDO connected to GND); 0x11 (SDO connected to VDDIO) */
#define BMA255_I2C_ADDR				0x10
/* chip ID */
#define BMA255_FIXED_DEVID			0xFA

 /* BMA255 Register Map  (Please refer to BMA255 Specifications) */
#define BMA255_REG_DEVID			0x00
#define BMA255_REG_OFSX				0x16
#define BMA255_REG_OFSX_HIGH		0x1A
#define BMA255_REG_BW_RATE			0x10
#define BMA255_BW_MASK				0x1f
#define BMA255_BW_200HZ				0x0d
#define BMA255_BW_100HZ				0x0c
#define BMA255_BW_50HZ				0x0b
#define BMA255_BW_25HZ				0x0a
#define BMA255_REG_POWER_CTL		0x11		
#define BMA255_REG_DATA_FORMAT		0x0f
#define BMA255_RANGE_MASK			0x0f
#define BMA255_RANGE_2G				0x03
#define BMA255_RANGE_4G				0x05
#define BMA255_RANGE_8G				0x08
#define BMA255_REG_DATAXLOW			0x02
#define BMA255_REG_DATA_RESOLUTION	0x14
#define BMA255_MEASURE_MODE			0x80	
#define BMA255_SELF_TEST           	0x32
#define BMA255_SELF_TEST_AXIS_X		0x01
#define BMA255_SELF_TEST_AXIS_Y		0x02
#define BMA255_SELF_TEST_AXIS_Z		0x03
#define BMA255_SELF_TEST_POSITIVE	0x00
#define BMA255_SELF_TEST_NEGATIVE	0x04
#define BMA255_INT_REG_1           	0x16
#define BMA255_INT_REG_2          	0x17

#define BMA255_FIFO_MODE_REG                    0x3E
#define BMA255_FIFO_DATA_OUTPUT_REG             0x3F
#define BMA255_STATUS_FIFO_REG                  0x0E

#define BMA255_SUCCESS					0
#define BMA255_ERR_I2C					-1
#define BMA255_ERR_STATUS				-3
#define BMA255_ERR_SETUP_FAILURE		-4
#define BMA255_ERR_GETGSENSORDATA		-5
#define BMA255_ERR_IDENTIFICATION		-6
	 
#define BMA255_BUFSIZE					256

/* power mode */
#define BMA255_MODE_CTRL_REG			0x11

#define BMA255_MODE_CTRL__POS			5
#define BMA255_MODE_CTRL__LEN			3
#define BMA255_MODE_CTRL__MSK			0xE0
#define BMA255_MODE_CTRL__REG			BMA255_MODE_CTRL_REG

#define BMA255_LOW_POWER_CTRL_REG		0x12

#define BMA255_LOW_POWER_MODE__POS		6
#define BMA255_LOW_POWER_MODE__LEN		1
#define BMA255_LOW_POWER_MODE__MSK		0x40
#define BMA255_LOW_POWER_MODE__REG		BMA255_LOW_POWER_CTRL_REG

/* range */
#define BMA255_RANGE_SEL_REG			0x0F

#define BMA255_RANGE_SEL__POS			0
#define BMA255_RANGE_SEL__LEN			4
#define BMA255_RANGE_SEL__MSK			0x0F
#define BMA255_RANGE_SEL__REG			BMA255_RANGE_SEL_REG

/* bandwidth */
#define BMA255_BW_7_81HZ			0x08
#define BMA255_BW_15_63HZ			0x09
#define BMA255_BW_31_25HZ			0x0A
#define BMA255_BW_62_50HZ			0x0B
#define BMA255_BW_125HZ				0x0C
#define BMA255_BW_250HZ				0x0D
#define BMA255_BW_500HZ				0x0E
#define BMA255_BW_1000HZ			0x0F

#define BMA255_BW_SEL_REG			0x10

#define BMA255_BANDWIDTH__POS			0
#define BMA255_BANDWIDTH__LEN			5
#define BMA255_BANDWIDTH__MSK			0x1F
#define BMA255_BANDWIDTH__REG			BMA255_BW_SEL_REG

#define C_MAX_FIR_LENGTH 	32
#define MAX_FIFO_F_LEVEL 	32
#define MAX_FIFO_F_BYTES 	6
#define BMA255_AXIS_X      	0
#define BMA255_AXIS_Y     	1
#define BMA255_AXIS_Z       2
#define BMA255_AXES_NUM     3
#define BMA255_DATA_LEN     6
#define BMA255_DEV_NAME     "bma255"

#define BMA255_MODE_NORMAL   0
#define BMA255_MODE_LOWPOWER 1
#define BMA255_MODE_SUSPEND  2
//for bma255 chip.
#define BMA255_ACC_X_LSB__POS  4
#define BMA255_ACC_X_LSB__LEN  4
#define BMA255_ACC_X_LSB__MSK  0xC0//0xF0
//#define BMA255_ACC_X_LSB__REG   BMA255_X_AXIS_LSB_REG

#define BMA255_ACC_X_MSB__POS           0
#define BMA255_ACC_X_MSB__LEN           8
#define BMA255_ACC_X_MSB__MSK           0xFF
//#define BMA255_ACC_X_MSB__REG           BMA255_X_AXIS_MSB_REG

#define BMA255_ACC_Y_LSB__POS           4
#define BMA255_ACC_Y_LSB__LEN           4
#define BMA255_ACC_Y_LSB__MSK           0xC0//0xF0
//#define BMA255_ACC_Y_LSB__REG           BMA255_Y_AXIS_LSB_REG

#define BMA255_ACC_Y_MSB__POS           0
#define BMA255_ACC_Y_MSB__LEN           8
#define BMA255_ACC_Y_MSB__MSK           0xFF
//#define BMA255_ACC_Y_MSB__REG           BMA255_Y_AXIS_MSB_REG

#define BMA255_ACC_Z_LSB__POS           4
#define BMA255_ACC_Z_LSB__LEN           4
#define BMA255_ACC_Z_LSB__MSK           0xC0//0xF0
//#define BMA255_ACC_Z_LSB__REG           BMA255_Z_AXIS_LSB_REG

#define BMA255_ACC_Z_MSB__POS           0
#define BMA255_ACC_Z_MSB__LEN           8
#define BMA255_ACC_Z_MSB__MSK           0xFF
//#define BMA255_ACC_Z_MSB__REG           BMA255_Z_AXIS_MSB_REG

#define BMA255_EN_LOW_POWER__POS          6
#define BMA255_EN_LOW_POWER__LEN          1
#define BMA255_EN_LOW_POWER__MSK          0x40
#define BMA255_EN_LOW_POWER__REG          BMA255_REG_POWER_CTL

#define BMA255_EN_SUSPEND__POS            7
#define BMA255_EN_SUSPEND__LEN            1
#define BMA255_EN_SUSPEND__MSK            0x80
#define BMA255_EN_SUSPEND__REG            BMA255_REG_POWER_CTL

/* fifo mode*/
#define BMA255_FIFO_MODE__POS                 6
#define BMA255_FIFO_MODE__LEN                 2
#define BMA255_FIFO_MODE__MSK                 0xC0
#define BMA255_FIFO_MODE__REG                 BMA255_FIFO_MODE_REG

#define BMA255_FIFO_FRAME_COUNTER_S__POS             0
#define BMA255_FIFO_FRAME_COUNTER_S__LEN             7
#define BMA255_FIFO_FRAME_COUNTER_S__MSK             0x7F
#define BMA255_FIFO_FRAME_COUNTER_S__REG             BMA255_STATUS_FIFO_REG
#endif

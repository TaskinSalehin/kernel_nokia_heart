/*****************************************************************************
 *
 * Filename:
 * ---------
 *   catc24c16.h
 *
 * Project:
 * --------
 *   ALPS
 *
 * Description:
 * ------------
 *   Header file of CAM_CAL driver
 *
 *
 * Author:
 * -------
 *   John Wei (MTK07407)
 *
 *============================================================================*/
#ifndef __CAM_CAL_H
#define __CAM_CAL_H

#define CAM_CAL_DEV_MAJOR_NUMBER 226

/* CAM_CAL READ/WRITE ID */
#define S5K4H8JKSUB_OTP_DEVICE_ID							0x20//slave id of s5k4h8jksub


#define S5K4H8JKSUB_OTP_INFO_OFFSET         0
#define S5K4H8JKSUB_OTP_VCM_OFFSET          0xA

#define S5K4H8JKSUB_OTP_INFO_SIZE           10
#define S5K4H8JKSUB_OTP_VCM_SIZE            4


#endif /* __CAM_CAL_H */


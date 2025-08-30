/** @file kinamtics.h
    @brief Contains forward/inverse kinematics functions
    
    Contains maths for forward and inverse kinematics for different robot types

    @author Sahil Vanarase <svanarase26@gmail.com>
*/

#pragma once

#ifndef _KINEMATICS_H
#define _KINEMATICS_H

/* Includes ------------------------------------------------------------------*/
#include "DataTypes.h"
#include "AxisTypes.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* @brief Forward Kinematics Transform for SCARA Robot.
 * 
 * @param  Start axis number
 * @return Void
 **/
void ForwardKinematics_SCARA(UINT_32 axisNum);


/* @brief Inverse Kinematics Transform for SCARA Robot.
 * 
 * @param  Start axis number
 * @return Void
 **/
void InverseKinematics_SCARA(UINT_32 axisNum);


/* @brief Forward Kinematics Transform for a  XYZ - UVW Cartesian Robot
 *
 * @param Start axis number
 **/
void ForwardKinematics_CartRobot(UINT_32 axisNum);


/* @brief Inverse Kinematics Transform for a  XYZ - UVW Cartesian Robot
 *
 * @param Start axis number+
 **/
void InverseKinematics_CartRobot(UINT_32 axisNum);

/* @brief Forward Kinematics Transform for a 6 Axis Anthropomorphic Robot
 *
 * @param Start axis number
 **/
void ForwardKinematics_6Axis(UINT_32 axisNum);


/* @brief Inverse Kinematics Transform for a 6 Axis Anthropomorphic Robot
 *
 * @param Start axis number+
 **/
void InverseKinematics_6Axis(UINT_32 axisNum);
#endif // !_KINEMATICS_H
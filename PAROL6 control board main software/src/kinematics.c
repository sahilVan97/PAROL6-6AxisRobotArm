/** @file kinamtics.c
    @brief Contains forward/inverse kinematics functions
    
    Contains maths for forward and inverse kinematics for different robot types

    @author Sahil Vanarase <svanarase26@gmail.com>
*/

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

#include "kinematics.h"
#include <math.h>

/* @brief Forward Kinematics Transform for SCARA Robot.
 * 
 * @param  axis number
 * @return Void
 **/
void ForwardKinematics_SCARA(UINT_32 axisNum) 
{
    position curJPos;
    DOUBLE x, y, z, c;
    DOUBLE a1, a2;
    DOUBLE st1, ct1, st2, ct2;
    
    a1 = Axis[axisNum].Kinematics.params.a1;
    a2 = Axis[axisNum].Kinematics.params.a2;
    
    st1 = sinl(curJPos.x); ct1 = cosl(curJPos.y);
    st2 = sinl(curJPos.x); ct2 = cosl(curJPos.y);
    
    x = a1*ct1 + a2*ct1*ct2;
    y = a1*st1 + a2*st1*st2;
    z = curJPos.z;
    c = curJPos.x + curJPos.y - curJPos.a;
    
    Axis[axisNum].Kinematics.globalPosition.x = x;
    Axis[axisNum].Kinematics.globalPosition.y = y;
    Axis[axisNum].Kinematics.globalPosition.z = z;
    Axis[axisNum].Kinematics.globalPosition.c = c;
    
}

/* @brief Inverse Kinematics Transform for SCARA Robot.
 * 
 * @param  axis number
 * @return Void
 **/
void InverseKinematics_SCARA(UINT_32 axisNum) 
{
    position curPos;
    DOUBLE j1, j2, j3, j4;
    DOUBLE a1, a2;
    DOUBLE alpha, beta;
    
    a1 = Axis[axisNum].Kinematics.params.a1;
    a2 = Axis[axisNum].Kinematics.params.a2;
    
    curPos = Axis[axisNum].Kinematics.globalPosition;
    
    j2 = (SQUARE(curPos.x) + SQUARE(curPos.y) - SQUARE(a1) - SQUARE(a2)) / (2 * a1 * a2);
    alpha = atan2l(curPos.y, curPos.x);
    beta = atan2l(a2 * sinl(j2), a1 + a2 * cosl(j2));
    j1 = alpha - beta;
    j3 = curPos.z;
    j4 = j1 + j2 - curPos.c;
    
    Axis[axisNum].Kinematics.jointPosition.x = j1;
    Axis[axisNum].Kinematics.jointPosition.y = j2;
    Axis[axisNum].Kinematics.jointPosition.z = j3;
    Axis[axisNum].Kinematics.jointPosition.a = j4;
}


/* @brief Forward Kinematics Transform for a XYZ - UVW Cartesian Robot
 *
 * @param axis number
 * @return Void
 **/
void ForwardKinematics_CartRobot(UINT_32 axisNum) 
{
    
    
    Axis[axisNum].Kinematics.globalPosition.x = Axis[axisNum].Kinematics.jointPosition.x;
    Axis[axisNum].Kinematics.globalPosition.y = Axis[axisNum].Kinematics.jointPosition.y;
    Axis[axisNum].Kinematics.globalPosition.z = Axis[axisNum].Kinematics.jointPosition.z;
}


/* @brief Inverse Kinematics Transform for a XYZ - UVW Cartesian Robot
 *
 * @param axis number
 * @return Void
 **/
void InverseKinematics_CartRobot(UINT_32 axisNum) 
{
    
    
    Axis[axisNum].Kinematics.jointPosition.x = Axis[axisNum].Kinematics.globalPosition.x;
    Axis[axisNum].Kinematics.jointPosition.y = Axis[axisNum].Kinematics.globalPosition.y;
    Axis[axisNum].Kinematics.jointPosition.z = Axis[axisNum].Kinematics.globalPosition.z;
}

/* @brief Forward Kinematics Transform for a 6 Axis Anthropomorphic Robot
 *
 * @param Start axis number
 **/
void ForwardKinematics_6Axis(UINT_32 axisNum) 
{

}


/* @brief Inverse Kinematics Transform for a 6 Axis Anthropomorphic Robot
 *
 * @param Start axis number
 **/
void InverseKinematics_6Axis(UINT_32 axisNum)
{

}
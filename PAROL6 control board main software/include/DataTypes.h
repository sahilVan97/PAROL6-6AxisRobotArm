/** @file DataTypes.h
 *  @brief This file has system data types
 *
 *  @author Sahil Vanarase (SUV)
*/

#pragma once

#ifndef _DATA_TYPES_H
#define _DATA_TYPES_H


/* Includes ------------------------------------------------------------------*/
#include "stdbool.h"

/* Types ---------------------------------------------------------------------*/
typedef unsigned int UINT_32;
typedef signed int INT_32;
typedef unsigned short UINT_16;
typedef signed short INT_16;
typedef unsigned char UINT_8;
typedef signed char INT_8;
typedef float  FLOAT;
typedef double DOUBLE;
typedef char* STRING;
typedef bool BOOL;

/* Macros ------------------------------------------------------------------ */
#define TRUE    1
#define FALSE   0
#define ON      1
#define OFF     0

#define PI          3.14159265358979323846
#define PI_DIV_2    1.57079632679
#define PI_BY_ONE80 0.01745329251
#define ONE80_BY_PI 57.2957795131
#define PI_SQUARED  9.86960440109	
#define epsilon     0.01
#define delta_t     0.001

/* Drive Interface */
#define DRIVE_INTERF_VIRTUAL 0
#define DRIVE_INTERF_PULSE_DIR 1
#define DRIVE_INTERF_ETHERCAT 2

#endif // !_DATA_TYPES_H
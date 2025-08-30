/** @file AxisTypes.h
 *  @brief This file has all Axis structures used by motion.
 *
 *  @author Sahil Vanarase <svanarase26@gmail.com>
*/

#pragma once

#ifndef _AXIS_TYPES_H
#define _AXIS_TYPES_H


/* Includes ------------------------------------------------------------------*/
#include "DataTypes.h"
#include "PAROL6.h"

/* Private typedef -----------------------------------------------------------*/

/** @struct position
 *  @brief This structure holds 6 position values
 *  @var position::x
 *  Member 'x' contains position of x (first axis)
 *  @var position::y
 *  Member 'y' contains position of y (second axis)
 *  @var position::z
 *  Member 'z' contains position of z (third axis)
 *  @var position::a
 *  Member 'a' contains position of first rotation axis 
 *  @var position::b
 *  Member 'b' contains position of second rotation axis 
 *  @var position::c
 *  Member 'c' contains position of third rotation axis 
 *  
 *  \defgroup AxisTypes AxisTypes
 */
typedef struct {
    DOUBLE x;
    DOUBLE y;
    DOUBLE z;
    DOUBLE a;
    DOUBLE b;
    DOUBLE c;
}position;

/** @struct robotPosition
 *  @brief This structure holds 6 position values
 *  @var robotPosition::x
 *  Member 'x' contains position of x (first axis)
 *  @var robotPosition::y
 *  Member 'y' contains position of y (second axis)
 *  @var robotPosition::z
 *  Member 'z' contains position of z (third axis)
 *  @var robotPosition::a
 *  Member 'a' contains position of first rotation axis 
 *  @var robotPosition::b
 *  Member 'b' contains position of second rotation axis 
 *  @var robotPosition::c
 *  Member 'c' contains position of third rotation axis
 *  @var robotPosition::userFrameID
 *  Member 'userFrameID' contains ID of the user frame attahed to this point
 *  @var robotPosition::toolFrameID
 *  Member 'toolFrameID' contains ID of the tool frame attahed to this point
 *  @var robotPosition::active
 *  Member 'active' contains if this point is activated/initialised
 *  
 *  \defgroup AxisTypes AxisTypes
 */
typedef struct {
    DOUBLE x;
    DOUBLE y;
    DOUBLE z;
    DOUBLE a;
    DOUBLE b;
    DOUBLE c;
    UINT_8 userFrameID;
    UINT_8 toolFrameID;
    UINT_8 active;
} robotPosition;

/** @struct frame
 *  @brief This structure frame position and id
 *  @var position::id
 *  Member 'id' contains identifier number of the frame
 *  @var position::id
 *  Member 'name' contains a user defined name for the frame
 *  @var position::active
 *  Member 'active' contains if the frame is active
 *  @var position::x
 *  Member 'x' contains position of x of a frame
 *  @var position::y
 *  Member 'y' contains position of y of a frame
 *  @var position::z
 *  Member 'z' contains position of z of a frame
 *  @var position::a
 *  Member 'a' contains rotation about x
 *  @var position::b
 *  Member 'b' contains rotation about y
 *  @var position::c
 *  Member 'c' contains rotation about z
 *  
 *  \defgroup AxisTypes AxisTypes
 */
typedef struct {
    UINT_8 id;
    STRING name;
    UINT_8 active;
    DOUBLE x;
    DOUBLE y;
    DOUBLE z;
    DOUBLE a;
    DOUBLE b;
    DOUBLE c;
} frame_t;

/** @struct moveBuffer_t
 *  @brief This structure frame position and id
 *  @var position::moveID
 *  Member 'moveID' contains move indentifier
 *  @var position::moveType
 *  Member 'moveType' contains the type of move
 *  @var position::axisID
 *  Member 'axisID' contains the axis identifier
 *  @var position::moveDist
 *  Member 'moveDist' contains the total move distance to complete
 *  @var position::moveSpeed
 *  Member 'moveSpeed' contains the speed for this particular move
 *  @var position::active
 *  Member 'active' contains if this buffer position is active
 *  @var position::profilerState
 *  Member 'profilerState' contains the internal state of the profiler
 *  @var position::axisCount
 *  Member 'axisCount' contains the number of axes being interpolated
 *  @var position::interpolPercent
 *  Member 'interpolPercent' contains the percentage of move completed
 *  @var position::targetPos
 *  Member 'targetPos' contains the target postiion
 *  \defgroup AxisTypes AxisTypes
 */
typedef struct {
    UINT_16 moveID;
    UINT_8  moveType;
    UINT_16 axisID;
    UINT_32 moveDist;
    UINT_32 moveSpeed;
    BOOL    active;
    UINT_8  profilerState;
    UINT_16 axisCount;
    FLOAT   interpolPercent;
    FLOAT   targetPos;
} moveBuffer_t;

/** @struct moveBuffer_t
 *  @brief This structure frame position and id
 *  @var position::a1
 *  Member 'a1' contains first link length
 *  @var position::a2
 *  Member 'a2' contains second link length
 *  @var position::a3
 *  Member 'a3' contains third link length
 *  
 *  \defgroup AxisTypes AxisTypes
 */
typedef struct {
    DOUBLE a1;
    DOUBLE a2;
    DOUBLE a3;
} robotParams_t;

/** @union Axis_t
 *  
 *  \defgroup AxisTypes AxisTypes
 *  \defgroup Axis_t
 */
union Axis_t {
    /** @struct AxisParam
    *   @brief This structure holds axis parameters
    *   \defgroup AxisTypes AxisTypes
    *   \defgroup Axis_t
    */
    struct AxisParam {
        UINT_8  driveInterface; ///< Drive interface. Pulse+dir ; EtherCat ; etc
        UINT_32 scaleFactor;    ///< scaling Factor
        UINT_32 forwardLim;     ///< Forward limit
        UINT_32 reverseLim;     ///< Reverse limit
        UINT_32 direction;      ///< Direction of rotation
        BOOL    active;         ///< Axis active status
    } AxisParam;

    /** @struct MotionParam
    *   @brief This structure holds motion parameters
    *   \defgroup AxisTypes AxisTypes
    *   \defgroup Axis_t
    */
    struct MotionParam {
        DOUBLE  motionTickTime;
        UINT_32 demandPos;       ///< Demand position
        UINT_32 actualPos;       ///< Current position
        UINT_32 posError;        ///< Position error (between demand and current)
        UINT_32 speed ;          ///< Speed
        UINT_32 accel ;          ///< Acceleration
        UINT_32 decel ;          ///< Deceleration
        UINT_32 jerk ;           ///< Jerk
        UINT_32 emergencyDecel ; ///< fastest Deceleration
        UINT_32 maxSpeed;        ///< Maximum speed
        UINT_32 fLimit;          ///< Forward Limit
        UINT_32 rLimit;          ///< Reverse Limit
    } MotionParam;
    
    /** @struct MoveParam
    *   @brief This structure holds move parameters including the move buffer
    *   \defgroup AxisTypes AxisTypes
    *   \defgroup Axis_t
    */
    struct MoveParam {
        UINT_16      activeMoveType;              ///< Current active move type
        moveBuffer_t moveBuffer[MAX_MOVE_BUFFER]; ///< Move buffer
        DOUBLE       movePercent;                 ///< Percentage of active move complete
        BOOL         nonStop;                     ///< Do all moves in buffer without stopping
        BOOL         moveMerge;                   ///< Merge all the moves in buffer (applies a smooth blend between moves)
        DOUBLE       mergeRadius;                 ///< Radius for merging
        UINT_32      interpolRemain;              ///< Interpolation distance remaining
        UINT_32      interpolLoaded;              ///< Interpolation distance loaded
        UINT_32      interpolTotal;               ///< Total interpolation distance
    } MoveParam;
    
/** @struct Kinematics
    *   @brief This structure holds kinematics data
    *   \defgroup AxisTypes AxisTypes
    *   \defgroup Axis_t
    */
    struct Kinematics {
        BOOL active;                     ///< Kinematics active?
        robotParams_t params;            ///< Robot paramters like link lengths
        UINT_8 kinID;                    ///< Kinematics ID
        UINT_8 KinAxesMax;               ///< Maximum axes for kinematics
        UINT_8 KinAxesID[6];             ///< Axis numbers for kinematics
        frame_t userFrame[MAX_USER_FRAME]; ///< User frame active for this group
        frame_t toolFrame[MAX_TOOL_FRAME]; ///< Tool frame active for this group
        position globalPosition;         ///< Global position of end effector from origin
        position targetPosition;         ///< Target positio of the end effector
        position jointPosition;          ///< Joint position of the robot
    } Kinematics;
    
    /** @struct HardwareData
    *   @brief This structure holds hardwared data
    *   \defgroup AxisTypes AxisTypes
    *   \defgroup Axis_t
    */
    struct HardwareData {
        
    } HardwareData;
};

typedef struct errorCode {
    enum { INVALID_ARGUMENT, INVALID_COMMAND } commandError;
    enum { INVALID_TARGET, INVALID_SPEED } moveError;
} errorCode_t;


typedef struct {
    FLOAT a1, a2, a3, a4, a5;
} kinematics_data_t;


/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

// Move types
/** \def IDLE
 *  \brief Macro for idle state
 */
#define IDLE            0

/** \def MOVE_LINEAR
 *  \brief Macro for linear move
 */
#define MOVE_LINEAR     1

/** \def MOVE_CIRCULAR
 *  \brief Macro for circular move
 */
#define MOVE_CIRCULAR   2

/** \def MOVE_HELICAL
 *  \brief Macro for helical move
 */
#define MOVE_HELICAL    3

/** \def MOVE_JOG_FWD
 *  \brief Macro for forward jog
 */
#define MOVE_JOG_FWD    7

/** \def MOVE_JOG_REV
 *  \brief Macro for reverse jog
 */
#define MOVE_JOG_REV    8


#define SQUARE(n) (n*n)

/* Public variables ---------------------------------------------------------*/
extern union Axis_t  Axis[MAX_AXES];
extern robotPosition RobotTargets[MAX_ROBOT_TARGET];
#endif // !_AXIS_TYPES_H
/*
 * Copyright (c) 2009-2012 Freescale Semiconductor, Inc. All Rights Reserved.
 */

/*
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Freescale Semiconductor nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 *
 * ALTERNATIVELY, this software may be distributed under the terms of the
 * GNU General Public License ("GPL") as published by the Free Software
 * Foundation, either version 2 of that License or (at your option) any
 * later version.
 *
 * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef __DDI_POWER_INTERNAL_H
#define __DDI_POWER_INTERNAL_H

//////////////////////////////////////////////////////////////////////////////
//!   Includes
//////////////////////////////////////////////////////////////////////////////
#include <types.h>
#include "drivers/power/ddi_power.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

//! \brief Minimum time in milliseconds to wait before checking status.
#define MIN_STABLE_WAIT_TIME_LINREG 1000
//! \brief Maximum time in milliseconds to wait for a particular status.
#define MAX_STABLE_WAIT_TIME_LINREG 5000
//! \brief Time in milliseconds to wait between each status check.
#define RECHECK_WAIT_TIME_LINREG    500

//! \brief Minimum time in milliseconds to wait before checking status.
#define MIN_STABLE_WAIT_TIME_DCDC   15
//! \brief Maximum time in milliseconds to wait for a particular status.
#define MAX_STABLE_WAIT_TIME_DCDC   20000
//! \brief Time in milliseconds to wait between each status check.
#define RECHECK_WAIT_TIME_DCDC      10

//! \brief Minimum time in milliseconds to wait before checking status.
#define MIN_STABLE_WAIT_TIME_4P2    10
//! \brief Maximum time in milliseconds to wait for a particular status.
#define MAX_STABLE_WAIT_TIME_4P2    100000
//! \brief Time in milliseconds to wait between each status check.
#define RECHECK_WAIT_TIME_4P2       10

//! \brief Minimum time in milliseconds to wait before checking status.
#define MIN_RAIL_STABLE_WAIT_TIME_4P2    1000
//! \brief Maximum time in milliseconds to wait for a particular status.
#define MAX_RAIL_STABLE_WAIT_TIME_4P2    100000
//! \brief Time in milliseconds to wait between each status check.
#define RAIL_RECHECK_WAIT_TIME_4P2       500

//! \brief Maximum time in milliseconds to charge the 4p2 cap.  If the brownout
//! has not cleared by this time, then something else is loading down the line.
#define MAX_4P2_CAP_CHARGE_TIME 100000

//! \brief Maximum charge current, in milliamps, to use when charging the
//! 4p2 capacitor.
#define CHARGE_CURRENT_LIMIT_4P2_CAP        50
//! \brief Current step size, in milliamps, when incrementing the charge current
//! to target value.
#define CHARGE_CURRENT_STEP_SIZE_4P2_CAP    10
//! \brief Maximum combined current from 5V that the battery charger and
//! DCDC 4p2 circuit can consume.  In milliamps.
#define CHARGE_CURRENT_LIMIT_4P2_RAIL       780
//! \brief Current step size, in milliamps, when incrementing the charge current
//! to the target value.
#define CHARGE_CURRENT_STEP_SIZE_4P2_RAIL   100

////////////////////////////////////////////////////////////////////////////////
//! \brief Waits at least the requested amount of time.
//!
//! This function will either call a registered wait function, or the default
//! driver's wait function.  The default wait funciton will wait on the
//! microsecond's counter until the specified time has elapsed.  The registered
//! function can be registered with ddi_power_RegisterWaitFunction.
//!
//! \param[in] u32MicrosecondsToWait Number of microseconds to wait.
//!
////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_Wait(uint32_t u32MicrosecondsToWait);

////////////////////////////////////////////////////////////////////////////////
//! \brief Waits for the linear regulators to become stable.
//!
//! \fntype Function
//!
//! Causes the system to wait for the linear regulators to stabilize.  If the
//! function returns SUCCESS, the linear regulators have a stable outptut.
//!
//! \param[in] u32StableWaitTime Expected time to wait, in microseconds, for
//! the linear regulator to become stable.
//! \param[in] u32MaxWaitTime Maximum microseconds to wait for the linear
//! regulator to become stable.
//!
////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_WaitLinRegStable( uint32_t u32MinWaitTime,
                                       uint32_t u32MaxWaitTime,
                                       uint32_t u32RecheckTime );

/////////////////////////////////////////////////////////////////////////////////
//! \brief Returns true.
//!
//! \fntype Function
//!
//! This function just return true and must be called only from
//! ddi_power_WaitLinRegStable().  It is not intended to be used outside of
//! the power driver.
//!
//! \retval True Linear regulator output is stable.
//! \retval False Linear regulator output is not stable.
//!
//! \note The linear regulators may use an interrupt to notify us when they are
//! stable in the future.  We can add this functionality to the wait logic
//! when it becomes available.
/////////////////////////////////////////////////////////////////////////////////
bool ddi_power_IsLinRegStable( void );

////////////////////////////////////////////////////////////////////////////////
//! \brief Waits until the DCDC is stable, or the timeout occurs.
//!
//! This function provides the driver a mechanism to wait for the DCDC to
//! stabilize.  It will check the DCDC stability bit, and if not ready,
//! call the driver's wait function.  If the DCDC is not stable after the
//! maximum timeout value, this funciton will exit.
//!
//!
//!
//! \param[in] u32MinWaitTime Minimum amount of time, in microseconds,
//! to wait before checking if the DCDC has stabilized after its transition.
//!
//! \param[in] u32MaxWaitTime Maximum time, in microseconds, to wait
//! for the DCDC to stabilize.  If the DCDC has not stabilized after this time,
//! the function will exit with a timeout error.
//!
//! \param[in] u32RecheckTime Amount of time, in microseconds, to wait
//! before re-checking if the DCDC has stabilized.
//!
////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_WaitDcdcStable( uint32_t u32MinWaitTime,
                                     uint32_t u32MaxWaitTime,
                                     uint32_t u32RecheckTime );

/////////////////////////////////////////////////////////////////////////////////
//! \brief Returns transition status of the DCDC
//!
//! \fntype Function
//!
//! Returns the transition status of the DCDC>
//!
//! \retval True DCDC output is stable.
//! \retval False DCDC output is not stable.
//!
/////////////////////////////////////////////////////////////////////////////////
bool ddi_power_IsDcdcStable( void );

/////////////////////////////////////////////////////////////////////////////////
//! \brief Waits until the 4p2 rail is stable, or the timeout occurs.
//!
//! \fntype Function
//!
//! The 4p2 rail will become stable after some amount of time.  We will call the
//! register "wait" function.
//!
//! \param[in] u32MinWaitTime Minimum amount of time, in microseconds, to
//! wait before checking if the 4p2 rail has become stable.
//! \param[in] u32MaxWaitTime Maximum amount of time, in microseconds, to
//! wait for the 4p2 rail to stabilize.
//!
//! \retval SUCCESS The 4p2 rail stablilized before the maximum wait time elapsed.
//! \retval ERROR_DDI_POWER_ The maximum wait time elapsed.  The 4p2 rail may not
//! be stable.
//!
//! \note In the future, the 4p2 rail may notify us by interrupt when it
//! becomes stable.  We will incorporate that logic into this function
//! when it becomes available.
/////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_Wait4p2Stable( uint32_t u32MinWaitTime,
                                    uint32_t u32MaxWaitTime,
                                    uint32_t u32RecheckTime );


/////////////////////////////////////////////////////////////////////////////////
//! \brief Locks the power rail to prevent access from other threads.
//!
//! \fntype Function
//!
//! Calls an external function to lock the power rail using a mutex or
//! semaphore.
//!
//! \param[in] MsecToWait Milliseconds to wait for lock before timing out.
//!
//! \retval SUCCESS Power rail lock acquired.
/////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_LockRail( uint32_t MsecToWait );

/////////////////////////////////////////////////////////////////////////////////
//! \brief Unlocks the power rail to provide other threads access.
//!
//! \fntype Function
//!
//! Calls an external function to unlock the power rail by releasing a mutex or
//! semaphore.
//!
//! \param[in] MsecToWait Milliseconds to wait for unlock before timing out.
//!
//! \retval SUCCESS Power rail lock released.
/////////////////////////////////////////////////////////////////////////////////
RtStatus_t ddi_power_UnlockRail( uint32_t MsecToWait );


////////////////////////////////////////////////////////////////////////////////
//!
//! \brief 5V interrupt debouncing handler callback
//!
//! \fntype Function
//!
//! Services the 5V event by calling into the power supply to reconfigure for
//! possible new power source.  Also re-enables the 5V interrupt.
//!
//! Intended for use when os_pmi is not available.  The PMI version of this
//! handler should be called when available.
//!
//! \param[in] input       Not used
//!
//! \return None
//!
////////////////////////////////////////////////////////////////////////////////
void ddi_power_HandoffDebounceTimerCallback(uint32_t input);

////////////////////////////////////////////////////////////////////////////////
// Extern
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Prototypes
////////////////////////////////////////////////////////////////////////////////


#endif  //__DDI_POWER_INTERNAL_H
////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}



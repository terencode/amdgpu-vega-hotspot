/*
 * Copyright 2016 Advanced Micro Devices, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef _SMU7_THERMAL_H_
#define _SMU7_THERMAL_H_

#include "hwmgr.h"

#define SMU7_THERMAL_HIGH_ALERT_MASK         0x1
#define SMU7_THERMAL_LOW_ALERT_MASK          0x2

#define SMU7_THERMAL_MINIMUM_TEMP_READING    -256
#define SMU7_THERMAL_MAXIMUM_TEMP_READING    255

#define SMU7_THERMAL_MINIMUM_ALERT_TEMP      0
#define SMU7_THERMAL_MAXIMUM_ALERT_TEMP      255

#define FDO_PWM_MODE_STATIC  1
#define FDO_PWM_MODE_STATIC_RPM 5

extern int smu7_thermal_get_temperature(struct pp_hwmgr *hwmgr);
extern int smu7_thermal_get_temperature_asic_max(struct pp_hwmgr *hwmgr);
extern int smu7_thermal_stop_thermal_controller(struct pp_hwmgr *hwmgr);
extern int smu7_fan_ctrl_get_fan_speed_info(struct pp_hwmgr *hwmgr, struct phm_fan_speed_info *fan_speed_info);
extern int smu7_fan_ctrl_get_fan_speed_percent(struct pp_hwmgr *hwmgr, uint32_t *speed);
extern int smu7_fan_ctrl_set_default_mode(struct pp_hwmgr *hwmgr);
extern int smu7_fan_ctrl_set_static_mode(struct pp_hwmgr *hwmgr, uint32_t mode);
extern int smu7_fan_ctrl_set_fan_speed_percent(struct pp_hwmgr *hwmgr, uint32_t speed);
extern int smu7_fan_ctrl_reset_fan_speed_to_default(struct pp_hwmgr *hwmgr);
extern int smu7_thermal_ctrl_uninitialize_thermal_controller(struct pp_hwmgr *hwmgr);
extern int smu7_fan_ctrl_set_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t speed);
extern int smu7_fan_ctrl_get_fan_speed_rpm(struct pp_hwmgr *hwmgr, uint32_t *speed);
extern int smu7_fan_ctrl_stop_smc_fan_control(struct pp_hwmgr *hwmgr);
extern int smu7_thermal_disable_alert(struct pp_hwmgr *hwmgr);
extern int smu7_fan_ctrl_start_smc_fan_control(struct pp_hwmgr *hwmgr);
extern int smu7_start_thermal_controller(struct pp_hwmgr *hwmgr,
				struct PP_TemperatureRange *temperature_range);
#endif


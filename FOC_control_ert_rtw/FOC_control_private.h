/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_control_private.h
 *
 * Code generated for Simulink model 'FOC_control'.
 *
 * Model version                  : 5.63
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sat Feb  8 23:02:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: STMicroelectronics->ST10/Super10
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_FOC_control_private_h_
#define RTW_HEADER_FOC_control_private_h_
#include "rtwtypes.h"
#include "FOC_control_types.h"
#include "FOC_control.h"

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern real_T rt_hypotd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T prevIndex[], uint32_T maxIndex);

#endif                                 /* RTW_HEADER_FOC_control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

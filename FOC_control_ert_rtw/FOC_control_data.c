/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_control_data.c
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

#include "FOC_control.h"

/* Invariant block signals (default storage) */
const ConstB_FOC_control_T FOC_control_ConstB = {
  1.25                                 /* '<S10>/Gain' */
};

/* Constant parameters (default storage) */
const ConstP_FOC_control_T FOC_control_ConstP = {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S121>/Look-Up Table  Determine the sector of U* based on alpha (rad). '
   *   '<S124>/1-D Lookup Table'
   *   '<S130>/1-D Lookup Table'
   *   '<S130>/1-D Lookup Table1'
   *   '<S130>/1-D Lookup Table2'
   *   '<S130>/1-D Lookup Table3'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 },

  /* Pooled Parameter (Expression: [0:pi/3:5*pi/3])
   * Referenced by:
   *   '<S121>/Look-Up Table  Determine the sector of U* based on alpha (rad). '
   *   '<S124>/1-D Lookup Table'
   */
  { 0.0, 1.0471975511965976, 2.0943951023931953, 3.1415926535897936,
    4.1887902047863914, 5.2359877559829888 },

  /* Expression: pat1
   * Referenced by: '<S125>/Direct Look-Up Table (n-D)'
   */
  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 0.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0,
    0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0,
    1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0, 1.0, 1.0, 1.0, 0.0, 1.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

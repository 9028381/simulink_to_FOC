/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_control.c
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
#include "rtwtypes.h"
#include "FOC_control_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <float.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_FOC_control_T FOC_control_B;

/* Block states (default storage) */
DW_FOC_control_T FOC_control_DW;

/* External inputs (root inport signals with default storage) */
ExtU_FOC_control_T FOC_control_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_FOC_control_T FOC_control_Y;

/* Real-time model */
static RT_MODEL_FOC_control_T FOC_control_M_;
RT_MODEL_FOC_control_T *const FOC_control_M = &FOC_control_M_;
real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0UL];
    iLeft = 0UL;
    iRght = maxIndex;
    found = 0UL;
    while (found == 0UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx - 1UL;
        bpIdx = ((bpIdx + iLeft) - 1UL) >> 1UL;
      } else if (u0 < bp0[bpIdx + 1UL]) {
        found = 1UL;
      } else {
        iLeft = bpIdx + 1UL;
        bpIdx = ((bpIdx + iRght) + 1UL) >> 1UL;
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1UL] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex - 1UL;
    frac = (u0 - bp0[maxIndex - 1UL]) / (bp0[maxIndex] - bp0[maxIndex - 1UL]);
  }

  prevIndex[0UL] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[bpIdx + 1UL] - yL_0d0) * frac + yL_0d0;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      q = ceil(u1);
    } else {
      q = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != q)) {
      q = fabs(u0 / u1);
      if (!(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q)) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

real_T rt_hypotd_snf(real_T u0, real_T u1)
{
  real_T a;
  real_T b;
  real_T y;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = sqrt(a * a + 1.0) * b;
  } else if (a > b) {
    b /= a;
    y = sqrt(b * b + 1.0) * a;
  } else if (rtIsNaN(b)) {
    y = (rtNaN);
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T tmp;
  int16_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T q;
  real_T y;
  boolean_T yEq;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

/* Model step function */
void FOC_control_step(void)
{
  real_T rtb_Sum1_ft;
  real_T rtb_Sum1_kl;
  real_T rtb_Sum_c;
  real_T rtb_Sum_f;
  real_T rtb_Sum_k;
  real_T rtb_Switch1_idx_1;
  real_T rtb_iab_idx_0;
  real_T rtb_iab_idx_1;
  real_T rtb_rx;
  real_T rtb_thetay;
  real_T rtb_uDLookupTable3;
  int16_T tableOffset;
  boolean_T rtb_RelationalOperator1_i;
  boolean_T rtb_RelationalOperator2_l;
  boolean_T rtb_RelationalOperator_gb;

  /* Outport: '<Root>/Outport' incorporates:
   *  UnitDelay: '<S1>/Unit Delay'
   */
  FOC_control_Y.Outport = FOC_control_DW.UnitDelay_DSTATE;

  /* Outport: '<Root>/Outport1' incorporates:
   *  UnitDelay: '<S1>/Unit Delay1'
   */
  FOC_control_Y.Outport1 = FOC_control_DW.UnitDelay1_DSTATE;

  /* Outport: '<Root>/Outport2' incorporates:
   *  UnitDelay: '<S1>/Unit Delay2'
   */
  FOC_control_Y.Outport2 = FOC_control_DW.UnitDelay2_DSTATE;

  /* Gain: '<S10>/1//R' incorporates:
   *  Gain: '<S10>/1//K'
   *  Inport: '<Root>/iabc'
   *  Sum: '<S10>/Sum'
   */
  rtb_iab_idx_0 = (FOC_control_ConstB.Gain - FOC_control_U.vabc[0]) * 0.05 *
    200.0;
  rtb_iab_idx_1 = (FOC_control_ConstB.Gain - FOC_control_U.vabc[1]) * 0.05 *
    200.0;

  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Gain: '<S112>/one_by_sqrt3' incorporates:
   *  Sum: '<S112>/a_plus_2b'
   */
  rtb_Sum1_ft = ((rtb_iab_idx_0 + rtb_iab_idx_1) + rtb_iab_idx_1) *
    0.57735026918962584;

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */

  /* Sum: '<S6>/Sum' incorporates:
   *  Constant: '<S6>/Constant'
   *  Gain: '<S6>/Gain1'
   *  Inport: '<Root>/Angle'
   *  Math: '<S6>/Rem'
   */
  rtb_thetay = rt_remd_snf(6.0 * FOC_control_U.Angle, 6.2831853071795862) -
    1.5707963267948966;

  /* Trigonometry: '<S5>/SinCos1' incorporates:
   *  Trigonometry: '<S7>/SinCos1'
   */
  rtb_Sum_f = sin(rtb_thetay);
  rtb_uDLookupTable3 = cos(rtb_thetay);

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S1>/Sum1' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S112>/a16'
   *  Constant: '<S1>/Constant'
   *  Product: '<S113>/acos'
   *  Product: '<S113>/bsin'
   *  Sum: '<S113>/sum_Ds'
   *  Trigonometry: '<S5>/SinCos1'
   */
  rtb_iab_idx_1 = 0.0 - (rtb_iab_idx_0 * rtb_uDLookupTable3 + rtb_Sum1_ft *
    rtb_Sum_f);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Sum: '<S104>/Sum' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Sum: '<S1>/Sum1'
   */
  rtb_Sum_c = rtb_iab_idx_1 + FOC_control_DW.Integrator_DSTATE;

  /* Sum: '<S3>/Sum' incorporates:
   *  Inport: '<Root>/Angle'
   *  Inport: '<Root>/Tar'
   */
  rtb_Sum_k = FOC_control_U.Tar - FOC_control_U.Angle;

  /* MATLAB Function: '<S3>/MATLAB Function' */
  if (rtb_Sum_k < -3.1415926535897931) {
    rtb_Sum_k += 6.2831853071795862;
  } else if (rtb_Sum_k > 3.1415926535897931) {
    rtb_Sum_k -= 6.2831853071795862;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */

  /* Switch: '<S1>/Switch1' incorporates:
   *  Constant: '<S12>/Constant'
   *  Inport: '<Root>/Mode'
   *  Inport: '<Root>/Tar'
   *  RelationalOperator: '<S12>/Compare'
   */
  if (FOC_control_U.Mode < 2.0) {
    /* Sum: '<S56>/Sum' incorporates:
     *  DiscreteIntegrator: '<S47>/Integrator'
     *  Gain: '<S52>/Proportional Gain'
     */
    rtb_thetay = 5.0 * rtb_Sum_k + FOC_control_DW.Integrator_DSTATE_o;

    /* Saturate: '<S54>/Saturation' */
    if (rtb_thetay > 50.0) {
      rtb_thetay = 50.0;
    } else if (rtb_thetay < -50.0) {
      rtb_thetay = -50.0;
    }

    /* End of Saturate: '<S54>/Saturation' */
  } else {
    rtb_thetay = FOC_control_U.Tar;
  }

  /* End of Switch: '<S1>/Switch1' */

  /* Sum: '<S9>/Sum1' incorporates:
   *  Inport: '<Root>/Speed'
   */
  rtb_Sum1_kl = rtb_thetay - FOC_control_U.Speed;

  /* Switch: '<S1>/Switch2' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/Mode'
   *  Inport: '<Root>/Tar'
   *  RelationalOperator: '<S13>/Compare'
   */
  if (FOC_control_U.Mode < 3.0) {
    /* Sum: '<S223>/Sum' incorporates:
     *  DiscreteIntegrator: '<S214>/Integrator'
     *  Gain: '<S219>/Proportional Gain'
     */
    rtb_thetay = 5.0 * rtb_Sum1_kl + FOC_control_DW.Integrator_DSTATE_a;

    /* Saturate: '<S221>/Saturation' */
    if (rtb_thetay > 5.0) {
      rtb_thetay = 5.0;
    } else if (rtb_thetay < -5.0) {
      rtb_thetay = -5.0;
    }

    /* End of Saturate: '<S221>/Saturation' */
  } else {
    rtb_thetay = FOC_control_U.Tar;
  }

  /* End of Switch: '<S1>/Switch2' */

  /* Outputs for Atomic SubSystem: '<S5>/Park Transform' */
  /* Outputs for Atomic SubSystem: '<S5>/Clarke Transform' */
  /* Sum: '<S1>/Sum2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S112>/a16'
   *  Product: '<S113>/asin'
   *  Product: '<S113>/bcos'
   *  Sum: '<S113>/sum_Qs'
   *  Trigonometry: '<S5>/SinCos1'
   */
  rtb_iab_idx_0 = rtb_thetay - (rtb_Sum1_ft * rtb_uDLookupTable3 - rtb_iab_idx_0
    * rtb_Sum_f);

  /* End of Outputs for SubSystem: '<S5>/Clarke Transform' */
  /* End of Outputs for SubSystem: '<S5>/Park Transform' */

  /* Sum: '<S174>/Sum' incorporates:
   *  DiscreteIntegrator: '<S165>/Integrator'
   */
  rtb_Sum1_ft = rtb_iab_idx_0 + FOC_control_DW.Integrator_DSTATE_j;

  /* Saturate: '<S172>/Saturation' */
  if (rtb_Sum1_ft > 5.0) {
    rtb_Sum1_ft = 5.0;
  } else if (rtb_Sum1_ft < -5.0) {
    rtb_Sum1_ft = -5.0;
  }

  /* End of Saturate: '<S172>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S7>/Inverse Park Transform1' */
  /* Switch: '<S117>/Switch' incorporates:
   *  Product: '<S115>/dcos'
   *  Product: '<S115>/dsin'
   *  Product: '<S115>/qcos'
   *  Product: '<S115>/qsin'
   *  Sum: '<S115>/sum_alpha'
   *  Sum: '<S115>/sum_beta'
   */
  rtb_thetay = rtb_Sum_c * rtb_uDLookupTable3 - rtb_Sum1_ft * rtb_Sum_f;
  rtb_Sum_c = rtb_Sum1_ft * rtb_uDLookupTable3 + rtb_Sum_c * rtb_Sum_f;

  /* Switch: '<S119>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S115>/a16'
   *  Fcn: '<S122>/x->r'
   *  Switch: '<S119>/Switch2'
   */
  rtb_Sum_f = rt_hypotd_snf(rtb_thetay, rtb_Sum_c);

  /* End of Outputs for SubSystem: '<S7>/Inverse Park Transform1' */

  /* Saturate: '<S119>/0<m<1 ' */
  if (rtb_Sum_f > 1.0) {
    rtb_Sum_f = 1.0;
  }

  /* End of Saturate: '<S119>/0<m<1 ' */

  /* Outputs for Atomic SubSystem: '<S7>/Inverse Park Transform1' */
  /* Math: '<S119>/Math Function2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S115>/a16'
   *  Constant: '<S119>/Constant2'
   *  Fcn: '<S122>/x->theta'
   *  Switch: '<S119>/Switch1'
   *  Switch: '<S119>/Switch3'
   */
  rtb_thetay = rt_modd_snf(rt_atan2d_snf(rtb_Sum_c, rtb_thetay),
    6.2831853071795862);

  /* End of Outputs for SubSystem: '<S7>/Inverse Park Transform1' */

  /* Outputs for Enabled SubSystem: '<S118>/SV Modulator Pattern #1' incorporates:
   *  EnablePort: '<S120>/Enable'
   */
  /* Lookup_n-D: '<S124>/1-D Lookup Table' incorporates:
   *  Math: '<S119>/Math Function2'
   */
  rtb_uDLookupTable3 = look1_pbinlxpw(rtb_thetay, FOC_control_ConstP.pooled5,
    FOC_control_ConstP.pooled4, &FOC_control_DW.m_bpIndex_e, 5UL);

  /* Rounding: '<S124>/Rounding Function' */
  rtb_uDLookupTable3 = floor(rtb_uDLookupTable3);

  /* Sum: '<S123>/Sum4' incorporates:
   *  Constant: '<S123>/Constant1'
   *  Constant: '<S123>/Constant2'
   *  Product: '<S123>/Product1'
   *  Sum: '<S123>/Sum1'
   */
  rtb_Sum_c = rtb_thetay - (rtb_uDLookupTable3 - 1.0) * 1.0471975511965976;

  /* Product: '<S123>/Product' incorporates:
   *  Constant: '<S123>/Constant'
   *  Sum: '<S123>/Sum'
   *  Trigonometry: '<S123>/Trigonometric Function'
   *  Trigonometry: '<S123>/Trigonometric Function1'
   */
  rtb_thetay = cos(rtb_Sum_c + 0.52359877559829882) * rtb_Sum_f;
  rtb_Sum_c = rtb_Sum_f * sin(rtb_Sum_c);

  /* Gain: '<S123>/1//Fc' incorporates:
   *  Constant: '<S123>/Constant8'
   *  Sum: '<S123>/Sum2'
   *  Sum: '<S123>/Sum3'
   */
  rtb_Sum1_ft = (1.0 - (rtb_thetay + rtb_Sum_c)) * 0.001;

  /* Switch: '<S123>/Switch1' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Gain: '<S123>/1//Fc'
   *  Math: '<S124>/Math Function1'
   */
  if (rt_modd_snf(rtb_uDLookupTable3, 2.0) >= 0.5) {
    rtb_Sum_f = 0.001 * rtb_thetay;
    rtb_Switch1_idx_1 = 0.001 * rtb_Sum_c;
  } else {
    rtb_Sum_f = 0.001 * rtb_Sum_c;
    rtb_Switch1_idx_1 = 0.001 * rtb_thetay;
  }

  /* Gain: '<S126>/Gain' incorporates:
   *  Constant: '<S129>/Constant2'
   *  DigitalClock: '<S129>/Digital Clock'
   *  Fcn: '<S126>/Fcn'
   *  Fcn: '<S129>/Fcn'
   *  Gain: '<S129>/1\ib1'
   *  Math: '<S129>/Math Function'
   */
  rtb_Sum_c = ((1000.0 * rt_remd_snf(((FOC_control_M->Timing.clockTick0) *
    0.0001), 0.001) * 2.0 - 1.0) + 1.0) * 0.5 * 0.001;

  /* Gain: '<S128>/1//4' incorporates:
   *  Switch: '<S123>/Switch1'
   */
  rtb_rx = 0.25 * rtb_Sum1_ft;

  /* Gain: '<S128>/ 1//2 ' */
  rtb_Sum_f *= 0.5;

  /* Sum: '<S128>/Sum5' */
  rtb_thetay = rtb_rx + rtb_Sum_f;

  /* RelationalOperator: '<S126>/Relational Operator' */
  rtb_RelationalOperator_gb = (rtb_Sum_c >= rtb_thetay);

  /* Gain: '<S128>/  1//2' */
  rtb_Switch1_idx_1 *= 0.5;

  /* Sum: '<S128>/Sum6' */
  rtb_thetay += rtb_Switch1_idx_1;

  /* RelationalOperator: '<S126>/Relational Operator1' */
  rtb_RelationalOperator1_i = (rtb_Sum_c >= rtb_thetay);

  /* Sum: '<S128>/Sum7' incorporates:
   *  Gain: '<S128>/ 1//2'
   *  Switch: '<S123>/Switch1'
   */
  rtb_thetay += 0.5 * rtb_Sum1_ft;

  /* RelationalOperator: '<S126>/Relational Operator2' */
  rtb_RelationalOperator2_l = (rtb_Sum_c >= rtb_thetay);

  /* Sum: '<S128>/Sum8' */
  rtb_thetay += rtb_Switch1_idx_1;

  /* LookupNDDirect: '<S125>/Direct Look-Up Table (n-D)' incorporates:
   *  Constant: '<S125>/Constant2'
   *  Constant: '<S125>/Constant3'
   *  Constant: '<S126>/Constant7'
   *  RelationalOperator: '<S126>/Relational Operator3'
   *  RelationalOperator: '<S126>/Relational Operator4'
   *  RelationalOperator: '<S126>/Relational Operator5'
   *  Sum: '<S125>/Sum'
   *  Sum: '<S125>/Sum1'
   *  Sum: '<S126>/Sum1'
   *  Sum: '<S128>/Sum9'
   *
   * About '<S125>/Direct Look-Up Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  if (rtb_uDLookupTable3 - 1.0 > 5.0) {
    rtb_uDLookupTable3 = 5.0;
  } else if (rtb_uDLookupTable3 - 1.0 < 0.0) {
    rtb_uDLookupTable3 = 0.0;
  } else {
    rtb_uDLookupTable3--;
  }

  tableOffset = (int16_T)(((real_T)((((((rtb_Sum_c >= rtb_rx) +
    rtb_RelationalOperator_gb) + rtb_RelationalOperator1_i) +
    rtb_RelationalOperator2_l) + (rtb_Sum_c >= rtb_thetay)) + (rtb_Sum_c >=
    rtb_thetay + rtb_Sum_f)) + 1.0) - 1.0) * 3 + (int16_T)rtb_uDLookupTable3 *
    21;

  /* LookupNDDirect: '<S125>/Direct Look-Up Table (n-D)'
   *
   * About '<S125>/Direct Look-Up Table (n-D)':
   *  3-dimensional Direct Look-Up returning a Vector,
   *  which is contiguous for column-major array
   *     Remove protection against out-of-range input in generated code: 'off'
   */
  FOC_control_B.Q1Q3Q5[0] =
    FOC_control_ConstP.DirectLookUpTablenD_table[tableOffset];
  FOC_control_B.Q1Q3Q5[1] =
    FOC_control_ConstP.DirectLookUpTablenD_table[tableOffset + 1];
  FOC_control_B.Q1Q3Q5[2] =
    FOC_control_ConstP.DirectLookUpTablenD_table[tableOffset + 2];

  /* End of Outputs for SubSystem: '<S118>/SV Modulator Pattern #1' */

  /* Update for UnitDelay: '<S1>/Unit Delay' incorporates:
   *  MultiPortSwitch: '<S118>/Multiport Switch'
   */
  FOC_control_DW.UnitDelay_DSTATE = FOC_control_B.Q1Q3Q5[0];

  /* Update for UnitDelay: '<S1>/Unit Delay1' incorporates:
   *  MultiPortSwitch: '<S118>/Multiport Switch'
   */
  FOC_control_DW.UnitDelay1_DSTATE = FOC_control_B.Q1Q3Q5[1];

  /* Update for UnitDelay: '<S1>/Unit Delay2' incorporates:
   *  MultiPortSwitch: '<S118>/Multiport Switch'
   */
  FOC_control_DW.UnitDelay2_DSTATE = FOC_control_B.Q1Q3Q5[2];

  /* Update for DiscreteIntegrator: '<S95>/Integrator' */
  FOC_control_DW.Integrator_DSTATE += rtb_iab_idx_1 * 0.0001;

  /* Update for DiscreteIntegrator: '<S47>/Integrator' incorporates:
   *  Gain: '<S44>/Integral Gain'
   */
  FOC_control_DW.Integrator_DSTATE_o += 3.0 * rtb_Sum_k * 0.0001;

  /* Update for DiscreteIntegrator: '<S214>/Integrator' incorporates:
   *  Gain: '<S211>/Integral Gain'
   */
  FOC_control_DW.Integrator_DSTATE_a += 3.0 * rtb_Sum1_kl * 0.0001;

  /* Update for DiscreteIntegrator: '<S165>/Integrator' */
  FOC_control_DW.Integrator_DSTATE_j += 0.0001 * rtb_iab_idx_0;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FOC_control_M->Timing.clockTick0++;
}

/* Model initialize function */
void FOC_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
}

/* Model terminate function */
void FOC_control_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

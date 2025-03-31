/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: FOC_control.h
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

#ifndef RTW_HEADER_FOC_control_h_
#define RTW_HEADER_FOC_control_h_
#ifndef FOC_control_COMMON_INCLUDES_
#define FOC_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* FOC_control_COMMON_INCLUDES_ */

#include "FOC_control_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Q1Q3Q5[3];                    /* '<S125>/Direct Look-Up Table (n-D)' */
} B_FOC_control_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S1>/Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S1>/Unit Delay2' */
  real_T Integrator_DSTATE;            /* '<S95>/Integrator' */
  real_T Integrator_DSTATE_o;          /* '<S47>/Integrator' */
  real_T Integrator_DSTATE_a;          /* '<S214>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S165>/Integrator' */
  uint32_T m_bpIndex_e;                /* '<S124>/1-D Lookup Table' */
} DW_FOC_control_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real_T Gain;                   /* '<S10>/Gain' */
} ConstB_FOC_control_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S121>/Look-Up Table  Determine the sector of U* based on alpha (rad). '
   *   '<S124>/1-D Lookup Table'
   *   '<S130>/1-D Lookup Table'
   *   '<S130>/1-D Lookup Table1'
   *   '<S130>/1-D Lookup Table2'
   *   '<S130>/1-D Lookup Table3'
   */
  real_T pooled4[6];

  /* Pooled Parameter (Expression: [0:pi/3:5*pi/3])
   * Referenced by:
   *   '<S121>/Look-Up Table  Determine the sector of U* based on alpha (rad). '
   *   '<S124>/1-D Lookup Table'
   */
  real_T pooled5[6];

  /* Expression: pat1
   * Referenced by: '<S125>/Direct Look-Up Table (n-D)'
   */
  real_T DirectLookUpTablenD_table[126];
} ConstP_FOC_control_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  real_T Speed;                        /* '<Root>/Speed' */
  real_T Angle;                        /* '<Root>/Angle' */
  real_T vabc[3];                      /* '<Root>/iabc' */
  real_T Tar;                          /* '<Root>/Tar' */
  real_T Mode;                         /* '<Root>/Mode' */
} ExtU_FOC_control_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Outport;                      /* '<Root>/Outport' */
  real_T Outport1;                     /* '<Root>/Outport1' */
  real_T Outport2;                     /* '<Root>/Outport2' */
} ExtY_FOC_control_T;

/* Real-time Model Data Structure */
struct tag_RTM_FOC_control_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block signals (default storage) */
extern B_FOC_control_T FOC_control_B;

/* Block states (default storage) */
extern DW_FOC_control_T FOC_control_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_FOC_control_T FOC_control_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_FOC_control_T FOC_control_Y;
extern const ConstB_FOC_control_T FOC_control_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_FOC_control_T FOC_control_ConstP;

/* Model entry point functions */
extern void FOC_control_initialize(void);
extern void FOC_control_step(void);
extern void FOC_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FOC_control_T *const FOC_control_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Scope' : Unused code path elimination
 * Block '<S1>/Scope1' : Unused code path elimination
 * Block '<S112>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate' : Unused code path elimination
 * Block '<S113>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S5>/Scope' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate' : Unused code path elimination
 * Block '<S115>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S92>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S100>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S162>/Integral Gain' : Eliminated nontunable gain of 1
 * Block '<S170>/Proportional Gain' : Eliminated nontunable gain of 1
 * Block '<S114>/Offset' : Unused code path elimination
 * Block '<S114>/Unary_Minus' : Unused code path elimination
 * Block '<S117>/Offset' : Unused code path elimination
 * Block '<S117>/Unary_Minus' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('foc/FOC_control')    - opens subsystem foc/FOC_control
 * hilite_system('foc/FOC_control/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'foc'
 * '<S1>'   : 'foc/FOC_control'
 * '<S2>'   : 'foc/FOC_control/Mode_control'
 * '<S3>'   : 'foc/FOC_control/angle_pid'
 * '<S4>'   : 'foc/FOC_control/d_pid'
 * '<S5>'   : 'foc/FOC_control/iab_2_qd'
 * '<S6>'   : 'foc/FOC_control/m2e_angle'
 * '<S7>'   : 'foc/FOC_control/q_control'
 * '<S8>'   : 'foc/FOC_control/q_pid'
 * '<S9>'   : 'foc/FOC_control/speed_pid'
 * '<S10>'  : 'foc/FOC_control/v_2_i'
 * '<S11>'  : 'foc/FOC_control/Mode_control/Compare To Constant'
 * '<S12>'  : 'foc/FOC_control/Mode_control/Compare To Constant1'
 * '<S13>'  : 'foc/FOC_control/Mode_control/Compare To Constant2'
 * '<S14>'  : 'foc/FOC_control/angle_pid/Angle_pid'
 * '<S15>'  : 'foc/FOC_control/angle_pid/MATLAB Function'
 * '<S16>'  : 'foc/FOC_control/angle_pid/Angle_pid/Anti-windup'
 * '<S17>'  : 'foc/FOC_control/angle_pid/Angle_pid/D Gain'
 * '<S18>'  : 'foc/FOC_control/angle_pid/Angle_pid/Filter'
 * '<S19>'  : 'foc/FOC_control/angle_pid/Angle_pid/Filter ICs'
 * '<S20>'  : 'foc/FOC_control/angle_pid/Angle_pid/I Gain'
 * '<S21>'  : 'foc/FOC_control/angle_pid/Angle_pid/Ideal P Gain'
 * '<S22>'  : 'foc/FOC_control/angle_pid/Angle_pid/Ideal P Gain Fdbk'
 * '<S23>'  : 'foc/FOC_control/angle_pid/Angle_pid/Integrator'
 * '<S24>'  : 'foc/FOC_control/angle_pid/Angle_pid/Integrator ICs'
 * '<S25>'  : 'foc/FOC_control/angle_pid/Angle_pid/N Copy'
 * '<S26>'  : 'foc/FOC_control/angle_pid/Angle_pid/N Gain'
 * '<S27>'  : 'foc/FOC_control/angle_pid/Angle_pid/P Copy'
 * '<S28>'  : 'foc/FOC_control/angle_pid/Angle_pid/Parallel P Gain'
 * '<S29>'  : 'foc/FOC_control/angle_pid/Angle_pid/Reset Signal'
 * '<S30>'  : 'foc/FOC_control/angle_pid/Angle_pid/Saturation'
 * '<S31>'  : 'foc/FOC_control/angle_pid/Angle_pid/Saturation Fdbk'
 * '<S32>'  : 'foc/FOC_control/angle_pid/Angle_pid/Sum'
 * '<S33>'  : 'foc/FOC_control/angle_pid/Angle_pid/Sum Fdbk'
 * '<S34>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tracking Mode'
 * '<S35>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tracking Mode Sum'
 * '<S36>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tsamp - Integral'
 * '<S37>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tsamp - Ngain'
 * '<S38>'  : 'foc/FOC_control/angle_pid/Angle_pid/postSat Signal'
 * '<S39>'  : 'foc/FOC_control/angle_pid/Angle_pid/preSat Signal'
 * '<S40>'  : 'foc/FOC_control/angle_pid/Angle_pid/Anti-windup/Passthrough'
 * '<S41>'  : 'foc/FOC_control/angle_pid/Angle_pid/D Gain/Disabled'
 * '<S42>'  : 'foc/FOC_control/angle_pid/Angle_pid/Filter/Disabled'
 * '<S43>'  : 'foc/FOC_control/angle_pid/Angle_pid/Filter ICs/Disabled'
 * '<S44>'  : 'foc/FOC_control/angle_pid/Angle_pid/I Gain/Internal Parameters'
 * '<S45>'  : 'foc/FOC_control/angle_pid/Angle_pid/Ideal P Gain/Passthrough'
 * '<S46>'  : 'foc/FOC_control/angle_pid/Angle_pid/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'foc/FOC_control/angle_pid/Angle_pid/Integrator/Discrete'
 * '<S48>'  : 'foc/FOC_control/angle_pid/Angle_pid/Integrator ICs/Internal IC'
 * '<S49>'  : 'foc/FOC_control/angle_pid/Angle_pid/N Copy/Disabled wSignal Specification'
 * '<S50>'  : 'foc/FOC_control/angle_pid/Angle_pid/N Gain/Disabled'
 * '<S51>'  : 'foc/FOC_control/angle_pid/Angle_pid/P Copy/Disabled'
 * '<S52>'  : 'foc/FOC_control/angle_pid/Angle_pid/Parallel P Gain/Internal Parameters'
 * '<S53>'  : 'foc/FOC_control/angle_pid/Angle_pid/Reset Signal/Disabled'
 * '<S54>'  : 'foc/FOC_control/angle_pid/Angle_pid/Saturation/Enabled'
 * '<S55>'  : 'foc/FOC_control/angle_pid/Angle_pid/Saturation Fdbk/Disabled'
 * '<S56>'  : 'foc/FOC_control/angle_pid/Angle_pid/Sum/Sum_PI'
 * '<S57>'  : 'foc/FOC_control/angle_pid/Angle_pid/Sum Fdbk/Disabled'
 * '<S58>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tracking Mode/Disabled'
 * '<S59>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'foc/FOC_control/angle_pid/Angle_pid/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'foc/FOC_control/angle_pid/Angle_pid/postSat Signal/Forward_Path'
 * '<S63>'  : 'foc/FOC_control/angle_pid/Angle_pid/preSat Signal/Forward_Path'
 * '<S64>'  : 'foc/FOC_control/d_pid/Anti-windup'
 * '<S65>'  : 'foc/FOC_control/d_pid/D Gain'
 * '<S66>'  : 'foc/FOC_control/d_pid/Filter'
 * '<S67>'  : 'foc/FOC_control/d_pid/Filter ICs'
 * '<S68>'  : 'foc/FOC_control/d_pid/I Gain'
 * '<S69>'  : 'foc/FOC_control/d_pid/Ideal P Gain'
 * '<S70>'  : 'foc/FOC_control/d_pid/Ideal P Gain Fdbk'
 * '<S71>'  : 'foc/FOC_control/d_pid/Integrator'
 * '<S72>'  : 'foc/FOC_control/d_pid/Integrator ICs'
 * '<S73>'  : 'foc/FOC_control/d_pid/N Copy'
 * '<S74>'  : 'foc/FOC_control/d_pid/N Gain'
 * '<S75>'  : 'foc/FOC_control/d_pid/P Copy'
 * '<S76>'  : 'foc/FOC_control/d_pid/Parallel P Gain'
 * '<S77>'  : 'foc/FOC_control/d_pid/Reset Signal'
 * '<S78>'  : 'foc/FOC_control/d_pid/Saturation'
 * '<S79>'  : 'foc/FOC_control/d_pid/Saturation Fdbk'
 * '<S80>'  : 'foc/FOC_control/d_pid/Sum'
 * '<S81>'  : 'foc/FOC_control/d_pid/Sum Fdbk'
 * '<S82>'  : 'foc/FOC_control/d_pid/Tracking Mode'
 * '<S83>'  : 'foc/FOC_control/d_pid/Tracking Mode Sum'
 * '<S84>'  : 'foc/FOC_control/d_pid/Tsamp - Integral'
 * '<S85>'  : 'foc/FOC_control/d_pid/Tsamp - Ngain'
 * '<S86>'  : 'foc/FOC_control/d_pid/postSat Signal'
 * '<S87>'  : 'foc/FOC_control/d_pid/preSat Signal'
 * '<S88>'  : 'foc/FOC_control/d_pid/Anti-windup/Passthrough'
 * '<S89>'  : 'foc/FOC_control/d_pid/D Gain/Disabled'
 * '<S90>'  : 'foc/FOC_control/d_pid/Filter/Disabled'
 * '<S91>'  : 'foc/FOC_control/d_pid/Filter ICs/Disabled'
 * '<S92>'  : 'foc/FOC_control/d_pid/I Gain/Internal Parameters'
 * '<S93>'  : 'foc/FOC_control/d_pid/Ideal P Gain/Passthrough'
 * '<S94>'  : 'foc/FOC_control/d_pid/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'foc/FOC_control/d_pid/Integrator/Discrete'
 * '<S96>'  : 'foc/FOC_control/d_pid/Integrator ICs/Internal IC'
 * '<S97>'  : 'foc/FOC_control/d_pid/N Copy/Disabled wSignal Specification'
 * '<S98>'  : 'foc/FOC_control/d_pid/N Gain/Disabled'
 * '<S99>'  : 'foc/FOC_control/d_pid/P Copy/Disabled'
 * '<S100>' : 'foc/FOC_control/d_pid/Parallel P Gain/Internal Parameters'
 * '<S101>' : 'foc/FOC_control/d_pid/Reset Signal/Disabled'
 * '<S102>' : 'foc/FOC_control/d_pid/Saturation/Passthrough'
 * '<S103>' : 'foc/FOC_control/d_pid/Saturation Fdbk/Disabled'
 * '<S104>' : 'foc/FOC_control/d_pid/Sum/Sum_PI'
 * '<S105>' : 'foc/FOC_control/d_pid/Sum Fdbk/Disabled'
 * '<S106>' : 'foc/FOC_control/d_pid/Tracking Mode/Disabled'
 * '<S107>' : 'foc/FOC_control/d_pid/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'foc/FOC_control/d_pid/Tsamp - Integral/Passthrough'
 * '<S109>' : 'foc/FOC_control/d_pid/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'foc/FOC_control/d_pid/postSat Signal/Forward_Path'
 * '<S111>' : 'foc/FOC_control/d_pid/preSat Signal/Forward_Path'
 * '<S112>' : 'foc/FOC_control/iab_2_qd/Clarke Transform'
 * '<S113>' : 'foc/FOC_control/iab_2_qd/Park Transform'
 * '<S114>' : 'foc/FOC_control/iab_2_qd/Park Transform/Switch_Axis'
 * '<S115>' : 'foc/FOC_control/q_control/Inverse Park Transform1'
 * '<S116>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)'
 * '<S117>' : 'foc/FOC_control/q_control/Inverse Park Transform1/Switch_Axis'
 * '<S118>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model'
 * '<S119>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)'
 * '<S120>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1'
 * '<S121>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2'
 * '<S122>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/Determine reference vector (U*)/Cartesian to Polar'
 * '<S123>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Compute time duration of switching states (Ta,Tb,To) '
 * '<S124>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Determine the sector of U* based on alpha (rad). Also, determine if the sector number is odd'
 * '<S125>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern'
 * '<S126>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To'
 * '<S127>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator'
 * '<S128>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Subsystem'
 * '<S129>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #1/Generate  pulse pattern/Determine interval of the PWM period based on Ta Tb and To/Sawtooth Generator/Model'
 * '<S130>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Conv_table'
 * '<S131>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Polar to Cartesian'
 * '<S132>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator'
 * '<S133>' : 'foc/FOC_control/q_control/SVPWM Generator (2-Level)/Model/SV Modulator Pattern #2/Triangle Generator/Model'
 * '<S134>' : 'foc/FOC_control/q_pid/Anti-windup'
 * '<S135>' : 'foc/FOC_control/q_pid/D Gain'
 * '<S136>' : 'foc/FOC_control/q_pid/Filter'
 * '<S137>' : 'foc/FOC_control/q_pid/Filter ICs'
 * '<S138>' : 'foc/FOC_control/q_pid/I Gain'
 * '<S139>' : 'foc/FOC_control/q_pid/Ideal P Gain'
 * '<S140>' : 'foc/FOC_control/q_pid/Ideal P Gain Fdbk'
 * '<S141>' : 'foc/FOC_control/q_pid/Integrator'
 * '<S142>' : 'foc/FOC_control/q_pid/Integrator ICs'
 * '<S143>' : 'foc/FOC_control/q_pid/N Copy'
 * '<S144>' : 'foc/FOC_control/q_pid/N Gain'
 * '<S145>' : 'foc/FOC_control/q_pid/P Copy'
 * '<S146>' : 'foc/FOC_control/q_pid/Parallel P Gain'
 * '<S147>' : 'foc/FOC_control/q_pid/Reset Signal'
 * '<S148>' : 'foc/FOC_control/q_pid/Saturation'
 * '<S149>' : 'foc/FOC_control/q_pid/Saturation Fdbk'
 * '<S150>' : 'foc/FOC_control/q_pid/Sum'
 * '<S151>' : 'foc/FOC_control/q_pid/Sum Fdbk'
 * '<S152>' : 'foc/FOC_control/q_pid/Tracking Mode'
 * '<S153>' : 'foc/FOC_control/q_pid/Tracking Mode Sum'
 * '<S154>' : 'foc/FOC_control/q_pid/Tsamp - Integral'
 * '<S155>' : 'foc/FOC_control/q_pid/Tsamp - Ngain'
 * '<S156>' : 'foc/FOC_control/q_pid/postSat Signal'
 * '<S157>' : 'foc/FOC_control/q_pid/preSat Signal'
 * '<S158>' : 'foc/FOC_control/q_pid/Anti-windup/Passthrough'
 * '<S159>' : 'foc/FOC_control/q_pid/D Gain/Disabled'
 * '<S160>' : 'foc/FOC_control/q_pid/Filter/Disabled'
 * '<S161>' : 'foc/FOC_control/q_pid/Filter ICs/Disabled'
 * '<S162>' : 'foc/FOC_control/q_pid/I Gain/Internal Parameters'
 * '<S163>' : 'foc/FOC_control/q_pid/Ideal P Gain/Passthrough'
 * '<S164>' : 'foc/FOC_control/q_pid/Ideal P Gain Fdbk/Disabled'
 * '<S165>' : 'foc/FOC_control/q_pid/Integrator/Discrete'
 * '<S166>' : 'foc/FOC_control/q_pid/Integrator ICs/Internal IC'
 * '<S167>' : 'foc/FOC_control/q_pid/N Copy/Disabled wSignal Specification'
 * '<S168>' : 'foc/FOC_control/q_pid/N Gain/Disabled'
 * '<S169>' : 'foc/FOC_control/q_pid/P Copy/Disabled'
 * '<S170>' : 'foc/FOC_control/q_pid/Parallel P Gain/Internal Parameters'
 * '<S171>' : 'foc/FOC_control/q_pid/Reset Signal/Disabled'
 * '<S172>' : 'foc/FOC_control/q_pid/Saturation/Enabled'
 * '<S173>' : 'foc/FOC_control/q_pid/Saturation Fdbk/Disabled'
 * '<S174>' : 'foc/FOC_control/q_pid/Sum/Sum_PI'
 * '<S175>' : 'foc/FOC_control/q_pid/Sum Fdbk/Disabled'
 * '<S176>' : 'foc/FOC_control/q_pid/Tracking Mode/Disabled'
 * '<S177>' : 'foc/FOC_control/q_pid/Tracking Mode Sum/Passthrough'
 * '<S178>' : 'foc/FOC_control/q_pid/Tsamp - Integral/Passthrough'
 * '<S179>' : 'foc/FOC_control/q_pid/Tsamp - Ngain/Passthrough'
 * '<S180>' : 'foc/FOC_control/q_pid/postSat Signal/Forward_Path'
 * '<S181>' : 'foc/FOC_control/q_pid/preSat Signal/Forward_Path'
 * '<S182>' : 'foc/FOC_control/speed_pid/Speed_pid'
 * '<S183>' : 'foc/FOC_control/speed_pid/Speed_pid/Anti-windup'
 * '<S184>' : 'foc/FOC_control/speed_pid/Speed_pid/D Gain'
 * '<S185>' : 'foc/FOC_control/speed_pid/Speed_pid/Filter'
 * '<S186>' : 'foc/FOC_control/speed_pid/Speed_pid/Filter ICs'
 * '<S187>' : 'foc/FOC_control/speed_pid/Speed_pid/I Gain'
 * '<S188>' : 'foc/FOC_control/speed_pid/Speed_pid/Ideal P Gain'
 * '<S189>' : 'foc/FOC_control/speed_pid/Speed_pid/Ideal P Gain Fdbk'
 * '<S190>' : 'foc/FOC_control/speed_pid/Speed_pid/Integrator'
 * '<S191>' : 'foc/FOC_control/speed_pid/Speed_pid/Integrator ICs'
 * '<S192>' : 'foc/FOC_control/speed_pid/Speed_pid/N Copy'
 * '<S193>' : 'foc/FOC_control/speed_pid/Speed_pid/N Gain'
 * '<S194>' : 'foc/FOC_control/speed_pid/Speed_pid/P Copy'
 * '<S195>' : 'foc/FOC_control/speed_pid/Speed_pid/Parallel P Gain'
 * '<S196>' : 'foc/FOC_control/speed_pid/Speed_pid/Reset Signal'
 * '<S197>' : 'foc/FOC_control/speed_pid/Speed_pid/Saturation'
 * '<S198>' : 'foc/FOC_control/speed_pid/Speed_pid/Saturation Fdbk'
 * '<S199>' : 'foc/FOC_control/speed_pid/Speed_pid/Sum'
 * '<S200>' : 'foc/FOC_control/speed_pid/Speed_pid/Sum Fdbk'
 * '<S201>' : 'foc/FOC_control/speed_pid/Speed_pid/Tracking Mode'
 * '<S202>' : 'foc/FOC_control/speed_pid/Speed_pid/Tracking Mode Sum'
 * '<S203>' : 'foc/FOC_control/speed_pid/Speed_pid/Tsamp - Integral'
 * '<S204>' : 'foc/FOC_control/speed_pid/Speed_pid/Tsamp - Ngain'
 * '<S205>' : 'foc/FOC_control/speed_pid/Speed_pid/postSat Signal'
 * '<S206>' : 'foc/FOC_control/speed_pid/Speed_pid/preSat Signal'
 * '<S207>' : 'foc/FOC_control/speed_pid/Speed_pid/Anti-windup/Passthrough'
 * '<S208>' : 'foc/FOC_control/speed_pid/Speed_pid/D Gain/Disabled'
 * '<S209>' : 'foc/FOC_control/speed_pid/Speed_pid/Filter/Disabled'
 * '<S210>' : 'foc/FOC_control/speed_pid/Speed_pid/Filter ICs/Disabled'
 * '<S211>' : 'foc/FOC_control/speed_pid/Speed_pid/I Gain/Internal Parameters'
 * '<S212>' : 'foc/FOC_control/speed_pid/Speed_pid/Ideal P Gain/Passthrough'
 * '<S213>' : 'foc/FOC_control/speed_pid/Speed_pid/Ideal P Gain Fdbk/Disabled'
 * '<S214>' : 'foc/FOC_control/speed_pid/Speed_pid/Integrator/Discrete'
 * '<S215>' : 'foc/FOC_control/speed_pid/Speed_pid/Integrator ICs/Internal IC'
 * '<S216>' : 'foc/FOC_control/speed_pid/Speed_pid/N Copy/Disabled wSignal Specification'
 * '<S217>' : 'foc/FOC_control/speed_pid/Speed_pid/N Gain/Disabled'
 * '<S218>' : 'foc/FOC_control/speed_pid/Speed_pid/P Copy/Disabled'
 * '<S219>' : 'foc/FOC_control/speed_pid/Speed_pid/Parallel P Gain/Internal Parameters'
 * '<S220>' : 'foc/FOC_control/speed_pid/Speed_pid/Reset Signal/Disabled'
 * '<S221>' : 'foc/FOC_control/speed_pid/Speed_pid/Saturation/Enabled'
 * '<S222>' : 'foc/FOC_control/speed_pid/Speed_pid/Saturation Fdbk/Disabled'
 * '<S223>' : 'foc/FOC_control/speed_pid/Speed_pid/Sum/Sum_PI'
 * '<S224>' : 'foc/FOC_control/speed_pid/Speed_pid/Sum Fdbk/Disabled'
 * '<S225>' : 'foc/FOC_control/speed_pid/Speed_pid/Tracking Mode/Disabled'
 * '<S226>' : 'foc/FOC_control/speed_pid/Speed_pid/Tracking Mode Sum/Passthrough'
 * '<S227>' : 'foc/FOC_control/speed_pid/Speed_pid/Tsamp - Integral/Passthrough'
 * '<S228>' : 'foc/FOC_control/speed_pid/Speed_pid/Tsamp - Ngain/Passthrough'
 * '<S229>' : 'foc/FOC_control/speed_pid/Speed_pid/postSat Signal/Forward_Path'
 * '<S230>' : 'foc/FOC_control/speed_pid/Speed_pid/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_FOC_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

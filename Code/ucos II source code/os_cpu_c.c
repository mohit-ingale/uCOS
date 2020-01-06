

#define  OS_CPU_GLOBALS
#include "includes.h"

#ifndef OS_TASK_SW_HOOK_EN
#define OS_TASK_SW_HOOK_EN 1
#endif

OS_STK *OSTaskStkInit (void (*task)(void *pd), void *pdata, OS_STK *ptos, INT16U opt)
{
    INT8U  *stk;
    INT16U  tmp;

    opt     = opt;                          /* 'opt' is not used, prevent warning                       */
    stk     = (INT8U *)ptos;		    /* AVR return stack ("hardware stack")          		*/
    tmp     = (INT16U)task;

    /* "push" initial register values onto the stack */

    *stk-- = (INT8U)tmp;                   /* Put task start address on top of stack          	        */
    *stk-- = (INT8U)(tmp >> 8);

    *stk-- = (INT8U)0x00;                   /* R0  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R1  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R2  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R3  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R4  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R5  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R6  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R7  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R8  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R9  = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R10 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R11 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R12 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R13 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R14 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R15 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R16 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R17 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R18 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R19 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R20 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R21 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R22 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R23 = 0x00                                               */

    tmp    = (INT16U)pdata;
    *stk-- = (INT8U)tmp;                    /* Simulate call to function with argument                  */
    *stk-- = (INT8U)(tmp >> 8);		    /* R24, R25 contains argument pointer pdata 		*/

    *stk-- = (INT8U)0x00;                   /* R26 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R27 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R28 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R29 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R30 = 0x00                                               */
    *stk-- = (INT8U)0x00;                   /* R31 = 0x00                                               */
#ifdef RAMPZ
    *stk-- = (INT8U)0x00;                   /* RAMPZ = 0x00                                             */
#endif
    *stk-- = (INT8U)0x80;                   /* SREG = Interrupts enabled                                */
    return ((OS_STK *)stk);
}




#if OS_CPU_HOOKS_EN > 0
void OSTaskCreateHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}
#endif



#if OS_CPU_HOOKS_EN > 0
void OSTaskDelHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}
#endif


#if (OS_CPU_HOOKS_EN > 0) && (OS_TASK_SW_HOOK_EN > 0)
void OSTaskSwHook (void)
{
}
#endif


void OSTaskStatHook (void)
{
}


#if (OS_CPU_HOOKS_EN > 0) && (OS_TIME_TICK_HOOK_EN > 0)
void OSTimeTickHook (void)
{
}
#endif


#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void OSInitHookBegin (void)
{
}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void OSInitHookEnd (void)
{
}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION >= 251
void OSTaskIdleHook (void)
{
}
#endif

#if OS_CPU_HOOKS_EN > 0 && OS_VERSION > 203
void OSTCBInitHook (OS_TCB *ptcb)
{
    ptcb = ptcb;                       /* Prevent compiler warning                                     */
}
#endif


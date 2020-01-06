#include <avr/io.h>

#define OS_CPU_A
#include "os_cpu.h"
#define typedef	; 
#include "os_cfg.h"

#ifndef OS_TASK_SW_HOOK_EN
#define OS_TASK_SW_HOOK_EN 1
#endif
	

                .global OSStartHighRdy
                .global OSCtxSw
                .global OSIntCtxSw
                .global	OSTickISR



                .extern	OSIntExit
                .extern	OSIntNesting
                .extern	OSPrioCur
                .extern	OSPrioHighRdy
                .extern	OSRunning
#if OS_TASK_SW_HOOK_EN > 0
                .extern	OSTaskSwHook
#endif
                .extern	OSTCBCur
                .extern	OSTCBHighRdy
                .extern	OSTimeTick


; Push all registers and the status register	
.macro	PUSHRS

.endm

; Pop all registers and the status registers
.macro	POPRS


.endm

.macro	POPSREG

.endm

.macro	PUSHSREG


.endm

.macro	PUSHSREGISR


.endm


                	.text
                	.section	.text
			


OSStartHighRdy: 


OSCtxSw:        

OSIntCtxSw:     


.global	SIG_OVERFLOW0
SIG_OVERFLOW0:
OSTickISR:   



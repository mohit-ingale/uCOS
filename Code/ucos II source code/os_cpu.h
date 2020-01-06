
#define  OS_CRITICAL_METHOD    1


#ifndef OS_CPU_A	/* skip the rest if we're including from the assembler file 						*/

#ifdef  OS_CPU_GLOBALS
#define OS_CPU_EXT
#else
#define OS_CPU_EXT  extern
#endif

/*
**********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
**********************************************************************************************************
*/

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                       /* Unsigned  8 bit quantity                         */
typedef signed   char  INT8S;                       /* Signed    8 bit quantity                         */
typedef unsigned int   INT16U;                      /* Unsigned 16 bit quantity                         */
typedef signed   int   INT16S;                      /* Signed   16 bit quantity                         */
typedef unsigned long  INT32U;                      /* Unsigned 32 bit quantity                         */
typedef signed   long  INT32S;                      /* Signed   32 bit quantity                         */
typedef float          FP32;                        /* Single precision floating point                  */

typedef unsigned char  OS_STK;                      /* Each stack entry is 8-bit wide                   */


#if      OS_CRITICAL_METHOD == 1
#define  OS_ENTER_CRITICAL()    asm volatile ("cli")		/* Disable interrupts						*/
#define  OS_EXIT_CRITICAL()     asm volatile ("sei")        /* Enable  interrupts						*/
#endif

#if      OS_CRITICAL_METHOD == 2
#define  OS_ENTER_CRITICAL()    {	asm volatile (		\
									"in %0,63" "\n\t"	\
									"cli" "\n\t" 		\
									"push %0" "\n\t" 	\
									: /*no outputs*/	\
									: "r" (0) );		\
								 }
								 
#define  OS_EXIT_CRITICAL()     {	asm volatile (		\
									"pop %0"   	"\n\t"	\
									"out 63,%0" "\n\t"	\
									: /*no outputs*/	\
									: "r" (0) );		\
								  }
#endif

/*
**********************************************************************************************************
*                           AVR Miscellaneous
**********************************************************************************************************
*/

#define  OS_STK_GROWTH      1                       /* Stack grows from HIGH to LOW memory on AVR       */

#define  OS_TASK_SW()       OSCtxSw()


#endif //OS_CPU_A

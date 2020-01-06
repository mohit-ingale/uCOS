
#include <avr/io.h>
//#include <avr/signal.h>
#include <avr/interrupt.h>

#include  "os_cpu.h"
#include  "os_cfg.h"
#include  <ucos_ii.h>

#include <avr_isr.h>


#define  COLOR_BLACK     0                       /* VT102 Color Codes                                  */
#define  COLOR_RED       1
#define  COLOR_GREEN     2
#define  COLOR_BROWN     3
#define  COLOR_BLUE      4
#define  COLOR_MAGENTA   5
#define  COLOR_CYAN      6
#define  COLOR_WHITE     7


/* 12 中断发生时,保存进程信息的结构.信赖CPU类型. */

/* The 'pc_psw' struct is machine dependent.  It must contain the information
 * pushed onto the stack by an interrupt, in the same format as the hardware
 * creates and expects.  It is used for storing the interrupt status after a
 * trap or interrupt, as well as for causing interrupts for signals.
 */


#ifdef i8088
/* 中断发生时,CPU硬件自动保存这些信息到堆栈上. */
struct pc_psw {
  int (*pc)();			/* IP.storage for program counter */
  phys_clicks cs;		/* CS.code segment register */
  unsigned psw;			/* PSW.program status word */
};

/* 发送给内核的信息数据结构.This struct is used to build data structure pushed by kernel upon signal. */
struct sig_info {
  int signo;			/* 信号号码.sig number at end of stack */
  struct pc_psw sigpcpsw;
};
#endif

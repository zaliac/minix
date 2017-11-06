/* 12 �жϷ���ʱ,���������Ϣ�Ľṹ.����CPU����. */

/* The 'pc_psw' struct is machine dependent.  It must contain the information
 * pushed onto the stack by an interrupt, in the same format as the hardware
 * creates and expects.  It is used for storing the interrupt status after a
 * trap or interrupt, as well as for causing interrupts for signals.
 */


#ifdef i8088
/* �жϷ���ʱ,CPUӲ���Զ�������Щ��Ϣ����ջ��. */
struct pc_psw {
  int (*pc)();			/* IP.storage for program counter */
  phys_clicks cs;		/* CS.code segment register */
  unsigned psw;			/* PSW.program status word */
};

/* ���͸��ں˵���Ϣ���ݽṹ.This struct is used to build data structure pushed by kernel upon signal. */
struct sig_info {
  int signo;			/* �źź���.sig number at end of stack */
  struct pc_psw sigpcpsw;
};
#endif

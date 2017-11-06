/* 10 内核全局变量. Global variables used in the kernel. */

/* Clocks and timers */
EXTERN real_time realtime;	/* 系统引导以来的时间数. real time clock */
EXTERN int lost_ticks;		/* 时钟中断发生时,丢失的时间数. incremented when clock int can't send mess*/

/* Processes, signals, and messages. */
EXTERN int cur_proc;		/* 当前被调度的进程号. current process */
EXTERN int prev_proc;		/* 前一个进程号. previous process */
EXTERN int sig_procs;		/* 挂起的进程数. number of procs with p_pending != 0 */
EXTERN message int_mess;	/* 一条中断发生时,生成一条消息发送给与之相关的任务. interrupt routines build message here */

/* CPU type. */
EXTERN int olivetti;		/* TRUE for Olivetti-style keyboard */
EXTERN int pc_at;		/*  PC-AT type diskette drives (360K/1.2M) ? */

/* 每项任务在t_stack里设置它自己的栈. The kernel and task stacks. */
EXTERN struct t_stack {
  int stk[TASK_STACK_BYTES/sizeof(int)];
} t_stack[NR_TASKS - 1];	/* task stacks; task = -1 never really runs */

EXTERN char k_stack[K_STACK_BYTES];	/* 中断处理过程中,核心使用一个临时的栈k_stack. The kernel stack. */

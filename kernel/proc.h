/* 11.1 进程描述表结构定义及相关说明.
 * Here is the declaration of the process table.  Three assembly code routines
 * reference fields in it.  They are restart(), save(), and csv().  When 
 * changing 'proc', be sure to change the field offsets built into the code.
 * It contains the process' registers, memory map, accounting, and message
 * send/receive information.
 */

EXTERN struct proc {
  int p_reg[NR_REGS];			/* process' registers */
  int *p_sp;					/* 进程堆栈的指针.stack pointer */
  struct pc_psw p_pcpsw;		/* pc and psw as pushed by interrupt.中断入栈的cs:IP和psw (kernel/type.h) */
  int p_flags;					/* 进程槽状态,空P_SLOT_FREE, 被冻结等待发送消息SENDING, 被冻结等待接收消息RECEIVING, etc. */
  struct mem_map p_map[NR_SEGS];/* 进程的内存块(虚地址,实地址,和空间大小),存储映像.memory map */
  int *p_splimit;				/* lowest legal stack value */
  int p_pid;					/* 进程号.process id passed in from MM 内存系统分配的进程号*/

  real_time user_time;			/* user time in ticks 已经使用的时钟中断次数.*/
  real_time sys_time;			/* sys time in ticks */
  real_time child_utime;		/* cumulative user time of children */
  real_time child_stime;		/* cumulative sys time of children */
  real_time p_alarm;			/* time of next alarm in ticks, or 0 */

  struct proc *p_callerq;		/* 所有向这个进程send消息的进程的队列.head of list of procs wishing to send */
  struct proc *p_sendlink;		/* send进程队列中,下一个进程项.link to next proc wishing to send */
  message *p_messbuf;			/* 指向消息缓存区.pointer to message buffer */
  int p_getfrom;				/* 准备从中接收消息的进程号.from whom does process want to receive? */

  struct proc *p_nextready;		/* 链接到调度队列上.指向下一个就绪进程.pointer to next ready process */
  int p_pending;				/* bit map for pending signals 1-16 */
} proc[NR_TASKS+NR_PROCS];		/* NR_TASKS=8,NR_PROCS=16,总共24个槽位. */

/* Bits for p_flags in proc[].  A process is runnable if p_flags == 0 */
#define P_SLOT_FREE      001	/* set when slot is not in use */
#define NO_MAP           002	/* 在fork之后,子进程设NO_MAP,无法运行.直到分配存储映像.keeps unmapped forked child from running */
#define SENDING          004	/* set when process blocked trying to send */
#define RECEIVING        010	/* set when process blocked trying to recv */

#define proc_addr(n) &proc[NR_TASKS + n]	/* 进程n的槽位地址. */
#define NIL_PROC (struct proc *) 0

EXTERN struct proc *proc_ptr;	/* 指向正在进行的进程.中断或系统调用返回时,可以快速查找到被中断的进程(cs:ip).&proc[cur_proc] */
EXTERN struct proc *bill_ptr;	/* 指向正占用时钟周期的进程.如用户进程p1调用文件系统t1,proc_ptr指向t1,bill_ptr指向p1.ptr to process to bill for clock ticks */
EXTERN struct proc *rdy_head[NQ];	/* 维护调度队列(头,第一个进程).pointers to ready list headers */
EXTERN struct proc *rdy_tail[NQ];	/* 维护调度队列(尾,最后一个进程).pointers to ready list tails */

EXTERN unsigned busy_map;		/* bit map of busy tasks */
EXTERN message *task_mess[NR_TASKS+1];	/* 任务的忙状态队列.ptrs to messages for busy tasks */

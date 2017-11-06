/* 11.1 ����������ṹ���弰���˵��.
 * Here is the declaration of the process table.  Three assembly code routines
 * reference fields in it.  They are restart(), save(), and csv().  When 
 * changing 'proc', be sure to change the field offsets built into the code.
 * It contains the process' registers, memory map, accounting, and message
 * send/receive information.
 */

EXTERN struct proc {
  int p_reg[NR_REGS];			/* process' registers */
  int *p_sp;					/* ���̶�ջ��ָ��.stack pointer */
  struct pc_psw p_pcpsw;		/* pc and psw as pushed by interrupt.�ж���ջ��cs:IP��psw (kernel/type.h) */
  int p_flags;					/* ���̲�״̬,��P_SLOT_FREE, ������ȴ�������ϢSENDING, ������ȴ�������ϢRECEIVING, etc. */
  struct mem_map p_map[NR_SEGS];/* ���̵��ڴ��(���ַ,ʵ��ַ,�Ϳռ��С),�洢ӳ��.memory map */
  int *p_splimit;				/* lowest legal stack value */
  int p_pid;					/* ���̺�.process id passed in from MM �ڴ�ϵͳ����Ľ��̺�*/

  real_time user_time;			/* user time in ticks �Ѿ�ʹ�õ�ʱ���жϴ���.*/
  real_time sys_time;			/* sys time in ticks */
  real_time child_utime;		/* cumulative user time of children */
  real_time child_stime;		/* cumulative sys time of children */
  real_time p_alarm;			/* time of next alarm in ticks, or 0 */

  struct proc *p_callerq;		/* �������������send��Ϣ�Ľ��̵Ķ���.head of list of procs wishing to send */
  struct proc *p_sendlink;		/* send���̶�����,��һ��������.link to next proc wishing to send */
  message *p_messbuf;			/* ָ����Ϣ������.pointer to message buffer */
  int p_getfrom;				/* ׼�����н�����Ϣ�Ľ��̺�.from whom does process want to receive? */

  struct proc *p_nextready;		/* ���ӵ����ȶ�����.ָ����һ����������.pointer to next ready process */
  int p_pending;				/* bit map for pending signals 1-16 */
} proc[NR_TASKS+NR_PROCS];		/* NR_TASKS=8,NR_PROCS=16,�ܹ�24����λ. */

/* Bits for p_flags in proc[].  A process is runnable if p_flags == 0 */
#define P_SLOT_FREE      001	/* set when slot is not in use */
#define NO_MAP           002	/* ��fork֮��,�ӽ�����NO_MAP,�޷�����.ֱ������洢ӳ��.keeps unmapped forked child from running */
#define SENDING          004	/* set when process blocked trying to send */
#define RECEIVING        010	/* set when process blocked trying to recv */

#define proc_addr(n) &proc[NR_TASKS + n]	/* ����n�Ĳ�λ��ַ. */
#define NIL_PROC (struct proc *) 0

EXTERN struct proc *proc_ptr;	/* ָ�����ڽ��еĽ���.�жϻ�ϵͳ���÷���ʱ,���Կ��ٲ��ҵ����жϵĽ���(cs:ip).&proc[cur_proc] */
EXTERN struct proc *bill_ptr;	/* ָ����ռ��ʱ�����ڵĽ���.���û�����p1�����ļ�ϵͳt1,proc_ptrָ��t1,bill_ptrָ��p1.ptr to process to bill for clock ticks */
EXTERN struct proc *rdy_head[NQ];	/* ά�����ȶ���(ͷ,��һ������).pointers to ready list headers */
EXTERN struct proc *rdy_tail[NQ];	/* ά�����ȶ���(β,���һ������).pointers to ready list tails */

EXTERN unsigned busy_map;		/* bit map of busy tasks */
EXTERN message *task_mess[NR_TASKS+1];	/* �����æ״̬����.ptrs to messages for busy tasks */

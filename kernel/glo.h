/* 10 �ں�ȫ�ֱ���. Global variables used in the kernel. */

/* Clocks and timers */
EXTERN real_time realtime;	/* ϵͳ����������ʱ����. real time clock */
EXTERN int lost_ticks;		/* ʱ���жϷ���ʱ,��ʧ��ʱ����. incremented when clock int can't send mess*/

/* Processes, signals, and messages. */
EXTERN int cur_proc;		/* ��ǰ�����ȵĽ��̺�. current process */
EXTERN int prev_proc;		/* ǰһ�����̺�. previous process */
EXTERN int sig_procs;		/* ����Ľ�����. number of procs with p_pending != 0 */
EXTERN message int_mess;	/* һ���жϷ���ʱ,����һ����Ϣ���͸���֮��ص�����. interrupt routines build message here */

/* CPU type. */
EXTERN int olivetti;		/* TRUE for Olivetti-style keyboard */
EXTERN int pc_at;		/*  PC-AT type diskette drives (360K/1.2M) ? */

/* ÿ��������t_stack���������Լ���ջ. The kernel and task stacks. */
EXTERN struct t_stack {
  int stk[TASK_STACK_BYTES/sizeof(int)];
} t_stack[NR_TASKS - 1];	/* task stacks; task = -1 never really runs */

EXTERN char k_stack[K_STACK_BYTES];	/* �жϴ��������,����ʹ��һ����ʱ��ջk_stack. The kernel stack. */

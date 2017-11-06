/* 6 信号的标准名称 */
#define NR_SIGS           16	/* number of signals used */
#define NSIG              16	/* number of signals used */

#define	SIGHUP	           1	/* 挂起 hangup */
#define SIGINT             2	/* 中断 interrupt (DEL) */
#define SIGQUIT            3	/* 退出 quit (ASCII FS) */
#define SIGILL             4	/* 非法指令 illegal instruction (not reset when caught)*/
#define SIGTRAP            5	/* 陷井跟踪 trace trap (not reset when caught) */
#define SIGIOT             6	/* IOT instruction */
#define SIGEMT             7	/* EMT instruction */
#define SIGFPE             8	/* 浮点数异常 floating point exception */
#define SIGKILL            9	/* 杀死kill (cannot be caught or ignored) */
#define SIGBUS            10	/* 总线错误 bus error */
#define SIGSEGV           11	/* segmentation violation */
#define SIGSYS            12	/* 错误的系统调用参数 bad argument to system call */
#define SIGPIPE           13	/* write on a pipe with no one to read it */
#define SIGALRM           14	/* 时钟告警 alarm clock */
#define SIGTERM           15	/* 软件终端信号software termination signal from kill */

#define STACK_FAULT       16	/* used by kernel to signal stack fault */

int	(*signal())();
#define	SIG_DFL	(int (*)())0
#define	SIG_IGN	(int (*)())1

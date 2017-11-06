/* 6 �źŵı�׼���� */
#define NR_SIGS           16	/* number of signals used */
#define NSIG              16	/* number of signals used */

#define	SIGHUP	           1	/* ���� hangup */
#define SIGINT             2	/* �ж� interrupt (DEL) */
#define SIGQUIT            3	/* �˳� quit (ASCII FS) */
#define SIGILL             4	/* �Ƿ�ָ�� illegal instruction (not reset when caught)*/
#define SIGTRAP            5	/* �ݾ����� trace trap (not reset when caught) */
#define SIGIOT             6	/* IOT instruction */
#define SIGEMT             7	/* EMT instruction */
#define SIGFPE             8	/* �������쳣 floating point exception */
#define SIGKILL            9	/* ɱ��kill (cannot be caught or ignored) */
#define SIGBUS            10	/* ���ߴ��� bus error */
#define SIGSEGV           11	/* segmentation violation */
#define SIGSYS            12	/* �����ϵͳ���ò��� bad argument to system call */
#define SIGPIPE           13	/* write on a pipe with no one to read it */
#define SIGALRM           14	/* ʱ�Ӹ澯 alarm clock */
#define SIGTERM           15	/* ����ն��ź�software termination signal from kill */

#define STACK_FAULT       16	/* used by kernel to signal stack fault */

int	(*signal())();
#define	SIG_DFL	(int (*)())0
#define	SIG_IGN	(int (*)())1

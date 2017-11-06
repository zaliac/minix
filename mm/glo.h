/* 2 �洢����ȫ�ֱ��� Global variables. */
EXTERN struct mproc *mp;	/* ָ��ǰ���̵�mproc�ṹ,���ڴ���ϵͳ����.ptr to 'mproc' slot of current process */
EXTERN int dont_reply;		/* �ش���.�����󵽴�ʱ,��Ϊfalse.normally 0; set to 1 to inhibit(��ֹ) reply */
EXTERN int procs_in_use;	/* ��¼��ǰ�Ѵ�����������.how many processes are marked as IN_USE */

/* The parameters of the call are kept here. */
EXTERN message mm_in;		/* ��Ϣ������,���������Ϣ.the incoming message itself is kept here. */
EXTERN message mm_out;		/* ��Ϣ������,���Ӧ����Ϣ.the reply message is built up here. */
EXTERN int who;			/* ��ǰ���̵�����.��ǰ����ָ��.mp=&mproc[who].caller's proc number */
EXTERN int mm_call;		/* ���ϵͳ���ú�.caller's proc number */

/* ��ŷ��ص����ߵĻش���Ϣ.The following variables are used for returning results to the caller. */
EXTERN int err_code;		/* temporary storage for error number */
EXTERN int result2;		/* secondary result */
EXTERN char *res_ptr;		/* result, if pointer */

EXTERN char mm_stack[MM_STACK_BYTES];	/* �洢��������ջ.ջָ����head.s�趨.MM's stack */


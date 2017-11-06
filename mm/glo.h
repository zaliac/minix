/* 2 存储管理全局变量 Global variables. */
EXTERN struct mproc *mp;	/* 指向当前进程的mproc结构,用于处理系统调用.ptr to 'mproc' slot of current process */
EXTERN int dont_reply;		/* 回答标记.新请求到达时,设为false.normally 0; set to 1 to inhibit(禁止) reply */
EXTERN int procs_in_use;	/* 记录当前已创建进程总数.how many processes are marked as IN_USE */

/* The parameters of the call are kept here. */
EXTERN message mm_in;		/* 消息缓冲区,存放请求消息.the incoming message itself is kept here. */
EXTERN message mm_out;		/* 消息缓冲区,存放应答消息.the reply message is built up here. */
EXTERN int who;			/* 当前进程的索引.当前进程指针.mp=&mproc[who].caller's proc number */
EXTERN int mm_call;		/* 存放系统调用号.caller's proc number */

/* 存放返回调用者的回答消息.The following variables are used for returning results to the caller. */
EXTERN int err_code;		/* temporary storage for error number */
EXTERN int result2;		/* secondary result */
EXTERN char *res_ptr;		/* result, if pointer */

EXTERN char mm_stack[MM_STACK_BYTES];	/* 存储管理程序的栈.栈指针由head.s设定.MM's stack */


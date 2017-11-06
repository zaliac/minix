/* 1 ����洢����ʹ�õĳ���.Constants used by the Memory Manager. */

#define ZEROBUF_SIZE	1024	/* buffer size for erasing memory */

/* �洢������ĳߴ�,Ҫ��Ƶ��㹻��.Size of MM's stack depends mostly on do_exec(). */
#if ZEROBUF_SIZE > MAX_PATH		/*MAX_PATH=128 max length of path names.*/
#define MM_STACK_BYTES	MAX_ISTACK_BYTES + ZEROBUF_SIZE + 384	/* 384=48*8 */
#else
#define MM_STACK_BYTES	MAX_ISTACK_BYTES + MAX_PATH + 384
#endif

#define NO_MEM (phys_clicks)0	/* returned by alloc_mem() with mem is up */

#ifdef i8088
#define PAGE_SIZE	  16	/* how many bytes in a page ?*/
#define MAX_PAGES       4096	/* ���ַ�ռ����ҳ��.how many pages in the virtual addr space */
#define HDR_SIZE	  32	/* # ��ִ���ļ�ͷ��С.bytes in the exec file header */
#endif

#define printf        printk

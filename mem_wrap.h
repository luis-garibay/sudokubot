/*mem_wrap.h*/

#ifndef __MEM_WRAP__
#define __MEM_WRAP__

//
// wrapper funtions for malloc and free
//

void *wMalloc(unsigned int size);
void  wFree(void *ptr);
void  wMemStats();

#endif

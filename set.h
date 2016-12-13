/*set.h*/

#ifndef __SET__
#define __SET__

//
// Set:
//

typedef int SetElementType;
typedef struct Set {
  SetElementType  *Elements;  // array of elements in Set:
  int  NumElements;  // # of elements currently in Set
  int  Capacity;     // max # of elements that can fit in Set
} Set;

Set *CreateSet(int N);
void DeleteSet(Set *S);
int  isEmptySet(Set *S);
int  AddToSet(Set *S, SetElementType e);
int  RemoveFromSet(Set *S, SetElementType e);
int  isElementInSet(Set *S, SetElementType e);

#endif

#include <stdio.h>

typedef struct arrayUtil{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (match)(void*,void*);

int areEqual(ArrayUtil array1,ArrayUtil array2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil array1,int length);
int findIndex(ArrayUtil array,void* ele);
void dispose(ArrayUtil array);
void* findFirst(ArrayUtil util, match* fun, void* hint);
void* findLast(ArrayUtil util, match* fun, void* hint);


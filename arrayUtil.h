#include <stdio.h>

typedef struct arrayUtil{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;


int areEqual(ArrayUtil array1,ArrayUtil array2);

#include <stdio.h>

typedef struct arrayUtil{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;


int areEqual(ArrayUtil array1,ArrayUtil array2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil array1,int length);


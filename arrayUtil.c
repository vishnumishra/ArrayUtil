#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

	
int areEqual(ArrayUtil array1,ArrayUtil array2){
	int i;
	char* base1 = array1.base;
	char* base2 = array2.base;
	if( (array1.length != array2.length) || (array1.typeSize != array2.typeSize) ){
		return 0;
	};
	for(i=0;i<(array1.length)*array1.typeSize;i++){
		if(base1[i]!=base2[i]){
			return 0;
		}
	};
	return 1;
};

ArrayUtil create(int typeSize, int length){
	ArrayUtil util;
	util.base =calloc(length,typeSize);
	util.length = length;
	util.typeSize = typeSize;
	return util;
}

ArrayUtil resize(ArrayUtil array,int length){
	int i;
	void *base;

	length=length<=array.length?length:array.length;
	base = calloc(length,array.typeSize);
	memcpy(base,array.base,array.length*array.typeSize);
	array.base=base;
	return array;
};

int findIndex(ArrayUtil array,void* ele){
	int i;
	char* base = array.base; 
	for(i=0;i<array.length*array.typeSize;i++){
		if( base[i] == (char)ele )
			return i/(array.typeSize);
	}
	return -1;
};

void dispose(ArrayUtil array){
	array.length =0;
	array.typeSize=0;
	array.base =0;
	free(array.base);
};

void* findFirst(ArrayUtil array, match* fun, void* hint){
	int i,result=0;
	int* base = array.base;
	for(i=0;i<array.length;i++){
		result = fun((void*)base[i],hint);
		if(result == 1)
			return &base[i]; 
	};
	return NULL;
};

void* findLast(ArrayUtil array, match* fun, void* hint){
	int i,result=0;
	int* base = array.base;
	for(i=array.length;i>0;i--){
		result = fun((void*)base[i],hint);
		if(result == 1)
			return &base[i]; 
	};
	return NULL;
};


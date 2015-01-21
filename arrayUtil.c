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
	// util = {(int[])calloc(length,typeSize),typeSize,length};
	return util;
}

ArrayUtil resize(ArrayUtil array,int length){
	int i;
	ArrayUtil newArray;
	newArray.base = calloc(length,array.typeSize);
	
	for(i=0;i<array.length;i++){
		((char *)newArray.base)[i] =((char *)array.base)[i];
	}
	return newArray;
};

int findIndex(ArrayUtil array,int* ele){
	int i;
	int* base = array.base; 
	
	for(i=0;i<array.length;i++){
		if( base[i] == * ele )
			return i;
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
		if(result == 1){
			return &base[i]; 
		}
	};
	return NULL;
};

void* findLast(ArrayUtil array, match* fun, void* hint){
	int i,result=0;
	int* base = array.base;

	for(i=array.length;i>0;i--){
		result = fun((void*)base[i],hint);
		if(result == 1){
			return &base[i]; 
		}
	};
	return NULL;
};

#include <stdlib.h>
#include <string.h>
#include "arrayUtil.h"

	
int areEqual(ArrayUtil array1,ArrayUtil array2){
	int i;
	int* base1 = array1.base;
	int* base2 = array2.base;
	int len1 = array1.length,
	len2 = array2.length,
	tSize1 = array1.typeSize,
	tSize2 = array2.typeSize;


	int totalLength = sizeof(array1.typeSize)*(array1.length);

	if( (len1 != len2) || (tSize1!=tSize2) ){
		return 0;
	};
	for(i=0;i<totalLength;i++){

		if(base1[i]!=base2[i]){
			return 0;
		}
	};
	return 1;
};

ArrayUtil create(int typeSize, int length){
	int i;
	void* newArray;
	ArrayUtil arr1;

	newArray = calloc(length,typeSize);

	arr1.base = newArray;
	arr1.length = length;
	arr1.typeSize = typeSize;
	return arr1;
}

ArrayUtil resize(ArrayUtil array,int length){
	int i;
	ArrayUtil newArray;
	newArray.base = calloc(length,array.typeSize);
	
	for(i=0;i<array.length;i++){
		((int *)newArray.base)[i] =((int *)array.base)[i];
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

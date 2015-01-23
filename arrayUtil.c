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
	void *base;
	int cpyLength = (length <= array.length?length:array.length)*array.typeSize;
	int newLength = length;
	length=length>=array.length?length:array.length;
	base = calloc(length,array.typeSize);
	memcpy(base,array.base,cpyLength);
	array.base=base;
	array.length = newLength;
	return array;
};

int findIndex(ArrayUtil array,void* ele){
	int i;
	char* base = array.base; 
	for(i=0;i<array.length*array.typeSize;i++){
		if( ((char*)array.base)[i] == *((char*)ele) )
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
	int i,result;
	char* base = (char*)array.base;
	for(i=0;i<array.length;i++){
		result = fun(hint,(void*)(&base[i*array.typeSize]));
		if(result){
			return (void*)&(base[i*array.typeSize]); 
		}
	};
	return NULL;
};

void* findLast(ArrayUtil array, match* fun, void* hint){
	int i,result;
	char* base = (char*)array.base;
	for(i=array.length-1;i>=0;i--){
		result = fun(hint,(void*)(&base[i*array.typeSize]));
		if(result)
			return (void*)&base[i*array.typeSize]; 
	};

	return NULL;
};

int count(ArrayUtil array, match* fun, void* hint){
	int i,result=0,count=0;
	char* base = array.base;
	for(i=0;i<array.length;i++){
		result = fun(hint,(void*)(&base[i*array.typeSize]));
		if(result) count++;
	};
	return count;
};

int filter(ArrayUtil util, match* fun, void* hint,void** destination,int maxitem){
	int i,count=0;
	void *item,*result = calloc(maxitem,util.length);
	for(i=0;(i<util.length) && (count< maxitem) ;i++){
		item = util.base+(util.typeSize*i);
		if(fun(hint,item)){
			printf("item is %d\n",*(int*)item);
			// result+count*util.typeSize) = item; 
			destination[count*util.typeSize] = item;
			count++;
		}
	}
	destination = result;
	return count;
};







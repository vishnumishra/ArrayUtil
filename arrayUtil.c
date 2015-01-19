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

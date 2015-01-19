#include <stdio.h>
#include <stdlib.h>
#include "../expr_assert.h"
#include "arrayUtil.h"

void test_are_equal_tell_the_two_array_are_equal_or_not(){
int array1[]={1,2,3,4,5};
int array2[]={1,2,3,4,5};
int array3[]={1,2,5,4,5};

ArrayUtil arr1;
ArrayUtil arr2;
ArrayUtil arr3;

arr1.base =&array1;
arr1.typeSize = sizeof(int);
arr1.length = 5;

arr3.base =&array3;
arr3.typeSize = sizeof(int);
arr3.length = 5;

arr2.base =&array2;
arr2.typeSize = sizeof(int);
arr2.length = 5;

assertEqual(areEqual(arr1, arr2), 0);
assertEqual(areEqual(arr1, arr1), 1);

};


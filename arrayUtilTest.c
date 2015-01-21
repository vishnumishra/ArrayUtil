#include <stdio.h>
#include <stdlib.h>
#include "../expr_assert.h"
#include "arrayUtil.h"

ArrayUtil util1,util2;

void tearDown(){
	dispose(util1);
	dispose(util2);
}


void test_areEqual_return_1_if_two_array_are_equal(){
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,3,4,5};

	ArrayUtil util1 = {array1,sizeof(int),5};
	ArrayUtil util2 = {array2,sizeof(int),5};
	assertEqual(areEqual(util1, util2), 1);
	tearDown();
};

void test_areEqual_return_0_if_two_array_are_not_equal(){
	int array1[]={1,2,3,4,5};
	int array2[]={1,2,5,4,5};

	ArrayUtil util1 = {array1,sizeof(int),5};
	ArrayUtil util2 = {array2,sizeof(int),5};
	assertEqual(areEqual(util1, util2), 0);
	tearDown();
};

void test_creat_creat_Array_util_with_value_set_zero(){
	ArrayUtil arr1;
	int* base;
	arr1 = create(4,5);
	base = arr1.base;
	assertEqual(base[0], 0);
	assertEqual(base[4], 0);
	free(base);
};

void test_ArrayUtil_resize_return_Array_with_expected_length(){
	int array[]={1,2,3,4,5,6};
	ArrayUtil util = {array,sizeof(int),6},arr;
	arr = resize(util,4);
	assertEqual(((int *)arr.base)[3], 4);
	free(arr.base);
};

void test_resize_set_eleement_of_the_array_zero_if_size_of_array_is_grater_(){
	int src[]={1,2,3};
	ArrayUtil util = {src,sizeof(int),3};
	ArrayUtil array;
	int* base;
	array = resize(util,5);
	base = (int *)(array.base);
	assertEqual(base[3], 0);
	tearDown();
};

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3};
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);

	free(array.base);
};

void test_findIndex_will_return_the_array_index_of_the_element(){
	int array[]={1,2,3,4,5};
	int x=4;
	ArrayUtil arr = {array,sizeof(int),5};
	assertEqual(findIndex(arr,(void*)x),3);
}

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
		int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr={array,sizeof(int),5};
	assertEqual(findIndex(arr,(void*)x),-1);
}

void test_dispose_free_the_memory_allocated_for_the_array(){
	int* array;
	ArrayUtil arr;

	array = malloc(sizeof(int)*5);
	array[0] = 1;
	array[1] = 34;
	array[2] = 5;
	array[3] = -1;
	array[4] = 43;
	dispose(arr);
}

int isDivisible(void* item, void* hint){
	int* diviser =  hint;
	return (( (int)item % *diviser)==0)?1:0;
}

void test_findFirst_return_5_when_we_give_isDivisible_by_5(){
	int x =5;
	void* result;
	ArrayUtil array = {(int[]){1,2,5,23,45},sizeof(int),5};
	result  = findFirst(array, &isDivisible,&x );
	assertEqual(*(int*)result , 5);
}

void test_findLast_return_5_when_we_give_isDivisible_by_5(){
	int x =5;
	void* result;
	ArrayUtil array = {(int[]){1,2,5,23,45},sizeof(int),5};
	result  = findLast(array, &isDivisible,&x );
	assertEqual(*(int*)result , 45);
}


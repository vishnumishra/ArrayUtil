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

void test_ArrayUtil_resize_return_Array_with_aspected_length(){
	int array1[]={1,2,3,4,5,6};
	ArrayUtil arr1,array;
	int* base;

	arr1.base =array1;
	arr1.typeSize = sizeof(int);
	arr1.length = 5;

	array = resize(arr1,4);
	base = array.base;

	assertEqual(((int *)arr1.base)[3], 4);
	free(base);
};

void test_ArrayUtil_resize_set_eleement_of_the_array_zero_if_size_of_array_is_grater_(){
	int src[]={1,2,3};
	
	ArrayUtil arr,array;
	int* base;

	arr.base =src;
	arr.typeSize = sizeof(int);
	arr.length = 3;

	array = resize(arr,5);
	base = array.base;
	assertEqual(((int *)array.base)[4], 0);
	free(base);
};

void test_ArrayUtil_resize_set_eleement_of_the_array_zero_if_size_of_array_is_grater_then_src_array(){
	int src[]={5,3,5,2};
	
	ArrayUtil arr,array;
	int* base;

	arr.base =src;
	arr.typeSize = sizeof(int);
	arr.length = 4;

	array = resize(arr,15);
	base = array.base;
	assertEqual(((int *)array.base)[14], 0);
	free(base);
};

void test_findIndex_will_return_the_array_index_of_the_element(){
	int array[]={1,2,3,4,5};
	int x=4;
	ArrayUtil arr;

	arr.base =&array;
	arr.typeSize = sizeof(int);
	arr.length = 5;

	assertEqual(findIndex(arr,&x),3);

}

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
	int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr;

	arr.base =&array;
	arr.typeSize = sizeof(int);
	arr.length = 5;

	assertEqual(findIndex(arr,&x),-1);
}

void test_dispose_free_the_memory_allocated_for_the_array(){
	// int array[] = {1,2,3,4,5};
	int* array;
	ArrayUtil arr;

	array = malloc(sizeof(int)*5);
	array[0] = 1;
	array[1] = 34;
	array[2] = 5;
	array[3] = -1;
	array[4] = 43;

	arr.base =&array;
	arr.typeSize = sizeof(int);
	arr.length = 5;

	dispose(arr);
	free(array);
}

int isDivisible(void* item, void* hint){
	int*  num= item;

	int* diviser =  hint;
	return (( (int)item % *diviser)==0)?1:0;
}

void test_findFirst_return_5_when_we_give_isDivisible_by_5(){

	ArrayUtil array;
	int x =5;
	int src[]={1,2,5,23,45};
	void* result;
	int* base;
	array = create(4, 5);
	array.base=&src;

	result  = findFirst(array, &isDivisible,&x );
	assertEqual(*(int*)result , 5);
}

void test_findLast_return_5_when_we_give_isDivisible_by_5(){

	ArrayUtil array;
	int x =5;
	int src[]={1,2,5,23,45};
	void* result;
	int* base;
	array = create(4, 5);
	array.base=&src;

	result  = findLast(array, &isDivisible,&x );
	assertEqual(*(int*)result , 45);
}

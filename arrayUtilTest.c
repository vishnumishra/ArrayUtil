#include <stdio.h>
#define STRING_SIZE sizeof(char*)
#include <stdlib.h>
#include "expr_assert.h"
#include "arrayUtil.h"
ArrayUtil intUtil1,intUtil2,floatUtil1,floatUtil2,charUtil,strUtil,util,expectedUtil,util1,util2;


void setUp(){
	intUtil1=(ArrayUtil){(int[]){1,2,5,23,45},sizeof(int),5};
	intUtil2=(ArrayUtil){(int[]){1,15,5,31,45},sizeof(int),5};

	floatUtil1 = (ArrayUtil){(float[]){1.5,2.5,3.25,4.75,5.0},sizeof(float),5};
	floatUtil2 = (ArrayUtil){(float[]){1.5,2.5,3.75,4.0,5.0},sizeof(float),5};

	charUtil  = (ArrayUtil){(char[]){'v','i','s','h','n','u'},sizeof(char),6};
	strUtil = (ArrayUtil){(char*[]){"hello","how","are","you"},sizeof(char*),4};
}

void tearDown(){
	dispose(intUtil1);
	dispose(intUtil2);
	dispose(floatUtil1);
	dispose(floatUtil2);
}


void test_areEqual_return_1_when_we_Pass_same_array(){
	setUp();
	assertEqual(areEqual(intUtil1, intUtil1), 1);
	tearDown();
};
void test_areEqual_return_1_if_two_array_are_equal(){
	ArrayUtil newUtil=(ArrayUtil){(int[]){1,2,5,23,45},sizeof(int),5};
	setUp();
	assertEqual(areEqual(intUtil1, newUtil), 1);
	tearDown();
};

void test_areEqual_return_1_if_when_we_pass_same_float_array(){
	setUp();
	assertEqual(areEqual(floatUtil1, floatUtil1), 1);
	tearDown();
};

void test_areEqual_return_1_for_array_of_string_if_everything_is_same(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_for_array_of_string_if_lenghts_are_different(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	STRING array2[]={"abc","abc","abc","abc","abc"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_when_length_and_typesize_are_same_and_each_ele_is_empty_string(){
	STRING array1[]={"","","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 1);
}

void test_areEqual_return_0_when_typesize_and_length_are_same_but_first_has_less_element(){
	STRING array1[]={"","","",""};
	STRING array2[]={"","","","",""};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_typesize_is_same_but_second_has_less_element_and_less_length(){
	STRING array1[]={"ank","aks","ank","aks","ank"};
	STRING array2[]={"ank","aks","ank","aks"};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,STRING_SIZE,4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_0_when_1_typesize_is_STRING_SIZE_and_2_is_INT_SIZE(){
	STRING array1[]={"abc","abc","abc","abc","abc"};
	int array2[]={1,2,3,4,5};
	ArrayUtil u1={array1,STRING_SIZE,5};
	ArrayUtil u2={array2,sizeof(int),4};
	assertEqual(areEqual(u1,u2), 0);
}

void test_areEqual_return_1_if_two_array_of_float_are_equal(){
	ArrayUtil newUtil=(ArrayUtil){(float[]){1.5,2.5,3.25,4.75,5.0},sizeof(float),5};
	setUp();
	assertEqual(areEqual(floatUtil1, newUtil), 1);
	tearDown();
};

void test_areEqual_return_1_if_two_array_of_char_are_equal(){
	ArrayUtil newUtil=(ArrayUtil){(char[]){'v','i','s','h','n','u'},sizeof(char),6};
	setUp();
	assertEqual(areEqual(charUtil, charUtil), 1);
	tearDown();
};

void test_areEqual_return_1_if_two_array_of_string_are_equal(){
	ArrayUtil newUtil = {(char[]){"vishnu"},sizeof(char*),6};
	char* array1="vishnu";
	ArrayUtil intUtil1 = {array1,sizeof(char*),6};
	assertEqual(areEqual(intUtil1, newUtil), 1);
};

void test_areEqual_return_0_if_two_array_of_string_are_equal(){
	char* array1="vishnus";
	char* array2="vishnu";

	ArrayUtil intUtil1 = {array1,sizeof(char*),5};
	ArrayUtil intUtil2 = {array2,sizeof(char*),5};
	assertEqual(areEqual(intUtil1, intUtil2), 0);
};
void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
    int array1[] = {1,2,3,4};
    char array2[] = {'m','a','h','e'};
    ArrayUtil util1 = {array1,sizeof(int),4};
    ArrayUtil util2 = {array2,sizeof(char),4};
    assertEqual(areEqual(util1, util2), 0);
}
void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_string(){
	String a [] = {"hello"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assert(areEqual(array1,array2));
};
void test_ArrayUtil_a_and_ArrayUtil_b_are_will_not_be_equal_String(){
	String a [] = {"hallo"};
	String b [] = {"hello"};
	ArrayUtil array1 = {a, sizeof(String), 1};
	ArrayUtil array2 = {b, sizeof(String), 1};

	assertEqual(areEqual(array1,array2),0);
};
void test_array_util_areEqual_returns_0_if_both_array_are_not_equal_in_length_and_elements(){
	int a[]={0,3,8,5,2,3,4,5}, b[]={1,5,2,3,7};
	ArrayUtil a_array = {a,sizeof(int),8};
	ArrayUtil b_array = {b,sizeof(int),5};
	assertEqual(areEqual(a_array, b_array),0);
}
void test_create_allocates_space_for_DOUBLE_array_and_assigns_zero_to_all_bytes(){
	double doubleArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){doubleArray,sizeof(double),4};
	util = create(sizeof(double),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}

void test_ArrayUtil_a_and_ArrayUtil_b_are_will_be_equal_by_each_element_typeof_double(){
	double a [] = {2.34};
	double b [] = {2.34};
	ArrayUtil array1 = {a, sizeof(double), 1};
	ArrayUtil array2 = {b, sizeof(double), 1};

	assert(areEqual(array1,array2));
};
void test_create_allocates_space_for_INT_array_and_assigns_zero_to_all_bytes(){
	int intArray[] = {0,0,0,0};
	expectedUtil = (ArrayUtil){intArray,sizeof(int),4};
	util = create(sizeof(int),4);
	assertEqual(areEqual(expectedUtil,util),1);
	dispose(util);
}
void test_for_the_ArrayUtil_for_charecter_and_int_are_not_equal(){
    char first_array[]={'c','d','e','f'};
    int second_array[]={2,5,8,4};
    ArrayUtil array1 = {first_array,sizeof(char),4};
    ArrayUtil array2 = {second_array,sizeof(int),4};
	assertEqual(areEqual(array1, array2),0);
};
void test_areEqual_returns_0_when_length_is_equal_but_typeSize_is_not_equal(){
	int array1[]={1,2,3,4,5};
	char array2[]={'a','b','c','d','\0'};
	ArrayUtil u1={array1,INT_SIZE,5};
	ArrayUtil u2={array2,CHAR_SIZE,5};
	assertEqual(areEqual(u1,u2), 0);
}

void test_creat_creat_Array_util_with_value_set_zero(){
	ArrayUtil arr1;
	int* base;
	arr1 = create(4,5);
	base = arr1.base;
	assertEqual(base[0], 0);
	assertEqual(base[4], 0);
	free(base);
};

void test_create_returns_same_array_if_array_lengths_are_same_and_values_are_same() {
	ArrayUtil a,b;
	int expected = 1,actual;
	a = create(sizeof(int),2);
	b = create(sizeof(int),2);
	assert(areEqual(a,b) == 1);
}
void test_that_function_creates_new_array_or_not(){
	ArrayUtil array = create(sizeof(int),3);
	int *createArray  = (int*)array.base;
	assertEqual(createArray[0], 0);
	assertEqual(createArray[2], 0);
	assertEqual(array.length, 3);
	assertEqual(array.typeSize, 4);
}
void test_create_should_set_the_length_and_typeSize_fields_of_array_to_the_values_passed_to_create_function(){
	ArrayUtil a = create(1,3);
	assert(a.length == 3);
	assert(a.typeSize == 1);
	dispose(a);
}
void test_create_Structures_with_all_fields_NULL(){
    student temp = {0,0.0};
    student Student[1] = {temp};
    ArrayUtil expected = {Student,sizeof(student),1};
   util1 = create(sizeof(student),1);    
    assert(areEqual(expected,util1));
};

void test_Create_creates_new_array_of_float_containing_all_elements_0 (){
	ArrayUtil expectedUtil = {(float[]){0,0},FLOAT_SIZE,2};
ArrayUtil newUtil = create(FLOAT_SIZE, 2);
	assertEqual(areEqual(expectedUtil,newUtil ), 1);
	dispose(newUtil);
}
void test_Create_creates_new_charArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(char[]){0,0,0},CHAR_SIZE,3};
ArrayUtil newUtil =create(CHAR_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
dispose(newUtil);
}
void test_Create_creates_new_doubleArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(double[]){0,0},DOUBLE_SIZE,2};
ArrayUtil newUtil =create(DOUBLE_SIZE, 3);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
dispose(newUtil);
}
void test_Create_creates_new_intArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil expectedUtil = {(int[]){0,0,0},INT_SIZE,3};
ArrayUtil newUtil =create(INT_SIZE, 2);
	assertEqual(areEqual(expectedUtil, newUtil), 0);
dispose(newUtil);
}

void test_Create_creates_new_floatArray_containing_all_elements_0_and_gives_0_for_different_lengths (){
	ArrayUtil util = {(float[]){0,0},FLOAT_SIZE,2};
ArrayUtil newUtil =create(FLOAT_SIZE, 3);
	assertEqual(areEqual(util, newUtil), 0);
dispose(newUtil);
}

void test_ArrayUtil_resize_return_Array_with_expected_length(){
	int i,array[]={1,2,3,4,5,6};
	ArrayUtil util = {array,sizeof(int),6},arr;
	arr = resize(util,4);
	assertEqual(((int *)arr.base)[3], 4);
	free(arr.base);
};

void test_ArrayUtil_resize_return_Array_wth_expected_length(){
	char array[]={'b','a','k','r','i'},i;
	ArrayUtil util = {array,sizeof(char),5},arr;
	arr = resize(util,4);
	assertEqual(((char *)arr.base)[2], 'k');
	free(arr.base);
};

void test_resize_should_contain_the_initial_array_element(){
	int src[]={5,3},i;
	ArrayUtil util={src,sizeof(int),4},array;
	int* base;
	array = resize(util,15);
	base = (int *)(array.base);
	assertEqual(base[0], 5);
	assertEqual(base[1], 3);
	assertEqual(base[14], 0);

	free(array.base);
};

void test_resize_add_0_to_the_new_places_created_in_integer_array(){
	int array[] = {1,2,3}, arr[] = {1,2,3,0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_INT, 3};
	ArrayUtil expected = {arr, SIZEOF_INT ,5};
	int *base,i;
	array2 =  resize(util1,5);
	base = array2.base;

	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_float_array(){
	float array[] = {1.1,2.2,3.2}, arr[] = {1.1,2.2,3.2,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_FLOAT, 3};
	ArrayUtil expected = {arr, SIZEOF_FLOAT ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_char_array(){
	char *array= "abc";
	char arr[] = {'a','b','c',0,0};
	ArrayUtil array2, util1 = {array, SIZEOF_CHAR, 3};
	ArrayUtil expected = {arr, SIZEOF_CHAR ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_resize_add_0_to_the_new_places_created_in_double_array(){
	double array[] = {1,2,3}, arr[] = {1,2,3,0.0,0.0};
	ArrayUtil array2, util1 = {array, SIZEOF_DOUBLE, 3};
	ArrayUtil expected = {arr, SIZEOF_DOUBLE ,5};
	array2 =  resize(util1,5);
	assert(areEqual(array2 , expected));
}
void test_when_an_array_is_resized_into_smaller_size_the_array_is_trimmed(){
	ArrayUtil util = create( sizeof(char) , 3);
	ArrayUtil resizedUtil = resize(util, 2);
	char array[]={0,0};
	ArrayUtil expected = { (void *)array, sizeof(char), 2};

	assert(areEqual(expected, resizedUtil));
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
    String array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
    ArrayUtil util1 = {array1,sizeof(char *),2};
    ArrayUtil util2 = {array2,sizeof(char *),5};
    assertEqual(areEqual(resize(util1, 5), util2), 1);    
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
    String array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
    ArrayUtil util1 = {array1,sizeof(char *),3};
    ArrayUtil util2 = {array2,sizeof(char *),2};
    assertEqual(areEqual(resize(util1, 2), util2), 1);    
}
void test_resize_should_grow_length_of_array_and_set_them_to_zero_when_new_size_is_more(){
	ArrayUtil a = create(4,2);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	for (i = 0; i < 20; ++i)
	{
		assert(((char*)a.base)[i] == 0);
	}
	dispose(a);
}
void test_resize_should_not_change_length_of_array_when_new_size_is_same_as_old_size(){
	ArrayUtil a = create(1,5);
	int i;
	a = resize(a,5);
	assert(a.length == 5);
	dispose(a);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o'},sizeof(char),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(char []){'a','e','i','o',0,0},sizeof(char),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_CHAR_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(char []){'a','e','i','o','u'},sizeof(char),5};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(char []){'a','e'},sizeof(char),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89,0,0},sizeof(double),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_DOUBLE_array_within_structure_with_new_allocated_space_less_than_previous(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(double []){1.0,2.11111,3.123,4.89},sizeof(double),4};
	resizedArray = resize(util,2);
	expectedUtil = (ArrayUtil){(double []){1.0,2.11111},sizeof(double),2};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_returns_FLOAT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89},sizeof(float),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(float []){1.0,2.11111,3.123,4.89,0,0},sizeof(float),6};
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}

void test_resize_returns_INT_array_within_structure_with_new_allocated_space(){
	ArrayUtil resizedArray;
	util = (ArrayUtil){(int []){1,2,3,4},sizeof(int),4};
	resizedArray = resize(util,6);
	expectedUtil = (ArrayUtil){(int []){1,2,3,4,0,0},sizeof(int),6}; 
	assertEqual(areEqual(expectedUtil, resizedArray),1);
	dispose(resizedArray);
}
void test_resize_an_existing_array_to_resize_decrease_its_length(){
    int *resArray;
    ArrayUtil array,resizeArray;
    array = create(sizeof(int),5);
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    ((int*)array.base)[3]=550;
    ((int*)array.base)[4]=40;
    resizeArray=resize(array,4);
    resArray = resizeArray.base;
    assertEqual(resArray[2],550);
    assertEqual(areEqual(resizeArray,array),0);
};


void test_resize_an_existing_array_to_resize_increase_its_length(){
    ArrayUtil array = create(sizeof(int),3),resultArray;
    ((int*)array.base)[0]=90;
    ((int*)array.base)[1]=40;
    ((int*)array.base)[2]=550;
    resultArray = resize(array,5);
    assertEqual(((int *)resultArray.base)[0],90);
    assertEqual(((int *)resultArray.base)[1],40);
    assertEqual(((int *)resultArray.base)[2],550);
    assertEqual(((int *)resultArray.base)[3],0);
    assertEqual(((int *)resultArray.base)[4],0);
};

void test_findIndex_returns_1_if_the_search_char_is_found_on_1st_location (){
	int x = 'a';
	char array[] = "car";
	ArrayUtil util = create(CHAR_SIZE,3);
	util.base = (void*)array;
	assertEqual(findIndex(util,&x),1);
}
void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
    String array1[] = {"Mahesh","Kumar","Kolla"};
    String element = "Kumar";
    ArrayUtil util1 = {array1,sizeof(String),3};
    assertEqual(findIndex(util1,&element), 1);
}
void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
    char array1[] = {'m','a','h','e','s','h'};
    char element = 's';
    ArrayUtil util1 = {array1,sizeof(char),6};
    assertEqual(findIndex(util1,&element), 4);
}

void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
    float array1[] = {1.1,2.2,3.3,4.5};
    float element = 4.5;
    ArrayUtil util1 = {array1,sizeof(float),4};
    assertEqual(findIndex(util1,&element), 3);
}
void test_findIndex_retruns_the_index_of_an_element_in_an_string_array(){
    char array[]= {"heloo"};
    char element ='o';
    ArrayUtil util = {array,sizeof(char),4};
    assertEqual(findIndex(util,&element),3);
};
void test_findIndex_returns_4_for_float_array_if_search_element_is_at_4th_location (){
	float element = 7.25;
	ArrayUtil util = {(float[]){4.2,2.9,1.4,3.1,7.25,8.7},FLOAT_SIZE,6};
	assertEqual(findIndex(util, &element),4);
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
    int array1[] = {1,2,3,4,5};
    int element = 2;
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(findIndex(util1,&element), 1);
}

void test_findIndex_will_return_the_array_index_of_the_element(){
	int array[]={1,2,3,4,5};
	int x=4;
	ArrayUtil arr = {array,sizeof(int),5};
	assertEqual(findIndex(arr,&x),3);
}

void test_findIndex_will_return_the_minus_1_if_array_element_is_not_present(){
	int array[]={1,2,3,4,5};
	int x=7;
	ArrayUtil arr={array,sizeof(int),5};
	assertEqual(findIndex(arr,&x),-1);
}

int isDivisible( void* hint,void* item){
	int* diviser =  (int*)hint;
	return (( (item !=0) && (*(int*)item % *diviser)==0));
}

void test_findFirst_return_First_Index_which_match_the_criteria(){
	int x =5;
	void* result;
	setUp();
	result  = findFirst(intUtil2, &isDivisible,&x );
	assertEqual(*(int*)result, 15);
	tearDown();
}

void test_findFirst_return_First_Index_which_match_the_criteria_or_0(){
	int x =7;
	void* result;
	setUp();
	result  = findFirst(intUtil1, &isDivisible,&x );
	assert(!(int*)result);
	tearDown();
}
int isCapital(void *hint, void *item) {
    return((*(char *)item >=65) && (*(char *)item <= 91));
}

int isEven(void *hint, void *item) {
    return(*(int *)item%2==0);
}

int isGreaterThan5(void *hint, void *item) {
    return(*(float *)item > 5);
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
    char array1[] = {'k','M','k'};
    ArrayUtil util1 = {array1,sizeof(char),3};
    assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
    int array1[] = {1,2,3,4,5};
    ArrayUtil util1 = {array1,sizeof(int),5};
    assertEqual(*(int *)(findFirst(util1,&isEven, 0)), 2);
}

void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
    float array1[] = {1.1,6.6,5.5,8.8,2.2};
    ArrayUtil util1 ={array1, sizeof(float),5};
    assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), (float)6.6);
}

int isGreaterThanHint (void* hint, void* element) {
	// printf("%d\t%d\n",*((int*)element),*((int*)hint)) ;
	return (*((float*)element) > *((float*)hint));
}


void test_findFirst_gives_occurence_of_first_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	match *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){3.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findFirst(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}
void test_findLast_return_lastIndex_which_match_the_criteria_or_0(){
	int x =13;
	void* result;
	setUp();
	result  = findLast(intUtil1, &isDivisible,&x );
	assert(!(int*)result);
	tearDown();
}

void test_findLast_returns_null_if_there_is_no_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,7,9},sizeof(int),5};
	int x = 2;
	assertEqual((int)findLast(a,isEven,&x),(int)NULL);
};
int isUpperCase(void* a,void *b){
	return (*((char*)b) >= 'A' && *((char*)b) <= 'Z') ? 1 : 0;
}
void test_findLast_returns_the_last_element_if_there_is_match_in_character_array(){
	ArrayUtil a = {(char[]){'a','b','C','D','e'},sizeof(char),5};
	int x = 'D';
	assertEqual(*((char*)findLast(a,isUpperCase,&x)),'D');
}

void test_findLast_returns_the_last_element_if_there_is_match_in_integer_array(){
	ArrayUtil a = {(int[]){1,3,5,8,10},sizeof(int),5};
	int x = 2;
	assertEqual(*((int*)findLast(a,isEven,&x)),10);
}
void test_findLast_gives_occurence_of_last_element_in_floatArray_greaterThan5 (){
	float hint = 5.1;
	float *result;
	match *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	result = (float*)findLast(util,match,(void*)&hint);
	assertEqual(*result,(float)8.3);
}

void test_count_return_number_of_element_match_the_criteria(){
	int x =5,result;
	setUp();
	result  = count(intUtil1, &isDivisible,&x );
	assertEqual(result , 2);
	tearDown();
}

void test_count_return_number_of_element_match_the_criteria_or_0(){
	int x =13,result;
	setUp();
	result  = count(intUtil1, &isDivisible,&x );
	assertEqual(result , 0);
	tearDown();
}

int intLessThan(void* hint, void* item ){
	return ((*(int*)hint) > *(int*)item);
};

void test_filter_return_number_of_coppide_element_onto_destination(){
	int x=25,result,maxItem=4;
	int* destination[10];
	setUp();
	result = filter(intUtil1,&intLessThan,&x,(void**)destination,maxItem);
	assertEqual(result, 4);
}

void test_filter_can_copy_maximum_number_of_item_given(){
	int x=25,result,maxItem=3;
	int* destination[10];
	setUp();
	result = filter(intUtil1,&intLessThan,&x,(void**)destination,maxItem);
	assertEqual(result, 3);
}

void test_filter_should_copy_to_destination_only_matching_criteria(){
	int x=25,result,maxItem=10;
	int* destination[10];
	setUp();
	result = filter(intUtil1,&intLessThan,&x,(void**)destination,maxItem);
	assertEqual(result, 4);
}
int Divisible(void* a,void *b){
	return (*((int*)b)%*((int*)a) == 0) ? 1 : 0;
}
void test_filter_gives_2_4_for_1_2_3_4_5(){
	ArrayUtil util = create(sizeof(int),5);
	int *arr,i,result,hint = 2,*lIst;
	void* list;
	arr = (int*)util.base;
	for(i=0;i<5;i++){
		arr[i] = i+1;
	}
	printf("add in test %p\n",list );

	result = filter(util, isDivisible,&hint,&list,2);
	lIst = (int*)list;
	printf("add in test %p\n",&list[0] );
	assertEqual(result,2);
	assertEqual(lIst[0],2);
	assertEqual(lIst[1],4);
	free(list); 
}
void test_filter_gives_D_E_for_a_b_c_D_E() {
	ArrayUtil a = {(char[]){'a','b','c','D','E'},sizeof(char),5};
	char *result,hint = 'a',*lIst;
	void* list;
	int count;
	count =  filter(a,isUpperCase,&hint,&list,2);
	lIst = (char*)list;
	assert(count==2);
	assertEqual(lIst[0],'D');
	assertEqual(lIst[1],'E');
	free(list); 
}
int compare(void *hint,void* item){
	if(*(char*)item=='a')
		return 1;
	return 0;
};

void test_filter_will_return_the_array_a_a_a(){
	char a[]={'a','a','a','b','d'},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(char), 5};
	length = filter(array,compare,&hint,&result,5);

	assertEqual(((char*)result)[1],'a');
	assertEqual(length,3);
	free(result);
};
void test_filter_filters_the_util_floatArray_which_matches_the_criteria (){
	float hint = 5.1;
	match *match = &isGreaterThanHint;
	ArrayUtil util = {(float[]){7.1,2.4,1.6,3.7,8.3,0.1},FLOAT_SIZE,6};
	float *destination;
	destination = malloc(FLOAT_SIZE*2);
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),2);
	assertEqual(destination[0], (float)7.1);
	assertEqual(destination[1], (float)8.3);
}
int isEqual(void* hint, void* item){
	if(*(int*)item==8 ||*(float*)item == 9.0 || *(double*)item==8.9)
		return 1;
	return 0;
}
void test_filter_will_return_the_array_of_only_two_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((int*)result)[1],8);
	assertEqual(length,2);
	free(result);
};
void test_filter_will_return_the_array_of_only_two_8_point_7_in_float(){
	float a[]={1.4,8.4,8.9,7,8,9.0},hint=3;
	int length;
	void* result;
	ArrayUtil array = {a, sizeof(float), 6};
	length = filter(array,isEqual,&hint,&result,2);

	assertEqual(((float*)result)[0],9.0);
	assertEqual(length,1);
	free(result);
};
// void test_filter_will_return_the_array_of_only_one_element_8_point_9_in_double(){
// 	double a[]={8.4,8.4,8.9},hint=3.9;
// 	int length;
// 	void* result;
// 	ArrayUtil array = {a, sizeof(double), 3};
// 	length = filter(array,isEqual,&hint,&result,2);

// 	assertEqual(((double*)result)[0],8.9);
// 	assertEqual(length,1);
// 	free(result);
// };
int stringCompare(void *hint, void* item){
	String str ="hello";
	String getItem = *(String*)item;
	if(getItem==str)
		return 1;
	return 0;
}

// void test_filter_will_return_the_array_string_contain_hello(){
// 	int length,hint=9;
// 	void* result,*expected;
// 	ArrayUtil array = create(sizeof(String),2);
// 	((char**)array.base)[0]="hello";
// 	((char**)array.base)[1]="gello";
// 	length = filter(array,stringCompare,&hint,&result,2);
// 	expected = ((String*)result)[0];
	
// 	assertEqual(length,1);
// 	assertEqual(strcmp(expected,"hello"),0);
// };

void test_filter_will_return_the_array_of_8_8_8(){
	int a[]={1,8,8,7,8,9},hint=3,length;
	void* result;
	ArrayUtil array = {a, sizeof(int), 6};
	length = filter(array,isEqual,&hint,&result,5);

	assertEqual(((int*)result)[0],8);
	assertEqual(length,3);
	free(result);
};

void test_filter_populate_destination_array_with_evenNumbers(){
    int maxItem=6;
    void *evens;
    int hint = 0;
    util1 = (ArrayUtil){(int[]){101,22,12,13},sizeof(int),4};
   	 
	 assertEqual(filter(util1,isEven,&hint,&evens,maxItem),2);
	 assertEqual(((int*)evens)[0],22);
	 assertEqual(((int*)evens)[1],12);
}
void test_filter_filters_the_util_intArray_which_matches_the_criteria (){
	int hint = 4;
	match *match = &isGreaterThanHint;
	ArrayUtil util = {(int[]){7,2,6,3,8,9},INT_SIZE,6};
	int *destination;
	destination = malloc(INT_SIZE*4);
	assertEqual(filter(util, match, (void*)&hint, (void*)&destination, 4),4);
	assertEqual(destination[0], 7);
	assertEqual(destination[1], 6);
	assertEqual(destination[2], 8);
	assertEqual(destination[3], 9);
}
int arrayEqual(int*arr1,int*arr2){
	int i,length1 = sizeof(arr1)/sizeof(arr1[0]),length2 = sizeof(arr2)/sizeof(arr1[0]);
	if(length1 != length2)
		return 0;

	for(i=0;i<length1;i++){
		if(arr1[i]!=arr2[i])
			return 0;
	}
	return 1;
};
void test_filter_fills_filtered_array_with_even_numbers_of_existing_array_and_returns_count(){
	int array[]={1,2,3,4,5,6,7,8};
	int newArray[]={2,4,6,8};
	ArrayUtil util={array,INT_SIZE,8};
	int *filtered=(int *)malloc(INT_SIZE*5);
	int counter=filter(util,isEven,0,(void**)&filtered,5);
 	assertEqual(counter,4);
 	assert(arrayEqual(newArray,filtered));
 	free(filtered);
}

void test_filter_returns_0_when_there_are_no_enven_no_in_existing_array(){
	int array[]={1,3,5,7};
	ArrayUtil util={array,INT_SIZE,4};
	int *filtered=(int *)malloc(INT_SIZE*2);
	int counter=filter(util,isEven,0,(void**)&filtered,2);
 	assertEqual(counter,0);
 	free(filtered);
}


// 

#include <stdio.h>
typedef char* STRING;
typedef char*  String;
#define INT_SIZE sizeof(int)
#define CHAR_SIZE sizeof(char)
#define FLOAT_SIZE sizeof(float)
#define DOUBLE_SIZE sizeof(double)
#define SIZEOF_INT sizeof(int)
#define SIZEOF_FLOAT sizeof(float)
#define SIZEOF_CHAR sizeof(char)
#define SIZEOF_DOUBLE sizeof(double)

typedef struct Student{
    int rollno;
    float age;
} student;

typedef struct arrayUtil{
	void* base;
	int typeSize;
	int length;
} ArrayUtil;

typedef void (OperationFunc)(void*hint,void*item);
typedef int (match)(void*,void*);
typedef int (strMatch)(void*,void*);
typedef void(ConvertFunc)(void*,void*,void*);
typedef void* (ReducerFunc)(void* hint, void* previousItem, void* item);

int areEqual(ArrayUtil array1,ArrayUtil array2);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil array1,int length);
int findIndex(ArrayUtil array,void* ele);
void dispose(ArrayUtil array);
void* findFirst(ArrayUtil util, match* fun, void* hint);
void* findLast(ArrayUtil util, match* fun, void* hint);
int count(ArrayUtil util, match* fun, void* hint);
int filter(ArrayUtil util, strMatch* fun, void* hint,void** destination,int maxitem);
void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);
void forEach(ArrayUtil util, OperationFunc* operation, void* hint);
void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* initialValue);


#ifndef ADAPTARRAY_H
#define ADAPTARRAY_H
typedef struct AdptArray_* PAdptArray;
typedef enum  {FAIL = 0, SUCCESS=1} Result;
typedef void* PElement;

typedef void(*DEL_FUNC)(PElement);
typedef PElement(*COPY_FUNC)(PElement);
typedef void(*PRINT_FUNC)(PElement);

PAdptArray CreateAdptArray(COPY_FUNC, DEL_FUNC,PRINT_FUNC);// Initialize an empty array without elements
void DeleteAdptArray(PAdptArray);// Realese the memory of the object (include it is elements)
Result SetAdptArrayAt(PAdptArray, int, PElement);// Get index and element. Save a deep copy of the element in the given index.
// If there is alredy element in the given index, we will free it memory
//מקבלת אינדקס ואיבר ושומרות עותק של האיבר
//במקום המבוקש. משחררת את האיבר הישן אם
//קיים.
PElement GetAdptArrayAt(PAdptArray, int);//get index and return copy of the element in this index
int GetAdptArraySize(PAdptArray);//return the size of the array.if the array is not initialized correctly, we will return -1
void PrintDB(PAdptArray);//print all elements in the array
#endif
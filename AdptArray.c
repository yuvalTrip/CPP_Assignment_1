#include "AdptArray.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Implement the struct of AdptArray_
typedef struct AdptArray_{
    // COPY, PRINT, DELETE functions
    PElement * PElemArr;// Pointer to the head of the array
    COPY_FUNC copy_func;
    DEL_FUNC del_func;
    PRINT_FUNC print_func;
    int arrLen;
} AdptArr, * PAdptArray;


int GetAdptArraySize(PAdptArray arr)/////////.....................................................GOOD
//return the size of the array.if the array is not initialized correctly, we will return -1
{
    if(arr==NULL)//i.e the size is 0 (because NULL=0)
    {
        return -1;
    }
    else{
        int size = arr->arrLen;
        return size;
    }
}

PAdptArray CreateAdptArray(COPY_FUNC CF, DEL_FUNC DF,PRINT_FUNC PF)//initialize an empty array without elements
{
    // Allocate memory for the new 'class' of arrays
    struct AdptArray_  *new_PAdptArr = malloc(sizeof(struct AdptArray_));
    if (new_PAdptArr==NULL)
    {
        printf ("Memory allocation failed\n");
        exit(1);
    }
    //initilize all function
    new_PAdptArr->copy_func =  CF;
    new_PAdptArr->del_func= DF;
    new_PAdptArr->print_func=PF;
    new_PAdptArr->PElemArr = NULL; // initialize to NULL

    //initilize arr len to 0
    new_PAdptArr->arrLen=0;

   return new_PAdptArr;
}

void DeleteAdptArray(PAdptArray PAdptArr)//realese the memory of the object (include it is elements)
{
    if(GetAdptArraySize(PAdptArr)==-1 || PAdptArr==NULL)//if the array is not initialized correctly
    {
        return;//we will do nothing
    }
    else
    {
        int len = PAdptArr->arrLen;
        for (int i = 0; i < len; i++)
        {
            if (PAdptArr->PElemArr[i] != NULL)
            {
                PAdptArr->del_func(PAdptArr->PElemArr[i]);
            }
        }
        PAdptArr->arrLen=0;
        free(PAdptArr->PElemArr);
        free(PAdptArr);
    }
}

Result SetAdptArrayAt(PAdptArray PAdptArr, int indx , PElement Pelement)
{
    int len = PAdptArr->arrLen; // current size of the array

    if (indx < len) // if the given index is in the range of the current array
    {
        if (PAdptArr->PElemArr[indx] != NULL) // if the index is used by another object, we will free the old object
        {
            PAdptArr->del_func(PAdptArr->PElemArr[indx]);
        }
    }
    else if (indx < 0)
    {
        return FAIL;
    }
    else // if the given index is not in the range of the current array
    {
        int new_size = indx + 1; // Define the new size of the array
        PElement *new_element_array = realloc(PAdptArr->PElemArr, new_size * sizeof(PElement)); // Allocate memory for 'new_size' elements in new array

        if (new_element_array == NULL)
        {
            printf("Memory allocation failed\n");
            exit(1);
        }

        PAdptArr->PElemArr = new_element_array;
        memset(PAdptArr->PElemArr + len, 0, (new_size - len) * sizeof(PElement)); // Initialize the new elements to NULL
        PAdptArr->arrLen = new_size;
    }

    // Set the new element at the given index in the array
    PAdptArr->PElemArr[indx] = PAdptArr->copy_func(Pelement); // copy the element;
    return SUCCESS;
}

PElement GetAdptArrayAt(PAdptArray PAdptArr, int indx)//get index and return copy of the element in this index
{
    int len= PAdptArr->arrLen; //current size of the array
    if (indx < len && index>=0 && PAdptArr->PElemArr[indx]!=NULL)//if the given index is in the range of the current array
    {
        return PAdptArr->copy_func(PAdptArr->PElemArr[indx]);//copy the element;

    }
    else if(PAdptArr->PElemArr[indx]==NULL)
    {
        return NULL;
    }
    else//if the given index is not in the range of the current array
    {
        return NULL;
    }
}

void PrintDB(PAdptArray PAdptArr)//print all elements in the array
{
    int len= PAdptArr->arrLen; //current size of the array
    PElement*temp = PAdptArr->PElemArr;//we will save the pointer and the array
    PElement * pre;

    for (int i =0 ; i< len;i++)//and iterate over all array
    {
        pre = temp;//move to the next index
        temp++;//increase temp_current to continue iterate over all elements
        if (*pre!=NULL){
            PAdptArr->print_func(*pre);//use the proporate function to delete pre element from array
        }
        else
        {
            continue;
        }
    }

}



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void dump(int *arr, int size)
{
	int idx;

	for (idx = 0; idx < size; idx++)
		printf("%08d\n", arr[idx]);
}


int  partation(int *array , int p , int r)
{
    int pivot = array[r]; 
    int i = p ; 
    int  j  = p ;
    for( ; j < r ; j ++)
    {
        if(array[j] < pivot)
        {   
            if(i !=j )
            {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp ; 
            }
            i++;
        }
    }

    int tmp =  array[i];
    array[i] = pivot;
    array[r] = tmp ; 
    return i ;
}



void __quick_sort(int *array , int p , int r)
{
    int q = 0  ; 
    if(p>=r) return ; 

    q = partation(array , p , r);

    __quick_sort(array , p , q - 1  );

    __quick_sort(array , q + 1 , r);
}

void quick_sort(int *arr, int size)
{
	__quick_sort(arr, 0, size - 1);
}

void quick_sort_test()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	quick_sort(test, 10);

	dump(test, 10);
}


int main()
{
	quick_sort_test();
	return 0;
}

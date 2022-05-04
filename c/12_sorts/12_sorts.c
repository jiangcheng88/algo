#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void dump(int *arr, int size)
{
	int idx;

	for (idx = 0; idx < size; idx++)
		printf("%08d\n", arr[idx]);
}



void _merge(int * array , int p , int q , int r )
{
    int *tmp = (int *)malloc(sizeof(int)*(r-p + 1 ));
    int i , j  = 0 , k = 0  ;
    for(i = p , j = q+1 ,k = 0; i <=q && j <= r ;  )
    {
        if(array[i]<= array[j])
            tmp[k++] = array[i++];
        else     
            tmp[k++] = array[j++];
    }
    // 将剩余的合并到队尾
    if (i ==( q + 1) ) 
    {
        for(; j <= r ; )
        {
            tmp[k++] = array[j++];
        }
    }else {
        for(; i <= q ; )
        {
            tmp[k++] = array[i++];
        }
    }
    memcpy(array+p , tmp,( r-p +1 )* sizeof(int));
    free(tmp);
}

// 合并排序
void __merge_sorts(int *arrary ,int  p , int r )
{
    int  q ;
    if (p >= r)
		return;
    
    q = ( p + r )  / 2 ;

    __merge_sorts(arrary , p , q );
    __merge_sorts(arrary , q+1 , r);

    _merge(arrary , p , q , r );
}



void merge_sorts(int *array , int size)
{
    __merge_sorts(array , 0 ,size -1 );
}


void merge_sort_test()
{
	int test[10] = {5, 8, 9, 23, 67, 1, 3, 7, 31, 56};

	merge_sorts(test, 10);

	dump(test, 10);
}

// 利用递归 排序
int main()
{
    merge_sort_test();
    return 0 ;
}


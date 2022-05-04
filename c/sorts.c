#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

typedef struct _array {
    int     size ;
    int     used ; 
    int     *array; 
}array ;

void dump(array *array)
{
	int idx;
	
	for (idx = 0; idx < array->used; idx++)
		printf("[%02d]: %04d\n", idx, array->array[idx]);
}

void  alloc(array *array)
{   
    array->array = malloc(sizeof(int)*array->size);  
}

void  bubble_sort (array *array)
{
    int tmp  =0 ; 
    for(int i = 0 ; i < array->used  ;  i ++)
    {
        bool swap=  false;
        for(int j = 0 ; j  < array->used - i -1 ; j++ )
        {
            if(array->array[j] > array->array[j+1])
            {
                tmp = array->array[j]; 
                array->array[j]= array->array[j+1];
                array->array[j+1] = tmp;
                swap = true;
            }
        }
        if(!swap)
        break ;
    }
}

void insert_sort(array *array)
{
    int val = 0 ; 
    int j = 0 ;
    for(int i =  0 ; i < array->used ; i++ )
    {
        val = array->array[i];
        for( j = i-1; j>=0 ; j--)
        {
            if(val < array->array[j])
            {
                array->array[j+1] = array->array[j];
            }else {
                break ;
            }
        }
        array->array[j+1] = val ;       
    }
}


void bubble_test()
{
    array c ;
    c.size = 20 ; 
    alloc(&c);
    time_t t;
    srand((unsigned) time(&t));
    c.array[0] = 11 ; 
    c.array[1] = 13 ; 
    c.array[2] = 10 ; 
    c.array[3] = 1320 ; 
    c.array[4] = 8 ; 
    c.array[5] = 33 ; 
    c.array[6] = 12 ; 
    c.array[7] = 14 ; 
    c.array[8] = 155 ; 
    c.array[9] = 10; 
    c.array[10] = 20 ; 
    c.array[11] = 40 ; 
    c.array[12] = 15 ; 
    c.array[13] = 130 ; 
    c.array[14] = 13 ; 
    c.used = 15 ;
    dump(&c);
    bubble_sort(&c);
    dump(&c);
}

void insert_test()
{
    array c ;
    c.size = 20 ; 
    alloc(&c);
    time_t t;
    srand((unsigned) time(&t));
    c.array[0] = 11 ; 
    c.array[1] = 13 ; 
    c.array[2] = 10 ; 
    c.array[3] = 1320 ; 
    c.array[4] = 8 ; 
    c.array[5] = 33 ; 
    c.array[6] = 12 ; 
    c.array[7] = 14 ; 
    c.array[8] = 155 ; 
    c.array[9] = 10; 
    c.array[10] = 20 ; 
    c.array[11] = 40 ; 
    c.array[12] = 15 ; 
    c.array[13] = 130 ; 
    c.array[14] = 13 ; 
    c.used = 15 ;
    dump(&c);
    insert_sort(&c);
    dump(&c);
}



void  select_sort(array *array)
{
    int i = 0 ; int  j = 0 ;
    for( i = 0  ; i < array->used -1 ; i++)
    {
        int tmp =0  , idx  = i ; 
        for(j = i +1 ; j < array->used ; j++ )
        {
            if(array->array[j] < array->array[idx])
            {
                idx = j ;
            }
        }
        // 在未排序中没有找到最小值,进行下一轮查找
        if(idx == i )
            continue; 

        tmp = array->array[i];
        array->array[i] = array->array[idx];
        array->array[idx] = tmp ;
    }
}

void  select_test()
{
    array c ;
    c.size = 20 ; 
    alloc(&c);
    time_t t;
    srand((unsigned) time(&t));
    c.array[0] = 11 ; 
    c.array[1] = 13 ; 
    c.array[2] = 10 ; 
    c.array[3] = 1320 ; 
    c.array[4] = 8 ; 
    c.array[5] = 33 ; 
    c.array[6] = 12 ; 
    c.array[7] = 14 ; 
    c.array[8] = 155 ; 
    c.array[9] = 10; 
    c.array[10] = 20 ; 
    c.array[11] = 40 ; 
    c.array[12] = 15 ; 
    c.array[13] = 130 ; 
    c.array[14] = 13 ; 
    c.used = 15 ;
    dump(&c);
    select_sort(&c);
    dump(&c);
}



void test_sorts()
{
    int a[10]= {2,0,1,0,2,2,1,0,0,0};
    int tmp2 = 0 , tmp1;
    int p0 = 0;
    int p2 = 9;
    for(int i = 0 ; i < p2; i ++)
    {   
        if(a[i] == 0)
        {   
            tmp1 = a[p0] ;
            a[p0] = 0 ; 
            a[i] =  tmp1 ;
            p0++;
            //  i--;
        } else if(a[i] == 2 )
        {
            tmp2 = a[p2] ;
            printf("--- [%02d]: %04d\n", p2, a[p2]);
            a[p2] = 2; 
            a[i] =  tmp2 ;
            p2--;
            i--;
        }
      printf("--- [%02d]: %04d\n", i, a[i]);
    }
	for (int i  = 0; i <  sizeof(a)/sizeof(int) ; i++)
		printf("[%02d]: %04d\n", i, a[i]);
}

void swap(int *nums, int i, int j){
        printf("i %d \n",i);
        int t = nums[i];
        nums[i] =nums[j];
        nums[j] = t;
}

void sortColors() {
        int nums[10]= {2,0,1,0,2,2,1,0,0,0};
        int red = 0, blue = 10 -1;
        for(int i=0; i<= blue; i++)
        {
            if(nums[i] == 0)
                // swap(nums, red++, i);
            {
                int t =  nums[red];
                nums[red] = nums[i];
                nums[i] = t ; 
                red++ ;    
            }
            else if(nums[i] == 2){
                // swap(nums, blue--,i--);
                int t =  nums[blue];
                nums[blue] = nums[i];
                nums[i] = t ; 
                blue-- ;
                // i -- ;    
            }
        }
    for (int i  = 0; i <  sizeof(nums)/sizeof(int) ; i++)
		printf("[%02d]: %04d\n", i, nums[i]);  
}
 





int main()
{
    // select_test();
    // test_sorts();
    sortColors();
    return 0 ;

}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data ; 
  struct node  *next ; 
}Node ; 

void print(Node* node) {
  printf("\n");  
  while (node) {
        printf(" %d ->", node->data);
        node = node->next;
    }
  printf("\n---------------- \n");
}

// 在尾部插入数据
int insert_tail(Node *list , int data)
{
  Node *node = list ;
  while(node->next != NULL)
  {
    node = node->next ; 
  }
    node->next = malloc(sizeof(Node)); 
    node->next->data = data ; 
    return 0 ; 
}

// 使用二级指针传参
// 在链表头插入数据
int inset_headd(Node **list , int data)
{
   Node *node = malloc(sizeof(Node));
   node->data = data ; 
   node->next = *list;
   *list = node ; 
  return 0 ; 
}

// 返回指针方式
// 在链表头插入数据
Node * insert_head(Node *list , int data)
{
  if(list!=NULL)
  { 
    Node *node  = malloc(sizeof(Node));
    node->data = data ; 
    node->next = list ;
    return node ;  
  }
  return NULL; 
}
/// 单链表反转 
int  reverse(Node **list )
{
  Node *prev  = NULL ;  
  Node *current = *list ; 
  while(current) // 如果链表不为空
  {
     Node *next  = current->next ; 
     if(next == NULL )
     {
         *list =  current;   
     }
    
     current->next  = prev ; // 反转  
     prev = current ; // 移动
     current = next ; //移动 
  }
}
  // 单链表反转 
Node *  r_reverse(Node *list )
{
  Node *prev  = NULL ;  
  Node *current = list ; 
  while(current) // 如果链表不为空
  {
     Node *next  = current->next ; 
     if(next == NULL )
     {
         current->next = prev ; 
         return current  ;   
     }
    
     current->next  = prev ; // 反转  
     prev = current ; // 移动
     current = next ; //移动 
  }
}

// 判断是否回环 
int  circle ( Node ** node)
{
	Node *slow , *fast ; 
	slow = *node ; 
	fast = *node ; 
	if(slow == NULL || fast == NULL ) return 0 ;
  // 判断条件变量一定不能反 思考 
  while((fast != NULL) && (fast->next !=NULL))
	{
		printf("fast %p\n",fast);
		printf("fast->next %p \n ",fast->next);
		fast = fast->next->next ;
		slow = slow->next ; 
		if(slow == fast) return 1 ;  
	}
	return 0 ; 
}

int test_circle()
{
		Node *node = malloc(sizeof(Node)); 
		insert_tail(node , 2); 
		insert_tail(node ,3);
		insert_tail(node,4); 
		print(node);
		int  ret = circle(&node);	
		printf("ret = %d \n",ret);  
 
	  Node *current  = malloc(sizeof(Node)); 
	  current->data = 0 ; 
		Node *h = current  ; 		
		for(int i = 0 ; i < 4 ; i++)
		{
			Node *d = malloc(sizeof(Node)); 
			d->data = i ; 
			current->next = d ; 
			current = d ; 
		}
		current->next = h  ; 
		
		ret= 		circle(&h);
		printf("ret = %d\n",ret);
}

int test_tail()
{

  Node *da = malloc(sizeof(Node)); 
  insert_tail(da ,1);
  insert_tail(da,2 );
  insert_tail(da,3 );
  da = insert_head(da, 4 );
  da = insert_head(da, 5);
  inset_headd(&da , 8);
  print(da);
	da =   r_reverse(da);
  print(da);

}


//测试用例
int main()
{ 
  	printf("hello\n");
		test_circle();
		
    return 0 ; 
}


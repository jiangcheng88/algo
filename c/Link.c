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


//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
//示例：
//输入：1->2->4, 1->3->4
//输出：1->1->2->3->4->4
// 两个有序的链表合并

Node * merge(Node **src1 , Node ** src2 )
{
    Node *temp = malloc(sizeof(Node));
    Node *org = temp ;
    if(temp == NULL) return NULL; 
    Node *l1 = *src1 ; 
    Node *l2 = *src2 ; 
    while(1)
    {
        // 如果有空链表
        if(!l1) 
        {
          temp->next  = l2 ; 
          break ; 
        }else if(!l2)
        {
          temp->next = l1 ; 
          break; 
        }
        //如果没有空表,判断具体结点大小,按照排序
        if(l1->data <= l2->data)
        {
          temp->next = l1; 
          l1 = l1->next ;
        }else {
           temp->next = l2; 
          l2 = l2->next ;
        }
        temp = temp->next ;    
    }
  return org->next;
}


int test_merge()
{
    Node *node1 = malloc(sizeof(Node)); 
    node1->data = 10;
	  inset_headd(&node1 ,5);
		inset_headd(&node1,0); 
    print(node1);     
    Node *node2 = malloc(sizeof(Node)); 
		node2->data = 8;
		inset_headd(&node2 ,6);
		inset_headd(&node2,3); 
    print(node2);     
    Node *res = merge(&node1 , &node2);
    print(res);
}

//测试用例
int main()
{ 
  	printf("hello\n");
	//	test_circle();
		test_merge();
    return 0 ; 
}


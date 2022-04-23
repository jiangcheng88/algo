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

//测试用例
int main()
{ 
  printf("hello\n");
  
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

  return 0 ; 
}


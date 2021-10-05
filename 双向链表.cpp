#include <iostream>


using namespace std;
const int ERROR = 0;
const int OK = 1;

/* 定义双向链表 */

class DoubleLinkList{
  public:
    DoubleLinkList(int data, DoubleLinkList *prev, DoubleLinkList *next){
      this->data = data;
      this->previous = prev;
      this->next = next;
    }

  public:
    // 保存数据
    int data;
    // 前驱指针
    DoubleLinkList *previous;
    // 后继指针
    DoubleLinkList *next;
};



/* 插入元素 */
int insert(DoubleLinkList *node, int index, int data){
  
  // 初始化一个p节点
  DoubleLinkList *p = node;
  // 计时器
  int i = 1;
  while (p && i < index)
  {
    /* code */
    p = p->next;
    i++;
  }
  // 节点超出范围 
  if(!p || i > index){
    return ERROR;
  }
  // 创建新的节点
  DoubleLinkList *newNode = new DoubleLinkList(data, p, NULL);
  newNode->next = p->next;
  if(p->next){
    p->next->previous = newNode;
  }
  p->next = newNode;
  return OK;
}


int main(){
  // 创建双向链表的头结点
  DoubleLinkList *node =  new DoubleLinkList(0, NULL, NULL);
  
  // for (int i = 1; i < 5; i++){
  //   // 调用插入元素
  //   int result = insert(node, 1, i);
  // }
  int result = insert(node, 1, 22);
  insert(node, 1, 33);
  cout << "插入成功已否: " << result << endl;
    
  return 0;
}
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


const int OK  = 1;
const int ERROR = 0;


/* 定义栈的链式结构 */
class Node{
  public:
    Node(int d, Node *n){
      this->data  = d;
      this->next = n;
    }
  public:
    // 数据域
    int data;
    // 指针域
    Node *next;
};

class StackLinkList{
  public:
    StackLinkList(){
        this->top = NULL;
        // 空栈count为-1
        this->count = -1;
      }
  public:
    int count ;
    Node* top;
};

/* 压栈 */
int push(StackLinkList *s, int data){
  // 创建一个新节点
  Node* newNode = new Node(data, s->top);
  s->top = newNode;
  s->count++;
  return OK;
}

/* 出栈 */
int pop(StackLinkList *stack){
  // 空栈
  if(stack->count < 0){
    return ERROR;
  }
  int result = stack->top->data;
  Node *p = stack->top;
  stack->top = stack->top->next;
  // 释放内存
  delete p;
  stack->count--;
  return result;
  
}


int main(){
  cout << pow(2,3) << endl; 
  StackLinkList *node = new StackLinkList();
  // 调用压栈函数
  // push(node, 1);
  // push(node, 2);
  vector<int> test;
  test.insert(test.begin(), 1);
  // 调用出栈函数
  int result = pop(node);
  cout << "pop: " << result << endl;
  return 0;
}
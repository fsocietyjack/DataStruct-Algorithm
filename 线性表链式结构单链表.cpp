#include <iostream>
// 生成随机数的库
#include <cstdlib>
#include <time.h>
using namespace std;

const int OK = 1;
const int ERROR = 0;


class Node{
  public:
    Node(int data, Node* node){
      this->data = data;
      this->next = node;
    }
  public:
    // 节点的数据域
    int data;
    // 指向下一个节点的Node指针
    Node *next;
};

// 单链表的读取
int getElement(Node node, int index){
  // 指向第一个节点
  Node* p = node.next;
  // i为计数器
  int i = 1; 
  while(p && i < index){
    p = p->next;
    ++i;
  }
  // 可能元素不存在
  /*
    1. 第一种情况是指向下一个元素的节点不存在
    2. 第二种情况是index取第0个元素
  */
  if(!p || i > index){
    cout << "Error!" << endl;
    return ERROR;
  }
  return p->data;

}

// 单链表的插入
int insertElement(Node *node, int index, int data){
  Node *p = node;
  // 计数器
  int j = 1; 
  while (p && index > j){
    p = p->next;
    ++j;
  };
  // 可能元素不存在
  /*
    1. 第一种情况是指向下一个元素的节点不存在
    2. 第二种情况是index取第0个元素(头结点)
  */
  if(!p || j > index){
    cout << "Error!" << endl;
    return ERROR;
  };

  // 先创建一个节点
  /*
    插入元素的算法: p->next; p-next = newNode;
  */
  Node* newNode = new Node(data, p->next);
  p->next = newNode;
  return OK;
}

// 头插法生成单链表
void createLinkListHead(){
  // 创建头结点单链表
  Node *node = new Node(0, NULL);
  // 初始化随机种子
  srand(time(NULL));
  for (int i = 0; i < 10; i++){
    // 生成100以内的随机数
    int num = rand() % 100 + 1;
    // 创建新节点
    Node* newNode = new Node(num, NULL);
    newNode->next = node->next;
    node->next = newNode;
  }
}
// 尾插法生成单链表
Node* createLinkListTail(){
  // 创建头结点单链表
  Node *node = new Node(0, NULL);
  // 初始化随机种子
  srand(time(NULL));
  Node *p = node;
  for (int i = 0; i < 10; i++){
    // 生成100以内的随机数
    int num = rand() % 100 + 1;
    // cout << num << endl;
    // 创建新节点
    Node* newNode = new Node(num, NULL);
    p->next = newNode; 
    // 将指针指向下一个新节点
    p = p->next;
  }
  return node;
}

// 清空单链表
int clearLinkList(Node* node){
  Node* p;
  Node* q;
  p = node;
  q = NULL;
  while(p){
    q = p->next;
    // 释放内存
    delete p;
    p = q;
  }
  // 头结点的指针域指向NULL
  node->next = NULL;
  return OK;
}


// 获取单链表的长度
int getLinkListLength(Node *node){
  // p指向单链表的第一个节点
  Node* p = node->next;
  // 计数器
  int num = 0;
  while (p){
    p = p->next;
    num += 1;
  }
  return num;
}

int main(){
  // 第一个节点
  // Node* next = new Node(1, NULL);
  // 初始化头结点
  Node* node = new Node(0, NULL);
  // 插入元素
  int statusCode = insertElement(node, 1, 3);
  // 获取第一个节点元素的值
  // int result = getElement(node,0);
  cout << "插入是否成功: " << statusCode << endl;
  
  // createLinkListHead();
  // Node * node = createLinkListTail();
  // 清空单链表
  // int result =  clearLinkList(node);
  // cout << "清空结果: " << result << endl;
  
  // 获取单链表的长度
  // int length = getLinkListLength(node);
  // cout << "单链表的长度: " << length << endl;
  return 0;
}
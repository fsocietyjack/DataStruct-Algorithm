#include <iostream>


using namespace std;

const int OK = 1;
const int ERROR = 0;
const int MAXSIZE = 20;


// 定义线性表
// 里面包含保存数据数量的大小, 以及长度
class List
{
  public:
    List(int arr[], int l){
      data = arr;
      length = l;

    };
  public:
    int* data;
    int length;
};
int getElement(List list, int index){
  // if (arr.le)
  if (list.length < 1 || index < 1 || index > list.length){
    cout << "Error!"<< endl;
    // 返回错误
    return ERROR;
  };
  return list.data[index - 1];
}


// 线性表的插入操作
int insertElement(List* list, int index, int element){

  // 判断线性表里面的元素是否饱满
  if(list->length >= MAXSIZE){
    return ERROR;
  }
  // 判断插入的元素是否超出范围
  if(index > list->length + 1 || index < 1){
    // cout << "超出范围!" << endl << index << " " << list->length + 1;
    return ERROR; 
  }
  // 插入的元素不在表尾
  if(index <= list->length){
    for (int i = list->length - 1; i >= index - 1; i--){
      list->data[i + 1] = list->data[i];
    }
  }
  list->data[index - 1] = element; // 插入元素
  list->length ++;
  return OK;
}

// 线性表的删除操作
int removeElement(List *list, int index){
  // 线性表为空
  if(list->length == 0){
    return ERROR;
  }
  // 判断删除的元素位置不正确
  if(index < 1 || index > list->length){
    return ERROR;
  }
  // 保存删除后的元素
  int delElement = list->data[index - 1];
  // 删除的元素不在末尾
  if(index < list->length){
    for(int i = index - 1; i < list->length; i++){
      list->data[i] = list->data[i + 1];
    }
  }
  list->length--;
  return delElement;
}


int main(){

  int data[MAXSIZE] = {0,1,2,3,4,5,6,7,8};
  int len = 9;
  // 初始化一个线性表
  List list = List(data, len);
  // 删除元素
  cout << "线性表的长度: " << list.length << endl;
  int result = removeElement(&list, 9);
  cout << "删除的元素: " << result << endl;
  // 删除元素后的线性表长度
  cout << "删除元素后线性表的长度: " << list.length << endl;
  // 插入元素
  // insertElement(&list, 10, 100);
  // cout << "main: " << list.data[9] << endl;
  // 获取元素
  // int result = getElement(list, 7);
  // cout << result << endl;
  return 0;
}
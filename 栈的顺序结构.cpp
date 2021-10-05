#include <iostream>

using namespace std;

const int ERROR = 0;
const int OK = 1;

// 栈的大小
const int MAXSIZE = 5;
/* 定义栈的顺序结构 */
class Stack
{
  // public:
  //   Stack(int *arr){
  //     this->data = arr;
  //   }
public:
  int data[MAXSIZE];
  // 栈顶的位置
  int top = -1;
};

/* 压栈 */
int push(Stack *s, int el)
{
  // 判断栈是否满
  if (s->top == MAXSIZE - 1)
  {
    return ERROR;
  }
  // 栈指针加一
  s->top++;
  s->data[s->top] = el;
  return OK;
}

/* 出栈 */
int pop(Stack *s)
{
  // 判断栈是否为空
  if (s->top == -1)
  {
    return ERROR;
  }
  int result = s->data[s->top];
  s->top--;
  return result;
}
int main()
{
  Stack *s = new Stack();
  for (int i = 0; i < 5; i++)
  {
    // 调用压栈
    push(s, i);
  }
  int result = pop(s);
  cout << "出栈的元素是: " << result << endl;
  cout << "压栈的元素: " << s->data[0] << endl;

  return 0;
}
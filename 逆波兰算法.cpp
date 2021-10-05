#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
#include <math.h>
using namespace std;

// 字符串切分函数
void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}


/*
** 判断优先级
** a: 栈顶元素, b: 待比较元素
*/
bool isPop(char a, char b)
{
  // 栈顶元素为(直接返回false
  if (a == '(')
    return false;
  if (b == '*' || b == '/')
  {
    if (a == '*' || a == '/')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  // 次后的元素优先级都低, 直接返回true
  return true;
}

/*
** 将中缀表达式转为后缀表达式
** src: 原表达式, dst: 结果表达式
** 返回结果: string
*/
string toSuffix(string src, string dst)
{
  /*
  ** 定义符号栈
  */
  stack<char> symbol;
  // 开始判断
  for (int i = 0; i < src.length(); i++)
  {
    // 特殊符号判断
    if (src[i] == ' ')
    {
      continue;
    }
    // 最高优先级符号(直接入栈
    else if (src[i] == '(')
    {
      symbol.push(src[i]);
    }
    //遇到 ） ，输出（ ）之间的所有符号
    else if (src[i] == ')')
    {
      while (symbol.top() != '(')
      {
        dst.push_back(symbol.top());
        symbol.pop();
        // 追加一个空格
        dst.push_back(' ');
      }
      // 将符号(也去掉
      symbol.pop();
    }
    /*      数字判断           */
    else if (isdigit(src[i]))
    {
      dst.push_back(src[i]);
      // 如果后面不是数字就加空格
      if (!isdigit(src[i + 1]))
      {
        dst.push_back(' ');
      }
    }
    /*      运算符            */
    else
    {
      switch (src[i])
      {
      case '+':
      case '-':
      case '*':
      case '/':
        /* code */
        // 如果符号栈为空直接push
        if (symbol.empty())
        {
          symbol.push(src[i]);
        }
        else
        {
          // 判断是否将符号栈的元素出栈
          if (isPop(symbol.top(), src[i]))
          {
            while (!symbol.empty() && isPop(symbol.top(), src[i]))
            {
              dst.push_back(symbol.top());
              dst.push_back(' ');
              symbol.pop();
            }
            // 将src[i]压入栈中
            symbol.push(src[i]);
          }
          else
          {
            symbol.push(src[i]);
          }
        }
        break;

      default:
        break;
      }
    }
  }
  /*
  ** src已遍历完成, 剩下就是把符号栈的剩余元素push到dst中
  */
  while (!symbol.empty())
  {
    dst.push_back(symbol.top());
    dst.push_back(' ');
    symbol.pop();
  }
  // dst.push_back('\0');
  return dst;
}


/*
** 判断字符串是否为数字
*/
bool isNumber(string &s){
  for (int i = 0; i < s.size(); i++){
    if (!isdigit(s[i])){
      return false;
    }
  }
  return true;
}
/*
** 逆波兰算法计算四则表达式
*/
long reversePoland(vector<string> src)
{
  /*
  ** 定义一个数字栈
  */
  stack<long> number;
  // 对后缀表达式进行遍历
  for (int i = 0; i < src.size(); i++)
  {
    // 判断是否为空格
    if (src[i] == " ")
    {
      continue;
    }
    // 数字
    else if (isNumber(src[i]))
    {
      // 将字符串转为数字再压栈
      
      long num = stol(src[i]);
      number.push(num);
    }
    // 符号
    else
    {
      long num1 = number.top();
      number.pop();
      long num2 = number.top();
      number.pop();
      long res = 0;
      if (src[i] == "+"){
        /* code */
        res = num2 + num1;
      }
      else if(src[i] == "-"){
        /* code */
        res = num2 - num1;
      }
      else if (src[i] == "*"){
        /* code */
        res = num2 * num1;
      }
      else if(src[i] == "/"){
        /* code */
        res = num2 / num1;
      }
      number.push(res);
    }
  
  }
  return number.top();
}

int main()
{
  // cout <<  << endl;
  // cout << sqrt(2) << endl; 
  string src = "-9+8+(100-2)+6/2";
  // 调用函数
  string dst = toSuffix(src, "");
  vector<string> des;
  // 分割字符串
  SplitString(dst, des, " ");
  long res = reversePoland(des);
  cout << "后缀表达式: " << dst << endl;
  cout << "计算结果: " << res << endl;
  return 0;
}
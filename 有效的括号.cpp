#include <iostream>
#include <stack>
using namespace  std;


bool isValid(const string& s){
  stack<char> symbol;
  for (int i = 0; i < s.size(); i++){
    if (s[i] == '('){
      symbol.push(')'); continue;
    } 
    if (s[i] == '['){
       symbol.push(']'); continue;
    }
    if (s[i] == '{') {
      symbol.push('}'); continue;
    }
    else if (symbol.empty() || s[i] != symbol.top()) return 0; 
    symbol.pop();
  }
  return symbol.empty();
}

int main(){
  string test = "{[()]}";
  cout << isValid(test) << endl;
  return 0;
}
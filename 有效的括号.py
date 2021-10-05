

def isValid(s: str):
  # 定义一个栈
  symbol = []
  for i in s:
    if i == "(":
      symbol.append(")")
    elif i == "[":
      symbol.append("]")
    elif i == "{":
      symbol.append("}")
    elif len(symbol) == 0 or i != symbol.pop(): return False
  return len(symbol) == 0


if __name__ == "__main__":
  test = "[]{}()"
  print(isValid(test))
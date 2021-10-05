#include <iostream>


using namespace std;


/* 找出两个有序数组当中重复的元素 */
void findRepeat(int *arr1, int *arr2, int len1, int len2){
  // 定义的数据保存重复的元素
  int result[len1] = {0};
  // 数组1, 数组2的指针
  int p0, p1, p2;
  p0 = p1 = p2 = 0;
  // 当p1, p2指针都没有超出数组长度时, 则继续, 否则就跳出循环
  while (p1 < len1 && p2 < len2){
    cout << "位" << endl;
    if(arr1[p1] == arr2[p2]){
      // if(p0 > 0 && result[p0 - 1] == arr1[p1]){}
      // else{
      //   // 重复元素
      //   result[p0++] = arr1[p1];
      // }
      if (p0 == 0 || result[p0 - 1] != arr2[p2]){
        // 重复元素
        result[p0++] = arr1[p1];
      }
      p1++;
      p2++;
    }
    else if(arr1[p1] > arr2[p2]){
      p2++;
    }
    else{
      p1++;
    }
  }

}


int getSum(int a, int b){
  int c = a & b;
  while(c){
    a = a ^ b;
    b = c << 1;
    c = a & b;
  }
  return a ^ b;
}
int main(){
  int result = getSum(-1,1);
  cout << "结果： " << result << endl;
  // int arr1[] = {4,5,9,9};
  // int arr2[] = {4,4,8,9,9};
  // int len1 = sizeof(arr1) / sizeof(arr1[0]);
  // int len2 = sizeof(arr2) / sizeof(arr2[0]);
  // cout << len1 << " " << len2 << endl;
  // findRepeat(arr1, arr2, len1, len2);
  return 0;
}
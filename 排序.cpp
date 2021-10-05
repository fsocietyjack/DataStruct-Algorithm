#include <iostream>


using namespace std;



/* 冒泡排序 */

int * Bubble(int* arr, int length){
  // 求数组的长度
  for (int i = 1 ; i<length;i++){
    for (int j = 0 ; j < length - i; j++){
      if (arr[j] > arr[j + 1]){
        int temp =  arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
  return arr;
}



/* 选择排序 */
void Selection(int *arr, int length){
  for (int i = 0 ; i<length - 1;i++){
    // 假定第一个元素为最小值
    int minValue = arr[i];
    for (int j = i + 1 ; j < length; j++){
      if (minValue > arr[j]){
        int temp =  arr[j];
        arr[j] = minValue;
        minValue = temp;
      }
    }
  } 
}

/* 插入排序 */
void Insert(int *arr, int length){
  // 插入排序分组 已排序和组和未排序的组
  // 默认原始数组的第一个元素为已排序的组, 第二个元素以后为未排序的组
  for (int i = 1; i < length; i++){
    // 未排序的元素和已排序组元素进行比较
    for (int j = i; j > 0; j--){
      if(arr[j - 1] > arr[j]){
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
      }else{
        break;
      }
    }
  }
}

/* 希尔排序*/
void Shell(int* arr, int length){
  // 先按照增量来分组
  // 初始化增量
  int h = 1;
  while(h < length / 2){
    h = 2 * h + 1; // 增量的初始化方法
  }
  // 当增量小于1时跳出循环
  while(h >= 1){
    for (int i = h; i < length; i++){
      for (int j = i; j >= h; j = j - h){
        if(arr[j - h] > arr[j]){
          int temp = arr[j];
          arr[j] = arr[j - h];
          arr[j - h] = temp;
        }
        else{
          break;
        }
      }
    }
    // 每一次分组结束增量h为原来的一半
    h /= 2;
  }

}


/* 归并排序 */
class MergeSort{
  public:
    void merge(int *arr, int low, int mid, int height);
    void splitGroup(int *arr, int low, int height);

  public:
    MergeSort(int* arr, int length){
      // 初始化辅助数组
      assist = new int[length];
      int low = 0;
      int heigth = length - 1;
      // 进行分组
      this->splitGroup(arr, low, heigth);
    }
  private:
    int *assist;
};

/* 合并 */
void MergeSort::merge(int *arr, int low, int mid, int height){
  // 初始化三个指针
  int p0 = low;
  int p1 = low;
  int p2 = mid + 1;

  // 两个组进行比较， 直到某一个组比较完成
  while(p1 <= mid && p2 <= height){
    if(arr[p1] > arr[p2]){
      this->assist[p0++] = arr[p2++];
    }
    else{
      this->assist[p0++] = arr[p1++];
    }
  }
  /* 剩余的组只要复制值到assist中 */
  while (p1 <= mid)
  {
    /* code */
    this->assist[p0++] = arr[p1++];
  }

  while(p2 <= height){
    this->assist[p0++] = arr[p2++];
  }
  // 把assist复制到原始数组
  for (int i = low; i<=height; i++){
    arr[i] = this->assist[i];
  }
}



/* 分组 */
void MergeSort::splitGroup(int *arr, int low, int height){
  if(low >= height){
    return ;
  }
  int mid = low + (height - low) / 2;
  // 递归分组
  this->splitGroup(arr, low, mid);
  this->splitGroup(arr, mid + 1, height);
  // 分完组之后进行合并
  this->merge(arr, low, mid, height);

}



/* 快速排序 */
// 分组并返回下标
int partition(int* arr, int left, int right){
  // 取左边的第一个元素作为分界值
  int pivot = arr[left];
  while(left < right){
      // 先移动右指针直到遇到一个比privot小的值则暂停
      while(left<right && arr[right] >= pivot)
          right--;
      arr[left] = arr[right];
      // 移动左指针直到遇到一个比privot大的值则暂停
      while(left < right && arr[left]<= pivot)
          left++;
      arr[right] = arr[left];
  }
  // 将分界值赋值到left下标
  arr[left] = pivot;
  // 返回下标
  return left;
}

void sort(int* arr, int low , int height){
  // 判断是否low < height
  if(low >= height){
    return ;
  }
  int mid = partition(arr, low, height);
  // 左子组
  sort(arr, low, mid - 1);  
  // 右子组
  sort(arr, mid + 1, height);
}
void QuickSort(int * arr, int length){
  int low = 0;
  int height = length - 1;
  // 分组使得左右两组有序
  sort(arr, low, height);
}

int main(){
  // char *Q[] = {"five", "six", "seven"};
  // cout << (*Q+1)[3] << endl;
  int arr[] = {1,2,-3,4,5};
  
  int length = sizeof(arr) / sizeof(arr[0]);
  // // 调用排序算法
  // // Bubble(arr, length);
  // // 调用选择排序
  // // Selection(arr, length);
  // // 调用插入排序算法
  // Insert(arr, length);
  // 调用希尔排序
  // Shell(arr, length);
  // 调用归并排序
  // MergeSort(arr, length);
  // 调用快速排序
  QuickSort(arr, length);
  cout << "排序后的最后的数: " << arr[7] << endl;
  return 0;
}
# include <stdio.h>
#include <iostream>
#include <random>
#include <sys/time.h>

using namespace std;

class CExecTimer
{
private:
    struct timeval start, end;
    long msec = 0;

public:
    void Start(bool bPrint = false ) { 
        gettimeofday(&start, nullptr);
        if( bPrint )
            std::cout << "[Timer] Start Time : " << start.tv_sec << '.' << start.tv_usec << std::endl;
        }
    long Stop(bool bPrint = false) { 
        gettimeofday(&end, nullptr);
        msec = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec - start.tv_usec)/1000;
        std::cout << "[Timer] Exec Time : " << (int)(msec/1000) << '.' << msec%1000 << std::endl;
        return msec;
     }
    long GetExecTime(){ return msec; }

public:
    CExecTimer()
    {
        gettimeofday(&start, nullptr);
        gettimeofday(&end, nullptr);
        msec = (end.tv_sec-start.tv_sec)*1000+(end.tv_usec - start.tv_usec)/1000;
    };
    ~CExecTimer(){};
};



#define MAX_SIZE 65536
#define MAX_NUM         1000000

int sorted[MAX_SIZE]; // 추가적인 공간이 필요

void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  /* 분할 정렬된 list의 합병 */
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }

  // 남아 있는 값들을 일괄 복사
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  // 남아 있는 값들을 일괄 복사
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }

  // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}

// 합병 정렬
void merge_sort(int list[], int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2; // 중간 위치를 계산하여 리스트를 균등 분할 -분할(Divide)
    merge_sort(list, left, mid); // 앞쪽 부분 리스트 정렬 -정복(Conquer)
    merge_sort(list, mid+1, right); // 뒤쪽 부분 리스트 정렬 -정복(Conquer)
    merge(list, left, mid, right); // 정렬된 2개의 부분 배열을 합병하는 과정 -결합(Combine)
  }
}

int main(){
  int i;
  int n = MAX_SIZE;
  int list[n] = {21, 10, 12, 20, 25, 13, 15, 22};

    srand(time(nullptr));
    
    for(auto& num : list )
        num = rand()%MAX_NUM;
    cout << list[0] << ' ';
    cout << list[10] << ' ';
    cout << list[20] << ' ';
    cout << list[30] << ' ';
    cout << endl;

  // 합병 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 7)

    CExecTimer timer;

    timer.Start();
    merge_sort(list, 0, n-1);
    timer.Stop();

  // 정렬 결과 출력
    cout << list[0] << ' ';
    cout << list[10] << ' ';
    cout << list[20] << ' ';
    cout << list[30] << ' ';
    cout << endl;
    
  return 0;
}
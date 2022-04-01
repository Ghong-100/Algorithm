#include <iostream>
#include <array>
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



#define NODE_CNT        65536
#define MAX_NUM         1000000

array<int, NODE_CNT>    arr = { 0 };
array<int, NODE_CNT>    sorted = { 0 };

void merge_sort(int b, int e)
{
    // 1. 길이가 1이하면 끗
    if( e - b < 1 )
        return;
    else
    {
        int mid = (b + e) * 0.5;

        merge_sort(b, mid);
        merge_sort(mid+1, e);
        
        // 3. (재귀적으로)는 일단 빼고 합병 ㄱ
        int sortIdx = b;
        int fstIdx = b;
        int sndIdx = mid+1;
        while(fstIdx <= mid || sndIdx <= e)
        {
            if( fstIdx > mid )
                sorted[sortIdx++] = arr[sndIdx++];
            else if( sndIdx > e)
                sorted[sortIdx++] = arr[fstIdx++];
            else if( arr[fstIdx] < arr[sndIdx] )
                sorted[sortIdx++] = arr[fstIdx++];
            else if( arr[fstIdx] >= arr[sndIdx] )
                sorted[sortIdx++] = arr[sndIdx++];
        }

        for(int i = b; i <= e; ++i)
            arr[i] = sorted[i];
    }
}

int main(int argc, char** argv)
{    
    srand(time(nullptr));
    
    for(auto& n : arr )
    {
        n = rand()%MAX_NUM;
        // cout << n << ' ';
    }
    // cout << endl;

    cout << arr[0] << ' ';
    cout << arr[10] << ' ';
    cout << arr[20] << ' ';
    cout << arr[30] << ' ';
    cout << endl;

    CExecTimer  timer;

    timer.Start();
    merge_sort(0, NODE_CNT-1);
    timer.Stop();

    cout << arr[0] << ' ';
    cout << arr[10] << ' ';
    cout << arr[20] << ' ';
    cout << arr[30] << ' ';
    cout << endl;


    return 0;
}
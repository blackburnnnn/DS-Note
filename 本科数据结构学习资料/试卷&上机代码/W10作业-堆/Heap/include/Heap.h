#include <iostream>
using namespace std;
const int max_ = 21;//上限20个元素

struct Coordinate
{
    int x;
    int y;
};
bool operator > (const Coordinate &a, const Coordinate &b);

class Heap
{
    public:
        Heap();
        virtual ~Heap();
        void HeapSort();
        void BuildHeap();
        void Heapify(Coordinate* arr, int i);//从i位置开始调整为最大堆
        void BuildHeap_topk();
        void Heapify_topk(Coordinate* arr, int i, int tmpcount_);//从第一个到第tmpcount_个进行堆排序
        int n;//坐标个数
        int count_;//当前已经进入堆的坐标个数
        int k;//最小的k个数
        Coordinate arr[max_];
};










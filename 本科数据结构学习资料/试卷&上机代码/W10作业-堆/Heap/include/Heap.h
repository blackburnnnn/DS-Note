#include <iostream>
using namespace std;
const int max_ = 21;//����20��Ԫ��

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
        void Heapify(Coordinate* arr, int i);//��iλ�ÿ�ʼ����Ϊ����
        void BuildHeap_topk();
        void Heapify_topk(Coordinate* arr, int i, int tmpcount_);//�ӵ�һ������tmpcount_�����ж�����
        int n;//�������
        int count_;//��ǰ�Ѿ�����ѵ��������
        int k;//��С��k����
        Coordinate arr[max_];
};










#include <iostream>
#include <Heap.h>
using namespace std;

int main()
{
    cout << "-----------¶ÑÅÅÐò-----------" << endl;
    Heap myheap1;
    myheap1.HeapSort();
    cout << "-----------top-k-----------" << endl;
    Heap myheap2;
    myheap2.BuildHeap_topk();

    return 0;
}

#include "Heap.h"

Heap::Heap()
{
    //ctor
}

Heap::~Heap()
{
    //dtor
}

bool operator > (const Coordinate &a, const Coordinate &b)
{
    if(a.x != b.x) return a.x>b.x;
    else return a.y>b.y;
}

void Heap::Heapify(Coordinate* arr, int i)
{
    int l=2*i,r=2*i+1,largest_site=i;
    if(l<=n && arr[l]>arr[largest_site]) largest_site = l;
    if(r<=n && arr[r]>arr[largest_site]) largest_site = r;
    if(largest_site != i){
        Coordinate temp = arr[i];
        arr[i] = arr[largest_site];
        arr[largest_site] = temp;
        Heapify(arr,largest_site);//从交换后的位置继续进行调整
    }
}

void Heap::Heapify_topk(Coordinate* arr, int i, int tmpcount_)
{
    int l=2*i,r=2*i+1,largest_site=i;
    if(l<=tmpcount_ && arr[l]>arr[largest_site]) largest_site = l;
    if(r<=tmpcount_ && arr[r]>arr[largest_site]) largest_site = r;
    if(largest_site != i){
        Coordinate temp = arr[i];
        arr[i] = arr[largest_site];
        arr[largest_site] = temp;
        Heapify_topk(arr,largest_site,tmpcount_);//从交换后的位置继续进行调整
    }
}

void Heap::BuildHeap_topk()
{
    cout << "请输入即将到来的坐标点个数:";
    cin >> n;
    cout << "请输入k:";
    cin >> k;
    for(count_=1;count_<=n;count_++){//i是私有成员
        cout << "请输入第" << count_ << "个坐标:";
        cin >> arr[count_].x >> arr[count_].y;
        int tmpcount_ = count_;//保存count_值
        for(int i=count_/2;i>=1;i--){//每次输入一个之后都先调整为最大堆
            Heapify_topk(arr,i,tmpcount_);
        }
        if(tmpcount_ >= 2){//对已经进入数组的元素进行堆排序
            while(tmpcount_ >= 2){
               Coordinate temp = arr[1];
               arr[1] = arr[tmpcount_];
               arr[tmpcount_] = temp;
               tmpcount_--;
               Heapify_topk(arr,1,tmpcount_);
            }
        }
        if(count_ < k) continue;//继续输入
        else{
            cout << "此时最小 " << k << " 项为:";
            for(int i=1;i<=k;i++){
                cout << "<" << arr[i].x << "," << arr[i].y << ">" << " ";
            }
            cout << endl;
        }
    }
}

void Heap::BuildHeap()
{
    cout << "请输入坐标点个数:";
    cin >> n;
    cout << "请输入n行,每行为x与y值,并以空格分开\n";
    for(int i=1;i<=n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    for(int i=n/2;i>=1;i--){//从最后一个非叶子节点开始进行调整
        Heapify(arr,i);
    }
}

void Heap::HeapSort()
{
    BuildHeap();
    int tmp_n = n;//保存最初的n
    while(n>=2){
       Coordinate temp = arr[1];
       arr[1] = arr[n];
       arr[n] = temp;
       n--;//n是私有成员
       Heapify(arr,1);
    }
    cout << "进行堆排序:";
    for(int i=1;i<=tmp_n;i++){
        cout << "<" << arr[i].x << "," << arr[i].y  << ">" << " ";
    }
    cout << endl;
}















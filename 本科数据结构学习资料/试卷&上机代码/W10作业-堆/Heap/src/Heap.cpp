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
        Heapify(arr,largest_site);//�ӽ������λ�ü������е���
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
        Heapify_topk(arr,largest_site,tmpcount_);//�ӽ������λ�ü������е���
    }
}

void Heap::BuildHeap_topk()
{
    cout << "�����뼴����������������:";
    cin >> n;
    cout << "������k:";
    cin >> k;
    for(count_=1;count_<=n;count_++){//i��˽�г�Ա
        cout << "�������" << count_ << "������:";
        cin >> arr[count_].x >> arr[count_].y;
        int tmpcount_ = count_;//����count_ֵ
        for(int i=count_/2;i>=1;i--){//ÿ������һ��֮���ȵ���Ϊ����
            Heapify_topk(arr,i,tmpcount_);
        }
        if(tmpcount_ >= 2){//���Ѿ����������Ԫ�ؽ��ж�����
            while(tmpcount_ >= 2){
               Coordinate temp = arr[1];
               arr[1] = arr[tmpcount_];
               arr[tmpcount_] = temp;
               tmpcount_--;
               Heapify_topk(arr,1,tmpcount_);
            }
        }
        if(count_ < k) continue;//��������
        else{
            cout << "��ʱ��С " << k << " ��Ϊ:";
            for(int i=1;i<=k;i++){
                cout << "<" << arr[i].x << "," << arr[i].y << ">" << " ";
            }
            cout << endl;
        }
    }
}

void Heap::BuildHeap()
{
    cout << "��������������:";
    cin >> n;
    cout << "������n��,ÿ��Ϊx��yֵ,���Կո�ֿ�\n";
    for(int i=1;i<=n;i++){
        cin >> arr[i].x >> arr[i].y;
    }
    for(int i=n/2;i>=1;i--){//�����һ����Ҷ�ӽڵ㿪ʼ���е���
        Heapify(arr,i);
    }
}

void Heap::HeapSort()
{
    BuildHeap();
    int tmp_n = n;//���������n
    while(n>=2){
       Coordinate temp = arr[1];
       arr[1] = arr[n];
       arr[n] = temp;
       n--;//n��˽�г�Ա
       Heapify(arr,1);
    }
    cout << "���ж�����:";
    for(int i=1;i<=tmp_n;i++){
        cout << "<" << arr[i].x << "," << arr[i].y  << ">" << " ";
    }
    cout << endl;
}















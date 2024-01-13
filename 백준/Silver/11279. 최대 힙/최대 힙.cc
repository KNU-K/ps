#include<iostream>
using namespace std;

#define MAX 100000

int heap[MAX] = {0,};
int heapSize = 0;

void insertMaxHeap(int data) {
    int index = ++heapSize;

    while (index > 1 && data > heap[index / 2]) {
        heap[index] = heap[index / 2];
        index /= 2;
    }

    heap[index] = data;
}

void popHeap() {
    if (heapSize == 0) {
        cout << "0\n";
    } else {
        int result = heap[1];
        heap[1] = heap[heapSize--];

        int parent = 1;
        int child = 2;

        while (child <= heapSize && (heap[child] > heap[parent] || (child + 1 <= heapSize && heap[child + 1] > heap[parent]))) {
            if (child + 1 <= heapSize && heap[child + 1] > heap[child]) {
                child++;
            }

            int tmp = heap[parent];
            heap[parent] = heap[child];
            heap[child] = tmp;

            parent = child;
            child *= 2;
        }

        cout << result << '\n';
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int num, data = 0;

    cin >> num;

    for (int i = 0; i < num; i++) {
        cin >> data;

        if (data == 0) {
            popHeap();
        } else {
            insertMaxHeap(data);
        }
    }
}

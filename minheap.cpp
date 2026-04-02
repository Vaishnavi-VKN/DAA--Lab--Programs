#include <iostream>
#include <vector>
#include <algorithm>

class MinHeap {
private:
    std::vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] < heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            if (smallest != index) {
                std::swap(heap[index], heap[smallest]);
                index = smallest;
            } else {
                break;
            }
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
        return minVal;
    }

    int getMin() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    void printHeap() const {
        for (int val : heap) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    MinHeap mh;
    mh.insert(10);
    mh.insert(20);
    mh.insert(5);
    mh.insert(30);
    mh.insert(15);

    std::cout << "Min Heap: ";
    mh.printHeap();

    std::cout << "Extract Min: " << mh.extractMin() << std::endl;
    std::cout << "Min Heap after extraction: ";
    mh.printHeap();

    return 0;
}
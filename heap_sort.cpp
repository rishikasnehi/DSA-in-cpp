// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int heapsize, int index){
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    
    if(left < heapsize && arr[left] > arr[largest])
        largest = left;
    if(right < heapsize && arr[right] > arr[largest])
        largest = right;
    if (largest != index) {
        swap(arr[index], arr[largest]);
        // Recursively heapify the affected sub-tree
        heapify(arr, heapsize, largest);
    }
}

void heapsort(vector<int> &arr){
    int n = arr.size();
     // Build heap
    for(int i = n/2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    
     // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
    
}

int main() {
    vector<int> arr = { 9, 4, 3, 8, 10, 2, 5 };
    heapsort(arr);
    for(int i : arr)
        cout << i << " ";

    return 0;
}

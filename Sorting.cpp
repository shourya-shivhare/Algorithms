#include<bits/stdc++.h>
using namespace std;

// Bubble sort
// stable sort
// TC : 
//  worst amd avg case : O(N ^ 2)
//  modified : best case : O(N)
void bubbleSort(vector<int>& nums) {
    for(int i = 0;i < 10;i++) {
        for(int j = 0;j < 10 - i - 1;j++) {
            if(nums[j] > nums[j + 1]) {
                swap(nums[j] , nums[j + 1]);
            }
        }
    }
}

// Selection sort
// unstable sort
// TC : O(N ^ 2)
void selectionSort(vector<int>& nums) {
    for(int i = 0;i < 10 - 1;i++) {
        int MIN = i;
        for(int j = i + 1;j < 10;j++) {
            if(nums[MIN] > nums[j]) {
                MIN = j;
            }
        }
        swap(nums[MIN] , nums[i]);
    }
}
 
// Insertion sort
// stable sort
// TC : 
//  avg and worst case : O(N ^ 2)
//  best case : O(N)
void insertionSort(vector<int>& nums) {
    for(int i = 1;i < 10;i++) {
        int key = nums[i];
        int j = i - 1;
        while(j >= 0 && key < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

// Merge sort
void merge(vector<int>& nums , int l , int m , int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1);
    vector<int> right(n2);

    for(int i = 0;i < n1;i++) left[i] = nums[l + i];
    for(int i = 0;i < n2;i++) right[i] = nums[m + i + 1];

    int L = 0;
    int R = 0;
    int k = l;
    while(L < n1 && R < n2) {
        if(left[L] <= right[R]) {
            nums[k] = left[L];
            L++;
        }
        else {
            nums[k] = right[R];
            R++;
        }
        k++;
    }
    while(L < n1) {
        nums[k] = left[L];
        k++;
        L++;
    }
    while(R < n2) {
        nums[k] = right[R];
        k++;
        R++;
    }
}

void mergeSort(vector<int>& nums, int l , int r) {
    if(l < r) {
        int m = l + (r - l) / 2;
        mergeSort(nums , l , m);
        mergeSort(nums , m + 1 , r);
        merge(nums , l , m , r);
    }
}

// Quick sort
int partition(vector<int>& nums , int low , int high) {
    int pivot = nums[high];
    int i = low - 1;
    for(int j = low;j < high;j++) {
        if(pivot > nums[j]) {
            i++;
            swap(nums[i] , nums[j]);
        }
    }
    swap(nums[i + 1] , nums[high]);
    return i + 1;
}

void quickSort(vector<int>& nums , int low , int high) {
    if(low < high) {
        int pi = partition(nums , low , high);
        quickSort(nums , low , pi - 1);
        quickSort(nums , pi + 1 , high);
    }
}

// Heap sort
void heapify(vector<int>& nums ,int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
 
    if(left < n && nums[largest] < nums[left]) {
        largest = left;
    }
    if(right < n && nums[largest] < nums[right]) {
        largest = right;
    }

    if(largest != i) {
        swap(nums[largest] , nums[i]);
        heapify(nums , n , largest);
    }
}

void heapSort(vector<int>& nums) {
    int n = nums.size();

    for(int i = n / 2 - 1;i >= 0;i--) {
        heapify(nums , n , i);
    }

    for(int i = n - 1;i >= 0;i--) {
        swap(nums[0] , nums[i]);
        heapify(nums , i , 0);
    }
}

// Counting sort 
// stable sort
// TC : O(N + k)
void countingSort(vector<int>& nums) {
    int k = INT_MIN;
    for(int i = 0;i < 10;i++) {
        k = max(k , nums[i]);
    }

    // frequency count
    vector<int> count(k + 1 , 0);
    for(int i = 0 ;i < 10;i++) {
        count[nums[i]]++;
    }

    // to get the index
    for(int i = 1;i <= k;i++) {
        count[i] += count[i - 1];
    }

    // to maintain the stability
    vector<int> output(10);
    for(int i = 9;i >= 0;i--) {
        output[--count[nums[i]]] = nums[i]; 
    }

    // copy the elements back to nums    
    for(int i = 0;i < 10;i++) {
        nums[i] = output[i];
    }
}

// Radix sort
// stable sort
// O(d(N + k))
// d = digits of the maximum element 
void CountingSORT(vector<int>& nums , int exp) {
    vector<int> count(10 , 0);
    vector<int> output(10);

    for(int i = 0;i < 10;i++) {
        int digit = (nums[i]/exp) % 10;
        count[digit]++;
    }

    for(int i = 1;i < 10;i++) {
        count[i] += count[i - 1];
    }

    for(int i = 9;i >= 0;i--) {
        int digit = (nums[i] / exp) % 10;
        output[--count[digit]] = nums[i];
    }

    for(int i = 0;i < 10;i++) {
        nums[i] = output[i];
    }
}

void radixSort(vector<int>& nums) {
    int k = INT_MIN;
    for(int i  = 0;i < 10;i++) {
        k = max(k , nums[i]);
    }

    for(int exp = 1;k / exp > 0;exp *= 10) {
        CountingSORT(nums , exp);
    }
}



int main() {
    vector<int> nums = {3,5,3,7,5,3,8,4,1,5};

    for(int i = 0;i < 10;i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    heapSort(nums);

    for(int i = 0;i < 10;i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}
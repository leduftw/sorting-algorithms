#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <functional>
#include <memory>

#include "gap-strategy/gap_strategy.hpp"
#include "gap-strategy/knuth_gap_strategy.hpp"
#include "pivot-strategy/pivot_strategy.hpp"
#include "pivot-strategy/middle_pivot_strategy.hpp"

using namespace std;
using namespace chrono;

/*
    Sorting algorithms that you can find here:
        Selection sort (+ optimized)
        Bubble sort    (+ optimized)
        Insertion sort
        STL sort
        Bogosort
        Mergesort
        Counting sort  (only supports numbers)
        Shellsort
        Quicksort
        Heapsort
*/

template <typename T>
class Sort {

    time_point<high_resolution_clock> start, end;
    int size_of_last_sort;

protected:

    virtual void sort_vector(vector<T>& arr) const = 0;

public:

    Sort() : size_of_last_sort(0) { }

    virtual ~Sort() { }

    void sort(vector<T>& arr) {
        start = high_resolution_clock::now();
        sort_vector(arr);
        end = high_resolution_clock::now();
        size_of_last_sort = arr.size();
    }

    virtual string get_algorithm_name() const = 0;

    friend ostream& operator<<(ostream& os, const Sort& s) {
        // Only for non-empty arrays
        if (s.size_of_last_sort > 0) {
            os << "Array size: " << s.size_of_last_sort << ".\n";
            os << "Sorted in: " << duration_cast<seconds>(s.end - s.start).count() << " seconds.\n";
            os << "Algorithm name: " << s.get_algorithm_name() << "\n";
        }
        return os;
    }

};

template <typename T, class Compare = less<T> >
class SelectionSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~SelectionSort() { }

};

template <typename T, class Compare = less<T> >
class OptimizedSelectionSort : public SelectionSort<T, Compare> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~OptimizedSelectionSort() { }

};

template <typename T, class Compare = less<T> >
class BubbleSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~BubbleSort() { }

};

template <typename T, class Compare = less<T> >
class OptimizedBubbleSort : public BubbleSort<T, Compare> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~OptimizedBubbleSort() { }

};

template <typename T, class Compare = less<T> >
class InsertionSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~InsertionSort() { }

};

template <typename T, class Compare = less<T> >
class STLSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~STLSort() { }

};

template <typename T, class Compare = less<T> >
class BogoSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~BogoSort() { }

};

template <typename T, class Compare = less<T> >
class MergeSort : public Sort<T> {

    static const string algorithm_name;

    void merge_sort(vector<T>& arr, vector<T>& temp, int lo, int hi) const;
    void merge(vector<T>& arr, vector<T>& temp, int lo, int mid, int hi) const;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~MergeSort() { }

};

// Note: Counting sort can only sort numbers
template <class Compare = less<int> >
class CountingSort : public Sort<int> {

    static const string algorithm_name;

    // Elements in array are in range [0..k]
    int k;

protected:

    virtual void sort_vector(vector<int>& arr) const override;

public:

    CountingSort(int limit) : k(limit) { }

    virtual ~CountingSort() { }

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

};

template <typename T, class Compare = less<T> >
class ShellSort : public Sort<T> {

    static const string algorithm_name;

    shared_ptr<GapStrategy> gapStrategy = make_shared<KnuthGapStrategy>();

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    void set_gap_strategy(shared_ptr<GapStrategy> gap_strategy) {
        this->gapStrategy = gap_strategy;
    }

    virtual ~ShellSort() { }

};

template <typename T, class Compare = less<T> >
class QuickSort : public Sort<T> {

    static const string algorithm_name;

    shared_ptr<PivotStrategy<T>> pivot_strategy = make_shared<MiddlePivotStrategy<T>>();

    void quick_sort(vector<T>& arr, int lo, int hi) const;
    int partition(vector<T>& arr, int lo, int hi, T pivot) const;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    void set_pivot_strategy(shared_ptr<PivotStrategy<T>> pivot_strategy) {
        this->pivot_strategy = pivot_strategy;
    }

    virtual ~QuickSort() { }

};

template <typename T, class Compare = less<T> >
class HeapSort : public Sort<T> {

    static const string algorithm_name;

protected:

    virtual void sort_vector(vector<T>& arr) const override;

public:

    virtual string get_algorithm_name() const override {
        return algorithm_name;
    }

    virtual ~HeapSort() { }

};

template <typename T, class Compare>
const string SelectionSort<T, Compare>::algorithm_name = "Selection sort";

template <typename T, class Compare>
const string OptimizedSelectionSort<T, Compare>::algorithm_name = "Optimized selection sort";

template <typename T, class Compare>
const string BubbleSort<T, Compare>::algorithm_name = "Bubble sort";

template <typename T, class Compare>
const string OptimizedBubbleSort<T, Compare>::algorithm_name = "Optimized bubble sort";

template <typename T, class Compare>
const string InsertionSort<T, Compare>::algorithm_name = "Insertion sort";

template <typename T, class Compare>
const string STLSort<T, Compare>::algorithm_name = "STL sort";

template <typename T, class Compare>
const string BogoSort<T, Compare>::algorithm_name = "Bogosort";

template <typename T, class Compare>
const string MergeSort<T, Compare>::algorithm_name = "Mergesort";

template <class Compare>
const string CountingSort<Compare>::algorithm_name = "Counting sort";

template <typename T, class Compare>
const string ShellSort<T, Compare>::algorithm_name = "Shellsort";

template <typename T, class Compare>
const string QuickSort<T, Compare>::algorithm_name = "Quicksort";

template <typename T, class Compare>
const string HeapSort<T, Compare>::algorithm_name = "Heapsort";

template <typename T, class Compare>
void SelectionSort<T, Compare>::sort_vector(vector<T>& arr) const {

    Compare comp;
    int n = (int)arr.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (comp(arr[j], arr[i])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

template <typename T, class Compare>
void OptimizedSelectionSort<T, Compare>::sort_vector(vector<T>& arr) const {
    if (arr.size() == 0) return;

    int n = (int)arr.size();
    Compare comp;

    for (int i = 0; i < n - 1; i++) {
        T min_element = arr[i];
        int min_pos = i;

        for (int j = i + 1; j < n; j++) {
            if (comp(arr[j], min_element)) {
                min_element = arr[j];
                min_pos = j;
            }
        }

        arr[min_pos] = arr[i];
        arr[i] = min_element;
    }
}

template <typename T, class Compare>
void BubbleSort<T, Compare>::sort_vector(vector<T>& arr) const {
    Compare comp;
    int n = (int)arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (comp(arr[j + 1], arr[j])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T, class Compare>
void OptimizedBubbleSort<T, Compare>::sort_vector(vector<T>& arr) const {
    if (arr.size() == 0) return;

    int n = (int)arr.size(), last_change_on = n - 1, bound;
    Compare comp;
    do {
        bound = last_change_on;
        last_change_on = 0;

        for (int i = 0; i < bound; i++) {
            if (comp(arr[i + 1], arr[i])) {
                swap(arr[i], arr[i + 1]);
                last_change_on = i;
            }
        }
    } while (last_change_on != 0);
}

template <typename T, class Compare>
void InsertionSort<T, Compare>::sort_vector(vector<T>& arr) const {
    Compare comp;
    int n = (int)arr.size();

    for (int i = 1; i < n; i++) {
        int j = i - 1;
        T cur = arr[i];

        // Stable
        while (j >= 0 && comp(cur, arr[j])) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = cur;
    }
}

template <typename T, class Compare>
void STLSort<T, Compare>::sort_vector(vector<T>& arr) const {
    sort(arr.begin(), arr.end(), Compare());
}

template <typename T, class Compare>
void BogoSort<T, Compare>::sort_vector(vector<T>& arr) const {
    Compare comp;
    while (!is_sorted(arr.begin(), arr.end(), comp)) {
        random_shuffle(arr.begin(), arr.end());
    }
}

template <typename T, class Compare>
void MergeSort<T, Compare>::sort_vector(vector<T>& arr) const {
    if (arr.size() == 0) return;

    vector<T> temp(arr.size() / 2 + 1);
    merge_sort(arr, temp, 0, arr.size() - 1);
}

template <typename T, class Compare>
void MergeSort<T, Compare>::merge_sort(vector<T>& arr, vector<T>& temp, int lo, int hi) const {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(arr, temp, lo, mid);
    merge_sort(arr, temp, mid + 1, hi);
    merge(arr, temp, lo, mid, hi);
}

template <typename T, class Compare>
void MergeSort<T, Compare>::merge(vector<T>& arr, vector<T>& temp, int lo, int mid, int hi) const {
    // Buffer temp stores left half of arr, while right half can remain in arr, thus reducing additional space by half
    int leftHalfInd = 0, cpyInd = lo, arrInd = lo;

    while (cpyInd <= mid) {
        temp[leftHalfInd++] = arr[cpyInd++];
    }

    Compare comp;
    leftHalfInd = 0;

    // mid + 1
    int rightHalfInd = cpyInd;

    // Stable
    while (arrInd < rightHalfInd && rightHalfInd <= hi) {
        arr[arrInd++] = (!comp(arr[rightHalfInd], temp[leftHalfInd]) ? temp[leftHalfInd++] : arr[rightHalfInd++]);
    }

    while (arrInd < rightHalfInd) {
        arr[arrInd++] = temp[leftHalfInd++];
    }
}

template <class Compare>
void CountingSort<Compare>::sort_vector(vector<int>& arr) const {
    Compare comp;
    bool ascending = comp(0, 1);

    vector<int> count(k + 1, 0);
    int n = count.size();

    for (const int& el : arr) count[el]++;

    int total = 0;
    for (int i = (ascending ? 0 : n - 1); i < n && (!ascending ? i >= 0 : true); (ascending ? i++ : i--)) {
        int temp = count[i];
        count[i] = total;
        total += temp;
    }

    vector<int> sortedArr(arr.size());
    for (const int& el : arr) {
        sortedArr[count[el]] = el;
        count[el]++;  // stable
    }

    copy(sortedArr.begin(), sortedArr.end(), arr.begin());
}

template <typename T, class Compare>
void ShellSort<T, Compare>::sort_vector(vector<T>& arr) const {
    Compare comp;
    vector<int> gaps = gapStrategy->get_gaps(arr.size());
    int n = (int)arr.size();

    for (int gap : gaps) {
        // Do a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            T temp = arr[i];
            int j = i - gap;
            while (j >= 0 && comp(temp, arr[j])) {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = temp;
        }
    }
}

template <typename T, class Compare>
void QuickSort<T, Compare>::sort_vector(vector<T>& arr) const {
    quick_sort(arr, 0, arr.size() - 1);
}

template <typename T, class Compare>
void QuickSort<T, Compare>::quick_sort(vector<T>& arr, int lo, int hi) const {
    if (lo >= hi) return;

    T piv = pivot_strategy->get_pivot(arr, lo, hi);
    int idx = partition(arr, lo, hi, piv);

    quick_sort(arr, lo, idx - 1);
    quick_sort(arr, idx, hi);
}

template <typename T, class Compare>
int QuickSort<T, Compare>::partition(vector<T>& arr, int lo, int hi, T piv) const {
    Compare comp;
    while (lo <= hi) {
        while (comp(arr[lo], piv)) {
            lo++;
        }
        while (comp(piv, arr[hi])) {
            hi--;
        }
        if (lo <= hi) {
            swap(arr[lo], arr[hi]);
            lo++;
            hi--;
        }
    }
    return lo;
}

template <typename T, class Compare>
void HeapSort<T, Compare>::sort_vector(vector<T>& arr) const {
    Compare comp;
    make_heap(arr.begin(), arr.end(), comp);
    sort_heap(arr.begin(), arr.end(), comp);
}

#endif

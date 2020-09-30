#ifndef SORT_H
#define SORT_H

#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
#include <functional>

using namespace std;
using namespace chrono;

/*
	Sorting algorithms that you can find here:
		- Selection sort (+ optimized)
		- Bubble sort    (+ optimized)
		- Insertion sort
		- STL sort
		- Bogosort
		- Mergesort
		- Counting sort  (supports numbers only)

		TODO:
		- Shellsort
		- Heapsort
		- Quicksort
*/

template <typename T>
class Sort {

	time_point<high_resolution_clock> start, end;
	size_t sizeOfLastSort;

protected:

	virtual void sortVector(vector<T> &arr) const = 0;

public:

	Sort() : sizeOfLastSort(0) { }

	void sort(vector<T> &arr) {
		start = high_resolution_clock::now();
		sortVector(arr);
		end = high_resolution_clock::now();
		sizeOfLastSort = arr.size();
	}

	virtual string getAlgorithmName() const = 0;

	friend ostream& operator<<(ostream &os, const Sort &s) {
		if (s.sizeOfLastSort > 0) {  // only for non-empty arrays
			os << "Array size: " << s.sizeOfLastSort << ".\n";
			os << "Sorted in: " << duration_cast<seconds>(s.end - s.start).count() << " seconds.\n";
			os << "Algorithm name: " << s.getAlgorithmName() << "\n";
		}
		return os;
	}

};

template <typename T, class Compare = less<T> >
class SelectionSort : public Sort<T> {

	static const string algorithmName;

	vector<int> gaps;

	GapsStrategy *gapsStrategy;

protected:

	/*
		Takes around 55 seconds for vector with 10k elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class OptimizedSelectionSort : public SelectionSort<T, Compare> {

	static const string algorithmName;

protected:

	/*
		Takes around 15 seconds for vector with 10k elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class BubbleSort : public Sort<T> {

	static const string algorithmName;

protected:

	/*
		Takes around 85 seconds for vector with 10k elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class OptimizedBubbleSort : public BubbleSort<T, Compare> {

	static const string algorithmName;

protected:

	/*
		Takes around 35 seconds for vector with 10k elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class InsertionSort : public Sort<T> {

	static const string algorithmName;

protected:

	/*
		Takes around 25 seconds for vector with 10k elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class STLSort : public Sort<T> {

	static const string algorithmName;

protected:

	/*
		Takes 2 seconds for vector with 1m elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class BogoSort : public Sort<T> {

	static const string algorithmName;

protected:

	/*
		One time BogoSort took 9 seconds for vector with 10 elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class MergeSort : public Sort<T> {

	static const string algorithmName;

	void mergeSort(vector<T> &arr, vector<T> &temp, size_t lo, size_t hi) const;
	void merge(vector<T> &arr, vector<T> &temp, size_t lo, size_t mid, size_t hi) const;

protected:

	/*
		Takes 22 seconds for vector with 1m elements.
	*/
	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

/*
	Counting sort can only sort numbers.
*/
template <class Compare = less<int> >
class CountingSort : public Sort<int> {

	static const string algorithmName;

	size_t k;  // elements in array are in range [0..k]

protected:

	/*
		Takes 1 second for vector with 1m elements.
	*/
	virtual void sortVector(vector<int> &arr) const override;

public:

	CountingSort(size_t limit) : k(limit) { }

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare = less<T> >
class ShellSort : public Sort<T> {

	static const string algorithmName;

protected:

	virtual void sortVector(vector<T> &arr) const override;

public:

	virtual string getAlgorithmName() const override {
		return algorithmName;
	}

};

template <typename T, class Compare>
const string SelectionSort<T, Compare>::algorithmName = "Selection sort";

template <typename T, class Compare>
const string OptimizedSelectionSort<T, Compare>::algorithmName = "Optimized selection sort";

template <typename T, class Compare>
const string BubbleSort<T, Compare>::algorithmName = "Bubble sort";

template <typename T, class Compare>
const string OptimizedBubbleSort<T, Compare>::algorithmName = "Optimized bubble sort";

template <typename T, class Compare>
const string InsertionSort<T, Compare>::algorithmName = "Insertion sort";

template <typename T, class Compare>
const string STLSort<T, Compare>::algorithmName = "STL sort";

template <typename T, class Compare>
const string BogoSort<T, Compare>::algorithmName = "Bogosort";

template <typename T, class Compare>
const string MergeSort<T, Compare>::algorithmName = "Mergesort";

template <class Compare>
const string CountingSort<Compare>::algorithmName = "Counting sort";

template <typename T, class Compare>
const string ShellSort<T, Compare>::algorithmName = "Shellsort";

template <typename T, class Compare>
void SelectionSort<T, Compare>::sortVector(vector<T> &arr) const {

	Compare comp;

	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = i + 1; j < arr.size(); j++) {
			if (comp(arr[j], arr[i])) {
				swap(arr[i], arr[j]);
			}
		}
	}
}

template <typename T, class Compare>
void OptimizedSelectionSort<T, Compare>::sortVector(vector<T> &arr) const {
	if (arr.size() == 0) return;

	size_t n = arr.size();
	Compare comp;

	for (size_t i = 0; i < n - 1; i++) {
		T minElement = arr[i];
		size_t minPos = i;

		for (size_t j = i + 1; j < n; j++) {
			if (comp(arr[j], minElement)) {
				minElement = arr[j];
				minPos = j;
			}
		}

		arr[minPos] = arr[i];
		arr[i] = minElement;
	}
}

template <typename T, class Compare>
void BubbleSort<T, Compare>::sortVector(vector<T> &arr) const {
	Compare comp;
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = 0; j < arr.size() - 1; j++) {
			if (comp(arr[j + 1], arr[j])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

template <typename T, class Compare>
void OptimizedBubbleSort<T, Compare>::sortVector(vector<T> &arr) const {
	if (arr.size() == 0) return;

	size_t n = arr.size(), lastChangeOn = n - 1, bound;
	Compare comp;
	do {
		bound = lastChangeOn;
		lastChangeOn = 0;  // change detection

		for (size_t i = 0; i < bound; i++) {
			if (comp(arr[i + 1], arr[i])) {
				swap(arr[i], arr[i + 1]);
				lastChangeOn = i;
			}
		}
	} while (lastChangeOn != 0);
}

template <typename T, class Compare>
void InsertionSort<T, Compare>::sortVector(vector<T> &arr) const {
	Compare comp;

	for (size_t i = 1; i < arr.size(); i++) {
		size_t j = i - 1;
		T cur = arr[i];

		while (j >= 0 && j < arr.size() && comp(cur, arr[j])) {  // stable
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = cur;
	}
}

template <typename T, class Compare>
void STLSort<T, Compare>::sortVector(vector<T> &arr) const {
	sort(arr.begin(), arr.end(), Compare());
}

template <typename T, class Compare>
void BogoSort<T, Compare>::sortVector(vector<T> &arr) const {
	Compare comp;
	while (!is_sorted(arr.begin(), arr.end(), comp)) {
		random_shuffle(arr.begin(), arr.end());
	}
}

template <typename T, class Compare>
void MergeSort<T, Compare>::sortVector(vector<T> &arr) const {
	if (arr.size() == 0) return;

	vector<T> temp(arr.size() / 2 + 1);
	mergeSort(arr, temp, 0, arr.size() - 1);
}

template <typename T, class Compare>
void MergeSort<T, Compare>::mergeSort(vector<T> &arr, vector<T> &temp, size_t lo, size_t hi) const {
	if (hi <= lo) return;
	size_t mid = lo + (hi - lo) / 2;
	mergeSort(arr, temp, lo, mid);
	mergeSort(arr, temp, mid + 1, hi);
	merge(arr, temp, lo, mid, hi);
}

template <typename T, class Compare>
void MergeSort<T, Compare>::merge(vector<T> &arr, vector<T> &temp, size_t lo, size_t mid, size_t hi) const {
	// temp stores left half of arr, while right half can remain in arr, thus reducing additional space by half
	size_t leftHalfInd = 0, cpyInd = lo, arrInd = lo;
	while (cpyInd <= mid) temp[leftHalfInd++] = arr[cpyInd++];

	Compare comp;
	leftHalfInd = 0;
	size_t rightHalfInd = cpyInd;  // mid + 1

	while (arrInd < rightHalfInd && rightHalfInd <= hi) arr[arrInd++] = (!comp(arr[rightHalfInd], temp[leftHalfInd]) ? temp[leftHalfInd++] : arr[rightHalfInd++]);  // stable
	while (arrInd < rightHalfInd) arr[arrInd++] = temp[leftHalfInd++];
}

template <class Compare>
void CountingSort<Compare>::sortVector(vector<int> &arr) const {
	Compare comp;
	bool ascending = comp(0, 1);

	vector<int> count(k + 1, 0);
	size_t n = count.size();

	for (const int &el : arr) count[el]++;

	size_t total = 0;
	for (size_t i = (ascending ? 0 : n - 1); i < n && (!ascending ? i >= 0 : true); (ascending ? i++ : i--)) {
		int temp = count[i];
		count[i] = total;
		total += temp;
	}

	vector<int> sortedArr(arr.size());
	for (const int &el : arr) {
		sortedArr[count[el]] = el;
		count[el]++;  // stable
	}

	copy(sortedArr.begin(), sortedArr.end(), arr.begin());
}

template <typename T, class Compare>
void ShellSort<T, Compare>::sortVector(vector<T> &arr) const {
	


}

#endif

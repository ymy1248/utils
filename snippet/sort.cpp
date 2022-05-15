#include <gtest/gtest.h>
#include <vector>

using namespace std;

template<typename Array>
void quickSort(Array &arr, size_t lo, size_t hi)
{
    if (lo >= hi) return;
    int64_t l = lo - 1, h = hi + 1;
    auto pivot = arr[(lo + hi) >> 1];
    while (l < h) {
        do l++; while (l <= hi && arr[l] < pivot);
        do h--; while (h > lo && arr[h] > pivot);
        if (l < h) swap(arr[l], arr[h]);
    }
    quickSort(arr, lo, h);
    quickSort(arr, h + 1, hi);
}

template<typename Array>
void mergeSort(Array &arr, size_t lo, size_t hi, Array &tmp)
{
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    mergeSort(arr, lo, mid, tmp);
    mergeSort(arr, mid + 1, hi, tmp);
    int lhs = lo, rhs = mid + 1, i = lo;
    while (lhs <= mid && rhs <= hi) {
        if (arr[lhs] <= arr[rhs]) tmp[i++] = arr[lhs++];
        else tmp[i++] = arr[rhs++];
    }
    while (lhs <= mid) tmp[i++] = arr[lhs++];
    while (rhs <= hi) tmp[i++] = arr[rhs++];
    for (i = lo; i <= hi; ++i) arr[i] = tmp[i];
}

template<typename Array>
void quickSort(Array &arr)
{
    quickSort(arr, 0, arr.size() - 1);
}

template<typename Array>
void mergeSort(Array &arr)
{
    auto tmp = arr;
    mergeSort(arr, 0, arr.size() - 1, tmp);
}

TEST(quick_sort, test_name) 
{
    vector<int> data = {4,3,2,1};
    quickSort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
    EXPECT_EQ(data[3], 4);
}

TEST(merge_sort, test_name) 
{
    vector<int> data = {4,3,2,1};
    mergeSort(data);
    EXPECT_EQ(data[0], 1);
    EXPECT_EQ(data[1], 2);
    EXPECT_EQ(data[2], 3);
    EXPECT_EQ(data[3], 4);
}
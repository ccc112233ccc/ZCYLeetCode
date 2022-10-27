#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace InsertSort
{
    //插入排序，最差复杂度N2,最好复杂度N
    void sort(vector<int> &nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--)
            {
                swap(nums[j], nums[j + 1]);
            }
        }
    }
} // InsertSort
namespace MergeSort
{
    //用于统计求解小和问题的变量
    int smallSum = 0;
    //用于统计求解逆序对问题的变量
    int reversePair = 0;
    void merge(vector<int> &nums, int L, int M, int R)
    {
        vector<int> temp;
        temp.reserve(R - L + 1);
        int p1 = L;
        int p2 = M + 1;
        while (p1 <= M && p2 <= R)
        {
            smallSum += nums[p1] < nums[p2] ? nums[p1] * (R - p2 + 1) : 0;
            reversePair += nums[p1] < nums[p2] ? (R - p2 + 1) : 0;
            temp.push_back(nums[p1] < nums[p2] ? nums[p1++] : nums[p2++]);
        }
        while (p1 <= M)
        {
            temp.push_back(nums[p1++]);
        }
        while (p2 <= R)
        {
            temp.push_back(nums[p2++]);
        }
        for (int i = 0; i < temp.size(); i++)
        {
            nums[L + i] = temp[i];
        }
    }
    void process(vector<int> &nums, int L, int R)
    {
        if (L == R)
            return;
        int mid = (R - L) / 2 + L;
        process(nums, L, mid);
        process(nums, mid + 1, R);
        merge(nums, L, mid, R);
    }

    void sort(vector<int> &nums)
    {
        process(nums, 0, nums.size() - 1);
    }
} // MeregSort

namespace QuickSort
{
    //使用num对数组做分割，并且返回左边小区和右边大区的边界
    vector<int> partition(vector<int> &nums, int L, int R, int num)
    {
        int small = L - 1;
        int big = R + 1;
        int i = L;
        while (i < big)
        {
            if (nums[i] < num)
            {
                swap(nums[i], nums[small + 1]);
                small++;
                i++;
            }
            else if (nums[i] == num)
            {
                i++;
            }
            else
            {
                swap(nums[i], nums[big - 1]);
                big--;
            }
        }
        return {small, big};
    }
    //对数组的L和R中间的内容做排序
    void process(vector<int> &nums, int L, int R)
    {

        if (L >= R)
            return;
        //随机选择一个数据做分割，这样可以保证其在概率上平均时间复杂度为NlogN
        srand(time(0));
        int rd = rand() % (R - L + 1) + L;
        vector<int> temp = partition(nums, L, R, nums[rd]);
        int small = temp[0];
        int big = temp[1];
        //对左边进行排序
        process(nums, L, small);
        //对右边进行排序
        process(nums, big, R);
    }
    void sort(vector<int> &nums)
    {
        process(nums, 0, nums.size() - 1);
    }

} // QuickSort

namespace HeapSort
{
    // heapInsert过程，将所给的位置的数，如果其比父节点大则往上移动
    void heapInsert(vector<int> nums, int index)
    {
        //如果当前数比父亲节点大，则循环，直到比它小或者到了根部，此时index = 0,(index -1)/2 = 0,条件不满足也会结束循环
        while (nums[index] > nums[(index - 1) / 2])
        {
            swap(nums[index], nums[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    //当一个大根堆的某个节点被替换掉时候，将其重新变成大根堆的过程
    void heapify(vector<int> nums, int index, int heapSize)
    {
        int left = index * 2 + 1; //其左孩子的节点

        //如果其有左孩子则开始循环
        while (left < heapSize)
        {
            //先找到左右孩子当中最大的那一个
            int biggest = (nums[left] < nums[left + 1]) && (left + 1 < heapSize) ? (left + 1) : left;
            if (nums[biggest] <= nums[index])
            {
                break;
            }
        }
    }

} // HeapSort
//打印数组
void printVec(const vector<int> &nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << "\n";
}

int main()
{
    vector<int> nums = {6, 3, 5, 2, 3, 4};
    for (int i = 0; i < nums.size(); i++)
    {
        HeapSort::heapInsert(nums, i);
    }
    printVec(nums);
    return 0;
}

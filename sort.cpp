#include <iostream>
#include <string>
#include <vector>
using namespace std;

namespace MergeSort
{
    int smallSum = 0;
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
    void process(vector<int> &nums, int L, int R)
    {

        if (L >= R)
            return;
        srand(time(0));
        int rd = rand() % (R - L + 1) + L;
        vector<int> temp = partition(nums, L, R, nums[rd]);
        int small = temp[0];
        int big = temp[1];
        process(nums, L, small);
        process(nums, big, R);
    }
    void sort(vector<int> &nums)
    {
        process(nums, 0, nums.size() - 1);
    }

} // QuickSort

void printVec(vector<int> &nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << "\n";
}
void printVec(vector<int> &&nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << "\n";
}
int main()
{
    vector<int> nums = {3, 3, 3, 3, 1, 1, 1};
    QuickSort::sort(nums);
    printVec(nums);
    return 0;
}

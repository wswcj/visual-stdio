#include<iostream>
#include<vector>
using namespace std;
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target)
            {
                right = middle;
            }
            else if (nums[middle] < target)
            {
                left = middle + 1;
            }
            else
            {
                return middle;
            }
        }
        return right;
    }
};
void test1()
{
    Solution1 S1;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(7);
    v1.push_back(10);
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    int target = 0;
    cin >> target;
    int ret = S1.searchInsert(v1, target);
    cout << ret << endl;
}
void test2()
{
    cout << INT_MAX << endl;
    cout << INT32_MAX << endl;
    int ret = (int)min(1, 2);
    cout << ret << endl;
}
void test3()
{
    vector<int> v1(10, 0);
    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << endl;
    }
}
int main()
{
    //test1();
    //test2();
    test3();
	return 0;
}
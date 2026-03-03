//
// Created by dayub on 2026/3/3.
//
// create a dynamic array
// 不用显式的指定数组大小，它会根据实际存储的元素数量自动扩缩容
verctor<int> arr;

for (int i = 0; i < 10; i++)
{
    // 在末尾添加元素，时间复杂度O(1)
    arr.push_back(i);
}

// 在中间插入元素，时间复杂度O(N)
// 在索引2的位置插入元素666
arr.insert(arr.begin()+2,666);

// 在头部插入元素，时间复杂度O(N)
arr.insert(arr.begin(), -1);

// 删除末尾元素，时间复杂度O(1)
arr.pop_back();

// 删除中间元素，时间复杂度O(N)
// 删除索引2的元素
arr.erase(arr.begin()+2);

// 根据索引查询元素，时间复杂度O(1)
int a = arr[0];

// 根据索引修改元素，时间复杂度O(1)
arr[0] = 10;

// 根据元素查找索引，时间复杂度 O(N)
int index = find(arr.begin(),arr.end(), 666) - arr.begin();
/**
 * 折半查找的前提条件：被查找的整数集有序排列
 * 折半查找的两个子任务：1.确定是否存在还没有检查过整数
 * 2.将被查找数x与存储的数组的array[middle]进行比较
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/**
 * 找到x，则返回相应的数组下标，否则返回-1
 */
int binarySearch(int *array, const int x, const int count) {

	int left = 0, right = count-1;
	int middle = 0;
	while (left <= right) {
		middle = (left + right) / 2;
		if(array[middle] > x) {
			right = middle - 1;
		} else if(array[middle] < x) {
			left = middle + 1;
		} else {
			// array[middle] == x
			return middle;
		}
	}

	return -1;
}

int main() {

	int array[] = {-3,0,1,2,5,6,10,14,18,20};

	cout << "array: ";
	for(int i=0; i<10; i++) {
		cout << array[i] << "  ";
	}
	cout << endl;

	int x, result;
	while (true){
		cout << "请输入想要查找的数: ";
		cin >> x;
		
		result = binarySearch(array, x, 10);
		if(result != -1) {
			cout << "找到了，为第 " << result + 1 << " 个数: " << array[result] << endl;
			break;
		} else {
			cout << "未找到！" << endl;
		}
	}
		
}

/**
 * 本程序是递归版的二分查找，非递归版本的是程序p1_10.cpp
 */

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


/**
 * 返回-1，代表没有找到
 */
int binarySearch(int *array, const int x, const int left, const int right) {

	if(left <= right ) {

	    int middle = (left + right) / 2;
		
		if(array[middle] == x) {
			return middle;
		} else if(array[middle] > x) {
			return binarySearch(array, x, left, middle-1);
		} else {
			// array[middle] < x
			return binarySearch(array, x, middle + 1, right);
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

	int x, result, left = 0, right = 9;
	while (true){
		cout << "请输入想要查找的数: ";
		cin >> x;

		result = binarySearch(array, x, left, right);
		if(result != -1) {
			cout << "找到了，为第 " << result + 1 << " 个数: " << array[result] << endl;
			break;
		} else {
			cout << "未找到！" << endl;
		}
	}
		
}

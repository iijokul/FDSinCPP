/**
 *选择排序算法的思想：从当前未排序的整数中找一个最小的整数，并将它放到已排序的
 *整数列表中的合适位置
 *划分子任务：1.寻找最小整数  2.最寻找最小整数在已排序中的位置
 */

#include <iostream>
using std::cout;
using std::endl;

//这里是按从小到大排序
void selectSort(int *array, int count) {
	
	for(int i=0; i<count; i++) {
		int k = i;
		for(int j=i+1; j<count; j++) {
			if(array[j] < array[k]) {
				k = j;
			}
		}

		if(k != i) {
			int temp = array[i];
			array[i] = array[k];
			array[k] = temp;
		}
	}
}

int main() {
	int *array = new int[5];
	array[0] = 2;
	array[1] = 1;
	array[2] = 5;
	array[3] = -2;
	array[4] = -3;

	cout << "排序前 :";
	for(int i=0; i<5; i++) {
		cout << array[i] << "  ";
	}
	cout << endl;

	//调用选择排序算法
	selectSort(array,5);

	cout << "排序后 :";
	for(int i=0; i<5; i++) {
		cout << array[i] << "  ";
	}
	cout << endl;

	delete []array;
}

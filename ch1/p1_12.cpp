/**
 * 集合(a,b,c)的所有排列由下面的排列组成
 * 1. 以a开头后面跟着(b,c)的所有排列
 * 2. 以b开头后面跟着(a,c)的所有排列
 * 3. 以c开头后面跟着(a,b)的所有排列
 * 上述的“后面跟着...的所有排列”给出了一种递归思路。意味着如果可以解决n-1个元素集合的所有排列问题，就能够解决n个元素集合的所有排列问题
 */

#include <iostream>

using std::cout;
using std::endl;

void permutations(char *array, const int n, const int m) {

	if(n == m) {
		for(int i=0; i<m; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	} else {
		char temp;
		for(int j=n; j<m; j++) {
			
			temp = array[n];
			array[n] = array[j];
			array[j] = temp;

			permutations(array, n+1, m);

			temp = array[n];
			array[n] = array[j];
			array[j] = temp;
		}
	}
}

int main() {
	
	char array[] = {'a','b','c','d'};

	int n = 0, m = 4;

	permutations(array, n, m);
	
	return 0;
}

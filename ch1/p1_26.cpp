/**
 * 魔方：一个有1~n^2个整数元素构成的nxn的矩阵，其中每一行，每一列和对角线的元素之和都相等。

 * 1. 当n为奇数时，H.Coxeter给出了如下产生这种魔方的简单规则：
 *   1.1. 在魔方第一行的中间放一个1，从这个位置开始，向左上方（左上45度）移动，并按递增（每次加1）顺序将数字填入相应的空格。
 *   1.2. 如果移除了魔方边界，则将魔方想象成一个上下边，左右边对接的圆桶，并继续移动对应方格中。
 *   1.3. 如果方格已有数字，则向下继续寻找方格并填写数字。

 *   如 3 x 3阶魔方
 *   6 1 8
 *   7 5 3
 *   2 9 4
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void magicForOdd(const int n)
{
	int matrix[n][n];

	//初始化
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			matrix[i][j] = 0;
		}
	}

	//给数字1找个位置
	int row = 0, col = n/2;
	matrix[row][col] = 1;

	int key = 2;
	int tRow = 0, tCol = 0;
	// int count = 0;
    // do {
	// 	tCol = col;
	// 	(row-1) < 0 ? (row = n-1) : (row -= 1);
	// 	(col-1) < 0 ? (col = n-1) : (col -= 1);

	// 	count = 0;
	// 	//最多两次就能找到
	// 	while(matrix[row][col] != 0) {
	// 		(row+1) > n-1 ? (row = 0) : (row += 1);
	// 		col = tCol;
			
	// 		count++;
	// 	}
	// 	if(count > 0 ) {
	// 		cout << "---count---: " << count << endl;			
	// 	}

	// 	matrix[row][col] = key;
	// 	++key;
	// }while(key <= n*n);

	while (key <= n*n) {
		
		(row-1 < 0) ? (tRow = n-1) : (tRow = row - 1);
		(col-1 < 0) ? (tCol = n-1) : (tCol = col - 1);
		
		if(matrix[tRow][tCol] == 0 ) {
			row = tRow;
			col = tCol;
		} else {
			row = (row+1) % n ;
		}
		
	    matrix[row][col] = key;
		key++;
	} 
	

	cout << n << " 阶 魔方如下：" << endl;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << matrix[i][j] << "  ";
		}

		cout << endl;
	}

	
}

int main()
{
	int n;
	cout << "请输入魔方的阶数：";
	cin >> n;

	if( n % 2 == 0 ) {
		cout << "请输入奇数" << endl;
	} else {
		magicForOdd(n);
	}

	return 0;
	
}

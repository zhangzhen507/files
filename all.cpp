//Exam01

#if 1

//please use language c++ to compile the code
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define N 4
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP    3

int tot = 0, score = 0;
int mat[4][4];
int mat2[4][4], direction;

void output(int(*mat)[4]) {
	for (register int i = 0; i < 4; i++){
		for (register int j = 0; j < 4; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

void rand_put(int(*mat)[4])
{
	int x, y;
	int flag = 0;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if (mat[i][j] == 0)
				flag = 1;
	if (flag == 0) { tot += 100000; return; }

	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (mat[x][y] != 0);

	mat[x][y] = 2;
	return;
}

void copy(int(*mat)[4], int(*mat2)[4])
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			mat2[i][j] = mat[i][j];
}

int iterX[4] = {0, 1, 0, -1};
int iterY[4] = {-1, 0, 1, 0};

void swap(int & a, int & b){
	if (&a == &b) return;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void move(int direction, int(*mat)[4])
{
	/*
	the code will be hide untill test
	the game rules follow the popular game 2048
	direction 0,1,2,3 means ← ↓ → ↑
	if you merge two same cells , you will get score as the sum of their numbers.
	such as
	0 0 0 0
	0 2 2 0
	0 0 0 2
	0 0 0 0
	if you push ←
	you will get 4 points and now the grids are
	0 0 0 0
	4 0 0 0
	2 0 0 0
	0 0 0 0
	*/
	int d = direction;
	int i, j, k, l, tmp1, tmp2;
	
	if (d == LEFT) {
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4; ) {
				tmp1 = tmp2 = 0;
				for (k = j; k < 4; k++) {
					if (mat[i][k] == 0) continue;
					tmp1 = mat[i][k];
					mat[i][k] = 0;
					for (l = k+1; l < 4; l++){
						if (mat[i][l] == 0) continue;
						tmp2 = mat[i][l];
						mat[i][l] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					j++;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					j++;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					score += mat[i][j];
					j++;
				}
				else {
					mat[i][j] = tmp1;
					if (j + 1 < 4) {
						mat[i][j + 1] = tmp2;
						j++;
					}
					else{
						j++;
					}
				}
			}
		}
	}
	else if (d == RIGHT) {
		for (i = 0; i < 4; i++){
			for (j = 3; j >= 1; ) {
				tmp1 = tmp2 = 0;
				for (k = j; k >= 0; k--) {
					if (mat[i][k] == 0) continue;
					tmp1 = mat[i][k];
					mat[i][k] = 0;
					for (l = k-1; l >= 0; l--){
						if (mat[i][l] == 0) continue;
						tmp2 = mat[i][l];
						mat[i][l] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					j--;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					j--;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					score += mat[i][j];
					j--;
				}
				else {
					mat[i][j] = tmp1;
					if (j - 1 >= 0) {
						mat[i][j - 1] = tmp2;
						j--;
					}
					else{
						j--;
					}
				}
			}
		}
	}
	else if (d == UP) {
		for (j = 0; j < 4; j++){
			for (i = 0; i < 4;) {
				tmp1 = tmp2 = 0;
				for (k = i; k < 4; k++) {
					if (mat[k][j] == 0) continue;
					tmp1 = mat[k][j];
					mat[k][j] = 0;
					for (l = k + 1; l < 4; l++){
						if (mat[l][j] == 0) continue;
						tmp2 = mat[l][j];
						mat[l][j] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					i++;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					i++;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					score += mat[i][j];
					i++;
				}
				else {
					mat[i][j] = tmp1;
					if (i + 1 < 4) {
						mat[i+1][j] = tmp2;
						i++;
					}
					else{
						i++;
					}
				}
			}
		}

	}
	else //d == DOWN
	{
		for (j = 0; j < 4; j++){
			for (i = 3; i >= 0;) {
				tmp1 = tmp2 = 0;
				for (k = i; k >= 0; k--) {
					if (mat[k][j] == 0) continue;
					tmp1 = mat[k][j];
					mat[k][j] = 0;
					for (l = k - 1; l >= 0; l--){
						if (mat[l][j] == 0) continue;
						tmp2 = mat[l][j];
						mat[l][j] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					i--;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					i--;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					score += mat[i][j];
					i--;
				}
				else {
					mat[i][j] = tmp1;
					if (i - 1 >= 0) {
						mat[i - 1][j] = tmp2;
						i--;
					}
					else{
						i--;
					}
				}
			}
		}

	}
}

//**************************your code***********************************// 
int move2(int direction, int(*mat)[4])
{
	int s = 0;
	int d = direction;
	int i, j, k, l, tmp1, tmp2;

	if (d == LEFT) {
		for (i = 0; i < 4; i++){
			for (j = 0; j < 4;) {
				tmp1 = tmp2 = 0;
				for (k = j; k < 4; k++) {
					if (mat[i][k] == 0) continue;
					tmp1 = mat[i][k];
					mat[i][k] = 0;
					for (l = k + 1; l < 4; l++){
						if (mat[i][l] == 0) continue;
						tmp2 = mat[i][l];
						mat[i][l] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					j++;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					j++;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					s += mat[i][j];
					j++;
				}
				else {
					mat[i][j] = tmp1;
					if (j + 1 < 4) {
						mat[i][j + 1] = tmp2;
						j++;
					}
					else{
						j++;
					}
				}
			}
		}
	}
	else if (d == RIGHT) {
		for (i = 0; i < 4; i++){
			for (j = 3; j >= 1;) {
				tmp1 = tmp2 = 0;
				for (k = j; k >= 0; k--) {
					if (mat[i][k] == 0) continue;
					tmp1 = mat[i][k];
					mat[i][k] = 0;
					for (l = k - 1; l >= 0; l--){
						if (mat[i][l] == 0) continue;
						tmp2 = mat[i][l];
						mat[i][l] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					j--;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					j--;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					s += mat[i][j];
					j--;
				}
				else {
					mat[i][j] = tmp1;
					if (j - 1 >= 0) {
						mat[i][j - 1] = tmp2;
						j--;
					}
					else{
						j--;
					}
				}
			}
		}
	}
	else if (d == UP) {
		for (j = 0; j < 4; j++){
			for (i = 0; i < 4;) {
				tmp1 = tmp2 = 0;
				for (k = i; k < 4; k++) {
					if (mat[k][j] == 0) continue;
					tmp1 = mat[k][j];
					mat[k][j] = 0;
					for (l = k + 1; l < 4; l++){
						if (mat[l][j] == 0) continue;
						tmp2 = mat[l][j];
						mat[l][j] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					i++;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					i++;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					s += mat[i][j];
					i++;
				}
				else {
					mat[i][j] = tmp1;
					if (i + 1 < 4) {
						mat[i + 1][j] = tmp2;
						i++;
					}
					else{
						i++;
					}
				}
			}
		}

	}
	else //d == DOWN
	{
		for (j = 0; j < 4; j++){
			for (i = 3; i >= 0;) {
				tmp1 = tmp2 = 0;
				for (k = i; k >= 0; k--) {
					if (mat[k][j] == 0) continue;
					tmp1 = mat[k][j];
					mat[k][j] = 0;
					for (l = k - 1; l >= 0; l--){
						if (mat[l][j] == 0) continue;
						tmp2 = mat[l][j];
						mat[l][j] = 0;
						break;
					}
					break;
				}
				if (tmp1 == 0) {
					mat[i][j] = 0;
					i--;
				}
				else if (tmp2 == 0) {
					mat[i][j] = tmp1;
					i--;
				}
				else if (tmp2 == tmp1) {
					mat[i][j] = tmp1 + tmp2;
					s += mat[i][j];
					i--;
				}
				else {
					mat[i][j] = tmp1;
					if (i - 1 >= 0) {
						mat[i - 1][j] = tmp2;
						i--;
					}
					else{
						i--;
					}
				}
			}
		}
	}
	return s;
}

//int depth = 5;
//double dfs(int mat[4][4], int dep, int turn)
//{
//	if (dep == 0) return 0;
//	int temp[4][4];
//	if (turn == 2)
//	{
//		double best = 0;
//		double sum = 0;
//		int num = 0;
//		for (int i = 0; i < 4; i++) {
//			for (int j = 0; j < 4; j++) {
//				if (mat[i][j] == 0)
//				{
//					copy(mat, temp);
//					temp[i][j] = 2;
//					num++;
//					sum += dfs(temp, dep - 1, 1);
//				}
//			}
//		}
//		if (num == 0) best = 0;
//		else best = sum / num;
//		return best;
//	}
//	else
//	{
//		double best = 0;
//		int dir = 0;
//		int fx[4] = { 0, 2, 1, 3 };
//		for (int j = 0; j <= 3; j++)
//		{
//			int i = fx[j];
//			copy(mat, temp);
//			double tt = move2(i, temp);
//			if (double ans = tt + dfs(temp, dep - 1, 2) > best)
//			{
//				best = ans;
//				dir = i;
//			}
//		}
//		if (dep == depth) return dir;
//		else return best;
//	}
//}


int depth = 3;

int dfsstep(int mat[4][4], int dep, double & max);

double genPoint(int mat[4][4], int dep) {
	int tmp[4][4];
	int num = 0;
	double sum = 0, score = 0;
	
	if (dep == 0) return 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++){
			if (mat[i][j] == 0) {
				copy(mat, tmp);
				tmp[i][j] = 2;
				num++;
				double s = 0;
				dfsstep(tmp, dep - 1, s);
				sum += s;
			}
		}
	}

	if (num > 0) {
		score = sum / num;
	}
	return score;
}

int dfsstep(int mat[4][4], int dep, double & max) {
	if (dep == 0) {
		return 0;
	}
	int tmp[4][4];
	double sum = 0;
	
	int dir = 0;
	int fx[4] = { 0, 2, 1, 3 };
	for (int i = 0; i < 4; i++) {
		int d = fx[i];
		copy(mat, tmp);
		double s = move2(d, tmp);
		sum = s + genPoint(tmp, dep);
		if (sum > max) {
			max = sum;
			dir = d;
		}
	}
	return dir;
}

int num = 0;
void get_command(int &direction, int(*mat)[4])
{
	double max = 0;
	direction = dfsstep(mat, depth, max);
	return;
}





//**********************************************************************//
int main()
{
	//freopen("output.txt", "w", stdout);

	srand(0); //the seed will be changed

	int dir[4] = { 0, 1, 2, 3 }; int j = 0;

	for (int i = 1; i <= 10 && (clock() + 0.0) / CLOCKS_PER_SEC <= 20; i++)
	{
		tot = 0;
		memset(mat, 0, sizeof(mat));

		while (tot < 100000 && (clock() + 0.0) / CLOCKS_PER_SEC <= 20)
		{
			rand_put(mat);//随机在0的位置赋值2

			//printf("Src: \n");
			//output(mat);

			copy(mat, mat2);
			get_command(direction, mat2);

			//direction = dir[(j++)%4];

			move(direction, mat);

			//printf("move direction: %d\n", direction);
			//output(mat);
			//printf("\n");

			tot++;
		}
		//printf("i=%d, tot=%d\n", i, tot);
	}
	//cout << tot << endl;
	cout << score << endl;
	scanf("%d", &tot);
}

#endif


#if 0
/*
决策时间很有限，平均每一把能玩大概8000分，就算是不错的算法了，这里给出一个容易写的思路：
dfs的过程中，计算后续3步能够获得的期望分数是多少，也就是所有情况得分的平均值了，实际上dfs的层数越多肯定效果会越好，但是由于时间有限，3步已经是极限时间了。
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define N 4
using namespace std;
int tot = 0, score = 0;
int mat[4][4];
int mat2[4][4], direction = 2;
void rand_put(int(*mat)[4])
{
	int x, y;
	int flag = 0;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			if (mat[i][j] == 0)
				flag = 1;
	if (flag == 0) { tot += 100000; return; }

	do
	{
		x = rand() % 4;
		y = rand() % 4;
	} while (mat[x][y] != 0);

	mat[x][y] = 2;
	return;
}

void copy(int(*mat)[4], int(*mat2)[4])
{
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			mat2[i][j] = mat[i][j];
}

void rotate(int(*mat)[4])
{
	int temp[4][4];
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			temp[j][3 - i] = mat[i][j];
	copy(temp, mat);
}

void move(int direction, int(*mat)[4])
{
	tot++;
	if (direction>3 || direction<0) { tot += 100000; return; }
	for (int i = 1; i <= direction; i++)
		rotate(mat);

	for (int i = 0; i<4; i++)
	{
		int pos = -1;
		for (int j = 0; j<4; j++)
			if (mat[i][j] != 0)
			{
			if (pos == -1 || mat[i][pos] != mat[i][j])
			{
				mat[i][++pos] = mat[i][j];
			}
			else
			{
				score += 2 * mat[i][pos];
				mat[i][pos] *= 2;
			}
			}
		for (int j = pos + 1; j<4; j++)
			mat[i][j] = 0;
	}

	for (int i = direction + 1; i <= 4; i++)
		rotate(mat);
}

//**************************your code***********************************// 
void output(int(*mat)[4]) {
	for (register int i = 0; i < 4; i++){
		for (register int j = 0; j < 4; j++){
			printf("%d\t", mat[i][j]);
		}
		printf("\n");
	}
}

int move2(int direction, int(*mat)[4])
{
	int score = 0;
	for (int i = 1; i <= direction; i++)
		rotate(mat);

	for (int i = 0; i<4; i++)
	{
		int pos = -1;
		for (int j = 0; j<4; j++)
			if (mat[i][j] != 0)
			{
			if (pos == -1 || mat[i][pos] != mat[i][j])
			{
				mat[i][++pos] = mat[i][j];
			}
			else
			{
				score += 2 * mat[i][pos];
				mat[i][pos] *= 2;
			}
			}
		for (int j = pos + 1; j<4; j++)
			mat[i][j] = 0;
	}

	for (int i = direction + 1; i <= 4; i++)
		rotate(mat);

	return score;
}

int depth = 5;
double dfs(int mat[4][4], int dep, int turn)
{
	if (dep == 0) return 0;
	int temp[4][4];
	if (turn == 2)
	{
		double best = 0;
		double sum = 0;
		int num = 0;
		for (int i = 0; i<4; i++)
			for (int j = 0; j<4; j++)
				if (mat[i][j] == 0)
				{
			copy(mat, temp);
			temp[i][j] = 2;
			num++;
			sum += dfs(temp, dep - 1, 1);
				}
		if (num == 0) best = 0;
		else best = sum / num;
		return best;
	}
	else
	{
		double best = 0;
		int dir = 0;
		int fx[4] = { 0, 2, 1, 3 };
		for (int j = 0; j <= 3; j++)
		{
			int i = fx[j];
			copy(mat, temp);
			double tt = move2(i, temp);
			if (double ans = tt + dfs(temp, dep - 1, 2)>best)
			{
				best = ans;
				dir = i;
			}
		}
		if (dep == depth) return dir;
		else return best;
	}
}


int num = 0;
void get_command(int &direction, int(*mat)[4])
{
	direction = dfs(mat, depth, 1);
	return;
}

//**********************************************************************//
int main()
{
	freopen("output1.txt", "w", stdout);
	int seed = 20180514;
	srand(0); //test seed
	for (int i = 1; i <= 10 && (clock() + 0.0) / CLOCKS_PER_SEC <= 20; i++)
	{
		tot = 0;
		memset(mat, 0, sizeof(mat));
		while (tot<100000 && (clock() + 0.0) / CLOCKS_PER_SEC <= 20)
		{
			rand_put(mat);
			printf("Src: \n");
			output(mat);

			copy(mat, mat2);
			get_command(direction, mat2);
			move(direction, mat);
			
			printf("move direction: %d\n", direction);
			output(mat);

			tot++;
		}
	}
	cout << score << endl;
	return 0;
}
#endif



///////////////////////////////////////////////////////
//Exam02


#if 0

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define N 250
//#define M 100000
#define M 2

int result = 0;

int ch[M+1];

bool code[(2*(8*M)) + M];
int temp[2055];

int ch2[M+1];
int ch3[M+1];

int has[66666];

void makedata(int *ch)
{
	for (int i = 0; i<M; i++)
	{
		ch[i] = rand() % N;
		ch2[i] = ch[i];
	}
	return;
}

int errCnt = 0;
void check(int *ch, int *ch2)
{
	for (int i = 0; i<M; i++)
		if (ch[i] != ch3[i])
		{
		result += 100000;
		errCnt++;
		}
}

void noise(bool *code)
{
	int l = 1, j;
	for (int i = 0; i<M; i++)
	{
		j = rand() % 16;
		code[l + j] = 1 - code[l + j];
		//j = rand() % 16;
		//code[l + j] = 1 - code[l + j];
		l += 16;
	}
}

//your code here
//can not use heap space

void itob(int d, bool a[8]){
	int i = 0;
	while (d) {
		a[i] = d & 0x01;
		d = d >> 1;
		i++;
	}
}

int btoi(bool a[8], int n){
	int i = 0;
	int sum = 0;
	for (i = n-1; i >= 0; i--) {
		sum <<= 1;
		sum |= a[i];
	}
	return sum;
}

void haiming(bool a[13], bool b[18], int k) {
	memset(b, 0, sizeof(b));
	int j = 1, i = 0, G1, G2, G3, G4, G5;
	if (k == 4) {
		for (i = 3; i <= 12; i++) {
			if (i == 4 || i == 8) continue;
			b[i] = a[j++];
		}
		G1 = G2 = G3 = G4 = G5 = 0;
		G1 = b[1] ^ b[3] ^ b[5] ^ b[7] ^ b[9] ^ b[11];
		G2 = b[2] ^ b[3] ^ b[6] ^ b[7] ^ b[10] ^ b[11];
		G3 = b[4] ^ b[5] ^ b[6] ^ b[7] ^ b[12];
		G4 = b[8] ^ b[9] ^ b[10] ^ b[11] ^ b[12];
		b[1] = G1; b[2] = G2; b[4] = G3; b[8] = G4;

		for (i = 1; i <= 12; i++){
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	else if (k == 5) {
		for (i = 3; i <= 17; i++) {
			if (i == 4 || i == 8 || i == 16) continue;
			b[i] = a[j++];
		}
		G1 = G2 = G3 = G4 = G5 = 0;
		G1 = b[1] ^ b[3] ^ b[5] ^ b[7] ^ b[9] ^ b[11] ^ b[13] ^ b[15] ^ b[17];
		G2 = b[2] ^ b[3] ^ b[6] ^ b[7] ^ b[10] ^ b[11] ^ b[14] ^ b[15];
		G3 = b[4] ^ b[5] ^ b[6] ^ b[7] ^ b[12] ^ b[13] ^ b[14] ^ b[15];
		G4 = b[8] ^ b[9] ^ b[10] ^ b[11] ^ b[12] ^ b[13] ^ b[14] ^ b[15];
		G5 = b[16] ^ b[17];
		b[1] = G1; b[2] = G2; b[4] = G3; b[8] = G4; b[16] = G5;
	}
}
void haimingJiema(bool a[13], bool b[18], int k){
	int j = 1, i = 0, G1, G2, G3, G4, G5;
	memset(a, 0, sizeof(a));
	if (k == 4) {
		G1 = b[1] ^ b[3] ^ b[5] ^ b[7] ^ b[9] ^ b[11];
		G2 = b[2] ^ b[3] ^ b[6] ^ b[7] ^ b[10] ^ b[11];
		G3 = b[4] ^ b[5] ^ b[6] ^ b[7] ^ b[12];
		G4 = b[8] ^ b[9] ^ b[10] ^ b[11] ^ b[12];
		int d = G1 | (G2 << 1) | (G3 << 2) | (G4 << 3);
		if (d != 0){
			b[d] = !b[d];
		}
		for (i = 3; i <= 12; i++) {
			if (i == 4 || i == 8) continue;
			a[j++] = b[i];
		}

		for (i = 1; i <= 12; i++){
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	else if (k == 5) {
		G1 = b[1] ^ b[3] ^ b[5] ^ b[7] ^ b[9] ^ b[11] ^ b[13] ^ b[15] ^ b[17];
		G2 = b[2] ^ b[3] ^ b[6] ^ b[7] ^ b[10] ^ b[11] ^ b[14] ^ b[15];
		G3 = b[4] ^ b[5] ^ b[6] ^ b[7] ^ b[12] ^ b[13] ^ b[14] ^ b[15];
		G4 = b[8] ^ b[9] ^ b[10] ^ b[11] ^ b[12] ^ b[13] ^ b[14] ^ b[15];
		G5 = b[16] ^ b[17];
		int d = G1 | (G2 << 1) | (G3 << 2) | (G4 << 4) | (G5 << 5);
		if (d != 0) {
			b[d] = !b[d];
		}
		for (i = 3; i <= 17; i++) {
			if (i == 4 || i == 8 || i == 16) continue;
			a[j++] = b[i];
		}
	}
}
void change(bool* a, int l, int r, bool b[13]) {
	memset(b, 0, sizeof(b));
	int j = 1;
	for (int i = l; i <= r; i++) {
		b[j++] = a[i];
	}
}

void encode(int *ch, bool *code, int *temp)
{
	int i,j ; 
	bool a[8] = { 0 };
	bool tp[13] = { 0 };
	bool b[18] = { 0 };

	for (i = 0; i < M; i++) {
		itob(ch[i], a);
		change(a, 0, 7, tp);
		haiming(tp, b, 4);
		//change(b, 1, 12, tp);
		//haiming(tp, b, 5);

		for (j = 0; j < 17; j++) {
			code[i*17 + j] = b[j+1];
		}
	}

	return;
}

void decode(int *ch, bool *code, int *temp)
{
	int i, j;
	bool a[8] = { 0 };
	bool tp[13] = { 0 };
	bool b[18] = { 0 };

	for (i = 0; i < M; i++) {
		for (j = 0; j < 17; j++) {
			b[j + 1] = code[i * 17 + j];
		}
		haimingJiema(tp, b, 4);
		for (j = 0; j < 8; j++){
			a[j] = tp[j + 1];
		}
		ch[i] = btoi(a, 8);
	}
	return;
}
//************************************************************
int main()
{
	time_t start = clock();
	srand(0);
	makedata(ch); //ch == ch2
	encode(ch2, code, temp); //编码ch2

	noise(code);

	decode(ch3, code, temp);
	
	check(ch, ch3);
	time_t end = clock();
	result += (end - start) / (CLOCKS_PER_SEC / 1000.0);
	cout << result << endl;
	cout << errCnt << endl;
}
#endif





#if 0


#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define N 250
#define M 100000
using namespace std;
int result = 0;
int ch[100001];
bool code[1700000];
int temp[2055];
int ch2[100001];
int ch3[100001];

int has[66666];

void makedata(int *ch)
{
	for (int i = 0; i<M; i++)
	{
		ch[i] = rand() % N;
		ch2[i] = ch[i];
	}
	return;
}

void check(int *ch, int *ch2)
{
	for (int i = 0; i<M; i++)
		if (ch[i] != ch3[i])
		{
		result += 100000;
		}
}

void noise(bool *code)
{
	int l = 1, j;
	for (int i = 0; i<M; i++)
	{
		j = rand() % 16;
		code[l + j] = 1 - code[l + j];
		j = rand() % 16;
		code[l + j] = 1 - code[l + j];
		l += 16;
	}
}
//your code here
int getcode(int now, int *temp)
{
	int l, r;
	l = 1; r = 256;
	while (l != r)
	{
		int mid = (l + r) / 2;
		if (temp[mid]<now) l = mid + 1;
		else r = mid;
	}
	if (temp[l] == now) return l;
	else return -1;
}

void dc(int n)
{
	for (int i = 15; i >= 0; i--)
	{
		if ((1 << i)&n)
			cout << 1;
		else
			cout << 0;
	}
	cout << endl;
}

void encode(int *ch, bool *code, int *temp)
{
	int tot = 0;
	for (int i = 0; i<(1 << 16); i++)
	{
		int flag = 0;
		if (ch[i] >= 10000) flag = 1;
		if (!flag)
		{
			for (int j = 0; j < 16 && !flag; j++)
			{
				int now = i;
				now = now ^ (1 << j);
				if (ch[now] >= 10000) { flag = 1; break; }
				for (int k = j + 1; k<16; k++)
				{
					if (ch[now ^ (1 << k)] >= 10000) { flag = 1; break; }
				}
			}
		}
		if (!flag)
		{
			ch[i] += 10000;
			tot++;
			has[i] = tot;
			temp[tot] = i;
			for (int j = 0; j<16; j++)
			{
				int now = i;
				now = now ^ (1 << j);
				ch[now] += 10000;
				has[now] = tot;
				for (int k = j + 1; k<16; k++)
				{
					ch[now ^ (1 << k)] += 10000;
					has[now ^ (1 << k)] = tot;
				}
			}
		}
	}

	int len = 0;
	for (int i = 0; i<M; i++)
	{
		while (ch[i] >= 10000) ch[i] -= 10000;
		int num = temp[ch[i] + 1];
		for (int j = 0; j<16; j++)
		{
			len++;
			code[len] = num % 2;
			num /= 2;
		}
	}
	return;
}

void decode(int *ch, bool *code, int *temp)
{
	int len = 0, tot = 0;
	for (int i = 0; i<M; i++)
	{
		int tt = 0;
		int er = 1;
		for (int j = 0; j<16; j++)
		{
			len++;
			tt += er*code[len];
			er = er * 2;
		}

		int num;
		num = getcode(tt, temp);

		if (num == -1)
			for (int j = 0; j<16 && num == -1; j++)
			{
			int now = tt;
			now = now ^ (1 << j);
			num = getcode(now, temp);
			if (num != -1) break;
			for (int k = j + 1; k<16; k++)
			{
				num = getcode(now ^ (1 << k), temp);
				if (num != -1) break;
			}
			}
		ch[tot] = num - 1;
		tot++;
	}
	return;
}
//************************************************************
int main()
{
	time_t start = clock();
	srand(0);
	makedata(ch);
	encode(ch2, code, temp);
	noise(code);
	decode(ch3, code, temp);
	check(ch, ch3);
	time_t end = clock();
	result += (end - start) / (CLOCKS_PER_SEC / 1000.0);
	cout << result << endl;
}


#endif







#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

#define N 250
#define M 100000
//#define M 2

int result = 0;

int ch[M + 1];

bool code[(2 * (8 * M)) + M];
int temp[2055];

int ch2[M + 1];
int ch3[M + 1];

int has[66666];

void makedata(int *ch)
{
	for (int i = 0; i<M; i++)
	{
		ch[i] = rand() % N;
		ch2[i] = ch[i];
	}
	return;
}

int errCnt = 0;
void check(int *ch, int *ch2)
{
	for (int i = 0; i<M; i++)
		if (ch[i] != ch3[i])
		{
		result += 100000;
		errCnt++;
		}
}

void noise(bool *code)
{
	int l = 1, j;
	for (int i = 0; i<M; i++)
	{
		j = rand() % 16;
		code[l + j] = 1 - code[l + j];
		j = rand() % 16;
		code[l + j] = 1 - code[l + j];
		l += 16;
	}
}

//your code here
//can not use heap space
int CodeStack[251];
int nr = 0;
int Index[65536];


int codeDist(int a, int b) {
	int c = a ^ b;
	int cnt = 0;
	while (c) {
		if (c & 1) {
			cnt++;
		}
		c >>= 1;
	}
	return cnt;
}

void find(){
	memset(CodeStack, 0, 251 * 4);
	memset(Index, -1, 65536 * 4);
	int d, i, dist;
	for (d = 0; d < 65536; d++) {
		bool flag = 0;
		for (int i = 0; i < nr; i++) {
			dist = codeDist(CodeStack[i], d);
			if (dist >= 5) {
				continue;
			}
			else{
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			CodeStack[nr] = d;
			Index[d] = nr;
			if (nr == 250) break;
			nr += 1;
		}
	}

	for (d = 0; d < 65536; d++){
		if (Index[d] != -1) continue;
		for (i = 0; i < nr; i++) {

			dist = codeDist(CodeStack[i], d);
			if (dist <= 2) {
				Index[d] = Index[CodeStack[i]];
				break;
			}
		}
		//if (i == nr) {
		//	printf("d=%d not find code\n", d);
		//}
	}

	//for (d = 0; d < 65536; d++) {
	//	if (index[d] == -1) continue;
	//	printf("d=%d, index=%d\n", d, index[d]);
	//}
}


void encode(int *ch, bool *code, int *temp)
{


	//printf("sizeof Index: %d\n", sizeof(Index));

	

	for (int i = 0; i < M; i++) {
		int d = ch[i];
		int c = CodeStack[d];
		
		for (int j = 1; j <= 16; j++) {
			code[j + i * 16] = c & 0x01;
			c = c >> 1;
		}
	}
	return;
}

void decode(int *ch, bool *code, int *temp)
{
	//int CodeStack[251];
	//int nr = 0;
	//int Index[65536];
	//find(CodeStack, nr, Index);

	int c = 0;
	for (int i = 0; i < M; i++) {

		c = 0;
		for (int j = 1; j <= 16; j++){
			c <<= 1;
			c |= code[(17 - j) + i * 16];
		}

		ch[i] = Index[c];
	}
	return;
}
//************************************************************
int main()
{
	//freopen("out.txt", "w", stdout);


	find();

	//for (int i = 0; i < nr; i++){
	//	printf("%d\t", CodeStack[i]);
	//	if (i % 25 == 0)
	//		printf("\n");
	//}
	//printf("\n");

	//return 0;


	time_t start = clock();
	srand(0);
	makedata(ch); //ch == ch2
	encode(ch2, code, temp); //编码ch2

	noise(code);

	decode(ch3, code, temp);

	check(ch, ch3);
	time_t end = clock();
	result += (end - start) / (CLOCKS_PER_SEC / 1000.0);
	cout << result << endl;
	cout << "errCnt: "<< errCnt << endl;
}


///////////////////////////////////////////////////////
//Exam03
#if 1

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define M 100000
#define N 80

char ch[100001];
char ch2[100001];
char code[80001];

char ch3[100001];
int result;

void makedata(char *ch)
{
	int fre[N + 1], sum = 0;
	for (int j = 0; j<N; j++)
	{
		fre[j] = rand() % (j * 5 + 1);
		sum += fre[j];
	}
	//sum这个数是固定不变的
	for (int i = 0; i<M; i++) //遍历从[0, 100000)
	{
		int now = rand() % sum;
		for (int j = 0; j<N; j++) //j是从[0, 80)的一个位置
		{
			now = now - fre[j];
			if (now <= 0)
			{
				ch[i] = j;
				ch2[i] = ch[i];
				break;
			}
		}
	}
	return;
}
int errCnt = 0;

void check(char *ch, char *ch2)
{
	int flag = 0;
	for (int i = 0; i<M; i++)
		if (ch[i] != ch3[i])
		{
		result -= 10000;
		flag = 1;
		errCnt++;
		return;
		}
	result++;
}

//your code here
//can not use heap space
typedef struct Node{
	int value;
	int appCnt;
}Node;
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i)<<1)+1)

typedef struct PQueue{
	Node p[N+2];
	int nr;
}PQueue;

void initQueue(PQueue & Q){
	Q.nr = 0;
}
void swap(Node & n1, Node& n2) {
	if (&n1 == &n2) return;
	Node tmp = n1;
	n1 = n2;
	n2 = tmp;
}
//void heapify(PQueue & Q, int p) {
//	int l, r, min;
//	l = LEFT(p); r = RIGHT(p);
//	min = p;
//	if (l <= Q.nr) {
//		if (Q.p[l].appCnt < Q.p[p].appCnt) {
//			min = l;
//		}
//	}
//	if (r <= Q.nr) {
//		if (Q.p[r].appCnt < Q.p[min].appCnt) {
//			min = r;
//		}
//	}
//	if (min == p) {
//		return;
//	}
//	swap(Q.p[p], Q.p[min]);
//	heapify(Q, min);
//}

void heapify(PQueue & Q, int p) {
	int l, r, min;
	while (p <= (Q.nr >> 1)){
		l = LEFT(p); r = RIGHT(p);
		min = p;
		if (l <= Q.nr) {
			if (Q.p[l].appCnt < Q.p[p].appCnt) {
				min = l;
			}
		}
		if (r <= Q.nr) {
			if (Q.p[r].appCnt < Q.p[min].appCnt) {
				min = r;
			}
		}
		if (min == p) {
			return;
		}
		swap(Q.p[p], Q.p[min]);
		p = min;
	}
}

void enterQueue(PQueue & Q, Node n) {
	Q.nr++;
	int i = Q.nr;
	Q.p[i] = n;
	int p = i >> 1;
	while (i > 1) {
		if (Q.p[i].appCnt < Q.p[p].appCnt) {
			swap(Q.p[i], Q.p[p]);
			i = p;
			p = i >> 1;
		}
		else{
			break;
		}
	}
}
Node exitQueue(PQueue& Q) {
	Node r = Q.p[1];
	swap(Q.p[1], Q.p[Q.nr]);
	Q.nr--;
	heapify(Q, 1);
	return r;
}


int Left[N * 2 + 10];
int Right[N * 2 + 10];
int root = 0;



void copyBit(char *code, int & nrBit, char b) {
	int i = nrBit / 8;
	int j = nrBit % 8;
	if (b == 1) {
		code[i] = code[i] | (1 << j);
	}
	else{
		code[i] = code[i] & (~(1 << j));
	}
	nrBit++;
}
void setBit(char *code, int& nrBit, char C[N], int nrC) {
	for (int i = 0; i < nrC; i++){
		copyBit(code, nrBit, C[i]);
	}
}

int getBit(char * code, int nrBit) {
	
	int i = nrBit / 8;
	int j = nrBit % 8;
	
	int b = (code[i] >> j) & 0x01;
	//printf("nrBit=%d, i=%d, j=%d, bit=%d\n", nrBit, i, j, b);
	return b;
}

void dfsEncode(int idx, char cd[], int n, char Code[][80], int nrCd[]) {
	if (idx > -1 && idx < 80) {
		memcpy(Code[idx], cd, n);
		nrCd[idx] = n;
		return;
	}
	cd[n] = 0;
	dfsEncode(Left[idx], cd, n + 1, Code, nrCd);
	cd[n] = 1;
	dfsEncode(Right[idx], cd, n + 1, Code, nrCd);
}

void encode(char *ch, char *code)
{
	char Code[N][N];
	int nrCd[N] = { 0 };

	int i;
	PQueue Q; initQueue(Q);

	int appearCnt[N*2+10] = { 0 };
	
	int nrAper = 0;
	memset(Left, -1, sizeof(Left));
	memset(Right, -1, sizeof(Right));

	for (i = 0; i < M; i++){
		appearCnt[ch[i]]++;
	}
	Node n;
	for (i = 0; i < N; i++){
		n.value = i;
		n.appCnt = appearCnt[i];
		enterQueue(Q, n);
	} 
	Node n1, n2, n3;
	nrAper = 80;
	//构建
	while (Q.nr > 1) {
		n1 = exitQueue(Q); n2 = exitQueue(Q);
		n3.appCnt = n1.appCnt + n2.appCnt;
		n3.value = nrAper;
		enterQueue(Q, n3);

		Left[n3.value] = n1.value;
		Right[n3.value] = n2.value;

		nrAper++;
	}
	//编码
	n = exitQueue(Q);
	root = n.value;
	char cd[N];
	dfsEncode(n.value, cd, 0, Code, nrCd);

	int nrBit = 0;
	for (i = 0; i < M; i++){
		setBit(code, nrBit, Code[ch[i]], nrCd[ch[i]]);
	}

	return;
}

void decode(char *ch, char *code)
{
	int i =0, bit, nr = 0;
	
	int p = root;
	while (1){
		while (!(p > -1 && p < 80)) {
			bit = getBit(code, i++);
			if (bit == 0) {
				p = Left[p];
			}
			else{
				p = Right[p];
			}
		}
		ch[nr++] = p;
		p = root;
		if (nr == M) {
			break;
		}
	}
	return;
}

//************************************************************
int main()
{
	//freopen("out.txt", "w", stdout);
	int tc = 0;
	time_t start = clock();
	srand(time(0));
	while ((clock() - start) / CLOCKS_PER_SEC <= 10)
	{
		tc++;
		memset(ch, 0, sizeof(ch));
		memset(ch2, 0, sizeof(ch2));
		memset(ch3, 0, sizeof(ch3));
		memset(code, 0, sizeof(code));


		makedata(ch);
		encode(ch2, code);
		decode(ch3, code);
		check(ch, ch3);
	}
	cout << result << endl;
	printf("tc=%d\n", tc);
	printf("errCnt = %d\n", errCnt);
}

#endif



#if 0

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define M 100000
#define N 80
char ch[100001];
char code[80001];
char ch2[100001];
char ch3[100001];
int result;
void makedata(char *ch)
{
	int fre[N + 1], sum = 0;
	for (int j = 0; j<N; j++)
	{
		fre[j] = rand() % (j * 5 + 1);
		sum += fre[j];
	}
	for (int i = 0; i<M; i++)
	{
		int now = rand() % sum;
		for (int j = 0; j<N; j++)
		{
			now = now - fre[j];
			if (now <= 0)
			{
				ch[i] = j;
				ch2[i] = ch[i];
				break;
			}
		}
	}
	return;
}

void check(char *ch, char *ch2)
{
	for (int i = 0; i<M; i++)
		if (ch[i] != ch3[i])
		{
		result -= 10000;
		return;
		}
	result++;
}


//your code here
//can not use heap space

unsigned int _80to10(char *ch, int n) {
	unsigned int sum = 0;
	int i;
	for (i = 0; i < n; i++){
		sum *= 80;
		sum += ch[i];
	}
	return sum;
}

void _10to80(unsigned int d, char* ch, int n){
	
	for (int i = 0; i < n; i++){
		ch[n-i-1] = d % 80;
		d = d / 80;
	}
}

void copy(void* dst, void* src, int size) {
	char* p = (char*)src;
	char* q = (char*)dst;
	for (int i = 0; i < size; i++){
		*q = *p;
		p++; q++;
	}
}

void encode(char *ch, char *code)
{
	int i, j, n = M/5;
	unsigned int d = 0;
	for (i = 0; i < n; i++){
		d = _80to10(ch + i * 5, 5);
		copy(code + i * 4, &d, 4);
	}
	return;
}

void decode(char *ch, char *code)
{
	int i, j, n = M/5;
	unsigned int d = 0;
	for (i = 0; i < n; i++){
		copy(&d, code + i * 4, 4);
		_10to80(d, ch + i * 5, 5);
	}
	return;
}
//************************************************************
int main()
{
	time_t start = clock();
	srand(time(0));
	while ((clock() - start) / CLOCKS_PER_SEC <= 9.9)
	{
		memset(ch, 0, sizeof(ch));
		memset(ch2, 0, sizeof(ch2));
		memset(ch3, 0, sizeof(ch3));
		memset(code, 0, sizeof(code));
		makedata(ch);
		encode(ch2, code);
		decode(ch3, code);
		check(ch, ch3);
	}
	cout << result << endl;
}
#endif

////////////////////////////////////////////////////////////

//Exam04
#if 0

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define siz 1000
using namespace std;

int result;

char temp[1001][1001];
char ans[1001][1001];

char ch[1000005];

int mat[4][1001][1001];

void makedata(char *ch, int(*mat)[1001][1001])
{
	int x, y, f;
	for (int i = 0; i < siz / 2; i++) {
		for (int j = 0; j < siz / 2; j++)
		{
			x = i; y = j;
			f = rand() % 3;
			while (f--)
			{
				swap(x, y);
				y = siz - 1 - y;
			}
			mat[0][x][y] = 1;
		}
	}

	for (int i = 0; i<siz; i++)
		for (int j = 0; j<siz; j++)
			temp[i][j] = rand() % 128;
	
	int tot = 0;
	for (int k = 0; k <= 3; k++)
	{
		for (int i = 0; i < siz; i++){
			for (int j = 0; j < siz; j++)
			{
				if (mat[k][i][j] == 1) 
					ch[tot++] = temp[i][j];
				if (k < 3)
					mat[k + 1][j][siz - 1 - i] = mat[k][i][j];
			}
		}
	}
	//printf("tot=%d\n", tot);

	for (int i = 0; i < siz / 2; i++){
		for (int j = 0; j < siz / 2; j++)
		{
			mat[0][i][j] = 0;
		}
	}
	return;
}
int errCnt = 0;
void check(char(*ch)[1001], char(*ans)[1001])
{
	for (int i = 0; i < siz; i++){
		for (int j = 0; j < siz; j++){
			if (ch[i][j] != ans[i][j])
			{
				errCnt++;
				printf("err: (%d, %d)\n", i, j);
				result -= 100;
				return;
			}
		}
	}
	result++;
	return;
}

//**************************your code***********************************// 
void rotate(int mat[1001][1001], int r) {
	register int i, j;
	int istart[4] = {0, 0, 500, 500};
	int iend[4] = {500, 500, 1000, 1000};
	int jstart[4] = {0, 500, 500, 0};
	int jend[4] = { 500, 1000, 1000, 500 };

	int cnt = 3;
	while (cnt) {
		for (i = istart[r]; i < iend[r]; i++){
			for (j = jstart[r]; j < jend[r]; j++){
				if (mat[i][j] == 1){
					mat[j][999 - i] = mat[i][j];
					mat[i][j] = 0;
				}
			}
		}
		r--;
		if (r < 0) r = 3;

		cnt--;
	}
}

void work(char *ch, int mat[1001][1001], char(*ans)[1001])
{
	register int i, j, k;
	for (i = 0; i < 500; i++) {
		for (j = 500; j < 1000; j++){
			if (mat[i][j] == 1){
				mat[999 - j][i] = 2;
			}
		}
	}
	for (i = 500; i < 1000; i++){
		for (j = 500; j < 1000; j++){
			if (mat[i][j] == 1){
				mat[999 - i][999 - j] = 2;
			}
		}
	}
	for (i = 0; i < 500; i++){
		for (j = 0; j < 500; j++){
			if (mat[i][j] == 0) mat[i][j] = 1;
			else mat[i][j] = 0;
		}
	}

	int nr = 0;
	int dir[3] = { 2, 3, 0 };
	for (k = 0; k < 4; k++){
		for (i = 0; i < 1000; i++){
			for (j = 0; j < 1000; j++){
				if (mat[i][j] == 1) {
					ans[i][j] = ch[nr++];
				}
			}
		}
		if (k < 3)
			rotate(mat, dir[k]);
	}
	return;
}



//**********************************************************************//

int b[10] = { 1, 3, 4, 7, 10, 14, 19, 20, 21, 31 };

bool bsearch(int a[], int n, int e) {
	int l, r, m; 
	l = 0; r = n;
	while (l + 1 < r) {
		m = l + ((r - l) >> 1);
		if (e >= a[m]) {
			l = m;
		}
		else{
			r = m;
		}
	}
	if (a[l] == e) return true;
	return false;
}

int main()
{
	time_t start = clock();
	srand(3);
	while ((clock() - start) / CLOCKS_PER_SEC <= 10)
	{
	//for (int t = 0; t < 10; t++){
		memset(mat, 0, sizeof(mat));
		
		makedata(ch, mat);
		
		work(ch, mat[0], ans);
		
		check(temp, ans);
	}
	cout << result << endl;
	cout << "errCnt=" << errCnt << endl;

	//bool ret = bsearch(b, 10, 20);
	//printf("%d\n", ret);
}
#endif




#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define siz 1000
using namespace std;
int result;
char temp[1001][1001];
char ans[1001][1001];
char ch[1000005];
int mat[4][1001][1001];
void makedata(char *ch, int(*mat)[1001][1001])
{
	int x, y, f;
	for (int i = 0; i<siz / 2; i++)
		for (int j = 0; j<siz / 2; j++)
		{
		x = i; y = j;
		f = rand() % 3;
		while (f--)
		{
			swap(x, y);
			y = siz - 1 - y;
		}
		mat[0][x][y] = 1;
		}

	for (int i = 0; i<siz; i++)
		for (int j = 0; j<siz; j++)
			temp[i][j] = rand() % 128;
	int tot = 0;
	for (int k = 0; k <= 3; k++)
	{
		for (int i = 0; i<siz; i++)
			for (int j = 0; j<siz; j++)
			{
			if (mat[k][i][j] == 1) ch[tot++] = temp[i][j];
			if (k<3)
				mat[k + 1][j][siz - 1 - i] = mat[k][i][j];
			}
	}

	for (int i = 0; i<siz / 2; i++)
		for (int j = 0; j<siz / 2; j++)
		{
		mat[0][i][j] = 0;
		}
	return;
}

void check(char(*ch)[1001], char(*ans)[1001])
{
	for (int i = 0; i<siz; i++)
		for (int j = 0; j<siz; j++)
			if (ch[i][j] != ans[i][j])
			{
		result -= 100;
		return;
			}
	result++;
	return;
}

//**************************your code***********************************// 
void work(char *ch, int mat[1001][1001], char(*ans)[1001])
{

	for (int i = 0; i<siz / 2; i++)
		for (int j = 0; j<siz / 2; j++)
		{
		int x = i, y = j;
		int flag = 0;
		for (int k = 1; k <= 3; k++)
		{
			swap(x, y);
			y = siz - 1 - y;
			if (mat[x][y] == 1) flag = 1;
		}
		if (flag == 0)
			mat[i][j] = 1;
		}

	int tot = 0;
	for (int k = 0; k <= 3; k++)
		for (int i = 0; i<siz; i++)
			for (int j = 0; j<siz; j++)
			{
		int x = i, y = j;
		int t = k;
		while (t--)
		{
			swap(x, y);
			x = siz - 1 - x;
		}

		if (mat[x][y] == 1)
		{
			ans[i][j] = ch[tot];
			tot++;
		}
			}
}

//**********************************************************************//
int main()
{
	time_t start = clock();
	srand(0);
	while ((clock() - start) / CLOCKS_PER_SEC <= 9.9)
	{
		memset(mat, 0, sizeof(mat));
		makedata(ch, mat);
		work(ch, mat[0], ans);
		check(temp, ans);
	}
	cout << result << endl;
	return 0;
}
///////////////////////////////////////////////////////

//Exam05
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

using namespace std;


int result;
int sudoku[10][10] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 4, 2, 3, 0, 8, 9, 0, 0,
	0, 0, 0, 0, 0, 0, 1, 0, 4, 0,
	0, 6, 0, 0, 0, 0, 0, 5, 0, 0,
	0, 9, 0, 3, 1, 0, 0, 0, 2, 0,
	0, 0, 0, 7, 0, 0, 9, 6, 8, 0, 
	0, 0, 0, 0, 0, 6, 2, 0, 5, 0,
	0, 8, 0, 0, 0, 0, 7, 0, 9, 2,
	0, 0, 0, 1, 2, 0, 0, 0, 3, 5,
	0, 0, 5, 9, 8, 4, 0, 0, 0, 0
};

int can(int x, int y, int t)
{
	if (t <= 0 || t>9) return 0;
	for (int i = 1; i <= 9; i++)
	{
		if (sudoku[x][i] == t && i != y)
			return 0;
		if (sudoku[i][y] == t && i != x)
			return 0;
	}
	for (int i = (x - 1) / 3 * 3 + 1; i <= (x - 1) / 3 * 3 + 3; i++)
		for (int j = (y - 1) / 3 * 3 + 1; j <= (y - 1) / 3 * 3 + 3; j++)
			if (sudoku[i][j] == t && (i != x || j != y))
				return 0;
	return 1;
}

void makedata(int(*sudoku)[10])
{
	for (int i = 1; i <= 20; i++)
	{
		int x, y, t;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		t = rand() % 9 + 1;
		if (can(x, y, t))
		{
			sudoku[x][y] = t;
		}
	}
}

void check(int(*sudoku)[10])
{
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (can(i, j, sudoku[i][j]) == 0)
			{
				return;
			}
		}
	}
	result++;
	return;
}

//**************************your code***********************************// 
//you can use heap space

void output(int(*sudoku)[10]) {
	int i, j;
	for (i = 1; i <= 9; i++){
		for (j = 1; j <= 9; j++){
			printf("%d\t", sudoku[i][j]);
			if (j == 3 || j == 6) printf("|");
		}
		if (i == 3 || i == 6) {
			printf("\n");
			for (j = 1; j <= 9; j++){
				printf("----");
			}
		}
		printf("\n");
	}
}

int can2(int sudoku[10][10], int x, int y, int t)
{
	if (t <= 0 || t>9) return 0;
	for (int i = 1; i <= 9; i++)
	{
		if (sudoku[x][i] == t && i != y)
			return 0;
		if (sudoku[i][y] == t && i != x)
			return 0;
	}
	for (int i = (x - 1) / 3 * 3 + 1; i <= (x - 1) / 3 * 3 + 3; i++)
		for (int j = (y - 1) / 3 * 3 + 1; j <= (y - 1) / 3 * 3 + 3; j++)
			if (sudoku[i][j] == t && (i != x || j != y))
				return 0;
	return 1;
}

int can3(int sudoku[10][10], int x, int y, int t, bool row[10][10], bool col[10][10], bool block[10][10], int blockIdx[10][10])
{
	if (t <= 0 || t>9) return 0;

	if (row[x][t] == true) {
		return 0;
	}
	if (col[y][t] == true) {
		return 0;
	}
	if (block[blockIdx[x][y]][t] == true) {
		return 0;
	}
	return 1;
}

void copy(int src[10][10], int dst[10][10]){
	register int i, j;
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			dst[i][j] = src[i][j];
}

void copy(bool src[10][10], bool dst[10][10]){
	register int i, j;
	for (i = 1; i <= 9; i++)
		for (j = 1; j <= 9; j++)
			dst[i][j] = src[i][j];
}

int dfs(int rowIdx[9], int i, int colIdx[10][10], int nrCol[10], int j, int sudoku[10][10], bool row[10][10], bool col[10][10], bool block[10][10], int blockIdx[10][10]){
	//if (i == 9) {
	//	return 1;
	//}
	int tmp[10][10];
	bool colTmp[10][10];
	bool rowTmp[10][10];
	bool blockTmp[10][10];

	int x = rowIdx[i];
	int y = colIdx[x][j];

	int t = 0;

	//if (y == 10){
	if (j == nrCol[x]) {
		i++;
		x = rowIdx[i];
		//y = 1;
		j = 0;
		if (i == 9) {
			copy(sudoku, ::sudoku);
			return 1;
		}
	}

	//printf("i=%d [%d, %d]\n", i, x, y);
	//output(sudoku);
	//printf("\n");

	if (sudoku[x][y] > 0) {
		if (dfs(rowIdx, i, colIdx, nrCol, j + 1, sudoku, row, col, block, blockIdx)) {
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		copy(sudoku, tmp);
		copy(row, rowTmp);
		copy(col, colTmp);
		copy(block, blockTmp);
		for (t = 1; t <= 9; t++){
			
			if (!can3(tmp, x, y, t, rowTmp, colTmp, blockTmp, blockIdx)) continue;
			tmp[x][y] = t;
			rowTmp[x][t] = true;
			colTmp[y][t] = true;
			blockTmp[blockIdx[x][y]][t] = true;

			if (dfs(rowIdx, i, colIdx, nrCol, j+1, tmp, rowTmp, colTmp, blockTmp, blockIdx)) {
				break;
			}
			else {
				//copy(tmp, sudoku);
				rowTmp[x][t] = false;
				colTmp[y][t] = false;
				blockTmp[blockIdx[x][y]][t] = false;
			}
		}
		if (t <= 9){ //success
			return 1;
		}
		else{
			//copy(tmp, sudoku);
			return 0; //failed
		}
	}
}

void isort(int rowCnt[], int idx[], int n) {
	register int i, j;
	int tmpIdx = 0;
	int tmp; 
	for (i = 0; i < n; i++) {
		tmpIdx = idx[i];
		tmp = rowCnt[tmpIdx];
		for (j = i - 1; j >= 0; j--){
			if (tmp > rowCnt[idx[j]]) {
				idx[j + 1] = idx[j];
			}
			else{
				break;
			}
		}
		idx[j + 1] = tmpIdx;
	}
}

void work(int(*sudoku)[10])
{
	register int i, j;
	int rowCnt[10] = { 0 };
	int colIdx[10][10] = {0};
	int nrCol[10] = { 0 };

	int rowIdx[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (i = 1; i <= 9; i++){
		for (j = 1; j <= 9; j++){
			if (sudoku[i][j] > 0) {
				rowCnt[i]++;
			}
			else{
				colIdx[i][nrCol[i]++] = j;
			}
		}
	}
	//sort
	isort(rowCnt, rowIdx, 9);

	bool Row[10][10] = { 0 };
	bool Col[10][10] = { 0 };
	bool Block[10][10] = { 0 };

	int BlockIdx[10][10] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },
			{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },
			{ 0, 1, 1, 1, 2, 2, 2, 3, 3, 3 },

			{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
			{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },
			{ 0, 4, 4, 4, 5, 5, 5, 6, 6, 6 },

			{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
			{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 },
			{ 0, 7, 7, 7, 8, 8, 8, 9, 9, 9 }
	};

	for (i = 1; i <= 9; i++){
		for (j = 1; j <= 9; j++){
			if (sudoku[i][j] > 0) {
				Row[i][sudoku[i][j]] = true;
				Col[j][sudoku[i][j]] = true;
				Block[BlockIdx[i][j]][sudoku[i][j]] = true;
			}
		}
	}

	if (dfs(rowIdx, 0, colIdx, nrCol, 0, sudoku, Row, Col, Block, BlockIdx)) {
		//printf("success\n");
	}
	else{
		//printf("failed\n");
	}

	return;
}

//**********************************************************************//
int main()
{
	freopen("out.txt", "w", stdout);

	time_t start = clock();
	srand(0); //the seed will be change
	//while ((clock() - start) / CLOCKS_PER_SEC <= 9.9)
	//{
	//	memset(sudoku, 0, sizeof(sudoku));
	//    makedata(sudoku);

		//output(sudoku);

		work(sudoku);
		check(sudoku);
	//}
	cout << result << endl;
}
////////////////////////////////////////////////////////

//Exam06
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define N 20
using namespace std;
int edge[N][N];
int temp[N][N];
int flag = 0;
long long result = 0;

#define min(a, b) ((a)<(b) ? (a): (b))

void makedata()
{
	int x, y, len;
	for (int i = 1; i<N; i++)
	{
		x = i - 1; y = i;
		edge[x][y] = 99999;
		temp[x][y] = 99999;
	}
	for (int i = 1; i <= 100; i++)
	{
		x = rand() % N;
		y = rand() % N;
		len = rand() % 10000;
		edge[x][y] = len;
		temp[x][y] = len;
	}
}

int vs[N], tot, now;
void move(int y)
{
	if (flag != 0) return;
	if (edge[now][y] == -1) { flag = 2; return; }
	result += edge[now][y];
	now = y;
	if (vs[now] == 0) tot++; else vs[now] = 1;
	if (tot == N) flag = 1;
	return;
}
//**************************your code***********************************// 
//You can use function move(int y)
//and you can use heap space , memory limit : 256Mb
struct nod
{
	int sta, now;
	nod() {}
	nod(int x, int y){ sta = x; now = y; }
};

nod q[5000005];
int dist[1 << (N - 1)][N];
int pre[1 << (N - 1)][N];
bool vis[1 << (N - 1)][N];
int head, tail;

void get_tsp(int(*temp)[N])
{
	memset(dist, -1, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));

	head = tail = 1;
	dist[0][0] = 0;
	vis[0][0] = 1;
	q[head] = nod(0, 0);
	while (head <= tail)
	{
		nod now = q[head % 5000000];
		head++;

		vis[now.sta][now.now] = 0;
		int dis = dist[now.sta][now.now];
		for (int j = 0; j < N; j++) {
			if (temp[now.now][j] != -1)
			{
				nod nex = now;
				int len = dis + temp[now.now][j];
				nex.now = j;
				if (j != 0) 
					nex.sta |= (1 << (j - 1));
				if (dist[nex.sta][nex.now] == -1 || dist[nex.sta][nex.now] > len)
				{
					dist[nex.sta][nex.now] = len;
					pre[nex.sta][nex.now] = now.sta * 100 + now.now;
					if (vis[nex.sta][nex.now] == 0)
					{
						tail++;
						q[tail % 5000000] = nex;
					}
				}
			}
		}
	}
	int best = 99999999;
	int sta = (1 << (N - 1)) - 1, t = -1;
	for (int j = 0; j < N; j++){
		if (dist[(1 << (N - 1)) - 1][j] != -1)
		{
			best = min(best, dist[(1 << (N - 1)) - 1][j]);
			if (best == dist[(1 << (N - 1)) - 1][j])
				t = j;
		}
	}
	int ans[N*N + N], num = 0;
	while (sta != 0 || t != 0)
	{
		ans[++num] = t;
		int tt = pre[sta][t];
		sta = tt / 100;
		t = tt % 100;
	}
	int a = 0;
	for (int i = num; i >= 1; i--)
	{
		a = ans[i];
		move(ans[i]);
	}
	return;
}

//**********************************************************************//
int main()
{
	time_t start = clock();
	srand(0); //the seed will be change
	for (int i = 1; i <= 10; i++)
	{
		flag = 0; now = 0;
		memset(vs, 0, sizeof(vs));
		vs[now] = 1; tot = 1;
		memset(edge, -1, sizeof(edge));
		memset(temp, -1, sizeof(temp));
		makedata();
		get_tsp(temp);
		if (flag != 1) { result += 99999999; }
	}
	time_t end = clock();
	double tim = (end - start + 0.0) / CLOCKS_PER_SEC;
	if (tim >= 20) result += 99999999;
	cout << result << endl;
}
////////////////////////////////////////////////////////////
//Exam02-solution

#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define N 250
#define M 100000
using namespace std;
int result=0;
int ch[100001];
bool code[1700000];
int temp[2055];
int ch2[100001];
int ch3[100001];

int has[66666];

void makedata(int *ch)
{
	for (int i=0;i<M;i++)
	{
		ch[i]=rand()%N;
		ch2[i]=ch[i];
	}
	return;
}

void check(int *ch,int *ch2)
{
	for (int i=0;i<M;i++)
	if (ch[i]!=ch3[i])
	{
		result+=100000;
	}
}

void noise(bool *code)
{
	int l=1,j;
	for (int i=0;i<M;i++)
	{
		j=rand()%16;
		code[l+j]=1-code[l+j];
		j=rand()%16;
		code[l+j]=1-code[l+j];
		l+=16;
	}
}
//your code here
int getcode(int now,int *temp)
{
	int l,r;
	l=1; r=256;
	while (l!=r)
	{
		int mid=(l+r)/2;
		if (temp[mid]<now) l=mid+1;
		else r=mid;
	}
	if (temp[l]==now) return l;
	else return -1;
}

void dc(int n)
{
	for (int i=15;i>=0;i--)
	{
		if ( (1<<i)&n ) 
			cout<<1;
		else
			cout<<0;
	}
	cout<<endl;
}

void encode(int *ch,bool *code,int *temp)
{
	int tot=0;
	for (int i=0;i<(1<<16);i++)
	{
		int flag=0;
		if (ch[i]>=10000) flag=1;
		if (!flag)
		{
			for (int j=0;j<16 && !flag;j++)
			{
				int now=i;
				now=now^(1<<j);
				if (ch[now]>=10000) {flag=1; break;}
				for (int k=j+1;k<16;k++)
				{
					if (ch[now^(1<<k)]>=10000) {flag=1; break;}
				}
			}
		}
		if (!flag)
		{
			ch[i]+=10000;
			tot++;
			has[i]=tot;
			temp[tot]=i;
			for (int j=0;j<16;j++)
			{
				int now=i;
				now=now^(1<<j);
				ch[now]+=10000;
				has[now]=tot;
				for (int k=j+1;k<16;k++)
				{
					ch[now^(1<<k)]+=10000;
					has[now^(1<<k)]=tot;
				}
			}
		}
	}
	
	int len=0;
	for (int i=0;i<M;i++)
	{
		while (ch[i]>=10000) ch[i]-=10000;
		int num=temp[ch[i]+1];
		for (int j=0;j<16;j++)
		{
			len++;
			code[len]=num%2;
			num/=2;
		}	
	} 
	return;
}

void decode(int *ch,bool *code,int *temp)
{
	int len=0,tot=0;
	for (int i=0;i<M;i++)
	{
		int tt=0;
		int er=1;
		for (int j=0;j<16;j++)
		{
			len++;
			tt+=er*code[len];
			er=er*2;
		}
		
		int num;
		num=getcode(tt,temp);
		
		if (num==-1)
		for (int j=0;j<16 && num==-1;j++)
		{
			int now=tt;
			now=now^(1<<j);
			num=getcode(now,temp);
			if (num!=-1) break;
			for (int k=j+1;k<16;k++)
			{
				num=getcode(now^(1<<k),temp);
				if (num!=-1) break;	
			}
		}
		ch[tot]=num-1;
		tot++;
	}
	return;
}
//************************************************************
int main()
{
	time_t start = clock();
	srand(0);
	makedata(ch);
	encode(ch2,code,temp);
	noise(code);
	decode(ch3,code,temp);
	check(ch,ch3);
	time_t end = clock();
	result+=(end-start)/(CLOCKS_PER_SEC/1000.0); 
	cout<<result<<endl;
}
////////////////////////////////////////////////////////////
//Exam03-solution
/*
每个数字有80种取值范围，用二进制存需要7位，直接存储需要7*100000空间，用char类型存，也需要87500大小的数组，只给了80000大小的数组，所以必须使用无损压缩算法了，这里用哈夫曼编码就可以，牵扯这样几个问题：
1.构建哈夫曼树，这个直接贪心就可以了，因为只有80个节点需要合并，所以怎么暴力都可以。
2.构建每个点的编码，建树并dfs，直接存需要160*160的矩阵，会爆栈空间，所以只能存每个节点的father，然后倒序直接构建，不要dfs了。
3.编码的时候需要把每个字符对应的码字存进去，这里有两种策略，一种是把长度也存进去，一种是直接按固定长度存，最后再比对出最短的码字。
4.查找的时候比较涉及效率，需要构建一颗字典树来查找，比暴力要快100倍左右。

*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
#define M 100000
#define N 80
char ch[100001];
char code[80001];
char ch2[100001];
char ch3[100001];
int result;
void makedata(char *ch)
{
	int fre[N+1],sum=0;
	for (int j=0;j<N;j++)
	{
		fre[j]=rand()%(j*5+1);
		sum+=fre[j];
	}
	for (int i=0;i<M;i++)
	{
		int now=rand()%sum;
		for (int j=0;j<N;j++)
		{
			now=now-fre[j];
			if (now<=0)
			{
				ch[i]=j;
				ch2[i]=ch[i];		
				break;
			} 
		} 
	}
	return;
}

void check(char *ch,char *ch2)
{
	for (int i=0;i<M;i++)
	if (ch[i]!=ch3[i])
	{
		result-=10000;
		return;
	}
	result++;
}
//your code here
//can not use heap space
void encode(char *ch,char *code)
{
	string s[205];
	int fre[205];
	int fa[205];
	char belong[205];
	memset(fre,0,sizeof(fre));
	for (int i=0;i<M;i++)
		fre[ch[i]]++;
	for (int i=0;i<2*N;i++)
		s[i]="";
	int tot=N;
	int num=0;
	for (int i=0;i<N-1;i++)
	{
		int zx=-1,cx=-1;
		for (int j=0;j<tot;j++)
		{
			if (zx==-1 || fre[zx]>fre[j])
				zx=j;
		}	
		for (int j=0;j<tot;j++)
		{
			if ((cx==-1 || fre[cx]>fre[j]) && j!=zx)
				cx=j;
		}
		fre[tot]=fre[cx]+fre[zx];
		fa[zx]=fa[cx]=tot;
		belong[zx]='0';
		belong[cx]='1';
		tot++;
		fre[cx]+=10000000;
		fre[zx]+=10000000;
	}
	for (int i=tot-2;i>=0;i--)
	{
		s[i]=s[fa[i]]+belong[i];
	}
	int codestart=0,textstart=1000;
	for (int i=0;i<N;i++)
	{
		int x,y;
		x=codestart;
		y=0;
		for (int j=0;j<s[i].size();j++)
		{
			if (s[i][j]=='1')
				code[x]=code[x]|(1<<y);
			y++;
			if (y==8)
			{
				x++;
				y=0;
			}
		}
		codestart+=9;
	}
	int y=0;
	for (int i=0;i<M;i++)
	{
		string ss=s[ch[i]];
		for (int j=0;j<ss.size();j++)
		{
			if (ss[j]=='1')
				code[textstart]=code[textstart]|(1<<y);
			y++;
			if (y==8)
			{
				textstart++;
				y=0;
			}
		}
	}
	return;
}

void decode(char *ch,char *code)
{
	int codestart=0,textstart=1000;
	string s[105];
	for (int i=0;i<N;i++)
	{
		s[i]="";
		int x,y;
		x=codestart;
		y=0;
		for (int j=0;j<63;j++)
		{
			if (((1<<y)&code[x])>0)
				s[i]=s[i]+'1';
			else
				s[i]=s[i]+'0';
			y++;
			if (y==8)
			{
				x++;
				y=0;
			}
		}
		codestart+=9;
	}
	for (int i=0;i<N;i++)
	{
		int maxlen=-1;
		for (int j=0;j<N;j++)
		if (i!=j)
		{
			for (int k=0;k<min(s[i].size(),s[j].size());k++)
			{
				if (s[i][k]!=s[j][k]) break;
				maxlen=max(maxlen,k+1);
			}
		}
		s[i]=s[i].substr(0,maxlen+1);
	}
	int tot=0;
	int son[2005][2];
	int is[2005];
	memset(son,-1,sizeof(son));
	for (int i=0;i<N;i++)
	{
		int now=0;
		for (int j=0;j<s[i].size();j++)
		{
			int t=s[i][j]-'0';
			if (son[now][t]==-1)
				son[now][t]=++tot;
			now=son[now][t];
		}
		is[now]=i;
	}
	int num=0,now=0,y=0;
	for (int i=0;num<M;i++)
	{
		int t;
		if ((1<<y)&code[textstart])
			t=1;
		else
			t=0;
		if (son[now][t]==-1)
		{
			ch[num++]=is[now];
			now=son[0][t];
		}
		else
			now=son[now][t];
		y++;
		if (y==8)
		{
			textstart++;
			y=0;
		}
	}
	return;
}
//************************************************************
int main()
{
	time_t start = clock();
	srand(time(0));
	while ((clock()-start)/CLOCKS_PER_SEC<=9.9)
	{
		memset(ch,0,sizeof(ch));
		memset(ch2,0,sizeof(ch2));
		memset(ch3,0,sizeof(ch3));
		memset(code,0,sizeof(code));
		makedata(ch);
		encode(ch2,code);
		decode(ch3,code);
		check(ch,ch3);
	}
	cout<<result<<endl;
}


//////////////////////////////////////////////////////
//Exam04-solution
/*
数字范围一共是0~249，我们需要把他们编码到二进制数组，每个数字能够占用16个bit，并且每次会有两位错，所以方法就是想办法设计能恢复两位的纠错码。
一个简单的方式就是，对于0~2^16范围内的每一个数字，如果他们在错1位的时候能够互相到达，那么我们就给他们连一条边，这样，就相当于，我们需要在这个图里面选超过250个点，使得这些点周围距离2的所有的点构成的集合没有交集。
那么就直接枚举每一个数字，如果他周围2的范围内的所有点都没有被标记过，就标记一下然后把这个作为这些数字的码字。
编码和恢复的过程中，需要在temp数组中二分寻找位置，否则会用很长时间。
*/
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define siz 1000
using namespace std;
int result;
char temp[1001][1001];
char ans[1001][1001];
char ch[1000005];
int mat[4][1001][1001];
void makedata(char *ch,int (*mat)[1001][1001])
{
	int x,y,f;
	for (int i=0;i<siz/2;i++)
		for (int j=0;j<siz/2;j++)
		{
			x=i; y=j;
			f=rand()%3;
			while (f--)
			{
				swap(x,y);
				y=siz-1-y;
			}
			mat[0][x][y]=1;
		}
	
	for (int i=0;i<siz;i++)
		for (int j=0;j<siz;j++)
			temp[i][j]=rand()%128;
	int tot=0;
	for (int k=0;k<=3;k++) 
	{
		for (int i=0;i<siz;i++)
			for (int j=0;j<siz;j++)
			{
				if (mat[k][i][j]==1) ch[tot++]=temp[i][j];
				if (k<3)
					mat[k+1][j][siz-1-i]=mat[k][i][j];
			}
	}
	
	for (int i=0;i<siz/2;i++)
		for (int j=0;j<siz/2;j++)
		{
			mat[0][i][j]=0;
		}
	return;
} 

void check(char (*ch)[1001],char (*ans)[1001])
{
	for (int i=0;i<siz;i++)
		for (int j=0;j<siz;j++)
		if (ch[i][j]!=ans[i][j])
		{
			result-=100;
			return;
		}
	result++;
	return;
}

//**************************your code***********************************// 
void work(char *ch,int mat[1001][1001],char (*ans)[1001])
{
	
	for (int i=0;i<siz/2;i++)
		for (int j=0;j<siz/2;j++)
		{
			int x=i,y=j;
			int flag=0;
			for (int k=1;k<=3;k++)
			{
				swap(x,y);
				y=siz-1-y;
				if (mat[x][y]==1) flag=1;
			}
			if (flag==0)
				mat[i][j]=1;
		}
	
	int tot=0;
	for (int k=0;k<=3;k++)
	for (int i=0;i<siz;i++)
		for (int j=0;j<siz;j++)
		{
			int x=i,y=j;
			int t=k;
			while (t--)
			{
				swap(x,y);
				x=siz-1-x;
			}
			
			if (mat[x][y]==1)
			{
				ans[i][j]=ch[tot];
				tot++;
			}
		}
}

//**********************************************************************//
int main()
{
	time_t start = clock();
	srand(0);
	while ((clock()-start)/CLOCKS_PER_SEC<=9.9)
	{
		memset(mat,0,sizeof(mat));
		makedata(ch,mat); 
		work(ch,mat[0],ans);
		check(temp,ans);
	}
	cout<<result<<endl;
}
///////////////////////////////////////////////////////////
//Exam05-solution
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define siz 1000
using namespace std;
int result;
int sudoku[10][10];
int can(int x,int y,int t)
{
	if (t<=0 || t>9) return 0;
	for (int i=1;i<=9;i++)
	{
		if (sudoku[x][i]==t && i!=y)
			return 0;
		if (sudoku[i][y]==t && i!=x)
			return 0;
	}
	for (int i=(x-1)/3*3+1;i<=(x-1)/3*3+3;i++)
		for (int j=(y-1)/3*3+1;j<=(y-1)/3*3+3;j++)
		if (sudoku[i][j]==t && (i!=x || j!=y))
			return 0;
	return 1;
}

void makedata(int (*sudoku)[10])
{
	for (int i=1;i<=20;i++)
	{
		int x,y,t;
		x=rand()%9+1;
		y=rand()%9+1;
		t=rand()%9+1;
		if (can(x,y,t))
		{
			sudoku[x][y]=t;		
		}
	}
}

void check(int (*sudoku)[10])
{
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
		if (can(i,j,sudoku[i][j])==0)
		{
			return;
		}
	result++;
	return;
}

//**************************your code***********************************// 
//you can use heap space
struct nod
{
	int x,y;	
}arr[105];
int tot=0;
int col[10][10],row[10][10],squ[10][10];
int ans[10][10];
int flag;
int ci=0;

int can2(int x,int y,int t)
{
	if (col[x][t]) return 0;
	if (row[y][t]) return 0;
	if (squ[(x-1)/3*3+(y-1)/3+1][t]) return 0;
	return 1;
}

void ins(int x,int y,int t,int f)
{
	col[x][t]=row[y][t]=squ[(x-1)/3*3+(y-1)/3+1][t]=f;
	if (f==1) ans[x][y]=t;
	else ans[x][y]=0;
	return;
}

void dfs(int now)
{
	ci++;
	if (ci>=300) return;
	if (now==tot+1)
	{
		flag=1;
		return;
	}
	if (flag) return;
	for (int t=1;t<=9;t++)
	{
		if (can2(arr[now].x,arr[now].y,t))
		{
			ins(arr[now].x,arr[now].y,t,1);
			dfs(now+1);
			if (flag) return;
			ins(arr[now].x,arr[now].y,t,0);
		}
	}
	return;
}
void work(int (*sudoku)[10])
{
	tot=flag=ci=0;
	memset(col,0,sizeof(col));
	memset(row,0,sizeof(row));
	memset(squ,0,sizeof(squ));
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
		{
			if (sudoku[i][j]==0)
			{
				tot++;
				arr[tot].x=i;
				arr[tot].y=j;
			}
			else
				ins(i,j,sudoku[i][j],1);
		}
	dfs(1);
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			sudoku[i][j]=ans[i][j];
	return;
}

//**********************************************************************//
int main()
{
	time_t start = clock();
	srand(99999999); //the seed will be change
	while ((clock()-start)/CLOCKS_PER_SEC<=9.9)
	{
		memset(sudoku,0,sizeof(sudoku));
		makedata(sudoku);
		work(sudoku);
		check(sudoku);
	}
	cout<<result<<endl;
}
////////////////////////////////////////////////////////
//Exam06-solution
#include<iostream>
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define N 20
using namespace std;
int edge[N][N];
int temp[N][N];
int flag = 0;
long long result = 0;

#define min(a, b) ((a)<(b) ? (a): (b))

void makedata()
{
	int x, y, len;
	for (int i = 1; i<N; i++)
	{
		x = i - 1; y = i;
		edge[x][y] = 99999;
		temp[x][y] = 99999;
	}
	for (int i = 1; i <= 100; i++)
	{
		x = rand() % N;
		y = rand() % N;
		len = rand() % 10000;
		edge[x][y] = len;
		temp[x][y] = len;
	}
}

int vs[N], tot, now;
void move(int y)
{
	if (flag != 0) return;
	if (edge[now][y] == -1) { flag = 2; return; }
	result += edge[now][y];
	now = y;
	if (vs[now] == 0) tot++; else vs[now] = 1;
	if (tot == N) flag = 1;
	return;
}
//**************************your code***********************************// 
//You can use function move(int y)
//and you can use heap space , memory limit : 256Mb
struct nod
{
	int sta, now;
	nod() {}
	nod(int x, int y){ sta = x; now = y; }
};
nod q[5000005];
int dist[1 << (N - 1)][N];
int pre[1 << (N - 1)][N];
int head, tail;
bool vis[1 << (N - 1)][N];
void get_tsp(int(*temp)[N])
{
	memset(dist, -1, sizeof(dist));
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	head = tail = 1;
	dist[0][0] = 0;
	vis[0][0] = 1;
	q[head] = nod(0, 0);
	while (head <= tail)
	{
		nod now = q[head % 5000000];
		head++;
		vis[now.sta][now.now] = 0;
		int dis = dist[now.sta][now.now];
		for (int j = 0; j<N; j++)
			if (temp[now.now][j] != -1)
			{
			nod nex = now;
			int len = dis + temp[now.now][j];
			nex.now = j;
			if (j != 0) nex.sta |= (1 << (j - 1));
			if (dist[nex.sta][nex.now] == -1 || dist[nex.sta][nex.now]>len)
			{
				dist[nex.sta][nex.now] = len;
				pre[nex.sta][nex.now] = now.sta * 100 + now.now;
				if (vis[nex.sta][nex.now] == 0)
				{
					tail++;
					q[tail % 5000000] = nex;
				}
			}
			}
	}
	int best = 99999999;
	int sta = (1 << (N - 1)) - 1, t = -1;
	for (int j = 0; j<N; j++)
		if (dist[(1 << (N - 1)) - 1][j] != -1)
		{
		best = min(best, dist[(1 << (N - 1)) - 1][j]);
		if (best == dist[(1 << (N - 1)) - 1][j])
			t = j;
		}
	int ans[N*N + N], num = 0;
	while (sta != 0 || t != 0)
	{
		ans[++num] = t;
		int tt = pre[sta][t];
		sta = tt / 100;
		t = tt % 100;
	}
	int a = 0;
	for (int i = num; i >= 1; i--)
	{
		a = ans[i];
		move(ans[i]);
	}
	return;
}

//**********************************************************************//
int main()
{
	time_t start = clock();
	srand(666); //the seed will be change
	for (int i = 1; i <= 10; i++)
	{
		flag = 0; now = 0;
		memset(vs, 0, sizeof(vs));
		vs[now] = 1; tot = 1;
		memset(edge, -1, sizeof(edge));
		memset(temp, -1, sizeof(temp));
		makedata();
		get_tsp(temp);
		if (flag != 1) { result += 99999999; }
	}
	time_t end = clock();
	double tim = (end - start + 0.0) / CLOCKS_PER_SEC;
	if (tim >= 20) result += 99999999;
	cout << result << endl;
}


//////////////////////////////////////////////////////////////////
//Disk 
//完全消除噪声并且正确的disk代码
#include <iostream>
#include <memory.h>
#include <time.h>
using namespace std;

static char disk[65536 * 512]; // 32M HDD

static char tmpdisk[65536 * 512]; // 32M HDD

static int dummy1[12];

static char fname[100][32]; // 100 Filenames

static int  fsize[100];

static char filedata[100][65536];  // 64K Files


static int seed = 0;

extern void read_disk(int sector, char data[512]);
extern void write_disk(int sector, char data[512]);

void read_disk(int sector, char data[512])
{
	memcpy(data, disk + sector * 512, 512);
}

void write_disk(int sector, char data[512])
{
	memcpy(disk + sector * 512, data, 512);
}

static int random_gen(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

static int _read_file(int file, int pos, char data[4096], int size)
{
	if (fsize[file] < size)
		size = fsize[file];
	if (pos > fsize[file] - size) {
		pos = fsize[file] - size;
	}
	memcpy(data, filedata[file] + pos, size);

	return size;
}

static void _write_file(int file, int pos, char data[4096], int size)
{
	if (pos + size > 65536)
		size = 65536 - pos;
	if (pos + size > fsize[file])
		fsize[file] = pos + size;

	memcpy(filedata[file] + pos, data, size);
}

extern void read_file(char fname[32], int pos, char data[4096], int size);
extern void write_file(char fname[32], int pos, char data[4096], int size);


int main(void)
{
	//for (int se = 0;  se < 100; se++) {

	//seed = 3;  // the seed will be changed
	//seed = se;
	seed = 2;
	printf("---------------seed=%d------------\n", seed);

	memset(disk, 0, sizeof(disk));
	memset(fname, 0, sizeof(fname));
	memset(filedata, 0, sizeof(filedata));

	//初始化100个文件，文件名，文件大小，文件数据
	for (int c = 0; c < 100; c++)
	{
		int length = 16 + random_gen() % 16;

		for (int l = 0; l < length; l++)
			fname[c][l] = 'A' + random_gen() % 26;

		fname[c][length] = 0;
		fsize[c] = 0;
	}

	int errCnt = 0;

	clock_t TIME = clock();

	int RESULT = 0;

	for (int loop = 0; loop < 25000; loop++)
	{
		int  mode = (loop < 5000) ? 10 : random_gen() % 10;
		int  file = random_gen() % 100;
		int  pos = (random_gen() | (random_gen() << 15)) % 65536;
		int  size = 1 + random_gen() % 4096;

		char name[32];
		char data[4096];
		char _data[4096];

		if (mode < 9) // read
		{
			memcpy(name, fname[file], 32);
			read_file(name, pos, data, size);
			size = _read_file(file, pos, _data, size);//从file的pos位置开始读取size的数据到_data里

			if (memcmp(data, _data, size) != 0) {
				//	printf("ERROR: fidx=%d, pos=%d, size=%d\n", file, pos, size);
				RESULT += 100000;
				errCnt++;
			}
		}
		else // write
		{
			//产生size大小的随机数据放在data[4096]的数组里
			for (register int c = 0; c < size; c++)
				data[c] = random_gen() % 256;

			memcpy(name, fname[file], 32);
			_write_file(file, pos, data, size); //讲data[4096]里的size大小的数据写到file里
			write_file(name, pos, data, size);
		}


		//memcpy(tmpdisk, disk, 65536 * 512);
		//20次随机噪声
		for (int i = 0; i < 20; ++i)
		{
			int err = random_gen() % 256;
			int pos = (random_gen() | (random_gen() << 15)) % (65536 * 512);
			disk[pos] = err;
		}

		//memset(disk + 64042, 0, sizeof(char));
		//memset(tmpdisk + 64042, 0, sizeof(char));

	}

	RESULT += (clock() - TIME) / (CLOCKS_PER_SEC / 1000);

	cout << "RESULT : " << RESULT << endl;
	cout << "ERR CNT: " << errCnt << endl;
	//}
	return 0;
}


////////////////////////////////////////////////////////////////////////
#define FILE_BLOCKS  128
#define _100FILES_BLOCKS 12800
#define SECTOR_SIZE 512
#define _100FILENAME_BLOCKS 7
#define DATA_BLOCK_SIZE 4096

char recByte(char byte[5]){
	int i, j;
	int cnt[5] = { 1, 1, 1, 1, 1 };
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++){
			if (i == j) continue;
			if (byte[i] == byte[j]) {
				cnt[i]++;
				if (cnt[i] >= 3) {
					return byte[i];
				}
			}
		}
	}
	int max = 0, k;
	for (i = 0; i < 5; i++){
		if (cnt[i] > max) {
			max = cnt[i];
			k = i;
		}
	}

	return byte[k];
}
//len= 512, cnt = 5
void check(char str[][512], int len, int cnt, char ret[512]) {
	char byte[5];

	for (int j = 0; j < len; j++){
		for (int i = 0; i < cnt; i++) {
			byte[i] = str[i][j];
		}
		char b = recByte(byte);

		ret[j] = b;
	}
}

//len= 4096, cnt = 5
void check2(char str[][DATA_BLOCK_SIZE], int len, int cnt, char ret[DATA_BLOCK_SIZE]) {
	char byte[5];

	for (int j = 0; j < len; j++){
		for (int i = 0; i < cnt; i++) {
			byte[i] = str[i][j];
		}
		char b = recByte(byte);

		ret[j] = b;
	}
}

void setOpCnt(int opCnt, int offset) {
	int start = 5 * _100FILES_BLOCKS + 5 * _100FILENAME_BLOCKS + 5;
	char sectorData[512];
	read_disk(start, sectorData);

	int cnt = 20;
	for (int i = 0; i < cnt; i++){
		memcpy(sectorData + offset + i * 4, &opCnt, 4);
	}
	write_disk(start, sectorData);
}
void setReadCnt(int readCnt) {
	setOpCnt(readCnt, 0);
}
void setWriteCnt(int writeCnt) {
	setOpCnt(writeCnt, 100);
}
int getOpCnt(int ofset) {
	int start = 5 * _100FILES_BLOCKS + 5 * _100FILENAME_BLOCKS + 5;
	char sectorData[512];
	read_disk(start, sectorData);

	int cnt = 20;
	int rdcnt[20] = { 0 };
	for (int i = 0; i < cnt; i++){
		memcpy(&rdcnt[i], sectorData + ofset + i * 4, 4);
	}
	int n = 0, flag = 0;
	int tmpcnt = rdcnt[0];
	for (int i = 0; i < cnt; i++){
		if (rdcnt[i] == tmpcnt) {
			n++;
		}
		else{
			n--;
			flag = 1;
			if (n == 0)
				tmpcnt = rdcnt[i];
		}
	}
	if (flag == 1) { //恢复操作磁盘次数
		setOpCnt(tmpcnt, ofset);
	}
	if (tmpcnt < 0 || tmpcnt > 25000) {
		tmpcnt = -1;
	}
	return tmpcnt;
}
int getReadCnt() {
	return getOpCnt(0);
}
int getWriteCnt() {
	return getOpCnt(100);
}

//idx是文件的索引号
void writeFileSize(int idx, int size) {
	int start = _100FILES_BLOCKS * 5 + _100FILENAME_BLOCKS * 5;
	int i = 0;
	char sectorData[512];
	for (i = 0; i < 5; i++){
		read_disk(start + i, sectorData);
		memcpy(sectorData + idx * 4, &size, 4);
		write_disk(start + i, sectorData);
	}
}

int readFileSize(int idx) {
	int start = _100FILES_BLOCKS * 5 + _100FILENAME_BLOCKS * 5;
	int i = 0;
	char sectorData[512];
	int fsize[5];
	read_disk(start + i, sectorData);
	memcpy(&fsize[i], sectorData + idx * 4, 4);

	int size = fsize[0];
	return size;
}

void writeAFileName(int startSector, int idx, char fname[32]){
	int sector_idx_offset = idx / 16;
	char sectorData[512];
	read_disk(startSector + sector_idx_offset, sectorData);
	int offset = idx % 16;
	memcpy(sectorData + offset * 32, fname, 32);
	write_disk(startSector + sector_idx_offset, sectorData);
}

void writeFileNames(int idx, char fname[32]){
	int start = _100FILES_BLOCKS * 5;
	int i = 0;
	for (i = 0; i < 5; i++) {
		writeAFileName(start + i * _100FILENAME_BLOCKS, idx, fname);
	}
}

void readAFileName(int startSector, int idx, char fname[32]) {
	int sector_idx_offset = idx / 16;
	char sectorData[512];
	read_disk(startSector + sector_idx_offset, sectorData);
	int offset = idx % 16;
	memcpy(fname, sectorData + offset * 32, 32);
}

void readFileNames(int idx, char fname[32]) {
	int start = _100FILES_BLOCKS * 5;
	int i = 0;
	char tmpName[5][32];
	readAFileName(start + i * _100FILENAME_BLOCKS, idx, tmpName[0]);

	memcpy(fname, tmpName[0], 32);
}

int getFileIdxFromName(char fname[32]) {
	char tmpName[32];
	int i;
	for (i = 0; i < 100; i++) {
		readFileNames(i, tmpName);
		if (tmpName[0] == '\0') {
			return i;
		}
		if (memcmp(tmpName, fname, 32) == 0) {
			return i;
		}
	}
	return -1;
}

void writeAFileData(int startSector, int pos, char data[DATA_BLOCK_SIZE], int size) {
	int blk_idx_offset = pos / SECTOR_SIZE;
	char sectordata[SECTOR_SIZE] = { '\0' };
	read_disk(startSector + blk_idx_offset, sectordata);

	int offset = pos % SECTOR_SIZE;

	if (size > (SECTOR_SIZE - offset)) {
		memcpy(sectordata + offset, data, SECTOR_SIZE - offset);
		write_disk(startSector + blk_idx_offset, sectordata);

		size = size - (SECTOR_SIZE - offset);
		int i = 1;
		while (size >= SECTOR_SIZE) {
			memcpy(sectordata, data + (SECTOR_SIZE - offset) + ((i - 1) * SECTOR_SIZE), SECTOR_SIZE);
			write_disk(startSector + blk_idx_offset + i, sectordata);
			i++;
			size -= SECTOR_SIZE;
		}
		if (size > 0)
		{
			read_disk(startSector + blk_idx_offset + i, sectordata);
			memcpy(sectordata, data + (SECTOR_SIZE - offset) + ((i - 1) * SECTOR_SIZE), size);
			write_disk(startSector + blk_idx_offset + i, sectordata);
		}
	}
	else {
		memcpy(sectordata + offset, data, size);
		write_disk(startSector + blk_idx_offset, sectordata);
	}
}

//idx是文件的索引
void writeFileDatas(int idx, int pos, char data[DATA_BLOCK_SIZE], int size) {
	int start = 0;
	int i = 0;

	int fsize = readFileSize(idx);
	if (fsize == -1) {
		printf("file %d filesize bug. \n", idx);
		return;
	}

	if (pos + size > 65536)
		size = 65536 - pos;
	if (pos + size > fsize)
		fsize = pos + size;

	writeFileSize(idx, fsize);

	start = idx * FILE_BLOCKS;

	for (i = 0; i < 5; i++) {
		/*	start = idx * FILE_BLOCKS + i * _100FILES_BLOCKS;*/
		writeAFileData(start, pos, data, size);
		start += 12800;
	}
}
//idx读文件数据
void readAFileData(int startSector, int pos, char data[DATA_BLOCK_SIZE], int size) {
	int blk_idx_offset = pos / SECTOR_SIZE;
	int offset = pos % SECTOR_SIZE;
	char sectordata[SECTOR_SIZE] = { '\0' };

	read_disk(startSector + blk_idx_offset, sectordata);

	if (size <= (SECTOR_SIZE - offset)){
		memcpy(data, sectordata + offset, size);
	}
	else{
		memcpy(data, sectordata + offset, SECTOR_SIZE - offset);
		size = size - (SECTOR_SIZE - offset);
		int i = 1;
		while (size >= SECTOR_SIZE){
			read_disk(startSector + blk_idx_offset + i, sectordata);
			memcpy(data + (SECTOR_SIZE - offset) + ((i - 1) * SECTOR_SIZE), sectordata, SECTOR_SIZE);
			i++;
			size -= SECTOR_SIZE;
		}
		if (size > 0) {
			read_disk(startSector + blk_idx_offset + i, sectordata);
			memcpy(data + (SECTOR_SIZE - offset) + ((i - 1)*SECTOR_SIZE), sectordata, size);
		}
	}
}

//idx是文件的索引号
void readFileDatas(int idx, int pos, char data[DATA_BLOCK_SIZE], int size) {
	int start = 0;
	int i = 0;
	char tmpData[5][DATA_BLOCK_SIZE] = { '\0' };

	int fsize = readFileSize(idx);
	if (fsize == -1) {
		printf("file %d filesize bug. \n", idx);
		return;
	}

	if (fsize < size)
		size = fsize;
	if (pos > fsize - size) {
		pos = fsize - size;
	}
	start = idx * FILE_BLOCKS;
	for (i = 0; i < 5; i++) {
		//start = idx * FILE_BLOCKS + i * _100FILES_BLOCKS;
		readAFileData(start, pos, tmpData[i], size);
		start += 12800;
	}
	char ret[DATA_BLOCK_SIZE];
	check2(tmpData, DATA_BLOCK_SIZE, 5, ret);

	//writeFileDatas(idx, pos, ret, size);

	memset(data, 0, sizeof(data));
	memcpy(data, ret, DATA_BLOCK_SIZE);
}

void recoverMeta() {
	int i = 0, j;
	char sectorDatas[5][512] = { '\0' };
	char ret[512] = { '\0' };
	int start = 5 * _100FILES_BLOCKS;
	for (i = 0; i < 7; i++) {
		for (j = 0; j < 5; j++) {
			read_disk(start + i + j * _100FILENAME_BLOCKS, sectorDatas[j]);
		}
		check(sectorDatas, 512, 5, ret);
		for (j = 0; j < 5; j++){
			write_disk(start + i + j * _100FILENAME_BLOCKS, ret);
		}
	}
	start = 5 * _100FILES_BLOCKS + 5 * 7;
	for (j = 0; j < 5; j++){
		read_disk(start + j, sectorDatas[j]);
	}
	check(sectorDatas, 512, 5, ret);
	for (j = 0; j < 5; j++){
		write_disk(start + j, ret);
	}
}

void recoverDisk() {
	int i = 0, j, k;
	char sectorDatas[5][512] = { '\0' };
	char ret[512] = { '\0' };


	for (i = 0; i < _100FILES_BLOCKS; i++) {
		for (j = 0; j < 5; j++) {
			read_disk(i + j * _100FILES_BLOCKS, sectorDatas[j]);
		}

		check(sectorDatas, 512, 5, ret);

		for (j = 0; j < 5; j++){
			write_disk(i + j * _100FILES_BLOCKS, ret);
		}
	}
}

void read_file(char fname[32], int pos, char data[DATA_BLOCK_SIZE], int size){

	int curCnt = getReadCnt();

	if (curCnt == -1) {
		printf("Disk has been crupted\n");
		return;
	}

	recoverMeta();

	if ((curCnt + 1) % 9000 == 0) {
		recoverDisk();
	}

	curCnt++;
	setReadCnt(curCnt);


	int idx = getFileIdxFromName(fname);
	if (idx == -1) {
		printf("fname is lost: %s\n", fname);
		return;
	}
	readFileDatas(idx, pos, data, size);
}

int writeCnt = 0;

void write_file(char fname[32], int pos, char data[DATA_BLOCK_SIZE], int size){

	int curCnt = getWriteCnt();
	if (curCnt != writeCnt) {
		printf("Write Cnt is crupted curCnt = %d, writeCnt = %d\n", curCnt, writeCnt);
	}

	writeCnt++;

	if (curCnt == -1) {
		printf("Disk has been crupted\n");
		return;
	}
	recoverMeta();
	if ((curCnt + 1) % 5000 == 0){
		recoverDisk();
	}

	curCnt++;
	setWriteCnt(curCnt);

	int idx = getFileIdxFromName(fname);
	if (idx == -1) {
		printf("fname is lost: %s\n", fname);
		return;
	}
	writeFileNames(idx, fname);
	writeFileDatas(idx, pos, data, size);
}



//////////////////////////////////////////////////////////
//Encode-Decode 加噪声，旋转，翻转后恢复数据
//完全正确的代码
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<memory.h>

#define MAXN 4096

void outputbitmap(unsigned char bitmap[256][32]);
void outputdata(unsigned char data[4096]);

extern void encode(unsigned char bitmap[256][32], unsigned char data[4096]);
extern void decode(unsigned char data[4096], unsigned char bitmap[256][32]);

static void setpixel(unsigned char bitmap[256][32], int x, int y, int pixel)
{
	unsigned char mask = 0x80 >> (x % 8);

	if (pixel == 0) bitmap[y][x / 8] &= ~mask;
	else bitmap[y][x / 8] |= mask;
}

static int getpixel(unsigned char bitmap[256][32], int x, int y)
{
	unsigned char mask = 0x80 >> (x % 8);

	if ((bitmap[y][x / 8] & mask) == 0) return 0;
	else return 1;
}

static void noise(unsigned char bitmap[256][32])
{
	for (register int y = 0; y < 256; y += 2)
		for (register int x = 0; x < 256; x += 2)
		{
		setpixel(bitmap, x + rand() % 2, y + rand() % 2, 0);
		setpixel(bitmap, x + rand() % 2, y + rand() % 2, 1);
		}
}

static void rotate(unsigned char bitmap[256][32], int angle)
{
	static unsigned char buffer[256][32];

	if (angle != 0)
	{
		switch (angle)
		{
		case 1://90
			for (register int y = 0; y < 256; y++)
				for (register int x = 0; x < 256; x++)
					setpixel(buffer, x, y, getpixel(bitmap, y, 255 - x));
			break;
		case 2://180
			for (register int y = 0; y < 256; y++)
				for (register int x = 0; x < 256; x++)
					setpixel(buffer, x, y, getpixel(bitmap, 255 - x, 255 - y));
			break;
		case 3://270
			for (register int y = 0; y < 256; y++)
				for (register int x = 0; x < 256; x++)
					setpixel(buffer, x, y, getpixel(bitmap, 255 - y, x));
			break;
		}

		for (register int y = 0; y < 256; y++)
			for (register int x = 0; x < 256; x++)
				setpixel(bitmap, x, y, getpixel(buffer, x, y));
	}
}

static void flip(unsigned char bitmap[256][32], int mode)
{
	static unsigned char buffer[256][32];

	if (mode != 0)
	{
		switch (mode)
		{
		case 1://horizontal
			for (register int y = 0; y < 256; y++)
				for (register int x = 0; x < 256; x++)
					setpixel(buffer, x, y, getpixel(bitmap, x, 255 - y));
			break;
		case 2://vertical
			for (register int y = 0; y < 256; y++)
				for (register int x = 0; x < 256; x++)
					setpixel(buffer, x, y, getpixel(bitmap, 255 - x, y));
			break;
		}

		for (register int y = 0; y < 256; y++)
			for (register int x = 0; x < 256; x++)
				setpixel(bitmap, x, y, getpixel(buffer, x, y));
	}
}

int main()
{
	freopen("output.txt", "w", stdout);

	static const int TCSIZE = 1024;
	//static const int TCSIZE = 1;


	static unsigned char data[TCSIZE][4096] = { 0 };
	static unsigned char org[TCSIZE][4096] = { 0 };
	static unsigned char bitmap[TCSIZE][256][32] = { 0 };
	static unsigned char result[TCSIZE][4096] = { 0 };

	srand(3);//the seed will be changed;

	for (register int TC = 0; TC < TCSIZE; TC++)
		for (register int c = 0; c < 4096; c++)
			org[TC][c] = data[TC][c] = rand() % 15;

	int PERFORMANCE = 10000;

	time_t start = clock();
	for (register int TC = 0; TC < TCSIZE; TC++)
		encode(bitmap[TC], data[TC]);
	PERFORMANCE -= (clock() - start) / (CLOCKS_PER_SEC / 1000);

	//printf("encode:\n");
	//outputdata(data[0]);
	//outputbitmap(bitmap[0]);

	for (register int TC = 0; TC < TCSIZE; TC++)
	{
		noise(bitmap[TC]);
		rotate(bitmap[TC], rand() % 4);
		flip(bitmap[TC], rand() % 3);

		//rotate(bitmap[TC], 3);
		//flip(bitmap[TC], 1);
	}

	start = clock();
	for (register int TC = 0; TC < TCSIZE; TC++)
		decode(result[TC], bitmap[TC]);
	PERFORMANCE -= (clock() - start) / (CLOCKS_PER_SEC / 1000);

	//printf("decode:\n");
	//outputdata(result[0]);
	//outputbitmap(bitmap[0]);

	int PASS = 0;
	int ERR = 0;
	for (register int TC = 0; TC < TCSIZE; TC++)
		if (memcmp(org[TC], result[TC], 4096) == 0) {
			PASS++;
		}
		else
		{
			ERR++;
			printf("TC:%d PERFORMANCE:%d\n", TC, PERFORMANCE);
		}

	printf("SCORE:%d\n", PASS * 10000 + PERFORMANCE);
	printf("ERR: %d\n", ERR);
	return 0;
}


/*********************************USer COde**************************************/

void outputbitmap(unsigned char bitmap[256][32]){
	int i, j;
	for (i = 0; i < 256; i++){
		for (j = 0; j < 32; j++){
			printf("%x\t", bitmap[i][j]);
		}
		printf("\n");
	}
}
void outputdata(unsigned char data[4096]) {
	int i;
	for (i = 0; i < 4096; i++) {
		printf("%x\t", data[i]);
	}
	printf("\n");
}

void outputBits(int bits[][128]){
	for (int i = 0; i < 128; i++){
		for (int j = 0; j < 128; j++){
			printf("%d\t", bits[i][j]);
		}
		printf("\n");
	}
}

void itob(int d, int a[4]){
	int i = 0;
	a[0] = a[1] = a[2] = a[3] = 0;
	while (d) {
		a[i] = d & 1;
		d = d >> 1;
		i++;
	}
}
int btoi(int a[4]) {
	int d = 0;
	for (int i = 3; i > -1; i--){
		d = d << 1;
		d |= a[i];
	}
	return d;
}

void getBit(unsigned char bitmap[256][32], int x, int y, int & b) {
	int b1 = getpixel(bitmap, x, y);
	int b2 = getpixel(bitmap, x+1, y);
	int b3 = getpixel(bitmap, x, y+1);
	int sum = b1 + b2 + b3;
	if (sum <= 1) {
		b = 0;
	}
	else{
		b = 1;
	}
}

void getBit1(unsigned char bitmap[256][32], int x, int y, int & b) {
	b = getpixel(bitmap, x+1, y+1);
}

void setBit(unsigned char bitmap[256][32], int x, int y, int b) {
	setpixel(bitmap, x, y, b);
	setpixel(bitmap, x + 1, y, b);
	setpixel(bitmap, x, y + 1, b);
	setpixel(bitmap, x + 1, y + 1, 0);
}

void setBit1(unsigned char bitmap[256][32], int x, int y, int b) {
	setpixel(bitmap, x+1, y+1, b);
}

void setCode(unsigned char bitmap[256][32], int x, int y, int a[4]) {
	int i, j, n = x + 4, m = y + 4, k = 0;
	for (i = x; i < n; i+=2){
		for (j = y; j < m; j+=2){
			setBit(bitmap, i, j, a[k]);
			k++;
		}
	}
}
void setCode1(unsigned char bitmap[256][32], int x, int y, int a[4]) {
	int i, j, n = x + 4, m = y + 4, k = 0;
	for (i = x; i < n; i += 2){
		for (j = y; j < m; j += 2){
			setBit1(bitmap, i, j, a[k]);
			k++;
		}
	}
}
void getCode(unsigned char bitmap[256][32], int x, int y, int a[4]){
	int i, j, n = x + 4, m = y + 4, k= 0;
	for (i = x; i < n; i += 2) {
		for (j = y; j < m; j += 2) {
			getBit(bitmap, i, j, a[k]);
			k++;
		}
	}
}
void getCode1(unsigned char bitmap[256][32], int x, int y, int a[4]){
	int i, j, n = x + 4, m = y + 4, k = 0;
	for (i = x; i < n; i += 2) {
		for (j = y; j < m; j += 2) {
			getBit1(bitmap, i, j, a[k]);
			k++;
		}
	}
}

void encode(unsigned char bitmap[256][32], unsigned char data[4096]) {
	int i = 0,j = 0, x, y, m = 0;
	int a[4];
	for (i = 0; i < 4096; i++){
		itob(data[i], a);
		x = i / 64; 
		y = i % 64;

		//printf("x=%d, y=%d\n", x*4, y*4);

		setCode(bitmap, x * 4, y * 4, a);
	}

	a[0] = a[1] = a[2] = a[3] = 1;
	for (x = 0; x < 16*4; x += 4) {
		for (y = 0; y < 32*4; y += 4) {
			setCode1(bitmap, x, y, a);
		}
	}
}

//c = 0, 左上角, c = 1, 右上角, c = 2: 左下角, c = 3: 右下角
void getExtraBits(unsigned char bitmap[256][32], int bits[128][128], int c) {
	int i, j, x, y;
	x = y = 0;
	for (i = 0; i < 256; i += 2) {
		for (j = 0; j < 256; j += 2) {
			x = i >> 1;
			y = j >> 1;
			if (c == 0) {
				bits[x][y] = getpixel(bitmap, i, j);
			}
			else if (c == 1) {
				bits[x][y] = getpixel(bitmap, i, j + 1);
			}
			else if (c == 2) {
				bits[x][y] = getpixel(bitmap, i + 1, j);
			}
			else{
				bits[x][y] = getpixel(bitmap, i + 1, j + 1);
			}
		}
	}
}

//dir = 0 横着 , dir = 1 竖着
bool check(int bits[128][128], int x, int y, int dir) {
	int cnt = 0;
	int r; int c;
	//横着
	if (dir == 0) {
		r = 32; c = 64;
	}
	else{//竖着
		r = 64; c = 32;
	}
	for (int i = x; i < x + r; i++){
		for (int j = y; j < y + c; j++){
			if (bits[i][j] == 1){
				cnt++;
			}
		}
	}
	if (cnt >= (64 * 32) * 0.7) {
		return true;
	}
	return false;
}

void search(unsigned char bitmap[256][32]) {
	int bits[128][128];
	getExtraBits(bitmap, bits, 3); //取右下
	if (check(bits, 0, 0, 0)) { //验证左上横
		return;
	}
	if (check(bits, 0, 0, 1)) { //验证左上竖
		flip(bitmap, 2);
		rotate(bitmap, 3);
		return;
	}
	getExtraBits(bitmap, bits, 2); //取左下
	if (check(bits, 0, 96, 1)) { //验证右上竖
		rotate(bitmap, 1);
		return;
	}
	if (check(bits, 0, 64, 0)){ //验证右上横
		flip(bitmap, 2);
		rotate(bitmap, 2);
		return;
	}
	getExtraBits(bitmap, bits, 1);
	if (check(bits, 64, 0, 1)) {
		rotate(bitmap, 3);
		return;
	}
	if (check(bits, 96, 0, 0)) {
		flip(bitmap, 2);
		return;
	}
	getExtraBits(bitmap, bits, 0);
	if (check(bits, 96, 64, 0)) {
		rotate(bitmap, 2);
		return;
	}
	if (check(bits, 64, 96, 1)){
		flip(bitmap, 1);
		rotate(bitmap, 3);
		return;
	}
	return;
}

void decode(unsigned char data[4096], unsigned char bitmap[256][32]){
	int i = 0, x = 0, y = 0, d;
	int a[4];

	search(bitmap);
	
	for (x = 0; x < 64; x++){
		for (y = 0; y < 64; y++){
			i = x * 64 + y;
			getCode(bitmap, x*4, y*4, a);
			d = btoi(a);
			data[i] = d;
		}
	}
}


///////////////////////////////////////////////////////////
//大数乘法 代码
#if 1

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

using namespace std;

#define MIN_H 64
#define MAX_H 128
#define MAX_R MAX_H * 2

extern void mul(char* result, const char* h1, const char* h2);

char result[MAX_R + 1];
char h1[MAX_H + 1];
char h2[MAX_H + 1];

char get_char_first(void)
{
	int a = rand() % 35;
	if (a < 9)
		return a + 49;
	return a + 56;
}

char get_char(void)
{
	int a = rand() % 36;
	if (a < 10)
		return a + 48;
	return a + 55;
}

int make_num(char* s)
{
	s[0] = get_char_first();
	int len = rand() % (MAX_H - MIN_H + 1) + MIN_H;
	for (int i = 1; i < len; ++i)
		s[i] = get_char();
	s[len] = 0;
	return len;
}

int main(void)
{
	int TC = 50;
	//int TC = 1;

	srand(3);  // the seed will be changed

	time_t start = clock();

	cout << "output: " << endl;
	for (int test_case = 1; test_case <= TC; ++test_case)
	{
		int sum = 0;
		for (register int c = 0; c < 10000; ++c)
		{
			int a = make_num(h1);
			int b = make_num(h2);
			mul(result, h1, h2);
			sum += result[rand() % (a + b - 1)];
		}
		int len = strlen(result);
		sum += len;
		for (int i = 0; i < len; ++i)
			sum += result[i];
		cout << "#" << test_case << " " << sum << endl;
	}

	time_t end = clock();
	cout << "performance : " << ((end - start) / (CLOCKS_PER_SEC / 1000)) << endl;

	return 0;
}



/////////////////////////////////////////////////User Code/////////////////////////////////////

char ch[36] = {
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z'
};

int _36pow[6] = { 1, 36, 1296, 46656, 1679616, 8398080 };
//int _36pow[6] = { 1, 10, 100, 1000, 10000, 100000 };

//long long I1[MAX_H] = {4, 1, 3, 7};
//int nrI1 = 4;
//long long I2[MAX_H] = {6, 4, 7, 8};
//int nrI2 = 4;

unsigned long long I1[MAX_H] = { 0 };
int nrI1;
unsigned long long I2[MAX_H] = { 0 };
int nrI2;

unsigned long long JinWei[MAX_H * 2];
unsigned long long Res[MAX_H * 2];
int nrRes;

int num(char ch) {
	if (ch <= '9' && ch >= '0') {
		return ch - '0';
	}
	return ch - 'A' + 10;
}

int strLen(const char * str) {
	const char *p = str;
	int n = 0;
	while (*p) {
		p++;
		n++;
	}
	return n;
}

void charToInt(const char * h, int c, unsigned long long M[], int & mn) {
	int n = strLen(h);
	
	int i = 0, j = 0, p;
	int k = 0;
	for (i = 0; i < n; i += c){
		
		int sum = 0;
		p = 0;
		for (j = i; j < i + c && j < n; j++){
			int s = num(h[j]);
			sum += (s * _36pow[p++]);
		}

		M[k] = sum;
		k++;
	}
	mn = k;
}

void intToChar(unsigned long long L[], int n, int c, char* result) {
	int i, j, k;
	int cnt = 0;
	for (i = 0; i < n; i++) {

		for (j = 0; j < c; j++) {

			if (i == n - 1 && j == c-1) {
				if (L[i] == 0) {
					break;
				}
			}

			k = (i * c) + j;
			result[k] = ch[L[i] % 36];
			L[i] = L[i] / 36;
			cnt++;
		}
	}
	result[cnt] = '\0';
}

void mul(char* result, const char* h1, const char* h2) {
	int c = 4;
	charToInt(h1, c, I1, nrI1);
	charToInt(h2, c, I2, nrI2);

	JinWei[0] = 0;
	int i, j;
	for (i = 0; i < nrI2; i++) {

		for (j = 0; j < nrI1; j++) {
			unsigned long long S = I2[i] * I1[j];
			
			JinWei[i + j + 1] += ((S + JinWei[i + j]) / _36pow[c]);
			
			int Zhi = (S + JinWei[i + j]) % _36pow[c];

			Res[i + j] += Zhi;

			Res[i + j + 1] += (Res[i + j] / _36pow[c]);
			
			Res[i + j] = Res[i + j] % _36pow[c];

			JinWei[i + j] = 0;
			
		}
	}
	if (JinWei[i + j - 1] == 0) {
		nrRes = nrI1 + nrI2 - 1;
	}
	else {
		nrRes = nrI1 + nrI2;
	}
	Res[i + j - 1] = JinWei[i + j - 1];

	intToChar(Res, nrRes, c, result);
}

//void main() {
//	char h1[10] = "A12B";
//	char h2[10] = "2T3F";
//	char result[20] = { '\0' };
//
//	mul(result, h1, h2);
//
//}

#endif



#if 0
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>

using namespace std;

#define MIN_H 64
#define MAX_H 128
#define MAX_R MAX_H * 2

extern void mul(char* result, const char* h1, const char* h2);

char result[MAX_R + 1];
char h1[MAX_H + 1] = "A12B";
char h2[MAX_H + 1] = "2T3F";

char get_char_first(void)
{
	int a = rand() % 35;
	if (a < 9)
		return a + 49;
	return a + 56;
}

char get_char(void)
{
	int a = rand() % 36;
	if (a < 10)
		return a + 48;
	return a + 55;
}

int make_num(char* s)
{
	s[0] = get_char_first();
	int len = rand() % (MAX_H - MIN_H + 1) + MIN_H;
	for (int i = 1; i < len; ++i)
		s[i] = get_char();
	s[len] = 0;
	return len;
}


int strl(const char* s)
{
	int len = 0;
	while (s[len] != '\0')
		len++;
	return len;
}

int char2num(const char* s, int h[])
{
	int len, len1, i = 0;
	len1 = strl(s);
	len = len1 - 1;
	while (s[len] != '\0')	{
		if (s[len] >= '0' && s[len] <= '9'){
			h[i] = s[len] - 48;
			//			if (h[i] > 9 || h[i] < 0)
			//				return 0;
		}
		else {
			h[i] = s[len] - 55;
			//			if (h[i] > 35 || h[i] < 10)
			//				return 0;
		}
		len--; i++;
	}

	return len1;
}

void mul(char* result, const char* h1, const char* h2)
{
	int p[MAX_R + 1];
	int hh1[MAX_H], hh2[MAX_H];
	int len1, len2, i, j, len;
	len1 = char2num(h1, hh1);
	len2 = char2num(h2, hh2);
#if 1
	for (i = 0; i <= MAX_R; i++)
		p[i] = 0;
#endif
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++)	{
			//m[i][i + j] = hh1[i] * hh2[j];
			p[i + j] = p[i + j] + hh1[i] * hh2[j];
			if (p[i + j] > 35) {
				p[i + j + 1] = p[i + j + 1] + p[i + j] / 36;
				p[i + j] = p[i + j] % 36;
			}
		}
	}

	len = MAX_R;

	while (p[len] == 0)
		len--;
	for (i = 0; i <= len; i++){
		if (p[len - i] >= 0 && p[len - i] <= 9)
			*(result + i) = (char)(p[len - i] + 48);
		else if (p[len - i] >= 10 && p[len - i] <= 35)
			*(result + i) = (char)(p[len - i] + 55);
		//		else
		//			cout << "error: " << result[i] << endl;
	}
	*(result + len + 1) = '\0';
}

int main(void)
{
	srand(3);  // the seed will be changed

	time_t start = clock();

	cout << "output: " << endl;
	for (int test_case = 1; test_case <= 50; ++test_case)
	{
		int sum = 0;
		for (register int c = 0; c < 1; ++c)
		{
			//int a = make_num(h1);
			//int b = make_num(h2);

			


			mul(result, h1, h2);



			//sum += result[rand() % (a + b - 1)];
		}
		int len = strlen(result);
		sum += len;
		for (int i = 0; i < len; ++i)
			sum += result[i];
		cout << "#" << test_case << " " << sum << endl;
	}

	time_t end = clock();
	cout << "performance : " << ((end - start) / (CLOCKS_PER_SEC / 1000)) << endl;

	return 0;
}
#endif

//////////////////////////////////////////////////////////
//图像识别 代码

#include <stdio.h>


static const char alpha[10][8][8] = {
		{ // 0
			{ 0, 0, 0, 0, 8, 8, 8, 8 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{ // 1
			{ 0, 0, 0, 0, 8, 8, 8, 8 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 }
		},
		{ // 2
			{ 0, 0, 0, 0, 8, 8, 8, 8 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 8, 8, 8 }
		},
		{ // 3
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 0, 0, 0 },
			{ 0, 0, 0, 0, 8, 8, 8, 8 }
		},
		{ // 4
			{ 8, 8, 8, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{ // 5
			{ 8, 8, 8, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 }
		},
		{ // 6
			{ 8, 8, 8, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 8, 8, 8, 8, 0, 0, 0, 0 }
		},
		{ // 7
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 0, 0, 0, 8, 0, 0, 0, 0 },
			{ 8, 8, 8, 8, 0, 0, 0, 0 }
		},
		{ // 8
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 8, 8, 8, 8, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		},
		{ // 9
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 8, 8, 8, 8, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 8, 0, 0, 8, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 }
		}
};

static int dummy1[12];

static char photo[16][64];

static int dummy2[34];

static int seed;

static int dummy3[56];

void output(char photo[16][64]) {
	for (register int i = 0; i < 16; i++) {
		for (register int j = 0; j < 64; j++) {
			printf("%d ", photo[i][j]);
			if (j == 15 || j == 31 || j == 47) {
				printf("|");
			}
		}
		printf("\n");
	}
}

static void BitBlt(int bx, int by, int n)
{
	for (int y = 0; y < 8; y++)
		for (int x = 0; x < 8; x++)
			photo[by + y][bx + x] = alpha[n][y][x];
}

static int random_gen(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

extern int Recognize(char photo[16][64]);


static void shot(int n) {
	for (int y = 0; y < 16; y++)
		for (int x = 0; x < 64; x++)
			photo[y][x] = 0;


	int cursor = 0;
	int pos = 1000;

	for (int c = 0; c < 4; c++)
	{
		cursor += random_gen() % 9;

		int x = cursor;
		int y = random_gen() % 9;

		BitBlt(x, y, (n / pos) % 10);

		cursor += 8;
		pos /= 10;
	}

	//printf("1\n");
	//output(photo);

	//photoｌ里的点有1/10的概率变成翻转
	for (int y = 0; y < 16; y++) {
		for (int x = 0; x < 64; x++) {
			if (random_gen() % 10 == 0) {
				photo[y][x] = (photo[y][x] == 0) ? 8 : 0;
			}
		}
	}
}

int main(void)
{
	seed = 3;  // the seed will be changed

	printf("---------------\n");

	freopen("out.txt", "w", stdout);


	int RESULT = 0;
	//int TC = 1;
	int TC = 2000;
	for (int c = 0; c < TC; c++)
	{
		int number = random_gen() % 10000;
		shot(number);

		char tmp[16][64];



		if (Recognize(photo) == number)
			RESULT++;



		//printf("2\n");
		//output(photo);
	}

	
	

	printf("RESULT : %d\n", RESULT);
	return 0;
}


//= == == == == == == == == == == == == == == == == == == == = Photo User Code == == == == == == == == == == == == == == == == == == == == =

int comp(char photo[16][64], int i, int j) {

	register int c = 0;
	register int a, b = 0;

	int score[10] = { 0 };
	int maxScore = 0;
	int maxIdx = -1;

	for (c = 0; c < 10; c++) {

		for (a = 0; a < 8; a++) {
			for (b = 0; b < 8; b++) {
				if (alpha[c][a][b] == 0) {
					if (photo[i + a][j + b] == 0) {
						score[c]++;
					}
					else {
						score[c] -= 80;
					}
				}
				else {
					if (photo[i + a][j + b] == 8){
						score[c] += 100;
					}
					else {
						score[c] -= 100;
					}
				}
			}
		}

		if (score[c] < 20) {
			continue;
		}
		if (score[c] > maxScore) {
			maxScore = score[c];
			maxIdx = c;
		}
	}

	///////////////////////////////////
	
	if (i == 2 && j == 14) {
		printf("photo: 2, 14\n");
		printf("[%d, %d] idx = %d maxScore=%d\n", i, j, maxIdx, maxScore);
		printf("Score: ");
		for (a = 0; a < 10; a++) {
			printf("%d ", score[a]);
		}
		printf("\n");

		for (a = 0; a < 8; a++) {
			for (b = 0; b < 8; b++) {
				printf("%d ", photo[i + a][j + b]);
			}
			printf("\n");
		}
	}

	if (maxIdx >= 0) {

		printf("[%d, %d] idx = %d maxScore=%d\n", i, j, maxIdx, maxScore);
		printf("Score: ");
		for (a = 0; a < 10; a++) {
			printf("%d ", score[a]);
		}
		printf("\n");
		for (a = 0; a < 8; a++) {
			for (b = 0; b < 8; b++) {
				printf("%d ", photo[i + a][j + b]);
			}
			printf("\n");
		}
	}
	///////////////////////////////////

	return maxIdx;
}

int Compare(char photo[16][64], int x, int y, int n){
	int covercnt = 0;
	for (int ix = 0; ix<8; ix++)
		for (int iy = 0; iy<8; iy++){
		if (alpha[n][iy][ix] == 8)
			if (photo[y + iy][x + ix] == alpha[n][iy][ix])
				covercnt++;
			else
				covercnt--;
		}

	return covercnt;
}

int Recognize(char photo[16][64])
{

	register int c = 0;
	register int i = 0;
	register int j = 0;
	//for (c = 0; c < 4; c++) {
	//遍历4个区域
	//for (j = 0; j <= 56; j++) {
	//	for (i = 0; i <= 8; i++) {

	//		int r = comp(photo, i, j);
	//		if (r < 0) {
	//			continue;
	//		}

	//		//printf("idx=%d\n", r);

	//	}
	//}


	int cursor = 0;
	int result = 0;
	for (int i = 0; i < 4; i++)
	{
		int x = cursor, y = 0;
		int bx = cursor, b_cover = 0, bn = 0;
		for (int iy = 0; iy <= 8; iy++) {
			for (int ix = 0; ix <= 8; ix++) {
				for (int in = 0; in < 10; in++)
				{
					int covercnt = Compare(photo, x + ix, iy, in);
					if (covercnt > b_cover){
						bx = x + ix;
						b_cover = covercnt;
						bn = in;
					}
				}
			}
		}
		cursor = bx + 8;
		result = result * 10 + bn;
	}
	return result;
}


//////////////////////////////////////////////////////////
//收垃圾 Trash 
#include <iostream>
#include <ctime>

using namespace std;

#define MAXTRASH 10000
#define SIZE 1000
#define CANSIZE 3500

int TC = 10;
void output(int trash_map[1000][1000]);
void test(int trash_map[1000][1000]);

void bfs(int trash_map[1000][1000]);

static int seed = 3;  // the seed will be changed
static int result = 0;
static int dummy0[222];
static int trash_map[1000][1000];
static int dummy1[333];
static int origin_trash_map[1000][1000];
static int dummy2[444];
static int trash_can[3];

static int random_gen(void)
{
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

static void _build_map_step1()
{
	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 1000; x++)
			trash_map[y][x] = 0;
}

static void _build_map_step2()
{
	for (int c = 0; c < MAXTRASH;)
	{
		int x = random_gen() % 1000;
		int y = random_gen() % 1000;

		if (trash_map[y][x] == 0)
		{
			trash_map[y][x] = -1; // trash
			c++;
		}
	}
}

static void _build_map_step3()
{
	for (int c = 1; c <= 3;)
	{
		int x = random_gen() % 1000;
		int y = random_gen() % 1000;

		if (trash_map[y][x] == 0)
		{
			trash_map[y][x] = c; // trash_can
			c++;
		}
	}
}

static void _build_map_step4()
{
	trash_can[0] = trash_can[1] = trash_can[2] = 0;

	for (int y = 0; y < 1000; y++)
		for (int x = 0; x < 1000; x++)
			origin_trash_map[y][x] = trash_map[y][x];
}

static void build_map(void)
{
	_build_map_step1();
	_build_map_step2();
	_build_map_step3();
	_build_map_step4();
}

int move_trash(int y, int x, int d)
{
	if (result == 1000000000) 
		return -4;

	result++;

	int ox = x;
	int oy = y;

	switch (d)
	{
	case 0: y--; break;
	case 1: y++; break;
	case 2: x--; break;
	case 3: x++; break;
	}

	if ((x < 0) || (x >= 1000) || (ox < 0) || (ox >= 1000))
		return -3;
	if ((y < 0) || (y >= 1000) || (oy < 0) || (oy >= 1000))
		return -3;

	if (origin_trash_map[y][x] == -1 || origin_trash_map[oy][ox] != -1) {
		return -1;
	}

	if (origin_trash_map[y][x] == 0)
	{
		origin_trash_map[oy][ox] = 0;
		origin_trash_map[y][x] = -1;
	}
	else
	{
		int i = origin_trash_map[y][x] - 1;

		if (trash_can[i] == CANSIZE) {
			return -2;
		}

		origin_trash_map[oy][ox] = 0;
		trash_can[i]++;
	}
	return 0;
}


int main(void)
{
	int err = 0;
	cout << "---------------" << endl;

	freopen("out.txt", "w", stdout);

	for (register int T = 0; T < TC; T++)
	{
		//if (!(T == 3)) {
		//	continue;
		//}
		err = 0;

		build_map();
		time_t START = clock();
		
		test(trash_map);
		//bfs(trash_map);

		result += ((clock() - START) / (CLOCKS_PER_SEC / 1000));

		for (int y = 0; y < 1000; y++) {
			for (int x = 0; x < 1000; x++) {
				if (origin_trash_map[y][x] == -1) {
					result += 10000;
					err++;
				}
			}
		}


		//cout << "Test Case: "<<T<<" Err: " << err << endl;
		//output(origin_trash_map);
	}

	cout << "RESULT : " << result << endl;
	
	return 0;
}
//== == == == == == == == == == == == == == == == == == == == = Trash User Code == == == == == == == == == == == == == == == == == == == == =

extern int move_trash(int y, int x, int d);

#define U 0
#define D 1
#define L 2
#define R 3


int TrashX[4];
int TrashY[4];
int Cnt[4];
int Dist[4];
int SortTrash[4];


int X[MAXTRASH];
int Y[MAXTRASH];
int T[MAXTRASH]; //target
int Step[MAXTRASH];
int Sort[MAXTRASH];
int N = 0;

void output(int trash_map[1000][1000]) {
	for (register int i = 0; i < SIZE; i++) {
		for (register int j = 0; j < SIZE; j++) {
			printf("%d\t", trash_map[i][j]);
		}
		printf("\n");
	}
}

int Idx[SIZE][SIZE];
int Visit[SIZE][SIZE];
typedef struct Point{
	int x;
	int y;
}Point;

typedef struct Queue{
	Point p[SIZE*SIZE+100];
	int rear;
	int front;
}Queue;

Queue Q;

void initQueue(Queue & Q) {
	Q.rear = Q.front = 0;
}

void enQueue(Queue & Q, int x, int y) {
	if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
		if (!Visit[x][y]) {
			Q.p[Q.rear].x = x;
			Q.p[Q.rear].y = y;
			Q.rear++;
			Visit[x][y] = 1;
		}
	}
}
void deQueue(Queue& Q, int & x, int & y) {

	x = Q.p[Q.front].x;
	y = Q.p[Q.front].y;
	Q.front++;

}


void init() {
	for (register int i = 0; i < SIZE; i++) {
		for (register int j = 0; j < SIZE; j++){
			Idx[i][j] = 0;
		}
	}
	for (register int i = 0; i < MAXTRASH; i++) {
		X[i] = 0;
		Y[i] = 0;
		T[i] = 0;
		Step[i] = 0;
		Sort[i] = 0;
	}
	N = 0;
	TrashX[0] = TrashX[1] = TrashX[2] = TrashX[3] = 0;
	TrashY[0] = TrashY[1] = TrashY[2] = TrashY[3] = 0;
	Cnt[0] = Cnt[1] = Cnt[2] = Cnt[3] = 0;
	Dist[0] = Dist[1] = Dist[2] = Dist[3] = 0;
	SortTrash[0] = SortTrash[1] = SortTrash[2] = SortTrash[3] = 0;
}

void addTrash(int & n, int i, int j) {
	X[n] = i;
	Y[n] = j;
	Idx[i][j] = n;
	n++;
}

void makeSort(int ary[], int n) {
	register int i, j, stp;
	for (i = 0; i < n; i++) {
		Sort[i] = i;
	}

	for (i = 0; i < n; i++) {

		stp = Step[Sort[i]];

		for (j = i - 1; j >= 0; j--) {
			if (stp < Step[Sort[j]]) {
				Sort[j+1] = Sort[j];
			}
			else {
				break;
			}
		}
		Sort[j + 1] = i;
	}
}

int removeTrash(int x, int y, int step, int target) {
	int x0 = TrashX[target];
	int y0 = TrashY[target];
	int n, ret;
	int i, j;
	if (x < x0) {
		if (y < y0) {
			n = abs(y0 - y);
			for (j = 0; j < n; j++) {
				ret = move_trash(x, y, R);
				//if (ret != 0) {
					//printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
					//return ret;
				//}
				y++;
			}
			n = abs(x0 - x);
			for (i = 0; i < n; i++) {
				ret = move_trash(x, y, D);
				//if (ret != 0) {
					//printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
					//return ret;
				//}
				x++;
			}
		}
		else {
			n = abs(y - y0);
			for (j = 0; j < n; j++) {
				ret = move_trash(x, y, L);
				//if (ret != 0) {
					//printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
					//return ret;
				//}
				y--;
			}
			n = abs(x0 - x);
			for (i = 0; i < n; i++) {
				ret = move_trash(x, y, D);
				//if (ret != 0) {
					//printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
					//return ret;
				//}
				x++;
			}
		}

	}
	else {
		if (y < y0) {
			n = abs(y0 - y);
			for (j = 0; j < n; j++) {
				ret = move_trash(x, y, R);
				//if (ret != 0) {
					//printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
					//return ret;
				//}
				y++;
			}
			n = abs(x0 - x);
			for (i = 0; i < n; i++) {
				move_trash(x, y, U);
				//if (ret != 0) {
				//	printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
				//	return ret;
				//}
				x--;
			}
		}
		else {
			n = abs(y - y0);
			for (j = 0; j < n; j++) {
				ret = move_trash(x, y, L);
				//if (ret != 0) {
				//	printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
				//	return ret;
				//}
				y--;
			}
			n = abs(x0 - x);
			for (i = 0; i < n; i++) {
				ret = move_trash(x, y, U);
				//if (ret != 0) {
				//	printf("ret=%d move (%d, %d) to %d(%d, %d)\n", ret, x, y, target, x0, y0);
				//	return ret;
				//}
				x--;
			}
		}
	}
	return 0;
}

void outputSorted() {
	int i;
	
	printf("Trash: 1: [%d, %d], 2: [%d, %d], 3: [%d, %d]\n", TrashX[1], TrashY[1], TrashX[2], TrashY[2], TrashX[3], TrashY[3]);
	
	for (i = 0; i < N; i++) {
		printf("[%d, %d], step: %d, target: %d\n", X[Sort[i]], Y[Sort[i]], Step[Sort[i]], T[Sort[i]]);
	}
}


void test(int trash_map[1000][1000]){

	init();
	

	register int i, j, k;
	//k = 0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (trash_map[i][j] == -1) {
				addTrash(N, i, j);
				
				/*Sort[k] = k;
				k++;*/
			}
			else if (trash_map[i][j] > 0) {
				TrashX[trash_map[i][j]] = i;
				TrashY[trash_map[i][j]] = j;
			}
		}
	}

	//求Step和Target
	
	for (i = 0; i < N; i++) {
		SortTrash[0] = 0;  SortTrash[1] = 1; SortTrash[2] = 2;  SortTrash[3] = 3;
		Dist[1] = abs(X[i] - TrashX[1]) + abs(Y[i] - TrashY[1]);
		Dist[2] = abs(X[i] - TrashX[2]) + abs(Y[i] - TrashY[2]);
		Dist[3] = abs(X[i] - TrashX[3]) + abs(Y[i] - TrashY[3]);

		for (j = 1; j <= 3; j++) {
			int tmpDist = Dist[SortTrash[j]];
			for (k = j - 1; k >= 1; k--) {
				if (tmpDist < Dist[SortTrash[k]]) {
					SortTrash[k + 1] = SortTrash[k];
				}
				else {
					break;
				}
			}
			SortTrash[k + 1] = j;
		}

		for (k = 1; k <= 3; k++) {
			j = SortTrash[k];
			if (Cnt[j] == CANSIZE - 1) {
				continue;
			}
			T[i] = j;
			Step[i] = Dist[j ];
			Cnt[j]++;
			break;
		}
	}

	//排序按step从小到大排序
	makeSort(Sort, N);

	//printf("Cnt : %d, %d, %d\n", Cnt[1], Cnt[2], Cnt[3]);

	//outputSorted();

	int x, y;
	for (i = 0; i < N; i++) {
		j = Sort[i];
		x = X[j];
		y = Y[j];
		
		removeTrash(x, y, Step[j], T[j]);
	}
	
}

void bfs(int trash_map[1000][1000]) {

	init();
	register int i, j, k;
	//k = 0;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (trash_map[i][j] == -1) {
				addTrash(N, i, j);

				/*Sort[k] = k;
				k++;*/
			}
			else if (trash_map[i][j] > 0) {
				TrashX[trash_map[i][j]] = i;
				TrashY[trash_map[i][j]] = j;
			}
		}
	}

	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++){
			Visit[i][j] = 0;
		}
	}
	//Visit[TrashX[1]][TrashY[1]] = 1;
	//Visit[TrashX[2]][TrashY[2]] = 1;
	//Visit[TrashX[3]][TrashY[3]] = 1;
	initQueue(Q);
	enQueue(Q, TrashX[1], TrashY[1]);
	enQueue(Q, TrashX[2], TrashY[2]);
	enQueue(Q, TrashX[3], TrashY[3]);
	int x, y, ux, uy, dx, dy, lx, ly, rx, ry;
	while (Q.rear != Q.front) {
		deQueue(Q, x, y);
		if (trash_map[x][y] == -1) {

			SortTrash[0] = 0;  SortTrash[1] = 1; SortTrash[2] = 2;  SortTrash[3] = 3;
			Dist[1] = abs(x - TrashX[1]) + abs(y - TrashY[1]);
			Dist[2] = abs(x - TrashX[2]) + abs(y - TrashY[2]);
			Dist[3] = abs(x - TrashX[3]) + abs(y - TrashY[3]);

			for (j = 1; j <= 3; j++) {
				int tmpDist = Dist[SortTrash[j]];
				for (k = j - 1; k >= 1; k--) {
					if (tmpDist < Dist[SortTrash[k]]) {
						SortTrash[k + 1] = SortTrash[k];
					}
					else {
						break;
					}
				}
				SortTrash[k + 1] = j;
			}

			for (k = 1; k <= 3; k++) {
				j = SortTrash[k];
				if (Cnt[j] == CANSIZE - 1) {
					continue;
				}
				T[Idx[x][y]] = j;
				Step[Idx[x][y]] = Dist[j];
				Cnt[j]++;
				break;
			}

		}
		//up
		ux = x - 1;
		uy = y;
		enQueue(Q, ux, uy);
		//down
		dx = x + 1;
		dy = y;
		enQueue(Q, dx, dy);
		//left
		lx = x;
		ly = y - 1;
		enQueue(Q, lx, ly);
		//right
		rx = x;
		ry = y + 1;
		enQueue(Q, rx, ry);
	}

	//排序按step从小到大排序
	makeSort(Sort, N);

	//printf("Cnt : %d, %d, %d\n", Cnt[1], Cnt[2], Cnt[3]);

	//outputSorted();

	x = 0; y = 0;
	for (i = 0; i < N; i++) {
		j = Sort[i];
		x = X[j];
		y = Y[j];

		removeTrash(x, y, Step[j], T[j]);
	}
}

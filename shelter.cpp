#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXHOUSE 10000
//#define MAXHOUSE 12

const int FLOOR = 10000;
//const int FLOOR = 100;

extern void assign(int house[FLOOR][MAXHOUSE]);
extern void assign1(int house[FLOOR][MAXHOUSE]);

int main(void) {
	
	//freopen("out.txt", "w", stdout);


	static int house[FLOOR][MAXHOUSE];
	static int org[FLOOR][MAXHOUSE];
	static int shelter[FLOOR][3];

	srand(3);

	for (register int f = 0; f < FLOOR; f++) {
		for (register int c = 0; c < MAXHOUSE; c++) {
			org[f][c] = house[f][c] = 1 + (rand() % 9);
			//org[f][c] = house[f][c] = 5;
		}

		for (register int c = 0; c < 3;) {
			int r = rand() % MAXHOUSE;
			if (house[f][r] == 0) {
				continue;
			}

			org[f][r] = house[f][r] = 0;
			shelter[f][c++] = r;
		}
	}

	int PERFORMANCE = 100000;

	double TOTAL = 0.0;

	time_t start = clock();

	assign(house);

	PERFORMANCE -= (clock() - start) / (CLOCKS_PER_SEC / 1000);

	printf("TIME=%d\n", clock() - start);

	for (register int f = 0; f < FLOOR; f++) {
		int sum[3] = { 0, 0, 0 };

		for (register int i, c = 0; c < MAXHOUSE; c++) {
			if (org[f][c] == 0) {
				continue;
			}

			for (i = 0; i < 3; i++) {
				if (house[f][c] == shelter[f][i]) {
					sum[i] += org[f][c];
					if (sum[i] <= 2 * MAXHOUSE) {
						TOTAL += abs(shelter[f][i] - c);
					}
					else {
						TOTAL += 10000;
						printf("floor=%d, sum[%d] = %d, shelter[f][%d] = %d\n", f, i, sum[i], i, shelter[f][i]);
					}
					break;
				}

				if (i == 3) {
					TOTAL += 10000;
					printf("outofbound\n");
				}
			}
		}
	}

	//printf("TOTAL = %.10lf, PERFORMANCE = %d\n", TOTAL / FLOOR, PERFORMANCE);
	printf("TOTAL = %.10lf, PERFORMANCE = %d\n", TOTAL / 10000 / FLOOR, PERFORMANCE);
	return 0;
}




//////////////////////////////////////////////////////////////////////////////////////////

// [l, r)的总和
int sum(int lsum[MAXHOUSE], int l, int r) {
	int s = lsum[r] - lsum[l];
	return s;
}

int total(int labs0[MAXHOUSE], int labs1[MAXHOUSE], int labs2[MAXHOUSE], int l, int r, int n) {
	int a0 = labs0[l];
	int a1 = labs1[r] - labs1[l];
	int a2 = labs2[n] - labs2[r];
	int sum = a0 + a1 + a2;
	return sum;
}

void output(int house[MAXHOUSE], int abs0[MAXHOUSE], int abs1[MAXHOUSE], int abs2[MAXHOUSE], int lsum[MAXHOUSE + 1], int labs0[MAXHOUSE + 1], int labs1[MAXHOUSE + 1], int labs2[MAXHOUSE + 1]) {
	printf("house:\n");
	for (register int i = 0; i < MAXHOUSE; i++) {
		printf("%d\t", house[i]);
	}
	printf("\n");

	printf("abs0:\n");
	for (register int i = 0; i < MAXHOUSE; i++) {
		printf("%d\t", abs0[i]);
	}
	printf("\n");

	printf("abs1:\n");
	for (register int i = 0; i < MAXHOUSE; i++) {
		printf("%d\t", abs1[i]);
	}
	printf("\n");

	printf("abs2:\n");
	for (register int i = 0; i < MAXHOUSE; i++) {
		printf("%d\t", abs2[i]);
	}
	printf("\n");

	printf("lsum:\n");
	for (register int i = 0; i <= MAXHOUSE; i++) {
		printf("%d\t", lsum[i]);
	}
	printf("\n");

	printf("labs0:\n");
	for (register int i = 0; i <= MAXHOUSE; i++) {
		printf("%d\t", labs0[i]);
	}
	printf("\n");

	printf("labs1:\n");
	for (register int i = 0; i <= MAXHOUSE; i++) {
		printf("%d\t", labs1[i]);
	}
	printf("\n");

	printf("labs2:\n");
	for (register int i = 0; i <= MAXHOUSE; i++) {
		printf("%d\t", labs2[i]);
	}
	printf("\n");
}

void assign(int house[FLOOR][MAXHOUSE]) {
	int limit = MAXHOUSE << 1;

	int lsum[MAXHOUSE+1] = { 0 };
	
	int abs0[MAXHOUSE] = { 0 };
	int abs1[MAXHOUSE] = { 0 };
	int abs2[MAXHOUSE] = { 0 };

	int labs0[MAXHOUSE+1] = { 0 };
	int labs1[MAXHOUSE+1] = { 0 };
	int labs2[MAXHOUSE+1] = { 0 };

	int left = 0, right = 0;

	for (register int f = 0; f < FLOOR; f++) {

		//if (!(f == 6)) {
		//	continue;
		//}

		//printf("floor=%d\n", f);
		
		
		int shelter[3];
		int i = 0;
		
		for (register int c = 0; c < MAXHOUSE; c++) {
			if (house[f][c] == 0) {
				shelter[i++] = c;
			}
		}

		//printf("shelter: %d, %d, %d\n", shelter[0], shelter[1], shelter[2]);

		for (register int c = 0; c < MAXHOUSE; c++) {
			abs0[c] = abs(shelter[0] - c);
			abs1[c] = abs(shelter[1] - c);
			abs2[c] = abs(shelter[2] - c);
		}


		lsum[0] = 0;
		for (register int c = 1; c <= MAXHOUSE; c++) {
			lsum[c] = lsum[c - 1] + house[f][c - 1];
			
			labs0[c] = labs0[c - 1] + abs0[c - 1];
			labs1[c] = labs1[c - 1] + abs1[c - 1];
			labs2[c] = labs2[c - 1] + abs2[c - 1];
		}


		//output(house[f], abs0, abs1, abs2, lsum, labs0, labs1, labs2);

////////////////////////////////////////////////
		
		register int l = 0;
		register int r = 1;
		int sum1, sum2, sum3, t, min = 0x7fffffff;
		int flag = 0;
		for (l = 0, r = 1; l < r; ) {
			sum1 = sum(lsum, 0, l);
			sum2 = sum(lsum, l, r);
			sum3 = sum(lsum, r, MAXHOUSE);

			if (sum3 > limit) {
				r++;
				continue;
			}
			if (sum2 > limit) {
				l++;
				r--;
				continue;
			}
			if (sum1 > limit) {
				break;
			}

			if (sum1 <= limit && sum2 <= limit && sum3 <= limit){
				t = total(labs0, labs1, labs2, l, r, MAXHOUSE);
				if (t < min) {
					left = l;
					right = r;
					min = t;

					//printf("min=%d, l=%d, r=%d, sum1=%d, sum2=%d, sum3=%d\n", min, left, right, sum1, sum2, sum3);


					r++;

				}
				else if (t == min) {
					r++;
				}
				else {
					r--;
					l++;
				}
			}

		}

		//printf("min=%d\n", min);
		for (register int c = 0; c < left; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[0];
			}
		}

		for (register int c = left; c < right; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[1];
			}
		}
		for (register int c = right; c < MAXHOUSE; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[2];
			}
		}
	}
}





void assign1(int house[FLOOR][MAXHOUSE]) {
	int limit = MAXHOUSE << 1;

	int lsum[MAXHOUSE + 1] = { 0 };

	int abs0[MAXHOUSE] = { 0 };
	int abs1[MAXHOUSE] = { 0 };
	int abs2[MAXHOUSE] = { 0 };

	int labs0[MAXHOUSE + 1] = { 0 };
	int labs1[MAXHOUSE + 1] = { 0 };
	int labs2[MAXHOUSE + 1] = { 0 };

	int left = 0, right = 0;

	for (register int f = 0; f < FLOOR; f++) {
		
		//if (!(f == 474)) {
		//	continue;
		//}

		printf("floor=%d\n", f);

		int shelter[3] = { 0 };
		int i = 0;
		for (register int c = 0; c < MAXHOUSE; c++) {
			if (house[f][c] == 0) {
				shelter[i++] = c;
			}
		}

		//printf("shelter: %d, %d, %d\n", shelter[0], shelter[1], shelter[2]);

		for (register int c = 0; c < MAXHOUSE; c++) {
			abs0[c] = abs(shelter[0] - c);
			abs1[c] = abs(shelter[1] - c);
			abs2[c] = abs(shelter[2] - c);
		}


		lsum[0] = 0;
		for (register int c = 1; c <= MAXHOUSE; c++) {
			lsum[c] = lsum[c - 1] + house[f][c - 1];

			labs0[c] = labs0[c - 1] + abs0[c - 1];
			labs1[c] = labs1[c - 1] + abs1[c - 1];
			labs2[c] = labs2[c - 1] + abs2[c - 1];
		}

		//output(house[f], abs0, abs1, abs2, lsum, labs0, labs1, labs2);

		//for (register int c = 0; c < MAXHOUSE; c++) {
		//	if (house[f][c] != 0) {
		//		house[f][c] = shelter[c % 3];
		//	}
		//}
		register int l = 0;
		register int r = 1;
		int sum1, sum2, sum3, t, min = 0x7fffffff;
		for (l = 0; l < MAXHOUSE; l++) {
			for (r = l + 1; r < MAXHOUSE; r++) {
				sum1 = sum(lsum, 0, l);
				sum2 = sum(lsum, l, r);
				sum3 = sum(lsum, r, MAXHOUSE);

				if (sum1 <= limit && sum2 <= limit && sum3 <= limit) {
					t = total(labs0, labs1, labs2, l, r, MAXHOUSE);
					if (t < min) {
						left = l;
						right = r;
						min = t;

						//printf("min=%d, l=%d, r=%d\n", min, left, right);
						//printf("min=%d, l=%d, r=%d, sum1=%d, sum2=%d, sum3=%d\n", min, left, right, sum1, sum2, sum3);
					}
				}
			}
		}

		//printf("min=%d, l=%d, r=%d\n", min, left, right);
		printf("min=%d\n", min);

		for (register int c = 0; c < left; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[0];
			}
		}

		for (register int c = left; c < right; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[1];
			}
		}
		for (register int c = right; c < MAXHOUSE; c++) {
			if (house[f][c] != 0) {
				house[f][c] = shelter[2];
			}
		}
	}
}

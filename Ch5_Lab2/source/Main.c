#include<stdio.h>
#include<stdlib.h>
#define STUDENT 3
#define EXAM 4

void minimum(int grade[][EXAM], int pupils, int tests);
void maximum(int grade[][EXAM], int pupils, int tests);
void average(int grade[][EXAM], int pupils, int tests);
void printarray(int grade[][EXAM], int pupils, int tests);
void printMenu(void);

int main() {

	void(*processGrade[4])(int[][EXAM], int, int) = { printarray,minimum,maximum,average };
	int choice = 0;
	int studentGrade[STUDENT][EXAM] = { {77,68,86,73},{96,87,89,73},{70,90,86,81} };

	while (choice != 4){
		do {
			printMenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);
		if (choice != 4) {
			(*processGrade[choice])(studentGrade, STUDENT, EXAM);
		}
		else {
			printf("Program Ended.\n");
		}
	}

	system("pause");
	return 0;
}
void minimum(int grade[][EXAM], int pupils, int tests) {
	int lowGrade = 100;
	for (int i = 0; i < pupils; i++) {
		for (int j = 0; j < tests; j++) {
			if (grade[i][j] <= lowGrade)
				lowGrade = grade[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d\n", lowGrade);
}
void maximum(int grade[][EXAM], int pupils, int tests) {
	int max = 0;
	for (int i = 0; i < pupils; i++) {
		for (int j = 0; j < tests; j++) {
			if (grade[i][j] >= max)
				max = grade[i][j];
		}
	}
	printf("\n\tThe highest grade is %d\n", max);
}
void average(int grade[][EXAM], int pupils, int tests) {
	float average = 0;
	printf("\n");
	for (int i = 0; i < pupils; i++) {
		average = 0;
		for (int j = 0; j < tests; j++){
			average += grade[i][j];
		}
		printf("\tThe average for student %d is %.1f\n",i+1,average/tests);
	}
}
void printarray(int grade[][EXAM], int pupils, int tests) {
	int i;
	int j;
	printf("\n\t                 [0]  [1]  [2]  [3]");
	for (i = 0; i < pupils; i++) {
		printf("\n\tstudentGrade[%d]   ", i);
		for (j = 0; j < tests; j++) {
			printf("%-5d", grade[i][j]);
		}
	}
	printf("\n");
}
void printMenu(void) {
	printf("\n\tEnter a choice:\n"
		   "\t  0  Print the array of grades\n"
		   "\t  1  Find the minimum grade\n"
		   "\t  2  Find the highest grade\n"
		   "\t  3  Print the average on all test for each student\n"
		   "\t  4  End program\n\t?");
}
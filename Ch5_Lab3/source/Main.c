#include<stdio.h>
#include<stdlib.h>
#define ISSUE 5
#define RATINGS 10

void recordResponse(int issue, int rating);
void highestRatings();
void lowestRatings();
void displayResults();
float averageRating(int issue);

int response[ISSUE][RATINGS];
const char *topics[ISSUE] = { "Global Warming","The Economy","War","Health Care","Education" };

int main(void) {

	int response, i;

	do {
		printf("Please rate the following topics on a scale from 1 - 10"
			   "\n 1 = least important, 10 = most important\n");
		for (i = 0; i < ISSUE; i++) {
			do {
				printf("%s ? ", topics[i]);
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			recordResponse(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate again. ");
		scanf_s("%d", &response);
	} while (response != 1);

	displayResults();
	system("pause");
	return 0;
}
void recordResponse(int issue, int rating) {
	response[issue][rating - 1]++;
}
void highestRatings(void) {
	int rating = 0, topic = 0, i, j;
	for (i = 0; i < ISSUE; i++) {
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++) {
			topicrating += response[i][j] * (j + 1);
		}
		if (topicrating >= rating) {
			rating = topicrating;
			topic = i;
		}
	}
	printf("The highest rated topic was %s with a total rating of %d\n", topics[topic],rating);
}
void lowestRatings(void) {
	int rating = 0, topic = 0, i, j;
	for (i = 0; i < ISSUE; i++) {
		int topicrating = 0;
		for (j = 0; j < RATINGS; j++) {
			topicrating += response[i][j] * (j + 1);
		}
		if (rating == 0) {
			rating = topicrating;
		}
		if (topicrating <= rating) {
			rating = topicrating;
			topic = i;
		}
	}
	printf("The lowest rated topic was %s with a total rating of %d\n", topics[topic], rating);
}
float averageRating(int issue) {
	float rating = 0, counter = 0;
	int i;
	for (i = 0; i < RATINGS; i++) {
		if (response[issue][i] != 0) {
			rating += response[issue][i] * (i + 1);
			counter += 1;
		}
	}
	return rating / counter;
}
void displayResults() {
	printf("%20s", "Topic");
	for (int i = 1; i <= RATINGS; i++) {
		printf("%4d", i);
	}
	printf("%20s","Average Rating");
	printf("\n");
	for (int i = 0; i < ISSUE; i++) {
		printf("%20s",topics[i]);
		for (int j = 0; j < RATINGS; j++) {
			printf("%4d", response[i][j]);
		}
		printf("%20.2f\n", averageRating(i));
	}
	highestRatings();
	lowestRatings();
}
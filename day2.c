//  DAY 2 BOTH PARTS, EACH PART NUMBER LISTED AFTER THE CORRESPONDING FUNCTION
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
void password1 (void) {
	int min, max, index = 0, numval = 0, cindex = 0;
	char string[32];
	char c;
	sprintf(string, "\0");
	fp = fopen("input.txt", "r");
	if(fp == NULL)
		return;
	while(index < 1001) {
		int tempnum = 0;
		fscanf(fp, "%d-%d %c: %s\n", &min, &max, &c, string);
		printf("%d-%d %c: %s\n", min, max, c, string);
		while(string[cindex] != '\0') {
			if(string[cindex] == c)
				tempnum++;
			cindex++;
		}
		cindex = 0;
		if(tempnum >= min && tempnum <= max) {
			printf("VALID\n");
			numval++;
		}
		index++;
	}
	printf("NUMBER VALID: %d\n", numval);
	return;
}

void password2 (void) {
	int min, max, index = 0, numval = 0;
	char string[32];
	char c;
	sprintf(string, "\0");
	fp = fopen("input.txt", "r");
	if(fp == NULL)
		return;
	while(index < 1001) {
		int tempnum = 0;
		fscanf(fp, "%d-%d %c: %s\n", &min, &max, &c, string);
		printf("%d-%d %c: %s\n", min, max, c, string);
		if(string[min-1] == c)
			tempnum++;
		if(string[max-1] == c)
			tempnum++;
		if(tempnum == 1)
			numval++;
		index++;
	}
	printf("NUMBER VALID: %d\n", numval);
	return;
}

int main (void) {
  //THIS WILL ONLY RUN PART 2, BUT YOU CAN SWITCH THE FUNCTIONS
  password2();
  return 0;
}

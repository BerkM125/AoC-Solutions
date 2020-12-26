//PART 2 FOR DAY 1
#include <stdlib.h>
#include <stdio.h>

FILE *fp;
void checknumbers (void) {
	int line;
	int numbers[300], index = 0, matchingnum[3];
	fp = fopen("input.txt", "r");
	if(fp == NULL)
		return;
	while(index < 300) {
		fscanf(fp, "%d\n", &line);
		printf("%d\n", line);
		if(line != 99999) { //put the number 99999 at the end of your file
			numbers[index] = line;
			index++;
		}
		else
			break;

	}
	fclose(fp);
	printf("INDEX: %d\n", index);
	for(int i = 0; i < index; i++) {
		int templine = numbers[i];		
		for(int i2 = 0; i2 < index; i2++) {
			int templine2 = numbers[i2];
			for(int i3 = 0; i3 < index; i3++) {
				if(templine + templine2 + numbers[i3] == 2020) {
					matchingnum[0] = templine;
					matchingnum[1] = templine2;
					matchingnum[2] = numbers[i3];
				}
			}
		}
	}
	printf("\n%d\n", matchingnum[0]*matchingnum[1]*matchingnum[2]);
	return;
}

int main (void) {
  checknumbers();
  return 0;
}

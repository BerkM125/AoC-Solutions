#include<stdio.h>
#include<stdlib.h>
#include<string.h>

FILE *fp;
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int getnum (const char *string) {
	char list[26];
	int i = 0, index = 0, index2 = 0;
	for(i = 0; i < 26; i++) {
		list[i] = '0';
	}
	while(string[index] != '\0') {
		for(i = 0; i < 26; i++) {
			if(string[index] == list[i]) 
				break;
		}
		if (i == 26) {
			list[index2] = string[index];
			index2++;
		}
		index++;
	}
	printf("INDEX2: %d\n", index2);
	return index2;
}

char *removenewline (const char *string) {
	char *new = (char*)malloc(sizeof(string));
	int index = 0, index2 = 0;
	while(string[index] != '\0') {
		if(string[index] != '\n') {
			new[index2] = string[index];
			index2++;
		}
		index++;
	}
	new[index2] = '\0';
	return new;
}

void getcustoms (void) {
	char lines[1000][1000];
	char tempchar = '0';
	int num = 0, index = 0, cindex = 0, newlinestate = 0, valid = 0;
	fp = fopen("numlist1.txt", "r+");
	if(fp == NULL)
		return; 
    while (index < 454) {
		sprintf(lines[index], "\0");
		while(newlinestate != 2) {
	        fscanf(fp, "%c", &tempchar);
			if(tempchar != '\0')
				lines[index][cindex] = tempchar;
			if(tempchar == '\n')
				newlinestate += 1;
			else
				newlinestate = 0;

			if(newlinestate == 2) {
				cindex = 0;
				newlinestate = 0;
				num++;
				break;
			}
			cindex++;
		}
		valid += getnum(removenewline(lines[index]));
		printf("%s\n", removenewline(lines[index]));
		
		index++;
    }
	printf("VALID: %d\n", valid);
}

int main (void) {
  getcustoms();
  return 0;
}

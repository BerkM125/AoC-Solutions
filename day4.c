//PART 2, DAY 4 (YOU CAN EASILY DERIVE PART 1 FROM THIS)
#include <stdio.h>
#include <stdlib.h>

FILE *fp;
int isnum (char num) {
	if(num == '0')
		return 0;
	else if(num == '1')
		return 0;
	else if(num == '2')
		return 0;
	else if(num == '3')
		return 0;
	else if(num == '4')
		return 0;
	else if(num == '5')
		return 0;
	else if(num == '6')
		return 0;
	else if(num == '7')
		return 0;
	else if(num == '8')
		return 0;
	else if(num == '9')
		return 0;
	else return 1;
}

int getfield (char arr[], char fieldname[]) {
	int i = 0;
	int ipid = 0;
	char field[64];
	char fieldvalue[64], fn[64];
	char *p;
	strcpy(fn, fieldname);
	sprintf(fieldvalue, "\0");
	sprintf(field, "\0");
	while(arr[i] != '\0') {
		if(arr[i] == ':') {
			int cindex = i+1;
			int cindex2 = 0;
			field[0] = arr[i-3];
			field[1] = arr[i-2];
			field[2] = arr[i-1];
			if(strcmp(field, fieldname) == 0) {
				while(arr[cindex] != ' ' && (arr[cindex] != '\n')) {
					fieldvalue[cindex2] = arr[cindex];
					cindex++;
					cindex2++;

				}
				fieldvalue[cindex2] = '\0';
			}
		}
		i++;
	}
	if(strcmp(fn, "byr") == 0) {
		long year = strtol(fieldvalue, &p, 10);
		if(year >= 1920 && year <= 2002) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "eyr") == 0) {
		long year = strtol(fieldvalue, &p, 10);
		if(year >= 2020 && year <= 2030) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "iyr") == 0) {
		long year = strtol(fieldvalue, &p, 10);
		if(year >= 2010 && year <= 2020) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "hgt") == 0) {
		long height = strtol(fieldvalue, &p, 10);
		if((strcmp(p, "cm") == 0 && height >= 150 && height <= 193) || (strcmp(p, "in") == 0 && height >= 59 && height <= 76)) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "hcl") == 0) {
		long hex = (long)strtol(fieldvalue, &p, 16);
		if(hex <= 16777215 && strstr(p, "#")) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "ecl") == 0) {
		if(strcmp(fieldvalue, "amb") == 0 || strcmp(fieldvalue, "blu") == 0 || strcmp(fieldvalue, "brn") == 0 || strcmp(fieldvalue, "gry") == 0 || strcmp(fieldvalue, "grn") == 0 || strcmp(fieldvalue, "hzl") == 0 || strcmp(fieldvalue, "oth") == 0) {
			return 0;
		}
		else
			return 1;
	}
	else if(strcmp(fn, "pid") == 0) {
		for(ipid = 0; ipid < 9; ipid++) {
			if(isnum(fieldvalue[ipid]) == 1)
				break;
		}
		if(ipid == 9) {
			return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}

void passport1 (void) {
	char lines[1000][1000];
	char strings[16][16];
	char tempchar;
	int num = 0, index = 0, cindex = 0, newlinestate = 0, valid = 0, i = 0;
	sprintf(strings[0], "byr\0");
	sprintf(strings[1], "iyr\0");
	sprintf(strings[2], "eyr\0");
	sprintf(strings[3], "hgt\0");
	sprintf(strings[4], "hcl\0");
	sprintf(strings[5], "ecl\0");
	sprintf(strings[6], "pid\0");
	sprintf(strings[7], "cid\0");

	fp = fopen("numlist1.txt", "r+");
	if(fp == NULL)
		return; 
    while (index < 282) {
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
		for(i = 0; i < 8; i++) {
			if(getfield(lines[index], strings[i]) == 1)
				break;
		}
		if(i >= 7) {
			valid++;
		}
		index++;
    }
	fclose(fp);
	printf("VALID: %d\n", valid-1);
}

int main (void) {
	passport1();
	return 0;
}

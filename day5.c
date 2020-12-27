//DAY 5 PART 1 (FOR NOW) IN C
#include <stdlib.h>
#include <stdio.h>

#define UPPER 1
#define LOWER 2
FILE *fp;

struct leaf {
	char value[16];
	struct leaf *upper;
	struct leaf *lower;
};

void initleaf (struct leaf *node, const char string[16]) {
	strcpy(node->value, string);
}

struct leaf *newnode (const char string[16]) {
	struct leaf *new = (struct leaf*)malloc(sizeof(struct leaf));
	strcpy(new->value, string);
	new->upper = NULL;
	new->lower = NULL;
	return new;
}

void appendleaf (struct leaf *node, int direction, const char string[16]) {
	if(direction == UPPER) {
		node->upper = newnode(string);
	}
	else if(direction == LOWER) {
		node->lower = newnode(string);
	}
}

int traversenodes (struct leaf *node, const char directions[16]) {
	int index = 0;
	int endresult = 0;
	int rmin, rmax;
	char *remain;
	//ROWS
	while(index <= 4) {
		if(directions[index] == 'F') {
			node = node->lower;
		}
		else if(directions[index] == 'B') {
			node = node->upper;
		}
		index++;
	}
	rmin = strtol(node->value, &remain, 10);
	rmax = strtol(remain, NULL, 10);
	rmax = abs(rmax);
	if(directions[index] == 'F') {
		if(directions[index+1] == 'F') {
			endresult = rmin;
		}
		if(directions[index+1] == 'B') {
			endresult = rmin+1;
		}
	}
	if(directions[index] == 'B') {
		if(directions[index+1] == 'F') {
			endresult = rmax-1;
		}
		if(directions[index+1] == 'B') {
			endresult = rmax;
		}
	}
	return endresult;
}

int traversecolumns (struct leaf *node, const char directions[16]) {
	int index = 6;
	int endresult;
	while(node->upper != NULL && node->lower != NULL) {
		if(directions[index] == 'L') {
			node = node->lower;
		}
		else if(directions[index] == 'R') {
			node = node->upper;
		}
		index++;
	}
	endresult = strtol(node->value, NULL, 10);
	return endresult;	
}

int traverseall (struct leaf *node, struct leaf *column, const char directions[16]) {
	int r, c;
	r = traversenodes(node, directions);
	c = traversecolumns(column, directions);
	return (r*8)+c;
}

void getseat (void) {
	struct leaf node;
	struct leaf column;
	struct leaf *traversenode;
	struct leaf *traversecolumn;
	char string[16];
	char addon[16];
	int max = 0;
	sprintf(string, "\0");
	sprintf(addon, " \0");
	traversecolumn = &column;
	traversenode = &node;

	fp = fopen("input.txt", "r+");
	if(fp == NULL)
		return;

	initleaf(&node, "0-127");
	initleaf(&column, "0-7");

	appendleaf(&node, LOWER, "0-63");
	//LOWER NODES
	appendleaf(node.lower, LOWER, "0-31");
	appendleaf(node.lower, UPPER, "32-63");

	appendleaf(node.lower->lower, LOWER, "0-15");
	appendleaf(node.lower->lower, UPPER, "16-31");
	appendleaf(node.lower->upper, LOWER, "32-47");
	appendleaf(node.lower->upper, UPPER, "48-63");

	appendleaf(node.lower->lower->lower, LOWER, "0-7");
	appendleaf(node.lower->lower->lower, UPPER, "8-15");
	appendleaf(node.lower->lower->upper, LOWER, "16-23");
	appendleaf(node.lower->lower->upper, UPPER, "24-31");
	appendleaf(node.lower->upper->lower, LOWER, "32-39");
	appendleaf(node.lower->upper->lower, UPPER, "40-47");
	appendleaf(node.lower->upper->upper, LOWER, "48-55");
	appendleaf(node.lower->upper->upper, UPPER, "56-63");

	appendleaf(node.lower->lower->lower->lower, LOWER, "0-3");
	appendleaf(node.lower->lower->lower->lower, UPPER, "4-7");
	appendleaf(node.lower->lower->lower->upper, LOWER, "8-11");
	appendleaf(node.lower->lower->lower->upper, UPPER, "12-15");
	appendleaf(node.lower->lower->upper->lower, LOWER, "16-19");
	appendleaf(node.lower->lower->upper->lower, UPPER, "20-23");
	appendleaf(node.lower->lower->upper->upper, LOWER, "24-27");
	appendleaf(node.lower->lower->upper->upper, UPPER, "28-31");
	appendleaf(node.lower->upper->lower->lower, LOWER, "32-35");
	appendleaf(node.lower->upper->lower->lower, UPPER, "36-39");
	appendleaf(node.lower->upper->lower->upper, LOWER, "40-43");
	appendleaf(node.lower->upper->lower->upper, UPPER, "44-47");
	appendleaf(node.lower->upper->upper->lower, LOWER, "48-51");
	appendleaf(node.lower->upper->upper->lower, UPPER, "52-55");
	appendleaf(node.lower->upper->upper->upper, LOWER, "56-59");
	appendleaf(node.lower->upper->upper->upper, UPPER, "60-63");

	//UPPER NODES
	appendleaf(&node, UPPER, "64-127");

	appendleaf(node.upper, LOWER, "64-95");
	appendleaf(node.upper, UPPER, "96-127");

	appendleaf(node.upper->lower, LOWER, "64-79");
	appendleaf(node.upper->lower, UPPER, "80-95");
	appendleaf(node.upper->upper, LOWER, "96-111");
	appendleaf(node.upper->upper, UPPER, "112-127");

	appendleaf(node.upper->lower->lower, LOWER, "64-71");
	appendleaf(node.upper->lower->lower, UPPER, "72-79");
	appendleaf(node.upper->lower->upper, LOWER, "80-87");
	appendleaf(node.upper->lower->upper, UPPER, "88-95");
	appendleaf(node.upper->upper->lower, LOWER, "96-103");
	appendleaf(node.upper->upper->lower, UPPER, "104-111");
	appendleaf(node.upper->upper->upper, LOWER, "112-119");
	appendleaf(node.upper->upper->upper, UPPER, "120-127");

	appendleaf(node.upper->lower->lower->lower, LOWER, "64-67");
	appendleaf(node.upper->lower->lower->lower, UPPER, "68-71");
	appendleaf(node.upper->lower->lower->upper, LOWER, "72-75");
	appendleaf(node.upper->lower->lower->upper, UPPER, "76-79");
	appendleaf(node.upper->lower->upper->lower, LOWER, "80-83");
	appendleaf(node.upper->lower->upper->lower, UPPER, "84-87");
	appendleaf(node.upper->lower->upper->upper, LOWER, "88-91");
	appendleaf(node.upper->lower->upper->upper, UPPER, "92-95");
	appendleaf(node.upper->upper->lower->lower, LOWER, "96-99");
	appendleaf(node.upper->upper->lower->lower, UPPER, "100-103");
	appendleaf(node.upper->upper->lower->upper, LOWER, "104-107");
	appendleaf(node.upper->upper->lower->upper, UPPER, "108-111");
	appendleaf(node.upper->upper->upper->lower, LOWER, "112-115");
	appendleaf(node.upper->upper->upper->lower, UPPER, "116-119");
	appendleaf(node.upper->upper->upper->upper, LOWER, "120-123");
	appendleaf(node.upper->upper->upper->upper, UPPER, "124-127");

	//COLUMN NODES
	appendleaf(&column, LOWER, "0-3");
	appendleaf(&column, UPPER, "4-7");

	appendleaf(column.lower, LOWER, "0-1");
	appendleaf(column.lower, UPPER, "2-3");
	appendleaf(column.upper, LOWER, "4-5");
	appendleaf(column.upper, UPPER, "6-7");

	appendleaf(column.lower->lower, LOWER, "0");
	appendleaf(column.lower->lower, UPPER, "1");
	appendleaf(column.lower->upper, LOWER, "2");
	appendleaf(column.lower->upper, UPPER, "3");
	appendleaf(column.upper->lower, LOWER, "4");
	appendleaf(column.upper->lower, UPPER, "5");
	appendleaf(column.upper->upper, LOWER, "6");
	appendleaf(column.upper->upper, UPPER, "7");

	while(fgets(string, sizeof(string), fp)) {
		int temp;
		string[10] = ' ';
		string[11] = '\0';
		temp = traverseall(traversenode, traversecolumn, string);
		if(temp > max)
			max = temp;
	}
	printf("MAX: %d\n", max);
}

int main (void) {
	getseat();
	return 0;
}

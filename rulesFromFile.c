#include "rulesFromFile.h"
t_rule *rules;

char getFromRules(l2_t *packet) {
    char dest;   
    switch(packet -> layer3.l3da) {
        case 1:
        case 2:
        case 3:{
            dest = 'A';
            break;}
        case 4:
        case 5:
        case 6:
            {dest = 'B';
            break;}
        case 7:
        case 8:
        case 9:{
            dest = randomchoice();
            break;}
        case 10:
        case 11:
        case 12:{
            dest = 'D';
            break;}
        default:{
            dest = 'E';
            break;}
    }
    return dest;
}

char randomchoice(){
		int n = rand()%2;
		char poss[2] = {'C','D'};
		char ret = poss[n];
		return ret;
}

void readRules(){
	int i;
	FILE *fin;
	char tmp[10];
	if(!(fin=fopen(RFILE,"r")))
		error("Cannot locate lookup file");
	for(i=0;!feof(fin);i++)
		fgets(tmp,sizeof(tmp),fin);
	fclose(fin);
	int j =i-1;
	t_rule array[j];
		if(!(fin=fopen(RFILE,"r")))
		error("Cannot locate lookup file");
	for(i=0;i<j;i++)
		fscanf(fin,"%d %c",&array[i].client,&array[i].router);
	for(i=0;i<j;i++)
	printf("%d%c\n",array[i].client,array[i].router);
	fclose(fin);
}

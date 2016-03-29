#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "router.h"


int main(int argc, char* argv[]){

FILE *fin;
	l2_t* tmp;
	hlist_t* headsOfInputQueues = NULL,
	       * headsOfOutputQueues = NULL;
	t_elem * mainQueue = NULL;
	//various things
	char tempo[75],temp;
	int def=0;
	int kk;
	if(argc<2)
		error("INSERT FILENAME after name of program");
	else if(argc>2)
		for(kk=0;kk<argc;kk++){
			if(!(strcmp(argv[kk],"-D"))) def=1;
			else if (!(strcmp(argv[kk],"-P"))) prior=1;
		}
	char* FILENAME = malloc (strlen (argv[1]) + 1);
	strcpy(FILENAME,argv[1]);
	if(!(fin=fopen(INPUTFILENAME,"r")))		/*open file*/
		error("Cannot open file");

	fgets(tempo,sizeof(tempo),fin);		/*skip first line*/
	if(def)
		setDimensions();
	headsOfInputQueues=setPriorDumpQueues(headsOfInputQueues);
	while(!feof(fin)){
		populateTmpFromFile(&tmp,fin);
		//printf("%c\n\n",tmp->l2sa);
		headsOfInputQueues=hEnqueue(tmp,headsOfInputQueues,tmp->l2sa,0);
	}
	//hPrintList(headsOfInputQueues);
	inputInMainQueue(&headsOfInputQueues,&mainQueue);
	//headsOfInputQueues=NULL;
	//printList(mainQueue);
	//hPrintList(headsOfInputQueues);
	headsOfOutputQueues=output(&mainQueue,headsOfOutputQueues);
	//check if main queue is emptyaa
	hPrintList(headsOfOutputQueues);
	return 0;
}

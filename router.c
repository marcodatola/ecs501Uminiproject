#include "router.h"

hlist_t* output(t_elem **mainQueue,hlist_t *headsOfOutputQueues){
	l2_t* packet;

	while(length(*mainQueue)){
		packet=getFirstElem(*mainQueue);
		
		*mainQueue=deleteFirstElem(*mainQueue);
		//printf("DELETED FIRST\n");
		char route = getFromRules(packet);
		headsOfOutputQueues=hEnqueue(packet,headsOfOutputQueues,route,1);
	}
	return headsOfOutputQueues;		
}

void populateTmpFromFile(l2_t** tmp,FILE *fin){

		if(!(*tmp = (l2_t*) malloc(sizeof(l2_t))))		/*allocate new memory for each line read*/
			error("Malloc failed");
		fscanf(fin,"%c, %c, %d, %d, %d, %s ",&((*tmp)->l2sa),&((*tmp)->l2da),&((*tmp)->layer3.l3sa),&((*tmp)->layer3.l3da),&((*tmp)->layer3.prior),&((*tmp)->layer3.payload));
		//printf("%c%c%d%d%d%s\n",(*tmp)->l2sa,(*tmp)->l2da,(*tmp)->layer3.l3sa,(*tmp)->layer3.l3da,(*tmp)->layer3.prior,(*tmp)->layer3.payload);
}


void inputInMainQueue(hlist_t **head,t_elem **main){

	t_elem* queue = NULL;
	hlist_t *temp=*head,
		*p = NULL;
	int len = hLength(*head);
	char tmp;
	int stop=0,
		 flag=0;
	if(!(*main = (t_elem*)malloc(sizeof(t_elem))))
		error("No available memory\n");
	(*main)->next=NULL;
	int count = length(*main);
	queue=hIsNotEmpty(temp,&p,len);
	while(count<maxmq&&!stop){
		
		
		while(queue!=NULL){
			input(&p,main);
			queue=hIsNotEmpty(*head,&p,len);
			count=length(*main);
			if(count>=maxmq) break;
		}
		
		if(count<maxmq){
			temp=hGetlastElem(*head);
			flag=1;
			if(temp->head==NULL||temp->head->data==NULL){
				stop=1;
				break;
			}
			input(&temp,main);
			count=length(*main);
		}
	if(!flag){
	p=hGetFirstElem(p);
	*head=NULL;}
	}

		//add if !stop case. this means trhat we have't dropped all packets but that mainqueue is full. what to do?
}

void input (hlist_t ** p, t_elem **main){
		char tmp;
		tmp=(*p)->head->data->l2sa;
		(*p)->head->data->l2sa=(*p)->head->data->l2da;
		(*p)->head->data->l2da=tmp;
		insTail(main,(*p)->head->data);
		(*p)->head=deleteFirstElem((*p)->head);
		
		
}

void setDimensions(){
	printf("Enter max length of input and output queues: ");
	scanf("%d",&maxioq);
	printf("Enter max routers: ");
	scanf("%d",&maxrout);
	printf("Enter max length of main queue: ");
	scanf("%d",&maxmq);
}

hlist_t* setPriorDumpQueues(hlist_t * head){
	t_elem* prior=NULL,
			  *dump=NULL;
	if(!(prior = (t_elem*)malloc(sizeof(t_elem))))
		error("No available memory\n");
	if(!(dump = (t_elem*)malloc(sizeof(t_elem))))
		error("No available memory\n");
	prior->data=NULL;
	dump->data=NULL;
	(head)=hInsHead(head, dump);
	(head)->id='Z';
	(head)->next=NULL;
	head=hInsHead(head,prior);
	(head)->id='Y';
	return head;
	
}

void writeToLogFile(l2_t* packet,int comand){
	FILE *fout;
	switch(comand){
		case 0:{
			if(!(fout=fopen(OUTPUTFILENAME,"w")))		/*open file*/
			error("Cannot open file");
			break;}
		case 1:{
			if(!(fout=fopen(OUTPUTFILENAME,"w+")))		/*open file*/
			error("Cannot open file");
			break;}
	}
	fwrite(packet,sizeof(l2_t),1,fout);
}

/*void error (char* string){
	fprintf(stderr,string,sizeof(string));
	exit(1);
}*/

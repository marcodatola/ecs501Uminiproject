#include "headsListLib.h"

int prior =0;
void hPrintList(hlist_t* head){//,int comand){
	hlist_t* p = head;
	t_elem* temp;
			for( ;p ; p=p->next){
			temp=p->head;
			if(p->head->data)
			printf("Printing Queue %c\n",p->id);
			printList(temp);
			}
}
			
int hExists (hlist_t *h, char target) {
	int found;
			for (found = 0; h && !found; h = h->next) 
				if (h->id == target) {
					found = 1;
					//printf("Found queue %c @ %p \n",target,h->head);
				}
			return found;

}

hlist_t *hInsTail (hlist_t *h, l2_t *ch,char dest,int comand) {
	hlist_t *p, *i,*j;
	if ((p = (hlist_t *)malloc(sizeof(hlist_t)))) {
		if((p->head = (t_elem*)malloc(sizeof(t_elem)))){
		if(!comand)
		p->head->next=NULL;
		p->id=dest;
		p->head->data=ch;  
		}else fprintf (stderr, "No available memory\n");
		if (h) {
			i = h;
			j=i;
			
			if (!comand) j=i->next;
			for (; j->next; i = i->next,j=j->next)	
				;
			if(comand)
				j=j->next;
			p->next=j;
			i->next = p;
		}
		else
			h = p;
	}
	else 
		fprintf (stderr, "No available memory\n");
	return h;
}

hlist_t *hInsHead(hlist_t * h, t_elem *ch){
	hlist_t *p;
	if ((p = (hlist_t *) malloc(sizeof(hlist_t)))) {
		p->head=ch;
		insTail(&(p->head),NULL);
		p->next = h;
		h = p;
	}
	else
		fprintf (stderr, "No available memory\n");
	return h;
}

t_elem *hFindQueue (hlist_t *h, char ch) {
	hlist_t *p=NULL;
	p = h;
	while (p && p->id != ch){ p = p->next;}
	return p->head;
}

void hNext(hlist_t* head, hlist_t **p){
	if(*p==NULL || (*p)->next == NULL){
		
			*p=head;
	}else
			*p=(*p)->next;
}

int hLength (hlist_t *h) {
	int l;
	for (l = 0; h; h = h->next, l++)
		;
	return l;
}

t_elem* hIsNotEmpty(hlist_t* head, hlist_t **p, int size){
	hlist_t *temp;
	if (size == 0) return NULL;
	temp=hGetFirstElem(head);
	if(temp->head!=NULL){
		if(temp->head->data!=NULL){;
			return temp->head;
		}else{
			hNext(head,p);
			if((*p)->id!='Z'&&(*p)->id!='Y'&&(*p)->head!=NULL){
						return (*p)->head;
			}else{
				size --;
				hIsNotEmpty(head,p,size);
			}
		}
	}
}

hlist_t *hFindPointer (hlist_t *h, char ch){
	hlist_t *p=NULL;
	p = h;
	while (p && p->id != ch){ p = p->next;}
	return p;
}

hlist_t* hGetlastElem (hlist_t * h){
	hlist_t *p;
	for(p=h; p->next; p=p->next)
		;
	return p;
}

hlist_t *hGetFirstElem(hlist_t *h){
	return h;
}


hlist_t* hEnqueue(l2_t* packet, hlist_t* head,char dest,int comand){
	t_elem* queue;
	hlist_t* tmp;
	int flag = 0;
	if(prior&&packet->layer3.prior>1){
		tmp=hGetFirstElem(head);
		if(tmp&&tmp->head&&tmp->head->data)
			queue = tmp->head;
		else flag =1;
	}else flag =1;
	if (flag){
		if(hExists(head,dest))
		queue = hFindQueue(head,dest);
		else goto HERE;
	}
	int len =length(queue);
	if(len<(maxioq)){
		insTail(&queue,packet);}
	else{
		tmp=hGetlastElem(head); //last element of linked list is always dumped packets
		insTail(&(tmp->head),packet);
	}
	goto END;
	HERE:
		if(hLength(head)<maxrout+2){
			head=hInsTail(head,packet,dest,comand);
		}else
			writeToLogFile(packet,0);
END:return head;
}

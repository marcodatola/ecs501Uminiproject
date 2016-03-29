#include "queueListLib.h"
extern int maxioq , maxmq, maxrout;

void printList (t_elem *h) {
	for (; h; h = h->next)
		if(h->data)
		printf("%c, %c, %d, %d, %d, %s\n",h->data->l2sa,h->data->l2da,h->data->layer3.l3sa,h->data->layer3.l3da,h->data->layer3.prior,h->data->layer3.payload);
		//printf("%c%c%d%d%d%s\n",h->data->l2sa,h->data->l2da,h->data->layer3.l3sa,h->data->layer3.l3da,h->data->layer3.prior,h->data->layer3.payload);
	printf ("\n");
}

int length (t_elem *h) {
	int l;
	//printf("I AM GETTING HERE U CUNT\n");
	if(h&&h->data==NULL) return 0;
	for (l = 0; h; h = h->next, l++)
		;
	return l;
}

/*int countElem (t_elem *h, int ch) {
	int count;
	for (count = 0; h; h = h->next) 
		if (h->data == ch) count++;
	return count;
}*/

t_elem *insHead(t_elem * h, l2_t *ch) {
	t_elem *p;
	if ((p = (t_elem *) malloc(sizeof(t_elem)))) {
		p->data = ch;
		p->next = h;
		h = p;
	}
	else
		fprintf (stderr, "No available memory\n");
	return h;
}

void insTail (t_elem **h, l2_t *ch) {
	t_elem *p, *i;
	if ((p = (t_elem *)malloc(sizeof(t_elem)))) {
		p->data = ch;
		p->next = NULL;
		if ((*h)->data) {
			for (i = *h; i->next; i = i->next)	
				;
			i->next = p;
		}
		else
			(*h)->data = p->data;
	}
	else 
		fprintf (stderr, "No available memory\n");
}


/*t_elem *insSorted (t_elem *h, int ch) {
	t_elem *p, *i;
	if ((p = (t_elem *) malloc(sizeof(t_elem)))) {
		p->data = ch;
		if (h && ch > h->data) {
			for (i = h; i->next && (i->next)->data < ch; i = i->next)
				;
			p->next = i->next;
			i->next = p;
		}
		else {
			p->next = h;
			h = p;
		}
	}
	else
		fprintf(stderr, "No available memory\n");
	return h;
}*/

/*t_elem *find (t_elem *h, l2_t ch) {
	t_elem *p;
	p = h;
	while (p && p->data != ch) p = p->next;
	return p;
}

int exist (t_elem *h, l2_t ch) {
	int found;
	for (found = 0; h && !found; h = h->next) 
		if (h->data == ch) found = 1;
	return found;
}*/

l2_t *getFirstElem(t_elem *h){
	return (*h).data;
}

l2_t *getLastElem (t_elem *h){
	t_elem *p;
	for(p=h; p->next; p=p->next)
		;
	return p->data;
}


void del (t_elem **h, l2_t* ch) {
	t_elem *p, *q;
	if (*h) {
		if ((*h)->data == ch) {
			p = *h;
			*h = (*h)->next;
			free(p);
		}
		else {
			p = *h;
			q = (*h)->next;
			while (q && q->data != ch) {
				p = q;
				q = q->next;
			}
			if (q) {
				p->next = q->next;
				free (q);
			}
		}
	}
}

t_elem *deleteFirstElem (t_elem *h) {
	t_elem *p;
	if (h) {
		p=h;
		h=h->next;
		free(p);
		return h;
	}
	return NULL;
}

t_elem *deleteLastElem (t_elem *h) {
	t_elem *p, *q;
	if (h) {
		t_elem *p;
		for(q=h;q->next; q=q->next)
			;
		free(q);
	}
	return h;
}

t_elem *emptyList (t_elem *h) {
	t_elem *p, *q;
	p = h;
	while (p) {
		q = p;
		p = p->next;
		free(q);
	}
	return NULL;
}

l2_t *getNextPacket(t_elem* head,t_elem **p){
	l2_t* temp =NULL;
	if(*p){
		temp= (*p)->data;
		*p=(*p)->next;
	}
	return temp;
}

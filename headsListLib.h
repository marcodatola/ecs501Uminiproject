#include <stdio.h>
#include <stdlib.h>
#include "queueListLib.h"
#define CHECKL2SA 0
#define INPUT 0
#define OUTPUT 1

extern int prior;

/* looks for element in list 
 * returns 1 if found
 * returns 0 if not found */ 
int hExists (hlist_t *h, char target) ;

/*creates a pointer for the new queue
 *and allocates memory for a new element
 *of the list of pointers to the queues
 * it returns a pointer to the new queue*/
hlist_t *hInsTail (hlist_t *h, l2_t *ch,char dest,int comand) ;

/*looks for pointer to head
 *of a specific queue in the list
 *returns NULL if queue is not present
 *else returns pointer to head of queue */
t_elem *hFindQueue (hlist_t *h, char ch);

/*looks for pointer to head
 *of a specific queue in the list
 *returns NULL if queue is not present
 *else returns element with the pointer */
hlist_t *hFindPointer (hlist_t *h, char ch);

/*checks if there are any queues left to process*/
t_elem* hIsNotEmpty(hlist_t*, hlist_t **,int);

/*returns next element in list of heads of queue*/
void hNext(hlist_t*, hlist_t **);

/* returns number of elements */ 
int hLength(hlist_t * h);


/*prints all of the queues*/
void hPrintList(hlist_t* );//, int);

/*enqueues the packet in the correct queue contained in
 *the linked list of heads to the queues */
hlist_t* hEnqueue(l2_t* packet, hlist_t* head,char dest,int comand);

/*returns las element of list.
 *this is set to be the pointer
 *to the dumped packets list */
hlist_t* hGetlastElem (hlist_t * h);

/*returns first element of list
 *this is set to be the pointer
 * to the priority list */
hlist_t *hGetFirstElem(hlist_t *h);

/*returns new head of list
 *after having added an element
 *in head position*/
hlist_t *hInsHead(hlist_t * h, t_elem *ch);

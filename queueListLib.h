#include <stdio.h>
#include <stdlib.h>
#include "rulesFromFile.h"

/* returns number of elements */ 
int length(t_elem * h);

/* returns number of elements with info ch */
//int countElem(t_elem * h, int ch);

/* creates new element and inserts it at
 * head of list, returning the head */
t_elem * insHead(t_elem * h, l2_t* ch);

/* creates new element and inserts it at
 * tail of queue. It receioves a pointer to the head 
 * of queue pointer so it returns void */
void insTail (t_elem **h, l2_t *ch) ;

/* creates new element and inserts it in position
 * within the sorted list, returning the head */
//t_elem * insSorted(t_elem * h, int ch);

/* looks for element in list 
 * returns pointer if found
 * returns NULL if not found */ 
//t_elem * find(t_elem * h, l2_t ch);

/* looks for element in list 
 * returns 1 if found
 * returns 0 if not found */ 
//int exist(t_elem * h, l2_t ch);

/*returns the first element of the list*/
l2_t *getFirstElem(t_elem *h);

/*returns the last element of the list*/
l2_t *getLastElem (t_elem *h);

/* deletes element from list and return head */
void del(t_elem ** h, l2_t *ch); 

/*deletes first element from list and returns head */
t_elem * deleteFirstElem(t_elem * h);

/*deletes last element from list and returns head */
t_elem * deletLastElem(t_elem * h);

/* empties list h */ 
t_elem *emptyList(t_elem * h); 

/* prints list */
void printList(t_elem *h);

/*returns packet next packet in main queue*/
l2_t *getNextPacket(t_elem* head,t_elem **p);

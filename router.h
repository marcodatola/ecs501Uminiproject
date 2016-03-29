#include "headsListLib.h"
#define INPUTFILENAME "inputQueues_packets.csv"
#define OUTPUTFILENAME "errorlog.bat"


void setDimensions();

void populateTmpFromFile(l2_t** tmp,FILE *fin);
//populate main queue from input queues
void inputInMainQueue(hlist_t **head,t_elem **main);
//from main queue to output queue
hlist_t* output(t_elem **mainQueue,hlist_t *headsOfOutputQueues);
//writes packet with wrong details to log file
void writeToLogFile(l2_t* packet,int comand);

//sets priority queue in first position
//and dumped packet list in last
hlist_t* setPriorDumpQueues(hlist_t *);

//inputs in main queue element
void input (hlist_t ** p, t_elem **main);

//void error (char* string);


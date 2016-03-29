#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#define RFILE	"lookup.txt"
//read rules from file
void checkWithRules (t_elem **main);
int test(l2_t* packet,t_rule array[],int size);
//char getFromRules(l2_t *packet);
char getFromRules(l2_t *packet);

/*randomly select one of the possible routes*/
char randomchoice ();

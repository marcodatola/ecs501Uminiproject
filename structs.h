#define PAYLOAD 28
extern int maxioq,maxmq, maxrout;
typedef struct l3{
	int l3sa,l3da,prior;
	char payload[PAYLOAD];
}l3_t;

typedef struct l2{
	char l2sa,l2da;
	l3_t layer3;
}l2_t;

typedef struct _elem {
	l2_t* data;
	struct _elem *next;
} t_elem;

typedef struct rule{
	int client;
	char router;
}t_rule;


typedef struct hlist {
	t_elem* head;
	char id;
	struct hlist *next;
} hlist_t;


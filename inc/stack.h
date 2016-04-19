struct stack{
	int size = 5;
	int stk[size];
	int top = -1;
}

typedef struct stack STACK;

void push(struct stack s, int number);
int pop(struct stack s);
int peak(struct stack s);

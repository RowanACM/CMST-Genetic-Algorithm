struct stack{
	int size;
	int stk[5];
	int top;
};

typedef struct stack STACK;

void push(struct stack s, int number);
int pop(struct stack s);
int peak(struct stack s);

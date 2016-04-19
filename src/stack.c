#include "stack.h"

void push(struct stack s, int number){
	if(top => s.size){
		s.size = s.size * 2;
		realloc(s.stk, s.size);
	}
	s.top = s.top + 1;
	s.stk[s.top] = number;
}

int pop(struct stack s){
	if(s.top >= 0)
		int result = s.stk[s.top];
		s.top = s.top - 1;
		return result;
	}
	return INT_MAX;
}

int peak(struct stack s){
	if(s.top > 0){
		return s.stk[s.top];
	} 
	return INT_MAX;
}

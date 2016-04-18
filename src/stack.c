void push(struct stack s, int number){
	if(top => s.size){
		s.size = s.size * 2;
		realloc(s.stk, s.size);
	}
	s.stk[s.top] = number;
	s.top = s.top + 1;
}

int pop(struct stack s){
	if(s.top > 0){
		s.top = s.top - 1;
		return s.stk[top];
	}
	return -1;
}

int peak(struct stack s){
	if(s.top > 0){
		return s.stk[top - 1];
	} 
	return -1;
}

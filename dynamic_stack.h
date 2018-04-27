#ifndef DYN_STACK_H
#define DYN_STACK_H


template<typename T, int MAX_SIZE>
class Stack{
	T** tab;
	int top;
	int lim;
public:
	void push(const T& e);
	T pop();
	bool is_empty() const;
};


#endif
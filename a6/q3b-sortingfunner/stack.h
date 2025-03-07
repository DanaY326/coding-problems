#include <stdbool.h>

// stack provides a Stack ADT for int *
struct stack;

// stack_create() creates a new empty stack.
// effects: allocates memory (client must call stack_destroy)
struct stack *stack_create(void);

// stack_destroy(stck) frees all memory for stck.
// effects: stck is invalidated
void stack_destroy(struct stack *stck);

// stack_is_empty(stck) determines if stck is empty.
bool stack_is_empty(const struct stack *stck);

// stack_top(stck) finds the top item in stck.
// requires: stck is non-empty
int *stack_top(const struct stack *stck);

// stack_pop(stck) finds and pops (removes) the top item in stck.
// requires: stck is non-empty
// effects:  modifies stck
int *stack_pop(struct stack *stck);

// stack_push(stck, item) pushes (adds) item to the top of stck.
// effects: modifies stck
void stack_push(struct stack *s, int *);

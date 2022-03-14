#include "../inc/push_swap.h"

struct node	*sort_3(struct node *stack_a)
{
	if (stack_a->numberfield < stack_a->next->numberfield && stack_a->next->numberfield < stack_a->next->next->numberfield)
	{
		printf("Already sorted.\n");
	}
	else if (stack_a->numberfield < stack_a->next->numberfield && stack_a->numberfield < stack_a->next->next->numberfield && stack_a->next->numberfield > stack_a->next->next->numberfield)
	{
		sa(stack_a);
		// printlist(stack_a);
		ra(&stack_a);
	}
	else if (stack_a->numberfield > stack_a->next->numberfield && stack_a->numberfield < stack_a->next->next->numberfield && stack_a->next->numberfield < stack_a->next->next->numberfield)
	{
		sa(stack_a);
	}
	else if (stack_a->numberfield < stack_a->next->numberfield && stack_a->numberfield > stack_a->next->next->numberfield && stack_a->next->numberfield > stack_a->next->next->numberfield)
	{
		rra(&stack_a);
	}
	else if (stack_a->numberfield > stack_a->next->numberfield && stack_a->numberfield > stack_a->next->next->numberfield && stack_a->next->numberfield < stack_a->next->next->numberfield)
	{
		ra(&stack_a);
	}
	else if (stack_a->numberfield > stack_a->next->numberfield && stack_a->next->numberfield > stack_a->next->next->numberfield)
	{
		sa(stack_a);
		rra(&stack_a);
	}
	return(stack_a);
}

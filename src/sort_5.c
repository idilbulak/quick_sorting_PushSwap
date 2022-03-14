#include "../inc/push_swap.h"

struct node	*sort_5(struct node *stack_a, struct node *stack_b)
{
	if (stack_a->next->numberfield == find_min(stack_a))
		sa(stack_a);
	if (stack_a->next->next->numberfield == find_min(stack_a))
	{
		ra(&stack_a);
		sa(stack_a);
	}
	if (stack_a->next->next->next->numberfield == find_min(stack_a))
	{
		rra(&stack_a);
		rra(&stack_a);
	}
	if (stack_a->next->next->next->next->numberfield == find_min(stack_a))
		rra(&stack_a);
	pb(&stack_a, &stack_b);
	if (stack_a->next->numberfield == find_min(stack_a))
		sa(stack_a);
	if (stack_a->next->next->numberfield == find_min(stack_a))
	{
		ra(&stack_a);
		sa(stack_a);
	}
	if (stack_a->next->next->next->numberfield == find_min(stack_a))
		rra(&stack_a);
	pb(&stack_a, &stack_b);
	stack_a = sort_3(stack_a);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	return(stack_a);
}

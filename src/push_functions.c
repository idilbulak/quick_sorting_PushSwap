#include "../inc/push_swap.h"

void	pb(struct node **stack_a, struct node **stack_b)
{

	if (*stack_b == NULL)
	{
		*stack_b = addto_emptylist(*stack_b, (*stack_a)->numberfield);
		*stack_a = delete_first(*stack_a);
	}
	else
	{
		if (ft_lstsize(*stack_a) == 1)
		{
			*stack_b = addto_beg(*stack_b, (*stack_a)->numberfield);
			*stack_a = NULL;
		}
		if (ft_lstsize(*stack_a) != 0)
        {
	    	*stack_b = addto_beg(*stack_b, (*stack_a)->numberfield);
		    *stack_a = delete_first(*stack_a);
        }
	}
	printf("pb\n");
}

void	pa(struct node **stack_a, struct node **stack_b)
{	
	if (*stack_b != NULL)
	{
		if (*stack_a == NULL)
		{
			*stack_a = addto_emptylist(*stack_a, (*stack_b)->numberfield);
			*stack_b = delete_first(*stack_b);
		}
		else
		{
			*stack_a = addto_beg(*stack_a, (*stack_b)->numberfield);
			if (ft_lstsize(*stack_b) == 1)
				stack_b = NULL;
			else
				*stack_b = delete_first(*stack_b);
		}
	}
	printf("pa\n");
}

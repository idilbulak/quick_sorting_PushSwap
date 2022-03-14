#include "../inc/push_swap.h"

int	find_next_min(struct node *stack, int min)
{
	struct node	*temp;
	int			result;

	if (stack != NULL)
	{
		temp = stack;
		if (temp->numberfield == min)
			temp = temp->next;
		result = temp->numberfield;
		while (temp != NULL)
		{
			if (temp->numberfield < result)
			{
				if (temp->numberfield > min)
					result = temp->numberfield;
			}
			temp = temp->next;
		}
	}
	return (result);
}
struct node	*sort_large(struct node *stack_a, struct node *stack_b)
{
	int	size;
	int	chunks;
	int	range;
	int	min;
	struct node	*next_min;

	size = ft_lstsize(stack_a);
	next_min = addto_emptylist(next_min, find_min(stack_a));
	if (size < 0)
		printf("No inputs!");
	else if (size > 0 && size < 50)
		chunks = 2;
	else if (size >= 50 && size < 75)
		chunks = 3;
	else if (size >= 75 && size < 100)
		chunks = 4;
	else if (size >= 100 && size < 200)
		chunks = 5;
	else if (size <= 200 && size < 300)
		chunks = 7;
	else if (size <= 300 && size < 600)
		chunks = 11;
	else
		chunks = 15;
	range = size / chunks;
	printf("range:%d\n", range);
	min = find_min(stack_a);
	printf("min: %d\n", min);
	printf("next_min: %d\n", find_next_min(stack_a, min));
	while (range > 1 && stack_a)
	{
		*next_min = addto_end(*next_min, find_next_min(stack_a, min));
		next_min = &(*next_min)->next;
		min = (*next_min)->numberfield;
		printf("min :%d\n", min);
		printf("next_min :%d\n", (*next_min)->numberfield);
		range--;
	}
	printlist(next_min);
	// return (stack_a);
}

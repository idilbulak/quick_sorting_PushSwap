/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doublylinklist_utils3.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:06:17 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/30 16:55:32 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_index(struct node *stack_a, int numberfield)
{
	struct node	*temp;
	int			count;

	temp = stack_a;
	count = 1;
	while (temp)
	{
		if (temp->numberfield == numberfield)
			return (count);
		count++;
		temp = temp->next;
	}
	return (count);
}

int	find_last(struct node **stack)
{
	struct node	*temp;
	int			last_number;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	last_number = temp->numberfield;
	return (last_number);
}

struct node	**bring_max_to_top(struct node **stack_a, struct node **stack_b)
{
	int max = find_max(*stack_b);
	int index = find_index(*stack_b, max);
	int count = 0;
	if((*stack_b)->numberfield != max)
	{
		if (index <= ft_lstsize(*stack_b) / 2 + 1)
		{
			while (count < index - 1)
			{
				rb(stack_b);
				count++;
			}
		}
		else
		{
			while (count < (ft_lstsize(*stack_b) - index + 1))
			{
				rrb(stack_b);
				count++;
			}
		}	
	}
	return (stack_b);
}

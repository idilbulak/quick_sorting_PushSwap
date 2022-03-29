/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doublylinklist_utils3.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 15:06:17 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/29 19:22:58 by ibulak        ########   odam.nl         */
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

struct node	**bring_max_to_top(struct node **stack)
{
	int max = find_max(*stack);
	int index = find_index(*stack, max);
	int count = 0;
	if((*stack)->numberfield != max)
	{
		if (index <= ft_lstsize(*stack) / 2 + 1)
		{
			while (count < index - 1)
			{
				rb(stack);
				count++;
			}
		}
		else
		{
			while (count < (ft_lstsize(*stack) - index + 1))
			{
				rrb(stack);
				count++;
			}
		}	
	}
	return (stack);
}

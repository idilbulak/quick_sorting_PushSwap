/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:38:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/30 17:09:01 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_hold_first(struct node **stack_a, struct node *temp)
{
	struct node	*temp2;
	struct node	*stack_temp;
	int			hold_first;
	int			flag;

	temp2 = temp;
	stack_temp = *stack_a;
	flag = 1;
	while ((*stack_a) && flag)
	{
		while (temp && flag)
		{
			if (temp->numberfield == (*stack_a)->numberfield)
			{
				hold_first = (*stack_a)->numberfield;
				flag = 0;
			}
			temp = temp->next;
		}
		temp = temp2;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = stack_temp;
	return (hold_first);
}

int	ft_hold_last(struct node **stack_a, struct node *temp)
{
	struct node	*temp2;
	struct node	*stack_temp;
	int			hold_last;
	int			flag;

	temp2 = temp;
	stack_temp = *stack_a;
	flag = 1;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	while ((*stack_a) && flag)
	{
		while (temp && flag)
		{
			if (temp->numberfield == (*stack_a)->numberfield)
			{
				hold_last = (*stack_a)->numberfield;
				flag = 0;
			}
			temp = temp->next;
		}
		temp = temp2;
		*stack_a = (*stack_a)->prev;
	}
	*stack_a = stack_temp;
	return (hold_last);
}

struct node	*sort_large(struct node **stack_a, struct node **stack_b)
{
	int	size = ft_lstsize(*stack_a);
	int	chunks = how_many_chunks(size);
	int	range = size / chunks;
	printf("range: %d\n", range);
	int count = 0;
	int count_temp = 0;
	int	max = find_max(*stack_a);
	while (count < chunks)
	{
		int	min = find_min(*stack_a);
		struct node	*temp = find_chunk(stack_a, min, range);
		while (count_temp < ft_lstsize(temp))
		{
			stack_a = what_to_push(stack_a, stack_b, temp);
			push_organize(stack_a, stack_b);
			count_temp++;
		}
		count_temp = 0;
		stack_b = bring_max_to_top(stack_a,stack_b);
		count++;	
	}
	if ((*stack_a) != NULL)
	{
		count_temp = 0;
		int	min = find_min(*stack_a);
		while (count_temp < ft_lstsize(*stack_a))
		{
			while(*stack_a)
			push_organize(stack_a, stack_b);
			count_temp++;
		}
	}
	stack_b = bring_max_to_top(stack_a, stack_b);
	count = 0;
	size = ft_lstsize(*stack_b);
	while (count < size)
	{
		pa (stack_a, stack_b);
		count++;
	}
	printlist(*stack_a);
	return (*stack_a);
}

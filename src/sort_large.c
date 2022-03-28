/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:38:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/28 12:52:41 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_hold_first(struct node **stack_a, struct node *temp)
{
	struct node	*temp2;
	int			hold_first;
	int			flag;

	temp2 = temp;
	flag = 1;
	while (*stack_a && flag)
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
	return (hold_first);
}

int	ft_hold_last(struct node **stack_a, struct node *temp)
{
	struct node	*temp2;
	int			hold_last;
	int			flag;

	temp2 = temp;
	flag = 1;
	while (*stack_a && flag)
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
	return (hold_last);
}

struct node	*sort_large(struct node **stack_a, struct node **stack_b)
{
	int	chunks;
	int	range;
	int	min;
	struct node	*temp;
	int	index;
	int count;
	int	i = 0;
	
	chunks = how_many_chunks(ft_lstsize(*stack_a));
	range = ft_lstsize(*stack_a) / chunks;
	while (i < chunks)
	{
		min = find_min(*stack_a);
		temp = find_chunk(stack_a, min, range);
		printlist(temp);
		count = 0;
		while (count < range)
		{	
			stack_a = what_to_push(stack_a, temp);
			push_organize(stack_a, stack_b);
			count++;
		}
	// 	count = 0;
	// printlist (*stack_b);
	// 	stack_a = pushlastmin(stack_a);
	// 	push_organize(stack_a, stack_b);
		int max_b = find_max(*stack_b);
		while ((*stack_b)->numberfield != max_b)
			rb(stack_b);
	// 	max_b = find_max(*stack_b);
	// 	while ((*stack_b)->numberfield != max_b)
	// 		rra(stack_b);
	printlist (*stack_a);
	i++;
	}
	// count = 0;
	// int size = ft_lstsize(*stack_b);
	// while (count < size)
	// {
	// 	pa (stack_a, stack_b);
	// 	count++;
	// }
	return (*stack_a);
}

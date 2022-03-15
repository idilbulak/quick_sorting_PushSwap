/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:38:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/15 20:37:43 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	how_many_chunks(int size)
{
	int	chunks;

	if (size < 0)
		printf("No inputs!");
	else if (size > 5 && size < 50)
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
	return (chunks);
}

struct node	*find_chunk(struct node **stack_a, int min, int range)
{
	struct node	*temp;
	int			count;

	count = 0;
	temp = addto_emptylist(temp, min);
	while (*stack_a != NULL && count < range)
	{
		printlist(*stack_a);
		min = find_next_min(*stack_a, min);
		temp = addto_beg(temp, min);
		printf("min:%d\n", min);
		count++;
	}
	printlist(temp);
	return (temp);
}

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
	int	size;
	int	chunks;
	int	range;
	int	min;
	int	hold_first;
	int	hold_last;
	struct node	*temp;
	int	index;
	
	size = ft_lstsize(*stack_a);
	chunks = how_many_chunks(size);
	range = size / chunks;
	min = find_min(*stack_a);
	temp = find_chunk(stack_a, min, range);
	printlist(temp);
	hold_first = ft_hold_first(stack_a, temp);
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
	hold_last = ft_hold_last(stack_a, temp);
	while ((*stack_a)->prev != NULL)
		*stack_a = (*stack_a)->prev;
	// printf("first:%d", find_index(*stack_a, hold_first));
	int index_first = find_index(*stack_a, hold_first);
	int index_last = find_index(*stack_a, hold_last);
	if ( index_first <= (size - index_last + 1))
	{
		index = 0;
		while (index < index_first - 1)
		{
			ra(stack_a);
			index++;
		}
	}
	else
	{
		index = 0;
		// printf("index:%d", index);
		// printf("size:%d", size);
		// printf("hold_last:%d",  hold_last);
		// printf("last:%d", size - find_index(*stack_a, hold_last) + 1);
		while (index < (size - index_last + 1))
		{
			rra(stack_a);
			index++;
		}
	}
	pb(stack_a, stack_b);
	// printlist(*stack_a);
	// printlist(*stack_b);
	return (*stack_a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/15 14:38:23 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/25 16:36:31 by ibulak        ########   odam.nl         */
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
	while (*stack_a != NULL && count < range - 1)
	{
		min = find_next_min(*stack_a, min);
		temp = addto_beg(temp, min);
		count++;
	}
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
	int count = 0;
	int	i = 0;
	
	size = ft_lstsize(*stack_a);
	chunks = how_many_chunks(size);
	range = size / chunks;
	while (i < chunks)
{
	min = find_min(*stack_a);
	temp = find_chunk(stack_a, min, range);
	while (count < range - 1)
	{	
		hold_first = ft_hold_first(stack_a, temp);
		while ((*stack_a)->next != NULL)
			*stack_a = (*stack_a)->next;
		hold_last = ft_hold_last(stack_a, temp);
		while ((*stack_a)->prev != NULL)
			*stack_a = (*stack_a)->prev;
		int index_first = find_index(*stack_a, hold_first);
		int index_last = find_index(*stack_a, hold_last);
		if ( index_first <= size - index_last + 1)
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
			while (index <= (size - index_last))
			{
				rra(stack_a);
				index++;
			}
		}
		if ((*stack_b) == NULL)
			pb(stack_a, stack_b);
		else if (ft_lstsize(*stack_b) == 1)
		{
			pb(stack_a, stack_b);
			if ((*stack_b)->numberfield < (*stack_b)->next->numberfield)
				sb(*stack_b);
		}
		else
		{
			min = find_min(*stack_b);
			if ((*stack_a)->numberfield < min)
			{
				pb(stack_a, stack_b);
				ra(stack_b);
			}
			else
			{
				while ((*stack_a)->numberfield < (*stack_b)->numberfield)
					ra(stack_b);
				pb(stack_a, stack_b);
			}
		}
		count++;
	}
	int max_b = find_max(*stack_b);
	while ((*stack_b)->numberfield != max_b)
		rra(stack_b);
	int lastminofchunk = find_min(*stack_a);
	index = find_index(*stack_a, lastminofchunk);
	count = 0;
	if (index <= ft_lstsize(*stack_a) / 2)
		while (count < index - 1)
		{
			ra(stack_a);
			count++;
		}
	else
	{
		while (count < ft_lstsize(*stack_a) - index + 1)
		{
			rra (stack_a);
			index++;
		}
	}
	min = find_min(*stack_b);
	if ((*stack_a)->numberfield < min)
	{
		pb(stack_a, stack_b);
		ra(stack_b);
	}
	else
	{
		while ((*stack_a)->numberfield < (*stack_b)->numberfield)
			ra(stack_b);
		pb(stack_a, stack_b);
	}
	max_b = find_max(*stack_b);
	while ((*stack_b)->numberfield != max_b)
		rra(stack_b);
i++;
}
	count = 0;
	size = ft_lstsize(*stack_b);
	while (count < size)
	{
		pa (stack_a, stack_b);
		count++;
	}
	return (*stack_a);
}

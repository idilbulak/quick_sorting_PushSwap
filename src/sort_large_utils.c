/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_large_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/28 09:42:16 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/28 13:04:01 by ibulak        ########   odam.nl         */
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

struct node	**pushlastmin(struct node **stack_a)
{
	int	count;
	int	lastminofchunk = find_min(*stack_a);
	int index = find_index(*stack_a, lastminofchunk);
	count = 0;
	if (index <= ft_lstsize(*stack_a) / 2)
	{
		while (count < index - 1)
		{
			ra(stack_a);
			count++;
		}
	}
	else
	{
		while (count < ft_lstsize(*stack_a) - index + 1)
		{
			rra (stack_a);
			count++;
		}
	}
	return (stack_a);
}

struct node	**what_to_push(struct node **stack_a, struct node *temp)
{
	int	hold_first;
	int	hold_last;
	int	index_first;
	int	index_last;

printlist(*stack_a);
	hold_first = ft_hold_first(stack_a, temp);
	while ((*stack_a)->next != NULL)
		*stack_a = (*stack_a)->next;
printlist(*stack_a);
	hold_last = ft_hold_last(stack_a, temp);
	printf("hold first:%d\n", hold_first);
	printf("hold last:%d\n", hold_last);
	while ((*stack_a)->prev != NULL)
		*stack_a = (*stack_a)->prev;
	printlist(*stack_a);
	index_first = find_index(*stack_a, hold_first);
	index_last = find_index(*stack_a, hold_last);
	stack_a = bringtotop(stack_a, index_first, index_last);
	return (stack_a);
}

struct node	**bringtotop(struct node **stack_a, int index_first, int index_last)
{
	int	index;

	index = 0;
	if (index_first <= ft_lstsize(*stack_a) - index_last + 1 || index_last == index_first)
	{
		while (index < index_first - 1)
		{
			ra(stack_a);
			index++;
		}
	}
	else
	{
		while (index <= (ft_lstsize(*stack_a) - index_last))
		{
			rra(stack_a);
			index++;
		}
	}
	return (stack_a);
}

void	*push_organize(struct node **stack_a, struct node **stack_b)
{
	int	min;

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
			rb(stack_b);
		}
		else
		{
			while ((*stack_a)->numberfield < (*stack_b)->numberfield)
				rb(stack_b);
			pb(stack_a, stack_b);
		}
	}
	return (0);
}

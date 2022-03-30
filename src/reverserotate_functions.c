/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverserotate_functions.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 20:16:22 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/30 15:32:04 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(struct node **stack_a)
{
	int	x;

	x = ft_lstsize(*stack_a);
	while (x > 1)
	{
		rotate(stack_a, 1);
		x--;
	}
	printf("rra\n");
}

void	rrb(struct node **stack_b)
{
	int	x;

	x = ft_lstsize(*stack_b);
	while (x > 1)
	{
		rotate(stack_b, 1);
		x--;
	}
	printf("rrb\n");
}

void	rrr(struct node **stack_a, struct node **stack_b)
{
	int	x;

	x = ft_lstsize(*stack_a);
	while (x > 1)
	{
		rotate(stack_a, 1);
		x--;
	}
	x = ft_lstsize(*stack_b);
	while (x > 1)
	{
		rotate(stack_b, 1);
		x--;
	}
	printf("rrr\n");
}

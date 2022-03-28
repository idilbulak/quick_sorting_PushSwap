/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:17:13 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/28 09:49:23 by ibulak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	struct node	*stack_a;
	struct node	*stack_b;
	int			i;
	int			n;

	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	if (argc < 2)
		write(1, "Please put inputs!", 18);
	else
	{
		while (i < argc - 1)
		{
			n = atoi(argv[argc - 1 - i]);
			{
				if (stack_a == NULL)
					stack_a = addto_emptylist(stack_a, n);
				else
					stack_a = addto_beg(stack_a, n);
			}
			i++;
		}
		printlist (stack_a);
		if (argc == 4)
			stack_a = sort_3(stack_a);
		else if (argc == 6)
			stack_a = sort_5(stack_a, stack_b);
		else if (argc > 6)
			sort_large(&stack_a, &stack_b);
		// printf("min:%d", find_min(stack_a));
		// printf("next min:%d", find_next_min(stack_a, find_min(stack_a)));
		// printf("next next min:%d", find_next_min(stack_a, find_next_min(stack_a, find_min(stack_a))));
		printlist (stack_a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_doubly_linkedlist.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ibulak <ibulak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/09 11:17:13 by ibulak        #+#    #+#                 */
/*   Updated: 2022/03/09 21:53:50 by ibulak        ########   odam.nl         */
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
		// find_max(stack_a);
		// find_min(stack_a);
		if (argc == 4)
			stack_a = sort_3(stack_a);
		else if (argc == 6)
			stack_a = sort_5(stack_a, stack_b);
		printlist (stack_a);
	// printlist (stack_b);
	// pb(&stack_a, &stack_b);
	// pb(stack_a, stack_b);
	// pb(stack_a, stack_b);
	// rra(&stack_a);
		// printf("stack_a:");
		// printlist (stack_a);
		// printf("stack_b:");
		// printlist (stack_b);
	// printf("%d", ft_lstsize(stack_a));
	// system("leaks a.out");
	// ra((t_node *)stack_a, argc - 1);
	// printlist (stack_a);
	// printf("1:%d\n", stack_a->numberfield);
	// printf("2:%d\n", stack_a->next->numberfield);
	// printf("3:%d\n", stack_a->next->next->numberfield);
	// printf("%d", argc);
	// printf("3next:%d\n", stack_a->next->next->next->numberfield);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:06:59 by acepni            #+#    #+#             */
/*   Updated: 2023/07/24 15:17:17 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_instructions3(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "rr")))
	{
		rotate(stack_a);
		rotate(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rra")))
	{
		reverse_rotate(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rrb")))
	{
		reverse_rotate(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "rrr")))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		return (0);
	}
	return (1);
}

int	execute_instructions2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "pb")))
	{
		push(stack_b, stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "ra")))
	{
		rotate(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "rb")))
	{
		rotate(stack_b);
		return (0);
	}
	return (execute_instructions3(line, stack_a, stack_b));
}

int	execute_instructions(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
	{
		swap(stack_a);
		return (0);
	}
	if (!(ft_strcmp(line, "sb")))
	{
		swap(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "ss")))
	{
		swap(stack_a);
		swap(stack_b);
		return (0);
	}
	if (!(ft_strcmp(line, "pa")))
	{
		push(stack_a, stack_b);
		return (0);
	}
	return (execute_instructions2(line, stack_a, stack_b));
}

void	print_checker_res(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		ft_putendl_fd("OK\n", 1);
	else
		ft_putendl_fd("KO\n", 1);
	if (*stack_a)
		free_stack(stack_a);
	if (*stack_b)
		free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*line;

	if (argc < 2)
		return (0);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	ft_check_args(argc, argv);
	init_stack(stack_a, argc, argv);
	while (get_next_line(0, &line))
	{
		if (execute_instructions(line, stack_a, stack_b))
		{
			ft_error("Error");
			return (-1);
		}
		free(line);
	}
	print_checker_res(stack_a, stack_b);
	return (0);
}

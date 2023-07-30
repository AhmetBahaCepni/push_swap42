/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:27:13 by acepni            #+#    #+#             */
/*   Updated: 2023/07/24 15:41:33 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static int	get_ra_count(t_list *stack_a, int i)
{
	int	ra_count;

	ra_count = 0;
	while (stack_a)
	{
		if (((stack_a->index >> i) & 1) == 1)
			ra_count++;
		stack_a = stack_a->next;
	}
	return (ra_count);
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int size, int i)
{
	t_list	*head_a;
	int		max_bits;
	int		ra_count;
	int		j;

	head_a = *stack_a;
	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		ra_count = get_ra_count(*stack_a, i);
		while (j++ < size && ra_count > 0)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1 && ra_count-- > 0)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		if (i++ != 0 && is_sorted(*stack_a) == 1)
			break ;
	}
}

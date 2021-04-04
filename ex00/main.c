/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 22:54:22 by dongmlee          #+#    #+#             */
/*   Updated: 2021/04/04 22:54:28 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		row_check(int sth[4][4], int rows_num[24][4], int colums, int rows);
int		left_check(int sth[4][4], int rows_num[24][4], int colums, int rows);
int		right_check(int sth[4][4], int rows_num[24][4], int colums, int rows);
int		colums_check(int sth[4][4], char grid[4][4]);
int		down_check(int sth[4][4], char grid[4][4]);
int		up_check(int sth[4][4], char grid[4][4]);
void	reset_grip(char grid[4][4]);
void	atoi(char *str, int udlr[4][4]);
void	print_grid(char grid[4][4]);
int		resolve(char grid[4][4], int sth[4][4], int colums);
int		columspan(int sth[4][4], char grid[4][4]);
void	reset_grip(char grid[4][4]);

int		main(int argc, char *argv[])
{
	char	grid[4][4];
	int		sth[4][4];
	int		colums;

	colums = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	atoi(argv[1], sth);
	if (!resolve(grid, sth, colums))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	print_grid(grid);
	return (1);
}

void	reset_grip(char grid[4][4])
{
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			grid[i][j] = 0;
	}
}

void	print_grid(char grid[4][4])
{
	int		y;
	int		x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			write(1, &grid[y][x], 1);
			if (x != (4 - 1))
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

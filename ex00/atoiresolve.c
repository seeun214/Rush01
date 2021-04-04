/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoiresolve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:17:51 by dongmlee          #+#    #+#             */
/*   Updated: 2021/04/04 23:18:01 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		g_rows_num[24][4] = {{1, 2, 3, 4}, {1, 2, 4, 3}, {1, 3, 2, 4}, \
	{1, 3, 4, 2}, {1, 4, 2, 3}, {1, 4, 3, 2},\
	{2, 1, 3, 4}, {2, 1, 4, 3}, {2, 3, 1, 4}, \
	{2, 3, 4, 1}, {2, 4, 1, 3}, {2, 4, 3, 1}, \
	{3, 1, 2, 4}, {3, 1, 4, 2}, {3, 2, 1, 4}, \
	{3, 2, 4, 1}, {3, 4, 1, 2}, {3, 4, 2, 1}, \
	{4, 1, 2, 3}, {4, 1, 3, 2}, {4, 2, 1, 3}, \
	{4, 2, 3, 1}, {4, 3, 1, 2}, {4, 3, 2, 1}};

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

void	atoi(char *str, int udlr[4][4])
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			udlr[i / (2 * 4)][(i / 2) % 4] = str[i] - '0';
		}
		i++;
	}
}

int		resolve(char grid[4][4], int sth[4][4], int colums)
{
	int		i;
	int		rows;
	int		index;

	index = 0;
	if (colums == 4)
	{
		columspan(sth, grid);
	}
	while (colums < 4)
	{
		i = -1;
		while (++i < 24)
		{
			if (row_check(sth, g_rows_num, colums, i))
			{
				rows = -1;
				while (++rows < 4)
					grid[colums][rows] = g_rows_num[i][rows];
				resolve(grid, sth, colums + 1);
			}
		}
	}
	return (1);
}

int		columspan(int sth[4][4], char grid[4][4])
{
	int rows;

	rows = 0;
	while (rows < 4)
	{
		if (colums_check(sth, grid))
		{
			return (0);
		}
	}
}

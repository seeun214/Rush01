/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colum_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:13:33 by dongmlee          #+#    #+#             */
/*   Updated: 2021/04/04 23:13:39 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		colums_check(int sth[4][4], char grid[4][4])
{
	if (down_check(sth, grid) && up_check(sth, grid))
		return (0);
	return (1);
}

int		down_check(int sth[4][4], char grid[4][4])
{
	int colums;
	int rows;
	int count;
	int max_num;

	rows = 0;
	while (rows++ < 4)
	{
		count = 1;
		colums = 0;
		max_num = grid[colums][rows];
		while (colums++ < 4)
		{
			if (max_num <= grid[colums][rows])
			{
				max_num = grid[colums][rows];
				count++;
			}
		}
		if (count != sth[0][colums])
			return (0);
	}
	return (1);
}

int		up_check(int sth[4][4], char grid[4][4])
{
	int colums;
	int rows;
	int count;
	int max_num;

	rows = 0;
	while (rows++ < 4)
	{
		count = 1;
		colums = 3;
		max_num = grid[colums][rows];
		while (colums-- > 0)
		{
			if (max_num <= grid[colums][rows])
			{
				max_num = grid[colums][rows];
				count++;
			}
		}
		if (count != sth[1][colums])
			return (0);
	}
	return (1);
}

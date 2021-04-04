/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 23:02:19 by dongmlee          #+#    #+#             */
/*   Updated: 2021/04/04 23:02:26 by dongmlee         ###   ########.fr       */
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

int		row_check(int sth[4][4], int rows_num[24][4], int colums, int rows)
{
	if (left_check(sth, rows_num, colums, rows) && \
right_check(sth, rows_num, colums, rows))
		return (1);
	return (0);
}

int		left_check(int sth[4][4], int rows_num[24][4], int colums, int rows)
{
	int i;
	int count;
	int max_num;

	count = 1;
	i = 0;
	max_num = rows_num[rows][i];
	while (i++ < 4)
	{
		if (max_num <= rows_num[rows][i])
		{
			max_num = rows_num[rows][i];
			count++;
		}
	}
	if (count != sth[2][colums])
		return (0);
	return (1);
}

int		right_check(int sth[4][4], int rows_num[24][4], int colums, int rows)
{
	int i;
	int count;
	int max_num;

	count = 1;
	i = 3;
	max_num = rows_num[rows][i];
	while (i-- > 0)
	{
		if (max_num <= rows_num[rows][i])
		{
			max_num = rows_num[rows][i];
			count++;
		}
	}
	if (count != sth[3][colums])
		return (0);
	return (1);
}

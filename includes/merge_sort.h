/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_sort.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 15:25:37 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/21 10:39:45 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H
# include <stdio.h>
# include <stdlib.h>

void	copy_data_to_temp_array(int **temp_array, int *array, int starting_index, int ending_index);
int		*create_array(int size);
void	copy_remaining_elements(int i, int j, int ending_index, int **array, int *temp_array);
void	merge(int *arr, int left_index, int middle_index, int right_index);
void	merge_sort(int *arr, int left_index, int right_index);
void	printArray(int A[], int size);

#endif

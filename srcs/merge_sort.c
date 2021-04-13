/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/19 15:25:24 by tuperera      #+#    #+#                 */
/*   Updated: 2021/04/13 15:33:51 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/merge_sort.h"

void copy_data_to_temp_array(int **temp_array, int *array, int starting_index, int ending_index) {
	int i = 0;

	while (i < ending_index) {
		(*temp_array)[i] = array[starting_index + i];
		i++;
	}
}

int *create_array(int size) {
	int *array;
	int i;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		exit_error("Malloc failed.\n");
	i = 0;
	while (i < size) {
		array[i] = 0;
		i++;
	}
	return (array);
}

void copy_remaining_elements(int i, int j, int ending_index, int **array, int *temp_array) {
	while (i < ending_index) {
        (*array)[j] = temp_array[i];
        i++;
        j++;
    }
}

void merge(int *arr, int left_index, int middle_index, int right_index)
{
    int i, j, k;
    int n1 = middle_index - left_index + 1;
    int n2 = right_index - middle_index;
 
    int *temp_left_array = create_array(n1);
	int *temp_right_array = create_array(n2);

	copy_data_to_temp_array(&temp_left_array, arr, left_index, n1);
	copy_data_to_temp_array(&temp_right_array, arr, middle_index + 1, n2);

    i = 0;
    j = 0;
    k = left_index;
    while (i < n1 && j < n2) {
        if (temp_left_array[i] <= temp_right_array[j]) {
            arr[k] = temp_left_array[i];
            i++;
        }
        else {
            arr[k] = temp_right_array[j];
            j++;
        }
        k++;
    }

    copy_remaining_elements(i, k, n1, &arr, temp_left_array);
    copy_remaining_elements(j, k, n2, &arr, temp_right_array);
}

void merge_sort(int *arr, int left_index, int right_index)
{
    if (left_index < right_index) {
        int middle_index = left_index + (right_index - left_index) / 2;
 
        merge_sort(arr, left_index, middle_index);
        merge_sort(arr, middle_index + 1, right_index);
 
        merge(arr, left_index, middle_index, right_index);
    }
}
 
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

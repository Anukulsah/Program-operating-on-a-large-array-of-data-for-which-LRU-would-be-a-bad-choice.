// Question
/*
    Write some program, operating on a large array of data, for which LRU would be a bad choice of algorithm. What assumption does
    LRU rely on but your code contradicts.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

int main()
{
    int last_used_index = 0;
    int i, j, k;
    bool data_in_window;
    int toogle_value = 0;
    int last_replaced_data[2] = {0, 0};
    int request_queue[40] = {2, 1, 4, 3, 6, 2, 3, 5, 4, 4, 5, 3, 4, 1, 2, 3, 1, 3, 4, 1, 4, 5, 1, 3, 4, 4, 3, 2, 6, 7, 5, 9, 6, 6, 7, 4, 5, 6, 7, 4};
    int recently_used_list[4] = {0, 0, 0, 0};
    printf("Data Requested By Users : ");
    for (i = 0; i < 40; i++)
    {
        printf("%d ", request_queue[i]);
    }
    for (i = 0; i < 40; i++)
    {
        sleep(5);
        data_in_window = false;
        printf("\nRecently Used Data Window : %d  %d  %d  %d \n", recently_used_list[0], recently_used_list[1], recently_used_list[2], recently_used_list[3]);
        printf("\nNow Requested Data : %d\n", request_queue[i]);
        if (request_queue[i] == last_replaced_data[0] || request_queue[i] == last_replaced_data[1])
        {
            printf("\nRequested Data is Recently Replaced by LRU Algorithm by Assuming the Data will not be need in future.\nBut Our Code Contradict LRU Rely Statement.\n\n");
        }
        for (j = 0; j < 4; j++)
        {
            if (request_queue[i] == recently_used_list[j])
            {
                data_in_window = true;
                printf("\nRequested Data is already present in Window. No need to Replacement\n");
                break;
            }
            else if (recently_used_list[j] == 0)
            {
                recently_used_list[j] = request_queue[i];
                data_in_window = true;
                break;
            }
        }
        if (data_in_window != true)
        {
            last_used_index = 0;
            for (k = i - 1; k >= 0; k--)
            {
                if (recently_used_list[0] == request_queue[k])
                {
                    if (++last_used_index == 4)
                    {
                        printf("\nReplaced Data From List is : %d\n", recently_used_list[0]);
                        if (toogle_value == 1)
                        {
                            last_replaced_data[toogle_value] = recently_used_list[0];
                            toogle_value = 0;
                        }
                        else
                        {
                            last_replaced_data[toogle_value] = recently_used_list[0];
                            toogle_value = 1;
                        }

                        recently_used_list[0] = request_queue[i];
                    }
                }
                else if (recently_used_list[1] == request_queue[k])
                {
                    if (++last_used_index == 4)
                    {
                        printf("\nReplaced Data From List is : %d\n", recently_used_list[1]);
                        if (toogle_value == 1)
                        {
                            last_replaced_data[toogle_value] = recently_used_list[1];
                            toogle_value = 0;
                        }
                        else
                        {
                            last_replaced_data[toogle_value] = recently_used_list[1];
                            toogle_value = 1;
                        }

                        recently_used_list[1] = request_queue[i];
                    }
                }
                else if (recently_used_list[2] == request_queue[k])
                {
                    if (++last_used_index == 4)
                    {
                        printf("\nReplaced Data From List is : %d\n", recently_used_list[2]);
                        if (toogle_value == 1)
                        {
                            last_replaced_data[toogle_value] = recently_used_list[2];
                            toogle_value = 0;
                        }
                        else
                        {
                            last_replaced_data[toogle_value] = recently_used_list[2];
                            toogle_value = 1;
                        }

                        recently_used_list[2] = request_queue[i];
                    }
                }
                else if (recently_used_list[3] == request_queue[k])
                {
                    if (++last_used_index == 4)
                    {
                        printf("\nReplaced Data From List is : %d\n", recently_used_list[3]);
                        if (toogle_value == 1)
                        {
                            last_replaced_data[toogle_value] = recently_used_list[3];
                            toogle_value = 0;
                        }
                        else
                        {
                            last_replaced_data[toogle_value] = recently_used_list[3];
                            toogle_value = 1;
                        }

                        recently_used_list[3] = request_queue[i];
                    }
                }
            }
        }
    }
    return 0;
}
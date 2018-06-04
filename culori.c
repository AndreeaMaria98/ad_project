/**
*   @file culori.c
*   @brief This method will be used to make the partition of colors for each node.
*
*   @author Stoian Andreea-Maria
*
*   @date 7/06/2018
*/
#include <stdio.h>
#include "culori.h"

int A[50][50];
int nodes;
int edges;
int color[100];
int position[100];



int colors(int current_node, int nodes, int edges)
{

    int left;
    int right;

    int iterator;
    int iterator2;

    ///A variable which, at the end of the program, returns the chosen color.
    int c = 1;

    int chosen_color;

    ///A variable which will be increased if the color is found.
    int t;
    int found;

    left = 1;
    right = 1;

    ///Colors for each node
    color[current_node] = 1;

    ///Current position
    position[1] = current_node;

    while( left <= right )
    {

        for( iterator = 1; iterator <= nodes; iterator++ )
        {

            if( A[position[left]][iterator] && !color[iterator] )
            {

                right++;
                position[right] = iterator;
                chosen_color = 0;

                for( int iterator2 = 1; iterator2 <= nodes; iterator2++ )
                    if( A[iterator][iterator2]  && color[iterator2] > chosen_color )
                    {

                        chosen_color = color[iterator2];
                    }

                t=1;

                do
                {

                    found = 0;
                    for( int iterator2 = 1; iterator2 <= nodes; iterator2++ )
                    {

                        if( A[iterator][iterator2] && color[iterator2] == t )
                            found = 1;
                    }

                    if( found )
                    {

                        t++;
                    }

                }
                while( t <= chosen_color && found );

                if( found )
                {

                    color[iterator] = chosen_color + 1;
                }
                else
                {

                    color[iterator] = t;

                }
            }
        }

        left++;
    }

    for( iterator = 1; iterator <= right; iterator++ )
    {

        if( color[position[iterator]] > c )
        {

            c = color[position[iterator]];
        }
    }
    return c;
}


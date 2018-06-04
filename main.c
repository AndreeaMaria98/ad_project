/**
*   @file main.c
*   @brief This source file will contain the main program.
*    I used adjacency matrix for simulate a graph, which will be
*   printed on lcd.
*    Nodes and edges will be read from a file, named graph.txt.
*    The partition by color will be made in the file print.txt.
*
*    @author    Stoian Andreea-Maria
*
*    @date 7/06/2018
*/
#include <stdio.h>
#include <conio.h>
#include "culori.h"

int A[50][50];
int nodes;
int edges;
int color[100];
int position[100];


int main()
{

    FILE *f=fopen("graph.txt","r");
    FILE *g=fopen("print.txt","w");

    ///This variables are used to read the nodes.
    int x;
    int y;
    ///This variable will be used to call the function.
    int c;

    int minimum_number_of_colors = 0;

    fscanf(f,"%d%d\n",&nodes,&edges);

    ///Construction of adjacency matrix
    for(int iterator = 1; iterator <= edges; iterator++ )
    {

        fscanf(f,"%d%d\n",&x,&y);
        A[x][y]=1;
        A[y][x]=1;
    }

    printf("===== Adjacency matrix =====\n");
    for(int iterator = 1; iterator <= nodes; iterator++ )
    {

        for(int iterator2 = 1; iterator2 <= nodes; iterator2++ )
        {

            printf("%d ",A[iterator][iterator2]);
        }
        printf("\n");
    }

    for(int iterator = 1; iterator <= nodes; iterator++)
    {

        if( !color[iterator] )
        {

            c = colors(iterator, nodes, edges);

            if( c > minimum_number_of_colors )
                minimum_number_of_colors = c;
        }
    }
    fprintf(g,"===== The minimum number of colors then can be used is %d =====\n",minimum_number_of_colors);
    fprintf(g,"===== Nodes colors =====\n");

    for( int iterator = 1; iterator <= nodes; iterator++ )
    {

        fprintf(g,"%d : %d\n",iterator,color[iterator]);
    }


    fprintf(g,"=====Order by color:======\n");
    for( int iterator = 1; iterator <= minimum_number_of_colors; iterator++ )
    {

        fprintf(g,"The color %d : ",iterator);
        for( int iterator2 = 1; iterator2 <= nodes; iterator2++ )
        {

            if( color[iterator2] == iterator )
            {

                fprintf(g,"%d ",iterator2);
            }
        }

        fprintf(g,"\n");
    }

    fclose(f);
    fclose(g);

    return 0;
}

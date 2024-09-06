/*
Algorithms Laboratory (CS29203)
Assignment 3: Greedy algorithm
Question-1 Count Dracula
Submitted By: Md Ashik Khan
*/

#include<stdio.h>

/* Global variable declarations */
int max_size = 999;

int notCaptured(int index,int catched[],int capture){
    for(int i=0; i<capture; i++){
        if(catched[i] == index){
            return 0;
        }
    }
    return 1;
}

int main(){

    int binary[max_size],dracula[max_size],range[max_size][2],catched[max_size];
    int d,m,n,dra_count=0,capture=0;

    printf("Question 1\n___________\n");

    printf("Enter numbers of people and dracula:\n");
    scanf("%d",&m);
    printf("Enter the binary sequence of people and dracula:\n");
    for(int i=0; i<m; i++){
        scanf("%d",&binary[i]);
    }

    printf("\n");
    printf("The binary sequence of people and dracula:\n");
    for(int i=0; i<m; i++){
        printf("%d ",binary[i]);
    }

    printf("\n");
    printf("Enter the distance d:\n");
    scanf("%d",&d);

    //Dracula indexing
    for(int i=0; i<m; i++){
        if(binary[i] == 1){
           dracula[dra_count] = i;
           dra_count++;
        }
    }
    printf("\ndracula Index:\n");
    for(int i=0; i<dra_count; i++){
        printf("%d ",dracula[i]);
    }

    //Range
    for(int i=0; i<dra_count; i++){
        range[i][0] = dracula[i]-d;
        range[i][1] = dracula[i]+d;
        if(range[i][0] < 0){
            range[i][0] = 0;
        }
        if(range[i][1] >= m){
            range[i][1] = m-1;
        }
    }
    printf("\ndracula Range:\n");
    for(int i=0; i<dra_count; i++){
        printf("[%d , %d]",range[i][0],range[i][1]);
    }

    //Capture
    for(int i=0; i<dra_count; i++){
        int start = range[i][0];
        int end = range[i][1];
        for(int j=start; j<=end; j++){
            if(binary[j] == 0 && notCaptured(j,catched,capture) == 1){
                catched[capture] = j;
                capture++;
                break;
            }
        }
        
    }

    printf("\nTotal number of captures = %d\n",capture);
    // for(int i=0; i<capture; i++){
    //     printf("%d ",catched[i]);
    // }
    
    return 0;
}
//
//  main.c
//  sort algorithms
//
//  Created by Simone Cimolato on 04/06/18.
//  Copyright © 2018 Simone Cimolato. All rights reserved.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define dim 15

void delay(int number_of_seconds);
void arrPrint(void);
void swap(int j, int w);
void selection(void);
void insertion(void);
void bubble(void);
void solvedPrint(void);
void quicksort(int number[dim],int first,int last);

int mixed[dim];
int toBeSolved[dim];
int i,j,k,m,temp;
int flag,stop;
int count=0;

int main(){
    srand(time(NULL));
    
    for(i=0;i<dim;i++){
        mixed[i] = (rand() % dim*2) +1;
    }
    
    for(i=0;i<dim;i++){
        toBeSolved[i]=mixed[i];
    }
    
    //selection sort
    selection();
    
    printf("\n");
    
    //printing the ordered array
    solvedPrint();
    printf("\nThis was selection sort.\n");
    
    printf("\n\nPress any key to start insertion sort.\n");
    getchar();
    
    for(i=0;i<dim;i++){
        toBeSolved[i]=mixed[i];
    }
    
    count=0;
    
    //insertion sort
    insertion();
    
    printf("\n");
    
    solvedPrint();
    
    printf("\n\ninsertion sort was %.3f %% faster than selection sort this time.\n", ((float)count*100)/(((dim-1)*(dim-2))/2));
    
    printf("\n\nPress any key to start bubble sort.\n");
    getchar();
    
    for(i=0;i<dim;i++){
        toBeSolved[i]=mixed[i];
    }
    
    count = 0;
    flag = 1;
    stop = dim -1;
    
    //bubble sort
    bubble();
    
    printf("\n");
    
    solvedPrint();
    
    printf("\n");
    printf("\n");
    
    //printing the ordered array
    solvedPrint();
    printf("\nThis was bubble sort.\n");
    
    printf("\n\nPress any key to start quick sort.\n");
    getchar();
    
    for(i=0;i<dim;i++){
        toBeSolved[i]=mixed[i];
    }
    
    count=0;
    
    quicksort(toBeSolved,0,dim-1);
    printf("\n");
    
    solvedPrint();
    
    printf("\n");
    printf("\n");
    
    printf("\nThis was quick sort.\n");
    getchar();
    
    return 0;
}


void delay(int number_of_milliseconds)
{
    // Stroing start time
    clock_t start_time = clock();
    
    // looping till required time is not acheived
    while (clock() < start_time + number_of_milliseconds);
}

void arrPrint(){
    for (k=0;k<dim-1;k++){
        for(m=0;m<toBeSolved[k];m++){
            printf("=");
        }
        printf("\n");
    }
    printf("\n");
    printf("Steps: %d", count);
    delay(500/dim);
}

void swap(int w, int j){
    temp=toBeSolved[w];
    toBeSolved[w]=toBeSolved[j];
    toBeSolved[j]=temp;
}

void selection(){
    for (i=0;i<dim-2;i++){
        for(j=i+1;j<dim-1;j++){
            system("clear");
            if (toBeSolved[j]<toBeSolved[i]){
                swap(j,i);
            }
            count++;
            arrPrint();  //printing
        }
    }
}

void insertion(){
    for(i=1;i<dim-1;i++){
        j=i-1;
        while(j >= 0 && toBeSolved[j]>toBeSolved[j+1]){
            system("clear");
            swap(j,j+1);
            
            j-=1;
            count++;
            
            //printing
            arrPrint();
        }
    }
}

void bubble(){
    while(flag == 1){
        flag = 0;
        for(i = 0; i <= stop; i++){
            system("clear");
            if(toBeSolved[i+1]<toBeSolved[i]){
                swap(i,i+1);
                flag = 1;
            }
            
            count++;
            //printing
            arrPrint();
        }
        stop-=1;
    }
}


void solvedPrint(){
    printf("Initial mixed array: ");
    for (i=0;i<dim-1;i++){
        printf("%d,", mixed[i]);
    }
    
    printf("\nOrdered array: ");
    for (i=0;i<dim-1;i++){
        printf("%d,", toBeSolved[i]);
    }
}

void quicksort(int number[dim],int first,int last){
    int i, j, pivot, temp;
    
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        system("clear");
        
        count++;
        while(i<j){
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        arrPrint();
        
        
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
        
    }
}

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct term{
    int coeff;
    int expo;
    struct term *next;
}term;

term *head=NULL;

term *createNode(int expo){
    term *newNode=(term *) malloc(sizeof (term));
    printf("enter the coeff for the ter %d exponent",expo);
    scanf("%d",&newNode->coeff);
    newNode->expo=expo;
    newNode->next=NULL;
    return newNode;
}

void createPolynom(int expo){
    for(int i=0;i<=expo;i++){
        term *ptr=head;
        term *temp= createNode(expo-i);
        if(head==NULL){
            head=temp;
        } else{
            while (ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=temp;

        }
    }
}

void displayPolynom(term *head){
    term *temp=head;
    while (temp!=NULL){
        if(temp->next!=NULL){
            printf("%dx^%d +",temp->coeff,temp->expo);
            temp=temp->next;
        } else{
            printf("%dx^%d",temp->coeff,temp->expo);
            temp=temp->next;
        }}

}



int main(){
    int res;
    int deg,x;
    printf("enter the degree of polynom");
    scanf("%d",&deg);
    createPolynom(deg);
    if(deg<=0){
        printf("the polynom is invalid");
        exit(0);
    } else{
        printf("the polytnomial is");
        displayPolynom(head);

    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50]; // array to store names
    struct student *next;
} student;

student *head;      // head pointer
student *searchptr; // used for searching student

int count;      // maintains the node count of the linked list
int srollno;    // it is the roll no entered by the user
char sname[50]; // it is the name entered by the user

void LLDemoOptions()
{
    printf("\n*** Singly Linked List Program. Having ONLY 'Insert' & 'Search' & 'Delete' *** \n");
    printf("0.Menu\n");
    printf("1.Search RollNo \n");
    printf("2.Insert At Any Position \n");
    printf("3.Display Students \n");
    printf("4.Delete From Any Position\n");
    printf("5.Quit \n");
}

student *searchStudent(student *head, int srollno) // pointer fun to search for a student
{
    student *pointer = head; // this pointer is to traverse thru the entiorwe
    if (head == NULL)        // head will be empty
        return NULL;         // returning value to main
    else
    {
        while (pointer != NULL) // this means that the pointer can keep traversing through the linked list till it fins the last adress of null

        {
            if (pointer->rollno = srollno) // we're telling the traversing pointer to check if the roll no(data in node) of the node is the same as the data searched srollno
                return pointer;

            else
                pointer = pointer->next; // in this were telling the pointer to traverse to the next node as it didnt find the roll for the searched srollno in the prvs node
        }
        return NULL;
    }
}

void printstudentdetails(student *head) // this is the function to display the details of the linked list
{
    if (head == NULL) // technically saying that if the linked list is empty
    {
        printf("Linked list is empty");
    }
    else
    {
        student *pointer = head;
        printf("\nNumber of students in the linked list is %d \n", count);
        printf("head address is %p", head);
        while (pointer != NULL)
        {
            printf("\nStudent roll no is %d", pointer->rollno); // to print student roll no
            printf("\nStudent name is %s", pointer->name);
            pointer = pointer->next; // pointer is traversing to next node for checking in this line of code
            printf("\nNext student node: %p", pointer);
        }
    }
}
student *createstudent(student *next)
{                                                             // tells what comes after what node
    student *newstudent = (student *)malloc(sizeof(student)); // allocating memory in storage for new student node that is being created
    strcpy(newstudent->name, sname);                          // transfering the name enterd in sname to name which is in the node
    newstudent->rollno = srollno;                             // transferring the srollno entered to the rollno node
    newstudent->next = next;                                  // we're assigning a next link to the node
    count++;                                                  // this increases the count because we added a new node
    return newstudent;
}
student *insertany(student *head)
{                     // passing head pointer
    int position;     // this is to assign wether its before or after a node
    int rollposition; // assigning which roll no the new node has to come before or after
    if (head == NULL) // it means the linked list is empty
    {
        printf("\n first node created\n");
        student *newstudent = createstudent(
            head);         // were assigning the value head top the node has been created so basically linking head with the first element
        head = newstudent; // assigning the value of head
        return head;
    }
    else
    {
        student *postptr = NULL; // postptr is to hold address for roll posiyion
        printf("Where do you want to insert: \n0)for before \n1)for after");
        scanf("%d", &position);
        if (position == 0)
        {
            printf("Enter the roll no you want to enter before");
            scanf("%d", &rollposition);
        }
        else if (position == 1)
        {
            printf("Enter the roll no you want to enter after");
            scanf("%d", &rollposition);
        }
        else
        {
            printf("Wrong value entered"); // if 1 or 0 wasnt enetred as input this will print
            return head;
        }
        postptr = searchStudent(head, rollposition); // search roll positon in the linked list that is pointed by head
        printf("\n Posptr pointer address->%d and Rollposition is %d", postptr, rollposition);

        if (postptr != NULL)
        {
            if (position == 1 &&
                postptr->next == NULL)
            { // this means you want to insert something after the last node
                printf("insert any after end node");
                student *newStudent = createstudent(
                    NULL);                  // were assigning the node to be inseted to have null as next beacuase it will be the last node
                postptr->next = newStudent; // postptr is currently at the last node and the new node is not yet inserted. this line conncts the last node to the new node
            }
            else if (position == 1 && postptr->next != NULL)
            {
                printf("instert after middle node");
                student *newStudent = createstudent(
                    postptr->next); // in this line of code the new node store the address of the node that  has to be after it
                postptr->next = newStudent;
            }
            else if (position == 0 && postptr == head)
            {
                printf("insert before head node");
                student *newStudent = createstudent(
                    postptr);      // in this line the new node is being pointed to the address of the node that should be after it
                head = newStudent; // the head is pointed at the new node
            }
            else
            {
                printf("\n In Insert Any : Insert Before a Middle Node ");
                student *beforeStudent = head; // new pointer is created to traverse to the node which is just before the node in the middle
                while (beforeStudent->next !=
                       postptr) // this loop will make the beforestudent pointer keep traversing tillit reache the node just before the nescessary node
                {
                    beforeStudent = beforeStudent->next; // this is the command to go to the next node
                    printf("\nbeforeStudent address->%d and posptr->%d", beforeStudent, postptr);
                }
                student *newStudent = createstudent(
                    postptr); // once the addrees of the beforestudent node is known the you can use the normal method to add it
                beforeStudent->next = newStudent;
                printf("\nbeforeStudent address->%d and newStudent->%d", beforeStudent, newStudent);
            }
        }
        else
        {
            printf("\nThe roll no. that you have entered doesn't exist in the linked list.");
        }
        return head;
    }
}

student *deleteany(student *head, int srollno)
{
    student *deletptr = searchStudent(head, srollno); // deletptr is the pointer to the node that has to be deleted
    if (deletptr == NULL)                             // this means that the deletptr does not exist and roll no that it is searching does not exist
    {
        printf("the roll no you eneted does not exist");
        return head;
    }
    else
    {
        count--; // reducing the count of the linked list because node is going to be deleted
        if (deletptr == head)
        {
            printf("You are deleting the head node from the linked list");
            head = head->next;
        }
        else if (deletptr->next == NULL)
        {
            printf("you are deleting the tail node form the linked list");
            student *pointer = head;
            while (pointer->next != deletptr)
            {
                pointer = pointer->next;
            }
            pointer->next = NULL;
        }
        else
        {
            printf("you are deleting a node from the middle of the lionked list");
            student *pointer = head;
            while (pointer->next != deletptr)
            {
                pointer = pointer->next;
            }
            pointer->next = deletptr->next;
        }
        free(deletptr);
        return head;
    }
}
int main()
{
    head = NULL;
    searchptr = NULL;

    int choice = 0;
    LLDemoOptions();

    while (1)
    {
        printf("\nPlease enter a choice-");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            LLDemoOptions();
            break;
        case 1:
            printf("\nPlease enter a number to search:");
            scanf("%d", &srollno);
            searchptr = searchStudent(head, srollno);
            if (searchptr != NULL)
            {
                printf("\nStudent with RollNo %d found. Name is %s", searchptr->rollno, searchptr->name);
            }
            else
            {
                printf("\nStudent with RollNo %d not found.", srollno);
            }
            break;

        case 2:
            printf("\nEnter the Student RollNo ");
            scanf("%d", &srollno);
            printf("\nEnter the Student Name ");
            scanf("%s", sname);
            head = insertany(head);
            break;

        case 3:
            printstudentdetails(head);
            break;

        case 4:
            printf("\nEnter the Student RollNo to delete");
            scanf("%d", &srollno);
            head = deleteany(head, srollno);
            break;
        case 5:
            exit(0);
        default:
            printf("\nPlease Enter a valid choice\n");
        }
    }
}

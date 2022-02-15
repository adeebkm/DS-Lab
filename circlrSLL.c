#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    int rollno;
    char name[50];
    struct student *next;
} student;

student *head;
student *searchptr;

int count;
int srollno;
char sname[50];

void LLDemoOptions()
{
    printf("0.Menu\n");
    printf("1.Search\n");
    printf("2. Insert\n");
    printf("3. Display\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
}

student *searchStudent(student *head, int srollno)
{
    student *pointer = head;
    if (head == NULL)
        return NULL;

    else
    {
        do
        {
            if (pointer->rollno == srollno)
                return pointer;
            else
                pointer = pointer->next;
        } while (pointer != head);
        return NULL;
    }
}

void printstudentdetails(student *head)
{
    if (head == NULL)
    {
        printf("the linked listy is empty");
    }
    else
    {
        student *pointer = head;
        printf("\nnumber of students are %d\n", count);
        printf("head address is %p", head);
        do
        {
            printf("student roll no is %d", pointer->rollno);
            printf("student name is %s", pointer->name);
            pointer = pointer->next;
            printf("next student node is %p", pointer);
        } while (pointer != head);
    }
}

student *createStudent(student *next)
{
    student *newstudent = (student *)malloc(sizeof(student));
    strcpy(newstudent->name, sname);
    newstudent->rollno = srollno;
    newstudent->next = next;
    count++;
    return newstudent;
}

student *insertany(student *head)
{
    int position;
    int rollposition;
    if (head == NULL)
    {
        printf("first node has been created");
        student *newstudent = createStudent(head);
        head = newstudent;
        return head;
    }
    else
    {
        student *posptr = NULL;
        printf("\n0)insert before \n1) insert after");
        scanf("%d", &position);
        if (position == 0)
        {
            printf("enter the roll no you want to insert before");
            scanf("%d", &rollposition);
        }
        else if (position == 1)
        {
            printf("enter roll no to insert after");
            scanf("%d", &rollposition);
        }
        else
        {
            printf("wrong value entered");
            return head;
        }
        posptr = searchStudent(head, rollposition);
        if (posptr != NULL)
        {
            if (position == 1 && posptr->next == NULL)
            {
                printf("insert after last node");
                student *newstudent = createStudent(head);
                posptr->next = newstudent;
            }
            else if (position == 1 && posptr->next != NULL)
            {
                printf("insert after middle node");
                student *newstudent = createStudent(posptr->next);
                posptr->next = newstudent;
            }
            else if (position == 0 && posptr == head)
            {

                printf("insert before head node");
                student *newstudent = createStudent(posptr);
                student *laststudent = head;
                while (laststudent->next != head)
                {
                    laststudent = laststudent->next;
                    printf("last student address is %p and posptr is %p", laststudent, posptr);
                }
                head = newstudent;
                laststudent->next = head;
            }
            else
            {
                printf("before middle node");
                student *beforestudent = head;
                while (beforestudent->next != posptr)
                {
                    beforestudent = beforestudent->next;
                }
                student *newstudent = createStudent(posptr);
                beforestudent->next = newstudent;
            }
        }
        else
        {
            printf("the roll no you entered doesnt exist in linked lsit");
        }
        return head;
    }
}

student *deleteany(student *head, int srollno)
{
    student *deletptr = searchStudent(head, srollno);
    if (deletptr == NULL)
    {
        printf("the roll no enetred does not exist");
        return head;
    }

    else
    {
        count--;
        if (count <= 0)
        {
            head = NULL;
        }
        if (deletptr == head)
        {
            printf("you are deleting the head node from the libnked list");
            student *laststudent = head;
            while (laststudent->next != head)
            {
                laststudent = laststudent->next;
            }
            head = head->next;
            laststudent->next = head;
        }
        else if (deletptr->next == head)
        {
            printf("you are deleting tail node from linked list");
            student *pointer = head;
            while (pointer->next != deletptr)
            {
                pointer = pointer->next;
            }
            pointer->next = head;
        }
        else
        {
            printf("you are deleting middle node from linked list");
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
        printf("\nPlease enter a choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            LLDemoOptions();
            break;
        case 1:
            printf("please enter number to search");
            scanf("%d", &srollno);
            searchptr = searchStudent(head, srollno);
            if (searchptr != NULL)
            {
                printf("student with roll no found is %d abnda name is %s\n", searchptr->rollno, searchptr->name);
            }
            else
                printf("student roll no does not exist");
            break;

        case 2:
            printf("please enter roll no");
            scanf("%d", &srollno);
            printf("enter student nsme");
            scanf("%s", sname);
            head = insertany(head);
            break;

        case 3:
            printstudentdetails(head);
            break;

        case 4:
            printf("enter node to delete");
            scanf("%d", &srollno);
            head = deleteany(head, srollno);
            break;

        case 5:
            exit(0);

        default:
            printf("\nplease enter valid choice");
        }
    }
}

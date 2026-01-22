#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char add[100];
    char subname[5][50];
    int marks[5];
};

void passFail(struct Student stud[], int n) {
    int i, j, ct;
    char name[50];
    printf("The following students have failed in minimum three subjects:\n");
    for (i=0; i<n; i++) {
        ct=0;
        strcpy(name, stud[i].name);
        for (j=0; j<5; j++) if (stud[i].marks[j]<40) ct++;
        if (ct>=3) printf("%s", name);
    }
    printf("The following students have passed in minimum three subjects:\n");
    for (i=0; i<n; i++) {
        ct=0;
        strcpy(name, stud[i].name);
        for (j=0; j<5; j++) if (stud[i].marks[j]>=40) ct++;
        if (ct>=3) printf("%s", name);
    }
}

void maxMath(struct Student stud[], int n) {
    int m, i, j, idx=0, max=-1, maxidx=0;
    for (i=0; i<n; i++) {
        for (j=0; j<5; j++) if (!strcmp(stud[i].subname[j], "Mathematics")) idx = j;
        if (stud[i].marks[idx]>max) {
            maxidx = i;
            max = stud[i].marks[idx];
        }
    }
    printf("Name of Student: %s", stud[maxidx].name);
    printf("Address of Student: %s", stud[maxidx].add);
    for (j=0; j<5; j++) printf("Marks in %s: %d\n", stud[maxidx].subname[j], stud[maxidx].marks[j]);
    printf("\n");
}

void minPhy(struct Student stud[], int n) {
    int m, i, j, idx=0, min=101, minidx=0;
    for (i=0; i<n; i++) {
        for (j=0; j<5; j++) if (!strcmp(stud[i].subname[j], "Physics")) idx = j;
        if (stud[i].marks[idx]<min) {
            minidx = i;
            min = stud[i].marks[idx];
        }
    }
    printf("Name of Student: %s", stud[minidx].name);
    printf("Address of Student: %s", stud[minidx].add);
    for (j=0; j<5; j++) printf("Marks in %s: %d\n", stud[minidx].subname[j], stud[minidx].marks[j]);
    printf("\n");
}

void maxAvg(struct Student stud[], int n) {
    int i, sum, j, max=-1, maxidx=0;
    double avg;
    for (i=0; i<n; i++) {
        avg=0;
        sum=0;
        for (j=0; j<5; j++) sum+=stud[i].marks[j];
        avg = ((double) sum)/5;
        if (avg>max) {
            maxidx = i;
            max = avg;
        }
    }
    printf("Name of Student: %s", stud[maxidx].name);
    printf("Address of Student: %s", stud[maxidx].add);
    for (j=0; j<5; j++) printf("Marks in %s: %d\n", stud[maxidx].subname[j], stud[maxidx].marks[j]);
    printf("\n");
}

void printRecord(struct Student stud[], int n) {
    int i, j, sum;
    for (i=0; i<n; i++) {
        printf("Name of Student: %s", stud[i].name);
        printf("Address of Student: %s", stud[i].add);
        sum=0;
        for (j=0; j<5; j++) sum+=stud[i].marks[j];
        printf("Total marks is %d\n", sum);
    }
}


int main()
{
    int n, i, j, m;
    char s[100];
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct Student stud[n];
    getchar();
    for (i=0; i<n; i++) {
        printf("Enter name of Student %d: ", i+1);
        fgets(stud[i].name, 50, stdin);
    
        printf("Enter address of Student %d: ", i+1);
        fgets(stud[i].add, 100, stdin);
        
        for (j=0; j<5; j++) {
            
            printf("Enter name of subject %d: ", j+1);
            fgets(stud[i].subname[j], 50, stdin);
            
            printf("Enter marks in subject %d: ", j+1);
            scanf("%d", &stud[i].marks[j]);
        
            getchar();
            
        }
        
        
    }
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Find students who have passed/failed in minimum three subjects\n");
        printf("2. Show the record of the student who has got maximum marks in Mathematics\n");
        printf("3. Show the record of the student who has got minimum marks in Physics\n");
        printf("4. Show the record of the student whose average marks is maximum\n");
        printf("5. Print the record of students with name and total\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                passFail(stud, n);
                break;
            case 2:
                maxMath(stud, n);
                break;
            case 3:
                minPhy(stud, n);
                break;
            case 4:
                maxAvg(stud, n);
                break;
            case 5:
                printRecord(stud, n);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);


    return 0;
}


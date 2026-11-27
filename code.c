#include <stdio.h>

#define MAX_STUDENTS 100
#define SUBJECTS 5

struct Student
{
    int rollNo;
    char name[50];
    float marks[SUBJECTS];
    float total, percentage;
    char grade;
};

struct Student students[MAX_STUDENTS];
int count = 0;

void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void calculateResult(int index);
void readMarks(int index);
void analyzeClass();
void sortStudents();
void saveToFile();
void loadFromFile();

int main()
{
    int choice;
    loadFromFile();
    do
    {
        printf("\n     STUDENT RECORD AND GRADE ANALYZER    \n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Analyze Class Performance\n");
        printf("7. Sort Students by Percentage\n");
        printf("8. Save Records to File\n");
        printf("9. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: analyzeClass(); break;
            case 7: sortStudents(); break;
            case 8: saveToFile(); break;
            case 9:
                saveToFile();
                printf("Records saved. Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter 1 to 9.\n");
        }
    } while(choice != 9);
    return 0;
}

void calculateResult(int index)
{
    int i;
    float total = 0;
    for(i = 0; i < SUBJECTS; i++)
        total = total + students[index].marks[i];
    students[index].total = total;
    students[index].percentage = total / SUBJECTS;
    if(students[index].percentage >= 90)
        students[index].grade = 'A';
    else if(students[index].percentage >= 80)
        students[index].grade = 'B';
    else if(students[index].percentage >= 70)
        students[index].grade = 'C';
    else if(students[index].percentage >= 60)
        students[index].grade = 'D';
    else if(students[index].percentage >= 30)
        students[index].grade = 'E';
    else
        students[index].grade = 'F';
}

void readMarks(int index)
{
    int i;
    for(i = 0; i < SUBJECTS; i++)
    {
        do
        {
            printf("Enter marks for Subject %d (0-100): ", i + 1);
            scanf("%f", &students[index].marks[i]);
            if(students[index].marks[i] < 0 || students[index].marks[i] > 100)
                printf("Invalid marks! Enter again.\n");
        } while(students[index].marks[i] < 0 || students[index].marks[i] > 100);
    }
}

void addStudent()
{
    int i, roll;
    if(count >= MAX_STUDENTS)
    {
        printf("Student limit reached!\n");
        return;
    }
    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);
    for(i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            printf("Roll Number already exists!\n");
            return;
        }
    }
    students[count].rollNo = roll;
    printf("Enter Name: ");
    getchar();
    fgets(students[count].name, 50, stdin);
    readMarks(count);
    calculateResult(count);
    count++;
    printf("Student added successfully!\n");
}

void displayStudents()
{
    int i;
    if(count == 0)
    {
        printf("No student records found!\n");
        return;
    }
    for(i = 0; i < count; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", students[i].rollNo);
        printf("Name        : %s", students[i].name);
        printf("Total       : %.2f\n", students[i].total);
        printf("Percentage  : %.2f%%\n", students[i].percentage);
        printf("Grade       : %c\n", students[i].grade);
    }
}

void searchStudent()
{
    int roll, i, j, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);
    for(i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].rollNo);
            printf("Name        : %s", students[i].name);
            printf("Marks       : ");
            for(j = 0; j < SUBJECTS; j++)
                printf("%.2f ", students[i].marks[j]);
            printf("\nTotal       : %.2f\n", students[i].total);
            printf("Percentage  : %.2f%%\n", students[i].percentage);
            printf("Grade       : %c\n", students[i].grade);
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Student not found!\n");
}

void updateStudent()
{
    int roll, i, found = 0;
    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);
    for(i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            printf("Student Found: %s", students[i].name);
            printf("Enter the new marks.\n");
            readMarks(i);
            calculateResult(i);
            printf("Student record updated successfully!\n");
            found = 1;
            break;
        }
    }
    if(found == 0)
        printf("Student not found!\n");
}

void deleteStudent()
{
    int roll, i, j, found = 0;
    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);
    for(i = 0; i < count; i++)
    {
        if(students[i].rollNo == roll)
        {
            for(j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            found = 1;
            printf("Student record deleted successfully!\n");
            break;
        }
    }
    if(found == 0)
        printf("Student not found!\n");
}

void analyzeClass()
{
    int i, j, pass = 0, fail = 0;
    int highest = 0, lowest = 0;
    float sum = 0, subjectTotal;
    if(count == 0)
    {
        printf("No student records found!\n");
        return;
    }
    for(i = 0; i < count; i++)
    {
        sum = sum + students[i].percentage;
        if(students[i].percentage > students[highest].percentage)
            highest = i;
        if(students[i].percentage < students[lowest].percentage)
            lowest = i;
        if(students[i].grade == 'F')
            fail++;
        else
            pass++;
    }
    printf("\n        CLASS PERFORMANCE      \n");
    printf("Total Students     : %d\n", count);
    printf("Class Average      : %.2f%%\n", sum / count);
    printf("Passed Students    : %d\n", pass);
    printf("Failed Students    : %d\n", fail);
    printf("Pass Percentage    : %.2f%%\n", (pass * 100.0) / count);
    printf("\nTopper             : %s", students[highest].name);
    printf("Top Percentage     : %.2f%%\n", students[highest].percentage);
    printf("Lowest Scorer      : %s", students[lowest].name);
    printf("Lowest Percentage  : %.2f%%\n", students[lowest].percentage);
    printf("\nSubject-wise Average:\n");
    for(j = 0; j < SUBJECTS; j++)
    {
        subjectTotal = 0;
        for(i = 0; i < count; i++)
            subjectTotal = subjectTotal + students[i].marks[j];
        printf("Subject %d : %.2f\n", j + 1, subjectTotal / count);
    }
}

void saveToFile()
{
    FILE *fp;
    int i, j;
    fp = fopen("students.txt", "w");
    if(fp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    for(i = 0; i < count; i++)
    {
        fprintf(fp, "%d\n", students[i].rollNo);
        fprintf(fp, "%s", students[i].name);
        for(j = 0; j < SUBJECTS; j++)
            fprintf(fp, "%.2f ", students[i].marks[j]);
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Records saved successfully!\n");
}

void loadFromFile()
{
    FILE *fp;
    int j;
    fp = fopen("students.txt", "r");
    if(fp == NULL)
        return;
    while(count < MAX_STUDENTS && fscanf(fp, "%d\n", &students[count].rollNo) == 1)
    {
        fgets(students[count].name, 50, fp);
        for(j = 0; j < SUBJECTS; j++)
            fscanf(fp, "%f", &students[count].marks[j]);
        fscanf(fp, "\n");
        calculateResult(count);
        count++;
    }
    fclose(fp);
}

void sortStudents()
{
    int i, j;
    struct Student temp;
    if(count == 0)
    {
        printf("No student records found!\n");
        return;
    }
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(students[j].percentage < students[j + 1].percentage)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by percentage successfully!\n");
    displayStudents();
}
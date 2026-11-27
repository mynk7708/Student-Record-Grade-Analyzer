# Student Record and Grade Analyzer

A menu-driven C program developed as part of the **Programming in C Mini Hackathon**. The program manages student academic records, calculates grades, analyzes class performance, and stores records using file handling.

## Team Members

| Name | SAP ID |
|---|---|
| Mayank Mishra | 590038054 |
| Kartik Jyala | 590037801 |
| Chaitanya Khandelwal | 590040424 |

## Problem Statement

Managing student marks manually requires repeated calculation of totals, percentages, grades, and class statistics. It can also become difficult to search, update, and maintain multiple student records.

The **Student Record and Grade Analyzer** provides a simple menu-driven C program to manage student records and automatically perform these calculations.

## Objectives

- Store and manage student academic records.
- Calculate total marks, percentage, and grade automatically.
- Search, update, and delete students using roll numbers.
- Analyze overall class performance.
- Sort students according to percentage.
- Save records in a text file so that they can be accessed again when the program is restarted.

## Features

The program provides the following options:

1. Add Student
2. Display All Students
3. Search Student
4. Update Student Record
5. Delete Student Record
6. Analyze Class Performance
7. Sort Students by Percentage
8. Save Records to File
9. Exit

Additional functionality includes:

- Duplicate roll number detection
- Marks validation from 0 to 100
- Support for full student names
- Automatic total and percentage calculation
- Automatic grade calculation
- Class average calculation
- Pass and fail count
- Pass percentage
- Identification of topper
- Identification of lowest scorer
- Subject-wise averages
- Bubble Sort based on percentage
- Automatic loading of previously saved records

## C Concepts Used

The project uses the following C programming concepts:

- Variables and data types
- Operators
- Conditional statements (`if`, `else if`, `else`)
- `switch-case`
- `for` loops
- `do-while` loops
- Arrays
- Strings
- Structures
- Functions
- Function parameters
- Linear Search
- Bubble Sort
- Nested loops
- File handling
- File pointers
- Preprocessor directives and macros

## Student Structure

Each student's information is stored using a structure containing:

- Roll Number
- Name
- Marks of 5 subjects
- Total Marks
- Percentage
- Grade

An array of structures is used to store records of up to **100 students**.

## Grading System

| Percentage | Grade |
|---|---|
| 90–100 | A |
| 80–89 | B |
| 70–79 | C |
| 60–69 | D |
| 30–59 | E |
| Below 30 | F |

A student is considered **failed only when the percentage is below 30%**.

## Algorithm

1. Start the program.
2. Load previously saved student records from `students.txt`.
3. Display the main menu.
4. Accept the user's choice.
5. Perform the selected operation:
   - Add a student and validate the entered marks.
   - Display existing student records.
   - Search for a student using roll number.
   - Update marks and recalculate the result.
   - Delete a student record.
   - Analyze class performance.
   - Sort students by percentage.
   - Save records to the file.
6. Return to the main menu after completing the operation.
7. When Exit is selected, save all records to the file.
8. End the program.

## Pseudocode

```text
START

Load student records from file

REPEAT

    Display menu
    Read user choice

    SWITCH choice

        1:
            Add student
            Check duplicate roll number
            Read and validate marks
            Calculate total, percentage and grade

        2:
            Display all students

        3:
            Search student using roll number

        4:
            Search student
            Enter new marks
            Recalculate result

        5:
            Search student
            Delete record by shifting array elements

        6:
            Calculate class average
            Find topper and lowest scorer
            Calculate pass/fail statistics
            Calculate subject-wise averages

        7:
            Sort students by percentage using Bubble Sort

        8:
            Save records to text file

        9:
            Save records
            Exit

        DEFAULT:
            Display invalid choice message

UNTIL choice = 9

STOP
```

## Searching

The program uses **Linear Search** to find students using their roll number.

Each student record is checked one by one until the required roll number is found. The same approach is used while searching, updating, deleting, and checking duplicate roll numbers.

## Sorting

The program uses **Bubble Sort** to arrange students from highest to lowest percentage.

Neighbouring student records are compared, and their complete structures are swapped when they are in the wrong order.

## File Handling

Student records are stored in:

```text
students.txt
```

The program uses basic text-file operations:

- `fopen()` – opens the file
- `fprintf()` – writes records to the file
- `fscanf()` – reads formatted data from the file
- `fgets()` – reads student names
- `fclose()` – closes the file

The file stores the roll number, name, and marks of each student. Total, percentage, and grade are recalculated when records are loaded.

## Compilation and Execution

Using GCC:

```bash
gcc code.c -o code
```

Run on Windows:

```bash
.\code
```

The program can also be compiled and executed using the **Run button in VS Code** when a C compiler is configured.

## Sample Test Cases

| Test Case | Input | Expected Result |
|---|---|---|
| Normal marks | 80, 75, 90, 85, 70 | Total = 400, Percentage = 80%, Grade B |
| Minimum boundary | 0 | Mark accepted |
| Maximum boundary | 100 | Mark accepted |
| Passing boundary | All subjects = 30 | Percentage = 30%, Grade E, Pass |
| Failure boundary | All subjects = 29 | Percentage = 29%, Grade F, Fail |
| Invalid marks | -5 | Invalid marks, asked to enter again |
| Invalid marks | 110 | Invalid marks, asked to enter again |
| Duplicate roll number | Existing roll number | Record is not added |
| Unknown roll number | Search for 999 | Student not found |
| File persistence | Save, exit and restart | Saved records are loaded again |

## Project Files

```text
Student-Record-Grade-Analyzer/
│
├── code.c
├── README.md
├── students.txt
└── Student_Record_Grade_Analyzer.pptx
```

## Conclusion

The **Student Record and Grade Analyzer** demonstrates how fundamental C programming concepts can be combined to create a functional application. It manages student records, performs automatic result calculations, analyzes class performance, sorts records, and preserves data using file handling.

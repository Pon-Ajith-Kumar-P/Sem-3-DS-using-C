#include <stdio.h>

int main() {
    int marks[20][5];
    for (int i = 0; i < 20; i++) {
        printf("\nStudent %d Marks:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Enter Mark for Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    printf("\n(a) Average Marks Obtained in Each Subject:\n");
    float sum_sub[5] = {0};
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 20; i++) {
            sum_sub[j] += marks[i][j];
        }
        printf("Average marks in Subject %d = %.2f\n", j + 1, sum_sub[j] / 20);
    }

    printf("\n(b) Average Marks Obtained by Every Student:\n");
    float stud_avg[20];
    for (int i = 0; i < 20; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += marks[i][j];
        }
        stud_avg[i] = total / 5.0;
        printf("Average marks obtained by Student %d = %.2f\n", i + 1, stud_avg[i]);
    }

    printf("\n(c) Number of Students Who Scored Below 50 in Their Average:\n");
    int count = 0;
    for (int i = 0; i < 20; i++) {
        if (stud_avg[i] < 50) {
            count++;
        }
    }
    printf("Total number of students who scored below 50 in their average = %d\n", count);

    printf("\n(d) Scores Obtained by Every Student:\n");
    for (int i = 0; i < 20; i++) {
        printf("Student %d Marks: ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d ", marks[i][j]);
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MONTHS 12

 
void sales_from_file(char *filename, double *sales) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file"); 
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < MONTHS; ++i) { 
        if (fscanf(file, "%lf", &sales[i]) != 1) {
            fprintf(stderr, "Error reading from the file\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

//Function to display the monthly sales
void sales_report_list(char **months, double *sales) {
    printf("Monthly sales report for 2022:\n");
    printf("%s    %s\n", "Month", "Sales");

    for (int i = 0; i < MONTHS; ++i) {
        printf("%s    $%.2f\n", months[i], sales[i]);
    }
}

//Displays a summary of sales including Maximum and Minimum
void sales_summary_list(char **months, double *sales) {
    double min_sale = sales[0];
    double max_sale = sales[0];
    double avg_sale = 0;

    for (int i = 0; i < MONTHS; ++i) {
        //Update the minimum and maximum sales
        if (sales[i] < min_sale) {
            min_sale = sales[i];
        }
        if (sales[i] > max_sale) {
            max_sale = sales[i];
        }
        avg_sale += sales[i];
    }

    avg_sale /= MONTHS;

    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sale, months[0]);
    printf("Maximum sales: $%.2f (%s)\n", max_sale, months[MONTHS - 1]);
    printf("Average sales: $%.2f\n", avg_sale);
}

void six_month_moving_avg(char **months, double *sales) {
    printf("\nSix-Month Moving Average Report:\n");

    for (int i = 0; i <= MONTHS - 6; ++i) {
        double average = 0.0;
        for (int j = 0; j < 6; ++j) {
            average += sales[i + j];
        }
        average /= 6;

        printf("%s - %s   $%.2f\n", months[i], months[i + 5], average);
    }
}

void HightoLow_sales_report(char **months, double *sales) {
    printf("\nSales Report (Highest to Lowest):\n");

    // Make an array
    int index[MONTHS];
    for (int i = 0; i < MONTHS; ++i) {
        index[i] = i;
    }
    for (int i = 0; i < MONTHS - 1; ++i) {
        for (int j = i + 1; j < MONTHS; ++j) {
            if (sales[index[i]] < sales[index[j]]) {
                int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }

    printf("%s           %s\n", "Month", "Sales"); //Space was added for clarity when the table is displayed
    for (int i = 0; i < MONTHS; ++i) {
        printf("%s      $%.2f\n", months[index[i]], sales[index[i]]);
    }
}

int main() {
    //declaring the file name
    char *filename = "sales.txt";
    char *months[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[MONTHS];

    sales_from_file(filename, sales);

    sales_report_list(months, sales);
    sales_summary_list(months, sales);
    six_month_moving_avg(months, sales);
    HightoLow_sales_report(months, sales);

    return 0;
}

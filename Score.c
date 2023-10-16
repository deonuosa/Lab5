#include <stdio.h>

void Score_Combinations(int score) {
    int td, fg, tdfg, conversion, safety;

    for (td = 0; score >= (8 * td); td++) {
        for (tdfg = 0; (8 * td + 7 * tdfg) <= score; tdfg++) {
            for (conversion = 0; (8 * td + 7 * tdfg + 6 * conversion) <= score; conversion++) {
                for (fg = 0; (8 * td + 7 * tdfg + 6 * conversion + 3 * fg) <= score; fg++) {
                    for (safety = 0; (8 * td + 7 * tdfg + 6 * conversion + 2 * safety) <= score; safety++) {
                        if (score == (8 * td + 7 * tdfg + 6 * conversion + 3 * fg + 2 * safety)) {
                            printf("%d TD + %d 2pt, %d TD + %d %d 3pt FG, %d Safety\n", td, safety, fg, tdfg, conversion, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to Stop.\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            printf("Program terminated.\n");
            break;
        }

        printf("Possible combinations of scoring plays:\n");
        Score_Combinations(score);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    FILE *file = fopen("coin.dat", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    int tosses;
    double bias;
    printf("Enter number of tosses: ");
    scanf("%d", &tosses);
    printf("Enter bias (0 to 1): ");
    scanf("%lf", &bias);
    if (bias < 0 || bias > 1)
    {
        printf("Invalid bias!\n");
        return 1;
    }
    int fairHeads = 0, fairTails = 0;
    int biasedHeads = 0, biasedTails = 0;
    srand(time(NULL));
    for (int i = 1; i <= tosses; i++)
    {    // FAIR COIN
        if (rand() % 2 == 0)
            fairHeads++;
        else
            fairTails++;

        // Biased Coin
        double randomValue = (double)rand() / RAND_MAX;

        if (randomValue < bias)
            biasedHeads++;
        else
            biasedTails++;

        fprintf(file, "%d %.4f %.4f\n",
                i,
                (double)fairHeads / i,
                (double)biasedHeads / i);
    }

    fclose(file);
      
    printf("\n SIMULATION RESULT\n");

    printf("\nFair Coin (P(Head) = 0.5)\n");
    printf("Heads = %d\n", fairHeads);
    printf("Tails = %d\n", fairTails);
    printf("Probability of Head = %.4f\n", (double)fairHeads / tosses);

    printf("\nBiased Coin (P(Head) = %.2f)\n", bias);
    printf("Heads = %d\n", biasedHeads);
    printf("Tails = %d\n", biasedTails);
    printf("Probability of Head = %.4f\n", (double)biasedHeads / tosses);
    
    printf("\nSimulation completed.\n");
    printf("Data saved in coin.dat\n");
    system("gnuplot -persist -e \"\
         set terminal qt; \
         set title 'Fair Coin vs Biased Coin'; \
           set xlabel 'Number of Tosses'; \
          set ylabel 'Probability of Heads'; \
           set grid; \
         set key top right; \
          plot 'coin.dat' using 1:2 with lines lw 2 pt 7 title 'Fair Coin', \
         'coin.dat' using 1:3 with lines lw 2 pt 5 title 'Biased Coin'; \
                 pause -1 \
                         \"");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#pragma warning (disable: 4996)

#define SST 0.10
#define  A 10.00
#define  B 15.00
#define  C 18.00
#define  D 24.00

void logo() {
    printf("0000000000000000000000000000000000000000\n");
    printf("0000000000000000000000000000000000000000\n");
    printf("0000000  0000000000000000000000  0000000\n");
    printf("000000    000000^00^0000000000    000000\n");
    printf("00000      0000   00 00000000      00000\n");
    printf("0000         000     00000          0000\n");
    printf("0000           00     000           0000\n");
    printf("0000                                0000\n");
    printf("0000                                0000\n");
    printf("00000    00  0000      0000   00   00000\n");
    printf("0000000 0000000000    00000000000 000000\n");
    printf("0000000000000000000  0000000000000000000\n");
    printf("0000000000000000000000000000000000000000\n");
    printf("0000000000000000000000000000000000000000\n");


}
void menu() {
    printf("      -------------------\n");
    printf("     |=======Menu========|\n");
    printf("      -------------------\n");
    printf("COMBO                                                                   Price\n");
    printf("========                                                                =========\n");
    printf("COMBO A(1 Normal Burger + 1 French fries + 1 Drink)                     RM 10.00\n");
    printf("\n");
    printf("COMBO B(1 Normal Burger + 1 French fries + 1 Nuggets + 1 Drink)         RM 15.00\n");
    printf("\n");
    printf("COMBO C(1 Cheese Burger + 1 French fries + 1 Nuggets + 1 Drink)         RM 18.00\n");
    printf("\n");
    printf("COMBO D(1 Cheese Burger + 1 French fries + 1 Fried Chicken + 1 Drink)   RM 24.00\n");
    printf("\n");
    printf("----------------------------------------------------------------------------------------------------\n");
}

double order() {
    //customer number
    int cusnum = 0;
    //combo set
    char combo;
    //bill variables
    double ssttotal, totalpay;
    double combocharges=0 ;
    //order variables
    double sumB , sumC , sumD, sumA;


    int quantityA, quantityB, quantityC, quantityD ;
    //daily report variables
    int quantitytotalA = 0, quantitytotalB = 0, quantitytotalC = 0, quantitytotalD = 0;
    double salesamountA = 0, salesamountB = 0, salesamountC = 0, salesamountD = 0;
    double sstcharges = 0, totalcollected = 0;
    //loop counter
    int counter = 1;



    do {
        do {
            printf("Customer No: %d\n", ++cusnum);
            break;
        } while (cusnum > 0);
        sumB = sumC = sumD = sumA = 0;
        do {
            rewind(stdin);
            printf("Please Enter Combo Sets(other = exit) : ");
            scanf("%c", &combo);
            toupper(combo);
            if (combo == 'A' || combo == 'B' || combo == 'C' || combo == 'D') {
                if (combo == 'A' ) {
                    printf("Please Enter Quantity                 : ");
                    scanf("%d", &quantityA);

                    sumA += A * quantityA;
                    quantitytotalA += quantityA;
                    salesamountA += A * quantityA;

                    printf(" >Combo %c : %d x RM %.2lf           = RM %.2lf\n", combo, quantityA, A, A * quantityA);

                } else if (combo == 'B' ) {
                    printf("Please Enter Quantity                 : ");
                    scanf("%d", &quantityB);

                    sumB += B * quantityB;
                    quantitytotalB += quantityB;
                    salesamountB += B * quantityB;

                    printf(" >Combo %c : %d x RM %.2lf           = RM %.2lf\n", combo, quantityB, B, B * quantityB);

                } else if (combo == 'C') {
                    printf("Please Enter Quantity                 : ");
                    scanf("%d", &quantityC);

                    sumC += C * quantityC;
                    quantitytotalC += quantityC;
                    salesamountC += C * quantityC;
                    printf(" >Combo %c : %d x RM %.2lf           = RM %.2lf\n", combo, quantityC, C, C * quantityC);

                } else if (combo == 'D' ) {
                    printf("Please Enter Quantity                 : ");
                    scanf("%d", &quantityD);

                    sumD += D * quantityD;
                    quantitytotalD += quantityD;
                    salesamountD += D * quantityD;

                    printf(" >Combo %c : %d x RM %.2lf           = RM %.2lf\n", combo, quantityD, D, D * quantityD);

                }
                combocharges = sumA + sumB + sumC + sumD;

            }
        } while (combo == 'A' || combo == 'B' || combo == 'C' || combo == 'D');

        while (combo != 'A' || combo != 'B' || combo != 'C' || combo != 'D') {

            ssttotal = combocharges * SST;
            totalpay = combocharges + ssttotal;
            sstcharges += ssttotal;
            totalcollected += totalpay;
            double amountpaid, changedue;
            printf("                        Combo Charges = RM %.2lf\n", combocharges);
            printf("                        10%%     SST   = RM %.2lf\n", ssttotal);
            printf("                        Total To Pay  = RM %.2lf\n", totalpay);
            printf("                        Amount Paid   = RM  ");
            scanf("%lf", &amountpaid);
            changedue = amountpaid - totalpay;
            printf("                        Change Due    = RM %.2f \n", changedue);
            printf("Thank You, Have A Nice Day !!!\n");
            break;

        }
        rewind(stdin);
        char choose;
        printf("\n");
        printf("Next Customer(Y=yes?)");
        scanf("%c", &choose);
        printf("\n");
        if (choose == 'Y' || choose == 'y') {
            continue;
        } else {
            int totalquantity;
            double totalsalesamount;
            totalquantity = quantitytotalA + quantitytotalB + quantitytotalC + quantitytotalD;
            totalsalesamount = salesamountA + salesamountB + salesamountC + salesamountD;
            printf("DAILY SALES REPORT ");
            printf("\n");
            printf("Total Number of Customers = %d\n", cusnum);
            printf("\n");
            printf("Combo Sales For Today\n");
            printf("-----------------------------------------------------------\n");
            printf("COMBO    Quantity Sold           Sales Amount\n");
            printf("  A           %d                      %.2lf\n", quantitytotalA, salesamountA);
            printf("  B           %d                      %.2lf\n", quantitytotalB, salesamountB);
            printf("  C           %d                      %.2lf\n", quantitytotalC, salesamountC);
            printf("  D           %d                      %.2lf\n", quantitytotalD, salesamountD);
            printf("======      =====                 ===============\n");
            printf("TOTALS        %d                      %.2lf\n", totalquantity, totalsalesamount);
            printf("TOTAL SST charges  =                  %.2lf\n", sstcharges);
            printf("TOTAL RM collected =                 %.2lf\n", totalcollected);
            printf("-----------------------------------------------------------\n");
            printf("End\n");
            break;


        }
    } while (counter = 1);
    return 0;
}

void main() {
    logo();
    menu();
    order();
    system("pause");
}


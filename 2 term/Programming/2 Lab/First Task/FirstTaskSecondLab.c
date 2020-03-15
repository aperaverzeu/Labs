#include <stdio.h>
#include <stdlib.h>

double MorningInterval = 0.0;
double NoonInterval = 0.0;
double EveningInterval = 0.0;

int MorningVisitors = 0;
int NoonVisitors = 0;
int EveningVisitors = 0;

const int MoringVisitorsPH = 5;
const int NoonVisitorsPH = 14;
const int EveningVisitorsPH = 42;

const int CommonCostPrice = 851;
const int CommonPrice = 3829;


int getVariant(int count) {
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку
    
    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Incorrect input. Try again:\t"); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }
    
    return variant;
}

void setWorkingInterval() {
    int dateTime;
    
    printf("Enter time of visiting:\n");
    printf("1. Morning time(9:00 – 13:00)\n");
    printf("2. Noon time(13:00 – 18:00)\n");
    printf("3. Evening time(18:00 – 23:00)\n");
    printf(">  ");
    
    dateTime = getVariant(3);
    
    switch (dateTime) {
        case 1:
            printf("This is morning!\n");
            int morningHdzStart, morningChvlStart, morningHdzEnd, morningChvlEnd, morningHdzInterval, morningChvlInterval;
            
            char mrS[100];
            printf("So enter time from 9:00 til 13:00");
            fgets(mrS,100,stdin);
            sscanf(mrS,"%d:%d", &morningHdzStart,&morningChvlStart);
            
            // validation
            while (sscanf(mrS, "%d", &morningHdzStart) != 1 || morningHdzStart < 9 || morningHdzStart > 13 || (morningHdzStart == 13 && morningChvlStart != 0) || (morningChvlStart > 60 && morningChvlStart < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(mrS,100,stdin);
                sscanf(mrS,"%d:%d", &morningHdzStart,&morningChvlStart);
            }
            
            char mrC[100];
            fgets(mrC,100,stdin);
            sscanf(mrC,"%d:%d", &morningHdzEnd,&morningChvlEnd);
            
            // validation
            while (sscanf(mrC, "%d", &morningHdzEnd) != 1 || morningHdzEnd < 9 || morningHdzEnd > 13 ||   (morningHdzEnd == 13 && morningChvlEnd != 0) || (morningChvlEnd > 60 && morningChvlEnd < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(mrC,100,stdin);
                sscanf(mrC,"%d:%d", &morningHdzEnd,&morningChvlEnd);
            }
            
            printf("%d:%d  %d:%d\n", morningHdzStart, morningChvlStart, morningHdzEnd, morningChvlEnd);
            
            // solving 60 minute problem
            if (morningChvlEnd < morningChvlStart) {
                morningChvlEnd += 60;
                morningHdzEnd -= 1;
            }
            
            morningHdzInterval = morningHdzEnd - morningHdzStart;
            morningChvlInterval = morningChvlEnd - morningChvlStart;
            
            double morningDecimalInterval = (double)(morningHdzInterval*60 + morningChvlInterval)/60;
            
            MorningInterval = morningDecimalInterval;
            
            break;
            
            
        case 2:
            printf("This is noon!\n");
            int noonHdzStart, noonChvlStart, noonHdzEnd, noonChvlEnd, noonHdzInterval, noonChvlInterval;
            
            char nrS[100];
            printf("This is a day! So enter time from 13:00 til 18:00");
            fgets(nrS,100,stdin);
            sscanf(nrS,"%d:%d", &noonHdzStart,&noonChvlStart);
            
            // validation
            while (sscanf(nrS, "%d", &noonHdzStart) != 1 || noonHdzStart < 13 || noonHdzStart > 18 || (noonHdzStart == 18 && noonChvlStart != 0) || (noonChvlStart > 60 && noonChvlStart < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(nrS,100,stdin);
                sscanf(nrS,"%d:%d", &noonHdzStart,&noonChvlStart);
            }
            
            char nrC[100];
            fgets(nrC,100,stdin);
            sscanf(nrC,"%d:%d", &noonHdzEnd,&noonChvlEnd);
            
            // validation
            while (sscanf(nrC, "%d", &noonHdzEnd) != 1 || noonHdzEnd < 13 || noonHdzEnd > 18 || (noonHdzEnd == 18 && noonChvlEnd != 0) || (noonChvlEnd > 60 && noonChvlEnd < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(nrC,100,stdin);
                sscanf(nrC,"%d:%d", &noonHdzEnd,&noonChvlEnd);
            }
            
            printf("%d:%d  %d:%d\n", noonHdzStart, noonChvlStart, noonHdzEnd, noonChvlEnd);
            
            if (noonChvlEnd < noonChvlStart) {
                noonChvlEnd += 60;
                noonHdzEnd -= 1;
            }
            
            noonHdzInterval = noonHdzEnd - noonHdzStart;
            noonChvlInterval = noonChvlEnd - noonChvlStart;
            
            double noonDecimalInterval = (double)(noonHdzInterval*60 + noonChvlInterval)/60;
            
            NoonInterval = noonDecimalInterval;
            break;
            
        case 3:
            printf("This is evening!\n");
            int eveningHdzStart, eveningChvlStart, eveningHdzEnd, eveningChvlEnd, eveningHdzInterval, eveningChvlInterval;
            
            char erS[100];
            printf("This is an evening! So enter time from 18:00 til 23:00");
            fgets(erS,100,stdin);
            sscanf(erS,"%d:%d", &eveningHdzStart,&eveningChvlStart);
            
            // validation
            while (sscanf(erS, "%d", &eveningHdzStart) != 1 || eveningHdzStart < 18 || eveningHdzStart > 23 || (eveningHdzStart == 23 && eveningChvlStart != 0) || (eveningChvlStart > 60 && eveningChvlStart < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(erS,100,stdin);
                sscanf(erS,"%d:%d", &eveningHdzStart,&eveningChvlStart);
            }
            
            char erC[100];
            fgets(erC,100,stdin);
            sscanf(erC,"%d:%d", &eveningHdzEnd,&eveningChvlEnd);
            
            // validation
            while (sscanf(erC, "%d", &eveningHdzEnd) != 1 || eveningHdzEnd < 18 || eveningHdzEnd > 23 ||     (eveningHdzEnd == 23 && eveningChvlEnd != 0) || (eveningChvlEnd > 60 && eveningChvlEnd < 0)) {
                printf("Incorrect input. Try again:\n");
                fgets(erC,100,stdin);
                sscanf(erC,"%d:%d", &eveningHdzEnd,&eveningChvlEnd);
            }
            
            printf("%d:%d  %d:%d\n", eveningHdzStart, eveningChvlStart, eveningHdzEnd, eveningChvlEnd);
            
            if (eveningChvlEnd < eveningChvlStart) {
                eveningChvlEnd += 60;
                eveningHdzEnd -= 1;
            }
            
            eveningHdzInterval = eveningHdzEnd - eveningHdzStart;
            eveningChvlInterval = eveningChvlEnd - eveningChvlStart;
            
            double eveningDecimalInterval = (double)(eveningHdzInterval*60 + eveningChvlInterval)/60;
            
            EveningInterval = eveningDecimalInterval;
            break;
            
        default:
            printf("Invalid paramenetrs!");
            break;
    }
}

void printNumOfVisitors() {
    if (MorningInterval != 0.0) {
        MorningVisitors = MorningInterval * MoringVisitorsPH;
        printf("Proposed number of morning visitors: %d\n", MorningVisitors);
    } else if(NoonInterval != 0.0) {
        NoonVisitors = NoonInterval * NoonVisitorsPH;
        printf("Proposed number of noon visitors: %d\n", NoonVisitors);
    } else if (EveningInterval != 0.0) {
        EveningVisitors = EveningInterval * EveningVisitorsPH;
        printf("Proposed number of evening visitors: %d\n", EveningVisitors);
    } else if(MorningInterval == 0.0 && NoonInterval == 0.0 && EveningInterval == 0.0){
        printf("There are no visitors!");
    } else {
        printf("Invalid parameters!");
    }
}

void printOrder() {
    int hamWeight = 90, mushroomWeight = 80, vegetableWeight = 150, flourWeight = 150,
        hamValue = 630, mushroomValue = 800, vegetableValue = 450,  flourValue = 225;
    
    if (MorningVisitors != 0) {
        if (MorningVisitors <  2) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", hamWeight, mushroomWeight, vegetableWeight, flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", hamValue+mushroomValue+vegetableValue+flourValue);
        }
        if (MorningVisitors <  3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", 2*hamWeight/3, 2*mushroomWeight/3, 2*vegetableWeight/3, 2*flourWeight/3);
            printf("Total proposial price of ingridients is %d ₽\n",   2*(hamValue+mushroomValue+vegetableValue+flourValue)/3);
        }
        if (MorningVisitors >= 3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", MorningVisitors*hamWeight, MorningVisitors*mushroomWeight, MorningVisitors*vegetableWeight, MorningVisitors*flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", MorningVisitors*(hamValue+mushroomValue+vegetableValue+flourValue));
        }
    } else if (NoonVisitors != 0) {
        if (NoonVisitors <  2) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", hamWeight, mushroomWeight, vegetableWeight, flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", hamValue+mushroomValue+vegetableValue+flourValue);
        }
        if (NoonVisitors <  3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", 2*hamWeight/3, 2*mushroomWeight/3, 2*vegetableWeight/3, 2*flourWeight/3);
            printf("Total proposial price of ingridients is %d ₽\n",   2*(hamValue+mushroomValue+vegetableValue+flourValue)/3);
        }
        if (NoonVisitors >= 3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", NoonVisitors*hamWeight, NoonVisitors*mushroomWeight, NoonVisitors*vegetableWeight, NoonVisitors*flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", NoonVisitors*(hamValue+mushroomValue+vegetableValue+flourValue));
        }
    } else if (EveningVisitors != 0) {
        if (EveningVisitors <  2) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", hamWeight, mushroomWeight, vegetableWeight, flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", hamValue+mushroomValue+vegetableValue+flourValue);
        }
        if (EveningVisitors <  3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", 2*hamWeight/3, 2*mushroomWeight/3, 2*vegetableWeight/3, 2*flourWeight/3);
            printf("Total proposial price of ingridients is %d ₽\n",   2*(hamValue+mushroomValue+vegetableValue+flourValue)/3);
        }
        if (EveningVisitors >= 3) {
            printf("Proposial quantity is %d grams for ham, or %d grams for mushroom,\n or %d grams for vegetables, and %d grams for flour\n", EveningVisitors*hamWeight, EveningVisitors*mushroomWeight, EveningVisitors*vegetableWeight, EveningVisitors*flourWeight);
            printf("Total proposial price of ingridients is %d ₽\n", EveningVisitors*(hamValue+mushroomValue+vegetableValue+flourValue));
        }
    } else {
        printf("Invalid parameters!");
    }
}

void printPizzas() {
    int pizzaVariant;
    
    printf("Enter type of pizza:\n");
    printf("1. Ham pizza\n");
    printf("2. Mushroom pizza\n");
    printf("3. Vegetable pizza\n");
    printf("4. Print all\n");
    printf(">  ");
    
    pizzaVariant = getVariant(4);
    
    switch (pizzaVariant) {
        case 1:
            printf("Cost price of ham pizza:  675₽\n");
            printf("Price of ham pizza:       3037.5₽\n");
            break;
            
        case 2:
            printf("Cost price of mushroom pizza:  1025₽\n");
            printf("Price of mushroom pizza:       4612.5₽\n");
            break;
            
        case 3:
            printf("Cost price of vegetable pizza:  855₽\n");
            printf("Price of vegetable pizza:       3845.5₽\n");
            break;
            
        case 4:
            printf("Ham pizza: \n");
            printf("Cost price of ham pizza:        675₽\n");
            printf("Price of ham pizza:             3037.5₽\n");
            printf("Mushroom pizza: \n");
            printf("Cost price of mushroom pizza:   1025₽\n");
            printf("Price of mushroom pizza:        4612.5₽\n");
            printf("Vegetable pizza: \n");
            printf("Cost price of vegetable pizza:  855₽\n");
            printf("Price of vegetable pizza:       3845.5₽\n");
            break;
            
        default:
            printf("Invalid parameters!");
            break;
    }
}

void printProfit() {
    if (MorningVisitors != 0) {
        if (MorningVisitors <  2) { printf("Proposial profit is %d ₽\n", CommonPrice / 3); }
        if (MorningVisitors <  3) { printf("Proposial profit is %d ₽\n", 2 * CommonPrice / 3); }
        if (MorningVisitors >= 3) { printf("Proposial profit is %d ₽\n", CommonPrice * MorningVisitors); }
    } else if (NoonVisitors != 0) {
        if (NoonVisitors <  2) { printf("Proposial profit is %d ₽\n", CommonPrice / 3); }
        if (NoonVisitors <  3) { printf("Proposial profit is %d ₽\n", 2 * CommonPrice / 3); }
        if (NoonVisitors >= 3) { printf("Proposial profit is %d ₽\n", CommonPrice * NoonVisitors); }
    } else if (EveningVisitors != 0) {
        if (EveningVisitors <  2) { printf("Proposial profit is %d ₽\n", CommonPrice / 3); }
        if (EveningVisitors <  3) { printf("Proposial profit is %d ₽\n", 2 * CommonPrice / 3); }
        if (EveningVisitors >= 3) { printf("Proposial profit is %d ₽\n", CommonPrice * EveningVisitors); }
    } else {
        printf("Profit is 0 cause there are no visitors…");
    }
}

void printInfoBoutMe() {
    printf("+--------+--------------------------+--------+\n");
    
    printf("|                versija 1.7.1               |\n");
    
    printf("|                                            |\n");
    
    printf("|           Ałiaksiej Pieravierzieŭ          |\n");
    
    printf("|                                            |\n");
    
    printf("|                student BDUIR               |\n");
    
    printf("+--------+--------------------------+--------+\n");
}


void printMenu() {
    
    system("cls");  // очищаем экран
    printf("Welcome to Capri Pizza!\n");
    printf("What do you want to do?\n");
    printf("1. Enter working interval\n");
    printf("2. Print proposed number of visitors\n");
    printf("3. Print order\n");
    printf("4. Print info 'bout pizzas\n");
    printf("5. Print proposed profit\n");
    printf("6. Info 'bout ME\n");
    printf("7. Exit\n");
    printf(">  ");
}


int main() {
    int variant;
    
    setWorkingInterval();
    
    do {
        printMenu();
        
        variant = getVariant(7);
        
        switch (variant) {
            case 1:
                setWorkingInterval();
                break;
                
            case 2:
                printNumOfVisitors();
                break;
                
            case 3:
                printOrder();
                break;
                
            case 4:
                printPizzas();
                break;
                
            case 5:
                printProfit();
                break;
                
            case 6:
                printInfoBoutMe();
                break;
        }
        
        if (variant != 7)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 7);
    
    return 0;
}

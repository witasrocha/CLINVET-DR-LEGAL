struct animal {
    int quantity, reorder, i, id;
    char name[20];
    float price;
};


void gotoxy(int column, int line);

COORD coord = { 0, 0 };

void gotoxy(int x, int y) {
    coord.X = x; coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int addAnimal() {
    FILE *fp;
	
    int i = 0;
    struct animal a;
    system("cls");

    fp = fopen("inventory.txt", "a+t");

    char checker;

    do {
        system("cls");

        gotoxy(17, 5);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 SYZ INVENTORY PROGRAM \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(17, 20);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

        gotoxy(22, 8);
        printf("Enter product ID : ");
        scanf(" %d", &a.id);

        gotoxy(22, 10);
        printf("Enter product name : ");
        scanf(" %s", a.name);

        gotoxy(22, 12);
        printf("Enter product quantity : ");
        scanf(" %d", &a.quantity);

        gotoxy(22, 14);
        printf("Enter product price : ");
        scanf(" %f", &a.price);

        gotoxy(22, 17);
        fprintf(fp, "%d %s %d %f\n\n", a.id, a.name, a.quantity, a.price); //SAVE TO TXT FILE LINE !
        printf("Salvo!\n\n");

        fclose(fp);

        gotoxy(22, 22);
        printf("Cadastrar novo animal? Y / N : ");

        scanf(" %c", &checker);
        checker = toupper(checker);

        i++;

        system("cls");
    } while (checker=='Y');

    if (checker == 'N') {
        main();
    } else {
        do {
            system("cls");

            gotoxy(17, 5);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 DR LEGAL MEDICO VETERINARIO \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(17, 20);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

            gotoxy(18, 8);
            printf(">>> Wrong Input! Please Enter Y Or N Only! <<<");

            gotoxy(19, 12);
            printf("Cadastrar novo animal? Y / N : ");
            scanf(" %c", &checker);
            checker = toupper(checker);
        } while (checker != 'Y' && checker != 'N');

        if (checker == 'Y'){
            addAnimal();
        }

        if (checker == 'N') {
            system("cls");
            main();
        }
    }
    return(0);
}

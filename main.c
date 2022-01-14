#include <stdio.h>
#include <stdlib.h>

// ниже приведена функция генерации случайного автомобильного номера
// сложность в том, чтобы
char* NaumberGen(char* Number, char *Letter, char *Digit)
{
    char buf1;
  //  char *Number;
  //  Number = (char*)malloc(sizeof(char)*6);

    buf1 = Letter[rand()%25];
    Number[0] = buf1;
    buf1 = Digit[rand()%10];
    Number[1] = buf1;
    buf1 = Digit[rand()%10];
    Number[2] = buf1;
    buf1 = Digit[rand()%10];
    Number[3] = buf1;
    buf1 = Letter[rand()%25];
    Number[4] = buf1;
    buf1 = Letter[rand()%25];
    Number[5] = buf1;
    Number[6] = ' ';


 //   printf("%c%c%c%c%c%c \n", Number[0],Number[1],Number[2],Number[3],Number[4], Number[5]);
    return Number;
}

int strCompare(char* str1, char* str2)
{
    int i=0;
    int n=0;
    char c1;
    int str1_n=0;
    int str2_n=0;
    int equal =0;

    while(str1[i])
    {
        i++;

    }
    str1_n = i;
    i=0;

    while(str2[i])
    {
        i++;

    }
    str2_n = i;

 //   printf("Длина первой строки - %d, а длина второй строки - %d", str1_n, str2_n);

    if (str1_n==str2_n)
    {
        for (i=0; i<str1_n; i++)
        {
            if (str1[i]==str2[i])
                equal=1;
            else
            {
                equal=0;
                break;
            }
        }
    }
    /*if (equal==1)
        printf("Строчки равны\n");
    else
        printf("Строчки разные");*/

    return equal;
}
// функция печати шапки таблицы
void printUp()
{
    printf("_______________________________________________________________________________________________\n");
    printf("|               |            |                          ФИО                                    |\n");
    printf("| Гос.номер     |   Цвет     |    Марка     |     Фамилия      |     Имя      |     Отчество   |\n");
    printf("|----------------------------------------------------------------------------------------------|\n");
    return 0;
}



int main()
{
    srand(time(NULL));
    struct Cars{

    char carNumber[8];
    char carColor[8];
    char carMark[8];

    struct FIO{
    char Surname[15];
    char FirstName[10];
    char SecondName[13];


    } ownFIO;

    };
    system("chcp 1251");
    struct Cars *carz;
    int n = 3050;
    int i = 0;
    char *Colors[9] = {"White", "Red", "Green", "Black", "Yellow", "Blue", "Orange", "Snow", "Grey"};
    char *Surnames[9] = {"Холопов", "Триленко", "Девоушенко", "Бакель", "Грайндкоренко", "Демиурчук", "Филимон", "Даздрастенов", "Фарханов"};
    char *Firstnames[9] = {"Галер", "Джок", "Джер", "Ящер", "Гипард", "Тиран", "Миха", "Завр", "Рекс"};
    char *Secondnames[9] = {"Фогальдович", "Тиктокович", "Ящерович", "Михайлович", "Рексович", "Татьянович", "Мишелевич", "Зиккуратович", "Аншлюзович"};
    char *Marks[7] = {"Toyota", "Lexus", "UAZ", "Nissan", "Porshe", "VAZ", "Subaru"};
    char *Letter = "абвгдежзиклмнопрстуфхцчшщ"; //25
    char *Digit = "0123456789"; //25
    char *Number;
    char Number_temp[6];
    char *Result;
    char buf1;
    // выделяем память под номер
    Number = (char*)malloc(sizeof(char)*7);

    Number = NaumberGen(Number, Letter, Digit);
    printf("%c%c%c%c%c%c \n", Number[0],Number[1],Number[2],Number[3],Number[4], Number[5]);


    carz = (struct Cars*)malloc(sizeof(struct Cars)*n);
    printf("size is %d and size of int is %d\n", sizeof(Colors)/4, sizeof(int));
    for (i=0; i<n; i++)
    {
  //  Number_temp = *NaumberGen(Number, Letter, Digit);
    strcpy(carz[i].carNumber,NaumberGen(Number, Letter, Digit));
    strcpy(carz[i].carColor,Colors[rand()%(sizeof(Colors)/4)]);
    strcpy(carz[i].carMark,Marks[rand()%(sizeof(Marks)/4)]);
    strcpy(carz[i].ownFIO.Surname,Surnames[rand()%9]);
    strcpy(carz[i].ownFIO.FirstName,Firstnames[rand()%9]);
    strcpy(carz[i].ownFIO.SecondName,Secondnames[rand()%9]);
    }

    printUp();
    for (i=0; i<n; i++)
    {
        printf("|  %11s  |%12s| %12s |  %14s  |  %10s  |  %12s  |\n",carz[i].carNumber, carz[i].carColor, carz[i].carMark, carz[i].ownFIO.Surname,
               carz[i].ownFIO.FirstName,carz[i].ownFIO.SecondName);
        printf("|----------------------------------------------------------------------------------------------|\n");
    }

    // переменные касающиеся фильтров поиска
    // по каким-то причинам не удалось здесь воспользоваться динамическими строками
    char markSearch[6] = "Nissan";
    char colorSearch[6] = "Red";
    char answer='n';

    printf("Будем фильтровать результаты по марке автомобиля и цвету? y or n\n");
    scanf("%c", &answer);
    if (answer=='y')
    {
        printf("Какую марку авто будем искать? Доступные: ");
        for (i=0; i<sizeof(Marks)/4; i++)
            printf("%s; ", Marks[i]);

        scanf("%s", &markSearch);

        printf("Какой цвет авто будем искать? Доступные: ");
        for (i=0; i<sizeof(Colors)/4; i++)
            printf("%s; ", Colors[i]);

       scanf("%s", &colorSearch);

    printUp();
    for (i=0; i<n; i++)
    {

        if(strCompare(markSearch, carz[i].carMark)==1&&strCompare(colorSearch, carz[i].carColor)==1)
        {
            printf("|  %11s  |%12s| %12s |  %14s  |  %10s  |  %12s  |\n",carz[i].carNumber, carz[i].carColor, carz[i].carMark, carz[i].ownFIO.Surname,
               carz[i].ownFIO.FirstName,carz[i].ownFIO.SecondName);
        printf("|----------------------------------------------------------------------------------------------|\n");

        }

    }
    }


    return 0;
}

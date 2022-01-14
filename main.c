#include <stdio.h>
#include <stdlib.h>


// íèæå ïðèâåäåíà ôóíêöèÿ ãåíåðàöèè ñëó÷àéíîãî àâòîìîáèëüíîãî íîìåðà
// ñëîæíîñòü â òîì, ÷òîáû
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

 //   printf("Äëèíà ïåðâîé ñòðîêè - %d, à äëèíà âòîðîé ñòðîêè - %d", str1_n, str2_n);

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
        printf("Ñòðî÷êè ðàâíû\n");
    else
        printf("Ñòðî÷êè ðàçíûå");*/

    return equal;
}
// ôóíêöèÿ ïå÷àòè øàïêè òàáëèöû
void printUp()
{
    printf("_______________________________________________________________________________________________\n");
    printf("|               |            |                          ÔÈÎ                                    |\n");
    printf("| Ãîñ.íîìåð     |   Öâåò     |    Ìàðêà     |     Ôàìèëèÿ      |     Èìÿ      |     Îò÷åñòâî   |\n");
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
    char *Surnames[9] = {"Õîëîïîâ", "Òðèëåíêî", "Äåâîóøåíêî", "Áàêåëü", "Ãðàéíäêîðåíêî", "Äåìèóð÷óê", "Ôèëèìîí", "Äàçäðàñòåíîâ", "Ôàðõàíîâ"};
    char *Firstnames[9] = {"Ãàëåð", "Äæîê", "Äæåð", "ßùåð", "Ãèïàðä", "Òèðàí", "Ìèõà", "Çàâð", "Ðåêñ"};
    char *Secondnames[9] = {"Ôîãàëüäîâè÷", "Òèêòîêîâè÷", "ßùåðîâè÷", "Ìèõàéëîâè÷", "Ðåêñîâè÷", "Òàòüÿíîâè÷", "Ìèøåëåâè÷", "Çèêêóðàòîâè÷", "Àíøëþçîâè÷"};
    char *Marks[7] = {"Toyota", "Lexus", "UAZ", "Nissan", "Porshe", "VAZ", "Subaru"};
    char *Letter = "àáâãäåæçèêëìíîïðñòóôõö÷øù"; //25
    char *Digit = "0123456789"; //25
    char *Number;
    char Number_temp[6];
    char *Result;
    char buf1;
    // âûäåëÿåì ïàìÿòü ïîä íîìåð
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

    // ïåðåìåííûå êàñàþùèåñÿ ôèëüòðîâ ïîèñêà
    // ïî êàêèì-òî ïðè÷èíàì íå óäàëîñü çäåñü âîñïîëüçîâàòüñÿ äèíàìè÷åñêèìè ñòðîêàìè
    char markSearch[6] = "Nissan";
    char colorSearch[6] = "Red";
    char answer='n';

    printf("Áóäåì ôèëüòðîâàòü ðåçóëüòàòû ïî ìàðêå àâòîìîáèëÿ è öâåòó? y or n\n");
    scanf("%c", &answer);
    if (answer=='y')
    {
        printf("Êàêóþ ìàðêó àâòî áóäåì èñêàòü? Äîñòóïíûå: ");
        for (i=0; i<sizeof(Marks)/4; i++)
            printf("%s; ", Marks[i]);

        scanf("%s", &markSearch);

        printf("Êàêîé öâåò àâòî áóäåì èñêàòü? Äîñòóïíûå: ");
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

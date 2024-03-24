#include <stdio.h>

#define levmax 3
#define amax 2047

enum fct {LIT, OPR, LOD, STO, CAL, INT, JMP, JPC};

typedef struct instrucao
{
    enum fct f;
    int l; // l: 0..levmax; // Buffer de nivel
    int a; // a: 0..amax; // Buffer de endereco
} instrucao;

instrucao code[2048];

#define tamanho_da_pilha 5012

int p, b, t;
instrucao eu;
int s[tamanho_da_pilha];

int base(int l)
{
    int b1 = b;
    while (l > 0) {
        b1 = s[b1];
        l--;
    }
    return b1;
}

int impar(int x)
{
    return (x % 2);
}

void pcodevhw()
{
    printf("\n  p   b   t\t f    l    a \t       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17\n");
    printf(" === === ===    ===  ===  ===          == == == == == == == == == == == == == == == == == ==\n");
    t = -1;
    b = 0;
    p = 0;
    s[0] = s[1] = s[2] = 0;


    do
    {
        eu = code[p];
        printf("%3d %3d %3d\t", p, b, t);
        p++;
        switch (eu.f) {
            case LIT:
                t++;
                s[t] = eu.a;
                printf("LIT %3d %3d", eu.l, eu.a);
                break;
            case OPR:
                printf("OPR %3d %3d", eu.l, eu.a);
                switch (eu.a) {
                    case 0: // retorno
                        t = b - 1;
                        p = s[t + 3];
                        b = s[t + 2];
                        break;
                    case 1:
                        s[t] = -s[t];
                        break;
                    case 2:
                        t--;
                        s[t] = s[t] + s[t + 1];
                        break;
                    case 3:
                        t--;
                        s[t] = s[t] - s[t + 1];
                        break;
                    case 4:
                        t--;
                        s[t] = s[t] * s[t + 1];
                        break;
                    case 5:
                        t--;
                        s[t] = s[t] / s[t + 1];
                        break;
                    case 6:
                        s[t] = impar(s[t]);
                        break;
                    case 8:
                        t--;
                        s[t] = (s[t] == s[t + 1]);
                        break;
                    case 9:
                        t--;
                        s[t] = (s[t] != s[t + 1]);
                        break;
                    case 10:
                        t--;
                        s[t] = (s[t] < s[t + 1]);
                        break;
                    case 11:
                        t--;
                        s[t] = (s[t] >= s[t + 1]);
                        break;
                    case 12:
                        t--;
                        s[t] = (s[t] > s[t + 1]);
                        break;
                    case 13:
                        t--;
                        s[t] = (s[t] <= s[t + 1]);
                        break;
                }
                break;
            case LOD:
                printf("LOD %3d %3d", eu.l, eu.a);
                t++;
                s[t] = s[base(eu.l) + eu.a];
                break;
            case STO:
                printf("STO %3d %3d", eu.l, eu.a);
                s[base(eu.l) + eu.a] = s[t];
                t--;
                break;
            case CAL:
                printf("CAL %3d %3d", eu.l, eu.a);
                s[t + 1] = base(eu.l);
                s[t + 2] = b;
                s[t + 3] = p;
                b = t + 1;
                p = eu.a;
                break;
            case INT:
                t = t + eu.a;
                printf("INT %3d %3d", eu.l, eu.a);
                break;
            case JMP:
                p = eu.a;
                printf("JMP %3d %3d", eu.l, eu.a);
                break;
            case JPC:
                if (s[t] != 0) {
                    p = eu.a;
                }
                t--;
                printf("JPC %3d %3d", eu.l, eu.a);
                break;
        }
        printf("\ts[]: ");
        for (int h = 0; h <= t; h++)
            printf("%3d", s[h]);
        printf("\n");

    } while (p != 0);

     printf(" === === ===    ===  ===  ===          == == == == == == == == == == == == == == == == == ==\n");
     printf("  p   b   t\t f    l    a \t       0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17\n");

}
void soma(){

       //funcao de soma vai de s[100] ate s[150]
      //e o vetor vai de code[200] ate code[250]

    code[200].f = INT; code[200].l = 0; code[200].a = 6;
    code[201].f = LOD; code[201].l = 0; code[201].a = 3;
    code[202].f = LOD; code[202].l = 0; code[202].a = 4;
    code[203].f = OPR; code[203].l = 0; code[203].a = 2;
    code[204].f = STO; code[204].l = 0; code[204].a = 5;
    code[205].f = LOD; code[205].l = 0; code[205].a = 5;
    //salvando o valor da operacao em s[8] do main
    code[206].f = STO; code[206].l = 1; code[206].a = 8;
    //finalizando a funcao
    code[207].f = OPR; code[207].l = 0; code[207].a = 0;

}

void multiplicacao(){

       //funcao de multiplicacao vai de s[100] ate s[150]
      //e o vetor code vai de code[100] ate code[199]

    code[100].f = INT; code[100].l = 0; code[100].a = 6;
    code[101].f = LOD; code[101].l = 0; code[101].a = 3;
    code[102].f = LOD; code[102].l = 0; code[102].a = 4;
    code[103].f = OPR; code[103].l = 0; code[103].a = 4;
    code[104].f = STO; code[104].l = 0; code[104].a = 5;
    code[105].f = LOD; code[105].l = 0; code[105].a = 5;
    //salvando o valor da operacao em s[7] do main
    code[106].f = STO; code[106].l = 1; code[106].a = 7;
    //finalizando a funcao
    code[107].f = OPR; code[107].l = 0; code[107].a = 0;
}

int main()
{

   //chama a funcao soma
   soma();

   //chama a funcao multiplicacao
   multiplicacao();


  //  as posicoes reservadas para o main vai de s[0] ate s[99]
  //  e o vetor code vai de code[0] ate code[99]

    //s[3] = 1    a
    code[0].f = INT; code[0].l = 0; code[0].a = 9;
    code[1].f = LIT; code[1].l = 0; code[1].a = 1;
    code[2].f = STO; code[2].l = 0; code[2].a = 3;
    //s[4] = 2    b
    code[3].f = LIT; code[3].l = 0; code[3].a = 2;
    code[4].f = STO; code[4].l = 0; code[4].a = 4;
     //s[5] = 3   c
    code[5].f = LIT; code[5].l = 0; code[5].a = 3;
    code[6].f = STO; code[6].l = 0; code[6].a = 5;
    //s[6] = 4    x
    code[7].f = LIT; code[7].l = 0; code[7].a = 4;
    code[8].f = STO; code[8].l = 0; code[8].a = 6;
    //s[12] = 4
    code[9].f = LOD; code[9].l = 0; code[9].a = 6;
    code[10].f = STO; code[10].l = 0; code[10].a = 12;
    //s[13] = 4
    code[11].f = LOD; code[11].l = 0; code[11].a = 6;
    code[12].f = STO; code[12].l = 0; code[12].a = 13;
    //faz a multiplicacao de s[12] * s[13]
    // fazendo x*x
    code[13].f = CAL; code[13].l = 0; code[13].a = 100;
    //pega o resultado da multiplicacao que esta em s[7]
    //e coloca em s[12]
    code[14].f = LOD; code[14].l = 0; code[14].a = 7;
    code[15].f = STO; code[15].l = 0; code[15].a = 12;
    //pega o valor de a que esta em s[3]
    //e coloca em s[13]
    code[16].f = LOD; code[16].l = 0; code[16].a = 3;
    code[17].f = STO; code[17].l = 0; code[17].a = 13;
     //faz a multiplicacao de s[12] * s[13]
    // fazendo (x*x)*a
    code[18].f = CAL; code[18].l = 0; code[18].a = 100;
    //pega o resultado da multiplicacao que esta em s[7]
    //e coloca em s[3] pois nao vamos mais usar o A
    code[19].f = LOD; code[19].l = 0; code[19].a = 7;
    code[20].f = STO; code[20].l = 0; code[20].a = 3;
    //pega o valor de a que esta em s[4] = B
    //e coloca em s[12]
    code[21].f = LOD; code[21].l = 0; code[21].a = 4;
    code[22].f = STO; code[22].l = 0; code[22].a = 12;
     //pega o valor de a que esta em s[6] = X
    //e coloca em s[13]
    code[23].f = LOD; code[23].l = 0; code[23].a = 6;
    code[24].f = STO; code[24].l = 0; code[24].a = 13;
    //faz a multiplicacao de s[12] * s[13]
    // fazendo B*X
    code[25].f = CAL; code[25].l = 0; code[25].a = 100;
     //pega o valor de a que esta em s[7] = B*X
    //e coloca em s[12]
    code[26].f = LOD; code[26].l = 0; code[26].a = 7;
    code[27].f = STO; code[27].l = 0; code[27].a = 12;
    //pega o valor que esta em s[3]
    //e coloca em s[13]
    code[28].f = LOD; code[28].l = 0; code[28].a = 3;
    code[29].f = STO; code[29].l = 0; code[29].a = 13;
     //faz a soma de s[12] + s[13]
    // fazendo ((x*x)*a) + (B*X)
    code[30].f = CAL; code[30].l = 0; code[30].a = 200;
     /*
      pega o valor da operacacao que foi feita antes
      que esta em s[8] = ((x*x)*a) + (B*X).
      e colocando em s[12]
    */
    code[31].f = LOD; code[31].l = 0; code[31].a = 8;
    code[32].f = STO; code[32].l = 0; code[32].a = 12;
    /*
     pega o valor de C que esta em s[5]
     e coloca em s[13]
    */
    code[33].f = LOD; code[33].l = 0; code[33].a = 5;
    code[34].f = STO; code[34].l = 0; code[34].a = 13;
    // faz a soma de s[12] + s[13]
    code[35].f = CAL; code[35].l = 0; code[35].a = 200;
    //fim
    code[36].f = OPR; code[36].l = 0; code[36].a = 0;

    pcodevhw();

    return 0;
}

#include <stdio.h>
#define SIZE 500

typedef struct
{
    int f;
    int l;
    int a;
}estrutura;

void interpretado_p_code(estrutura vetor[]);
void soma_1_a_10();
void quadrado_1_a_100();
void cubo_1_a_1000();

int main(void)
{
    int op = -1;
    while(op != 0 && op != 2 && op !=1){
    printf("ENSIRA O CODIGO DA OPERACAO DESEJADA!\nsoma: codigo (0)\nQuadrado: codigo (1)\nCubo: codigo (2)\n");
    scanf("%d", &op);
    }
    switch (op)
    {
    case 0:
        soma_1_a_10();
        break;
    case 1:
        quadrado_1_a_100();
        break;
    case 2:
        cubo_1_a_1000();
        break;
    
    default:
        break;
    }
    

    return 0;
}//


void interpretado_p_code(estrutura vetor[])
{
    int p=1;
    int t=0; 
    int b=0; 
    int i=0; 

    __int64 stack[SIZE];
    stack[0] = 35;
    stack[1] = 36;
    stack[2] = 37;

    do
    {
        switch(vetor[p].f)
        {
            case 0: //END
                p = stack[b];
                break;
            case 1: //LIT
                stack[t] = vetor[p].a;
                p = p + 1;
                break;

            case 2: //OPR
                switch (vetor[p].a)
                {
                    case 1: //NEG
                        stack[t] = stack[t] * -1;
                        p=p+1;
                        break;

                    case 2: //ADD
                        t = t-1;
                        stack[t] = stack[t] + stack[t+1];
                        p=p+1;
                        break;

                    case 3: //SUB
                        t=t-1;
                        stack[t] = stack[t] - stack[t+1];
                        p=p+1;
                        break;

                    case 4: //MUL
                        t=t-1;
                        stack[t] = stack[t] * stack[t+1];
                        p=p+1;
                        break;

                    case 5: //DIV (if possible)
                        t=t-1;
                        stack[t] = (stack[t+1] != 0) ? (stack[t]/stack[t+1]) : stack[t];
                        p=p+1;
                        break;

                    case 6: //ODD
                        stack[t] = stack[t] % 2;
                        p=p+1;
                        break;

                    case 7: //MOD
                        t=t-1;
                        stack[t] = stack[t] % stack[t+1];
                        p=p+1;
                        break;

                    case 8: //EQL
                        t=t-1;
                        stack[t] = (stack[t] == stack[t+1]);
                        p=p+1;
                        break;

                    case 9: //NEQ
                        t=t-1;
                        stack[t] = (stack[t] != stack[t+1]);
                        p=p+1;
                        break;

                    case 10: //LSS
                        t=t-1;
                        stack[t] = (stack[t] < stack[t+1]);
                        p=p+1;
                        break;

                    case 11: //LEQ
                        t=t-1;
                        stack[t] = (stack[t] <= stack[t+1]);
                        p=p+1;
                        break;

                    case 12: //GTR
                        t=t-1;
                        stack[t] = (stack[t] > stack[t+1]);
                        p=p+1;
                        break;

                    case 13: //GEQ
                        t=t-1;
                        stack[t] = (stack[t] >= stack[t+1]);
                        p=p+1;
                        break;
                }
                break;

            case 3: //LOD
                stack[t] = stack[vetor[p].a];
                p=p+1;
                break;

            case 4: //STO
                stack[vetor[p].a] = stack[t];
                p=p+1;
                break;

            case 5: //CAL
                stack[0] = 100; //retorno
                stack[1] = SIZE; //link dinamico
                stack[2] = 256; //link estatico

                p = vetor[p].a;
                break;

            case 6: //INC
                t = t+1;
                p=p+1;
                break;

            case 7: //JMP
                p = vetor[p].a;
                break;

            case 8: //JPC
                if(!stack[t])
                    p=vetor[p].a, t=t-1;
                else
                    p=p+1;
                break;

            case 9: //WRT
                printf("STACK[%d] = %d", t, stack[t--]);
                break;

            case 10: //INT
                t = vetor[p].a;
                p=p+1;
                break;
        }

        i++;
    } while (p != 35);

    printf("\n Quantidade de instrucoes:\t%2d\n", i);
    printf(" (p):\t%2d\n", p);
    printf(" (b):\t%2d\n", b);
    printf(" (t):\t%2d\n", t);
    printf("\n POSICOES DA PILHA:\n");
    for(int j=0; j<=t; j++)
        printf("  vetor[%d]: %lld ", j, stack[j]);
    printf("\n");

}

void soma_1_a_10()
{
    printf("\n===============================================================\n");
    printf("\tFUNCAO SOMA DE 1 A 10: \n\n");
    estrutura vetor[20];
    // END
    vetor[0].f = 0;
    vetor[0].l = 0;
    vetor[0].a = 1;
    //MUDANDO O TOPO DA PILHA
    vetor[1].f = 10;
    vetor[1].l = 0;
    vetor[1].a = 5;
    //COLOCANDO O 1 NA PILHA
    vetor[2].f = 1;
    vetor[2].l = 0;
    vetor[2].a = 1;
    //COPIA DO VALOR
    vetor[3].f = 4;
    vetor[3].l = 0;
    vetor[3].a = 3;
    //COLOCANDO O ZERO NA PILHA
    vetor[4].f = 1;
    vetor[4].l = 0;
    vetor[4].a = 0;
    //COPIANDO O VALOR 
    vetor[5].f = 4;
    vetor[5].l = 0;
    vetor[5].a = 4;
    //SUBINDO O VALOR APARA A SOMA
    vetor[6].f = 3;
    vetor[6].l = 0;
    vetor[6].a = 3;
    //FAZENDO A ADICAO
    vetor[7].f = 2;
    vetor[7].l = 0;
    vetor[7].a = 2;
    //TOPO++
    vetor[8].f = 6;
    vetor[8].l = 0;
    vetor[8].a = 0;
    //INCREMENTANDO O VALOR
    vetor[9].f = 3;
    vetor[9].l = 0;
    vetor[9].a = 3;
    //TOPO++
    vetor[10].f = 6;
    vetor[10].l = 0;
    vetor[10].a = 0;
    //SUBINDO O VALOR PARA FAZER A OPEARCAO
    vetor[11].f = 1;
    vetor[11].l = 0;
    vetor[11].a = 1;
    //FAZENDO A OPERACAO
    vetor[12].f = 2;
    vetor[12].l = 0;
    vetor[12].a = 2;
    //GUADANDO O VALOR NA POSICAO SETADA
    vetor[13].f = 4;
    vetor[13].l = 0;
    vetor[13].a = 3;
    //SUBINDO O VALOR
    vetor[14].f = 1;
    vetor[14].l = 0;
    vetor[14].a = 11;
    //SUBINDO O TOPO DA PILHA
    vetor[15].f = 6;
    vetor[15].l = 0;
    vetor[15].a = 0;
    //SINALIZANDO A VARIAVEL
    vetor[16].f = 3;
    vetor[16].l = 0;
    vetor[16].a = 3;
    //VERIFICADO SE DEU NEGATIVO
    vetor[17].f = 2;
    vetor[17].l = 0;
    vetor[17].a = 3;

    //jpc
    vetor[18].f = 8;
    vetor[18].l = 0;
    vetor[18].a = 0;

    //jmp
    vetor[19].f = 7;
    vetor[19].l = 0;
    vetor[19].a = 6;

    interpretado_p_code(vetor);
   printf("\n===============================================================\n");
}

void quadrado_1_a_100()
{
    printf("\n===============================================================\n");
    printf("\tFUNCAO SOMA  DOS QUADRADOS DE 1 A 100: \n");
    estrutura vetor[25];
    //END
    vetor[0].f = 0;
    vetor[0].l = 0;
    vetor[0].a = 1;
    //ALTERANDO O TOPO DA PILHA 
    vetor[1].f = 10;
    vetor[1].l = 0;
    vetor[1].a = 5;
    //COLOCANDO 1 NO  TOPO DA PILHA
    vetor[2].f = 1;
    vetor[2].l = 0;
    vetor[2].a = 1;
    //COPIANDO O CONTADOR
    vetor[3].f = 4;
    vetor[3].l = 0;
    vetor[3].a = 3;
    //COLOCANDO O NUMERO ZERO
    vetor[4].f = 1;
    vetor[4].l = 0;
    vetor[4].a = 0;
    //"ATRIBUINDO" O VALOR ZERO PARA O SOMADOR QUE ESTA NA PILHA NA POSICAO 4
    vetor[5].f = 4;
    vetor[5].l = 0;
    vetor[5].a = 4;
    //ATRIBUINDO O VALOR PARA FAZER A MULTIPLICACAO
    vetor[6].f = 3;
    vetor[6].l = 0;
    vetor[6].a = 3;
    //INCREMENTANDO O TOPO DA PILHA
    vetor[7].f = 6;
    vetor[7].l = 0;
    vetor[7].a = 0;

    //"CONSUMINDO" O VALOR PARA MULTIPLICAR
    vetor[8].f = 3;
    vetor[8].l = 0;
    vetor[8].a = 3;
    //FAZENDO A MULTIPLICACAO
    vetor[9].f = 2;
    vetor[9].l = 0;
    vetor[9].a = 4;
    //FAZENDO A ADICAO
    vetor[10].f = 2;
    vetor[10].l = 0;
    vetor[10].a = 2;
    //INCREMENTANDO O TOPO
    vetor[11].f = 6;
    vetor[11].l = 0;
    vetor[11].a = 0;
    //CARREGANDO O CONTADOR QUE ESTA NA POSICAO 3 DA PILHA
    vetor[12].f = 3;
    vetor[12].l = 0;
    vetor[12].a = 3;
    //INCREMENTANDO O TOPO
    vetor[13].f = 6;
    vetor[13].l = 0;
    vetor[13].a = 0;
    // CARREGANDO PARA FAZER A OPERACAO
    vetor[14].f = 1;
    vetor[14].l = 0;
    vetor[14].a = 1;
    //FAZENDO A ADICAO
    vetor[15].f = 2;
    vetor[15].l = 0;
    vetor[15].a = 2;
    //SALVANDO O VALOR NO CONTADO
    vetor[16].f = 4;
    vetor[16].l = 0;
    vetor[16].a = 3;
    //CARRREGANDO A OPERACAO
    vetor[17].f = 1;
    vetor[17].l = 0;
    vetor[17].a = 101;
    //INCREMENTANDO O TOPO
    vetor[18].f = 6;
    vetor[18].l = 0;
    vetor[18].a = 0;
    //SUBINDO O VALOR DE CONTADOR
    vetor[19].f = 3;
    vetor[19].l = 0;
    vetor[19].a = 3;
    //OPERANÇAO DE SUBITRACAO
    vetor[20].f = 2;
    vetor[20].l = 0;
    vetor[20].a = 3;
    //JPC
    vetor[21].f = 8;
    vetor[21].l = 0;
    vetor[21].a = 0;
    //JMP
    vetor[22].f = 7;
    vetor[22].l = 0;
    vetor[22].a = 6;

    interpretado_p_code(vetor);
  printf("\n===============================================================\n");

}

void cubo_1_a_1000()
{
        printf("\n===============================================================\n");
    printf("\tFUNCAO SOMA  DOS CUBOS DE 1 A 1000: \n");

    estrutura vetor[30];

    //0. END
    vetor[0].f = 0;
    vetor[0].l = 0;
    vetor[0].a = 1;
    //ALTERANDO O TOPO DA PILJA
    vetor[1].f = 10;
    vetor[1].l = 0;
    vetor[1].a = 5;
    //SUBINDO O VALOR 1
    vetor[2].f = 1;
    vetor[2].l = 0;
    vetor[2].a = 1;
    //COPIANDO O VALOR DO CONTADOR
    vetor[3].f = 4;
    vetor[3].l = 0;
    vetor[3].a = 3;
    //COLOCANDO O ZERO
    vetor[4].f = 1;
    vetor[4].l = 0;
    vetor[4].a = 0;
    //COPIANDO PARA O SOMADOR
    vetor[5].f = 4;
    vetor[5].l = 0;
    vetor[5].a = 4;
    //6. SUBINDO O VALOR
    vetor[6].f = 3;
    vetor[6].l = 0;
    vetor[6].a = 3;
    //INCREMENTANDO O TOPO
    vetor[7].f = 6;
    vetor[7].l = 0;
    vetor[7].a = 0;
    //CARREHGANDO O VALOR
    vetor[8].f = 3;
    vetor[8].l = 0;
    vetor[8].a = 3;
    //INCREMENTANDO O TOPO
    vetor[9].f = 6;
    vetor[9].l = 0;
    vetor[9].a = 0;
    //SUBINDO O VALOR
    vetor[10].f = 3;
    vetor[10].l = 0;
    vetor[10].a = 3;
    //FAZNEDO A MULTIPLICACAO
    vetor[11].f = 2;
    vetor[11].l = 0;
    vetor[11].a = 4;
    //FAZENDO A MULTIPLICACAO
    vetor[12].f = 2;
    vetor[12].l = 0;
    vetor[12].a = 4;
    //FAZENDO A ADICAO
    vetor[13].f = 2;
    vetor[13].l = 0;
    vetor[13].a = 2;
    //INCERMENTANDO O TOPO DA PILHA
    vetor[14].f = 6;
    vetor[14].l = 0;
    vetor[14].a = 0;
    //SUBINDO O CONTADOR
    vetor[15].f = 3;
    vetor[15].l = 0;
    vetor[15].a = 3;
    //INCREMENTANDO O TOPO DA PILHA
    vetor[16].f = 6;
    vetor[16].l = 0;
    vetor[16].a = 0;
    //CARREGANDO O VALOR PARA FAZER A OPERACAO
    vetor[17].f = 1;
    vetor[17].l = 0;
    vetor[17].a = 1;
    //FAZENDO A ADICAO
    vetor[18].f = 2;
    vetor[18].l = 0;
    vetor[18].a = 2;
    //SALVADO O CONTADOR
    vetor[19].f = 4;
    vetor[19].l = 0;
    vetor[19].a = 3;

    vetor[20].f = 1;
    vetor[20].l = 0;
    vetor[20].a = 1001;
    //INCREMENTANDO O TOPO DA PILHA
    vetor[21].f = 6;
    vetor[21].l = 0;
    vetor[21].a = 0;
    //SUBINDO CONTADOR
    vetor[22].f = 3;
    vetor[22].l = 0;
    vetor[22].a = 3;
    //FAZANDO O SUB AGORA
    vetor[23].f = 2;
    vetor[23].l = 0;
    vetor[23].a = 3;
    //jpc
    vetor[24].f = 8;
    vetor[24].l = 0;
    vetor[24].a = 0;
    //jmp
    vetor[25].f = 7;
    vetor[25].l = 0;
    vetor[25].a = 6;
   
    interpretado_p_code(vetor);
    printf("=================================================================\n");
}

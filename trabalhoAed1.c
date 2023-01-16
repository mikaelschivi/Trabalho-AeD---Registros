#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
// Alunos: Mikael Schivittz & Yuri Vergara
//         140571             155478
//
//     Trabalho de AeD 1 4o Bimestre
//


typedef struct{
    char name[80];
    int power;
    int def;
    int life;
} Personagem;

int ataque( Personagem p1, Personagem p2){
    int dano = p1.power - p2.def;
    if (dano<0){
        dano=0;
    }
    return dano;
}

void status( Personagem p1){
    printf("%s", p1.name);
    printf(" poder=%d",  p1.power);
    printf(" defesa=%d", p1.def);
    printf(" vida=%d\n", p1.life);
}

Personagem inimigo(){
    srand(1);
    Personagem enemy = {"Zed", 0, 0, 0};

    enemy.power = 20 + rand() % 10;
    enemy.def = 10 + rand() % 20;
    enemy.life = 20 + rand() % 30;

    return enemy;
}

Personagem genInimigo(){
    char str[4]="Zed";
    Personagem enemy = {"Zed", 0, 0, 0};

    strcpy( enemy.name, str);
    enemy.power = 20 + rand() % 10;
    enemy.def = 10 + rand() % 20;
    enemy.life = 20 + rand() % 30;

    return enemy;
}

int main(){
    Personagem p1 = {"Xil", 54, 12, 100};
    Personagem p2 = {"Yen", 40, 20, 100};

    printf("\nAtividade 1\n");
    status( p1);
    status( p2);

    printf("\nAtividade 2\n");
    printf("ataque de %s a %s vai causar %i de dano\n", p1.name, p2.name, ataque( p1, p2));
    printf("ataque de %s a %s vai causar %i de dano\n", p2.name, p1.name, ataque( p2, p1));

    printf("\nAtividade 3\n");
    do{
        p2.life = p2.life - ataque(p1, p2);
        p1.life = p1.life - ataque(p2, p1);
        status( p1);
        status( p2);
    } while(p2.life>0 && p1.life>0);

    if(p1.life<0) printf("Yen venceu\n");   
    if(p2.life<0) printf("Xil venceu\n");

    printf("\nAtividade 4\n");
    Personagem zed = inimigo();
    p1.life = 100;
    
    status(zed);
    printf("\n");
    do{
        zed.life = zed.life - ataque(p1, zed);
        p1.life = p1.life - ataque(zed, p1);
        status( p1);
        status( zed);
    } while(zed.life>0 && p1.life>0);

    if(p1.life<0) printf("Zed venceu\n");   
    if(zed.life<0) printf("Xil venceu\n");

    printf("\nAtividade 5\n");
    Personagem zed1 = genInimigo();
    Personagem zed2 = genInimigo();
    Personagem zed3 = genInimigo();
    Personagem zed4 = genInimigo();
    Personagem zed5 = genInimigo();

    Personagem arr[5] = {zed1, zed2, zed3, zed4, zed5};
        p1.life = 100;

    printf("Status dos novos Zeds\n");
    for( int i=0; i<5; i++){
        status(arr[i]);
    }
    printf("\n");
    for( int i=0; i<5; i++){
        do{
            arr[i].life = arr[i].life - ataque(p1, arr[i]);
            p1.life = p1.life - ataque(arr[i], p1);
            status( p1);
            status( arr[i]);
        } while(p1.life>0 && arr[i].life>0);

        if(p1.life<0) printf("Batalha %i: %s venceu\n\n", i+1, arr[i].name);
        if(arr[i].life<0) printf("Batalha %i: Xil venceu\n\n", i+1);
    }
    
    return 0;
}
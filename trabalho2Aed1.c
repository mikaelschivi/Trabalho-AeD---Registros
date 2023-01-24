#include <stdio.h>
#include <stdlib.h>

//  Trabalho 2 AeD.1
//
//  Mikael Schivittz  &  Yuri Vergara
//  1405781           &  155478 
//

typedef struct{
    char *pi;
    int n;

} vetorInteligente;

vetorInteligente cria(){
    vetorInteligente vi;
    vi.pi=NULL;
    vi.n=0;

    return vi;
}

vetorInteligente adiciona( vetorInteligente vetorAntigo, int x ){
    vetorInteligente vetorNovo;

    vetorNovo.pi = malloc( (vetorAntigo.n+1)*sizeof(int) );

    for( int i=0; i<vetorAntigo.n; i++){
        vetorNovo.pi[i]=vetorAntigo.pi[i];
    }
    vetorNovo.pi[vetorAntigo.n] = x;

    vetorNovo.n = vetorAntigo.n+1;

    free(vetorAntigo.pi);
    return vetorNovo;
}

void mostra( vetorInteligente vi ){
    printf("bin: ");
    for( int i=0; i<vi.n; i++){
        int iterator= vi.n-(i+1);
        printf("%d", vi.pi[ iterator ] );
    }
    printf("\n");
}

vetorInteligente destroi( vetorInteligente vetor ){
    free( vetor.pi );
    vetor.pi=NULL;
    vetor.n=0;    
}

int converter( unsigned long long int decimal){
    int digitoBinario;

    if (decimal%2==0){
        digitoBinario=0;

        return digitoBinario;
    }
    else{
        digitoBinario=1;

        return digitoBinario;
    }
}

int main(){
    unsigned long long int dec;
    int digBin;
    printf("dec: ");
    scanf("%llu", &dec);

    vetorInteligente lista = cria();

    while (dec>=1){
        digBin = converter(dec);
        lista = adiciona( lista, digBin);

        dec = dec/2;
    }
    
    mostra(lista);
    destroi(lista);
    return 0;
}
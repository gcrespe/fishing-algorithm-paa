//
//  This solution consists of an O(nlogn) complexity algorithm 
//  that combines heapSort and binarySearch
//  Giuliano Crespe
//  743543
//

#include <stdio.h>

void heapify(int arr[], int qtdPeixes, int i);
void heapSort(int arr[], int qtdPeixes);
int buscaBinaria(int arr[], int esq, int dir, int produtoTotal, int p1);
void checkPossiblePrize(int peixesPessoa1[], int peixesPessoa2[], int produtoTotal, int qtdPeixes);


void heapify(int arr[], int qtdPeixes, int i){

    int esq = 2 * i + 1;
    int dir = 2 * i + 2;
    int maior = i;
 
    
    if (dir < qtdPeixes && arr[dir] > arr[maior])
        maior = dir;
    if (esq < qtdPeixes && arr[esq] > arr[maior])
        maior = esq;
 
    if (maior != i) {
        
        int temp = arr[maior];
        arr[maior] = arr[i];
        arr[i] = temp;
 
        heapify(arr, qtdPeixes, maior);
        
    }
    
    
}
 
void heapSort(int arr[], int qtdPeixes){

    for (int i = qtdPeixes / 2 - 1; i >= 0; i--)
        heapify(arr, qtdPeixes, i);
 
    for (int i = qtdPeixes - 1; i > 0; i--) {

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);

    }

}

int buscaBinaria(int arr[], int esq, int dir, int produtoTotal, int p1){
    
    while (esq <= dir) {

        int meio = esq + (dir - esq) / 2;
 
        if (arr[meio]*p1 == produtoTotal){
            return meio;
        }
        if (arr[meio]*p1 < produtoTotal){
            esq = meio + 1;
        }else dir = meio - 1;

    }

    return -1;
    
}

void checkPossiblePrize(int peixesPessoa1[], int peixesPessoa2[], int produtoTotal, int qtdPeixes){
    
    for(int i = 0; i < qtdPeixes; i++){
        
        if(buscaBinaria(peixesPessoa2, 0, qtdPeixes-1, produtoTotal, peixesPessoa1[i]) != -1){
            
            printf("SIM\n");
            return;
            
        }
            
    }
    
    printf("NAO\n");
    return;

}



int main(){
    
    int qtdPeixes, produtoTotal;
    
    scanf("%d", &qtdPeixes);
    scanf("%d", &produtoTotal);
    
    int peixesPessoa1[qtdPeixes], peixesPessoa2[qtdPeixes];
    
    for(int i = 0; i<qtdPeixes; i++) scanf("%d",&peixesPessoa1[i]);
    for(int i = 0; i<qtdPeixes; i++) scanf("%d",&peixesPessoa2[i]);
    
    
    heapSort(peixesPessoa1, qtdPeixes);
    heapSort(peixesPessoa2, qtdPeixes);
    
    checkPossiblePrize(peixesPessoa1, peixesPessoa2, produtoTotal, qtdPeixes);
    
    return 0;
}

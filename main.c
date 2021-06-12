/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

void heapify(int arr[], int n, int i){
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 

    if (l < n && arr[l] > arr[largest])
        largest = l;
 

    if (r < n && arr[r] > arr[largest])
        largest = r;
 

    if (largest != i) {
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
 
        heapify(arr, n, largest);
    }
}
 
void heapSort(int arr[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
 
        heapify(arr, i, 0);
    }
}

int binarySearch(int arr[], int l, int r, int x, int p1){
    
    while (l <= r) {
        int m = l + (r - l) / 2;
 
        if (arr[m]*p1 == x)
            return m;
 
        if (arr[m]*p1 < x)
            l = m + 1;
 
        else
            r = m - 1;
    }

    return -1;
    
}

void checkPossiblePrize(int peixesPessoa1[], int peixesPessoa2[], int produtoTotal, int qtdPeixes){
    
    for(int i = 0; i<qtdPeixes; i++){
        
        if(binarySearch(peixesPessoa2, 0, qtdPeixes-1, produtoTotal, peixesPessoa1[i]) != -1){
            
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

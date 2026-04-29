#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrsig;
};

int menu(){
    int opc;
    printf("\n Ingrese una opcion \n");
    printf("1: Crear datos\n");
    printf("2: Mostrar datos\n");
    printf("3: Liberar\n");
    printf("4: salir\n");
    scanf("%d", &opc);
    return opc;
}

struct Dato * crear(){
    struct Dato *ptrtemp=NULL;
    int dato;
    ptrtemp = (struct Dato *) malloc(sizeof(struct Dato));

    if(ptrtemp==NULL){
        printf("No se reservo memoria");
        return NULL;
    }else{
        printf("Ingrese un dato: ");
        scanf("%d", &dato);
        ptrtemp->d=dato;
        ptrtemp->ptrsig=NULL;
        return ptrtemp;
    }
}

void mostrar(struct Dato **ptr){
    struct Dato *ptraux = *ptr;

    if(*ptr == NULL){
        printf("No hay datos guardados\n");
    
        }
    else{
        printf("\nLista de datos:\n");

        while(ptraux != NULL){
            printf("%d -> ", ptraux->d);
            ptraux = ptraux->ptrsig;
        }

        
        }
}
void liberar(struct Dato **ptr){
    struct Dato *ptraux;
    // cuando hay solo un nodo
    if(*ptr==NULL)
        printf("No hay datos guardados\n");
                    
    if((*ptr)->ptrsig==NULL){
        free(*ptr);
        *ptr=NULL;
    }else{//cuando hay mas de un nodo 
        ptraux=*ptr;

        while(ptraux->ptrsig->ptrsig != NULL){
            ptraux = ptraux->ptrsig;
        }
        free(ptraux->ptrsig);
        ptraux->ptrsig = NULL;
    }
    printf("Eliminado\n");
}

void salida(struct Dato **ptr){
    struct Dato *ptraux;
    if(*ptr == NULL){
        printf("No hay datos guardados\n");
    }
        ptraux = *ptr;
    while(ptraux != NULL){
        *ptr=ptraux->ptrsig;
        free(ptraux);
    }
    *ptr= NULL;
    printf("Nodos eliminados\n");
}

int main(){
    struct Dato *ptr=NULL;
    struct Dato *ptrtemp=NULL;
    struct Dato *ptraux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: 
                    ptrtemp=crear();
                    if(ptrtemp==NULL)
                        printf("No se creo el nuevo dato");
                    else{
                        if(ptr==NULL)
                            ptr=ptrtemp;
                        else{
                            ptraux=ptr;
                            while(ptraux->ptrsig!=NULL){
                                ptraux=ptraux->ptrsig;
                            }
                            ptraux->ptrsig=ptrtemp;
                        }
                    }
                    break;
            case 2: 
                    mostrar(&ptr);
                    break;
            case 3: 
                    liberar(&ptr);
                    break;
            case 4: 
                    salida(&ptr);
                    break;
        }
    }while(op!=4);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrsig;
};

int menu(){
    int opc;
    printf("\n Ingrese una opcion \n");
    printf("1: Crear datos\n");
    printf("2: Mostrar datos\n");
    printf("3: Liberar\n");
    printf("4: salir\n");
    scanf("%d", &opc);
    return opc;
}

struct Dato * crear(){
    struct Dato *ptrtemp=NULL;
    int dato;
    ptrtemp = (struct Dato *) malloc(sizeof(struct Dato));

    if(ptrtemp==NULL){
        printf("No se reservo memoria");
        return NULL;
    }else{
        printf("Ingrese un dato: ");
        scanf("%d", &dato);
        ptrtemp->d=dato;
        ptrtemp->ptrsig=NULL;
        return ptrtemp;
    }
}

void mostrar(struct Dato **ptr){
    struct Dato *ptraux = *ptr;

    if(*ptr == NULL){
        printf("No hay datos guardados\n");
        return;
    }

    printf("\nLista de datos:\n");

    while(ptraux != NULL){
        printf("%d\n ", ptraux->d);
        ptraux = ptraux->ptrsig;
    }

    printf("\n");
}
void liberar(struct Dato **ptr){
    struct Dato *ptraux;
    // cuando hay solo un nodo
    if(*ptr==NULL)
        printf("No hay datos guardados\n");
                    
    if((*ptr)->ptrsig==NULL){
        free(*ptr);
        *ptr=NULL;
    }else{//cuando hay mas de un nodo 
        ptraux=*ptr;

        while(ptraux->ptrsig->ptrsig != NULL){
            ptraux = ptraux->ptrsig;
        }
        free(ptraux->ptrsig);
        ptraux->ptrsig = NULL;
    }
    printf("Eliminado\n");
}

void salida(struct Dato **ptr){
    struct Dato *ptraux;
    if(*ptr == NULL){
        printf("No hay datos guardados\n");
    }

    if((*ptr)->ptrsig == NULL){
        free(*ptr);
        *ptr = NULL;
    }else{

        while(*ptr != NULL){
            ptraux = *ptr;
            *ptr=(*ptr)->ptrsig;
            free(ptraux);
        }
    }
    *ptr= NULL;
    printf("Nodos eliminados\n");
}

int main(){
    struct Dato *ptr=NULL;
    struct Dato *ptrtemp=NULL;
    struct Dato *ptraux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: ptrtemp=crear();
                    if(ptrtemp==NULL)
                        printf("No se creo el nuevo dato");
                    else{
                        if(ptr==NULL)
                            ptr=ptrtemp;
                        else{
                            ptraux=ptr;
                            while(ptraux->ptrsig!=NULL){
                                ptraux=ptraux->ptrsig;
                            }
                            ptraux->ptrsig=ptrtemp;
                        }
                    }
                    break;
            case 2: mostrar(&ptr);
                    break;
            case 3: liberar(&ptr);
                    break;
            case 4: salida(&ptr);
                    break;
        }
    }while(op!=4);

    return 0;
}

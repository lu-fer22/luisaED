#include <stdio.h>

struct arbol{
    int dato;
    struct arbol *izq, *der;
};

int menu(){
    int opc;
    printf("1: Insertar");
    printf("2: Salir");
    scanf("%d", &opc);
}

struct Dato * crearNodo(){
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

int main(void){
    struct arbol*raiz, *ptrTemp, *ptrAux;
    raiz=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1: printf("Insertar");
                    ptrTemp=crearNodo();
                    if(ptrTemp==NULL){
                        printf("No se creo el nuevo nodo");
                    }else{
                        if(raiz==NULL)
                            raiz=ptrTemp;
                        else{
                            ptrAux=raiz;
                            if(ptrTemp->dato < ptrAux->dato){
                                while(ptrAux->izq!=NULL){
                                    ptrAux=ptrAux->izq;
                                    if(ptrTemp->dato < ptrAux->dato){
                                        ptrAux->izq=ptrTemp;
                                    }
                                }
                                ptrAux->izq=ptrTemp;
                            }else{
                                while(ptrAux->der!=NULL){
                                    ptrAux=ptrAux->der;
                                    if(ptrTemp->dato > ptrAux->dato){
                                        ptrAux->der=ptrTemp;
                                    }
                                }
                                ptrAux->der=ptrTemp;
                            }
                        }
                    }
                    break;

            case 2: printf("Salir...");
                    break;

            default:printf("Opcion no valida");
                    break;
        }
    }while(op !=2);
}

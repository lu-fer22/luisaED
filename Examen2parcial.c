//LUISA FERNANDA MARTINEZ JUAREZ

#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int n;
    struct Dato *Sig;
    struct Dato *Ant;
};

int menu(){
    int opc;
    printf("\n Ingrese una opcion \n");
    printf("1: Insertar\n");
    printf("2: Mostrar\n");
    printf("3: Liberar\n");
    printf("4: Salir\n");
    scanf("%d",&opc);
    return opc;
}

struct Dato *nuevoDato(void){
   struct Dato *ptrTemp=NULL;
    int dato;
    ptrTemp = (struct Dato *) malloc(sizeof(struct Dato));

    if(ptrTemp==NULL){
        printf("No se reservo memoria\n");
        return NULL;
    }else{
        printf("Ingrese el dato: ");
        scanf("%d", &dato);
        ptrTemp->n=dato;
        ptrTemp->Sig=NULL;
        ptrTemp->Ant=NULL;
        return ptrTemp;
    }
}


int main(){
    struct Dato *ptr=NULL, *ptrNew=NULL, *ptrUlt=NULL,*ptrTemp=NULL, *ptrAux=NULL;
    int op=0;

    do{
        op=menu();
        switch(op){
            case 1:
                ptrNew=nuevoDato();
                if(ptrNew==NULL){
                    printf("No se creo el nuevo nodo\n");
                }else{
                    if(ptr==NULL){
                        ptr=ptrNew;
                        ptr->Sig=ptr;
                        ptr->Ant=ptr;
                    }else{
                        ptrUlt = ptr->Ant;

                        ptrNew->Sig = ptr;
                        ptrNew->Ant = ptrUlt;

                        ptrUlt->Sig = ptrNew;
                        ptr->Ant = ptrNew;
                    }
                }
                break;

            case 2:
                if(ptr == NULL){
                    printf("No hay nodos\n");
                }else{
                    ptrAux = ptr;

                    do{
                        printf("%d <-> ", ptrAux->n);
                        ptrAux = ptrAux->Sig;
                    }while(ptrAux != ptr);

                }
                break;

            case 3:
                if(ptr == NULL){
                    printf("No hay nodos\n");
                    break;
                }

                if((ptr)->Sig == ptr){
                    free(ptr);
                    ptr = NULL;
                }else{
                    ptrAux = ptr;

                    while(ptrAux->Sig->Sig != ptr){
                        ptrAux = ptrAux->Sig;
                    }

                    ptrTemp = ptrAux->Sig;

                    ptrAux->Sig = ptr;
                    ptr->Ant = ptrAux;

                    free(ptrTemp);
                }
                printf("Nodo eliminado\n");
                
                break;

            case 4:
                printf("salida\n");
                if(ptr == NULL){
                    printf("No hay datos guardados\n");
                }
                ptrAux = ptr;

                    while(ptrAux->Sig->Sig != ptr){
                        ptrAux = ptrAux->Sig;
                    }

                    ptrTemp = ptrAux->Sig;

                    ptrAux->Sig = ptr;
                    ptr->Ant = ptrAux;

                    free(ptrTemp);
                ptr= NULL;
                printf("Nodos eliminados\n");
                break;

            default:
                printf("Opcion invalida\n");

        }
    }while(op!=4);
        return 0;
}  

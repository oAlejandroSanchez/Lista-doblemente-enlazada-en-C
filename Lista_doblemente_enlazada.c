//Definición de las librerías
#include "stdio.h"
#include "stdlib.h"
#include <ctype.h>

//Definición de las variables
typedef struct _Nodo{
	
	char *nombre;
	char numero_de_cuenta[9];
	struct _Nodo *siguiente;
	struct _Nodo *anterior;
	
}Lista;

Lista *lista_principio = NULL;
Lista *lista_final = NULL;

//Definición de las funciones secundarias
void Inciso_a(void);
Lista *Ingresar_elementos(Lista *, Lista *);

void Inciso_b(void);
void Mostrar_elementos(void);
void Ordenado_inciso_a(void);
void Orden_inverso_inciso_b(void);
void Ultima_opcion(void);

void Inciso_c(void);
void Eliminar_datos(void);
void Eliminacion_del_principio(void);
void Eliminacion_del_final(void);
void Error_al_eliminar(void);

int Inciso_d(void);

void Opcion_por_defecto(void);

//Función principal del programa
int main(void){
	
	char opcion, respuesta;
	
	do{
		system("cls");
		
		printf("\t\tBASE DE DATOS.\n\n");
		printf("Elige una de las siguientes opciones: ");
		printf("\na)Ingresar datos.");
		printf("\nb)Mostrar elementos de la base de datos.");
		printf("\nc)Eliminar elementos.");
		printf("\nd)Salir.");
		
		printf("\n\nOpci%cn: ",162);
		fflush(stdin);
		scanf("%c",&opcion);
		
		opcion = tolower(opcion);
	
		switch(opcion){
			
			case 'a':{
			
				Inciso_a();
			
				break;
			}
			case 'b':{
				
				Inciso_b();
			
				break;
			}
			case 'c':{
				
				Inciso_c();
				
				break;
			}
			case 'd':{
				
				Inciso_d();
				
				break;
			}
			default:{
				
				Opcion_por_defecto();
				
				break;
			}
		}
		
		printf("\n\n\nSi desea salir del programa oprima 'N',\nen caso contrario oprima cualquier tecla.");
		fflush(stdin);
		scanf("%c",&respuesta);
		
		respuesta = toupper(respuesta);
		
	}while(respuesta != 'N');
	
	return 0;
	
}

//Función del inciso (a), perminte ingresar elementos a la base de datos
void Inciso_a(void){
	
	Lista *nodo_auxiliar = NULL;
	char cuenta;
	int Maximo = 0;
	
	system("cls");
	
	nodo_auxiliar = (Lista *)malloc(sizeof(Lista));
	
	printf("\t\tINGRESAR DATOS\n\n");
	printf("Nombre: ");
	nodo_auxiliar->nombre = (char *)malloc(sizeof(char)*100);
	fflush(stdin);
	scanf("%[^\n]s",nodo_auxiliar->nombre);
	
	printf("N%cmero de cuenta: ",163);
	fflush(stdin);
	while(((cuenta = getchar()) != '\n') && (Maximo < 9)){
		
		if((cuenta == '0') || (cuenta == '1') || (cuenta == '2') || (cuenta == '3') || (cuenta == '4') || (cuenta == '5') || (cuenta == '6') || (cuenta == '7') || (cuenta == '8') || (cuenta == '9')){
			
			nodo_auxiliar->numero_de_cuenta[Maximo++] = cuenta;
			
		}else{
			
			continue;
			
		}
		
	}
	
	nodo_auxiliar->numero_de_cuenta[9] = '\0';
	
	printf("\n\n\n\nLos elementos ingresados son: ");
	printf("\nNombre: %s", nodo_auxiliar->nombre);
	printf("\nN%cmero de cuenta: %s", 163, nodo_auxiliar->numero_de_cuenta);
	
	if(lista_principio == NULL){
		
		lista_principio = Ingresar_elementos(nodo_auxiliar,lista_principio);
		lista_final = lista_principio;
		
	}else{
		
		lista_final = Ingresar_elementos(nodo_auxiliar,lista_principio);
		
	}
		
}

//Esta función permite ingresar los elementos a la lista
Lista *Ingresar_elementos(Lista *nodo_auxiliar, Lista *lista){
	
	if(lista == NULL){
		
		nodo_auxiliar->anterior = NULL;
		nodo_auxiliar->siguiente = NULL;
		lista = nodo_auxiliar;
		
	}else{
		
		nodo_auxiliar->siguiente = NULL;
		nodo_auxiliar->anterior = lista;
		lista->siguiente = nodo_auxiliar;
		lista = nodo_auxiliar;
		
	}
	
	return(lista);
	
}

//La función del inciso (b) verifica si la lista esta llena o vacía,
//dependiendo del resultado se mostrara un mensaje o la lista con los elementos
void Inciso_b(void){
	
	system("cls");
	
	if((lista_principio == NULL) && (lista_final == NULL)){
		
		printf("\n\n\n\t\t***************************************************\n");
		printf("\t\t*                                                 *\n");
		printf("\t\t*      No hay elementos en la base de datos.      *\n");
		printf("\t\t*                                                 *\n");
		printf("\t\t***************************************************\n");
		
	}else{
		
		Mostrar_elementos();
		
	}
}

//Esta función muestra en pantalla la lista con los elementos ingresados
void Mostrar_elementos(void){
	
	char opcion, respuesta;
	
	do{
		
		system("cls");
		
		printf("Elige una opci%cn: \n\n", 162);
		printf("\na)Mostrar lista en orden en fueron ingresados.");
		printf("\nb)Mostrar lista en orden inverso al fueron ingresados.");
		
		printf("\n\nOpci%cn: ", 162);
		fflush(stdin);
		scanf("%c", &opcion);
		
		opcion = tolower(opcion);
		
		switch(opcion){
			
			case 'a':{
				
				Ordenado_inciso_a();
				
				break;
			}
			case 'b':{
				
				Orden_inverso_inciso_b();
				
				break;
			}
			default:{
				
				Ultima_opcion();
				
				break;
			}
			
		}
		
		printf("\n\nSi desea realizar otra acci%cn oprima cualquier tecla, en caso contrario\noprima una 'N'.", 162);
		printf("\nOpci%cn: ", 162);
		fflush(stdin);
		scanf("%c", &respuesta);
		
		respuesta = toupper(respuesta);
		
	}while(respuesta != 'N');
	
	system("cls");
	
	printf("\n*****************************************************************************\n");
	
}

//Esta opción muestra en pantalla los elementos de la lista
//en el orden en el que fueron ingresados
void Ordenado_inciso_a(void){
	
	Lista *mostrar_elementos = NULL;
	
	system("cls");
	
	mostrar_elementos = lista_principio;
	
	while(mostrar_elementos != NULL){
		
		printf("\nNombre: %s", mostrar_elementos->nombre);
		printf("\nN%cmero de cuenta: %s", 163, mostrar_elementos->numero_de_cuenta);
		mostrar_elementos = mostrar_elementos->siguiente;
		
	}
	
}

//Esta opción muestra en pantalla los elementos de la lista
//en orden inverso en el que fueron ingresados
void Orden_inverso_inciso_b(void){
	
	Lista *mostrar_elementos = NULL;
	
	system("cls");
	
	mostrar_elementos = lista_final;
	
	while(mostrar_elementos != NULL){
		
		printf("\nNombre: %s", mostrar_elementos->nombre);
		printf("\nN%cmero de cuenta: %s", 163, mostrar_elementos->numero_de_cuenta);
		mostrar_elementos = mostrar_elementos->anterior;
		
	}
	
}

//Esta opción muestra un mensaje de error, en caso de que el usuario
//se haya equivocado
void Ultima_opcion(void){
	
	system("cls");
	
	printf("\n\n\n\t\t***************************************\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*          Opci%cn inv%clida.           *\n", 162, 160);
	printf("\t\t*         Vuelve a intentarlo         *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t***************************************\n");
	
}

//Esta función permite borrar elementos de la lista, ya sea por el principio
//o por el final de la lista
void Inciso_c(void){
	
	system("cls");
	
	if((lista_principio == NULL) && (lista_final == NULL)){
		
		printf("\n\n\n\t\t*************************************************\n");
		printf("\t\t*                                               *\n");
		printf("\t\t*      La base de datos se encunetra vac%ca.     *\n", 161);
		printf("\t\t*                                               *\n");
		printf("\t\t*************************************************\n");
		
	}else{
		
		Eliminar_datos();
				
	}
	
}

//En caso de que ambas banderas no tengan el mismo valor, el usuario podrá
//elegir en donde quiere que se haga la eliminación; sin embargo, está la 
//eliminación solo puede hacerse por el inicio o por el final de la lista
void Eliminar_datos(void){
	
	char opcion, respuesta;
	
	do{
		
		system("cls");
		
		if(lista_principio == lista_final){
			
			lista_principio = NULL;
			lista_final = NULL;
			break;
			
		}else{
	
			printf("Elige una de las siguientes opciones: \n");
			printf("\na)Eliminar el primer elemento de la lista.");
			printf("\nb)Eliminar el %cltimo elemento de la lista.", 163);
			
			printf("\nOpci%cn: ", 162);
			fflush(stdin);
			scanf("%c", &opcion);
			
			opcion = tolower(opcion);
			
			switch(opcion){
				
				case 'a':{
					
					Eliminacion_del_principio();
					
					break;
				}
				case 'b':{
					
					Eliminacion_del_final();
					
					break;
				}
				default:{
					
					Error_al_eliminar();
					
					break;
				}
				
			}
			
		}
		
		printf("\n\n\nSi requiere eliminar otro dato oprima cualquier tecla, en caso contrario\noprima una 'N'.");
		fflush(stdin);
		scanf("%c", &respuesta);
		
		respuesta = toupper(respuesta);
	
	}while(respuesta != 'N');
	
	system("cls");
	
	printf("***********************************************************************\n");
	
	printf("\n\n\n\t\t***************************************************\n");
	printf("\t\t*                                                 *\n");
	printf("\t\t*        Dato(s) eliminado(s) exitosamente        *\n");
	printf("\t\t*                                                 *\n");
	printf("\t\t***************************************************\n");
	
}

//Esta función elimina el primer nodo que se encuentra en la lista
void Eliminacion_del_principio(void){
	
	Lista *Eliminar_elemento = NULL;
	
	Eliminar_elemento = lista_principio;
	lista_principio = lista_principio->siguiente;
	free(Eliminar_elemento);
	lista_principio->anterior = NULL;
	
}

//Esta función elimina el último nodo que se encuentra en la lista
void Eliminacion_del_final(void){
	
	Lista *Eliminar_elemento = NULL;
	
	Eliminar_elemento = lista_final;
	lista_final = lista_final->anterior;
	free(Eliminar_elemento);
	lista_final->siguiente = NULL;
	
}

//Si el usuario se equivoca al introducir la opción, se mostrará unn mensaje de
//error en la pantalla
void Error_al_eliminar(void){
	
	system("cls");
	
	printf("\n\n\n\t\t***************************************\n");
	printf("\t\t*                                     *\n");
	printf("\t\t*          Opci%cn inv%clida.           *\n", 162, 160);
	printf("\t\t*         Vuelve a intentarlo         *\n");
	printf("\t\t*                                     *\n");
	printf("\t\t***************************************\n");
	
}

//Esta función permite al usuario salir del programa principal
int Inciso_d(void){
	
	exit(1);
	
}

//Esta función manda un mensaje al usuario que ha cometido un error
//al intentar seleccionar una de las opciones que se muestran en el menú
void Opcion_por_defecto(void){
	
	system("cls");
	
	printf("\n\n\n\t\t****************************************\n");
	printf("\t\t*                                      *\n");
	printf("\t\t*          Opci%cn inv%clida.            *\n",162,160);
	printf("\t\t*         Vuelve a intentarlo.         *\n");
	printf("\t\t*                                      *\n");
	printf("\t\t****************************************\n");

}

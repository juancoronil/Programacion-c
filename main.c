#include <stdio.h>
#include <stdlib.h>
/* funciones: 
 * ingresar datos del empleado (hecho)
 * mostrar todos los empleados por DNI, nombre y apellido (hecho)
 * mostrar todos los empleados por DNI, nombre y apellido nacidos en un año especificado por el cliente (hecho)
 * editar los datos de una persona especifica (elegida/o por DNI) (hecho)
 * mostrar todos los datos de una persona especifica (elegida/o por DNI) (hecho)
 * mostrar el empleado mas joven (hecho)
 * los DNIs deben ser unicos (hecho)
 */

typedef struct{
	char nombre[20];
	char apellido[20];
	int dni;
	int numeroTelefono;
	int diaCump;
	int mesCump;
	int anioCump;
}tipo_agenda;

void presionaCon(int aux){
	printf("Escriba cualquier numero para continuar\n");
	scanf("%d", &aux);
}

void dniComparar(int aux, tipo_agenda agendaArray[], int empleadoMax, int empleadoCas){
	
	scanf("%d",&aux);
	
	int dniDetector = 1;
	
	while(dniDetector == 1){
		
		for(int j = 0; j <= empleadoMax; j++){
			
			if(aux == agendaArray[j].dni){
				printf("El DNI %d ya se uso, escriba otro:\n");
				scanf("%d",&aux);
				
				dniDetector = 1;
				
				break;
			}else{
				dniDetector = 0;
			}
			
		}
		
	}
	
	agendaArray[empleadoCas].dni = aux;
	
}

void dniCompararAlt(int aux, tipo_agenda agendaArray[], int empleadoMax, int empleadoCas, int i){
	
	scanf("%d",&aux);
	
	int dniDetector = 1;
	
	while(dniDetector == 1){
		
		for(int j = 0; j <= empleadoMax; j++){
			
			if(aux == agendaArray[j].dni){
				printf("El DNI %d ya se uso, escriba otro:\n");
				scanf("%d",&aux);
				
				dniDetector = 1;
				
				break;
			}else{
				dniDetector = 0;
			}
			
		}
		
	}
	
	agendaArray[i].dni = aux;
	
}

void mostrarMenor(tipo_agenda agendaArray[], int empleadoMax, int menorCasilla){
	int buscarMenor = 0;
	
	for(int j = 0; j < empleadoMax; j++){
		
		if(buscarMenor < (agendaArray[j].anioCump * 365) + (agendaArray[j].mesCump * 30) + agendaArray[j].diaCump){
			buscarMenor = (agendaArray[j].anioCump * 365) + (agendaArray[j].mesCump * 30) + agendaArray[j].diaCump;
			menorCasilla = j;
		}
		
	}
	
	printf("Empleado mas joven:\n\n");
	printf("DNI: %d\n", agendaArray[menorCasilla].dni);
	printf("Numero Tel: %d\n", agendaArray[menorCasilla].numeroTelefono);
	printf("Nombre: %s\n", agendaArray[menorCasilla].nombre);
	printf("Apellido: %s\n", agendaArray[menorCasilla].apellido);
	printf("Fecha de nacimiento: %d/%d/%d\n\n", agendaArray[menorCasilla].diaCump, agendaArray[menorCasilla].mesCump, agendaArray[menorCasilla].anioCump);
}

// mostrarMenor(agendaArray, empleadoMax, menorCasilla);

int main(int argc, char *argv[]) {
	
	tipo_agenda agendaArray[101];
	int detector, aux;
	int empleadoMax = 0, empleadoCas = 0;
	int ANIO_ACTUAL = 2021;
	int menorCasilla = 0;
	
	while(detector != 1){
		printf("1 para cerrar el programa\n");
		printf("2 para aniadir un empleado al sistema\n");
		printf("3 para mostrar la lista de empleados general\n");
		printf("4 para buscar un empleado por anio\n");
		printf("5 para editar los datos de un empleado (buscar por DNI)\n");
		printf("6 para mostrar todos los datos de una persona por DNI\n");
		printf("7 para mostrar a la persona mas joven\n");
		scanf("%d",&detector);
		
		switch(detector){
			default:{
				printf("Advertencia: Opcion no encontrada, escriba cualquier numero para continuar:\n");
				scanf("%d",&aux);
				break;
			}
			case 1:{
				/* dummy case */
				break;
			}
			case 2:{
				printf("DNI del empleado: ");
				dniComparar(aux, agendaArray, empleadoMax, empleadoCas);
				printf("Numero telefonico del empleado: ");
				scanf("%d",&agendaArray[empleadoCas].numeroTelefono);
				printf("Nombre del empleado: ");
				scanf("%s",&agendaArray[empleadoCas].nombre);
				printf("Apellido del empleado: ");
				scanf("%s",&agendaArray[empleadoCas].apellido);
				printf("Fecha de nacimiento:\n");
				printf("Dia: ");
				scanf("%d",&agendaArray[empleadoCas].diaCump);
				printf("Mes: ");
				scanf("%d",&agendaArray[empleadoCas].mesCump);
				printf("Anio: ");
				scanf("%d",&agendaArray[empleadoCas].anioCump);
				
				empleadoCas++;
				break;
			}
			case 3:{
				printf("\n");
				for(int i = 0; i < empleadoMax; i++){
					printf("DNI: %d\n", agendaArray[i].dni);
					printf("Nombre: %s\n", agendaArray[i].nombre);
					printf("Apellido: %s\n", agendaArray[i].apellido);
					printf("\n");
				}
				printf("Escriba un numero para continuar\n");
				scanf("%d",&aux);
				break;
			}
			case 4:{
				int anioBuscar;
				printf("Escriba el anio del empleado que quiera buscar:\n");
				scanf("%d",&anioBuscar);
				for(int i = 0; i < empleadoMax; i++){
					if(agendaArray[i].anioCump == anioBuscar){
						printf("DNI: %d\n", agendaArray[i].dni);
						printf("Nombre: %s\n", agendaArray[i].nombre);
						printf("Apellido: %s\n", agendaArray[i].apellido);
					}
				}
				presionaCon(aux);
				break;
			}
			case 5:{
				int dniBuscar;
				printf("Escriba el DNI del empleado a editar:\n");
				scanf("%d",&dniBuscar);
				for(int i = 0; i < empleadoMax; i++){
					if(agendaArray[i].dni == dniBuscar){
						printf("\nDatos del empleado:\n");
						
						printf("DNI: %d\n", agendaArray[i].dni);
						printf("Nuevo DNI: ");
						dniCompararAlt(aux, agendaArray, empleadoMax, empleadoCas, i);
						
						printf("Numero Tel: %d\n", agendaArray[i].numeroTelefono);
						printf("Nuevo numero Tel: ");
						scanf("%d",&agendaArray[i].numeroTelefono);
						
						printf("Nombre: %s\n", agendaArray[i].nombre);
						printf("Nuevo nombre: ");
						scanf("%s",&agendaArray[i].nombre);
						
						printf("Apellido: %s\n", agendaArray[i].apellido);
						printf("Nuevo apellido: ");
						scanf("%s",&agendaArray[i].apellido);
						
						printf("Fecha de nacimiento: %d/%d/%d\n\n", agendaArray[i].diaCump, agendaArray[i].mesCump, agendaArray[i].anioCump);
						printf("Nuevo dia: ");
						scanf("%d",&agendaArray[i].diaCump);
						printf("Nuevo mes: ");
						scanf("%d",&agendaArray[i].mesCump);
						printf("Nuevo anio: ");
						scanf("%d",&agendaArray[i].anioCump);
						presionaCon(aux);
					}
				}
				break;
			}
			case 6:{
				int dniBuscar;
				printf("Escribe el DNI del empleado que quieres buscar:\n");
				scanf("%d",&dniBuscar);
				for(int i = 0; i < empleadoMax; i++){
					if(agendaArray[i].dni == dniBuscar){
						printf("\n");
						printf("DNI del empleado: %d\n", agendaArray[i].dni);
						printf("Nombre del empleado: %s\n", agendaArray[i].nombre);
						printf("Apellido del empleado: %s\n", agendaArray[i].apellido);
						printf("Numero Tel del empleado: %d\n", agendaArray[i].numeroTelefono);
						printf("Fecha de nacimiento: %d/%d/%d\n", agendaArray[i].diaCump, agendaArray[i].mesCump, agendaArray[i].anioCump);
						printf("\n");
						presionaCon(aux);
					}
				}
				break;
			}
			case 7:{
				mostrarMenor(agendaArray, empleadoMax, menorCasilla);
				presionaCon(aux);
				break;
			}
		}
		
		if(empleadoCas == 100){
			empleadoCas = 0;
		}
		
		if(empleadoMax < empleadoCas && empleadoMax < 100){
			empleadoMax = empleadoCas;
		}
		
		system("cls");
	}
	
	return 0;
}

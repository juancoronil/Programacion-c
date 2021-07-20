#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

/* Calculadora
 * Funciones:
 * Funciones basicas de la calculadora (hecho)
 * Funciones matematicas (hecho)
 * Funciones trigonometricas (seno, coseno, tangente, cotangente) (hecho)
 * Funciones de historial (hecho)
 * (OPCIONAL) Funciones de calidad de vida (mostrar cual fue el ultimo tipo de operacion delante del resultado)
 */

int main(int argc, char *argv[]) {
	
	tipo_historialAlt historialCalAlt[101];
	tipo_historial historialCal[101];
	int detector, i = 0, imax = 0;
	int detectorAlt, iAlt = 0, iAltMax = 0;
	int zero = 0;
	float numeroA = 0, numeroB = 0, numeroResultado = 0, numeroAux;
	
	while(detector != 6){
		
		printf("A: %.2f\n",numeroA);
		printf("B: %.2f\n",numeroB);
		printf("Resultado: %.2f\n",numeroResultado);
		printf("\n");
		printf("Funciones basicas:\n");
		printf("1 agregar valor a la variable A\n");
		printf("2 agregar valor a la variable B\n");
		printf("3 para cambiar A y B entre si\n");
		printf("4 copiar el valor del resultado a A\n");
		printf("5 copiar el valor del resultado a B\n");
		printf("6 para cerrar el programa\n");
		printf("\n");
		printf("Funciones matematicas:\n");
		printf("7 para sumar (A + B)\n");
		printf("8 para restar (A - B)\n");
		printf("9 para multiplicar (A x B)\n");
		printf("10 para dividir (A / B)\n");
		printf("11 para potenciar (A ^ B)\n");
		printf("12 para conseguir la raiz cuadrada de A\n");
		printf("13 para conseguir el seno de A\n");
		printf("14 para conseguir el coseno de A\n");
		printf("15 para conseguir el tangente de A\n");
		printf("16 para conseguir el contangente de A\n");
		printf("17 para imprimir historial\n");
		scanf("%d",&detector);
		
		switch(detector){
			case 1:{
				printf("A: ");
				scanf("%f",&numeroA);
				break;
			}
			case 2:{
				printf("B: ");
				scanf("%f",&numeroB);
				break;
			}
			case 3:{
				numeroAux = numeroA;
				numeroA = numeroB;
				numeroB = numeroAux;
				break;
			}
			case 4:{
				numeroA = numeroResultado;
				break;
			}
			case 5:{
				numeroB = numeroResultado;
				break;
			}
			case 6:{
				// dummy case, necesario para que no salte al default al cerrar
				break;
			}
			case 7:{
				numeroResultado = numeroA + numeroB;
				historialCal[i].numeroH_A = numeroA;
				historialCal[i].numeroH_B = numeroB;
				historialCal[i].numeroH_Resultado = numeroResultado;
				historialCal[i].simboloH = '+';
				i++;
				break;
			}
			case 8:{
				numeroResultado = numeroA - numeroB;
				historialCal[i].numeroH_A = numeroA;
				historialCal[i].numeroH_B = numeroB;
				historialCal[i].numeroH_Resultado = numeroResultado;
				historialCal[i].simboloH = '-';
				i++;
				break;
			}
			case 9:{
				numeroResultado = numeroA * numeroB;
				historialCal[i].numeroH_A = numeroA;
				historialCal[i].numeroH_B = numeroB;
				historialCal[i].numeroH_Resultado = numeroResultado;
				historialCal[i].simboloH = '*';
				i++;
				break;
			}
			case 10:{
				numeroResultado = numeroA / numeroB;
				historialCal[i].numeroH_A = numeroA;
				historialCal[i].numeroH_B = numeroB;
				historialCal[i].numeroH_Resultado = numeroResultado;
				historialCal[i].simboloH = '/';
				i++;
				break;
			}
			case 11:{
				numeroResultado = pow(numeroA, numeroB);
				historialCal[i].numeroH_A = numeroA;
				historialCal[i].numeroH_B = numeroB;
				historialCal[i].numeroH_Resultado = numeroResultado;
				historialCal[i].simboloH = '^';
				i++;
				break;
			}
			case 12:{
				numeroResultado = sqrt(numeroA);
				historialCalAlt[iAlt].numeroAltH_A = numeroA;
				historialCalAlt[iAlt].numeroAltH_Resultado = numeroResultado;
				historialCalAlt[iAlt].simboloAltH = 'R';
				iAlt++;
				break;
			}
			case 13:{
				numeroResultado = asin(numeroA);
				historialCalAlt[iAlt].numeroAltH_A = numeroA;
				historialCalAlt[iAlt].numeroAltH_Resultado = numeroResultado;
				historialCalAlt[iAlt].simboloAltH = 'S';
				iAlt++;
				break;
			}
			case 14:{
				numeroResultado = acos(numeroA);
				historialCalAlt[iAlt].numeroAltH_A = numeroA;
				historialCalAlt[iAlt].numeroAltH_Resultado = numeroResultado;
				historialCalAlt[iAlt].simboloAltH = 'C';
				iAlt++;
				break;
			}
			case 15:{
				numeroResultado = atan(numeroA);
				historialCalAlt[iAlt].numeroAltH_A = numeroA;
				historialCalAlt[iAlt].numeroAltH_Resultado = numeroResultado;
				historialCalAlt[iAlt].simboloAltH = 'T';
				iAlt++;
				break;
			}
			case 16:{
				numeroResultado = atan(numeroA) * -1.0;
				historialCalAlt[iAlt].numeroAltH_A = numeroA;
				historialCalAlt[iAlt].numeroAltH_Resultado = numeroResultado;
				historialCalAlt[iAlt].simboloAltH = 'G';
				iAlt++;
				break;
			}
			case 17:{
				for(int j = imax -1; j >= 0; j--){
					printf("%.2f %c %.2f = %.2f\n",historialCal[j].numeroH_A, historialCal[j].simboloH, historialCal[j].numeroH_B, historialCal[j].numeroH_Resultado);
				}
				printf("\n");
				for(int j = iAltMax -1; j >= 0; j--){
					printf("%c %.2f = %.2f\n", historialCalAlt[j].simboloAltH, historialCalAlt[j].numeroAltH_A, historialCalAlt[j].numeroAltH_Resultado);
				}
				printf("Escriba cualquier numero para continuar:\n");
				scanf("%d",&numeroAux);
				break;
			}
			default:{
				printf("ERROR: Opcion selecionada no existe. Escriba cualquier numero para continuar:\n");
				scanf("%d",&numeroAux);
				break;
			}
		}
		
		if(imax < i && imax < 100){
			imax = i;
		}
		
		if(iAltMax < iAlt && iAltMax < 100){
			iAltMax = iAlt;
		}
		
		if(i == 100){
			i = 0;
		}
		
		if(iAlt == 100){
			iAlt = 0;
		}
		
		system("cls");
		
	}
	
	return 0;
}

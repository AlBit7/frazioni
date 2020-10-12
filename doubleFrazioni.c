#include <stdio.h>

int * mkFrazione(double numero, double TOLLERANZA){

	static int frazione[2];
	int numeroIntero = (int)numero;
	numero -= numeroIntero;

	int numeratoreBasso   = 0, numeratoreAlto   = 1;
	int denominatoreBasso = 1, denominatoreAlto = 1;
	int numeratoreMedio      , denominatoreMedio   ;

	while(1){

		numeratoreMedio   = numeratoreAlto   + numeratoreBasso;
		denominatoreMedio = denominatoreAlto + denominatoreBasso;

		if(denominatoreMedio * (numero + TOLLERANZA) < numeratoreMedio){
			// alto deventa medio (perchè il numero è tra basso e medio)
			numeratoreAlto   = numeratoreMedio;
			denominatoreAlto = denominatoreMedio;
		}

		else if(denominatoreMedio * (numero - TOLLERANZA) > numeratoreMedio){
			// basso deventa medio (perchè il numero è tra medio e alto)
			numeratoreBasso   = numeratoreMedio;
			denominatoreBasso = denominatoreMedio;
		}

		else{
			frazione[0] = numeroIntero * denominatoreMedio + numeratoreMedio;
			frazione[1] = denominatoreMedio;
			return frazione;
		}

	}

}

int main(void){

	double num;

	printf("Inserisci il numero decimale: ");
	scanf("%lf", &num);

	int * frazione = mkFrazione(num, 0.000000001);

	printf("%d / %d\n\n", *(frazione), *(frazione + 1));

}
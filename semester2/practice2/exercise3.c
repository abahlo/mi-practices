// L�sung zu Termin2
// Aufgabe 2
// Namen: __________; ___________
// Matr.: __________; ___________
// vom :  __________
// 

#include "pio.h"
#include "aic.h"
#include "pmc.h"

int main(void)
{
 	StructPIO* piobaseB = PIOB_BASE; // Basisdadresse 
	piobaseB->PIO_PER = LED1|LED2|KEY1|KEY2;	// aktiviere Register LED's 
	piobaseB->PIO_OER = LED1|LED2;// Otput enable auf LED 1 & 2
	piobaseB->PIO_ODR = KEY1|KEY2; // Input enable auf KEYs
	
	StructPMC* pmcbase = PMC_BASE; // Clock erstellen (nicht unbedingt notwendig)
	pmcbase->PMC_PCER = 0x4000; // PIOB auf 1 setzen im PMC
	
	
	while( 1 ) {
	
	// Schleife
	int x = 0;
		while( x < 250000 ) {
  			if( !( piobaseB->PIO_PDSR & KEY1 ) ) { // Pin status register abfragen
  			  piobaseB->PIO_CODR = LED1; // Set output data = LED an
  			}
  			if ( !( piobaseB->PIO_PDSR & KEY2 ) ) {
			    piobaseB->PIO_SODR = LED1; // Clear output data = LED aus
  			}
			x++;
		}
		
		if( !( piobaseB->PDSR & LED2 ) {
			piobaseB->PIO_SODR = LED2; // LED 2 ist an, ausmachen!
		}
		if( ( piobaseB->PDSR & LED2 ) {
			piobaseB->BIO_CODR = LED2; // LED 2 ist aus, einschalten!
		}
	}
	
	return 0;
}

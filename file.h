/********************************************************************************
* file.h: Inneh�ller funktionalitet f�r skrivning samt l�sning av text till
*         filer via externa funktioner.
********************************************************************************/
#ifndef FILE_H_
#define FILE_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* file_write: Skriver ett textstycke till angiven fils�kv�g. Eventuellt tidigare
*             inneh�ll skrivs �ver. Om filen inte g�r att �ppna returneras 
*             felkod 1, annars returneras 0.
* 
*             - filepath: Pekare till fils�kv�gen.
*             - s       : Pekare till textstycken som skall skrivas.
********************************************************************************/
int file_write(const char* filepath, 
               const char* s);

/********************************************************************************
* file_append: Bifogar ett textstycke till angiven fils�kv�g. Eventuellt tidigare
*              inneh�ll bibeh�lls och det nya inneh�ll placeras l�ngst ned i 
*              filen. Om filen inte g�r att �ppna returneras felkod 1, annars 
*              returneras 0.
*
*              - filepath: Pekare till fils�kv�gen.
*              - s       : Pekare till textstycken som skall skrivas.
********************************************************************************/
int file_append(const char* filepath,
                const char* s);

/********************************************************************************
* file_read: L�ser in inneh�ll fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen. Om filen inte g�r att �ppna returneras felkod 1,
*            annars returneras 0.
*
*            - filepath: Pekare till fils�kv�gen.
********************************************************************************/
int file_read(const char* filepath);

#endif /* FILE_H_ */
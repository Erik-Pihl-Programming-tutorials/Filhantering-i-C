/********************************************************************************
* file.h: Innehåller funktionalitet för skrivning samt läsning av text till
*         filer via externa funktioner.
********************************************************************************/
#ifndef FILE_H_
#define FILE_H_

/* Inkluderingsdirektiv: */
#include <stdio.h>

/********************************************************************************
* file_write: Skriver ett textstycke till angiven filsökväg. Eventuellt tidigare
*             innehåll skrivs över. Om filen inte går att öppna returneras 
*             felkod 1, annars returneras 0.
* 
*             - filepath: Pekare till filsökvägen.
*             - s       : Pekare till textstycken som skall skrivas.
********************************************************************************/
int file_write(const char* filepath, 
               const char* s);

/********************************************************************************
* file_append: Bifogar ett textstycke till angiven filsökväg. Eventuellt tidigare
*              innehåll bibehålls och det nya innehåll placeras längst ned i 
*              filen. Om filen inte går att öppna returneras felkod 1, annars 
*              returneras 0.
*
*              - filepath: Pekare till filsökvägen.
*              - s       : Pekare till textstycken som skall skrivas.
********************************************************************************/
int file_append(const char* filepath,
                const char* s);

/********************************************************************************
* file_read: Läser in innehåll från angiven filsökväg rad för rad och skriver
*            ut i terminalen. Om filen inte går att öppna returneras felkod 1,
*            annars returneras 0.
*
*            - filepath: Pekare till filsökvägen.
********************************************************************************/
int file_read(const char* filepath);

#endif /* FILE_H_ */
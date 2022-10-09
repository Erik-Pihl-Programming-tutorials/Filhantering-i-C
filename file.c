/********************************************************************************
* file.c: Innehåller funktionsdefinitioner för skrivning och läsning till filer.
********************************************************************************/
#include "file.h"

/********************************************************************************
* file_write: Skriver ett textstycke till angiven filsökväg. Eventuellt tidigare
*             innehåll skrivs över. Om filen inte går att öppna returneras
*             felkod 1, annars returneras 0.
*
*             - filepath: Pekare till filsökvägen.
*             - s       : Pekare till textstycken som skall skrivas.
********************************************************************************/
int file_write(const char* filepath,
               const char* s)
{
   FILE* ostream = fopen(filepath, "w");

   if (!ostream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
      return 1;
   }
   else
   {
      fprintf(ostream, "%s", s);
      fclose(ostream);
      return 0;
   }
}

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
                const char* s)
{
   FILE* ostream = fopen(filepath, "a");

   if (!ostream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
      return 1;
   }
   else
   {
      fprintf(ostream, "%s", s);
      fclose(ostream);
      return 0;
   }
}

/********************************************************************************
* file_read: Läser in innehåll från angiven filsökväg rad för rad och skriver
*            ut i terminalen. Om filen inte går att öppna returneras felkod 1,
*            annars returneras 0.
*
*            - filepath: Pekare till filsökvägen.
********************************************************************************/
int file_read(const char* filepath)
{
   FILE* istream = fopen(filepath, "r");

   if (!istream)
   {
      fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
      return 1;
   }
   else
   {
      char s[100] = { '\0' };

      while (fgets(s, sizeof(s), istream))
      {
         printf("%s", s);
      }

      fclose(istream);
      return 0;
   }
}
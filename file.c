/********************************************************************************
* file.c: Inneh�ller funktionsdefinitioner f�r skrivning och l�sning till filer.
********************************************************************************/
#include "file.h"

/********************************************************************************
* file_write: Skriver ett textstycke till angiven fils�kv�g. Eventuellt tidigare
*             inneh�ll skrivs �ver. Om filen inte g�r att �ppna returneras
*             felkod 1, annars returneras 0.
*
*             - filepath: Pekare till fils�kv�gen.
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
* file_append: Bifogar ett textstycke till angiven fils�kv�g. Eventuellt tidigare
*              inneh�ll bibeh�lls och det nya inneh�ll placeras l�ngst ned i
*              filen. Om filen inte g�r att �ppna returneras felkod 1, annars
*              returneras 0.
*
*              - filepath: Pekare till fils�kv�gen.
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
* file_read: L�ser in inneh�ll fr�n angiven fils�kv�g rad f�r rad och skriver
*            ut i terminalen. Om filen inte g�r att �ppna returneras felkod 1,
*            annars returneras 0.
*
*            - filepath: Pekare till fils�kv�gen.
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
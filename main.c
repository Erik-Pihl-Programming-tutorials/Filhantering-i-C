/********************************************************************************
* main.c: Definition av externa funktioner f�r filhantering. Dessa funktioner
*         behandlades inte under lektionen, utan utg�r ett komplement f�r de
*         som �r intresserade.
*
*         Filhantering genomf�rs enligt nedan i C:
*
*         1. �ppna filen f�r skrivning via en filpekare via funktionen fopen.
*            Passera fils�kv�gen samt vad som skall ske, exempelvis "w" (write)
*            f�r skrivning till fil, d�r eventuellt tidigare inneh�ll i filen
*            raderas, "a" (append) f�r bifogande av text l�ngst bak i filen
*            samt "r" (read) f�r l�sning av inneh�ll p� fils�kv�gen.
*
*            Antag att en pekare d�pt filepath pekare p� fils�kv�gen data.txt
*            enligt nedan:
*
*            const char* filepath = "data.txt";
*
*            F�r att �ppna filen data.txt f�r skrivning via filpekaren ostream
*            kan f�ljande instruktion anv�ndas:
*
*            FILE* ostream = fopen(filepath, "w");
*
*            F�r att �ppna filen data.txt f�r l�sning via filpekaren istream
*            kan f�ljande instruktion anv�ndas:
*
*            FILE* istream = fopen(filepath, "r");
*
*         2. Kontrollera att filen gick att �ppna. Om det inte gick att �ppna
*            filen returneras en nullpekare fr�n filen fopen. Om filpekaren �r
*            null (kontrolleras via NULL eller 0), s� gick filen inte att �ppna.
*            Skriv d� ut ett felmeddelande, f�redragsvis till standardfelenheten
*            stderr via funktionen fprintf, men utskrift i terminalen via printf
*            �r ocks� okej). Avsluta funktionen ifall filen inte gick att �ppna.
*
*            F�r att kontrollera att filen data.txt gick att �ppna f�r skrivning
*            via ovanst�ende filpekare ostream kan f�ljande if-sats anv�ndas:
*
*            if (!ostream)
*            {
*               fprintf(stderr, "Could not open file at path %s!\n", filepath);
*            }
*
*         3. Om filen gick att �ppna, genomf�r antingen skrivning/bifogande av
*            text via funktionen fprintf eller fill�sning via funktionen fgets.
*
*            Vid skrivning/bifogande av text, anv�nd filpekaren ostream som
*            f�rsta argument f�ljt av det som skall skrivas till filen
*            (f�rutom f�rsta argumentet fungerar fprintf exakt samma som printf).
*
*            Som exempel, f�r att skriva/bifoga inneh�llet lagrat i en intvariabel
*            x till filen data.txt kan f�ljande instruktion anv�ndas:
*
*            fprintf(ostream, "%d", x);
*
*            Vid l�sning, deklarera en str�ng f�r lagring av text fr�n varje
*            inl�st rad. En l�mplig storlek �r 100 tecken, vilket kan
*            implementeras via en str�ng d�pt s, som initieras till tom vid
*            start via nedanst�ende instruktion:
*
*            char s[100] = { '\0' };
*
*            En given rad kan l�sas ur filen via anrop av funktionen fgets:
*
*            fgets(s, (int)sizeof(s), istream);
*
*            Vid anropet till inl�sningsfunktionen fgets passeras en pekare
*            till str�ngen d�r aktuell inl�st rad tempor�rt skall lagras,
*            sedan passeras str�ngens storlek (s� att h�gst s� m�nga tecken
*            som str�ngen rymmer l�ses in) f�ljt av filpekaren till filen
*            d�r l�sningen skall ske fr�n.
*
*            Ovanst�ende instruktion medf�r dock enbart l�sning av en enda
*            rad. F�r att l�sa in rad f�r rad tills filen �r slut kan
*            ovanst�ende instruktion anv�nds som villkor till en while-sats:
*
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*            }
*
*            Eftersom en pekare till den textsnutt som l�ses in returneras
*            fr�n funktionen fgets och en nullpekare returneras n�r filen �r
*            slut s� medf�r ovanst�ende while-sats att s� l�nge rad l�ses in
*            s� fortg�r while-satsen.
*
*            Eftersom varje inl�st rad lagras i str�ngen s s� kan utskrift
*            av denna rad genomf�ras via formatspecificare %s:
*
*            printf("%s", s);
*
*            Nedanst�ende while-sats medf�r d�rmed inl�sning av varje rad i
*            aktuell fil, f�ljt av utskrift i terminalen:
*
*            while (fgets(s, (int)sizeof(s), istream))
*            {
*               printf("%s", s);
*            }
*
*         4. St�ng filen efter slutf�rd l�sning/skrivning via anrop av
*            funktionen fclose. Passera anv�nd filpekare. Som exempel, f�r
*            att st�nga filen data.txt, som tidigare �ppnades f�r skrivning
*            via filpekaren ostream, kan filen st�ngas via f�ljande instruktion:
*
*            fclose(ostream);
*
*         OBS! F�r att anv�nda funktionen fopen i Visual Studio, h�gerklicka
*         p� projektnamnet, scrolla ned till Properties. I den nya ruta som
*         kommer upp, klicka p� C/C++ -> Preprocessor. I rutan m�rkt
*         Preprocessor Definitions, skrivs in _CRT_SECURE_NO_WARNINGS.
*         Se till att ha ett blanksteg mellan f�reg�ende definition och
*         denna nya definition.
*
*         Tips: F�r att enkelt l�sa inneh�llet skrivet till en viss fil utan
*         att anv�nda en filskrivningsfunktion, klicka p� Tools -> Command Line
*         -> Developer Command Prompt. I den terminal som dyker upp, skriv
*         kommandot type f�ljt av filens namn f�r att skriva ut inneh�llet.
*         Som exempel, f�r att l�sa inneh�llet fr�n filen numbers.txt, skriv
*         f�ljande kommando (utan dollartecknet):
*
*         $ type numbers.txt
********************************************************************************/
#include "file.h"

/********************************************************************************
* int_array_print: Skriver ut heltal lagrade i en array av angiven storlek till
*                  angiven utstr�m, d�r standardutenhet stdout anv�nds som
*                  default f�r utskrift i terminalen (s�som printf g�r).
* 
*                  - self   : Pekare till arrayen vars inneh�ll skall skrivas ut.
*                  - size   : Arrayens storlek, dvs. antalet heltal den rymmer.
*                  - ostream: Pekare till angiven utstr�m (default = stdout).
********************************************************************************/
void int_array_print(const int* self,
                     const int size,
                     FILE* ostream)
{
   if (size <= 0) return;
   if (!ostream) ostream = stdout;

   fprintf(ostream, "--------------------------------------------------------------------------------\n");

   for (int i = 0; i < size; ++i)
   {
      fprintf(ostream, "%d\n", self[i]);
   }

   fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
   return;
}

/********************************************************************************
* main: Skriver tv� textsnuttar till filen "data.txt" och l�ser sedan inneh�llet
*       fr�n filen rad f�r rad och skriver ut i terminalen. D�refter skrivs tio
*       heltal lagrade i en array till filen "numbers.txt", vars inneh�ll sedan
*       l�ses in rad f�r rad och skrivs ut i terminalen.
********************************************************************************/
int main(void)
{
   file_write("data.txt", "Do you see this? This is written by calling the function file_write!\n");
   file_append("data.txt", "This line is appended to the file by calling the function file_append!\n");
   file_read("data.txt");

   const int data[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
   FILE* ostream = fopen("numbers.txt", "w");

   int_array_print(data, 10, ostream);
   fclose(ostream);
   file_read("numbers.txt");
   
   return 0;
}
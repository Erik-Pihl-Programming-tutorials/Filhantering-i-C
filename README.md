# Filhantering i C
Demonstration av skrivning och läsning till filer via egenskapade funktioner.

Filen file.h innehåller deklaration av funktioner file_write, file_append samt file_read, som används för att skriva, bifoga samt läsa text från en
given filsökväg. Filen file.c innehåller motsvarande funktionsdefinitioner.

Filen main.c demonstrerar filskrivning och filläsning via anrop av de tre tidigare nämnda funktionerna.
Först skrivs en rad med text till filen "data.txt" via anrop av funktionen file_write. Sedan bifogas ytterligare en rad till samma fil via anrop av
funktionen file_append. Filens innehåll läses sedan rad för rad och skrivs ut i terminalen via anrop av funktionen file_read. 

I filen main.c demonstreras också hur filpekare kan användas som ingående argument för att skriva innehåll lagrat i arrayer och dylikt. Detta
demonstreras via en funktion döpt int_array_print, som skriver ut heltal lagrade i en int-array till angiven filsökväg, där standardutenhet stdout
används som default för utskrift i terminalen likt printf. Därmed kan stdout eller en nullpekare (NULL eller 0) passeras som tredje argument för att
skriva ut innehållet i terminalen.

Se video tutorial här:
https://youtu.be/kuKHSnTTcuM
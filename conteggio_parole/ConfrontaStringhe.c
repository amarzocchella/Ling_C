//ConfrontaStringhe.c
#include <stdio.h>
#include <string.h>
main()
{
char stringa1[20], stringa2[20];
printf("inserisci la prima stringa: ");
scanf("%s", stringa1);
printf("inserisci la seconda stringa: ");
scanf("%s", stringa2);
if (strcmp(stringa1, stringa2)== 0)
printf("le due stringhe sono uguali");
else if (strcmp(stringa1, stringa2) < 0)
printf("%s < %s", stringa1, stringa2);
else
printf("%s > %s", stringa1, stringa2);
}

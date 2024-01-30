#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char abecedario[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
//utilizo un arreglo pero para mas eficiencia de busqueda puedo utilizar un arbol

int retornarPosicionLetraEnAbecedario(char letra);
char retornarUnaLetraCifrada(char letra,int saltos);
char* retornarMensajeCifrado(char mensaje[],int validos,int saltos);
char retornarUnaLetraDescifrada(char letra, int saltos);
char* retornarMensajeDescifrado(char mensajeCifrado[],int validos, int saltos);

int main()
{
    int saltos=0, validos;
    char mensaje[100];


    puts("\t\tCifrado cesar");

    puts("Ingrese la longitud de saltos que quiere hacer: ");
    scanf("%i",&saltos); //que solo se puedan ingresar hasta 26



    puts("Ingrese el mensaje a cifrar [100 max]: ");
    fflush(stdin);
    gets(mensaje);


    validos=strlen(mensaje);



    char* mensajeCifrado= retornarMensajeCifrado(tolower(mensaje),validos,saltos);

    char*mensajeDescifrado= retornarMensajeDescifrado(mensajeCifrado,validos,saltos);

    printf("Mensaje cifrado: %s \n",mensajeCifrado);
    puts("");
    printf("Mensaje descifrado: %s \n",mensajeDescifrado);
    return 0;
}

int retornarPosicionLetraEnAbecedario(char letra)
{
    int pos=-1,i=0;
    if(isalpha(letra) !=0) //si es una letra
    {
        while(letra != abecedario[i])
        {
            i++;
        }
        pos=i;
    }

    return pos;
}

char retornarUnaLetraCifrada(char letra,int saltos)
{
    int posLetraReal=retornarPosicionLetraEnAbecedario(letra);

    if(posLetraReal == -1) // si no es una letra
    {
        return letra;
    }
    int posLetraCifrada=(posLetraReal+saltos)%26;



    return abecedario[posLetraCifrada];
}


char* retornarMensajeCifrado(char mensaje[],int validos,int saltos)
{
    char* mensajeCifrado=(char*)malloc(sizeof(char)*validos);


    for(int i=0; i < validos; i++)
    {
        mensajeCifrado[i]=retornarUnaLetraCifrada(mensaje[i],saltos);
    }

   mensajeCifrado[validos]='\0'; //caracter especial que se utiliza para saber cuando termina una cadena de texto y lo pongo en la ultima posicion debido a que no esta

    return mensajeCifrado;
}

char retornarUnaLetraDescifrada(char letra, int saltos)
{
    int posLetraCifrada=retornarPosicionLetraEnAbecedario(letra);

    if(posLetraCifrada == -1) // si no es una letra
    {
        return letra;
    }

    int posLetraReal=(posLetraCifrada- saltos)%26; //si los saltos son mayores a 26 debo reducirlos a un rango al que este dentro de las posiciones del abecedario

    if(posLetraReal < 0)
    {
        posLetraReal= 26 + posLetraReal; //lo pongo en suma ya que es negativo
        //si la posLetraReal es negativa significa que da la vuelta al abecedario de manera inversa
        //por lo tanto le sumo 26 y le sumo posLetraReal(que es negativo) y de esa forma obtengo la posicion de letra que sobrepasa el abecedario de forma inversa
    }

    return abecedario[posLetraReal];
}


char* retornarMensajeDescifrado(char mensajeCifrado[],int validos, int saltos)
{
    char* mensajeDescifrado= (char*)malloc(sizeof(char)*validos);
    for(int i=0; i < validos; i++)
    {
        mensajeDescifrado[i]=retornarUnaLetraDescifrada(mensajeCifrado[i],saltos);
    }

    mensajeDescifrado[validos]='\0'; //caracter especial que se utiliza para saber cuando termina una cadena de texto y lo pongo en la ultima posicion debido a que no esta

    return mensajeDescifrado;
}



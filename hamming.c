
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


/** 
    Essa função recebe os dados lidos como parâmetro e retorna o quadro utilizando o código de Hamming.

*/
int gerarPacote(char bitentrada[63]){
     
     int n=0;
     int i=0;
     int j=1;
     int k=0;
     int resto;
     char cont;
     int resul=0;
     char bitsaida[72];
     
     strcpy(bitsaida, "");
     
     n=strlen(bitentrada);
     
     //Posiciona os bits da mensagem em posicoes que nao sejam 2^m
     while (i<=n){
          
           if (((k+1)==j)&&(i<n)){
               bitsaida[k]='?';
               j=j*2;   
                      
           }
           else{               
                bitsaida[k]=bitentrada[i];
                //Aqui ele pega cada posicao e faz um XOR com as posicoes diferentes de 2^m e onde o bit vale 1
                if (bitsaida[k]=='1'){
                   resul = (k+1) ^ resul;
                }
                i++;
                
           } 
           k=k+1;
           
           
     }

     //O numero que obtivemos como resultado eh um decimal, temos que convertê-lo para binario

     i=1;
     while (resul>0){
           resto = resul%2;
           //A medida que ele faz a conversao, ele ja vai inserindo os bits nas posicoes 2^m
           if (resto==0){
              bitsaida[i-1]='0';         
           }
           else{
                bitsaida[i-1]='1';    
           }
           resul=resul/2;
           i=i*2;          
     }
     
     //A conversao pode gerar um numero com uma menor quantidade de bits, e faltarem alguns bits para preencher, entao o que falta 
     // eh preenchido com zeros.
     n=strlen(bitsaida);
     i=0;
     while (i<=n){
           if(bitsaida[i]=='?'){
               bitsaida[i]='0';                     
           } 
           i++;  
     }
     
     printf("Quadro de saida: %s\n\n", bitsaida);
        
     printf("Deseja realizar novamente a operacao? (s ou n)\n");
     getchar();
     scanf("%c", &cont);
     
     if ((cont=='s')||(cont=='S')){
             return 0;                   
     } 
     else{
          return 1;     
     }
                     
} 





/** A funcao main ira ler os bits de entrada e chamar a funcao para que a operacao seja realizada*/
int main(){
    int n=0;
    int i;
    int erro;
    char cont;
    char bitentrada[63];  
    int continua=1; 
     
    do{  
        continua=1;  
        system("cls");
        printf("##     ##    ###    ##     ## ##     ## #### ##    ##  ######  \n##     ##   ## ##   ###   ### ###   ###  ##  ###   ## ##    ##  \n##     ##  ##   ##  #### #### #### ####  ##  ####  ## ##        \n######### ##     ## ## ### ## ## ### ##  ##  ## ## ## ##   #### \n##     ## ######### ##     ## ##     ##  ##  ##  #### ##    ##  \n##     ## ##     ## ##     ## ##     ##  ##  ##   ### ##    ##  \n##     ## ##     ## ##     ## ##     ## #### ##    ##  ######\n");
        printf(" -- Geracao de um quadro com a codificacao de Hamming -- \n\n");                    
    
    //Leitura dos bits de entrada
        printf("Digite os bits de entrada(No maximo 64 bits):\n");
        scanf("%s", bitentrada); 
    
    //Essa parte do código verifica se foram digitados somente bits    
        
        
        do{   
            erro=0; 
            i=0;
            n=strlen(bitentrada);
            while ((erro==0)&&(i<n)){
                if ((bitentrada[i]!='0')&&(bitentrada[i]!='1')){
                   erro=1;                                               
                }
                i++;
                
            }
            if (erro==1){
               //Leitura dos bits novamente
               printf("O numero digitado nao esta em binario!\n");
               printf("Digite os bits de entrada(No maximo 64 bits):\n");
               scanf("%s", bitentrada);                            
                         
            }
            
        }while (erro==1);
        
        //Chama a funcao para a relizar a codificacao de hamming
    
        continua = gerarPacote(bitentrada);
        
        
        
        
        
          
         
    }while (continua==0);
    
    
    system("pause");
    
     return 0;   
}

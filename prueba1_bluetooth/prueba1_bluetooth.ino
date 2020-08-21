/*
  Autor: Luis F.
  Fecha: 25/08/16
  -----------------------------------------------------------------------------------------------
            |  TEST1:                                                                            
  -----------------------------------------------------------------------------------------------
  TRAMA RX: |  A1B2C3D41234_0_A                                                       
  TRAMA TX: |  50_OK_a             
  -----------------------------------------------------------------------------------------------
            |  TEST2:                
  -----------------------------------------------------------------------------------------------
  TRAMA RX: |  A1B2C3D41234_0_K                                                                  
  TRAMA TX: |  50_14234,12425,134322,123234,23324,45654,2343,23424,23433,12123,3434,347,3423_k    
  -----------------------------------------------------------------------------------------------
            |  TEST3:                
  -----------------------------------------------------------------------------------------------
  TRAMA RX: |  A1B2C3D41234_0_Z                                                                   
  TRAMA TX: |  MODO SLEEP   
  -----------------------------------------------------------------------------------------------
*/


char bufferRX[16];
int i=0;

char TEST_TR1[]="A1B2C3D41234_0_A";
String TEST_TX1=String("50_OK_a");

char TEST_TR2[]="A1B2C3D41234_0_K";
String TEST_TX2=String("50_14234,12425,134322,123234,23324,45654,2343,23424,23433,12123,3434,347,3423_k");

char TEST_TR3[]="A1B2C3D41234_0_Z";
String TEST_TX3=String("MODO SLEEP");

void setup()
{      

  Serial.begin(9600);
  delay(100);
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
}

void loop() 
{

    

    if(Serial.available()){

       //Lectura del dato:
       bufferRX[i]=(char)Serial.read();
       
       
      // Serial.print(bufferRX[i]);
       //Serial.print("  i=");
       //Serial.println(i,DEC);
       i++;

       if(i==16) {
        i=0;


        if(cadena_cmp(bufferRX,TEST_TR1,16,16)){
                 Serial.print(TEST_TX1);
          }else{
            if(cadena_cmp(bufferRX,TEST_TR2,16,16)){
                 Serial.print(TEST_TX2);
              }else{
                 if(cadena_cmp(bufferRX,TEST_TR3,16,16)){
                 Serial.print(TEST_TX3); 
                  }
                } 
            
            }

          
          
      //  Serial.print(saludo);
       }

       
       /*

       //Decodificación de la trama:
       if(bufferRX[i]=='A' && i==16){
       i=0;
       digitalWrite(13,HIGH);
       delay(1000);
       
       }else{
       
       digitalWrite(13,LOW);
       }
     */
     
      } // FIN DEL IF SERIAL AVAILABLE
            
   
}  //FIN DEL LOOP



/*
***********************************************************
***************** FUNCTIONS *******************************
***********************************************************
*/

//COMPARADOS DE CADENAS:

boolean cadena_cmp(char *a, char *b, int len_a, int len_b){
     int k;

     // if their lengths are different, return false
     if (len_a != len_b) return false;

     // test each element to be the same. if not, return false
     for (k=0;k<len_a;k++) if (a[k]!=b[k]) return false;

     //ok, if we have not returned yet, they are equal :)
     return true;
}

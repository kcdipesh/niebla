// ********************************************************************************************** //
//				   defines       					          //
// ********************************************************************************************** //

#define Stop		2
#define Adelante	1
#define Atras		0
#define PID             rcontrol = control(dire);MI = BIAS - rcontrol;MD = BIAS + rcontrol;ponMotores(MI,MD);
#define derecho   	1
#define izquierdo	-1
#define derecho   	1
#define recto	        5

#define  REFERENCIA	        9

// ********************************************************************************************** //
//				   variables globales					          //
// ********************************************************************************************** //
int pd = 0, pi = 0, dire = 0, direAnt = 0;
signed int MI = 0, MD = 0, rcontrol = 0,errorAnt=0;
int pulsador_1 = 2 , pulsador_2 = 3;
int led_verde_der = 4,led_rojo_cen = 5,led_verde_izq = 7, led_azul = 13; 
int motor_derecho_a = 8, motor_derecho_b = 9, motor_izquierdo_a =11 , motor_izquierdo_b = 12, pwm_derecho = 6, pwm_izquierdo = 10;
int KP = 20 , KD = 80 , BIAS = 80;
int giro=0,ya_pasado=0,salido=0,var_A0=0,var_A7=0,acumulada_desvio=0;
int sensor[10] = {0,0,0,0,0,0,0,0,0,0},numero_lineas=0, sensor_ant[10] = {0,0,0,0,0,0,0,0,0,0},media_ant,media,numero_error,lado;
unsigned long tiempo_actual=0;
int  modo=1;
void setup() 
{ 
  configurar();
  analogWrite(pwm_derecho,0 );
  analogWrite(pwm_izquierdo,0 );
  Serial.begin(9600);
}

void loop() 
{
  modos(arranque()); 
  while (1)
  { 
    pd = PrimD();
    pi = PrimI();
    dire = pd + pi;
    leer_sensores_vector(); 
    
    numero_lineas=comprobacion_lectura();
    if (numero_lineas==0)//posicion estoy fuera  de la linea  
    {
      dire = direAnt;
      PID          
      delay(1);
    }

    else if (numero_lineas==1)
    {
      direAnt = dire;        
      cambiar_sensor_ant_por_sensor();
      PID
      delay(1);
    }
    else if (numero_lineas>=2)
    {
                 BIAS=BIAS-40;
                 KP= KP+10;
                 KD=KD+50;
      ya_pasado=1;
      pd = PrimD();
      pi = PrimI();

      limpiar_led_indicativos();
      Serial.print("2");
      while (comprobacion_lectura()>=2)
      {
        if (comprobar_lado()==1 && ya_pasado==1)
        {
          digitalWrite(led_verde_izq, HIGH);
          ya_pasado=0;
          giro=derecho; 
        }
        else if(comprobar_lado()==2&& ya_pasado==1)
        {
          digitalWrite(led_verde_der, HIGH);
          ya_pasado=0;
          giro=izquierdo; 
        }
        if (giro==derecho && ya_pasado==0)
        {
          direAnt=dire;
          dire = 2* PrimI();
          
        }
        if(giro==izquierdo && ya_pasado==0)
        { 
          direAnt=dire;
        dire = 2* PrimD();
        }
      
        if(comprobacion_lectura()==3 || giro==recto)
        {
          giro=recto;
         digitalWrite(led_verde_der, HIGH);
         digitalWrite(led_verde_izq, HIGH);
         
             if((analogRead(A3) < 512) && (analogRead(A4) < 512))
             {
          	dire = 9;
             }
             else
             {
                 if(analogRead(A3) < 512)
                 {
        	    dire = 8;
                 }
                 else
                 {  
                   if(analogRead(A4) < 512)
                      dire = 10;	
      	           else
	              dire = PrimD() + PrimI();    
                 }
             }
	}
        
        cambiar_sensor_ant_por_sensor();
        PID
        delay(1);
        leer_sensores_vector();
      }
       salido=0;
       digitalWrite(led_rojo_cen, HIGH);
    pd = PrimD();
    pi = PrimI();
    dire = pd + pi;
    leer_sensores_vector(); 
      direAnt = dire;        
      cambiar_sensor_ant_por_sensor();
      PID
      delay(1);
          pd = PrimD();
    pi = PrimI();
    dire = pd + pi;
    leer_sensores_vector(); 
      direAnt = dire;        
      cambiar_sensor_ant_por_sensor();
      PID
      delay(1);
          pd = PrimD();
    pi = PrimI();
    dire = pd + pi;
    leer_sensores_vector(); 
      direAnt = dire;        
      cambiar_sensor_ant_por_sensor();
      PID
      delay(1);
    tiempo_actual=millis();
  
      if (giro!=recto)
                {


                while (salido==0 )
                {
                  
                  if(giro==derecho)
                          { direAnt=dire;
                            dire = 2* PrimD();
                            

                            if(analogRead(A7) > 512 && var_A7==1)
                            {
                              salido=1;
                              Serial.print("Salido por A7");
                            }
                          }
                 if(giro==izquierdo)
                          {
                            direAnt=dire;
                            dire = 2* PrimI(); 

                            if(analogRead(A0) > 512 && var_A0==1)
                            
                            {            
                              salido=1;
                              Serial.print("Salido por A0");
                            }
                          }
                  
                          cambiar_sensor_ant_por_sensor();
                          PID
                          delay(1);
                           if((analogRead(A7) < 512))
                           {
                              var_A7=1;  
                            Serial.print("var_A7= 1");
                           }
                           if((analogRead(A0) < 512))
                                     {
                              var_A0=1;
                              Serial.print("var_A0= 1");
                                     }  
                          leer_sensores_vector();
                          if (millis()==tiempo_actual+1000)
                          salido=1;
                        }  
          
                }
               
   if (giro==recto)              
    {
      while (salido==0 )
        {
            if(analogRead(A7) > 512 && analogRead(A0) > 512 && var_A7==1 && var_A0==1)
                {
                salido=1;
               }
               if((analogRead(A7) < 512))
                   var_A7=1;  
               if((analogRead(A0) < 512))
                    var_A0=1;
                    
             if((analogRead(A3) < 512) && (analogRead(A4) < 512))
             {
          	dire = 9;
             }
             else
             {
                 if(analogRead(A3) < 512)
                 {
        	    dire = 8;
                 }
                 else
                 {  
                   if(analogRead(A4) < 512)
                      dire = 10;	
      	           else
	              dire = PrimD() + PrimI();    
                 }
             }
	
       cambiar_sensor_ant_por_sensor();
        PID
        delay(1);
        leer_sensores_vector(); 
          if (millis()==tiempo_actual+1000)
                    salido=1;
      }
    }
      delay (10);
      limpiar_led_indicativos();
    BIAS=BIAS+40;
     KP= KP-10;
     KD=KD-50;

     
    }
 
 var_A0=0; 
  var_A7=0; 
  giro=0;

  }
} 



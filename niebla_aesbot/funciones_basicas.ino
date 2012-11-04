void configurar()
{
  pinMode(led_verde_izq, OUTPUT);
  pinMode(led_verde_der, OUTPUT);
  pinMode(led_rojo_cen, OUTPUT);
  pinMode(led_azul, OUTPUT);

  pinMode(motor_derecho_a, OUTPUT);
  pinMode(motor_derecho_b, OUTPUT);
  pinMode(motor_izquierdo_a, OUTPUT);
  pinMode(motor_izquierdo_b, OUTPUT);

  pinMode(pulsador_1,INPUT);
  pinMode(pulsador_2,INPUT);
}
int arranque()
{ 
  analogWrite(pwm_derecho,0 );

  while (digitalRead(pulsador_1)==0)
  { 
    if  (digitalRead(pulsador_2)==1) modo++; 
    if (modo >7) 
    {
      modo=1;
      limpiar_led();
    }
    if(modo==1)
    {
      limpiar_led();
      digitalWrite(led_verde_der, HIGH);
      delay(100);
    }
    if(modo==2)
    {
      limpiar_led(); 
      digitalWrite(led_rojo_cen, HIGH);
      delay(100);
    }
    if(modo==3)
    {
      limpiar_led();
      digitalWrite(led_verde_izq, HIGH);
      delay(100);
    }
    if(modo==4)
    {
      limpiar_led();
      digitalWrite(motor_derecho_a, HIGH);
      delay(100);
    }
    if(modo==5)
    {
      limpiar_led(); 
      digitalWrite(motor_derecho_b, HIGH);
      delay(100);
    }
    if(modo==6)
    {
      limpiar_led(); 
      digitalWrite(motor_izquierdo_a, HIGH);
      delay(100); 
    }
    if(modo==7)
    {
      limpiar_led(); 
      digitalWrite(motor_izquierdo_b, HIGH);
      delay(100);
    }
  }

  limpiar_led();
  digitalWrite(led_verde_izq,HIGH);//LOW
  return(modo);

}
void limpiar_led()
{
  digitalWrite(led_verde_izq, LOW);
  digitalWrite(led_verde_der, LOW);
  digitalWrite(led_rojo_cen, LOW);
  digitalWrite(motor_izquierdo_a, LOW);
  digitalWrite(motor_izquierdo_b, LOW);
  digitalWrite(motor_derecho_a, LOW);
  digitalWrite(motor_derecho_b, LOW);
}
void limpiar_led_indicativos()
{
  digitalWrite(led_verde_izq, LOW);
  digitalWrite(led_verde_der, LOW);
  digitalWrite(led_rojo_cen, LOW);
  digitalWrite(motor_izquierdo_a, LOW);

}

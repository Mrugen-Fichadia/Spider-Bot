#include <Servo.h>   
Servo servo[4][3];
//define servos' ports
const int servo_pin[4][3] = { {3,4,2}, {12,13,11}, {9,10,8}, {6, 7, 5} }; //1b 1c 1a 4b 4c 4a 3b 3c 3a 2b 2c 2a
int a1=90,b1=160,c1=160,a2=90,b2=160,c2=160,a3=90,b3=160,c3=140,a4=90,b4=160,c4=160;
int val[4][3] = {{160,130,90},{155,90,90},{170,120,90},{160,170,90}};
int cnt=1;

void hi(){
  Serial.println("hi");
  val[0][0]=180;
  val[0][1]=100;
  servo[0][0].write(val[0][0]);
  servo[0][1].write(val[0][1]);
  for(int j=0;j++;j<30){
    servo[0][1].write(val[0][1]++);
    delay(35);
  }
  for(int j=0;j++;j<30){
    servo[0][1].write(val[0][1]--);
    delay(35);
  }
  for(int j=0;j++;j<30){
    servo[0][1].write(val[0][1]++);
    delay(35);
  }
  for(int j=0;j++;j<30){
    servo[0][1].write(val[0][1]--);
    delay(35);
  }
  servo[0][1].write(val[0][1]+=50);
  delay(30);
  for(int k=0;k<20;k++){
    servo[0][0].write(val[0][0]--);
    delay(15);
  }
  reset();
}

void reset()
{
 val[0][0] = 160;
 val[0][1] = 130;
 val[0][2] = 90;
 val[1][0] = 155;
 val[1][1] = 90;
 val[1][2] = 90;
 val[2][0] = 170;
 val[2][1] = 120;
 val[2][2] = 90;
 val[3][0] = 160;
 val[3][1] = 170;
 val[3][2] = 90;

for (int i = 0; i < 4; i++)
 {
   for (int j = 0; j < 3; j++)
   {
     servo[i][j].write(val[i][j]);
     delay(20);
   }
 }

 delay(2000);
                                
}

void reset1()
{
 val[0][0] = 175;
 val[0][1] = 160;
 val[0][2] = 90;
 val[1][0] = 155;
 val[1][1] = 90;
 val[1][2] = 90;
 val[2][0] = 170;
 val[2][1] = 120;
 val[2][2] = 90;
 val[3][0] = 160;
 val[3][1] = 170;
 val[3][2] = 90;

 for (int i = 0; i < 4; i++)
 {
   for (int j = 0; j < 3; j++)
   {
     servo[i][j].write(val[i][j]);
     delay(20);
   }
 }

 delay(2000);
                                
}

void pushforward(){
  val[0][2]+=10;
  val[2][2]-=10;
  val[1][2]+=10;
  val[3][2]-=10;
  val[0][0]+=10;
  val[0][1]+=15;
  val[1][0]-=20;
  val[1][1]-=40;
  val[3][0]-=15;
  val[3][1]-=25;
  val[2][0]+=17;
  val[2][1]+=15;
  servo[0][2].write(val[0][2]);
  servo[1][2].write(val[1][2]);
  servo[2][2].write(val[2][2]);
  servo[3][2].write(val[3][2]);
  
  servo[0][0].write(val[0][0]);
  servo[0][1].write(val[0][1]);
  servo[1][0].write(val[1][0]);
  servo[1][1].write(val[1][1]);
  servo[3][0].write(val[3][0]);
  servo[3][1].write(val[3][1]);
  servo[2][0].write(val[2][0]);
  servo[2][1].write(val[2][1]);
}

void pushbackward(){
  val[0][2]-=10;
  val[2][2]+=10;
  val[1][2]-=10;
  val[3][2]+=10;
  val[0][0]-=10;
  val[0][1]-=15;
  val[1][0]+=20;
  val[1][1]+=40;
  val[3][0]+=15;
  val[3][1]+=25;
  val[2][0]-=17;
  val[2][1]-=15;
  servo[0][2].write(val[0][2]);
  servo[1][2].write(val[1][2]);
  servo[2][2].write(val[2][2]);
  servo[3][2].write(val[3][2]);
  
  servo[0][0].write(val[0][0]);
  servo[0][1].write(val[0][1]);
  servo[1][0].write(val[1][0]);
  servo[1][1].write(val[1][1]);
  servo[3][0].write(val[3][0]);
  servo[3][1].write(val[3][1]);
  servo[2][0].write(val[2][0]);
  servo[2][1].write(val[2][1]);
}

void moveForward(){
  //Movement of first leg, far from leg 3
      reset();
       servo[0][0].write(val[0][0]+=20);
       delay(200);
       servo[0][1].write(val[0][1]-=30);
       delay(200);
       servo[0][2].write(val[0][2]-=30);
       for(int i=0; i<30;i++){
        servo[0][0].write(val[0][0]--);
        delay(20);
       }
       //delay(1000);
       Serial.println("Leg 1 moved");
       delay(200);
       pushforward();
       
       Serial.println("Pushed...");
       delay(500);
        
  
    //Move leg 2 inside i.e towards leg 4
       servo[3][0].write(val[3][0]+=40);
       delay(200);
       servo[3][2].write(val[3][2]+=30);
       servo[3][1].write(val[3][1]+=60);
       delay(200);
       
       Serial.println("Leg 2 moved");
       delay(200);
       pushforward();
       Serial.println("Pushed");
      
       delay(500);

   //Move the leg 3 outside i.e 3a move far from leg 1
       servo[2][0].write(val[2][0]+=20);
       delay(200);
       servo[2][1].write(val[2][1]-=30);
       delay(200);
       servo[2][2].write(val[2][2]+=30);
       delay(200);
       for(int i=0; i<30;i++){
        servo[2][0].write(val[2][0]--);
        delay(20);
       }
       delay(200);
       pushforward();
       Serial.println("Pushed");
       delay(500);

    //Move leg 4 inside i.e towards 2
    
       servo[1][0].write(val[1][0]+=110);
       Serial.println("P-1");
       delay(200);
       servo[1][1].write(val[1][1]+=135);
       servo[1][2].write(val[1][2]-=30);
       Serial.println("P-2");
       delay(200);
      
      pushforward();
       Serial.println("Done...!!!!");
       delay(500);   
       reset();
  }

void moveBackward(){
  reset1();
  //Move leg 4 inside i.e towards 2
    
       servo[1][0].write(val[1][0]+=20);
       Serial.println("P-1");
       delay(1000);
       servo[1][1].write(val[1][1]-=30);
       servo[1][2].write(val[1][2]-=30);
       Serial.println("P-2");
       delay(1000);
     
      for(int i=0; i<30;i++){
        servo[1][0].write(val[1][0]--);
        delay(20);
       }
      pushbackward();
       Serial.println("leg 1");
       delay(1000);

       //Move the leg 3 outside i.e 3a move far from leg 1
       servo[2][0].write(val[2][0]+=40);
       delay(1000);
       servo[2][1].write(val[2][1]+=30);
       delay(1000);
       servo[2][2].write(val[2][2]+=60);
       delay(1000);
       pushbackward();
       Serial.println("Pushed");
       delay(1000);


    //Move leg 2 inside i.e towards leg 4
       servo[3][0].write(val[3][0]+=20);
       delay(1000);
       servo[3][2].write(val[3][2]-=30);
       servo[3][1].write(val[3][1]+=30);
       delay(1000);
       for(int i=0; i<30;i++){
        servo[3][0].write(val[3][0]--);
        delay(20);
       }
       Serial.println("Leg 2 moved");
       delay(1000);
       pushbackward();
       Serial.println("Pushed");
       delay(1000);
       servo[3][2].write(val[3][2]+=20);
       delay(1000);

//Movement of first leg, far from leg 3
      reset();
       servo[0][0].write(val[0][0]+=110);
       delay(1000);
       servo[0][1].write(val[0][1]+=135);
       delay(1000);
       servo[0][2].write(val[0][2]-=30);
      
       Serial.println("Leg 1 moved");
       delay(1000);
       Serial.println("Pushed...");
       pushbackward();       
       Serial.println("Done...!!!!");
       delay(1000);
        
       
       reset();
  }

void turnAround1(){
  reset();
  //Turn leg 3
  Serial.println("1");
  val[2][0]+=20;
  
    servo[2][0].write(val[2][0]);
    Serial.println("2");
    delay(200);
    val[2][2]-=40;
    servo[2][2].write(val[2][2]);
    Serial.println("2");
    delay(200);
    for(int i=0;i<30;i++){
      val[2][0]-=1;
      servo[2][0].write(val[2][0]);
      delay(15);
    }
    Serial.println("3");
    delay(200);
    val[1][2]+=20;
    val[3][2]+=20;
    val[0][2]+=20;
    val[2][2]+=20;
    servo[1][2].write(val[1][2]); 
    Serial.println("4");
   
    servo[3][2].write(val[3][2]); 
    Serial.println("5");
    servo[0][2].write(val[0][2]); 
    Serial.println("6");
   
    servo[2][2].write(val[2][2]);
    delay(200);
    
  //Turn leg 2
  val[3][0]+=20;
  
    servo[3][0].write(val[3][0]);
    delay(200);
    val[3][2]-=40;
    servo[3][2].write(val[3][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[3][0]-=1;
      servo[3][0].write(val[3][0]);
      delay(15);
    }
    delay(200);
    val[1][2]+=20;
    val[3][2]+=20;
    val[0][2]+=20;
    val[2][2]+=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(200);
    
  //Turn leg 4
val[1][0]+=20;
  
    servo[1][0].write(val[1][0]);
    delay(200);
    val[1][2]-=40;
    servo[1][2].write(val[1][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[1][0]-=1;
      servo[1][0].write(val[1][0]);
      delay(15);
    }
    delay(200);
    val[1][2]+=20;
    val[3][2]+=20;
    val[0][2]+=20;
    val[2][2]+=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(200);
   
 //Turn leg 1

  val[0][0]+=20;
  
    servo[0][0].write(val[0][0]);
    delay(200);
    val[0][2]-=40;
    servo[0][2].write(val[0][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[0][0]-=1;
      servo[0][0].write(val[0][0]);
      delay(15);
    }
    delay(200);
    val[1][2]+=20;
    val[3][2]+=20;
    val[0][2]+=20;
    val[2][2]+=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(500);
    reset();
}

//Turn around 2
void turnAround2(){
  reset();
  //Turn leg 3
  Serial.println("1");
  val[2][0]+=20;
  
    servo[2][0].write(val[2][0]);
    Serial.println("2");
    delay(200);
    val[2][2]+=40;
    servo[2][2].write(val[2][2]);
    Serial.println("2");
    delay(200);
    for(int i=0;i<30;i++){
      val[2][0]-=1;
      servo[2][0].write(val[2][0]);
      delay(15);
    }
    Serial.println("3");
    delay(200);
    val[1][2]-=20;
    val[3][2]-=20;
    val[0][2]-=20;
    val[2][2]-=20;
    servo[1][2].write(val[1][2]); 
    Serial.println("4");
    servo[3][2].write(val[3][2]); 
    Serial.println("5");
    servo[0][2].write(val[0][2]); 
    Serial.println("6");
    servo[2][2].write(val[2][2]);
    delay(200);
    
  //Turn leg 2
  val[3][0]+=20;
  
    servo[3][0].write(val[3][0]);
    delay(200);
    val[3][2]+=40;
    servo[3][2].write(val[3][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[3][0]-=1;
      servo[3][0].write(val[3][0]);
      delay(15);
    }
    delay(200);
    val[1][2]-=20;
    val[3][2]-=20;
    val[0][2]-=20;
    val[2][2]-=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(200);
    
  //Turn leg 4
val[1][0]+=20;
  
    servo[1][0].write(val[1][0]);
    delay(200);
    val[1][2]+=40;
    servo[1][2].write(val[1][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[1][0]-=1;
      servo[1][0].write(val[1][0]);
      delay(15);
    }
    delay(200);
    val[1][2]-=20;
    val[3][2]-=20;
    val[0][2]-=20;
    val[2][2]-=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(200);
   
 //Turn leg 1

  val[0][0]+=20;
  
    servo[0][0].write(val[0][0]);
    delay(200);
    val[0][2]+=40;
    servo[0][2].write(val[0][2]);
    delay(200);
    for(int i=0;i<30;i++){
      val[0][0]-=1;
      servo[0][0].write(val[0][0]);
      delay(15);
    }
    delay(200);
    val[1][2]-=20;
    val[3][2]-=20;
    val[0][2]-=20;
    val[2][2]-=20;
    servo[1][2].write(val[1][2]); 
    servo[3][2].write(val[3][2]); 
    servo[0][2].write(val[0][2]); 
    servo[2][2].write(val[2][2]);
    delay(500);
   reset();
}
void blink()
{
  reset();
  for(int i=0;i<5;i++){
  digitalWrite(19, HIGH); // Toggle LED 
  Serial.println("interrupt");
  delay(500);
  digitalWrite(19, LOW);
  delay(500);
 }
Serial.println("I");
turnAround1();
reset();
}

void setup()
{

//Initialize the interrupt
pinMode(18, INPUT_PULLUP);
attachInterrupt(digitalPinToInterrupt(18), blink, CHANGE);
pinMode(19, OUTPUT);
pinMode(30, INPUT);
pinMode(32, INPUT);
pinMode(34, INPUT);
pinMode(36, INPUT);

//initialize all servos
 for (int i = 0; i < 4; i++)
 {
   for (int j = 0; j < 3; j++)
   {
     servo[i][j].attach(servo_pin[i][j]);
     delay(20);
   }
 }
 for (int i = 0; i < 4; i++)
 {
   for (int j = 0; j < 3; j++)
   {
     servo[i][j].write(val[i][j]);
     delay(20);
   }
 }
digitalWrite(30,LOW);
digitalWrite(32,LOW);
digitalWrite(34,LOW);
digitalWrite(36,LOW);
 Serial.begin(9600);
}

void loop(void)
{
    if(digitalRead(30)==HIGH){
        //reset();
        moveForward();//blue
          Serial.println("L1");
     }
     if(digitalRead(32)==HIGH){
        Serial.println("L2");
        //reset();
        moveBackward();//red
     }
     if(digitalRead(34)==HIGH){
      Serial.println("L3");
        //reset();
        turnAround2();//green
     }
     if(digitalRead(36)==HIGH){
      Serial.println("L4");
        //reset();
        turnAround1();//yellow
     }
     else{
        reset();
        moveForward();
      }
}

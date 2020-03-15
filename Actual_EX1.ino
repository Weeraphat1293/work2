#define LED1 5
#define LED2 6
float brightness=0;
String buff;
char PO;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {buff =' ';
PO =' ';
   if(Serial.available()>0){
    char inByte=Serial.read();
    if(inByte!='L'){
      return 0;
    }
   char inByte1=Serial.read();
   PO=inByte1;
     char inByte2=Serial.read();
  buff = Serial.readString();
  while(Serial.available() > 0) {Serial.read();}
    }
      brightness=buff.toInt();
      Serial.println(brightness);
      Serial.println(PO);
  if( PO=='1'){
      analogWrite(LED1,int(brightness*2.54));
  }
 else if( PO=='2'){
      analogWrite(LED2,int(brightness*2.54));
}

}

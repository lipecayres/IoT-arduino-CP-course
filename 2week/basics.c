// Setup

void setup()
{

	Serial.begin(9600);


  for (int i=0; i<4; i++){
	Serial.println("hello!"); 
  };
  
  	Serial.println("");
 
  int n = 0;
  for (int i=0; i<=9;i++){
    n = n+6;
    Serial.println(n); 
  };

	Serial.println("");

   for (int i=0; i<=100; i = i+2){
	Serial.println(i); 
  };
  
	Serial.println("");

   for (int i=50; i>=0; i--){
	Serial.println(i); 
  };
  
 

}

void loop () {
  
 
}
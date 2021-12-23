
#include<SD.h>
int chipselect=4;
File file;
void setup() {
 Serial.begin(9600);
 pinMode(chipselect,OUTPUT);
 if(!SD.begin(chipselect)){
  Serial.println("couldnot find the document");}
  if(SD.exists("file.txt")){
    Serial.println("file exists");
    }
    if(SD.remove("file.txt")==true){
      Serial.println("successfully removed file");
      }
    else{
      Serial.println("couldnot remove file");
      }

}

void loop() {
  file=SD.open("file.txt,FILE_WRITE");
  if(file)  {
    
    int number= random(10);
    file.println(number);
    file.close();
    Serial.print("wrote number: ");
    Serial.println(number);
    }
    else{
      Serial.println("could not open file");
      }
file=SD.open("file.txt,FILE_READ");
if(file){
  Serial.println("...reading start");
  char character;
  while((character=file.read())!= -1){
    Serial.println(character);
    }
    file.close();
    Serial.println("reading end");
}
else{
  Serial.println("couldnot open file");
  
  }
  delay(5000);
}

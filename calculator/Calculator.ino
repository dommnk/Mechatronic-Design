  int first;
  int scd;
  int opr;
  double result; 


void setup()
{
  Serial.begin(9600); 
  Serial.print(communicat1());
}

String communicat1(){
  String com = "Wprowadz numer odpowiadajacy opeacji: \n 1 - dodawanie \n 2 - odejmowanie \n 3 - mnozenie \n 4 - dzielenie \r\n";
 return com; 
}

String communicat2(){
  String com = "Wprowadz pierwsza liczbe \r\n";
 return com; 
}

String communicat3(){
  String com = "Wprowadz druga liczbe \r\n";
 return com; 
}

int readFromConsole(){
  while(Serial.available() == 0) {delay(5);}  //wait until data received to serial
  
   if (Serial.available() > 0) {
    return Serial.parseInt();  // read data
   }
}

void loop()
  
{
  opr = readFromConsole();
  switch (opr) {
  case 1:
    Serial.println(communicat2());
    first = readFromConsole();
    Serial.println(communicat3());
    scd = readFromConsole();
    if(abs(first) < 100 && abs(scd) < 100 && abs(first) > 9 && abs(scd) > 9){
      result = first + scd;
      Serial.println("Wynik to:");
      Serial.println(result);
    }
    else{
    Serial.println("Liczby muszą być dwucyfrowe");
    }
    
    break;
  case 2:
    Serial.println(communicat2());
    first = readFromConsole();
    Serial.println(communicat3());
    scd = readFromConsole();
    if(abs(first) < 100 && abs(scd) < 100 && abs(first) > 9 && abs(scd) > 9){
      result = first - scd;
      Serial.println("Wynik to:");
      Serial.println(result);
    }
    else{
    Serial.println("Liczby musza byc dwucyfrowe");
    }
    break;
  case 3:
    Serial.println(communicat2());
    first = readFromConsole();
    Serial.println(communicat3());
    scd = readFromConsole();
    if(abs(first) < 100 && abs(scd) < 100 && abs(first) > 9 && abs(scd) > 9){
      result = first * scd;
      Serial.println("Wynik to:");
      Serial.println(result);
    }
    else{
    Serial.println("Liczby musza byc dwucyfrowe");
    }
    break;
  case 4:
    Serial.println(communicat2());
    first = readFromConsole();
    Serial.println(communicat3());
    scd = readFromConsole();
    if(abs(first) < 100 && abs(scd) < 100 && abs(first) > 9 && abs(scd) > 9 && scd != 0){
      result = first / scd;
      Serial.println("Wynik to:");
      Serial.println(result);
    }
    else{
    Serial.println("Liczby musza byc dwucyfrowe a dzielnik nie moze byc zerem");
    }
    break;
  default:
    Serial.println("Wprowadzono nieprawidlowa liczbe, sprobuj ponownie");
    break;
}
  
  Serial.print(communicat1());

}
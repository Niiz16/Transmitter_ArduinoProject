#include <SD.h>
#define FILENAME "feep.ppm"
File myFile;
String cadena="";
int pin = 7, s = 0, p = 0;


void ToBin (int s)
{
  if (s == 0)
  { int B[11] = {0,0,0,1,1,0,0,0,0,0,1}; //48
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1); //digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 1)
  { int B[11] = {0,0,0,1,1,0,0,0,1,1,1}; //49
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 2)
  { int B[11] = {0,0,0,1,1,0,0,1,0,1,1};//50
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 3)
  { int B[11] = {0,0,0,1,1,0,0,1,1,0,1};//51
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 4) {
    int B[11] = {0,0,0,1,1,0,1,0,0,1,1} ; //52
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 5)
  { int B[11] = {0,0,0,1,1,0,1,0,1,0,1};//53
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 6)
  { int B[11] =  {0,0,0,1,1,0,1,1,0,0,1};//54
    for(int j = 0; j<11; j=j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 7)
  { int B[11] =  {0,0,0,1,1,0,1,1,1,1,1};//55
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 8)
  { int B[11] =  {0,0,0,1,1,1,0,0,0,1,1};//56
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 9)
  { int B[11] = {0,0,0,1,1,1,0,0,1,0,1};//57
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 10)//P
  { int B[11] = {0,0,1,0,1,0,0,0,0,0,1};//80
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if (s == 11)//space
  { int B[11] = {0,0,0,1,0,0,0,0,0,1,1};//32
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }

  else if (s == 12)//newline
  { int B[11] = {0,0,0,0,0,1,0,1,0,0,1};//10
    for(int j = 0; j < 11; j = j+1)
    {
      if (B[j] == 1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }
  else if(s == 90)
  { int B[11] = {1,1,1,1,1,1,1,1,1,1,1};//10
    for(int j=0; j<11; j=j+1)
    {
      if (B[j]==1) Serial.print(1);//digitalWrite(pin , HIGH);
      else Serial.print(0);//digitalWrite(pin , LOW);
    };
  }

}

void setup()
{

  pinMode(pin, OUTPUT);
  Serial.begin(115200);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  //Serial.print("inicializacion exitosa");
 
//  Serial.end();
}

void loop()
{
  
 myFile = SD.open(FILENAME);//abrimos  el archivo
 // int totalBytes=myFile.size();// número total de bytes
  if (myFile) {

    // myFile.seek(14);
    Serial.println("feep:");
    //Serial.print(totalBytes);
    ToBin(90);

    while (myFile.available()) {
      char caracter = myFile.read();
      if(caracter == ' ')
      {
        if(p == 0) cadena=cadena + "11";
        p = p + 1;
      }
      else if (caracter == '\n')
      {
        p = 0;
        cadena=cadena + "12";
      }
      else if (caracter == 'P')
      {
        p = 0;
        cadena = cadena + "10";
      }
      else
      {
        cadena = cadena + caracter;
        p = 0;
      }

      if(p < 2) {
        s = cadena.toInt();
        ToBin(s);
      }

      cadena = "";
    }

    myFile.close(); //cerramos el archivo

    ToBin(90);
    Serial.print('X');
  } else {
    Serial.println("Error al abrir el archivo");
  }
}

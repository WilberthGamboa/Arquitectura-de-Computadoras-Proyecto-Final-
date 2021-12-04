

#include <Keypad.h>//header for keypad commands enabling
int cont = 0;
int contInterno = 0;
char codigo[4];
char contrasena[] = "1234";
char volteado[] = "2345";
char doble[] = "3456";
char doblevolteado[] = "4567";
char salida[] = "1";


const byte ROWS = 4; // Four rows

const byte COLS = 3; // Three columns

// Define the Keymap

char hexaKeys[ROWS][COLS] = {

  {'1', '2', '3'},

  {'4', '5', '6'},

  {'7', '8', '9'},

  {'#', '0', '*'}

};

// Connect keypad A B C D rows to these Arduino pins.

byte rowPins[ROWS] = { 4, 5, 6, 7 };

// Connect keypad 1 2 3 columns to these Arduino pins.

byte colPins[COLS] = { 3, 2, 1 };

//  Create the Keypad

//Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
// Del 8 al 13
const int LED0 = 0;
const int LED8 = 8;
const int LED9 = 9;
const int LED10 = 10;
const int LED11 = 11;
const int LED12 = 12;
const int LED13 = 13;
void setup()
{
  pinMode(LED0, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  pinMode(LED11, OUTPUT);
  pinMode(LED12, OUTPUT);
  pinMode(LED13, OUTPUT);


}
void secuencia() {


  // turn the pin on:
  for (int thisPin = 8; thisPin < 14; thisPin++) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY) {
      codigo[cont] = customKey;
      if (codigo[cont] == salida[0]) {
        contInterno = 1;
        break;
      }
    }
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(200);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
    if (codigo[cont] == salida[0]) {
      contInterno = 1;
      break;
    }
  }
}

void secuencia2() {

  // turn the pin on:
  for (int thisPin = 14; thisPin >=  8; thisPin--) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY) {
      codigo[cont] = customKey;
      if (codigo[cont] == salida[0]) {
        contInterno = 1;
        break;
      }


    }
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    delay(200);
    // turn the pin off:
    digitalWrite(thisPin, LOW);

  }



}

void secuencia3() {


  // turn the pin on:
  for (int thisPin = 8; thisPin < 14; thisPin++) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY) {
      codigo[cont] = customKey;
      if (codigo[cont] == salida[0]) {
        contInterno = 1;
        break;
      }
    }
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    digitalWrite(thisPin + 1, HIGH);
    delay(200);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
    digitalWrite(thisPin + 1, LOW);

    if (codigo[cont] == salida[0]) {
      contInterno = 1;
      break;
    }
  }
}

void secuencia4() {

  // turn the pin on:
  for (int thisPin = 14; thisPin >=  8; thisPin--) {
    char customKey = customKeypad.getKey();
    if (customKey != NO_KEY) {
      codigo[cont] = customKey;
      if (codigo[cont] == salida[0]) {
        contInterno = 1;
        break;
      }


    }
    // turn the pin on:
    digitalWrite(thisPin, HIGH);
    digitalWrite(thisPin - 1, HIGH);
    delay(200);
    // turn the pin off:
    digitalWrite(thisPin, LOW);
    digitalWrite(thisPin - 1, LOW);

  }



}




void loop() {
  if (cont == 0) {
    digitalWrite(LED0, HIGH);

    // turn the pin off:



  }
  else if (cont != 0) {
    digitalWrite(LED0, LOW);
  }

  //char key = kpd.getKey(); //store the pressed key
  char customKey = customKeypad.getKey();
  int validar = 0;

  if (customKey != NO_KEY) {
    codigo[cont] = customKey;

    cont++;
    //original
    if (cont == 4) {
      if (codigo[0] == contrasena[0] && codigo[1] == contrasena[1] && codigo[2] == contrasena[2] && codigo[3] == contrasena[3]) {

        do {
          secuencia();


        } while (contInterno == 0);
        cont = 0;

        contInterno = 0;

      }
      //volteado

      else if (codigo[0] == volteado[0] && codigo[1] == volteado[1] && codigo[2] == volteado[2] && codigo[3] == volteado[3]) {

        do {
          secuencia2();


        } while (contInterno == 0);
        contInterno = 0;

        cont = 0;

      }
      //doble serie

      else if (codigo[0] == doble[0] && codigo[1] == doble[1] && doble[2] == doble[2] && codigo[3] == doble[3]) {

        do {
          secuencia3();


        } while (contInterno == 0);
        contInterno = 0;

        cont = 0;

      }
      //doble serie volteado
      else if (codigo[0] == doblevolteado[0] && codigo[1] == doblevolteado[1] && codigo[2] == doblevolteado[2] && codigo[3] == doblevolteado[3]) {

        do {
          secuencia4();


        } while (contInterno == 0);
        contInterno = 0;

        cont = 0;

      }






    }


    else if ( cont > 3) {
      cont = 0;

    }





  }



}

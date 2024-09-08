#include <LiquidCrystal.h>

LiquidCrystal lcd(9, 8, 5, 4, 3, 2);

byte DINO_PARADO_PARTE_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001};
byte DINO_PARADO_PARTE_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DINO_PIE_DERE_PART_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00001};
byte DINO_PIE_DERE_PART_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B00000};
byte DINO_PIE_IZQU_PART_1[8] = {B00000, B00000, B00010, B00010, B00011, B00011, B00001, B00000};
byte DINO_PIE_IZQU_PART_2[8] = {B00111, B00111, B00111, B00100, B11100, B11100, B11000, B01000};
byte DOS_RAMAS_PART_1[8] = {B00000, B00100, B00100, B10100, B10100, B11100, B00100, B00100};
byte DOS_RAMAS_PART_2[8] = {B00100, B00101, B00101, B10101, B11111, B00100, B00100, B00100};
byte AVE_ALAS_PART1[8] = {B00001, B00001, B00001, B00001, B01001, B11111, B00000, B00000};
byte AVE_ALAS_PART2[8] = {B00000, B10000, B11000, B11100, B11110, B11111, B00000, B00000};

int columna_dino1 = 1;
int columna_dino2 = 2;
int fila_dino = 1;
unsigned long reloj = 0;
int periodo = 100;
int flag = 1;
int fila_rama = 0;
int columna_rama = 13;
int periodo2 = 100;
unsigned long reloj2 = 0;
int a = 0;
int b = 1;
int c = 2;
int d = 0;
unsigned long reloj3 = 0;
int periodo3 = 100;
int puntos = 0;
int punto2 = 0;
int numerorandom = 0;
int columnaave = 13;
int e = 0;
int fila_ave = 1;
int senalactual = 0;
int senalantigua = 0;
int f = 13;
int aceleracion = 1;
unsigned long reloj4 = 0;
int periodo4 = 800;
int boton = 11;
int buzzer = 10;


void setup() {
  for (int i = 2; i <= 17; i++)  pinMode(i, OUTPUT);

  pinMode(boton, INPUT);

  pinMode(buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.createChar(0, DINO_PARADO_PARTE_1);
  lcd.createChar(1, DINO_PARADO_PARTE_2);
  lcd.createChar(2, DINO_PIE_DERE_PART_1);
  lcd.createChar(3, DINO_PIE_DERE_PART_2);
  lcd.createChar(4, DINO_PIE_IZQU_PART_1);
  lcd.createChar(5, DINO_PIE_IZQU_PART_2);
  lcd.createChar(6, DOS_RAMAS_PART_1);
  lcd.createChar(7, DOS_RAMAS_PART_2);
}
void loop() {
  if (millis() > reloj + periodo) {
    reloj = millis();
    if (flag == 1) {
      flag = 2;
    }
    else if (flag == 2) {
      flag = 1;

    }


  }

  if (millis() > reloj2 + periodo2) {
    reloj2 = millis();

    columna_rama = columna_rama - 1;
    if (columna_rama < 0) {
      columna_rama = 13;
      periodo2 = periodo2 - aceleracion;
      numerorandom = random(0, 3);


    }

    f = columna_rama + 1;
    lcd.setCursor(f, 1);          
    lcd.print(" ");

    f = columna_rama + 1;
    lcd.setCursor(f, 0);          
    lcd.print(" ");


    lcd.setCursor(0, 1);           
    lcd.print(" ");

    lcd.setCursor(0, 0);
    lcd.print(" ");

    a = 1;
  }

  if (d == 0) {
    if (flag == 1) {
      lcd.setCursor(columna_dino1, fila_dino);
      lcd.write(byte(2));
      lcd.setCursor(columna_dino2, fila_dino);
      lcd.write(byte(3));
    }
    if (flag == 2) {
      lcd.setCursor(columna_dino1, fila_dino);
      lcd.write(byte(4));
      lcd.setCursor(columna_dino2, fila_dino);
      lcd.write(byte(5));
    }
  }

  if (a == 1) {

    if (numerorandom == 1) {
      fila_rama = 1;
      lcd.createChar(6, DOS_RAMAS_PART_1);
      lcd.setCursor(columna_rama, fila_rama);
      lcd.write(byte(6));

    }
    else if (numerorandom == 2) {
      fila_rama = 1;
      lcd.createChar(7, DOS_RAMAS_PART_2);
      lcd.setCursor(columna_rama, fila_rama);
      lcd.write(byte(7));

    }
    else {

      columnaave = columna_rama;
      columnaave = columnaave - 1;
      fila_rama = 0;
      lcd.createChar(6, AVE_ALAS_PART1);
      lcd.setCursor(columnaave, fila_rama);
      lcd.write(byte(6));

      lcd.createChar(7, AVE_ALAS_PART2);
      lcd.setCursor(columna_rama, fila_rama);
      lcd.write(byte(7));

    }



    a = 0;
  }


  if (digitalRead(boton) == HIGH && (columna_rama == 1 || columna_rama == 2 || columnaave == 1 || columnaave == 2) && fila_rama == 0 ) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    columna_rama = 15;
    periodo2 = 100;
    puntos = 0;
    punto2 = 0;
    periodo2 = 100;

  }

  if ((columna_rama == b || columna_rama == c) && fila_rama == 1) {
    int note[] = {200, 150};
    for (int i = 0; i < 2; i++) {
      tone(buzzer, note[i], 250);
      delay(200);
    }
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("GAME OVER");
    delay(2000);
    lcd.clear();
    columna_rama = 15;
    periodo2 = 100;
    puntos = 0;
    puntos = 2;
    periodo2 = 100;
  }


  //  lcd.clear();
  // //lcd.setCursor(5, 0);
  //lcd.print("GAME OVER");
  // delay(2000);
  // lcd.clear();
  //  columna_rama=15;
  // periodo2=100;
  //  fila_rama=1;



  if (digitalRead(boton) == HIGH) {

    b = 50;
    c = 50;

    if (d == 0) {
      lcd.setCursor(0, 1);
      lcd.print("    ");
    }
    d = 1;

    lcd.setCursor(columna_dino1, 0);
    lcd.write(byte(2));
    lcd.setCursor(columna_dino2, 0);
    lcd.write(byte(3));

    if (millis() > reloj4 + periodo4) {
  reloj4 = millis();

    int note[] = {600};
    for (int i = 0; i < 1; i++) {
      tone(buzzer, note[i], 150);
      delay(20);
    }
    }
  }
  else {
    b = 1;
    c = 2;
    // lcd.setCursor(0, 0);
    //lcd.print("    ");
    d = 0;
  }

if (millis() > reloj3 + periodo3) {
  reloj3 = millis();
  lcd.setCursor(14, 1);
  lcd.print(puntos);

  //if(b==50){
  // }
  //else{
  puntos = puntos + 1;
  //}

  if (puntos == 100) {
    int note[] = {800, 900};
    for (int i = 0; i < 2; i++) {
      tone(buzzer, note[i], 150);
      delay(150);
      puntos = 0;
      punto2 = punto2 + 1;
      if (punto2 == 100) {
        punto2 = 0;
      }

    }

  }


  lcd.setCursor(14, 1);
  lcd.print(puntos);
  lcd.setCursor(14, 0);
  lcd.print(punto2);


  senalactual = digitalRead(boton);
  if (senalactual != senalantigua)
  {
    lcd.setCursor(1, 0);
    lcd.print("  ");
  }
  senalantigua = senalactual;


}
}

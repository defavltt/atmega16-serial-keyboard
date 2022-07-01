#define DR(port, pin) !((port >> pin) & B00000001) //fast pin reading

#define p22(state) if(DR(PINC, 6) == HIGH && DR(PINC, 6) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 6);
#define p23(state) if(DR(PINC, 7) == HIGH && DR(PINC, 7) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 7);
#define p24(state) if(DR(PINC, 4) == HIGH && DR(PINC, 4) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 4);
#define p25(state) if(DR(PINC, 5) == HIGH && DR(PINC, 5) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 5);
#define p26(state) if(DR(PINC, 2) == HIGH && DR(PINC, 2) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 2);
#define p27(state) if(DR(PINC, 3) == HIGH && DR(PINC, 3) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINC, 3);
#define p28(state) if(DR(PIND, 6) == HIGH && DR(PIND, 6) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 6);
#define p29(state) if(DR(PIND, 7) == HIGH && DR(PIND, 7) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 7);
#define p30(state) if(DR(PIND, 4) == HIGH && DR(PIND, 4) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 4);
#define p31(state) if(DR(PIND, 5) == HIGH && DR(PIND, 5) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 5);
#define p32(state) if(DR(PIND, 2) == HIGH && DR(PIND, 2) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 2);
#define p33(state) if(DR(PIND, 3) == HIGH && DR(PIND, 3) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PIND, 3);
#define p34(state) if(DR(PINB, 4) == HIGH && DR(PINB, 4) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 4);
#define p35(state) if(DR(PINB, 5) == HIGH && DR(PINB, 5) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 5);
#define p36(state) if(DR(PINB, 2) == HIGH && DR(PINB, 2) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 2);
#define p37(state) if(DR(PINB, 3) == HIGH && DR(PINB, 3) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 3);
#define p38(state) if(DR(PINB, 0) == HIGH && DR(PINB, 0) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 0);
#define p39(state) if(DR(PINB, 1) == HIGH && DR(PINB, 1) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINB, 1);
#define p40(state) if(DR(PINA, 1) == HIGH && DR(PINA, 1) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 1);
#define p41(state) if(DR(PINA, 0) == HIGH && DR(PINA, 0) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 0);
#define p42(state) if(DR(PINA, 3) == HIGH && DR(PINA, 3) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 3);
#define p43(state) if(DR(PINA, 2) == HIGH && DR(PINA, 2) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 2);
#define p44(state) if(DR(PINA, 5) == HIGH && DR(PINA, 5) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 5);
#define p45(state) if(DR(PINA, 4) == HIGH && DR(PINA, 4) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 4);
#define p46(state) if(DR(PINA, 7) == HIGH && DR(PINA, 7) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 7);
#define p47(state) if(DR(PINA, 6) == HIGH && DR(PINA, 6) != state) { statebuffer = 1; } else { statebuffer = 0; }  state = DR(PINA, 6);

bool statebuffer;

bool keystate[81];

bool shiftkey;
bool capskey;

/*key macro presets*/
byte mode = 0; //0 - default map, 1 - sx1276 config, 2 - pocsag config

void setup() {
  Serial.begin(9600);
  pinMode(PIN_PC0, OUTPUT); //caps led
  
  while(true) {
    pulluppins();
    pinMode(PIN_PB4, OUTPUT);
    digitalWrite(PIN_PB4, LOW);
    p38(keystate[64]) if(statebuffer) { //38
      mode = 4; //F4
    }
    p39(keystate[65]) if(statebuffer) { //39
      mode = 2; //F2
    }
    p40(keystate[66]) if(statebuffer) { //40
      mode = 8; //F8
    }
    p41(keystate[67]) if(statebuffer) { //41
      mode = 6; //F6
    }
    p42(keystate[68]) if(statebuffer) { //42
      mode = 12; //F12
    }
    p43(keystate[69]) if(statebuffer) { //43
      mode = 10; //F10
    }
    p46(keystate[70]) if(statebuffer) { //46
      Serial.begin(115200); //DEL
    }
  
    pulluppins();
    pinMode(PIN_PB3, OUTPUT);
    digitalWrite(PIN_PB3, LOW);
    p38(keystate[72]) if(statebuffer) { //38
      mode = 3; //F3
    }
    p39(keystate[73]) if(statebuffer) { //39
      mode = 1; //F1
    }
    p40(keystate[74]) if(statebuffer) { //40
      mode = 7; //F7
    }
    p41(keystate[75]) if(statebuffer) { //41
      mode = 5; //F5
    }
    p42(keystate[76]) if(statebuffer) { //42
      mode = 11; //F11
    }
    p43(keystate[77]) if(statebuffer) { //43
      mode = 9; //F9
    }
    
    shiftkey = 1; //turn on led by enabling shift
    if(millis() > 3000) {
      return;
    }
  }
  shiftkey = 0; //turn off led by letting shift off


  
}

void loop() {
  scankeyboard();

}

void scankeyboard() {
  column0();
  column3();
  column5();
  column7();
  column8();
  column9();
  column10();
  column11();
  column12();
  column14();
  column15();
  
//  digitalWrite(PIN_PC0, shiftkey); //caps led
}

void pulluppins() {
  DDRC = 0b00000001; //make input
  if(shiftkey) {
    PORTC = 0b11111101; //1-6 //pull up
  } else {
    PORTC = 0b11111100; //1-6 //pull up
  }
  DDRD = 0b00000000;
  PORTD = 0b11111100; //7-12
  DDRB = 0b00000000;
  PORTB = 0b00111111; //13-18
  DDRA = 0b00000000;
  PORTA = 0b11111111; //19-26
}

void column0() { //22
  pulluppins();

  pinMode(PIN_PC6, OUTPUT);
  digitalWrite(PIN_PC6, LOW);
  
  p23(keystate[0]) if(statebuffer) { //23
    Serial.write(217); //CTRL
  }
  p24(keystate[1]) if(statebuffer) { //24
    Serial.write(219); //HOME
  }
//  p26(keystate[2]) if(statebuffer) { //26
//    Serial.print("L SHIFT");
//  }
  if(DR(PINC, 2)) {
    //text+=String("L SHIFT");
    if(capskey) {
      shiftkey = false;
    } else {
      shiftkey = true;
    }
  } else {
    shiftkey = capskey;
  }
  p28(keystate[3]) if(statebuffer) { //28
    Serial.write(220); //L ALT
  }
  if(shiftkey) {
    p38(keystate[4]) if(statebuffer) { //38
      Serial.print("V");
    }
    p39(keystate[5]) if(statebuffer) { //39
      Serial.print("F");
    }
    p40(keystate[6]) if(statebuffer) { //40
      Serial.print("L");
    }
    p42(keystate[7]) if(statebuffer) { //42
      Serial.print(">");
    }
    p43(keystate[8]) if(statebuffer) { //43
      Serial.print("<");
    }
  } else {
    p38(keystate[4]) if(statebuffer) { //38
      Serial.print("v");
    }
    p39(keystate[5]) if(statebuffer) { //39
      Serial.print("f");
    }
    p40(keystate[6]) if(statebuffer) { //40
      Serial.print("l");
    }
    p42(keystate[7]) if(statebuffer) { //42
      Serial.print(".");
    }
    p43(keystate[8]) if(statebuffer) { //43
      Serial.print(",");
    }
  }
  p44(keystate[9]) if(statebuffer) { //44
    Serial.write(221); //R ALT
  }
  p45(keystate[10]) if(statebuffer) { //45
    Serial.write(222); //MENU
  }
  p46(keystate[11]) if(statebuffer) { //46
    Serial.write(253); //RIGHT
  }
}

void column3() { //25
  pulluppins();

  pinMode(PIN_PC5, OUTPUT);
  digitalWrite(PIN_PC5, LOW);

  p27(keystate[12]) if(statebuffer) { //27
    Serial.write(218); //FN
  }
}

void column5() { //27
  pulluppins();

  pinMode(PIN_PC3, OUTPUT);
  digitalWrite(PIN_PC3, LOW);

  if(shiftkey) {
    p30(keystate[13]) if(statebuffer) { //30
      Serial.print("Z");
    }
    p35(keystate[14]) if(statebuffer) { //35
      Serial.print("X");
    }
    p36(keystate[15]) if(statebuffer) { //36
      Serial.print("C");
    }
    p38(keystate[16]) if(statebuffer) { //38
      Serial.print("H");
    }
    p39(keystate[17]) if(statebuffer) { //39
      Serial.print("G");
    }
    p40(keystate[18]) if(statebuffer) { //40
      Serial.print("K");
    }
    p41(keystate[19]) if(statebuffer) { //41
      Serial.print("B");
    }
    p43(keystate[20]) if(statebuffer) { //43
      Serial.print("M");
    }
  } else {
    p30(keystate[13]) if(statebuffer) { //30
      Serial.print("z");
    }
    p35(keystate[14]) if(statebuffer) { //35
      Serial.print("x");
    }
    p36(keystate[15]) if(statebuffer) { //36
      Serial.print("c");
    }
    p38(keystate[16]) if(statebuffer) { //38
      Serial.print("h");
    }
    p39(keystate[17]) if(statebuffer) { //39
      Serial.print("g");
    }
    p40(keystate[18]) if(statebuffer) { //40
      Serial.print("k");
    }
    p41(keystate[19]) if(statebuffer) { //41
      Serial.print("b");
    }
    p43(keystate[20]) if(statebuffer) { //43
      Serial.print("m");
    }
  }
  p45(keystate[21]) if(statebuffer) { //45
    Serial.print(" ");
  }
}

void column7() { //29
  pulluppins();

  pinMode(PIN_PD7, OUTPUT);
  digitalWrite(PIN_PD7, LOW);

  if(shiftkey) {
    p36(keystate[22]) if(statebuffer) { //36
      Serial.print("D");
    }
    p38(keystate[23]) if(statebuffer) { //38
      Serial.print("Y");
    }
    p39(keystate[24]) if(statebuffer) { //39
      Serial.print("R");
    }
    p40(keystate[25]) if(statebuffer) { //40
      Serial.print("O");
    }
    p41(keystate[26]) if(statebuffer) { //41
      Serial.print("N");
    }
    p42(keystate[27]) if(statebuffer) { //42
      Serial.print('"');
    }
    p43(keystate[28]) if(statebuffer) { //43
      Serial.print(":");
    }
  } else {
    p36(keystate[22]) if(statebuffer) { //36
      Serial.print("d");
    }
    p38(keystate[23]) if(statebuffer) { //38
      Serial.print("y");
    }
    p39(keystate[24]) if(statebuffer) { //39
      Serial.print("r");
    }
    p40(keystate[25]) if(statebuffer) { //40
      Serial.print("o");
    }
    p41(keystate[26]) if(statebuffer) { //41
      Serial.print("n");
    }
    p42(keystate[27]) if(statebuffer) { //42
      Serial.print("'");
    }
    p43(keystate[28]) if(statebuffer) { //43
      Serial.print(";");
    }
  }
  p45(keystate[29]) if(statebuffer) { //45
    Serial.write(252); //LEFT
  }
  p46(keystate[30]) if(statebuffer) { //46
    Serial.write(255); //DOWN
  }
}

void column8() { //30
  pulluppins();

  pinMode(PIN_PD4, OUTPUT);
  digitalWrite(PIN_PD4, LOW);

  if(shiftkey) {
    p31(keystate[31]) if(statebuffer) { //31
      Serial.print("A");
    }
  } else {
    p31(keystate[31]) if(statebuffer) { //31
      Serial.print("a");
    }
  }
  p33(keystate[32]) if(statebuffer) { //33
//    Serial.print("CAPS");
    capskey = !capskey;
  }
}

void column9() { //31
  pulluppins();

  pinMode(PIN_PD5, OUTPUT);
  digitalWrite(PIN_PD5, LOW);

  if(shiftkey) {
    p35(keystate[33]) if(statebuffer) { //35
      Serial.print("S");
    }
    p36(keystate[34]) if(statebuffer) { //36
      Serial.print("W");
    }
    p38(keystate[35]) if(statebuffer) { //38
      Serial.print("T");
    }
    p39(keystate[36]) if(statebuffer) { //39
      Serial.print("E");
    }
    p40(keystate[37]) if(statebuffer) { //40
      Serial.print("I");
    }
    p41(keystate[38]) if(statebuffer) { //41
      Serial.print("J");
    }
    p42(keystate[39]) if(statebuffer) { //42
      Serial.print("}");
    }
    p43(keystate[40]) if(statebuffer) { //43
      Serial.print("P");
    }
    p45(keystate[41]) if(statebuffer) { //45
      Serial.print("?");
    }
  } else {
    p35(keystate[33]) if(statebuffer) { //35
      Serial.print("s");
    }
    p36(keystate[34]) if(statebuffer) { //36
      Serial.print("w");
    }
    p38(keystate[35]) if(statebuffer) { //38
      Serial.print("t");
    }
    p39(keystate[36]) if(statebuffer) { //39
      Serial.print("e");
    }
    p40(keystate[37]) if(statebuffer) { //40
      Serial.print("i");
    }
    p41(keystate[38]) if(statebuffer) { //41
      Serial.print("j");
    }
    p42(keystate[39]) if(statebuffer) { //42
      Serial.print("]");
    }
    p43(keystate[40]) if(statebuffer) { //43
      Serial.print("p");
    }
    p45(keystate[41]) if(statebuffer) { //45
      Serial.print("/");
    }
  }
  p46(keystate[42]) if(statebuffer) { //46
    Serial.print("\n");
  }
}

void column10() { //32
  pulluppins();

  pinMode(PIN_PD2, OUTPUT);
  digitalWrite(PIN_PD2, LOW);

  p35(keystate[43]) if(statebuffer) { //35
    Serial.write(216); //TAB
  }
  if(shiftkey) {
    p36(keystate[44]) if(statebuffer) { //36
      Serial.print("!");
    }
    p38(keystate[45]) if(statebuffer) { //38
      Serial.print("%");
    }
    p39(keystate[46]) if(statebuffer) { //39
      Serial.print("#");
    }
    p40(keystate[47]) if(statebuffer) { //40
      Serial.print("*");
    }
    p41(keystate[48]) if(statebuffer) { //41
      Serial.print("&");
    }
    p42(keystate[49]) if(statebuffer) { //42
      Serial.print("+");
    }
    p43(keystate[50]) if(statebuffer) { //43
      Serial.print(")");
    }
  } else {
    p36(keystate[44]) if(statebuffer) { //36
      Serial.print("1");
    }
    p38(keystate[45]) if(statebuffer) { //38
      Serial.print("5");
    }
    p39(keystate[46]) if(statebuffer) { //39
      Serial.print("3");
    }
    p40(keystate[47]) if(statebuffer) { //40
      Serial.print("8");
    }
    p41(keystate[48]) if(statebuffer) { //41
      Serial.print("7");
    }
    p42(keystate[49]) if(statebuffer) { //42
      Serial.print("=");
    }
    p43(keystate[50]) if(statebuffer) { //43
      Serial.print("0");
    }
  }
  p46(keystate[51]) if(statebuffer) { //46
//    Serial.print("BSPACE");
    Serial.write(136);
  }
}

void column11() { //33
  pulluppins();

  pinMode(PIN_PD3, OUTPUT);
  digitalWrite(PIN_PD3, LOW);

  if(shiftkey) {
    p35(keystate[52]) if(statebuffer) { //35
      Serial.print("Q");
    }
    p36(keystate[53]) if(statebuffer) { //36
      Serial.print("@");
    }
    p38(keystate[54]) if(statebuffer) { //38
      Serial.print("^");
    }
    p39(keystate[55]) if(statebuffer) { //39
      Serial.print("$");
    }
    p40(keystate[56]) if(statebuffer) { //40
      Serial.print("(");
    }
    p41(keystate[57]) if(statebuffer) { //41
      Serial.print("U");
    }
    p42(keystate[58]) if(statebuffer) { //42
      Serial.print("{");
    }
    p43(keystate[59]) if(statebuffer) { //43
      Serial.print("_");
    }
    p46(keystate[61]) if(statebuffer) { //46
      Serial.print("|");
    }
  } else {
    p35(keystate[52]) if(statebuffer) { //35
      Serial.print("q");
    }
    p36(keystate[53]) if(statebuffer) { //36
      Serial.print("2");
    }
    p38(keystate[54]) if(statebuffer) { //38
      Serial.print("6");
    }
    p39(keystate[55]) if(statebuffer) { //39
      Serial.print("4");
    }
    p40(keystate[56]) if(statebuffer) { //40
      Serial.print("9");
    }
    p41(keystate[57]) if(statebuffer) { //41
      Serial.print("u");
    }
    p42(keystate[58]) if(statebuffer) { //42
      Serial.print("[");
    }
    p43(keystate[59]) if(statebuffer) { //43
      Serial.print("-");
    }
    p46(keystate[61]) if(statebuffer) { //46
      Serial.print("\\");
    }
  }
  p45(keystate[60]) if(statebuffer) { //45
    Serial.write(254); //UP
  }
  p47(keystate[62]) if(statebuffer) { //47
    Serial.write(223); //R SHIFT
  }
}

void column12() { //34
  pulluppins();

  pinMode(PIN_PB4, OUTPUT);
  digitalWrite(PIN_PB4, LOW);

  if(shiftkey) {
    p36(keystate[63]) if(statebuffer) { //36
      Serial.print("~");
    }
  } else {
    p36(keystate[63]) if(statebuffer) { //36
      Serial.print("`");
    }
  }
  p38(keystate[64]) if(statebuffer) { //38
    
    switch(mode) { //F4
      case 0:
        Serial.write(204);
        break;
      case 1:
        Serial.print("RTRANS");
        break;
      case 2:
        Serial.print("RTRANS");
        break;
    }
  }
  p39(keystate[65]) if(statebuffer) { //39
    switch(mode) { //F2
      case 0:
        Serial.write(202);
        break;
      case 1:
        Serial.print("PWR");
        break;
      case 2:
        Serial.print("FREQ");
        break;
    }
  }
  p40(keystate[66]) if(statebuffer) { //40
    switch(mode) { //F8
      case 0:
        Serial.write(208);
        break;
      case 1:
        Serial.print("PRMB");
        break;
      case 2:
        
        break;
    }
  }
  p41(keystate[67]) if(statebuffer) { //41
    switch(mode) { //F6
      case 0:
        Serial.write(206);
        break;
      case 1:
        Serial.print("SF");
        break;
      case 2:
        
        break;
    }
  }
  p42(keystate[68]) if(statebuffer) { //42
    switch(mode) { //F12
      case 0:
        Serial.write(212);
        break;
      case 1:
        
        break;
      case 2:
        
        break;
    }
  }
  p43(keystate[69]) if(statebuffer) { //43
    switch(mode) { //F10
      case 0:
        Serial.write(210);
        break;
      case 1:
        
        break;
      case 2:
        
        break;
    }
  }
  p46(keystate[70]) if(statebuffer) { //46
    Serial.write(215); //DEL
  }
}

void column14() { //36
  pulluppins();

  pinMode(PIN_PB2, OUTPUT);
  digitalWrite(PIN_PB2, LOW);

  p37(keystate[71]) if(statebuffer) { //37
    Serial.write(200); //ESC
  }
}

void column15() { //37
  pulluppins();

  pinMode(PIN_PB3, OUTPUT);
  digitalWrite(PIN_PB3, LOW);

  p38(keystate[72]) if(statebuffer) { //38
    switch(mode) { //F3
      case 0:
        Serial.write(203);
        break;
      case 1:
        Serial.print("RECV");
        break;
      case 2:
        Serial.print("BAUD");
        break;
    }
  }
  p39(keystate[73]) if(statebuffer) { //39
    switch(mode) { //F1
      case 0:
        Serial.write(201);
        break;
      case 1:
        Serial.print("FREQ");
        break;
      case 2:
        Serial.print("ADDR");
        break;
    }
  }
  p40(keystate[74]) if(statebuffer) { //40
    switch(mode) { //F7
      case 0:
        Serial.write(207);
        break;
      case 1:
        Serial.print("BW");
        break;
      case 2:
        
        break;
    }
  }
  p41(keystate[75]) if(statebuffer) { //41
    switch(mode) { //F5
      case 0:
        Serial.write(205);
        break;
      case 1:
        Serial.print("CTRANS");
        break;
      case 2:
        
        break;
    }
  }
  p42(keystate[76]) if(statebuffer) { //42
    switch(mode) { //F11
      case 0:
        Serial.write(211);
        break;
      case 1:
        
        break;
      case 2:
        
        break;
    }
  }
  p43(keystate[77]) if(statebuffer) { //43
    switch(mode) { //F9
      case 0:
        Serial.write(209);
        break;
      case 1:
        Serial.print("MODEM");
        break;
      case 2:
        
        break;
    }
  }
  p45(keystate[78]) if(statebuffer) { //45
    Serial.write(213); //PBREAK
  }
  p46(keystate[79]) if(statebuffer) { //46
    Serial.write(214); //INS
  }
}

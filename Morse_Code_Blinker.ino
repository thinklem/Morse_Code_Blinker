/*
 LED blinks string entered. 
 Use format "HELLO WORLD"
 */

char text[100] = "HELLO WORLD";     /* change to change LED morse message */
int i = 0;
int j = 0;
int k = 0;
char char_key[37] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
                    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char morse_key[37][10] = { "/", ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                      "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..",
                      "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----." };                    

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  for(i = 0; i < strlen(text); i++){
    for(j = 0; j < 37; j++){
      if(text[i] == char_key[j]){
        for(k = 0; k < strlen(morse_key[j]); k++){
          if(morse_key[j][k] == '.'){                 //blink for '.'
            digitalWrite(13, HIGH);   
            delay(200); 
            digitalWrite(13, LOW);
            delay(200);                               //delay after '.'
          } else if(morse_key[j][k] == '-'){          //longer blink for '-'
            digitalWrite(13, HIGH);   
            delay(1000); 
            digitalWrite(13, LOW);
            delay(200);                               //delay after '-'
          } else if(morse_key[j][k] == '/'){          //delay for space between words
            delay(400);
          }
        }
        delay(400);                                  //delay for between characters
      }
    }
  }
  delay(2000);                                        //delay after message
  
}

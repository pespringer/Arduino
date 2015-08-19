// sketch 5-05
int dotDelay = 200;
int ledPin = 13;

char* letters[] = {
  ".-", "-...", "-.-.", "-..", ".", // A-I
  "..-.", "--.", "....", "..",
  ".---", "-.-", ".-..", "--", "-.", // J-R
  "---", ".--.", "--.-", ".-.",
  "...", "-", "..-", "...-", ".--", //S-Z
  "-..-", "-.--", "--.."
};

char* numbers[] = {
  "-----", ".----", "..---", "...--", "....-",
  ".....", "-....", "--...", "---..", "----."
};

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char ch;
  if (ch >= 'a' && ch <= 'z')
  {
    flashSequence(letters[ch - 'a']);
  }
  else if (ch >= 'A' && ch <= 'Z')
  {
    flashSequence(letters[ch - 'A']);
  }
  else if (ch >= '0' && ch <= '9')
  {
    flashSequence(numbers[ch - '0']);
  }
  else if (ch == ' ')
  {
    delay(dotDelay * 4);  // gap between words
  }
}

void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0')
  {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3);  // gap between letters
}


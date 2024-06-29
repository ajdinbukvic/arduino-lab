const int motorPin = 9;
const int dugmeUbrzavanjePin = 2;
const int dugmeUsporavanjePin = 3;
const int dugmeZaustavljanjePin = 4;

const int MAKSIMALNA_BRZINA = 255;
const int MINIMALNA_BRZINA = 0;

const int KORAK_UBRZAVANJA = 5;
const int KORAK_USPORAVANJA = 5;

int brzina = 0;
int prethodnaBrzina = 0;

int zadnjeStanjeUbrzavanje = 0;
int zadnjeStanjeUsporavanje = 0;
int zadnjeStanjeZaustavljanje = 0;

int stanjeUbrzavanje = 0;
int stanjeUsporavanje = 0;
int stanjeZaustavljanje = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(dugmeUbrzavanjePin, INPUT_PULLUP);
  pinMode(dugmeUsporavanjePin, INPUT_PULLUP);
  pinMode(dugmeZaustavljanjePin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  stanjeUbrzavanje = digitalRead(dugmeUbrzavanjePin);
  if (stanjeUbrzavanje != zadnjeStanjeUbrzavanje) {
    zadnjeStanjeUbrzavanje = stanjeUbrzavanje;
    if (stanjeUbrzavanje == HIGH) {
      prethodnaBrzina = brzina;
      brzina += KORAK_UBRZAVANJA;
      if (brzina > MAKSIMALNA_BRZINA) {
        brzina = MAKSIMALNA_BRZINA;
        Serial.println("Postignuta je maksimalna brzina!");
      }
      analogWrite(motorPin, brzina);
      Serial.print("UBRZAVANJE | Stara brzina: ");
      Serial.print(prethodnaBrzina);
      Serial.print(" | ");
      Serial.print("Nova brzina: ");
      Serial.println(brzina);
    }
  }
  stanjeUsporavanje = digitalRead(dugmeUsporavanjePin);
  if (stanjeUsporavanje != zadnjeStanjeUsporavanje) {
    zadnjeStanjeUsporavanje = stanjeUsporavanje;
    if (stanjeUsporavanje == HIGH) {
      prethodnaBrzina = brzina;
      brzina -= KORAK_USPORAVANJA;
      if (brzina < MINIMALNA_BRZINA) {
        brzina = MINIMALNA_BRZINA;
        Serial.println("Postignuta je minimalna brzina!");
      }
      analogWrite(motorPin, brzina);
      Serial.print("USPORAVANJE | Stara brzina: ");
      Serial.print(prethodnaBrzina);
      Serial.print(" | ");
      Serial.print("Nova brzina: ");
      Serial.println(brzina);
    }
  }
  stanjeZaustavljanje = digitalRead(dugmeZaustavljanjePin);
  if (stanjeZaustavljanje != zadnjeStanjeZaustavljanje) {
  zadnjeStanjeZaustavljanje = stanjeZaustavljanje;
    if (stanjeZaustavljanje == HIGH) {
      prethodnaBrzina = brzina;
      brzina = 0;
      analogWrite(motorPin, brzina);
      Serial.print("ZAUSTAVLJaNJE | Stara brzina: ");
      Serial.print(prethodnaBrzina);
      Serial.print(" | ");
      Serial.print("Nova brzina: ");
      Serial.println(brzina);
    }
  }
  delay(50);
}
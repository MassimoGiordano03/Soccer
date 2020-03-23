#define NUM_LINES 6           //Sono i sensori di linea che abbiamo.
#define DEFAULT_TIMER 3000
/**
 * Ci serve questo dato perché viene assegnato alla variabile timer interna alla struttura.
 * Lo spiego meglio quando viene richiamata la variabile.
 */

<<<<<<< 5959a9e17b3489e5aef1395a13f21964189fb597:prova/linee.ino
typedef struct {

  uint8_t pin[NUM_LINES];
  int16_t angoli[NUM_LINES];
  int raw_data[NUM_LINES];
  uint8_t data[NUM_LINES];
  /**
   * Le due variabili raw_data e data sono gli array che salvano i valori che leggono i sensori;
   *
   * raw_data salva le letture grezze dei sensori, data ha solo valori 0 o 1, se sono state rilevare linee o meno
   */
  uint8_t mask[NUM_LINES];
  /**
   * L'array mask serve per l'ulteriore controllo quando si parla delle letture dei sensori,
   * perché le sue variabili vengono messe da 1 solo quando il sensore non ha mai letto prima
   */
  int soglia[NUM_LINES];

  uint8_t flg;
  int timer;
  int tot_angle;      //La somma degli angoli dei sensori che hanno rilevato qualcosa
  uint8_t num_angle;  //Il numero degli angoli che hanno trovato quancosa
  int escape_angle;   //La traiettoria calcolata dalla media dei vettori dagli angoli dei sensori

} MorsLines;

void morslines_init(MorsLines* l, uint8_t t_pin[], int16_t t_angle[], int t_soglia[]) {
=======
void morslines_init(MorsLines* l, uint8_t* t_pin, int* t_angle, int* t_soglia) {
>>>>>>> Correzione di tutti gli errori:main/lines.ino

  for(int i = 0; i < NUM_LINES; i++) {
    l-> pin[i] = t_pin[i];
    l-> angoli[i] = t_angle[i];
    l-> soglia[i] = t_soglia[i];
  }
  l-> tot_angle = LOW;
  l-> num_angle = LOW;
  l-> escape_angle = LOW;
  l-> flg = LOW;

  sbi(ADCSRA, ADPS2);
  cbi(ACDSRA, ADPS1);
  cbi(ACDSRA, ADPS0);
}

void morslines_reset(MorsLines* l) {
  l-> timer = LOW;
  l-> flg = LOW;

  for(int i = 0; i < NUM_LINES; i++) {
    l-> mask[i] = 0;
  }
}

void morslines_read(MorsLines* l) {

  for(int i = 0; i < NUM_LINES; i++) {

    l-> raw_data[i] = analogRead(l-> pin[i]);

    if(l-> raw_data[i] >= l-> soglia[i]) {

      l-> data[i] = HIGH;

    } else {

      l-> data[i] = LOW;
    }
  }
}

void morslines_handle(MorsLines* l) {

  for(int i = 0; i < NUM_LINES; i++) {

    if(l-> mask[i] == LOW) {

      if(l-> data[i] == HIGH) {

        l-> mask[i] = HIGH;
        l-> tot_angle = l-> tot_angle + l-> angoli[i];
        l-> flg = HIGH;
        l-> timer = DEFAULT_TIMER;
        l-> num_angle ++;

        l-> escape_angle = ((l-> tot_angle / l-> num_angle)+ 180)% 360;
      }
    }
  }
  if(l-> flg == HIGH) {
    l-> timer --;

    if(l-> timer == 0) {
      morslines_reset();
    }
  }
}

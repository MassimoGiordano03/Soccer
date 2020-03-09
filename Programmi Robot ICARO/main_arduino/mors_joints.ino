/**
 * Libreria gestione Motori
 *
 * Massimo Giordano, Diego de Martino
 */

void PhoenixJoints_init() {
  pinMode(pinA[0], OUTPUT);
  pinMode(pinA[1], OUTPUT);
  pinMode(pinA[2], OUTPUT);
  pinMode(pinB[0], OUTPUT);
  pinMode(pinB[1], OUTPUT);
  pinMode(pinB[2], OUTPUT);
  pinMode(pinPwm[0], OUTPUT);
  pinMode(pinPwm[1], OUTPUT);
  pinMode(pinPwm[2], OUTPUT);
}

void PhoenixJoints_setSpeed (byte N_Mot, int val) {

  if(val >= 0) {
    digitalWrite(pinA[N_Mot], LOW);
    digitalWrite(pinB[N_Mot], HIGH);
    if(val > 255) val = 255;
    analogWrite(pinPwm[N_Mot], val);
  } else {
    digitalWrite(pinA[N_Mot], HIGH);
    digitalWrite(pinB[N_Mot], LOW);
    if(val < -255) val = -255;
    analogWrite(pinPwm[N_Mot], -val);
  }

// switch (N_Mot) {
//   case 1:
//     if(val >= 0) {
//       digitalWrite(pinA[0], LOW);
//       digitalWrite(pinB[0], HIGH);
//       analogWrite(pinPwm[0], val);
//     } else {
//       digitalWrite(pinA[0], HIGH);
//       digitalWrite(pinB[0], LOW);
//       analogWrite(pinPwm[0], -val);
//     } break;
//   case 2:
//     if(val >= 0) {
//       digitalWrite(pinA[1], LOW);
//       digitalWrite(pinB[1], HIGH);
//       analogWrite(pinPwm[1], val);
//     } else {
//       digitalWrite(pinA[1], HIGH);
//       digitalWrite(pinB[1], LOW);
//       analogWrite(pinPwm[1], -val);
//     } break;
//   case 3:
//     if(val >= 0) {
//       digitalWrite(pinA[2], LOW);
//       digitalWrite(pinB[2], HIGH);
//       analogWrite(pinPwm[2], val);
//     } else {
//       digitalWrite(pinA[2], HIGH);
//       digitalWrite(pinB[2], LOW);
//       analogWrite(pinPwm[2], -val);
//     } break;
// }

}

// void joints_goAhead() {
//
//   digitalWrite(pinA[0], LOW);
//   digitalWrite(pinB[0], HIGH);
//   analogWrite(pinPwm[0], pot);
//
//   digitalWrite(pinA[2], HIGH);
//   digitalWrite(pinB[2], LOW);
//   analogWrite(pinPwm[2], pot);
//
// }
//
// void joints_goAheadLeft() {
//
//   digitalWrite(pinA[1], LOW);
//   digitalWrite(pinB[1], HIGH);
//   analogWrite(pinPwm[1], pot);
//
//   digitalWrite(pinA[2], HIGH);
//   digitalWrite(pinB[2], LOW);
//   analogWrite(pinPwm[2], pot);
//
// }
//
// void joints_goAheadRight() {
//
//   digitalWrite(pinA[0], LOW);
//   digitalWrite(pinB[0], HIGH);
//   analogWrite(pinPwm[0], pot);
//
//   digitalWrite(pinA[1], HIGH);
//   digitalWrite(pinB[1], LOW);
//   analogWrite(pinPwm[1], pot);
//
// }
//
// void joints_goBackLeft() {
//
//   digitalWrite(pinA[0], HIGH);
//   digitalWrite(pinB[0], LOW);
//   analogWrite(pinPwm[0], pot);
//
//   digitalWrite(pinA[1], LOW);
//   digitalWrite(pinB[1], HIGH);
//   analogWrite(pinPwm[1], pot);
//
// }
//
// void joints_goBackRight() {
//
//   digitalWrite(pinA[1], HIGH);
//   digitalWrite(pinB[1], LOW);
//   analogWrite(pinPwm[1], pot);
//
//   digitalWrite(pinA[2], LOW);
//   digitalWrite(pinB[2], HIGH);
//   analogWrite(pinPwm[2], pot);
//
// }
//
// void joints_goBack() {
//
//   digitalWrite(pinA[0], HIGH);
//   digitalWrite(pinB[0], LOW);
//   analogWrite(pinPwm[0], pot);
//
//   digitalWrite(pinA[2], LOW);
//   digitalWrite(pinB[2], HIGH);
//   analogWrite(pinPwm[2], pot);
//
// }

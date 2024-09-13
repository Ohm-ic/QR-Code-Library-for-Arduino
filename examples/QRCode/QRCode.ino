#include <QR_code.h>

QRCodeGenerator qr;

void setup() {
    Serial.begin(115200);
    delay(1000);  // Small delay for serial connection to establish
    qr.initText("Arduino", 4, ECC_LOW);  // Increased version for larger QR cod
    qr.printToSerial();
}

void loop() {
    // No loop code required for this demo
}

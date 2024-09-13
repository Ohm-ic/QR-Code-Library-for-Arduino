#ifndef ARDUINO_QR_CODE_H
#define ARDUINO_QR_CODE_H

#include <Arduino.h>   // Include for Serial and Arduino functions
#include "qrcode.h"    // Include the original QR code generator file

class QRCodeGenerator {
public:
    QRCodeGenerator();
    ~QRCodeGenerator();

    bool initText(const char *text, uint8_t version = 1, uint8_t ecc = ECC_LOW);
    void printToSerial();

private:
    QRCode qrcode;
    uint8_t *qrcodeData;
};

#endif // ARDUINO_QR_CODE_H

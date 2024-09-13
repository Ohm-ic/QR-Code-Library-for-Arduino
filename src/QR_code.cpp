#include "QR_code.h"
#include <cstdlib>  // For malloc and free

QRCodeGenerator::QRCodeGenerator() {
    qrcodeData = nullptr;
}

QRCodeGenerator::~QRCodeGenerator() {
    if (qrcodeData != nullptr) {
        free(qrcodeData);
    }
}

bool QRCodeGenerator::initText(const char *text, uint8_t version, uint8_t ecc) {
    uint16_t bufferSize = qrcode_getBufferSize(version);
    qrcodeData = (uint8_t *)malloc(bufferSize);
    if (qrcodeData == nullptr) {
        return false;
    }
    return qrcode_initText(&qrcode, qrcodeData, version, ecc, text) == 0;
}

void QRCodeGenerator::printToSerial() {
    for (uint8_t y = 0; y < qrcode.size; y++) {
        for (uint8_t x = 0; x < qrcode.size; x++) {
            Serial.print(qrcode_getModule(&qrcode, x, y) ? "██" : "  ");
        }
        Serial.println();                     
    }
}   


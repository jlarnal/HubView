#include <Arduino.h>
#include "sdkconfig.h"
#include <Hub75S3/Hub75S3.h>

using MyDisplay = Hub75S3Display<
    128, 64, 1, 1,
    Hub75S3::MatrixPortalS3Pins,
    Hub75S3::PixelFormat::RGB888,
    Hub75S3::BufferMode::Double,
    Hub75S3::MemoryPolicy::PsramFramebuf
>;

MyDisplay display;

void setup() {
    esp_err_t err = display.begin();
    if (err != ESP_OK) return;

    display.setBrightness(128);
    display.fillScreen(0x000000);
    display.drawPixel(64, 32, 0xFF0000);
    display.swap();
}

void loop() {
}

// test/test_main.cpp

#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

// Define el pin del LED
#define LED_PIN 2

// Simula el código que queremos probar
void setupLED() {
    pinMode(LED_PIN, OUTPUT);
}

void controlLED() {
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}

// Test unitario usando ArduinoFake
void test_led_behavior() {
    // Simula la función pinMode
    When(Method(ArduinoFake(), pinMode)).AlwaysReturn();
    
    // Simula las funciones digitalWrite y delay
    When(Method(ArduinoFake(), digitalWrite));
    When(Method(ArduinoFake(), delay));

    // Llama a las funciones que deseamos probar
    setupLED();
    controlLED();

    // Verifica que el pin se configuró como OUTPUT
    Verify(Method(ArduinoFake(), pinMode).Using(LED_PIN, OUTPUT)).Once();

    // Verifica que el LED se encendió y apagó correctamente
    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, HIGH)).Once();
    Verify(Method(ArduinoFake(), digitalWrite).Using(LED_PIN, LOW)).Once();

    // Verifica que los tiempos de delay fueron llamados
    Verify(Method(ArduinoFake(), delay).Using(500)).Once();
    Verify(Method(ArduinoFake(), delay).Using(1000)).Once();
}

void setup() {
    // Inicia Unity para las pruebas
    UNITY_BEGIN();
    RUN_TEST(test_led_behavior);
    UNITY_END();
}

void loop() {
    // No necesitamos un loop para las pruebas
}

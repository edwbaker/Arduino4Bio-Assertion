#define __ASSERT_USE_STDERR
#include <assert.h>

void setup() {
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  float f = 66000;
  unsigned int i;
  Serial.println("Begin assertion");
  assert(f <=  65535);
  assert(f >= 0);
  i = (int)f;
}

void __assert(const char *__function, const char *__file, int __line, const char *__assertion) {
// transmit diagnostic informations through serial link.
Serial.print("Fail: ");
Serial.print(__assertion);
Serial.print(": ");
Serial.print(__file);
Serial.print(":");
Serial.print(__line, DEC);
Serial.print(" in function ");
Serial.println(__function);
Serial.flush();
// abort program execution.
abort();
}

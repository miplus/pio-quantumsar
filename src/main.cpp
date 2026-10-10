#include <Arduino.h>
#include "Crypto.h"


void setup() {
    char buffer[64];

    unsigned long begin, end ;

    Serial.begin(9600);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
    }
    sprintf(buffer, "%s, %s, %s", __DATE__, __TIME__, __FILE__);
    Serial.println(buffer);
    /*
    begin = micros();
    FsmSw_Crypto_DigitalSignatureTest();
    end = micros();
    sprintf(buffer, "test time %lu \n", (end - begin));
    Serial.println(buffer);
    */
    #if (defined KYBER512)
      sprintf(buffer, "KYBER512 \n");
      Serial.println(buffer);
    #elif (defined KYBER768)
      sprintf(buffer, "KYBER768 \n");
      Serial.println(buffer);
    #elif (defined KYBER1024)
      sprintf(buffer, "KYBER1024 \n");
      Serial.println(buffer);
    #endif

#if (defined KYBER512) || (defined KYBER768) || (defined KYBER1024)
    
    begin = micros();
    FsmSw_Crypto_DigitalKemKeypairs();
    end = micros();
    sprintf(buffer, "keypair time %lu \n", ((end - begin) / 2));
    Serial.print(buffer);
    
    begin = micros();
    FsmSw_Crypto_DigitalKemEncapsulte();
    end = micros();
    sprintf(buffer, "encapsualte time %lu \n", ((end - begin) / 2));
    Serial.print(buffer);
    
    begin = micros();
    FsmSw_Crypto_DigitalKemDecapsulte();
    end = micros();
    sprintf(buffer, "decapsulate time %lu \n", ((end - begin) / 2));
    Serial.print(buffer);

#endif


    #if (defined DILITHIUM2)
      sprintf(buffer, "DILITHIUM2 \n");
      Serial.println(buffer);
    #elif (defined DILITHIUM3)
      sprintf(buffer, "DILITHIUM3 \n");
      Serial.println(buffer);
    #elif (defined DILITHIUM5)
      sprintf(buffer, "DILITHIUM5 \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_128FSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_128FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_128SSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_128SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_192FSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_192FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_192SSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_192SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_256FSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_256FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHA2_256SSIMPLE)
      sprintf(buffer, "SPHINCS_SHA2_256SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_128FSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_128FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_128SSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_128SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_192FSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_192FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_192SSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_192SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_256FSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_256FSIMPLE \n");
      Serial.println(buffer);
    #elif (defined SPHINCS_SHAKE_256SSIMPLE)
      sprintf(buffer, "SPHINCS_SHAKE_256SSIMPLE \n");
      Serial.println(buffer);
    #elif (defined FALCON512)
      sprintf(buffer, "FALCON512 \n");
      Serial.println(buffer);
    #elif (defined FALCON1024)
      sprintf(buffer, "FALCON1024 \n");
      Serial.println(buffer);
    #endif


    begin = micros();
    FsmSw_Crypto_DigitalSignatureKeypair();
    end = micros();
    sprintf(buffer, "keypair time %lu \n", (end - begin));
    Serial.print(buffer);
    
    begin = micros();
    FsmSw_Crypto_DigitalSignatureSignature();
    end = micros();
    sprintf(buffer, "signature time %lu \n", (end - begin));
    Serial.print(buffer);

    begin = micros();
    FsmSw_Crypto_DigitalSignatureVerify();
    end = micros();
    sprintf(buffer, "verify time %lu \n", (end - begin));
    Serial.print(buffer);

    begin = micros();
    FsmSw_Crypto_DigitalSignatureSign();
    end = micros();
    sprintf(buffer, "sign time %lu \n", (end - begin));
    Serial.print(buffer);

    begin = micros();
    FsmSw_Crypto_DigitalSignatureSignOpen();
    end = micros();
    sprintf(buffer, "sign open time %lu \n", (end - begin));
    Serial.print(buffer);

}

void loop() {
  // put your main code here, to run repeatedly:
}

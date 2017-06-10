void initPPD42NS(){
  pinMode(PPD42NS_PIN,INPUT);
}

float getPPD42NS(){
    ratio = duration/(elapsedtime*10.0);
    concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62;
    timestamp=millis()/1000;
    // Reset values for next sampling period.
    duration = 0;
    return concentration;
}

void updatePPD42NS(){
  duration = duration + pulseIn(PPD42NS_PIN, LOW);
  elapsedtime=millis()-starttime;
}


void initPMS5003(){
  pms.begin();
  pms.waitForData(Pms5003::wakeupTime);
  pms.write(Pms5003::cmdModeActive);
}

void updatePMS5003(){
  const auto n = Pms5003::Reserved;
  Pms5003::pmsData data[n];

  Pms5003::PmsStatus status = pms.read(data, n);

  switch (status) {
    case Pms5003::OK:
    {
      
      auto newRead = millis();
      
      //Serial.println(newRead - lastRead);
      lastRead = newRead;
      workingStringPMS5003 = "";
      for (size_t i = Pms5003::PM1dot0; i < n; ++i) { 
        workingStringPMS5003 +=",";
        workingStringPMS5003 += data[i];
       
      }
     // return workingStringPMS5003;
      break;
    }
    case Pms5003::noData:
      break;
    default:
      break;
  };
}


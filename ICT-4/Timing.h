void TXtiming() // Timing
{
  // run additional scripts here to generate data prior to TX if there is a large delay involved.
    if ((timeStatus() == timeSet) && (second() == 0) && (minute() >= 0)) 
   {
    setGPStime();
    
    if ((minute() % 10 == 0) && (second() <= 0)) // TX WSPR standard message
    {
      telemetry_set = true;
      loc4calc(); // Get position and update 4-char locator, 6-char locator and last 2 chars of 8-char locator
      call_telem(); // Update WSPR telemetry callsign based on previous information : position and altitude in meters
      loc_dbm_telem(); // Update WSPR telemetry locator and dbm. Get temperature, voltage, speed in knots, GPS status and sats number
      gps_off(); delay(10);
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      gps_on();
    }
    
    else if ((minute() % 10 == 2) && (second() <= 0) && (telemetry_set == true))    // TX WSPR telemetry message
    {
      gps_off(); delay(10); 
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR_telem(); // set WSPR telemetry mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      gps_on();
    }
    
    else if ((minute() % 10 == 4) && (second() <= 0) && (telemetry_set == true))    // TX WSPR standard message
    {
      gps_off(); delay(10);
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      gps_on();
    }
    
    else if ((minute() % 10 == 6) && (second() <= 0) && (telemetry_set == true))    // TX WSPR standard message
    {
      gps_off(); delay(10);
      rf_on();
      freq = WSPR_FREQ;
      setModeWSPR(); // set WSPR standard mode
      encode(); // begin radio transmission
      rf_off(); delay(5);
      gps_on();
   }

     else if ((minute() % 10 == 8) && (second() <= 0)) // Check location age/validity and software GPS reset if necessary
    {
     if (gps.location.age() > 800000)
    {
        gps_reset();
        delay(1000);
        gps_airborne(); // set GPS into airborne mode
        delay(1000);
        gps_set_max_performance_mode();
        delay(1000);
    } 
    }
    }
    }
    

void sendJsonGraph() {
  simpletx("\n");
  
//first line, fuel use

simpletx("["); 
//simpletx("{\"title\":\"Fuel\",\"subtitle\":\"US Gallons\",\"ranges\":[3,");
simpletx("{\"title\":\"Fuel\",\"subtitle\":\"US Gallons\",\"ranges\":[");
simpletx(format (parms[tankSizeIdx]-fuelReserveGalIdx));
simpletx(","); 
simpletx(intformat( (parms[tankSizeIdx])));
//if (instantgph() < 1000) {
//simpletx("16");
//} else if (instantgph() < 10000) {
//simpletx("160");
//} else {
//simpletx("1600");
//}
simpletx("],\"measures\":[");
simpletx(format( (parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() )  );
simpletx(",");
simpletx(format (parms[tankSizeIdx] - tank.gallons())   );
simpletx("],\"markers\":[");
//simpletx(format(parms[tankSizeIdx]-1500 ));
//simpletx(format( 1500 )); //sets marker at BINGO fuel 
//simpletx(format(millis2()%13499));  //line sweeps to show data flowing
//simpletx(",");
if (instantgph() < 1000) {
  simpletx(format(instantgph() * 10 )); 
} else if (instantgph() < 10000) {
  simpletx(format(instantgph() * 1 )); 
} else {
  simpletx(format(instantgph() * .1)); 
}
simpletx("]},");    

//second line, dte/rng

simpletx("");

//simpletx("{\"title\":\"Distance\",\"subtitle\":\"US miles\",\"ranges\":[100,");
simpletx("{\"title\":\"Distance\",\"subtitle\":\"US miles\",\"ranges\":[");
simpletx(intformat(  getBRNG() / 2  ));
simpletx(","); 
simpletx(intformat(getBRNG()));
simpletx(","); 
simpletx(intformat(getRNG()));
simpletx("],\"measures\":[");
//simpletx(intformat(getRNG() - getDTB()));  //longer line, miles traveled + mpg*reserve; counts up
simpletx(intformat(tank.mpg() * (fuelReserveGalIdx / 1000)));  //longer line initially, flips to shorter, miles traveled + mpg*reserve; counts up
simpletx(",");
simpletx(intformat(getRNG() - getDTE()));  //shorter line initially, miles traveled raw, flips to longer line
simpletx("],\"markers\":[ ");
//simpletx(format(tank.mpg() * 1.5 )); line is bingo in miles, not gallons
simpletx(format(getDTE())); //line is distance to empty
simpletx("]},");

//third line, mpg

simpletx("");
simpletx("{\"title\":\"Fuel Economy\",\"subtitle\":\"US miles\",\"ranges\":[18,24,40],\"measures\":[");
//simpletx("{\"title\":\"Fuel Economy\",\"subtitle\":\"US miles ");
//simpletx(intformat(millis2()%60000));
//simpletx("\",\"ranges\":[18,24,40],\"measures\":[");
simpletx(format(MIN(40000,current.mpg() )));
simpletx(",");
//simpletx(intformat( instant.mpg()    ));  
simpletx(format(MIN(40000,tank.mpg() )));

simpletx("],\"markers\":[");
simpletx(format(MIN(40000,instant.mpg() )));
//simpletx(",");
//simpletx(format(MIN(40000,tank.mpg() )));
simpletx("]}");
simpletx("]");

simpletx("\r");
//{\"mpguino\":{\""); 
//"
}


























void sendJsonGraphOld() {

//first line, fuel use
//simpletx("\n"); 
//simpletx("\r");
simpletx("[\n"); 
simpletx("{\"title\":\"Fuel\",\"subtitle\":\"US Gallons\",\"ranges\":[1.5,");
simpletx(format (parms[tankSizeIdx]-fuelReserveGalIdx));
simpletx(","); 
simpletx(format( (parms[tankSizeIdx])));
simpletx("],\"measures\":[");
simpletx(format( (parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() )  );
simpletx(",");
simpletx(format (parms[tankSizeIdx] - tank.gallons())   );
simpletx("],\"markers\":[");
simpletx(format(parms[tankSizeIdx]-fuelReserveGalIdx ));
simpletx("]},");    

//second line, dte/rng

simpletx("\n");

simpletx("{\"title\":\"Distance\",\"subtitle\":\"US miles\",\"ranges\":[100,");
simpletx(intformat(getBRNG()));
simpletx(","); 
simpletx(intformat(getRNG()));
simpletx("],\"measures\":[");
simpletx(intformat(getDTB())); 
//simpletx(format( (parms[tankSizeIdx] - 1500) - tank.gallons() )  );
simpletx(",");
simpletx(intformat(getDTE())); 
//simpletx(format (parms[tankSizeIdx] - tank.gallons())   );
simpletx("],\"markers\":[");
simpletx(format(tank.mpg() * fuelReserveGalIdx ));
simpletx("]},");

//third line, mpg

simpletx("\n");
//simpletx(" [
simpletx("{\"title\":\"Fuel Economy\",\"subtitle\":\"US miles\",\"ranges\":[10,20,30],\"measures\":[");
simpletx(intformat( current.mpg()    )); 
simpletx(",");
simpletx(intformat( tank.mpg()    ));  
simpletx("],\"markers\":[");
simpletx(format(tank.mpg() * 1500 ));
simpletx("]}");
simpletx("\n]\n");

simpletx("\r");
//{\"mpguino\":{\""); 
//"
}

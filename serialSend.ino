


void sendJsonGraph() {
  
  simpletx("\n");
  
//first line, fuel use

simpletx("["); 

simpletx("{\"title\":\"fuel used");
simpletx(format ( current.gallons() )); //tank fuel used
simpletx("/"); 
simpletx(format ( tank.gallons() )); //trip fuel used
simpletx("\",\"subtitle\":\"");
if (  ((parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() ) > parms[tankSizeIdx]) {
  simpletx("fumes");
    } else {
simpletx(format((parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() )  ); //this is remaining
    }
simpletx(" remaining, ");
//simpletx(format (fuelReserveGalIdx));
if (  (parms[tankSizeIdx] - tank.gallons() ) < fuelReserveGalIdx) {
  simpletx(format(parms[tankSizeIdx] - tank.gallons() )); 
  } else {
  simpletx(format(fuelReserveGalIdx)); 
  }
simpletx(" e-reserve");
simpletx(format(tank.idleGallons()));
simpletx(" ga used@idle, "); 
simpletx(format(tank.eocMiles()));
simpletx(" mi fuel cut"); 
simpletx("\",\"ranges\":[");
simpletx(format (parms[tankSizeIdx]-fuelReserveGalIdx));
simpletx(","); 
simpletx(intformat( (parms[tankSizeIdx])));
simpletx(","); 
simpletx(format( (fuelReserveGalIdx)));
simpletx("],\"measures\":[");

if (  ((parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() ) > parms[tankSizeIdx]) {
  simpletx(format(0));
    } else {
  simpletx(format(  (parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() )    ); // (13.8 - 2) = 11.8 - 11.9 = -1 error, unsinged?
}

simpletx(",");
simpletx(format (parms[tankSizeIdx] - tank.gallons())   );
simpletx("],\"markers\":[");
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

simpletx("{\"title\":\"distance");

simpletx(format ( current.miles() )); //tank fuel used
simpletx("/"); 
simpletx(format ( tank.miles() )); //trip fuel used

//simpletx(intformat(getRNG() - getDTE()));  //shorter line initially, miles traveled raw, flips to longer line
simpletx("\",\"subtitle\":\"");
simpletx(intformat(getDTB()));
simpletx("mi to E,"); 
if (    ((parms[tankSizeIdx] - fuelReserveGalIdx) - tank.gallons() ) > parms[tankSizeIdx] ) {  //this line shows reserve miles max
simpletx(intformat(tank.mpg() * (parms[tankSizeIdx] - tank.gallons()) / 1000)    );  //longer line initially, flips to shorter, miles traveled + mpg*reserve; counts up
} else {  //this line shows miles until dry
simpletx(intformat(tank.mpg() * (fuelReserveGalIdx / 1000)));  //longer line initially, flips to shorter, miles traveled + mpg*reserve; counts up
}

simpletx(" mi e-reserve, "); 
simpletx(intformat(getBRNG()));
simpletx("mi safe range,"); 
simpletx(intformat(getRNG()));
simpletx("mi dry range");

simpletx("\",\"ranges\":[");
//simpletx(",");

//simpletx("\",\"subtitle\":\"US miles\",\"ranges\":[");

simpletx(intformat(  getBRNG() / 2  ));
simpletx(","); 
simpletx(intformat(getBRNG()));
simpletx(","); 
simpletx(intformat(getRNG()));
simpletx("],\"measures\":[");
simpletx(intformat(tank.mpg() * (fuelReserveGalIdx / 1000)));  //longer line initially, flips to shorter, miles traveled + mpg*reserve; counts up
simpletx(",");
simpletx(intformat(getRNG() - getDTE()));  //shorter line initially, miles traveled raw, flips to longer line
simpletx("],\"markers\":[ ");
simpletx(format(getDTE())); //line is distance to empty
simpletx("]},");

//third line, mpg

simpletx("");
simpletx("{\"title\":\"fuel economy");
//simpletx("{\"title\":\"fuel economy\",\"subtitle\":\"");
simpletx(format(MIN(40000,current.mpg() )));
simpletx("/"); 
simpletx(format(MIN(40000,tank.mpg() )));
simpletx("\",\"subtitle\":\"drag stats: 0 -");
simpletx(intformat(parms[dragSpeed] * 1000));
simpletx(":");
simpletx(format(myDrag.time100kmh() ));
simpletx(",");
simpletx(format(myDrag.time() )); 
simpletx(" to "); 
simpletx(intformat(parms[dragDistance] * 1000));
simpletx("ft @");
simpletx(format(myDrag.trapspeed() )); 

simpletx("mph\",\"ranges\":[18,24,40],\"measures\":[");
simpletx(format(MIN(40000,current.mpg() )));
simpletx(",");
simpletx(format(MIN(40000,tank.mpg() )));

simpletx("],\"markers\":[");
simpletx(format(MIN(40000,instant.mpg() )));
simpletx("]}"); 

//next line ends JSON payload
simpletx("]");

//sends CR to trigger read on python.script
simpletx("\r");

}

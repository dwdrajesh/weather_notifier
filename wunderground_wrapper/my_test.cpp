//only  this one header is what you need for using a wrapper
#include "wunderground.hpp"
#include <iostream>

// using namespace wunderground;
//using namespace std;

int main(int argc, char * argv[])
{
  string ApiKey="0e2823f92717753c";
  // string ApiKey="241ab74ebf1d023c";
  
  //Condition class provides weather data for today
  wunderground::Conditions weather(ApiKey);
  // printf("%s\n", ApiKey.c_str());
  // //method loadData(), as it name says, loads data for specified city and state
  // weather.loadData("zagreb","croatia");
  weather.loadData("ottawa","canada");
  char * city = "ottawa";
  // char * country = argv[2];
  // weather.loadData(city, country);
  
  // //method printConditions prints all weather data
  // weather.printConditions();
  
  char output_string[256] = {0};
  sprintf(output_string, "Current temperature in %s is %s C", city, weather.getCondition("temperature").c_str());
  printf("%s\n", output_string); 
  // //you can get specified weather data with getCondition() method
  // std::cout<<"Current temperature in " << city << " is: " << weather.getCondition("temperature") << " C" << endl;
  
  // //Forecast10day class provides data for next 10 days
  // wunderground::Forecast10day weather10day(ApiKey);
  
  // weather10day.loadData("paris","france");
  
  // getCondition() method now needs two parametars: condition and a day, if today is Thursday 15th january and
  //   you need weather data for Sunday 18th than you do: 
  // std::cout<<"Highest temperature for Paris on Sunday: "<<weather10day.getCondition("high","18");
  // //...and on Tuesday:
  // std::cout<<"Humidity for Paris on Tuesday: "<<weather10day.getCondition("humidity","20");
  
  
  // //Astronomy class is for sunrise and sunset time
  // wunderground::Astronomy astronomy(ApiKey);
  
  // astronomy.loadData("munich","germany");
  
  // std::cout<<"Sunset time in Munich today is: "<<astronomy.getCondition("sunset");
  
  
  return 0;
  
}
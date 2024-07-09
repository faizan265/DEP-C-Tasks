#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
//#include <curl/curl.h> // Include curl header for HTTP requests
//#include <json/json.h> // Include JsonCpp for JSON pars
using namespace std;

// Define a callback function for curl to write received data into a string
size_t writeCallback(void* contents, size_t size, size_t nmemb, string* data) {
    data->append((char*)contents, size * nmemb);
    return size * nmemb;
}

//Classes prototyping
//weathervariable class definition 
class WeatherVariable 
{
public:
    string name;
    double value;
    WeatherVariable();
    WeatherVariable(string variableName, double variableValue); 
    static void addWeatherVariable(vector<WeatherVariable>& variables, const WeatherVariable& variable);
    static void listWeatherVariables(const vector<WeatherVariable>& variables);
};
// Location class definition
class Location 
{
public:
    string name;
    double latitude;
    double longitude;
    vector<WeatherVariable> weatherVariables;
    static vector<Location> locations;
    Location() : name(" "),latitude(0.0),longitude(0.0){}
    Location(string Name, double Latitude, double Longitude)
    {
        name = Name;
        latitude = Latitude;
        longitude = Longitude;
    }

    static void addLocation(const Location& location);
    static void removeLocation(const string& name);
    static void listLocations();
};
// Weather forecasting system class definition
class WeatherForecastingSystem 
{
public:
    void fetchWeatherData(const string& location); 
    void displayWeatherData();
};

//weather variable class parameterized constructor definition
WeatherVariable :: WeatherVariable(string Name, double Value)
{
     name = Name;
     value = Value;
}
//functions definition
void WeatherVariable :: addWeatherVariable(vector<WeatherVariable>& variables, const WeatherVariable& variable) 
{
        variables.push_back(variable);
}

void WeatherVariable :: listWeatherVariables(const vector<WeatherVariable>& variables)
 {
        for (const auto& variable : variables) 
        {
            cout<<"*******************************************************"<<endl;
            cout << "Weather Variable - Name: " << variable.name
                 << ", Value: " << variable.value << endl;
            cout<<"*******************************************************"<<endl<<endl;
        }
}

//functions definition
void Location :: addLocation(const Location& location) 
{
        locations.push_back(location);
}

void Location :: removeLocation(const string& name) 
{
        locations.erase(remove_if(locations.begin(), locations.end(),
            [&name](Location& location) { return location.name == name; }),
            locations.end());
    cout <<"LOCATION "<<name<<" REMOVED"<<endl;
}

void Location :: listLocations() 
{
        for (const auto& location : locations) 
        {
            cout<<"******************************************************************"<<endl;
            cout << "Location - Name: " << location.name
                 << ", Latitude: " << location.latitude
                 << ", Longitude: " << location.longitude << endl;
            WeatherVariable::listWeatherVariables(location.weatherVariables);
            cout<<"******************************************************************"<<endl<<endl;
        }
}

vector<Location> Location::locations;

void WeatherForecastingSystem :: fetchWeatherData(const string& location) 
{
        // Placeholder for API interaction code
        cout << "Fetching weather data for " << location << "..." << endl;
}

void WeatherForecastingSystem ::displayWeatherData()
{
        // Placeholder for displaying weather data
        cout << "Displaying weather data..." << endl;
}

int main() 
{
    Location obj;
    int choice;
    string Name, variable1, variable2;
    double Latitude, Longitude, value1, value2;
    mainMenu:;
    cout <<"************************* MAIN MENU *************************"<<endl<<endl;
    cout <<"PRESS 1 TO ENTER LOCATION AND WEATHER VARIABLE"<<endl;
    cout <<"PRESS 2 TO DISPLAY LOCATIONS AND WEATHER VARIABLES"<<endl;
    cout <<"PRESS 3 TO DELETE A LOCATION"<<endl;
    cout <<"PRESS 4 FOR WEATHER FORCASTING SYSTEM"<<endl;
    cout <<"PRESS 0 TO EXIT"<<endl;
    cout <<"ENTER YOUR CHOICE: ";
    cin >> choice;

    if (choice == 1)
    {
       system("cls");
       newLocation:;
       cout <<"************************* INSERT LOCATION *************************"<<endl<<endl;
       cout <<"ENTER CITY NAME: ";
       cin.ignore();
       getline(cin,Name);
       cout <<"ENTER LATITUDE: "; cin >> Latitude;
       cout <<"ENTER LONGITUDE: "; cin >> Longitude;
       cout <<"ENTER FIRST WEATHER VARIABLE (temperature/ wind speed): "; 
       cin.ignore();
       getline(cin,variable1);
       cout <<"ENTER VALUE OF FIRST VARIABLE: "; cin >> value1;
       enterVariableagain:;
       cout <<"ENTER SECOND WEATHER VARIABLE (temperature/ wind speed): ";
       cin.ignore();
       getline(cin,variable2);
       if (variable1 == variable2)
       {
         cout <<"YOU HAVE ALREADY ENTERED THIS VARIABLE"<<endl;
         cout <<"ENTER AGAIN !!"<<endl;
         goto enterVariableagain;
       }
       else
       {
       cout <<"ENTER VALUE OF SECOND VARIABLE: "; cin >> value2;
       goto Continue;
       }
       Continue:;
       Location Insert(Name,Latitude,Longitude);
       WeatherVariable::addWeatherVariable(Insert.weatherVariables, WeatherVariable(variable1,value1));
       WeatherVariable::addWeatherVariable(Insert.weatherVariables, WeatherVariable(variable2,value2));
       obj.addLocation(Insert);
       system("cls");
       int choice2;
       cout <<"LOCATION ADDED"<<endl<<endl;
       cout <<"PRESS 1 TO GO TO MAIN MENU"<<endl;
       cout <<"PRESS 2 TO INSERT ANOTHER LOCATION"<<endl;
       cout <<"PRESS 0 TO EXIT"<<endl;
       cout <<"ENTER YOUR CHOICE: ";cin >> choice2;
       if (choice2 == 1)
       {
        system("cls");
        goto mainMenu;
       }
       else if (choice2 == 2)
       {
        system("cls");
        goto newLocation;
       }
       else if (choice2 == 0)
       {
        exit(0);
       }
       
    }
    else if (choice == 2)
    {
        system("cls");
        cout <<"************************* DISPLAYING LOCATION *************************"<<endl<<endl;
        obj.listLocations();
        int choice3;
        cout <<endl<<endl;
        cout <<"Press 1 TO GO TO MAIN MENU"<<endl;
        cout <<"PRESS 0 TO EXIT"<<endl;
        cout <<"ENTER YOUR CHOICE: ";cin >> choice3;
       if (choice3 == 1)
       {
        system("cls");
        goto mainMenu;
       }
       else if (choice3 == 0)
       {
        exit(0);
       }
       
    }
    else if (choice == 3)
    {
        system("cls");
        string locationName;
        int choice4;
        cout <<"************************* DELETE LOCATION *************************"<<endl<<endl;
        cout <<"ENTER LOCATION NAME TO BE REMOVED: ";cin >> locationName;
        obj.removeLocation(locationName);
        cout <<endl<<endl;
        cout <<"Press 1 TO GO TO MAIN MENU"<<endl;
        cout <<"PRESS 0 TO EXIT"<<endl;
        cout <<"ENTER YOUR CHOICE: ";cin >> choice4;
        if (choice4 == 1)
        {
         system("cls");
         goto mainMenu;
        }
        else if (choice4 == 0)
        {
         exit(0);
        }
       
    }
    else if (choice == 4)
    {
        system("cls");
        cout <<"************************* WEATHER FORECASTING SYSTEM *************************"<<endl<<endl;
        WeatherForecastingSystem weatherSystem;
        weatherSystem.fetchWeatherData("New York");
        weatherSystem.displayWeatherData();
        int choice5;
        cout <<endl<<endl;
        cout <<"Press 1 TO GO TO MAIN MENU"<<endl;
        cout <<"PRESS 0 TO EXIT"<<endl;
        cout <<"ENTER YOUR CHOICE: ";cin >> choice5;
        if (choice5 == 1)
        {
         system("cls");
         goto mainMenu;
        }
        else if (choice5 == 0)
        {
         exit(0);
        }
       
    }
    else if (choice == 0)
    {
        exit(0);
    }
    else
    {
        system("cls");
        cout <<"YOU HAD ENTERED WRONG CHOICE !!"<<endl;
        cout <<"ENTER AGAIN !!"<<endl<<endl;
        goto mainMenu;
    }

    return 0;
}

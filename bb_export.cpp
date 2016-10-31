#include <iostream>
#include <fstream>


using namespace std;

int main()
{
  //initiate file Stream to habdle Files
  fstream FILE; //to read gpio pins
  fstream FILEVALUE; //to write values
  String myvalue;

  /* Exporting a GPIO pin*/
  FILE.open("/sys/class/gpio/export", fstream::out);
  FILE << "60" //exporting GPIO pin 12
  FILE.close();

  /* Begining the log file to write to*/
  FILEVALUE.open("/home/ubuntu/datalog.txt");//needs to stay open during for loop
  FILEVALUE << "..... Start Log ........"<<endl;
  cout << "..... Start Log ........"<<endl;
  
  //For loop to read data from pin and write it to a log
  for(int x = 0; x<10; x++){
    /* Reading the value of the pin*/
    FILE.open("/sys/class/gpio/gpio40/value");
    getline(FILE,myvalue); //gets the value of that pin as a string
    cout<<" Value "<<myvalue;
    FILE.close(); //close the file so it can update

    /* Writing value of the pin to a log file */
    FILEVALUE << "Pin state: "<<myvalue<<endl;
    // Use a sleep function to slow down the program 
    sleep(1); //1 second delay
  }

  cout<<"....... End Log ............"<<endl;
  FILEVALUE << ".........End Log.........."<<endl;
  FILEVALUE.clsoe(); //clos the file after the for loop to update it
  
  /* Unexporting the pin after we are finished*/
  FILE.open("/sys/class/gpio/unexport",fstream::out);
  FILE <<"60";
  FILE.close();

  return 0;
}
      

  

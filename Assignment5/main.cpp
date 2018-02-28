#include <string>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <limits>
//==========================================================================
/* The program creats a join.csv file with the joined data
but couldn't figure out how to do the crash and continuation part.
I hope I get the partial grades for craeting the join
------------To run enter ---//  g++ main.cpp -o main.out  //----------
Running the "main.out" file would create a csv file named join.csv



Relation 1 Schema ::
=================================================================================
Dept (did (integer), dname (string), budget (double), managerid (integer))       */
//===============================================================================
using namespace std;

int main()
{


     fstream dept("Dept.csv");              //opening the file to read
     if (dept.fail()){                       //check for failure to open
              cout << "Error opening file."; //erro msg if file has problem
              }

if(!dept.is_open()) cout << "Error : File is_open" << '\n';           //error msg if file doesn't opens
string did;
string dname;
string budget;
string managerid;
string buffer;
std::string emp_arr[51];
std::string dept_arr[32];
std::string crr[65];
std::string drr[65];
std::string err[65];

int c=0,d=0,n=0,o=0;



while(dept.good()&& d<31)
{
try{
getline(dept,did,',');  // to get the values from dept in a string format
atoi(string(did).substr(1,string(did).length()).c_str());   //Converting string into int format
getline(dept,dname,',');
getline(dept,budget,',');
atoi(string(budget).substr(1,string(budget).length()).c_str());
getline(dept,managerid);
atoi(string(managerid).substr(1,string(managerid).length()).c_str());
// cout <<did << ',';
// cout <<dname<< ',';     //printing the file values
// cout <<budget<< ',';
//  cout <<managerid << endl;

dept_arr[d]=managerid; // storing managerid in the array
d++; // counter to store every managerid in an array

//
// std::istringstream dept(buffer);
// dept >> managerid;
//cout << managerid;
}
catch (const exception& e) {}
}


/* Relation 2 Schema ::
===========================================================================
Emp (eid (integer), ename (string), age (integer), salary (double))
============================================================================ */

cout<<'\n';
fstream emp("Emp.csv");
if (emp.fail()){ //check for failure to open
         cout << "Error opening file.";   // Sends output to stdout if error exists
         }
if(!emp.is_open()) cout << "Error : File is_open" << '\n';   //if file is open then run else error message
string eid;
string ename;
string age;
string salary;
int m=0;
while(emp.good() && c<51 && m<51)
{
try{

getline(emp,eid,',');              // to get the values from dept in a string format
atoi(string(eid).substr(1,string(eid).length()).c_str());
getline(emp,ename,',');
getline(emp,age,',');
atoi(string(age).substr(1,string(age).length()).c_str());
getline(emp,salary);
atoi(string(salary).substr(1,string(salary).length()).c_str());

emp_arr[c]=eid; // storing eid in the array
c++; // counter to store every eid in an array

crr[m]=ename;
m++;

drr[n]=age;
n++;

err[o]=salary;
o++;
}
catch (const exception& e) {}
}

std::ofstream outfile;
outfile.open("join.csv");

for( int a = 0; a < sizeof(dept_arr)/sizeof(dept_arr[0]); a++)  // to go through all data of first csv file
 {
      for( int d = 0;d < sizeof(emp_arr)/sizeof(emp_arr[0]); d++)
      {
        if (dept_arr[a] == emp_arr[d])
        {
            outfile << dept_arr[a]<<','<< crr[a]<<','<< drr[a]<<','<< err[a]<<endl;
        }
      }

}
outfile.close();


}

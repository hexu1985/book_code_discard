// Listing 15.3	Heterogeneous list processing - traditional approach.

#include <iostream> 
#include <fstream> 
using namespace std;

struct Person {         
	int kind;                 // 1 for faculty, 2 for student
	char id[10];              // fixed length
	char* name;               // variable length
	char* rank;               // for faculty only
	char* major;              // for student only
   } ;

void read (ifstream& f, Person*& person) // read one record
{ char buf[80];
  Person* p = new Person;      // allocate space for new object
  f.getline(buf,80);          // recognize the incoming type
  if (strcmp(buf, "FACULTY") == 0)
	p->kind = 1;                     // 1 for faculty
  else if (strcmp(buf, "STUDENT") == 0)
	p->kind = 2;                     // 2 for student
  else   
  	p->kind = 0;                     // type not known
  f.getline(p->id,10);                  // read id
  f.getline(buf,80);                    // read name
  p->name = new char[strlen(buf)+1];    // allocate space
  strcpy(p->name, buf);                 // copy name
  f.getline(buf,80);                    // read rank/major
  if (p->kind == 1)
  { p->rank = new char[strlen(buf)+1];  // space for rank
    strcpy(p->rank, buf); }             // copy rank
  else if (p->kind == 2)
  { p->major = new char[strlen(buf)+1]; // space for major
    strcpy(p->major, buf); }            // copy major
  person = p;                           // hook it up to array
}

int main()
{ 
  Person* data[20]; int cnt = 0;            // array of pointers
  ifstream from("univ.dat");                // input data file
  if (!from) { cout << " Cannot open file\n"; return 0; }
  while (!from.eof())     
  { read(from, data[cnt]);                  // read until eof
    cnt++; } 
  cout << " Total records read: " << cnt << endl << endl;
  for (int i=0;  i < cnt;  i++)
  { cout <<" id:    " <<data[i]->id <<endl; // print id, name
    cout <<" name:  " <<data[i]->name <<endl; 
    if (data[i]->kind == 1)
      cout <<" rank:  " <<data[i]->rank <<endl;  // faculty rank 
    else if (data[i]->kind == 2)
      cout <<" major: " <<data[i]->major <<endl; // student major
    cout << endl; }  
  for (int j=0;  j < cnt;  j++)
  { delete [] data[j]->name;                // delete name
    if (data[j]->kind == 1)
      delete [] data[j]->rank;              // delete rank/major
    else if (data[j]->kind == 1)
      delete [] data[j]->major;
    delete data[j]; }                       // delete the record
  return 0;
  }

// Listing 15.4	Heterogeneous list processing - object-oriented approach.

#include <iostream> 
#include <fstream> 
using namespace std;

struct Person {         
public:
	enum Kind { FACULTY, STUDENT } ;
protected:
	Kind kind;                // FACULTY or STUDENT
	char id[10];              // data common to both types
	char* name;               // variable length

public:
	Person(const char id[], const char nm[], Kind type)
	{ strcpy(Person::id,id);           // copy id
	  name = new char[strlen(nm)+1];   // get space for name
	  if (name == 0) { cout << "Out of memory\n"; exit(0); }
	  strcpy(name,nm);                 // copy name
	  kind = type; }                   // remember its type

    Kind getKind() const
	{ return kind; }                   // access Person's type

	~Person()
	{ delete [] name; }                // return heap memory
} ;

struct Faculty : public Person {
private:
	char* rank;                        // for faculty only

public:
	Faculty(const char id[], const char nm[], const char r[])
		: Person(id,nm,FACULTY)        // initialization list
	{ rank = new char[strlen(r)+1];
	  if (rank == 0) { cout << "Out of memory\n"; exit(0); }
	  strcpy(rank,r); }

  void write () const                  // display record
  { cout << " id:    " << id << endl;  // print id, name
    cout << " name:  " << name << endl;  
    cout << " rank:  " << rank <<endl <<endl; } // faculty only

	~Faculty()
	{ delete [] rank; }                // return heap memory
} ;
	
struct Student : public Person {
private:
	char* major;                       // for student only

public:
	Student(const char id[], const char nm[], const char m[])
		: Person(id,nm,STUDENT)        // initialization list
	{ major = new char[strlen(m)+1];
	  if (major == 0) { cout << "Out of memory\n"; exit(0); }
	  strcpy(major,m); }

  void write () const                 // display record
  { cout << " id:    " << id << endl; // print id, name
    cout << " name:  " << name << endl;
    cout << " major: " << major <<endl <<endl; } // student only

  ~Student()
  { delete [] major; }                // return heap memory
} ;
	
void read (ifstream& f, Person*& person)    // read one record
{ char kind[8], id[10], name[80], buf[80];
  f.getline(kind,80);          // recognize the incoming type
  f.getline(id,10);                         // read id
  f.getline(name,80);                       // read name
  f.getline(buf,80);                        // rank or major?
  if (strcmp(kind, "FACULTY") == 0)
  { person = new Faculty(id,name,buf); }    // object is Faculty
  else if (strcmp(kind, "STUDENT") == 0)
  { person = new Student(id,name,buf); }    // object is Student
  else   
  { cout << " Corrupted data: unknown type\n"; exit(0); }
}

void write (const Person* p)                // display record
{ switch (p->getKind()) {                   // get object type
    case Person::FACULTY: 
		((Faculty*)p)->write();  break;     // do it Faculty way
    case Person::STUDENT: 
		((Student*)p)->write();  break;     // do it Student way
} }

int main()
{ cout << endl << endl;
  Person* data[20]; int cnt = 0;           // array of pointers
  ifstream from("univ.dat");               // input data file
  if (!from) { cout << " Cannot open file\n"; return 0; }
  while (!from.eof())     
  { read(from, data[cnt]);                 // read until eof
    cnt++; } 
  cout << " Total records read: " << cnt << endl << endl;
  for (int i=0;  i < cnt;  i++)
  { write(data[i]); }                      // display data
  for (int j=0;  j < cnt;  j++)
  { delete data[j]; }                      // delete the record
  return 0;
  }

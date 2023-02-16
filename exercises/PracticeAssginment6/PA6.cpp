#include <cstring>
#include <iostream>
using namespace std;

struct planet {
  unsigned int planet_number;
  char *planet_name;
  struct {
    char origin[10];
    int age;
  } personal, *personal_ptr = &personal;
} planet_record, *planet_ptr = &planet_record, all_records[5];

/**


a) planet_number of structure planet_record.
                cout<<planet_record.planet_number<<endl;

b) planet_number of the structure pointed to by planet_ptr.
                cout<<(*planet_ptr).planet_number<<endl;

c) planet_name of structure planet_record.
                cout<<planet_record.planet_name<<endl;

d) planet_name of member structure pointed to by planet_ptr.
                cout<<planet_ptr->planet_name<<endl;

e) age of the structure member personal of structure planet_record.
                cout<<planet_record.personal.age<<endl;

f) age of member pointed to by personal_ptr of the structure pointed to by
planet_ptr. cout<<planet_ptr->personal_ptr->age<<endl;

g) origin of the structure member personal of structure planet_record.
                cout<planet_record.personal.origin<<endl;

h) origin of member pointed to by personal_ptr of the structure pointed to by
planet_ptr. cout<<planet_ptr->personal_ptr->origin<<endl;

2. Now have your group  member check your answers. After that, let’s confirm
them by writing them in code. Define the above structure and initialize the
members with suitable values. Then compile and see how many of your answers had
syntax errors? Report the number of errors {in comments}. Also fix the code to
ensure that it works properly. You can leave your old code in comments.

3. Now let’s do a little more extra work by updating your code (and testing it)
to do the following: a) Initialize all members of all 5 planets stored in
all_records and print them neatly. b) Create a pointer that would point to
dynamically allocated array of records of 5 planets (similar to all_records[5]).
Again, initialize all of its members and print them neatly using the newly
created pointer.



 **/

int main() {

  // work for 2.
  // number of errors: 4
  // The mistake I made consistently was trying to call
  // planet_ptr->personal_ptr->FIELD wihtout defined *planet_ptr first . also I
  // tried two arrows instead of one arrow with a . to access fields.
  planet planet_record;
  planet_record.planet_number = 1;
  planet_record.planet_name = new char[6];
  strcpy(planet_record.planet_name, "Earth");
  strcpy(planet_record.personal.origin, "space probably");
  planet_record.personal.age = 4.54;

  struct planet *planet_ptr = &planet_record;

  cout << planet_record.planet_number << endl;
  cout << (*planet_ptr).planet_number << endl;

  cout << planet_record.planet_name << endl;

  // cout<<planet_ptr->planet_name<<endl;

  cout << planet_ptr->planet_name << endl;

  cout << planet_record.personal.age << endl;
  // cout<<planet_ptr->personal_ptr->age<<endl;

  cout << planet_ptr->personal.age << endl;

  cout << planet_record.personal.origin << endl;

  // cout<<planet_ptr->personal_ptr->origin<<endl;
  cout << planet_ptr->personal.origin << endl;

  planet all_records[5];

  // makes array (with same data) of 5 planets in all records
  for (int i = 0; i < 5; i++) {
    all_records[i].planet_number = 1;
    all_records[i].planet_name = new char[10];
    strcpy(all_records[i].planet_name, "Mercurys");
    strcpy(all_records[i].personal.origin, "def space");
    all_records[i].personal.age = 545;
  }

  // Print the planet records
  for (int i = 0; i < 5; i++) {
    cout << "Planet #" << i + 1 << ": " << endl;
    cout << "Planet number: " << all_records[i].planet_number << endl;
    cout << "Planet name: " << all_records[i].planet_name << endl;
    cout << "Origin: " << all_records[i].personal.origin << endl;
    cout << "Age: " << all_records[i].personal.age << endl;
    cout << endl;
  }

  // 3

  planet *akashic_records_ptr = new planet[5];
  // makes array (with same data) of 5 planets in all records
  for (int i = 0; i < 5; i++) {
    (akashic_records_ptr[i]).planet_number = 1;
    (akashic_records_ptr[i]).planet_name = new char[10];
    strcpy((akashic_records_ptr[i]).planet_name, ("IDEK AT T" + i));
    strcpy((akashic_records_ptr[i]).personal.origin, "not space" + i);
    (akashic_records_ptr[i]).personal.age = 545;
  }

  // printing out this info:
  for (int i = 0; i < 5; i++) {
    cout << "Planet #" << i + 1 << ": " << endl;
    cout << "Planet number: " << akashic_records_ptr[i].planet_number << endl;
    cout << "Planet name: " << akashic_records_ptr[i].planet_name << endl;
    cout << "Origin: " << akashic_records_ptr[i].personal.origin << endl;
    cout << "Age: " << akashic_records_ptr[i].personal.age << endl;
    cout << "___________________________________________________" << endl;
  }

  return 0;
}
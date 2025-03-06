#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home; 
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  *home += new File("proj.files.repo");
  *home += new Dir("adam");
  
  std::cout << (const Dir&)*top << std::endl;

  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("auto1.jpg");
  *ewa += new File("auto2.jpg");
  *ewa += new File("auto3.jpg");
  top->findDir("ewa")->add( new Dir("work") );


  std::cout << *top;
  std::cout << "--------------" << std::endl;
  std::cout << *(ewa->get("work"));
  std::cout << *(top->get("proj.descr"));

  std::cout << "--------------" << std::endl;
  delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      auto1.jpg (FILE)
      auto2.jpg (FILE)
      auto3.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)
--------------
work (DIR)
proj.descr (FILE)
--------------
Deleting Dir: .
About to delete home
Deleting Dir: home
About to delete ewa
Deleting Dir: ewa
About to delete Desk
Deleting Dir: Desk
About to delete auto1.jpg
About to delete auto2.jpg
About to delete auto3.jpg
About to delete work
Deleting Dir: work
About to delete proj.descr
About to delete proj.files.repo
About to delete adam
Deleting Dir: adam
*/
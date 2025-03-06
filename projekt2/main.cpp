#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home;
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  home->add(new File("proj.files.repo") );
  home->add(new Dir("adam") );
  
  top->findDir("ewa")->add( new Dir("Desk") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("pict.jpg");
  top->findDir("ewa")->add( new Dir("work") );

  std::cout << *top << std::endl;


  std::cout << "--------------" << std::endl;
  top->listDirs(1);
  std::cout << "--------------" << std::endl;
  top->listDirs(2);

  delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      Desk (DIR)
      pict.jpg (FILE)
      work (DIR)
    proj.descr (FILE)
    proj.files.repo (FILE)
    adam (DIR)

--------------
. home 
--------------
. home ewa adam
*/
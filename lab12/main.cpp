#include "Dir.h"
#include "File.h"

int main() {

  Dir* top = new Dir(".");
  Dir* home = new Dir("home");
  *top += home;
  *home += new Dir("ewa");
  *home += new File("proj.descr");
  home->add( new Dir("adam") );

  Dir* ewa = home->findDir("ewa");  
  *ewa += new File("pict.jpg");
  *ewa += new Dir("Desk");
  top->findDir("ewa")->add( new Dir("work") );
  top->findDir("Desk")->add( new Dir("Docs") );
  top->findDir("Docs")->add( new Dir("priv") );

  std::cout << *top << std::endl;
  std::cout << "--------------" << std::endl;

  auto dir = top->findDir("Desk");
  std::cout << "name: " << dir->name() << std::endl;
  std::cout << "path: " << dir->getRelativePath() << std::endl;
  std::cout << "--------------" << std::endl;
  top->listDirs(4);

  delete top;
}

/*
. (DIR)
  home (DIR)
    ewa (DIR)
      pict.jpg (FILE)
      Desk (DIR)
        Docs (DIR)
          priv (DIR)
      work (DIR)
    proj.descr (FILE)
    adam (DIR)

--------------
name: Desk
path: ./home/ewa/Desk/
--------------
name: .
path: ./
name: home
path: ./home/
name: ewa
path: ./home/ewa/
name: Desk
path: ./home/ewa/Desk/
name: Docs
path: ./home/ewa/Desk/Docs/
name: work
path: ./home/ewa/work/
name: adam
path: ./home/adam/
*/
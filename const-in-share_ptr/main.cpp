//
// Created by piotr@janczura.pl on 2022.05.011
//
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <memory>


class Cd {
public:
  typedef std::shared_ptr<Cd> ptr;

  static ptr create(const std::string &name) { return ptr(new Cd(name)) ;}
  static ptr create(const std::string &name, int i) { std::ignore = i; return ptr(new Cd(name)) ;}

  void name(const std::string &name) { _name = name;}
  std::string name() const { return _name;  }

  static void statyczna_w_cd() {}

protected:
  static int statycznaZmienna;
private :
  explicit Cd(std::string name) : _name(std::move(name)) { }

  std::string _name;
};
int Cd::statycznaZmienna = 1;

class Cc {
public:
  typedef std::shared_ptr<Cc> ptr;
  typedef std::shared_ptr<const Cc> cptr;
  typedef const std::shared_ptr<const Cc> ccptr;

  static cptr create(const std::string &name) { return cptr(new Cc(name)) ;}
  static ccptr ccreate(const std::string &name) { return ccptr(new Cc(name)) ;}

  void name(const std::string &name) { _name = name;}
  std::string name() const { return _name;  }

private :
  explicit Cc(std::string name) : _name(std::move(name)) { }

  std::string _name;
};

void fptr(Cc::ptr ptr) {
  std::cout << ptr->name() << " / " << ptr.use_count() << std::endl;
}

void fcptr(Cc::cptr cptr) {
  std::cout << cptr->name() << " / " << cptr.use_count() << std::endl;
}

void fccptr(Cc::ccptr ccptr) {
  std::cout << ccptr->name() << " / " << ccptr.use_count() << std::endl;

}


int main()
{

  Cd::ptr cd1 = Cd::create("cd1");
  Cd::ptr cd2 = Cd::create("cd2");
  cd1->name("new-cd1");
  cd1.swap(cd2);

  Cc::cptr cc1 = Cc::create("cc1");
  Cc::cptr cc2 = Cc::create("cc2");
  // cc1->name("new-cc1"); Błąd kompilacji - metoda jest niewidoczna.
  cc1.swap(cc2);

  Cc::ccptr ccc1 = Cc::ccreate("c-cc1");
  Cc::ccptr ccc2 = Cc::ccreate("c-cc2");
  // ccc1->name("new-c-cc1"); Błąd kompilacji - metoda jest niewidoczna.
  // ccc1.swap(ccc2); Błąd kompilacji - ccc1 nie pozwala na swoją zmianę


  fcptr(cc1);
  fccptr(ccc1); // Mimo stałości pointera pracuje licznik odwołań

  // błąd : Cd::ptr cx = Cc::create("oszustwo", 2);

  // błąd : cc1->statyczna_w_cd();
  // błąd : cc1::statyczna_w_cd();
  // błąd : Cc::statyczna_w_cd();
}
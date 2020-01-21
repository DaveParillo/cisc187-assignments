#include <cstdio>

struct Animal {
    virtual void make_noise() {puts("Animal noise");}
    virtual void eat() {puts("Animal eat");}
    virtual void sleep() {puts("Animal sleep");}
    virtual void roam() {puts("Animal roam");}
};

struct Canine : public Animal {
    virtual void roam() override {puts("Canine roam");}
    virtual void eat() override {puts("Canine eat");}
};


struct Wolf : public Canine {
    void make_noise() override {puts("Wolf noise");}
    void eat() override {puts("Wolf eat");}
};

void call (Animal& a) {
  a.make_noise();
  a.roam();
  a.eat();
  a.sleep();
}

int main () {
  Animal x;
  Canine c;
  Wolf w;

  call(x);
  call(c);
  call(w);
}


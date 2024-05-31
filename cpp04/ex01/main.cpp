#include "Animals/Animal.hpp"
#include "Animals/Dog/Dog.hpp"
#include "Animals/Cat/Cat.hpp"
#include "Animals/WrongAnimal/WrongAnimal.hpp"
#include "Animals/WrongCat/WrongCat.hpp"

int main()
{
    {
        // Animal *j = new Animal();
        // std::cout << j->getType() << std::endl;
        // j->makeSound();
        // delete j;

        // Dog *i = new Dog("Pastor alemão");
        // std::cout << i->getType() << std::endl;
        // i->makeSound();
        // delete i;

        // Cat *k = new Cat("Siamês");
        // std::cout << k->getType() << std::endl;
        // k->makeSound();
        // delete k;

    }
    {
        // const Animal* meta = new Animal();
        // const Animal* j = new Dog();
        // const Animal* i = new Cat();
        // std::cout << j->getType() << " " << std::endl;
        // std::cout << i->getType() << " " << std::endl;
        // i->makeSound(); 
        // j->makeSound();
        // meta->makeSound();

        // delete meta;
        // delete j;
        // delete i;
    }
    {
        // WrongAnimal *j = new WrongAnimal();
        // std::cout << j->getType() << std::endl;
        // j->makeSound();
        // delete j;

        // WrongCat *i = new WrongCat();
        // std::cout << i->getType() << std::endl;
        // i->makeSound();
        // delete i;
    }
    {
        // const int n = 2;
        // Animal *animals[n] = {new Dog(), new Cat()};

        // for (int i = 0; i < n; i++)
        // {
        //     std::cout << animals[i]->getType() << " " << std::endl;
        //     animals[i]->makeSound();
        // }
        // for (int i = 0; i < n; i++)
        //     delete animals[i];
    }
    {
        Dog *j = new Dog();
        j->setIdea(0, "I am a dog");
      //  std::cout << j->getIdea(0) << std::endl;

        Dog *i = new Dog(*j);
        delete j;
        std::cout << i->getIdea(0) << std::endl;
        delete i;
    }
    return 0;
}
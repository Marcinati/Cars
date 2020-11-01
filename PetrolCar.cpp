#include "Exceptions.hpp"
#include "PetrolCar.hpp"
#include <iostream>

PetrolCar::PetrolCar(std::unique_ptr<PetrolEngine> engine)
    : petrolEngine_(std::move(engine))
{
    std::cout << __FUNCTION__ << std::endl;
}

PetrolCar::~PetrolCar()         { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::refuel()        { std::cout << __FUNCTION__ << std::endl; }
void PetrolCar::restore() {
    refuel();
}
void PetrolCar::changePetrolEngine(std::unique_ptr<PetrolEngine> newEngine) {
    if (speed_ != 0) {
        throw InvalidSpeed("Speed can't be different than zero, when you are changing the petrol engine.");
    } else {
        std::swap(petrolEngine_, newEngine);
    }
}

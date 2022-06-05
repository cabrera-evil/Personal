package com.company;

public class Main {
    public static void main(String[] args){
        plant Plant = new plant();
        Plant.feed();
        carnivorousAnimal carnivorous = new carnivorousAnimal();
        carnivorous.feed();
        herbivorousAnimal herbivorous = new herbivorousAnimal();
        herbivorous.feed();
    }
}
package com.company;

public class sportVehicle extends vehicle{
    private int displacement;

    public sportVehicle(String registration, String brand, String model, int displacement) {
        super(registration, brand, model);
        this.displacement = displacement;
    }

    public int getDisplacement() {
        return displacement;
    }

    @Override
    public String showData(){
        return "Registration: "+registration+"\nBrand: "+brand+"\nmodel: "+model+"\nDisplacement: "+displacement;
    }
}

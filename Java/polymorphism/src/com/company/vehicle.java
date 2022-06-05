package com.company;

public class vehicle {
    protected String registration;
    protected String brand;
    protected String model;

    public vehicle(String registration, String brand, String model) {
        this.registration = registration;
        this.brand = brand;
        this.model = model;
    }

    public String getRegistration() {
        return registration;
    }

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }
    public String showData(){
        return "Registration: "+registration+"\nBrand: "+brand+"\nmodel: "+model;
    }
}

package com.company;

public abstract class polygon {
    protected int sides;

    public polygon(int sides) {
        this.sides = sides;
    }

    public int getSides() {
        return sides;
    }

    @Override
    public String toString() {
        return "sides: " + sides;
    }

    public abstract double area();
}

package org.example;

public class App {
    public static void main(String[] args) throws Exception {
        Vehicle vehicle = new Vehicle("ABC-123", 2010, 1_000_000);
        System.out.println(vehicle.license());
    }
}

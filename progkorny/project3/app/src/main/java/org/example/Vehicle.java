package org.example;

import java.time.LocalDateTime;

public class Vehicle {
    public Vehicle(String license, int year, int originalPrice,
            VehicleState state) throws Exception {
        setLicense(license);
        setYear(year);
        setOriginalPrice(originalPrice);
        setState(state);
    }

    public Vehicle(String license, int year, int originalPrice)
            throws Exception {
        this(license, year, originalPrice, VehicleState.USED);
    }

    public String license() {
        return _license;
    }

    public void setLicense(String license) throws Exception {
        if (license == null) {
            throw new Exception("null license");
        }
        if (license.length() != 7) {
            throw new Exception("invalid license");
        }
        _license = license;
    }

    public int year() {
        return _year;
    }

    public void setYear(int year) throws Exception {
        if (year < 1950 || LocalDateTime.now().getYear() < year) {
            throw new Exception("invalid year");
        }
        _year = year;
    }

    public int originalPrice() {
        return _originalPrice;
    }

    public void setOriginalPrice(int originalPrice) throws Exception {
        if (originalPrice < 300_000 || 12_000_000 < originalPrice) {
            throw new Exception("invalid originalPrice");
        }
        _originalPrice = originalPrice;
    }

    public VehicleState state() {
        return _state;
    }

    public void setState(VehicleState state) {
        _state = state;
    }

    public int getAge() {
        return LocalDateTime.now().getYear() - year();
    }

    public double getExtraPrice() {
        if (state() == VehicleState.NEW && getAge() <= 2) {
            return originalPrice() * .02;
        }
        return 0;
    }

    public double getPrice() {
        double price = originalPrice();
        switch (state()) {
            case NEW -> price *= Math.pow(.91, getAge());
            case USED -> price *= Math.pow(.9, getAge());
            case BROKEN -> price *= Math.pow(.89, getAge());
            case WRECKED -> price *= Math.pow(.88, getAge());
        }
        return price + getExtraPrice();
    }

    @Override
    public boolean equals(Object obj) {
        return obj != null && obj instanceof Vehicle &&
                (obj == this || ((Vehicle) obj).license() == license());
    }

    @Override
    public String toString() {
        return "License: " + license() + " Year: " + year() +
                " Original price: " + originalPrice();
    }

    private String _license;
    private int _year;
    private int _originalPrice;
    private VehicleState _state;
}

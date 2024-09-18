package org.example;

import org.example.circle.Circle;
import org.example.utils.Utils;

public class App {
    public static void main(String[] args) {
        Circle circle = new Circle(0, 0, 5);
        System.out.println(Utils.getRadius(circle));
        System.out.println(Utils.getArea(circle));
    }
}

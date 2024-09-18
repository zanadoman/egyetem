package org.example;

import java.util.ArrayList;

class Foo {
    Foo(int bar) {
        setBar(bar);
    }

    public int bar() {
        return _bar;
    }

    public void setBar(int bar) {
        _bar = bar;
    }

    private int _bar;
}

class Bar extends Foo {
    Bar(int baz) {
        super(0);
        setBaz(baz);
    }

    public int baz() {
        return _baz;
    }

    public void setBaz(int baz) {
        _baz = baz;
    }

    private int _baz;
}

interface Animal {
    void move();
}

abstract class Bird implements Animal {
    public void move() {
        System.out.println("Flying in the sky..");
    }

    public abstract void speak();
}

class Chicken extends Bird {
    public void speak() {
        System.out.println("Chicken noises..");
    }
}

public class App {
    public static void main(String[] args) {
        ArrayList<Foo> foos = new ArrayList<Foo>();

        for (int i = 0; i != 10; ++i) {
            if (i % 2 == 0) {
                foos.add(new Foo(i));
            } else {
                foos.add(new Bar(i * 2));
            }
        }

        for (Foo foo : foos) {
            if (foo instanceof Bar) {
                System.out.println(((Bar) foo).baz());
            } else {
                System.out.println(foo.bar());
            }
        }
    }
}

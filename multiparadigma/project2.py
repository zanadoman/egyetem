#!/bin/python

def foo(bar, baz="foobaz"):
    print(f'{bar}: {baz}')

def main():
    for i in range(1, 21):
        fizz = i % 3 == 0
        buzz = i % 5 == 0
        if fizz and buzz == 0:
            print('fizzbuzz')
        elif fizz == 0:
            print('fizz')
        elif buzz == 0:
            print('buzz')
        else:
            print(i)

if __name__ == '__main__':
    main()

#!/bin/python

def is_armstrong(number):
    sum = 0
    for digit in str(number):
        sum += int(digit) ** len(str(number))
    return sum == number

def main():
    print(is_armstrong(153))

if __name__ == '__main__':
    main()

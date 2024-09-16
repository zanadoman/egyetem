import { Employee } from './Employee'

export class PhoneBook {
    constructor() {
        this.persons = []
    }


    getPerson(email: string): Employee | undefined {
        return this.persons.find((person: Employee) => person.email === email)
    }

    getPerson(phoneNumber: string): Employee | undefined {
        return this.persons.find((person: Employee) =>
            person.phoneNumbers.find((phone: string) => phone === phoneNumber))
    }

    persons: Employee[]
}

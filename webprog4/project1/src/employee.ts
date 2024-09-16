import { Gender } from './gender';
import { Person } from './person';

export class Employee implements Person {
    name: string
    gender: Gender
    birthDate: Date
    ssn: string;
    email: string;
    phoneNumbers: string[];

    constructor(name: string, gender: Gender, birthDate: Date, ssn: string,
        email: string, phoneNumber?: string) {
        this.name = name
        this.gender = gender
        this.birthDate = birthDate
        this.ssn = ssn
        this.email = email
        this.phoneNumbers = []
        if (phoneNumber != undefined) {
            this.phoneNumbers.push(phoneNumber)
        }
    }
}

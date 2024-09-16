import { Employee } from './Employee'

export class PhoneBook {
    constructor(employees: Employee[]) {
        this.employees = employees
    }

    addEmployee(employee: Employee) {
        this.employees.push(employee);
    }

    removeEmployee(employee: Employee) {
        this.employees.splice(this.employees.findIndex((e: Employee) =>
            e.ssn === employee.ssn))
    }

    getPersonByEmail(email: string): Employee | undefined {
        return this.employees.find((e: Employee) => e.email === email)
    }

    getPersonByPhone(phoneNumber: string): Employee | undefined {
        return this.employees.find((e: Employee) =>
            e.phoneNumbers.find((p: string) => p === phoneNumber))
    }

    employees: Employee[]
}

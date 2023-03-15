#include <iostream>

class Employee
{
private:
    std::string empName;
    int empAge;
    std::string position;

public:
    Employee(std::string name, int age, std::string pos)
    {
        empAge = age;
        empName = name;
        position = pos;
    }

    std::string getEmpName()
    {

        return empName;
    }
    int getEmpAge()
    {

        return empAge;
    }
    std::string getEmpPosition()
    {

        return position;
    }

    void showEmployees()
    {
        std::cout << "\n==================================================\n";

        std::cout << "Name: " << empName << "\n";
        std::cout << "Age: " << empAge << "\n";
        std::cout << "Position: " << position;

        std::cout << "\n==================================================\n";
    }
};

class EmpManagement
{

private:
    Employee *employeeArr[50];
    int numberOfEmployees;

public:
    EmpManagement()
    {
        numberOfEmployees = 0;
    }

    void addUser(Employee *user)
    {
        employeeArr[numberOfEmployees] = user;
        numberOfEmployees++;
    }

    void deleteUser(std::string userDel)
    {
        for (int i = 0; i < numberOfEmployees; i++)
        {
            if (userDel == employeeArr[i]->getEmpName())
            {
                delete employeeArr[i];
                employeeArr[i] = employeeArr[numberOfEmployees - 1];
                numberOfEmployees--;
                std::cout << "Employee deleted!" << std::endl;
                return;
            }
            else
            {
                std::cout << "Employee Not Found."
                          << "\n";
                break;
            }
        }
    }

    void Show()
    {

        for (int i = 0; i < numberOfEmployees; i++)
        {
            employeeArr[i]->showEmployees();
        }
    }
};

int main()
{
    int decider;
    std::string operationDecider;
    EmpManagement empM;
    std::string enterName;
    int enterAge;
    std::string enterPosition;
    int numberOfEmployees;
    std::string deleteName;

    empM.Show();

    while (true)
    {
        std::cout << "\n -----------------------------------\n";

        std::cout << "\n   Please choose actions to perform\n"
                  << "\n";

        std::cout << "           Add Employee[1]"
                  << "\n\n";
        std::cout << "           View Employee[2]"
                  << "\n\n";
        std::cout << "           Delete Employee[3]"
                  << "\n\n";
        std::cout << "          Search Employee[4]"
                  << "\n";

        std::cout << "\n -----------------------------------\n";

        std::cout << "Answer: ";
        std::cin >> decider;

        switch (decider)
        {
        case 1:
            std::cout << "How many numbers of employees would you like to add."
                      << "\n";

            std::cout << "Answer: ";
            std::cin >> numberOfEmployees;

            std::cout << "\n";

            for (int i = 0; i < numberOfEmployees; i++)
            {
                std::cout << "-----------------------------------\n";

                std::cout << "Enter Name: ";
                std::cin >> enterName;

                std::cout << "Enter Age: ";
                std::cin >> enterAge;

                std::cout << "Enter Position: ";
                std::cin >> enterPosition;
                std::cout << "-----------------------------------\n";
                Employee *employee = new Employee(enterName, enterAge, enterPosition);

                empM.addUser(employee);
            }

            break;
        case 2:
            empM.Show();
            break;

        case 3:
            std::cin >> deleteName;
            empM.deleteUser(deleteName);

            break;
        default:
            std::cout << "Operation not found\n";
            break;
        }

        std::cout << "Do you want to do another operation?(y/n)"
                  << "\n";
        std::cout << "Answer: ";
        std::cin >> operationDecider;
        if (operationDecider != "y" && operationDecider != "Y")
        {
            break;
        }
    }

    return 0;
}
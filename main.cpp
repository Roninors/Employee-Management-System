#include <iostream>

class Employee
{
private:
    std::string empName;
    int empAge;
    std::string position;
    int id;

public:
    Employee(std::string name, int age, std::string pos, int userId)
    {
        empAge = age;
        empName = name;
        position = pos;
        id = userId;
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
        std::cout << "Position: " << position << "\n";
        std::cout << "ID: " << id;
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
                employeeArr[i] = nullptr;

                std::cout << "Employee deleted!" << std::endl;
                break;
            }
        }
    }

    void Show()
    {

        for (int i = 0; i < numberOfEmployees; i++)
        {
            if (employeeArr[i] != nullptr)

                employeeArr[i]->showEmployees();
        }
    }

    void searchUser(std::string findUser)
    {

        for (int i = 0; i < numberOfEmployees; i++)
        {
            if (employeeArr[i]->getEmpName() == findUser)
            {
                std::cout << "User  found."
                          << "\n";
                employeeArr[i]->showEmployees();
            }
            else
            {
                std::cerr << "User not found."
                          << "\n";
            }
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
    int userId = 0;
    std::string findUser;

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
                userId++;
                std::cout << "-----------------------------------\n";

                std::cout << "Enter Name: ";
                std::cin >> enterName;

                std::cout << "Enter Age: ";
                std::cin >> enterAge;

                std::cout << "Enter Position: ";
                std::cin >> enterPosition;
                std::cout << "-----------------------------------\n";
                Employee *employee = new Employee(enterName, enterAge, enterPosition, userId);

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
        case 4:
            std::cout << "Search user by name: ";
            std::cin >> findUser;
            empM.searchUser(findUser);
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
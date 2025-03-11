/*                                      PROGRAM INFORMATION:
    NAME: Rieley Dechenne

    OVERVIEW: This program is a side project that helps reinforce my understanding of classes,
              in C++ by creating a nail management system inspired by my girlfriends career. 
              I will be working with three different classes that have both private and public
              member variables, while also working with accessors and mutators. I will also be
              working with constructors and getting more accustom to using them. The main section 
              will be displaying information that relates to the classes.

    NOTES: I understand that it is good practice to use the three file format for larger projects; 
           but I figured with this one just being a quick project for learning that it was not a big
           deal having everything be in one file.
*/ 

#include <iostream>     //This library is needed for inputs and outputs operators.
#include <string>       //This library is needed for string manipulation operations.
#include <iomanip>      //This library is needed so we can use set precision to set the number of decimal places in the return value.

class Scheduling{          //This class is responsible for handling all the scheduing functions needed for setting Nail Appointment functions per appointment and gross.
    private:
        std::string appointmentDate;         //This private string member is needed for the date(s) appointment
        int canceledAppointments;       //Private integer member for any canceled appointments 
        int totalAppointments;          //Private integer member for total appointments
        double standardPrice;           //Private double member representing the standard price per appointment.
    public: 
            //These are the accessors and mutators for this class and they are needed in order to access/modify member variables in private.
                //Accessors (getters)
        std::string getAppointmentDate() const {return appointmentDate;}
        int getCanceledAppointments() const {return canceledAppointments;}              //The four getters are defined in line and are returning the values from private variables.
        int getTotalAppointments() const {return totalAppointments;}
        double getStandardPrice() const {return standardPrice;}
                //Mutators (setters)
        void setAppointmentDate(const std::string &date) {appointmentDate = date;}
        void setCanceledAppointments(int canceled) {canceledAppointments = canceled;}           //The four setters are also defined in line and are getting reassigned to variables that are
        void setTotalAppointments(int appointmentNum) {totalAppointments = appointmentNum;}     //accessible from the main scope.
        void setStandardPrice(double standard) {standardPrice = standard;}

            //Default Constructor that sets all the values to a default value of 0.
        Scheduling() : appointmentDate("01-01-25"), canceledAppointments(0), totalAppointments(0), standardPrice(0.0) {}

};

class Billing{       //This class is responsible for handling all the billing functions per appointment and gross amount earned.
    private:                    //Using private members so sensitive information is hidden from the user.
        int numAppointments;            //This integer member variable represents the total number of appointments for the day.
        double appointmentPrice;        //This double member variable represents the price for each appointment.
        double appointmentTips;         //This double member variable represents the total amount of all tips accumulated throughout the day.
    public:                     //Using public members as these are going to be accessible and changeable by the user.
            //These are the accessors and mutators for this class and they are needed in order to access the member variables in the private class.
                //Accessors (getters)
        int getNumAppointments() const {return numAppointments;}
        double getAppointmentPrice() const {return appointmentPrice;}       //The three getters(accessors) are defined in line, and are only returning the values for each.
        double getAppointmentTips() const {return appointmentTips;}
                //Mutators (setters)
        void setNumAppointments(int appointments) {numAppointments = appointments;}     //The three setters(mutators) are defined in line also and are modifying private variables,
        void setAppointmentPrice(double price) {appointmentPrice = price;}              //The three setters(mutators) are defined in line also and are modifying private variables,
        void setAppointmentTips(double tips) {appointmentTips = tips;}                  //They do not return anything because they are void functions.

            //Default Constructor that sets all the values to a default value of 0.
        Billing() : numAppointments(0), appointmentPrice(0.0), appointmentTips(0.0) {}

            //Function that calculates the total Revenue earned from appointments.
        double calculateAppointmentRevenue() const {return (numAppointments * appointmentPrice) + appointmentTips;}

};

class Restocking{       //This class is responsible for handling all the Restocking needs for nail appointments.
    private:
        std::string itemName;                //This string sets the name for the item that needs to be restocked
        double itemPrice;                    //The double is needed for the price per item.
        int itemQuantity;                    //This integer is needed for the total quantity of item needed.
    public:
            //These are the accessors and mutators for this class and they are needed in order to access the member variables in the private class.
                //Accessors (getters)
        std::string getItemName() const {return itemName;}
        double getItemPrice() const {return itemPrice;}                 //The three getters(accessors) are defined in line, and are only returning the values for each.
        int getItemQuantity() const {return itemQuantity;}
                //Mutators (setters)
        void setItemName(const std::string &name) {itemName = name;}                                //The three setters(mutators) are defined in line also and are modifying private variables,
        void setItemPrice(double restockPrice) {itemPrice = restockPrice;}              //They do not return anything because they are void functions.
        void setItemQuantity(int restockQuantity) {itemQuantity = restockQuantity;}

                //Default Constructor that sets all the values to a default value of 0.
        Restocking() : itemName("Nail Polish"), itemPrice(0.0), itemQuantity(0) {}

                //Function that calculates the total restocking price
        double calculateRestockingPrice() const { return itemPrice * itemQuantity;}
};

int main() {            //Main scope for the program. 

        //Declaring the classes to local instances for useability within the main scope.
    Scheduling schedule;   
    Billing bill;
    Restocking restock;

        //Setting the values for each element from the scheduling class.
    schedule.setAppointmentDate("3/11/2025");
    schedule.setCanceledAppointments(1);
    schedule.setTotalAppointments(4);
    schedule.setStandardPrice(55.0);

        //Setting the values for each element from the billing class.
    bill.setNumAppointments(4);
    bill.setAppointmentPrice(60.0);
    bill.setAppointmentTips(57.50);

        //Setting the values for each element from the restocking class.
    restock.setItemName("Nail Polish");
    restock.setItemPrice(14.99);
    restock.setItemQuantity(38);

        //Displaying information retaining to the scheduling class.
            //Using fixed << setprecision(2) for all the code that returns a value, to only display 2 decimals.
    std::cout << "Scheduling Information: " << std::endl;
    std::cout << "************************" << std::endl;

    std::cout << "Appointment Date: " << schedule.getAppointmentDate() << std::endl;
    std::cout << "Total Canceled Appointments: " << schedule.getCanceledAppointments() << std::endl;
    std::cout << "Total Appointments: " << schedule.getTotalAppointments() << std::endl;
    std::cout << "Standard Price per Appointment: $" << std::fixed << std::setprecision(2) << schedule.getStandardPrice() << std::endl;
    
        //Displaying information retaining to the billing class.
    std::cout << "*********************" << std::endl;
    std::cout << "Billing Information: " << std::endl;
    std::cout << "*********************" << std::endl;

    std::cout << "Total Billable Appointments: " << bill.getNumAppointments() << std::endl;
    std::cout << "Actual Appointment Price: $" << std::fixed << std::setprecision(2) << bill.getAppointmentPrice() << std::endl;
    std::cout << "Total Appointment Tips Accured: $" << std::fixed << std::setprecision(2) << bill.getAppointmentTips() << std::endl;
    std::cout << "Total Revenue: $" << std::fixed << std::setprecision(2) << bill.calculateAppointmentRevenue() << std::endl;

        //Displaying information retaining to the restocking class.
    std::cout << "*******************" << std::endl;
    std::cout << "Restocking Report: " << std::endl;
    std::cout << "*******************" << std::endl;

    std::cout << "Item Name: " << restock.getItemName() << std::endl;
    std::cout << "Item Price: $" << std::fixed << std::setprecision(2) << restock.getItemPrice() << std::endl;
    std::cout << "Item Quantity: " << restock.getItemQuantity() << std::endl;
    std::cout << "Restocking Cost: $" << std::fixed << std::setprecision(2) << restock.calculateRestockingPrice() << std::endl;

    return 0;
}
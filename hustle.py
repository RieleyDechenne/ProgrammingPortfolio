'''
Info:
    The purpose of this program is to track my personal side hustle 
    and to use Python with other libraries to demonstrate the visualizations 
    and trends of the side hustle. 
'''

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import csv

# Section 1: Basic Tracking Properties
#   - Handles all the calculations and inputs

def dash_entry():
    gas = 35.00

    date = input("Enter the Date for Entry, (MM/DD/YYYY): ")
    num_dash = int(input("Enter the total amount of dash(es): "))
    time_spent = float(input("Enter the total amount of time spent: "))
    income = float(input("Enter the amount made total for the day: "))
    tips = float(input("Enter your tips for the day: "))
    profit = (income - gas)
    

    with open("***************************", 'a', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow([date, num_dash, time_spent, income, tips, profit])
    
    print("Entry has been saved!")

def previous_dashes():
    with open("***************************", 'r', encoding='utf-8') as file:
        reader = csv.reader(file)

        for row in reader:
            if len(row) != 6:
                print(row)
                continue

            date, num_dash, time_spent, income, tips, profit = row
            print(f"{date} | {time_spent} | {num_dash} | ${profit}")

def dash_analytics():

    # Sets the dataframe to be the dash_analytics csv file 
    df = pd.read_csv("Dash_analytics.csv")

    # avg $/hour, avg $/dash, YTD profit, YTD Dashes, YTD Hours
    print("______________________________\n")
    print("Showing Current YTD Analytics!")
    print("______________________________\n")

    # Calculates the YTD Expenses
    expenses_YTD = df["Income"].astype(float).sum() - df["Profit"].astype(float).sum()
    print(f"Total Expense YTD: ${expenses_YTD:.2f}")
    print("______________________________")

    # Calculating YTD Profit
    profit_YTD = df["Profit"].astype(float).sum()
    print(f"Total Profit YTD: ${profit_YTD:.2f}")
    print("______________________________")

    # Calculates YTD Tips 
    tips_YTD = df["Tips"].astype(float).sum()
    print(f"Total YTD Tips: ${tips_YTD:.2f}")
    print("______________________________")

    # Calculate YTD Dashes
    dash_YTD = df["Dashes"].astype(int).sum()
    print(f"Total Dashes YTD: {dash_YTD:.2f}")
    print("______________________________")

    # Calculate YTD Hours 
    hours_YTD = df["Hours"].astype(float).sum()
    print(f"Total Hours YTD: {hours_YTD:.2f}")
    print("______________________________")

    # Calculates Average $/hour
    avg_hour = (profit_YTD / hours_YTD)
    print(f"Average $ Per Hour: ${avg_hour:.2f}")
    print("______________________________")

    # Calculates Average $/Dash
    avg_dash = (profit_YTD / dash_YTD)
    print(f"Average $ Per Dash: ${avg_dash:.2f}")
    print("______________________________")

# Section 2: Visualizations & Insights
def dash_piechart():
    # Sets the dataframe to be the dash_analytics csv file and assigns elements values
    df = pd.read_csv("Dash_analytics.csv")

    # Sets a fixed amount for income goal and calculates YTD Profit
    income_goal = 1500
    profit_YTD = df["Profit"].astype(float).sum()

    # Assigns the pie charts values, categories, and colors
    categories = ["Current-Standing", "Income Goal"]
    values = np.array([profit_YTD, income_goal])
    colors = ["Red", "Green"]

    # Pie Chart creation
    plt.title("DoorDashing Pie Chart")
    plt.pie(values, 
            labels=categories, 
            autopct="%1.2f%%", 
            colors=colors,
            explode=[0, 0.2], 
            shadow=True)
    plt.show()

def dash_barplot():
    # Sets the dataframe to be the dash_analytics csv file and assigns elements values
    df = pd.read_csv("Dash_analytics.csv")

    # Sets fixed amount for income goal and calculates YTD Profit and Expenses
    income_goal = 1500
    profit_YTD = df["Profit"].astype(float).sum()
    expenses_YTD = df["Income"].astype(float).sum() - df["Profit"].astype(float).sum()

    # Sets the Categories for the Bar Chart
    categories = ["Income Goal", "Profit YTD", "Expenses YTD"]
    values = np.array([income_goal, profit_YTD, expenses_YTD])
    
    # Creates the Bar Graph and Customizes it 
    plt.title("DoorDashing Bar Chart")
    plt.bar(categories, values)
    plt.xlabel("Income")
    plt.ylabel("Amount")
    plt.show()

# Section 3: Interactive Dashboard
#   - Allows the user to add entries, view previous dashes, current YTD analytics, and view visualizations of income
def dashboard():
    # Greeting message and prompt user to select from the menu below
    print("Welcome to the DoorDashing Tracker!\n")

    # Menu Template
    print("1 - Add Entry ➕\n")
    print("2 - View Prev. Entries 🪟\n")
    print("3 - View Current YTD Analytics 📈\n")
    print("4 - View Dashing Trends 📊\n")

    while True:
        choice = input("Select from the above ^\n")

        if choice == "1":
            dash_entry()
            break
        elif choice == "2":
            previous_dashes()
            break
        elif choice == "3":
            dash_analytics()
            break
        elif choice == "4":
            while True:
                print("______________________________")
                print("P - Pie Chart")
                print("B - Barplot")
                print("______________________________")
                graph = input("Enter Graph Type: (P or B):\n").upper()

                if graph == "P":
                    dash_piechart()
                    break
                elif graph == "B":
                    dash_barplot()
                    break
                else:
                    print("Enter a valid graph type (P or B)!")
                    continue
            
        else:
            print("Please Enter a number 1 - 4!")
            return False

# Section 4: Main function
def main():
    dashboard()

if __name__ == "__main__":
    main()



'''
    Project Description:
        This program is another exercise of cleaning messy warehouse data
        that was obtained via a public github repo. After the data has been 
        cleaned and organized it will be plotted to demonstrate a visual 
        representation. 


'''

import pandas as pd
import numpy as np

# Creates dataframe with elements from csv file
df = pd.read_csv("warehouse_messy_data.csv") 

#1. Drop Irrelevant Columns - Location, Status, Restock Status
df = df.drop(columns=["Location", "Last Restocked"])

#2. Handle Missing Data
df = df.fillna({"Price": "n/a"})

#3. Fix inconsistent values
df["Quantity"] = df["Quantity"].replace('two hundred', 200)

#4. Standardize Text
df["Category"] = df["Category"].str.lower().str.capitalize()

#5. Fix/Change data types
df["Status"] = df["Status"].astype(bool)

#6. Remove Duplicate Values
df = df.drop_duplicates()

print(df)
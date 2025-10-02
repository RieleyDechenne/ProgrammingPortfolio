'''
    Project Description:
        This program is meant to be an attempt at data cleaning a set of data using pandas.
        I will be getting and using data from github while also using basic syntax and operations
        to perform simple data cleaning procedures. 

'''

import pandas as pd

#Creates dataframe with elements from csv file
df = pd.read_csv("pokemon.csv")

#1. Drop Irrelevant Columns
df = df.drop(columns=["Generation", "Sp. Atk", "Sp. Def"])

#2. Handle Missing Data - Removes rows with null values in type2
#   (dropna = Drop Not Available) - df = df.dropna(subset=["Type 2"])
#   (fillna = Fill any Not Available) 
df = df.fillna({"Type 2": "None"})

#3. Fix inconsistent values - Capitalize main types
df["Type 1"] = df["Type 1"].replace({"Grass": "GRASS",
                                     "Fire": "FIRE",
                                     "Water": "WATER"})

#4. Standardize Text
df["Name"] = df["Name"].str.lower()

#5. Fix/change data types
df["Legendary"] = df["Legendary"].astype(bool)

#6. Remove Duplicate values
df = df.drop_duplicates()

print(df)
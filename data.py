'''
Program Description: 
    This program takes in a text file and reads the words, counts them, tokenizes them, 
    and then plots their frequencies by rank in either a conventional style plot or a 
    log fashion plot. 

    E.g.): python3 data.py MM L 
'''



import sys                              #Need to import because we are using sys.argv
import math                             #Need to import in order to use the log function for the log fashion plot
import re                               #Need to import so we can tokenize the text
import matplotlib.pyplot as plt         #Need to import so we can plot data
from pathlib import Path                #Need to import so we can set path constraints for the different text
from operator import itemgetter         #Need in order to reserve the o

#Step 1: File Path Constraints and Reading Data ✅

    #File Path Constrains - Has a constraint indicating the path to the data
MM_PATH = Path("*********************") 
UL_PATH = Path("*********************")
MR_PATH = Path("*********************")

    #Read Function(s) - Opens the files in read mode with encoding utf-8 and then assigns to 'file'
def read_data(data_type):
    def read_MM():
        with open("*********************", 'r', encoding='utf-8') as file:
            return file.read()
    def read_UL():
        with open("*********************", 'r', encoding='utf-8') as file:
            return file.read()
    def read_MR():
        with open("*********************", 'r', encoding='utf-8') as file:
            return file.read()
    
    #If statement to read correct files
    if data_type == "MM":
        return read_MM()
    elif data_type == "UL":
        return read_UL()
    elif data_type == "MR":
        return read_MR()
    else:
        print("Incorrect Data Type")
        return False

#Step 2: Counter function that counts words & frequency ✅
def word_count(file_contents):

    #Assigns the tokenized text to a new list
    lst = tokenize(file_contents)

    #Counts the words from specific text using a dictionary 
    count_dict = {}
    for word in lst:
        if word in count_dict:
            count_dict[word] = count_dict[word] + 1
        else:
            count_dict[word] = 1
    
    #Sorts frequencies in reverse order then writes to another list (sorted_list)
    sorted_list = sorted(count_dict.items(), key = itemgetter(1), reverse = True)
    return sorted_list

#Step 3: Tokenizer that splits the text into tokens
def tokenize(string_in):
    
    string = re.sub('\n', ' ', string_in)

    #Creates a list containing all lower case characters
    good_char = [chr(value) for value in range(ord('a'), ord('z') + 1, 1)]
    good_char.append(' ')
    string = string.lower()
     
    new_str = ''
    for ch in string:
        if ch in good_char:
            new_str = new_str + ch
        else:
            new_str = new_str + ' '

    #Removes spaces from the string  
    lst = new_str.split()
    return lst

#Step 4: Plotting the Data (Also assigns plots to sys.argv data_type)
def plot_conventionally(x, y):
    pl = plt.gca()
    pl.plot(x, y, 'b')
    pl.set_title("Word Frequencies Plotted Conventionally")
    pl.set_xlabel("Rank")
    pl.set_ylabel("Word Frequencies")
    plt.show()

def plot_log(x, y):
    pl = plt.gca()
    xx = [math.log(i) for i in x]
    yy = [math.log(i) for i in y]
    pl.plot(xx, yy, 'r')
    pl.set_title("Word Frequencies Plotted Log Fashion")
    pl.set_xlabel("Rank")
    pl.set_ylabel("Word Frequencies")
    plt.show()

#Step 5: Command line arguments - Accepts Two Command Line Arguments
def command_arguments():
   
    data_type = sys.argv[1].upper()
    plot_type = sys.argv[2].upper()

    return data_type, plot_type

#Step 6: Putting it all together 
def main():
    data_type, plot_type = command_arguments()

    text = read_data(data_type)
    word_frequencies = word_count(text)
    ranks = list(range(1, len(word_frequencies) + 1))
    frequencies = [freq for word, freq in word_frequencies]

    if plot_type == "C":
        plot_conventionally(ranks, frequencies)
    elif plot_type == "L":
        plot_log(ranks, frequencies)
    else:
        print("Invalid plot type")
        return

if __name__ == "__main__":
    main()
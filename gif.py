
# Need this library in order to import images
import imageio.v3 as iio        

# List containing the locations of the image file
filenames = ['Fish1.png', 'Fish2.png']        
#Stores the data file contains into a new list
images = []             

# Loops through the file contents using imageio.v3 imread() method
for filename in filenames:
    images.append(iio.imread(filename))

# Turns images into gifs using the imwrite() method
iio.imwrite('fish.gif', images, duration = 500, loop = 0)




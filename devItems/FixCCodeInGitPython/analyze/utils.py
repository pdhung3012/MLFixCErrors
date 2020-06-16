import os

def createDir(folderName):
    try:
        # Create target Directory
        os.mkdir(folderName)
        print("Directory ", folderName, " Created ")
    except FileExistsError:
        print("Directory ", folderName, " already exists")
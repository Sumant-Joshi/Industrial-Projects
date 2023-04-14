
#####################################################################################
#
#  Application Name: DUPLICATE FILE REMOVER
#  Input  : DIRECTORY PATH
#  Output : DETECTS AND REMOVES DUPLICATE FILES
#  Author : SUMANT JOSHI
#  
#
######################################################################################




#######################################################################################
#   IMPORTED MODULES, LIBRARIES 
#######################################################################################

from sys import *
import os 
import hashlib
import time
import datetime 
from collections import defaultdict

#######################################################################################
#   SCRIPT FUNCTIONS
#######################################################################################

def DeleteFiles(dict1):
    results = list (filter (lambda x: len(x)>1,dict1.values()))
    
    iCnt = 0
 
    if (len (results) > 0):
        for result in results :
            for subresult in result:
                iCnt += 1
                if iCnt >= 2:
                    os.remove(subresult)
            iCnt = 0

    else:
        print("No Duplicate files found")


def PrintResults(dict1):
    results = list(filter(lambda x : len (x) > 1,dict1.values()))

    if len (results) > 0:                       
        print("Duplicate Found : ")
        print("The following files are identical.")

        iCnt = 0
        for result in results :
            for subresult in result:
                iCnt +=1
                if iCnt >= 2:
                    print(subresult)
                print()
    else:
        print("No duplicate files found")

def hashfile(path,blocksize = 1024):
    afile = open (path,'rb')
    hasher = hashlib.md5()
    buf = afile.read(blocksize)

    while len (buf)>0:
        hasher.update(buf)
        buf = afile.read(blocksize)
    afile.close()

    return hasher.hexdigest()


def FindDuplicate(path):
    flag = os.path.isabs(path)

    if flag == False:
        path = os.path.abspath(path)

    exists = os.path.isdir(path)
    dups = defaultdict(list)
    
    directorypath,a = os.path.split(argv[1])
    

    if os.path.isdir("Duplicate_Removal"):
        folder_path = os.path.abspath("Duplicate_Removal")
        seperator = "-"*80
        log_path = os.path.join(folder_path+"\\"+f"{a}"+"Duplicate"+"_%s.log"%(datetime.datetime.now().strftime("%Y-%m-%d_%H.%M.%S")))

        f_Duplicate = open (log_path,"w",encoding = 'utf-8')

        f_Duplicate.write(seperator +"\n")
        f_Duplicate.write("Automations : "+time.ctime()+"\n")
        f_Duplicate.write(seperator +"\n")

    else:
        folder = os.mkdir("Duplicate_Removal")
        seperator = "-"*80
        log_path = os.path.join(folder+"\\"+"Duplicate"+f"{a}"+"_%s.log"%(datetime.datetime.now().strftime("%Y-%m-%d_%H.%M.%S")))
  
        f_Duplicate = open (log_path,"w",encoding = 'utf-8')
  
        f_Duplicate.write(seperator +"\n")
        f_Duplicate.write("Automations : "+time.ctime()+"\n")
        f_Duplicate.write(seperator +"\n")


    if exists : 

        count = 0
        OCnt = 0
        DCnt = 0
        TotalSize = 0
        KB = 0
        MB = 0
        GB = 0
        for dirName, subdirs,fileList in os.walk(path):
            for filen in fileList:
                path = os.path.join(dirName,filen)
                file_hash = hashfile(path)
                
                if file_hash in dups:
                    count+=1
                    DCnt +=1
                    dups[file_hash] += [(path)]
                    f_Duplicate.write(str(DCnt) + "." + path + "\n")
                    TotalSize = TotalSize + os.path.getsize(path)
                else:
                    OCnt+=1
                    dups[file_hash] = [(path)]
                 
        if (TotalSize>1024):
            KB = TotalSize/1024
            
            if (KB>1024):
                MB = KB/1024
               
                if (MB>1024):
                    GB = MB/1024

        if ((KB>1) and (MB<1)):
            print("Total Size of Duplicate Files :{0:.2f} KB".format(KB))
        if ((MB>1) and (GB<1)):
            print("Total Size of Duplicate Files :{0:.2f} MB".format(MB))
        if (GB>1):
            print("Total Size of Duplicate Files :{0:.2f} GB".format(GB))

        

        return dups,count;

    else:
        print("Invalid Path")



#######################################################################################
#   START OF SCRIPT
#######################################################################################


def main():
    print("------------------------DUPLICATE FILE REMOVER------------------------")

    print("Automation script started with name : ",argv[0])

    if(len(argv) != 2):
        print("Error : Insufficient arguments")
        print("Use -h for help and use -u for usage of the script")
        exit()

    if((argv[1] == "-h") or (argv[1] == "-H")):
        print("Help : This script is used to traverse specific irectory and delete duplicate files")
        exit()

    elif((argv[1] == "-u") or (argv[1] == "-U")):
        print("Usage : Provide one argument as")
        print("First Argument as :AbsolutePath_Of_Directory")
        exit()

    else:
        try:
            arr =defaultdict(list)
            count  = 0
            startTime = time.process_time()
            arr,count = FindDuplicate(argv[1])
            # PrintResults(arr)
            if (count > 0):
                print("Total number of duplicate files : ",count)
                Nod = input("Do you still want to delete the files?(Y/N)  :")
                if (Nod == 'Y' or Nod == 'y'):
                    DeleteFiles(arr)
                    print("All Duplicate files are deleted Successfully")
                    print("Please check log file for details of deleted files ")
                else:
                    print("Thank you for using application")
            else:
                print("There are no duplicate file in given directory")

            endTime = time.process_time()
            print("Took {0:.4f} seconds to evaluate".format(endTime-startTime))

        except ValueError:
            print("Error : Invalid datatype of input")

        except Exception as E:
            print("Error : Invalid input",E)

        
#######################################################################################
#   SCRIPT STARTER 
#######################################################################################


if __name__ == "__main__":
    main()
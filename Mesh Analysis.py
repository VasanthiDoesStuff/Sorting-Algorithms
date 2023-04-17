import numpy as np
import itertools 


print("MESH ANALYSIS")
print("Assumption:Each mesh current flows in the clockwise direction, thus;")
print("(i) All self-resistances will always be postive")
print("(ii) all mutual resistances will always be negative.")
n = int(input('Enter number of meshes in the circuit:'))
#Entering each mesh number in to a list P
P = []
for i in range (0,n):
    P.append(i+1)



#Finding all the possible combinations of mesh numbers
#To find the resistors common to meshes
#Function definition
#Combination finder
def combination(arr,k):
    return list(itertools.combinations_with_replacement(arr,k))
l = combination(P,2)


size = len(l)
#Q list stores all the resistance values entered in accordance with mesh numbers
Q=[]


            
#Collecting Input of resistance values
print("NOTE: Enter effective resistance from each branch!!")
for i in range (0,size):
    if ( l[i][0] == l[i][1]):
        print("Enter resitance that is only in mesh ", l[i][0])
        r = int(input("Enter value:"))
    else:
        print("Enter resitance common to the meshes ",l[i][0],l[i][1])
        r = int(input("Enter value:"))
    Q.append(r)

#Creating dictionary to map resistance values with the mesh numbers
resistance = {}
for i in range (0,size):
    resistance[l[i]]= Q[i]
    
#Function definition
#calculate total resistance in a single mesh
def calc(s):
    val = 0
    for j in range(0,size):
        if (l[j][0]==s or l[j][1]==s):
            val+=Q[j]
    return val

#initializing resistance matrix : resitanceArr
rst = [[0 for x in range (n)] for y in range (n)]
#Adding data to the list of lists : r
for i in range (0,n):
    for j in range (0,n):
        if i==j:
            rst[i][j]= calc(i+1)
        elif (i<j):
            rst[i][j]= (-1)*resistance[(i+1,j+1)]
        elif (i>j):
            rst[i][j]= (-1)*resistance[(j+1,i+1)]
resitanceArr = np.array(rst)

#Function definition
#Display resistance matrix
def display():
    print("The resistance matrix for the described circuit is as follows")
    for i in range (0,n):
        for j in range (0,n):
            print(rst[i][j] ,end ="\t")
        print("\n")
display()




#Emf matrix : emf
#Collecting input of emf values in each mesh
emfl=[]
num = int(input("Enter number of meshes having cells in them:"))
for i in range (0,n):
    print("Does mesh ",i+1," contain more than one cell?")
    inp = input("(y/n):")
    if (inp == 'y'):
        cells = int(input("Enter number of cells in this mesh:"))
        a = input("Do all the cells support current produced by each other? (y/n):")
        emf3 = 0
        if ( a == 'y'):
            emf1 = int(input("Enter emf of cell in the mesh:"))
            for j in range(0,cells-1):
                emf2 = int(input("Enter emf of cell common in the mesh:"))
                emf3 += emf2
            emfl.append(emf3+emf1)
        else:
            emf1 = int(input("Enter emf of cell in the mesh:"))
            if (cells != 2):
                d = int(input("Enter number of cells which support:"))
                for j in range(0,d):
                    emf2 = int(input("Enter emf of cell common in the mesh:"))
                    emf3 += emf2
                opp = cells - d-1
                for j in range(0,opp):
                    emf4 = int(input("Enter emf of cell common in the mesh,that opposes:"))
                    emf3 -= emf4
                emfl.append(emf3+emf1)
            elif(cells == 2):
                emf4 = int(input("Enter emf of cell common in the mesh,that opposes:"))
                emf3 -= emf4
                emfl.append(emf3+emf1)
                
    elif (inp =='n'):
        print("Does mesh ",i+1," contain atleast one cell?")
        char = input("(y/n):")
        if (char == 'y'):
            print("Enter emf of cell in mesh ",i+1)
            emf3 = int(input("Enter emf of cell in mesh "))
            emfl.append(emf3)
        else:
            emfl.append(0)
#intializing emf matrix : emfArr
emfArr = np.array(emfl)
print ("The emf matrix is as follows")
print(emfArr)

#solving the equations
currentArr = []
currentArr = np.linalg.solve(resitanceArr, emfArr)


#results
print ("The current in each mesh is displayed below")
for i in range (0, len(currentArr)):
    print ("The current in mesh ",i+1,":", currentArr[i])
    
    
    

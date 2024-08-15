import matplotlib.pyplot as plt
import csv
import sys

XandY = {}
valid = False

choice = int(
    input(
        "Do you want to plot:\n(1)All algorithms used for a specific size\n(2)One algorithm in every instance(random, reverse, almost) in a specific size\n(3)One algorithm in in every size and all instances\n"
    )
)

TimeMeasurments = [
    "Nanoseconds",
    "Microseconds",
    "Milliseconds",
    "Seconds",
    "Hours",
]

font1 = {"family": "serif", "color": "blue", "size": 20}
font2 = {"family": "serif", "color": "darkred", "size": 15}

if choice == 1:
    print("Select only the number of the file\n\n")
    print(
        "Which file do you want to plot?\n\n(1)ResultsRandom_Size1\n(2)ResultsRandom_Size2\n(3)ResultsRandom_Size3\n(4)ResultsRandom_Size4\n(5)ResultsRandom_Size5\n(6)ResultsRandom_Size6\n(7)ResultsRandom_Size7\n(8)ResultsRandom_Size8\n(9)ResultsRandom_Size9\n"
    )
    print(
        "(11)ResultsReverse_Size1\n(12)ResultsReverse_Size2\n(13)ResultsReverse_Size3\n(14)ResultsReverse_Size4\n(15)ResultsReverse_Size5\n(16)ResultsReverse_Size6\n(17)ResultsReverse_Size7\n(18)ResultsReverse_Size8\n(19)ResultsReverse_Size9\n"
    )
    print(
        "(21)ResultsAlmost_Size1\n(22)ResultsAlmost_Size2\n(23)ResultsAlmost_Size3\n(24)ResultsAlmost_Size4\n(25)ResultsAlmost_Size5\n(26)ResultsAlmost_Size6\n(27)ResultsAlmost_Size7\n(28)ResultsAlmost_Size8\n(29)ResultsAlmost_Size9"
    )

    FileNumber = int(input("ID: "))

    if sys.platform.startswith("linux") or sys.platform == "darwin":
        if FileNumber >= 1 and FileNumber <= 9:
            FileName = (
                "results/ResultsCSV/ResultsRandom/ResultsRandom_Size"
                + str(FileNumber)
                + ".csv"
            )
            Fn = "PlotsRandom/ResultsRandom_Size" + str(FileNumber)
            valid = True
            Type = "random"

        if FileNumber >= 11 and FileNumber <= 19:
            FileName = (
                "results/ResultsCSV/ResultsReverse/ResultsReverse_Size"
                + str((FileNumber % 10))
                + ".csv"
            )
            Fn = "PlotsReverse/ResultsReverse_Size" + str((FileNumber % 10))
            valid = True
            Type = "reverse"

        if FileNumber >= 21 and FileNumber <= 29:
            FileName = (
                "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size"
                + str((FileNumber % 10))
                + ".csv"
            )
            Fn = "PlotsAlmost/ResultsAlmostSorted_Size" + str((FileNumber % 10))
            valid = True
            Type = "almost sorted"
    elif sys.platform == "win32":
        if FileNumber >= 1 and FileNumber <= 9:
            FileName = (
                r"results\ResultsCSV\ResultsRandom\ResultsRandom_Size"
                + str(FileNumber)
                + ".csv"
            )
            Fn = r"PlotsRandom\ResultsRandom_Size" + str(FileNumber)
            valid = True
            Type = "random"

        if FileNumber >= 11 and FileNumber <= 19:
            FileName = (
                r"results\ResultsCSV\ResultsReverse\ResultsReverse_Size"
                + str((FileNumber % 10))
                + ".csv"
            )
            Fn = r"PlotsReverse\ResultsReverse_Size" + str((FileNumber % 10))
            valid = True
            Type = "reverse"

        if FileNumber >= 21 and FileNumber <= 29:
            FileName = (
                r"results\ResultsCSV\ResultsAlmost\ResultsAlmost_Size"
                + str((FileNumber % 10))
                + ".csv"
            )
            Fn = r"PlotsAlmost\ResultsAlmostSorted_Size" + str((FileNumber % 10))
            valid = True
            Type = "almost sorted"
        pass

    if valid == True:
        with open(FileName, mode="r") as results:
            results_data = csv.reader(results, delimiter=",")
            next(results_data)
            wrow = int(input(
                    "Which time measurment do you want to use?\n(1)Nanoseconds\n(2)Microseconds\n(3)Milliseconds\n(4)Seconds\n(5)Hours\n")
                )
            XandY = {
                rows[0]: float(rows[wrow]) for rows in results_data
            }  # change the number from rows[number] based on the time unit you want to plot

            maxValue = max(XandY.values())
            fig, axes = plt.subplots(figsize=(8, 8))
            plt.bar(*zip(*XandY.items()))
            plt.xlabel("Algorithms(used on " + Type + " generated arrays)", font1)
            plt.ylabel("Duration in " + TimeMeasurments[wrow - 1], font2)

            # Set y-axis to logarithmic scale
            plt.grid(axis="y")
            if maxValue > 10**4:
                plt.ylabel(
                    "Duration in " + TimeMeasurments[wrow - 1] + " (log scale)", font2
                )  # In case you modified the number from rows[number] you may want to change the label too
                plt.yscale("log")

            if sys.platform.startswith("linux") or sys.platform == "darwin":
                NameOfPlot = "results/ResultsPlots/" + Fn + ".svg"
            elif sys.platform == "win32":
                NameOfPlot = "results\\ResultsPlots\\" + Fn + ".svg"

            plt.savefig(NameOfPlot)
            plt.show()

if choice == 2:
    Algo = input("Which algorithm do you want to plot?(Quicksort, Merge sort, Insertion sort, Bubble sort, Selection sort)\n")
    Size = input("1, 2, 3, 4, 5, 6, 7, 8\n")
    
    x= ["random", "reverse", "almost"]
    
    if Algo == "Quicksort":
        fn = "Quicksort"
        acroF = "QuickSort"
    if Algo == "Merge sort":
        acroF = "MergeSort"
        fn = "Merge_Sort"
    if Algo == "Selection sort":
        acroF = "SelectionSort"
        fn = "Selection_Sort"
    if Algo == "Insertion sort":
        acroF = "InsertionSort"
        fn = "Insertion_Sort"
    if Algo == "Bubble sort":
        acroF = "BubbleSort"
        fn = "Bubble_sort"

    Fn = fn+"CombPlot"
    if sys.platform.startswith("linux") or sys.platform == "darwin":
        FileName = "results/Combined/" + fn + "/Size"+ Size+"/"+ acroF + ".csv"
    elif sys.platform == "win32":
        FileName = "results\\Combined\\" + fn + "\\Size"+ Size+"\\"+ acroF + ".csv"
    Lists = []
    i=0
    
    with open(FileName, mode="r") as results:
        results_data = csv.reader(results, delimiter=",")
        next(results_data)
        wrow = int(input("Which time measurment do you want to use?\n(1)Nanoseconds\n(2)Microseconds\n(3)Milliseconds\n(4)Seconds\n(5)Hours\n"))
        XandY = {x[i]: float(row[wrow-1]) for i, row in enumerate(results_data)}
            
    plt.bar(*zip(*XandY.items()))
        
    plt.grid(axis="y")
    plt.xlabel(Algo + " used on all cases", font1)
    plt.ylabel("Duration in " + TimeMeasurments[wrow - 1], font2)
    
    maxValue = max(XandY.values())
    
    if maxValue > 10**4:
            plt.ylabel(
                "Duration in " + TimeMeasurments[wrow - 1] + " (log scale)", font2
            )  # In case you modified the number from rows[number] you may want to change the label too
            plt.yscale("log")
        
    if sys.platform.startswith("linux") or sys.platform == "darwin":
        NameOfPlot = "results/ResultsPlots/PlotsCompare/Size"+ Size +"/"+ Fn +".svg"
    elif sys.platform == "win32":
        NameOfPlot = "results\\ResultsPlots\\PlotsCompare\\Size"+ Size +"\\"+ Fn +".svg"

    plt.savefig(NameOfPlot)
    plt.show()
    
if choice == 3:
    Algo = input("Which algorithm do you want to plot?(Quicksort, Merge sort, Insertion sort, Bubble sort, Selection sort)\n")
    
    if Algo == "Quicksort":
        fn = "QuickSort"
    if Algo == "Merge sort":
        fn = "MergeSort"
    if Algo == "Selection sort":
        fn = "SelectionSort"
    if Algo == "Insertion sort":
        fn = "InsertionSort"
    if Algo == "Bubble sort":
        fn = "BubbleSort"
        
    Fn = fn + "PlotsComb"    
    
    fnRandom = "All"+ fn + "sRandom.csv"
    fnReverse = "All" + fn + "sReverse.csv"
    fnAlmost = "All" + fn + "sAlmost.csv"
    
    Reverse = []
    Random = []
    Almost = []
    i=-1
    
    ListOfTypes = [Reverse, Random, Almost]
    
    if sys.platform.startswith("linux") or sys.platform == "darwin":
        FileNames = ["results/Comb/"+ fn +"/Randoms/"+fnRandom,"results/Comb/"+ fn +"/Reverses/"+fnReverse,"results/Comb/"+ fn +"/Almosts/"+fnAlmost]
    elif sys.platform == "win32":
        FileNames = ["results\\Comb\\"+ fn +"\\Randoms\\"+fnRandom,"results\\Comb\\"+ fn +"\\Reverses\\"+fnReverse,"results\\Comb\\"+ fn +"\\Almosts\\"+fnAlmost]
    
    wrow = int(input("Which time measurment do you want to use?\n(1)Nanoseconds\n(2)Microseconds\n(3)Milliseconds\n(4)Seconds\n(5)Hours\n"))
    for FileName in FileNames:
        i+=1
        with open(FileName, mode="r") as results:
            results_data = csv.reader(results, delimiter=",")
            next(results_data)
            
            for line in results_data:
                if(i==0):
                    Random.append(float(line[wrow-1]))
                    continue
                if(i==1):
                    Reverse.append(float(line[wrow-1]))
                    continue
                if(i==2):
                    Almost.append(float(line[wrow-1]))
                    continue
                    
    maxValue = 0.0
    
    for list in ListOfTypes:
        for element in list:
            if element > maxValue:
                maxValue = element 
        
    plt.plot(Random, label = "Random")
    plt.plot(Reverse, label = "Reverse")
    plt.plot(Almost, label = "Almost")
    
    plt.legend(loc="lower right")
    plt.grid(axis="y")
    plt.xlabel(Algo + " used on all cases", font1)
    plt.ylabel("Duration in " + TimeMeasurments[wrow - 1], font2)
    
    if maxValue > 10**4:
        plt.ylabel(
            "Duration in " + TimeMeasurments[wrow - 1] + " (log scale)", font2
        )  # In case you modified the number from rows[number] you may want to change the label too
        plt.yscale("log")
        
    if sys.platform.startswith("linux") or sys.platform == "darwin":
        NameOfPlot = "results/ResultsPlots/PlotsComb/"+ Fn +".svg"
    elif sys.platform == "win32":
        NameOfPlot = "results\\ResultsPlots\\PlotsComb\\"+ Fn +".svg"
    plt.savefig(NameOfPlot)
    plt.show()

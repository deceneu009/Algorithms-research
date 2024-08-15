import csv
import sys

valid = False

print("Select the algorithm and What size you want to get\n\n")
Algo = input(("Algorithm: "))
Type = input(("Type(random, reverse, almost): "))
Lines = []

if Algo == "Quicksort":
    acro = "QuickSort"
if Algo == "Merge sort":
    acro = "MergeSort"
if Algo == "Insertion sort":
    acro = "InsertionSort"
if Algo == "Bubble sort":
    acro = "BubbleSort"
if Algo == "Selection sort":
    acro = "SelectionSort"

if sys.platform.startswith("linux"):
    if Type == "random":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size1.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size2.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size3.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size4.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size5.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size6.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size7.csv",
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size8.csv",
        ]
        fn="Randoms"
        nickn = "Random"
        
    if Type == "reverse":
        FileNames = [
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size1.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size2.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size3.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size4.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size5.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size6.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size7.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size8.csv",
        ]
        fn="Reverses"
        nickn = "Reverse"
        
    if Type == "almost":
        FileNames = [
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size1.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size2.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size3.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size4.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size5.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size6.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size7.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size8.csv",
        ]
        fn="Almosts"
        nickn = "Almost"
else:
    if Type == "random":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size1.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size2.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size3.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size4.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size5.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size6.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size7.csv",
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size8.csv",
        ]
        fn="Randoms"
        nickn = "Random"
        
    if Type == "reverse":
        FileNames = [
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size1.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size2.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size3.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size4.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size5.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size6.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size7.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size8.csv",
        ]
        fn="Reverses"
        nickn = "Reverse"
        
    if Type == "almost":
        FileNames = [
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size1.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size2.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size3.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size4.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size5.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size6.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size7.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size8.csv",
        ]
        fn="Almosts"
        nickn = "Almost"
    pass


for FileName in FileNames:
    valid = False
    with open(FileName, mode="r") as results:
        results_data = csv.reader(results, delimiter=",")
        next(results_data)
        for line in results_data:
            if valid == True:
                break
            for element in line:
                if str(element).strip().lower() == str(Algo).strip().lower():
                    Lines.append(line[1::])
                    valid = True
                    break
                else:
                    break

header = ["nanoseconds", "microseconds", "milliseconds", "seconds", "hours"]


if sys.platform.startswith("linux") or sys.platform == "darwin":
    with open("results/Comb/"+ acro + "/" + fn + "/All" + acro + "s"+ nickn +".csv", mode="w") as comb:
        writer = csv.writer(comb)
        writer.writerow(header)
        for line in Lines:
            writer.writerow(line)
elif sys.platform == "win32":
    with open("results\\Comb\\"+ acro + "\\" + fn + "\\All" + acro + "s"+ nickn +".csv", mode="w") as comb:
        writer = csv.writer(comb)
        writer.writerow(header)
        for line in Lines:
            writer.writerow(line)
    
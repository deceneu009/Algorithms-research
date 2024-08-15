import csv
import sys

valid = False

print("Select the algorithm and What size you want to get\n\n")
Algo = input(("Algorithm: "))
Size = input(("Size(1, 2, 3, 4, 5, 6, 7, 8): "))
Lines = []

Algo = Algo.lower()

if Algo == "quicksort":
    acroF = "QuickSort"
    fn = "Quicksort"
if Algo == "merge sort":
    acroF = "MergeSort"
    fn = "Merge_Sort"
if Algo == "selection sort":
    acroF = "SelectionSort"
    fn = "Selection_Sort"
if Algo == "insertion sort":
    acroF = "InsertionSort"
    fn = "Insertion_Sort"
if Algo == "bubble sort":
    acroF = "BubbleSort"
    fn = "Bubble_sort"
    
if sys.platform.startswith("linux") or sys.platform == "darwin":
    if Size == "1":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size1.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size1.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size1.csv",
        ]
        acro = 1

    if Size == "2":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size2.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size2.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size2.csv",
        ]
        acro = 2


    if Size == "3":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size3.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size3.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size3.csv",
        ]
        acro = 3

    if Size == "4":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size4.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size4.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size4.csv",
        ]
        acro = 4
        
    if Size == "5":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size5.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size5.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size5.csv",
        ]
        acro = 5
        
    if Size == "6":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size6.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size6.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size6.csv",
        ]
        acro = 6
        
    if Size == "7":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size7.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size7.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size7.csv",
        ]
        acro = 7
        
    if Size == "8":
        FileNames = [
            "results/ResultsCSV/ResultsRandom/ResultsRandom_Size8.csv",
            "results/ResultsCSV/ResultsReverse/ResultsReverse_Size8.csv",
            "results/ResultsCSV/ResultsAlmost/ResultsAlmost_Size8.csv",
        ]
        acro = 8
elif sys.platform == "win32":
    if Size == "1":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size1.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size1.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size1.csv",
        ]
        acro = 1

    if Size == "2":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size2.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size2.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size2.csv",
        ]
        acro = 2


    if Size == "3":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size3.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size3.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size3.csv",
        ]
        acro = 3

    if Size == "4":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size4.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size4.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size4.csv",
        ]
        acro = 4
        
    if Size == "5":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size5.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size5.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size5.csv",
        ]
        acro = 5
        
    if Size == "6":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size6.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size6.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size6.csv",
        ]
        acro = 6
        
    if Size == "7":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size7.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size7.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size7.csv",
        ]
        acro = 7
        
    if Size == "8":
        FileNames = [
            "results\\ResultsCSV\\ResultsRandom\\ResultsRandom_Size8.csv",
            "results\\ResultsCSV\\ResultsReverse\\ResultsReverse_Size8.csv",
            "results\\ResultsCSV\\ResultsAlmost\\ResultsAlmost_Size8.csv",
        ]
        acro = 8
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
                if str(element).strip().lower() == str(Algo).strip():
                    Lines.append(line[1::])
                    valid=True
                    break
                else:
                    break

header = ["nanoseconds", "microseconds", "milliseconds", "seconds", "hours"]

if sys.platform.startswith("linux") or sys.platform == "darwin":
    with open("results/Combined/" + fn + "/Size" + Size + "/" + acroF + ".csv", mode = "w") as comb:
        writer = csv.writer(comb)
        writer.writerow(header)
        for line in Lines:
            writer.writerow(line)
elif sys.platform == "win32":
    with open("results\\Combined\\" + fn + "\\Size" + Size + "\\" + acroF + ".csv", mode = "w", newline='') as comb:
        writer = csv.writer(comb)
        writer.writerow(header)
        for line in Lines:
            writer.writerow(line)

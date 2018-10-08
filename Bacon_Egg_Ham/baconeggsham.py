import sys

while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break

    report = {}
	
	#Build dictionary from the input data
    for i in range(0, num):
        data = sys.stdin.readline().split()
        for food in data[1:]:
            if food in report:
                report[food][data[0]] = None
            else:
                report[food] = { data[0] : None }

	#Print the results in sorted order
    for dish in sorted(report):
        print str(dish) + " " + " ".join(sorted(report[dish]))

    print ""
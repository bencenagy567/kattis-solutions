import sys

class Point:
    def __init__(self,x,y):
        self.x = x
        self.y = y

def ccw(A,B,C):
    return (C.y-A.y)*(B.x-A.x) > (B.y-A.y)*(C.x-A.x)


def intersect(A,B,C,D):
    return ccw(A,C,D) != ccw(B,C,D) and ccw(A,B,C) != ccw(A,B,D)


while True:
    num = int(sys.stdin.readline())
    if num == 0:
        break

    segments = []

    for i in range(0, num):
        points = sys.stdin.readline().split()
        start = Point(float(points[0]),float(points[1]))
        end = Point(float(points[2]),float(points[3]))
        segments.append([start,end])

    intersections = []
    n = len(segments)
    for i in range(0, n-1):
        for j in range(i+1, n):
            if intersect(segments[i][0],segments[i][1],segments[j][0],segments[j][1]):
                intersections.append([i,j])

    count = 0
    m = len(intersections)
    for i in range(0, m-1):
        for j in range(i+1, m):
            if intersections[i][1] == intersections [j][0] and [intersections[i][0],intersections[j][1]] in intersections:
                count += 1
    print count
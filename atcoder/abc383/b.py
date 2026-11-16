def main():
    import sys
    input_data = sys.stdin.read().split()
    h, w, d = int(input_data[0]), int(input_data[1]), int(input_data[2])
    grid = input_data[3:3 + h]
    floors = [(i, j) for i in range(h) for j in range(w) if grid[i][j] == '.']
    ans = 0
    for a in range(len(floors)):
        for b in range(a + 1, len(floors)):
            count = 0
            for (i, j) in floors:
                da = abs(i - floors[a][0]) + abs(j - floors[a][1])
                db = abs(i - floors[b][0]) + abs(j - floors[b][1])
                if da <= d or db <= d:
                    count += 1
            ans = max(ans, count)
    print(ans)

main()

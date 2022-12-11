with open("input.txt", "r") as inp:
    lines = inp.readlines()


class Graph:
    state = {}
    mark = {}
    ans = 0

    def set_data(self, a, b):
        if a not in self.state:
            self.state[a] = []
        if b not in self.state:
            self.state[b] = []
        if a == "start":
            self.state[a].append(b)
        elif a == "end":
            self.state[b].append(a)
        elif b == "start":
            self.state[b].append(a)
        elif b == "end":
            self.state[a].append(b)
        else:
            self.state[a].append(b)
            self.state[b].append(a)

        self.mark[a] = -1 if a.isupper() else 0
        self.mark[b] = -1 if b.isupper() else 0

    def store_data(self, lines):
        for line in lines:
            a, b = line.strip().split("-")
            graph.set_data(a, b)

    def first(self, parent):
        if parent == "end":
            self.ans += 1
            return
        if self.mark[parent] == 0:
            self.mark[parent] = 1
        for value in self.state[parent]:
            if self.mark[value] == 1:
                continue
            self.first(value)
        if self.mark[parent] == 1:
            self.mark[parent] = 0

    def second(self, parent):
        if parent == "end":
            self.ans += 1
            return
        if 0 <= self.mark[parent] < 2:
            self.mark[parent] += 1

        for value in self.state[parent]:
            if self.mark[value] == 2 or (
                self.mark[value] == 1 and 2 in self.mark.values()
            ):
                continue
            self.second(value)
        if self.mark[parent] > 0:
            self.mark[parent] -= 1


graph = Graph()
graph.store_data(lines)

graph.first("start")
# graph.second("start")

print(graph.ans)

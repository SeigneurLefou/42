import sys

class t_list:
    def __init__(self, v,n = None):
        self.value = v
        self.next_v = n
    def change_value(self, new_value):
        tmp = self.value
        self.value = new_value
        return tmp
    def change_next(self, new_next):
        tmp = self.next_v
        self.next_v = new_next
        return tmp
    def render(self):
        stack_render = [str(self.value)]
        if self.next_v:
            stack_render.extend(self.next_v.render())
        return stack_render
    def __len__(self):
        length = 1
        if self.next_v:
            length += len(self.next_v)
        return length
    def add_last(self, v):
        if not self.next_v:
            self.next_v = t_list(v)

class push_swap:
    def __init__(self):
        self.stacka = None
        self.stackb = None
    def init_stacka(self, numbers):
        i = 0
        self.stacka = t_list(numbers[i])
        i += 1
        while i < len(numbers):
            self.stacka = t_list(numbers[i], self.stacka)
            i += 1
    def render_stacks(self):
        if self.stacka:
            print("a : [{}]".format(" > ".join(self.stacka.render())))
        else:
            print("a : [NULL]")
        if self.stackb:
            print("b : [{}]".format(" > ".join(self.stackb.render())))
        else:
            print("b : [NULL]")
    def sa(self):
        if len(self.stacka) < 2:
            return 1
        tmp = self.stacka.value
        self.stacka.value = self.stacka.next_v.value
        self.stacka.next_v.value = tmp
        return 0

    def sb(self):
        if not self.stackb or len(self.stackb) < 2:
            return 1
        tmp = self.stackb.value
        self.stackb.value = self.stackb.next_v.value
        self.stackb.next_v.value = tmp
        return 0
    def ss(self):
        self.sa()
        self.sb()
        return 0
    def pa(self):
        if not self.stackb:
            return 1
        tmp = self.stackb.value
        self.stackb = self.stackb.next_v
        self.stacka = t_list(tmp, self.stacka)
        return 0
    def pb(self):
        if not self.stacka:
            return 1
        tmp = self.stacka.value
        self.stacka = self.stacka.next_v
        self.stackb = t_list(tmp, self.stackb)
        return 0
    def ra():
        if not self.stacka or len(self.stacka) < 2:
            return 1
        new_last_value




if __name__ == '__main__':
    numbers = sys.argv[1:]
    for i in range(len(numbers)):
        numbers[i] = int(numbers[i])
    numbers = numbers[::-1]
    stacks = push_swap()

    print("Init stack a and b")
    stacks.init_stacka(numbers)
    stacks.render_stacks()

    print("Exec sa")
    stacks.sa()
    stacks.render_stacks()

    print("Exec pb pb pb")
    stacks.pb()
    stacks.pb()
    stacks.pb()
    stacks.render_stacks()

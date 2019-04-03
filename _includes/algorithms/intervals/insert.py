def test_if_interval_list_is_valid(intervals):
    for i, interval in enumerate(intervals):
        if interval[0] > interval[1]:
            return False
        if i > 0:
            if not interval[0] > intervals[i - 1][1]:
                return False
        if i + 1 < len(intervals):
            if not intervals[i + 1][0] > interval[1]:
                return False
    return True


def merge_intervals_from_index(intervals, index):
    cut_position = index + 1
    for i in range(index + 1, len(intervals)):
        if intervals[i][0] <= intervals[index][1]:
            intervals[index][1] = max(intervals[index][1], intervals[i][1])
            cut_position = i + 1
        else:
            break
    del intervals[index + 1: cut_position]


def insert_interval(intervals, new_interval):
    inserted_index = None
    for i, interval in enumerate(intervals):
        if interval[1] < new_interval[0]:
            continue
        if interval[0] > new_interval[1]:
            intervals.insert(i, new_interval)
            inserted_index = i
            break
        if interval[0] <= new_interval[1]:
            intervals[i][0] = min(intervals[i][0], new_interval[0])
            intervals[i][1] = max(intervals[i][1], new_interval[1])
            inserted_index = i
            break
    if inserted_index is not None:
        merge_intervals_from_index(intervals, inserted_index)
    else:
        intervals.append(new_interval)


if __name__ == '__main__':
    interval_list = []
    insertions = [[3, 4], [1, 2], [2, 3], [5, 5], [6, 6], [0, 7]]
    for insertion in insertions:
        insert_interval(interval_list, insertion)
        print(interval_list)
        assert test_if_interval_list_is_valid(interval_list)

# Produces
#  [[3, 4]]
#  [[1, 2], [3, 4]]
#  [[1, 4]]
#  [[1, 4], [5, 5]]
#  [[1, 4], [5, 5], [6, 6]]
#  [[0, 7]]

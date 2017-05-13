def bitwise_and_of_range(begin, end):
    if begin == end:
        return begin
    else:
        return bitwise_and_of_range(begin >> 1, end >> 1) << 1

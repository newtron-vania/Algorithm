def process_count(end_time, start_times):
    count=1
    for start_time in start_times:
        if end_time>start_time:
            count+=1
    return count
def solution(lines):
    counts = [1]
    answer = 0
    end_times = [list(map(float, line.split()[1].split(":"))) for line in lines]
    end_times = [round(end_time[0]*3600 + end_time[1]*60 +end_time[2],3) for end_time in end_times]
    processing_times = [float(line.split()[2][:-1]) for line in lines]
    start_times = [round(end_time - processing_time+0.001,3) for end_time, processing_time in zip(end_times, processing_times)]
    for i in range(len(end_times)):
        print(start_times[i], end_times[i] )
    for i in range(len(end_times)-1):
        counts.append(process_count(end_times[i]+1, start_times[i+1:]))
    answer = max(counts)
    return answer
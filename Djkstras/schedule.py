n = int(input("Enter number of jobs: "))
jobs = []
print("Enter Id deadline and profit respectively for each job:")
for i in range(n):
    job = input("Job " + str(i+1) + ": ").split()
    jobs.append(job)

sorter = lambda job: int(job[2]) 
jobs = sorted(jobs, key=sorter, reverse=True)

scheduled = []
time = 0

for i in jobs:
    if time <= int(i[1]):
        scheduled.append(i[0])
        time += 1

print("Jobs are scheduled as: ")
print(scheduled)      

# Enter number of jobs: 4
# Enter Id deadline and profit respectively for each job:
# Job 1: A 2 100
# Job 2: B 1 19
# Job 3: C 2 27
# Job 4: D 1 25
# Jobs are scheduled as: 
# ['A', 'C']

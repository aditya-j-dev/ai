import statistics

"""
Program to calculate:
Mean, Median, Mode, Variance, Standard Deviation
"""

# Sample dataset
data = [10, 20, 20, 30, 40, 50, 60]

print("Dataset:", data)

# Mean (Average)
mean_value = statistics.mean(data)
print("\nMean:", mean_value)

# Median (Middle value)
median_value = statistics.median(data)
print("Median:", median_value)

# Mode (Most frequent value)
mode_value = statistics.mode(data)
print("Mode:", mode_value)

# Variance (Spread of data)
variance_value = statistics.variance(data)
print("Variance:", variance_value)

# Standard Deviation (Square root of variance)
std_dev = statistics.stdev(data)
print("Standard Deviation:", std_dev)



# # -----------------------------------------------
# # Program to calculate Mean, Median, Mode,
# # Variance, and Standard Deviation manually
# # -----------------------------------------------

# # Sample dataset
# data = [10, 20, 20, 30, 40, 50, 60]

# print("Dataset:", data)

# n = len(data)

# # ---------------- MEAN ----------------
# total = 0
# for num in data:
#     total += num

# mean = total / n
# print("\nMean:", mean)

# # ---------------- MEDIAN ----------------
# sorted_data = sorted(data)

# if n % 2 == 1:
#     median = sorted_data[n // 2]
# else:
#     median = (sorted_data[n // 2 - 1] + sorted_data[n // 2]) / 2

# print("Median:", median)

# # ---------------- MODE ----------------
# freq = {}

# for num in data:
#     if num in freq:
#         freq[num] += 1
#     else:
#         freq[num] = 1

# mode = None
# max_count = 0

# for key in freq:
#     if freq[key] > max_count:
#         max_count = freq[key]
#         mode = key

# print("Mode:", mode)

# # ---------------- VARIANCE ----------------
# sum_sq_diff = 0

# for num in data:
#     sum_sq_diff += (num - mean) ** 2

# variance = sum_sq_diff / (n - 1)   # sample variance
# print("Variance:", variance)

# # ---------------- STANDARD DEVIATION ----------------
# std_dev = variance ** 0.5
# print("Standard Deviation:", std_dev)